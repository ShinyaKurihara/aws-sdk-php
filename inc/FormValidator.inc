<?php
/*
 * フォームバリデータクラス
*/
class FormValidator{
/*
	const LOGIN_ID_REGULAR = '^[a-zA-z]{1}[a-zA-z0-9\-_]*$';	//パスワード形式
	const PASSWORD_REGULAR = '!#$%&()*+,-.0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_abcdefghijklmnopqrstuvwxyz{|}';	//パスワード形式
	
	var $mobile_domain=array(
		"docomo.ne.jp",
		"mopera.net",
		"softbank.ne.jp",
		"vodafone.ne.jp",
		"disney.ne.jp",
		"i.softbank.jp",
		"ezweb.ne.jp",
		"biz.ezweb.ne.jp",
		"ido.ne.jp",
		"emnet.ne.jp",
		"emobile.ne.jp",
		"pdx.ne.jp",
		"willcom.com",
		"wcm.ne.jp",
		);
*/	
	var $mimeTypes = array( 
		'txt'=>'text/plain', 
		'csv'=>'text/comma-separated-values|vnd.ms-excel',
		'htm'=>'text/html', 
		'html'=>'text/html', 
		'jpg'=>'image/jpeg|image/pjpeg',
		'jpeg'=>'image/jpeg|image/pjpeg',
		'gif'=>'image/gif',
		'png'=>'image/png|image/x-png',
		'bmp'=>'image/x-bmp',
		'ai'=>'application/postscript',
		'psd'=>'image/x-photoshop',
		'eps'=>'application/postscript',
		'pdf'=>'application/pdf',
		'swf'=>'application/x-shockwave-flash',
		'lzh'=>'application/x-lha-compressed',
		'zip'=>'application/x-zip-compressed',
		'sit'=>'application/x-stuffit' 
	); 

	/*
	 * コンストラクタ
	*/
	function __construct(){
	}

	/*
	 * 必須チェック
	 * 指定の添え字のデータに値があるかをチェックする
	 * 数値の0は正常とする
	 *
	 * @param String $name
	 * @return bool
	*/
	//必須チェック
	function required($name){
	
		//該当するデータが無い場合はエラー
		if(!isset($this->data[$name]))		return false;
		
		//データが空の場合はエラー
		if(!strlen($this->data[$name]))		return false;
		
		//正常終了
		return true;
	}

	/*
	 * 空または0チェック
	 * 指定の添え字のデータに値があるかをチェックする
	 *
	 * @param String $name
	 * @return bool
	*/
	//空または0チェック
	function checkEmpty($name){
	
		//該当するデータが無い場合はエラー
		if(!isset($this->data[$name]))		return false;
	
		//空または0の場合はエラー
		if(empty($this->data[$name]))		return false;
		
		//正常終了
		return true;
	}

	/*
	 * 数値で形成されているかをチェック
	 * マイナスも可
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkNumeric($name){
	
		//数値のみで形成されていない場合はエラー
		if( !is_numeric($this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}

	/*
	 * 数字のみで形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkNumber($name){
	
		//数字のみで形成されていない場合はエラー
		if( !preg_match("/^[0-9]+$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 半角英数で形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkAlphanumeric($name){
	
		//半角英数のみで形成されていない場合はエラー
		if( !preg_match("/^[a-zA-Z0-9]+$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}

	/*
	 * 日本語で形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkJapanese($name){
		mb_regex_encoding("UTF-8");
		
		if(!preg_match("/^[ぁ-んァ-ヶー一-龠０-９―－Ａ-Ｚ　]+$/u",$this->data[$name]))	return false;

		//正常終了
		return true;

	}
	
	/*
	 * 半角数字(小数点可)で形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	/*
	function checkFloat($name){
	
		//半角数字(小数点可)で形成されていない場合はエラー
		if( !preg_match("/^[0-9]+(\.[0-9]*)?$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	*/
	/*
	 * 半角の和文記号で形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	/*
	function checkByteStringOnly($name){
	
		//半角の和文記号で形成されていない場合はエラー
		if( !preg_match("/^[ -~｡-ﾟ]+$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	*/

