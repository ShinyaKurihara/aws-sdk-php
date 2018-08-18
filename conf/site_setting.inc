<?php
//サイトドメイン
//顧客画面
define("FRONT_SITE_DOMAIN", "aws-sdk.local");


//顧客画面ディレクトリ名
define("FRONT_DIR_NAME", "/");

//顧客画面のURL
define("FRONT_SITE_URL", "http://".FRONT_SITE_DOMAIN.FRONT_DIR_NAME);

//顧客画面サイト名
define("FRONT_SITE_NAME", "AWS TEST");

//Blowfishのキー
define( "BLOWFISH_KEY", "AS><DHlddd2&093)(7ik#gsfiou9jjd&ss" );

////////////////Smarty////////////////
define("SMARTY_TPL_CORE_DIR", dirname(__FILE__)."/../smarty/");
define("SMARTY_DIR", SMARTY_TPL_CORE_DIR."libs/");


?>
