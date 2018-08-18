<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_proposal_pay_day_month.php
 * Type:     function
 * Name:     get_customer_form_proposal_plan
 * Purpose:  顧客画面用の支払い時期を表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_proposal_pay_day_month($params){
	global $payment_time_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if($proposal["proposal_business_hearing_sheets"]["payment_time"]){
		$str .= $payment_time_list[$proposal["proposal_business_hearing_sheets"]["payment_time"]];
	}

	return $str;

}
?>