<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_detail_target.php
 * Type:     function
 * Name:     smarty_function_get_customer_detail_target
 * Purpose:  顧客画面　ご契約内容で警備先を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_detail_target($params){
	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			if($guard_type['proposal_guard_type_targets']){
				foreach($guard_type['proposal_guard_type_targets'] as $num2 => $target){
					$str .= '〒'.$target['from_zip'].' ';
					$str .= $target['from_pref_name'] . htmlspecialchars($target['from_address'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET);
					$str .= '<br>';
				}
			}
			break; // 最初の一件のみ表示
		}
	}
	return $str;

}
?>