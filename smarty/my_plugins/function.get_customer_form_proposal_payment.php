<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_proposal_payment.php
 * Type:     function
 * Name:     get_customer_form_proposal_plan
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_proposal_payment($params){
	global $payment_type_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if($proposal['payment_type']){
		$str .= $payment_type_list[$proposal['payment_type']];
	}

	return $str;

}
?>