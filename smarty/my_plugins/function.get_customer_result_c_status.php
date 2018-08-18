<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_c_status.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_c_status
 * Purpose:  顧客画面用ので案件ステータスを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_result_c_status($params){

	$status_id =  $params["status_id"];
	$proposal_type_id =  $params["proposal_type_id"];

	if($status_id){
		$str = ProposalStatusLib::getStatusNameByDefaultStatusNum('c', $status_id, $proposal_type_id);
	}else{
		$str = "";
	}

	return $str;

}
?>