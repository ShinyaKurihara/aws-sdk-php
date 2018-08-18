<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_proposal_status.php
 * Type:     function
 * Name:     get_customer_form_proposal_status
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_proposal_status($params){
	global $proposal_status_list;

	$proposal =  $params["proposal_data"]["proposals"];
	$str = "";

	if($proposal['status_id']){
		$str .= ProposalStatusLib::getStatusNameByDefaultStatusNum('c', $proposal['status_id'], $proposal['proposal_type_id']);
	}

	return $str;

}
?>