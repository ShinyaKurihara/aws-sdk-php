<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_operation_other.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_operation_other
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_result_operation_other($params){
	global $machine_security_list, $machine_security_company_list, $unlocking_list, $keep_key;

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		$first_guard_type = $proposals['proposal_guard_types'][0];
		$str .= "ALSOK警備： ".$machine_security_list[$first_guard_type['machine_security']]."<br>";
		$str .= "鍵開閉業務： ".$unlocking_list[$first_guard_type['unlocking']]."<br>";
		$str .= "ALSOK鍵貸与： ".$keep_key[$first_guard_type['keep_key']]."<br>";

	}
	return $str;

}
?>