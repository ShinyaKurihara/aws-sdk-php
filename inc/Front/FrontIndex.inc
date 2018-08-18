<?php
/*
* 顧客　トップ
*/
use Aws\S3\S3Client;
//複数アップする場合に必要(未実装)
use Aws\CommandPool;

class FrontIndex{// extends CustomerCommon{
	//セッション名
	const S_FORM_DATA = "FrontIndex";	//フォームデータのセッション名
	
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
		$this->smarty = new MySmarty("front", "index");

		//ページタイトル
		$this->smarty->assign("page_title", "トップ" );

		//$this->getLoginStatus();

		//コンテンツを選定する
		$this->mode = empty($mode) ? "i" : $mode;

		switch($this->mode){
			case "i":		//TOP
				$this->index();
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
	
		//ページの表示
		$this->smarty->display('index.tpl');
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