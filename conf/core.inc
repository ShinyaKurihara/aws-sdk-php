<?php
/*
セッティングファイル
*/

session_name("MySession");
session_start();				//セッションの開始
if(mt_rand(1, 30)==1) {	// 実行確率
	session_regenerate_id(TRUE);
}// end if


#error_reporting(E_STRICT);
mb_detect_order('UTF-8,EUC-JP,SJIS,JIS,ASCII');

// 全てのエラー出力をオフにする
//error_reporting(0);

// 単純な実行時エラーを表示する
error_reporting(E_ERROR | E_PARSE);


//サイトの設定(テンプレート関係などのdefines)
include_once "site_setting.inc";

//各制御のdefine群
include_once "defines.inc";

//オートロード
include_once dirname(__FILE__)."/../inc/autoload.inc";

//Smarty
include_once SMARTY_DIR.'Smarty.class.php';


// AWS SDKライブラリのローディング
include_once dirname(__FILE__)."/../vendor/autoload.php";
?>