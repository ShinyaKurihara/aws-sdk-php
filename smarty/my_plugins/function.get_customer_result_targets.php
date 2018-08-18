<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_targets.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_targets
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */

require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_result_dates.php');

function smarty_function_get_customer_result_targets($params){

	global $pref_list;

	$targets =  $params["proposal_guard_type_targets"];
	$guard_type_id = $params["guard_type_id"];

	$str = "";
	if($targets){
		foreach($targets as $num => $target){
			if($guard_type_id != GUARD_CATEGORY_GUARDED_TRANSPORT){
				$str .= "&nbsp;対象先： ";
				$str .= "〒".$target['from_zip']."&nbsp;";
				$str .= $pref_list[$target['from_pref_number']];
				$str .= htmlspecialchars($target['from_address'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET);
				$str .= "<br>\n";
			}else{
				$str .= "&nbsp;代表輸送元： ";
				$str .= "〒".$target['from_zip']."&nbsp;";
				$str .= $pref_list[$target['from_pref_number']];
				$str .= htmlspecialchars($target['from_address'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET)
;
				$str .= "<br>\n";

				$str .= "&nbsp;代表輸送先： ";
				$str .= "〒".$target['to_zip']."&nbsp;";
				$str .= $pref_list[$target['to_pref_number']];
				$str .= htmlspecialchars($target['to_address'], ENT_QUOTES, SMARTY_RESOURCE_CHAR_SET)
;
				$str .= "<br>\n";
			}
		}
	}

	$str .= smarty_function_get_customer_result_dates(array(
		"proposal_guard_type_dates" => $target['proposal_guard_type_dates'],
		"rest" => $params["rest"]
	));

	return $str;

}
?>