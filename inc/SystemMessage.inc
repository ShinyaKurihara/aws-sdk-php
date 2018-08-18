<?php
/*
* 管理画面メッセージクラス
*/
class SystemMessage{

	var $contentsName;	//コンテンツ名

	/*
	 * コンストラクタ
	 * コンテンツ名が渡された場合は登録する
	 * @param String $contentsName
	*/
	function __construct($contentsName=""){
	
		//コンテンツ名を登録
		if(strlen($contentsName))	$this->setContentsName($contentsName);
	}
	
	/*
	 * コンテンツ名の登録
	 * セッションの名前の基本となる
	 * @param String $contentsName
	*/
	function setContentsName($contentsName){
		$this->contentsName = $contentsName."_system_message";
	}

	/*
	 * メッセージをセッションにセットする
	 * @param string $message
	*/
	function setMessage($message){
		//フォームのデータをセット
		$_SESSION[$this->contentsName] = $message;
	}

	/*
	 * メッセージを返し、削除する
	 * @return string
	*/
	function getMessage(){
	
		//フォームのデータをセット
		$message = $_SESSION[$this->contentsName];
		
		//メッセージを削除
		unset($_SESSION[$this->contentsName]);
		
		return $message;
	}
	


}
?>