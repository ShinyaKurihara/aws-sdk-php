<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_detail_payment_type.php
 * Type:     function
 * Name:     smarty_function_get_customer_detail_payment_type
 * Purpose:  顧客画面　ご契約内容で警備カテゴリーを表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_detail_payment_type($params){
	global $payment_type_list;
	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals["proposal_business_hearing_sheets"]['payment_kind']){
		$str .= $payment_type_list[$proposals["proposal_business_hearing_sheets"]['payment_kind']];
	}
	return $str;

}
?>