<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_proposal_plan.php
 * Type:     function
 * Name:     get_customer_form_proposal_plan
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_proposal_plan($params){
	global $customer_plan_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if($proposal['rank_id']){
		$str .= $customer_plan_list[$proposal['rank_id']];
	}

	return $str;

}
?>