<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_operation1.php
 * Type:     function
 * Name:     get_customer_form_operation1
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */
require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_form_questions.php');

function smarty_function_get_customer_form_operation1($params){
	$estimateLib = new ProposalEstimateLib();
	$guardCategoryList = $estimateLib->getGuardCategoryList();

	$input_operations1 =  $params["input_operations1"];
	$str = "";
	if($input_operations1['selected_guard_types']){
		foreach($input_operations1['selected_guard_types'] as $num => $category_id){
			$questions = $input_operations1['estimate_guard_type_questions'][$num];
			$str .= '<h4>'.$guardCategoryList[$category_id]['name'].'</h4>';
			$str .= '<div class="content"><table class="tbl04"><tbody>';

			$str .= '<tr><th class="w50p alignL">ガードマン配置希望場所は何箇所ですか？</th>';
			$str .= "<td>".$input_operations1['guard_types'][$category_id]['point']."箇所</td></tr>";

			$str .= smarty_function_get_customer_form_questions(array("questions" => $questions));
			$str .= '</tbody></table></div>';

		}
	}
	return $str;

}
?>