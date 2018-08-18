<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_detail_operation2.php
 * Type:     function
 * Name:     get_customer_detail_operation2
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */
require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_form_questions.php');

function smarty_function_get_customer_detail_operation2($params){
	$proposals =  $params["proposal_data"]["proposals"];
	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$questions = $guard_type['proposal_guard_type_questions'];
			$str .= "実施箇所： ".$guard_type['point']."箇所<br>";
			$str .= smarty_function_get_customer_form_questions(array("questions" => $questions));
			break; // 最初の一件のみ
		}
	}
	return $str;

}
?>