	/*
	 * 半角英字のみで形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	/*
	function checkEnglish($name){
	
		//半角英字のみで形成されていない場合はエラー
		if( !preg_match("/^[a-zA-Z]+$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	*/
	/*
	 * 全角カタカナで形成されているかをチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkKana($name){
	
		//全角カタカナのみで形成されていない場合はエラー
		if( !preg_match("/^[ァ-ヶー]+$/u", $this->data[$name]))	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 電話番号チェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkTel($name){
	
		//電話番号で形成されていない場合はエラー
		if( !preg_match("/^\d{2,4}\-\d{2,4}\-\d{3,4}$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 郵便番号チェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkZip($name){
	
		//郵便番号で形成されていない場合はエラー
		if( !preg_match("/^[0-9]{3}\-[0-9]{4}$/", $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * メールアドレスチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkMail($name){
	
		//メールアドレスで形成されていない場合はエラー
		if( !preg_match('/^[a-zA-Z0-9\.\-_\+]+?@[A-Za-z0-9\.\-_]+\.[a-zA-Z]+$/', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * モバイルのドメインチェック
	 * 基本的にはメールアドレスのチェックで使用する
 	 * 指定のデータの文字列がモバイルのドメインで終わっていな場合はエラーとする
 	 *
	 * @param String $name
	 * @return bool
	*/
	/*
	function checkMobileDomain($name){
	
		//モバイルのドメインチェックで文字列が終了していない場合はエラー
		if( !preg_match('/'.join("|",$this->mobile_domain).'$/', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	*/
	
