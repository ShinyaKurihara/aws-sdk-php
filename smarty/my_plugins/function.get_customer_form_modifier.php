<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_modifier.php
 * Type:     function
 * Name:     get_customer_form_modifier
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_modifier($params){
	global $question_type_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if(!$proposal['last_operation_system_user_id']
	  || (!$proposal['system_user_modified'] && !$proposal['system_user_created'])
	  || ($proposal['system_user_modified'] && strtotime($proposal['system_user_modified']) < strtotime($proposal['modified']))
	  || (!$proposal['system_user_modified'] && $proposal['system_user_created'] && strtotime($proposal['system_user_created']) < strtotime($proposal['created']))
	){
		//顧客のDBインスタンスを生成
		$dbCustomersObj = new DbCustomers(new MyPdo());

		$customer = $dbCustomersObj->getData(array("id"=>$proposal['customer_id']));
		$str .= htmlspecialchars($customer['name_sei'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET).' '.htmlspecialchars($customer['name_mei'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET).' 様';
	}else{
		$str .= "ALSOK";
	}

	return $str;

}
?>