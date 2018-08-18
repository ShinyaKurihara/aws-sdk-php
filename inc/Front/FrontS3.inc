<?php
/*
* S3 TEST
*/

class FrontS3{// extends CustomerCommon{
	//セッション名
	const S_FORM_DATA = "FrontS3";	//フォームデータのセッション名
	
	public $tp;				//テンプレートクラス
	public $form;			//フォームクラス
	public $messageObj;		//メッセージクラス
	public $mode;			//コンテンツの選定用
	
	
	
	/*
	* コンストラクタ
	*/
	function __construct($mode){
		
		//親クラスを呼び出す
		//parent::__construct();

		//テンプレート クラスオブジェクトを生成
		$this->smarty = new MySmarty("front", "s3");

		//AWS ADK S3
		$this->myAwsS3 = new MyAwsS3();

		//ページタイトル
		$this->smarty->assign("page_title", "S3 TEST" );

		//コンテンツを選定する
		$this->mode = empty($mode) ? "i" : $mode;

		switch($this->mode){
			case "i":		//新規、編集準備
				$this->index();
			break;
			
			case "up":		//アップロード
				$this->upload();
			break;

			case "del":		//画像削除
				$this->delete();
			break;
			
			default:		//上記以外はエラー
				$this->error();
			break;
		}
	}

	/*
	* インデックス
	* 
	*/
	function index(){
	
		//S3のディレクトリ一覧の配列
		$this->smarty->assign("dir_list", $this->myAwsS3->getDirList() );
	
		//S3の画像一覧の配列
		$this->smarty->assign("image_list", $this->myAwsS3->getImageList() );
		
		//ページの表示
		$this->smarty->display('index.tpl');
		
		
		#$this-> getDirListS3();
	}

	/*
	* 画像のアップロード
	* 
	*/
	function upload(){
	
		$extension_array = array(
			//'gif' => 'image/gif',
			'jpg' => 'image/jpeg',
			//'png' => 'image/png'
		);

		if(!$ext = array_search($_FILES['up_file']['type'], $extension_array)){
		        echo 'jpegファイルを指定して下さい';
		        exit();
		}

		if(!$_POST["imgDir"] && !$_POST["newImgDir"]){
		        echo 'ディレクトリを設定してください';
		        exit();
		}

		//新規登録を優先とする
		$upDir = $_POST["newImgDir"] ? $_POST["newImgDir"]:$_POST["imgDir"];
		$mime = mime_content_type($_FILES['up_file']['tmp_name']);

		$this->myAwsS3->upload($upDir, $_FILES['up_file']['name'], $_FILES['up_file']['tmp_name'], $mime);

	    
		//入力フォームへ
		header("Location: ".FRONT_DIR_NAME."s3/");
		exit;
	}

	/*
	* 画像の削除
	* 
	*/
	function delete(){
	
		if(!$_POST["delKey"]){
		        echo '不正な実行です';
		        exit();
		}

		$this->myAwsS3->delete($_POST["delKey"]);
	    
		//入力フォームへ
		header("Location: ".FRONT_DIR_NAME."s3/");
		exit;
	}
	
	/*
	* エラー画面
	* @return array|false
	*/
	function error(){
		//ページの表示
		$this->smarty->display("error.tpl");
	}

}
?>