<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_operation_other2.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_operation_other2
 * Purpose:  顧客画面用の警備内容を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_result_operation_other2($params){
	global $machine_security_list, $machine_security_company_list, $unlocking_list, $keep_key;

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		$first_guard_type = $proposals['proposal_guard_types'][0];
		if($first_guard_type['machine_security'] != ""){
			$str .= '<tr><th class="w40p alignL">警備システムを導入されていますか？</th><td>';
			$str .= $machine_security_list[$first_guard_type['machine_security']];
			$str .= '</td></tr>';
		}

		if($first_guard_type['unlocking'] != ""){
			$str .= '<tr><th class="w40p alignL">ガードマンがお客様に代わって、警備対象先の鍵を開閉する業務を依頼しますか？</th><td>';
			$str .= $unlocking_list[$first_guard_type['unlocking']];
			$str .= '</td></tr>';
		}

		if($first_guard_type['keep_key'] != ""){
			$str .= '<tr><th class="w40p alignL">警備システム導入にあたり、ALSOKに警備対象先の鍵を預けていますか？</th><td>';
			$str .= $keep_key[$first_guard_type['keep_key']];
			$str .= '</td></tr>';
		}

	}
	return $str;

}
?>