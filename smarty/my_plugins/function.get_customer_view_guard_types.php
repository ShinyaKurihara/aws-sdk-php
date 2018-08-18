<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_view_guard_types.php
 * Type:     function
 * Name:     smarty_function_get_customer_view_guard_types
 * Purpose:  顧客画面　ご契約内容で警備日程を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_view_guard_types($params){
	$estimateLib = new ProposalEstimateLib();
	$proposals =  $params["proposal_data"]["proposals"];
	$guardCategoryList = $estimateLib->getGuardCategoryList();

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$category_id = $guard_type['guard_type_id'];
			$str .= '<li>'.$guardCategoryList[$category_id]['name'].'</li>';
		}
	}
	return $str;

}
?>