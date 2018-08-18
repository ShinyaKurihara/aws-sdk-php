<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_operation.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_operation
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */
require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_form_questions.php');

require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_result_targets.php');

function smarty_function_get_customer_result_operation($params){
	$estimateLib = new ProposalEstimateLib();
	$guardCategoryList = $estimateLib->getGuardCategoryList();

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$guard_type_id = $guard_type['guard_type_id'];
			$questions = $guard_type['proposal_guard_type_questions'];
			$str .= $guardCategoryList[$guard_type_id]['name']."<br>";
			$str .= "&nbsp;実施箇所： ".$guard_type['point']."箇所<br>";

			$str .= smarty_function_get_customer_form_questions(array("questions" => $questions));

			// 対象先
			$str .= smarty_function_get_customer_result_targets(array(
				"proposal_guard_type_targets" => $guard_type['proposal_guard_type_targets'],
				"guard_type_id" => $guard_type['guard_type_id'],
				"rest" => $guardCategoryList[$guard_type_id]['rest'],
			));

			// 日程

		}
	}
	return $str;

}
?>