	/*
	 * URLチェック
 	 * httpまたはhttpsで始まっていることを前提する
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkUrl($name){
	
		//URL形式でない場合はエラー
		if( !preg_match('|^(https?)://\w+(?:-\w+)*(?:\.\w+(?:-\w+)*)+(?::\d+)?(?:[/\?][\w%&=~\-\+/;\.\?]*(?:#[^<\s>]*)?)?$|D', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 日付YMチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkDateFormatYM($name){
	
		//YM形式でない場合はエラー
		if( !preg_match('/^\d{4}\/\d{2}$/', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 日付YMDチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkDateFormatYMD($name){
	
		//YMD形式でない場合はエラー
		if( !preg_match('/^\d{4}\/\d{2}\/\d{2}$/', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 日付YMDHiチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkDateFormatYMDHi($name){
	
		//YMDHi形式でない場合はエラー
		if( !preg_match('/^\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}$/', $this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 日付整合性チェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkDateStr($name){
		$yy = $mm = $dd = "";
		
		$delimiter = "\/";
		
		//文字列を取得
		$dateStr = $this->data[$name];
		
		//YM形式の場合は01日を追加
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr) )	$dateStr.="/01";
		
		//文字列を分解
		list($yy, $mm, $dd) = preg_split("/".$delimiter."/",$dateStr);
	
		//日付に分割できない場合はエラー
		if(!$yy || !$mm || !$dd)	return false;
	
		//日付の整合性が取れない場合はエラー
		if( !checkDate($mm,$dd, $yy) )	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 日付の範囲チェック
	 * 第1引数が第2引数より大きい日付の場合はエラーとする
	 * 
	 * @param String $name1
	 * @param String $name2
	 * @return bool
	*/
	function checkDateRange($name1, $name2){
	
		//文字列を取得
		$dateStr1 = $this->data[$name1];
		$dateStr2 = $this->data[$name2];
		
		//YM形式であるなら01日を追加
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr1) )	$dateStr1.="/01";
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr2) )	$dateStr2.="/01";
		
		//文字列からタイムスタンプを生成
		$sData = strtotime($dateStr1." 00:00:00");	//開始年月日
		$eData = strtotime($dateStr2." 23:59:59");	//終了年月日
		
		//開始年月日が終了年月日より大きい場合はエラーとする
		if( $sData > $eData)	return false;
		
		//正常終了
		return true;
	}
	
	/*
	 * 指定の値が指定のバイト数より小さいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	/*
	function strlenCheckByteMinLimit($name, $limit){
	
		//文字コードをSJIS-WINに変換する
		$str = mb_convert_encoding($this->data[$name], 'SJIS-WIN', mb_detect_encoding($this->data[$name]));
		
		//文字数を取得
		$len = strlen($str);
		
		#if($len >= $limit)	return true;
		if($len < $limit)	return false;
		
		return true;
	}
	*/
	/*
	 * 指定の値が指定のバイト数より大きいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	/*
	function strlenCheckByteMaxLimit($name, $limit){
		
		//文字コードをSJIS-WINに変換する
		$str = mb_convert_encoding($this->data[$name], 'SJIS-WIN', mb_detect_encoding($this->data[$name]));
		
		//文字数を取得
		$len = strlen($str);
		
		#if($len <= $limit)	return true;
		if($len > $limit)	return false;
		
		return true;
		
	}
	*/
	/*
	 * 指定の値が指定のバイト数と一致するかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	/*
	function strlenCheckByteJust($name, $limit){
		//文字コードをSJIS-WINに変換する
		$str = mb_convert_encoding($this->data[$name], 'SJIS-WIN', mb_detect_encoding($this->data[$name]));
		
		//文字数を取得
		$len = strlen($str);
		
		if($len != $limit)	return false;
		
		return true;
	}
	*/
	/*
	 * 指定の値が指定の文字数より小さいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	function strlenCheckMinLimit($name, $limit){
	
		//文字数を取得
		$len = mb_strlen($this->data[$name],"utf8");
		
		#if($len >= $limit)	return true;
		if($len < $limit)	return false;
		
		return true;
		
	}
	
	/*
	 * 指定の値が指定の文字数より大きいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	function strlenCheckMaxLimit($name, $limit){
	
		//文字数を取得
		$len = mb_strlen($this->data[$name],"utf8");
		
		#if($len <= $limit)	return true;
		if($len > $limit)	return false;
		
		return true;
	}
	
	/*
	 * 指定の値が指定の文字数と一致するかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	function strlenCheckJust($name, $limit){
	
		//文字数を取得
		$len = mb_strlen($this->data[$name],"utf8");
		
		#if($len == $limit)	return true;
		if($len != $limit)	return false;
		
		return true;
	}
	
	/*
	 * 指定の数値が指定の数値より小さいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	function numberMinLimit($name, $limit){
		
		#if($this->data[$name] >= $limit)	return true;
		if($this->data[$name] < $limit)	return false;
		
		return true;
	}
	
	/*
	 * 指定の数値が指定の数値より大きいかをチェック
	 * 
	 * @param String $name
	 * @param Int $limit
	 * @return bool
	*/
	/*
	function numberMaxLimit($name, $limit){
		
		#if($this->data[$name] <= $limit)	return true;
		if($this->data[$name] > $limit)	return false;
		
		return true;
		
	}
	*/
	/*
	 * 指定の数値が指定の数値以内に含まれているかをチェック
	 * 
	 * @param String $name
	 * @param Int $minNum
	 * @param Int $maxNum
	 * @return bool
	*/
	function numberBetween($name, $minNum, $maxNum ){
		
		#if($this->data[$name] >= $minNum && $this->data[$name] <= $maxNum)	return true;
		if($this->data[$name] < $minNum || $this->data[$name] > $maxNum)	return false;
		
		return true;
		
	}

	/*
	 * 2つの値が同じであるかをチェック
	 * 
	 * @param String $name
	 * @param Int $minNum
	 * @param Int $maxNum
	 * @return bool
	*/
	function compare($name1, $name2){
	
		#if($this->data[$name1]==$this->data[$name2])	return true;
		if($this->data[$name1] != $this->data[$name2])	return false;
		
		return true;
	}
