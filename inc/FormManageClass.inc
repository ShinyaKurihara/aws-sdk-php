<?php
/*
* フォームデータ管理クラス
*/
class FormManageClass{

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
		$this->contentsName = $contentsName;
	}
	
	/*
	 * セッションの初期化
	 * 登録の開始時に呼び出す
	*/
	function initializationSession(){
		
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;

		$_SESSION[$this->contentsName] = array();				//フォームデータ
		$_SESSION[$this->contentsName."_updateId"] = 0;			//編集の場合に確保するDBのID
		$_SESSION[$this->contentsName."_up_file"] = "";			//アップロードファイル
		$_SESSION[$this->contentsName."_token"] = array();		//トークンデータ
		$_SESSION[$this->contentsName."_move_flag"] = 0;		//ページ遷移フラグ
	}
	
	/*
	 * フォームデータをセッションに登録する
	 * $_POST、$_GETの値をセットする
	 * @param Array $data
	*/
	function setFormData($data){
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
	
		//フォームのデータをセット
		$_SESSION[$this->contentsName] = $data;
	}

	/*
	 * フォームデータを返す
	 * @return array
	*/
	function getFormData(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//フォームのデータを返す
		return $_SESSION[$this->contentsName];
	}
	
	//////////UpdateのID////////
	/*
	 * アップデータ用のDBのIDを返す
	 * @return int
	*/
	function getUpdateId(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//フォームのデータを返す
		return $_SESSION[$this->contentsName."_updateId"];
	}

	/*
	 * アップデータ用のDBのIDを登録する
	 * @param int $id
	*/
	function setUpdateId($id){
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
	
		//IDをセット
		$_SESSION[$this->contentsName."_updateId"]=$id;
	}

	/*
	 * 表示件数を登録する
	 * @param int $id
	*/
	function setPageLimit($pageLimit){
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		if(!$pageLimit)						return false;

		//フォームデータを取得
		$formData = $this->getFormData();
			
		$formData["page_limit"]=$pageLimit;
		$formData["pID"]=0;					//ページャーは初期化
			
		//フォームの内容を保存
		$this->setFormData($formData);
	}
	
	/*
	 * 表示件数を登録する
	 * @param int $id
	*/
	function setPageId($pageID){
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		if(!preg_match("/^\d+$/",$pageID))	return false;
		
		//フォームデータを取得
		$formData = $this->getFormData();
			
		$formData["pID"]=$pageID;
			
		//フォームの内容を保存
		$this->setFormData($formData);
	}

	//////////アップロードファイル////////
	/*
	 * アップロードファイルデータをセッションに登録する
	 * $_POST、$_GETの値をセットする
	 * @param Array $data
	*/
	function setFileData($fileData, $isPath=true){
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//$isPathがtureの場合は指定のパスからファイルを取得する
		//$isPathがfalseの場合はそのままのデータを代入する
		$binary = $isPath ? file_get_contents($fileData) : $fileData;
		
		//base64でエンコードし、配列に代入
		$_SESSION[$this->contentsName."_up_file"] = base64_encode($binary);
	}
	
	/*
	 * 画像データをを返す
	 * @return array
	*/
	function getFileData(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//フォームのデータを返す
		return $_SESSION[$this->contentsName."_up_file"];
	}
	//////////////////////////////////////////
	
	////////////ページ遷移フラグ管理//////////
	/*
	 * 指定のビットを立てる
	 * @param Int $flag
	*/
	function setMoveFlag($flag){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
	
		//現在のフラグを取得
		$move_flag = $this->getMoveFlag();

		//ビットを立てる
		$move_flag |= (0x01 << $flag-1);
		
		//セッションに登録
		$_SESSION[$this->contentsName."_move_flag"] = $move_flag;
	}
	
	/*
	 * 指定のビットを落とす
	 * @param Int $flag
	*/
	function removeMoveFlag($flag){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
	
		//現在のフラグを取得
		$move_flag = $this->getMoveFlag();
		
		//ビットを落とす
		$move_flag &= ~(0x01 << $flag-1);
		
		//セッションに登録
		$_SESSION[$this->contentsName."_move_flag"] = $move_flag;
	}
	
	/*
	 * 遷移フラグを返す
	 * @return int
	*/
	function getMoveFlag(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//返却
		return $_SESSION[$this->contentsName."_move_flag"];
	}
	
	/*
	 * 正常に遷移しているかのフラグをチェックする
	 * @param Int $page
	*/
	function checkMoveFlag($page){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
	
		//現在のフラグを取得
		$move_flag = $this->getMoveFlag();
		
		//1ページ目から指定のページまでをループさせる
		for($i=1; $i<=$page; $i++){
			//チェックする値を生成
			$checkNum = pow(2,$i-1);
		
			//指定のビットが立っていない場合はエラーとする
			if( ( $move_flag & $checkNum)==0 ){
				return false;
			}
		}
		
		//正常
		return true;
	}
	//////////////////////////////////////////
	
	
	////////フォームに埋め込むトークン////////
	/*
	 * トークンを生成
	*/
	function createToken(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;

		//トークンを生成する
	    $_SESSION[$this->contentsName."_token"] = StringUtility::getToken();
	}

	/*
	 * トークンを返す
	 * @return String
	*/
	function getToken(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		//トークンを返す
		return $_SESSION[$this->contentsName."_token"];
	}
	
	/*
	 * トークンを削除
	*/
	function deleteToken(){
	
		//コンテンツ名が登録されていない場合はエラー
		if(!strlen($this->contentsName))	return false;
		
		$_SESSION[$this->contentsName."_token"]="";
	}
	
	//////////////////////////////////////////

}
?>