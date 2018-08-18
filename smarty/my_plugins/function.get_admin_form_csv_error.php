<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_form_csv_error.php
 * Type:     function
 * Name:     get_admin_form_error
 * Purpose:  管理画面用のフォームチェックでエラーがあった場合、メッセージを返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_form_csv_error($params){

	$errorArray =  $params["error"];
	
	if(!$errorArray || !count($errorArray))	return false;
	
	foreach($errorArray as $k=>$v){
		$str .= vsprintf("<br /><font color='#CC3333'><b>%s</b></font> \n",array($v));
	}
	
	return $str;

}
?>