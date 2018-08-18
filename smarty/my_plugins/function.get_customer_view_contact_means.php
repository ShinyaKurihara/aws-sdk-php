<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_view_contact_means.php
 * Type:     function
 * Name:     smarty_function_get_customer_view_contact_means
 * Purpose:  顧客画面　ご契約内容で連絡手段を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_view_contact_means($params){
	global $contact_means_list;

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_subscriptions']){
		$str .= $contact_means_list[$proposals['proposal_subscriptions']['contact_means']];
	}
	return $str;

}
?>