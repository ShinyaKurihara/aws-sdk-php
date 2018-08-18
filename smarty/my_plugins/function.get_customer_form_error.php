<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_error.php
 * Type:     function
 * Name:     get_customer_form_error
 * Purpose:  顧客画面用のフォームチェックでエラーがあった場合、メッセージを返す
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_error($params){

	$errorString =  $params["error"];

	if(!$errorString)	$errorString = "";

	$name = $params["name"];

	if($name){
		$idString = 'id="form_error_'.$name.'"';
	}

	$str = vsprintf('<p  %s  class="error nobdr">%s</p>', array($idString, $errorString));

	return $str;

}
?>