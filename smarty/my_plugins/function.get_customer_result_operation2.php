<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_operation2.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_operation2
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */
require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_form_questions.php');

function smarty_function_get_customer_result_operation2($params){
	$estimateLib = new ProposalEstimateLib();
	$guardCategoryList = $estimateLib->getGuardCategoryList();

	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$guard_type_id = $guard_type['guard_type_id'];
			$questions = $guard_type['proposal_guard_type_questions'];
			$str .= '<h4>'.$guardCategoryList[$guard_type_id]['name']."</h4>";

			$str .= '<table class="tbl04"><tbody>';

			$str .= '<tr><th class="w40p alignL">ガードマン配置希望場所は何箇所ですか？</th><td>';
			$str .= $guard_type['point'].'箇所';
			$str .= '</td></tr>';

			$str .= smarty_function_get_customer_form_questions(array("questions" => $questions));

			$str .= '</tbody></table>';

		}
	}
	return $str;

}
?>