/*
	//ログインID形式チェック
	function loginIdRegular($name){
		if(!preg_match('/'.self::LOGIN_ID_REGULAR.'/', $this->data[$name]))	return false;
		return true;
	}

	//パスワード形式チェック
	function passwordRegular($name){
		if(!preg_match('/^['.preg_quote(self::PASSWORD_REGULAR).'\/]+$/', $this->data[$name]))	return false;
		return true;
	}
*/
	///////////////////////////////////
		/*
	 * 日付の範囲チェック(from)
	 * 第1引数が第2引数（日付文字列）より小さい日付の場合はエラーとする
	 * 
	 * @param String $name1
	 * @param String $date1
	 * @return bool
	*/
	function checkDateFrom($name1, $date1){
	
		//文字列を取得
		$dateStr1 = $this->data[$name1];
		
		//YM形式であるなら01日を追加
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr1) )	$dateStr1.="/01";
		if( preg_match('/^\d{4}\/\d{2}$/', $date1) )	$date1.="/01";
		
		//文字列からタイムスタンプを生成
		$sData = strtotime($dateStr1." 00:00:00");	//開始年月日
		$eData = strtotime($date1." 23:59:59");	//終了年月日
		
		//開始年月日が終了年月日より小さい場合はエラーとする
		if( $sData < $eData)	return false;
		
		//正常終了
		return true;
	}

	/*
	 * 日付の範囲チェック(to)
	 * 第1引数が第2引数（日付文字列）より小さい日付の場合はエラーとする
	 * 
	 * @param String $name1
	 * @param String $date1
	 * @return bool
	*/
	function checkDateTo($name1, $date1){
	
		//文字列を取得
		$dateStr1 = $this->data[$name1];
		
		//YM形式であるなら01日を追加
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr1) )	$dateStr1.="/01";
		if( preg_match('/^\d{4}\/\d{2}$/', $date1) )	$date1.="/01";
		
		//文字列からタイムスタンプを生成
		$sData = strtotime($date1." 00:00:00");	//開始年月日
		$eData = strtotime($dateStr1." 23:59:59");	//終了年月日
		
		//開始年月日が終了年月日より小さい場合はエラーとする
		if( $sData < $eData)	return false;
		
		//正常終了
		return true;
	}

	/*
	 * 日付時刻の範囲チェック
	 * 第1引数：第2引数が第3引数：第4引数より大きい日付時刻の場合はエラーとする
	 * 
	 * @param String $name1
	 * @param String $name2
	 * @param String $name3
	 * @param String $name4
	 * @return bool
	*/
	function checkDateTimeRange($name1, $name2, $name3, $name4){
	
		//文字列を取得
		$dateStr1 = $this->data[$name1];
		$timeStr1 = $this->data[$name2];
		$dateStr2 = $this->data[$name3];
		$timeStr2 = $this->data[$name4];
		
		//YM形式であるなら01日を追加
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr1) )	$dateStr1.="/01";
		if( preg_match('/^\d{4}\/\d{2}$/', $dateStr2) )	$dateStr2.="/01";
		
		//文字列からタイムスタンプを生成
		$sData = strtotime($dateStr1." ".$timeStr1);	//開始年月日
		$eData = strtotime($dateStr2." ".$timeStr2);	//終了年月日
		
		//開始年月日が終了年月日より大きい場合はエラーとする
		if( $sData > $eData)	return false;
		
		//正常終了
		return true;
	}

	/*
	 * パスワード　大文字、小文字、数字、記号が全て含まれるかチェック
	 *
	 * @param String $name
	 * @return bool
	*/
	function checkFormatPassword($name){
	
		//小文字、数字、記号が含まれるない場合はエラー
		if( !StringUtility::checkPassword($this->data[$name]) )	return false;
		
		//正常終了
		return true;
	}
	
	///////////////////////////////////
	
	
	/****ファイル系****/
	/*
	 * アップロードファイルのエラーコードチェック
	 * $isRequiredは必須でない場合はfalseを引数で渡す
	 * 
	 * @param String $name
	 * @param Boolean $isRequired
	 * @return bool
	*/
	#function checkFileError($name, $isRequired = true){
	function checkFileError($isRequired = true){
		
		//フラグを宣言
		$flag = false;
		
		//エラー番号を取得
		$num = $this->fileData["error"];

		//ファイルが正しくアップロードされている場合は正常
		if($num==0)						$flag = true;
		//ファイルのアップロード必須でない場合は正常
		elseif(!$isRequired && $num==4)	$flag = true;
		
		//正常終了
		return $flag;
	}

	/*
	 * MIMEチェック
	 * $mimeは配列を渡すこと
	 * 対応するMIMEはメンバー変数の$mimeTypesを参照(追加可能)
 	 * 下記の例はjpeg、gif、pngを許可する場合
 	 * 例：$mime=array("jpeg","gif","png");
	 * 
	 * @param Array $mimeList
	 * @return bool
	*/
	#function checkMime($name, $mime){
	function checkMime($mimeList){

		//MINEの指定する配列が不正な状態の場合はエラー
		if(!is_array($mimeList) || !count($mimeList)) return false;
		
		//ファイルをアップロードしていない場合は正常終了とする
		if($this->fileData["error"]==4) return true;
		
		//MIMEタイプを取得
		$type = $this->fileData["type"];

		//mimeリスト格納用
		$checkMimeList = array();
		
		//正規表現用に指定のMIMEタイプの文字列を配列に代入
		foreach($mimeList as $k=>$v){
		
			//スラッシュをエスケープする
			$checkMimeList[] = preg_replace("/\//", "\\\/", $this->mimeTypes[$v]);
			
		}

		//該当するMIMEでない場合はエラー
		if(!preg_match('/('.join("|",$checkMimeList).')/', $type))	return false;
		
		//正常終了
		return true;
	}

	/*
	 * サイズチェック
	 * 
	 * @param Int $maxSize
	 * @return bool
	*/
	function checkSize($maxSize){

		//チェックするサイズが数値でない場合はエラー
		if(!is_int($maxSize))	return true;
	
		//ファイルをアップロードしていない場合は正常終了とする
		if($this->fileData["error"]==4) return true;
	
		//アップロードされたファイルサイズを取得
		$size = $this->fileData["size"];
		
		//サイズオーバーはエラー
		if($size > $maxSize)	return false;
		
		//正常終了
		return true;
	}
	
	//ファイル名チェック
	function fileNameRegular(){
		#preg_match('/^\/[a-z0-9_\-\.]+(\/|$)/', $data["picture_imgpath"])
		
		$pathData = pathinfo($this->fileData['name']);
		
		if(!preg_match('/^[a-zA-Z0-9_\-\.]+$/', $pathData['filename']))	return false;
		return true;
	}
	
/*	
	//拡張子チェック
	function checkExtension($name, $extStr){
		//拡張子を取得
		$extension = pathinfo($this->data[$name], PATHINFO_EXTENSION);
		
		//取得した拡張子を小文字に変換
		$extension = strtolower($extension);
		
		if(!preg_match('/('.$extStr.')/', $extension))	return false;
		
		return true;
	}
	
	//ファイル名チェック
	function fileNameRegular($filename){
		#preg_match('/^\/[a-z0-9_\-\.]+(\/|$)/', $data["picture_imgpath"])
		if(!preg_match('/^[a-zA-Z0-9_\-\.]+$/', $filename))	return false;
		return true;
	}
*/
}
?>