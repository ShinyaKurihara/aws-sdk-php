<?php

use Aws\S3\S3Client;
//複数アップする場合に必要(未実装)
use Aws\CommandPool;

class MyAwsS3 {

	var $s3client = false;	// S3オブジェクト
	var $bucket = false;	// S3バケット

	function __construct() {
	
	    $this->s3client = S3Client::factory([
	        'credentials' => [
	            'key' => getenv('AWS_ACCESS_KEY_ID'),
	            'secret' => getenv('AWS_SECRET_ACCESS_KEY'),
	        ],
	        'region' => getenv('AWS_S3_REGION'),
	        'version' => 'latest',
	    ]);

		//バケットを取得
		$this->bucket = getenv('AWS_S3_BUCKET');
	}

	/*
	* ディレクトリのの一覧を取得
	* 
	*/
	function getDirList(){

	    //ディレクトリの一覧の取得
	    $result = $this->s3client->ListObjectsV2([
	        'Bucket' => $this->bucket,
	        'Delimiter'=>"/"
	    ]);


		$tmp=[];
		
		foreach($result["CommonPrefixes"] as $num => $data){
		
			$tmp[$data["Prefix"]]=$data["Prefix"];
		
		}
	
		return $tmp;
	}

	/*
	* 画像の一覧を取得
	* 
	*/
	function getImageList(){
	
	    //画像の取得
	    $result = $this->s3client->ListObjectsV2([
	        'Bucket' => $this->bucket,
			#'MaxKeys' => 10, //最大取得数
			#'Prefix' => 'folder' //フォルダ指定
	    ]);
	
		//下記コードでフォルダと画像名のみ取得する
		foreach ($result['Contents'] as $img) {
			$imageUrls[$img['Key']] = $this->s3client->getObjectUrl($this->bucket,$img['Key']) ;
		}

		return $imageUrls;
	}

	/*
	* 画像のアップロード
	* 
	*/
	function upload($upDir, $file_name, $file_tmp_name, $mime){
	
		//読み込みの際のキーとなるS3上のファイルパスを作る
	    $new_filename = $upDir.'/'.time().'-'.$file_name;
		
		$image = $this->resizeImage($file_tmp_name);

	    //画像のアップロード(各項目の説明は後述)
	    $result = $this->s3client->putObject([
	        'ACL' => 'public-read',
	        'Bucket' => $this->bucket,
	        'Key' => $new_filename,
	        'Body' => $image,
	        'ContentType' => $mime,
	    ]);

	    //読み取り用のパスを返す
	    #$path = $result['ObjectURL'];
	    
	    return true;
	}

	/*
	* 画像の削除
	*
	*/
	function delete($key){

	    //画像のアップロード(各項目の説明は後述)
	    $result = $this->s3client->deleteObject([
	        'Bucket' => $this->bucket,
	        'Key' => $key,
	    ]);
	    
	    return true;
	}


	/*________________________*/
	/*
	* 画像のリサイズ
	* 
	*/
	function resizeImage($infilename, $newWidth =240){

		list($width, $height) = getimagesize($infilename);
		
		$newHeight = round($height*$newWidth/$width);
		
		$newimage = imagecreatetruecolor($newWidth, $newHeight);

		$source = imagecreatefromjpeg($infilename);
		imagecopyresampled($newimage, $source, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
		
	 	ob_start();
		imagejpeg($newimage);
		$outimage=ob_get_contents();
		ob_end_clean();
		
		imagedestroy($newimage);
		
		return $outimage;
	}
}
?>