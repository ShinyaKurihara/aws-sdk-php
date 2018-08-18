<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_implementation_form_error.php
 * Type:     function
 * Name:     get_admin_form_error
 * Purpose:  実施会社管理画面用のフォームチェックでエラーがあった場合、メッセージを返す
 * -------------------------------------------------------------
 */


function smarty_function_get_implementation_form_error($params){

	$errorString =  $params["error"];
	
	if(!$errorString)	return false;
	
	$str = vsprintf("<p class='error nobdr'>%s</p> \n",array($errorString));
	
	if($errorString =  $params["br"])	$str.="<br>";
	
	return $str;

}
?>