<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_proposal_situation.php
 * Type:     function
 * Name:     get_customer_form_proposal_situation
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_proposal_situation($params){
	global $situation_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if($proposal['stuation_id']){
		$str .= $situation_list[$proposal['stuation_id']]['name'];
	}

	return $str;

}
?>