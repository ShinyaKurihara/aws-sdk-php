<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_detail_operation.php
 * Type:     function
 * Name:     smarty_function_get_customer_detail_operation
 * Purpose:  顧客画面　ご契約内容で警備カテゴリーを表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_detail_operation($params){
	$estimateLib = new ProposalEstimateLib();
	$guardCategoryList = $estimateLib->getGuardCategoryList();

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$guard_type_id = $guard_type['guard_type_id'];
			$questions = $guard_type['proposal_guard_type_questions'];
			$str .= $guardCategoryList[$guard_type_id]['name']."<br>";
			break; // 最初の一件のみ表示
		}
	}
	return $str;

}
?>