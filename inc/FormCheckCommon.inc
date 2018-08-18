<?php
/*
* フォームチェックの共通クラス
*/
class FormCheckCommon extends FormValidator{

	var $data = array();
	var $fileData = array();
	var $errors = array();

	//コンストラクタ
	function __construct(){
	}
	
	//ヌルバイトの除去 
	function sanitizer($formData){
	
		if (is_array($formData) ){
			return array_map( array($this, 'sanitizer'), $formData); 
		}
		
		return str_replace("\0", "", $formData); 
	}

	/*
	 * チェックするデータをセットする
	 * $_POST、$_GETの値をセットする
	 * @param Array $data
	*/
	function setData($data){
		$this->data = $data;
	}

	/*
	 * チェックするアップロードファイルのデータをセットする
	 * $_FILEの値をセットする
	 * @param Array $fileData
	*/
	function setUpLoadFileData($fileData){
		$this->fileData = $fileData;
	}

	/*
	 * エラーメッセージをセットする
	 * @param String $key
	 * @param String $message
	*/
	function setError($key, $message){
		$this->errors[$key] = $message;
	}


	/*
	 * キーに対応するエラーメッセージを返す
	 * @return string
	*/
	function getErrorOf($key){
		return !empty($this->errors[$key]) ? $this->errors[$key] : "";
	}

	/*
	 * フォームチェックでエラーの有無を返す
	 * @return bool
	*/
	function isError(){
		
		if(count($this->errors))	return true;
		
		return false;
	}
	
	/*
	 * エラーメッセージの配列を返す
	 * @return array
	*/
	function getError(){
		return $this->errors;
	}

}
?>