<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_targets2.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_targets2
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_result_targets2($params){

	global $pref_list;

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'][0]['proposal_guard_type_targets'] as $num => $target){
			$str .= "〒".$target['from_zip']."&nbsp;";
			$str .= $pref_list[$target['from_pref_number']];
			$str .= htmlspecialchars($target['from_address'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET);
		}
	}
	return $str;

}
?>