<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_questions.php
 * Type:     function
 * Name:     get_customer_form_questions
 * Purpose:  顧客画面用の質問をを表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_questions($params){
	global $question_type_list;
//echo "smarty_function_get_customer_form_questions";
	$questions =  $params["questions"];
	$str = "";

	$estimateLib = new ProposalEstimateLib();
	$questionTypeList = $estimateLib->getQuestionTypeList();

	if(!empty($questions)) foreach($questions as $id => $question){
		$question_type = $questionTypeList[$question["question_type_id"]];

			if($question["answer_num"] == "" && $question["answer_text"] == "") continue;

			$str .= "<tr><th class=\"w50p alignL\">".$question_type["title"]."</th><td>";
			if($question_type["input_type"]=="number"){
				$str .= $question["answer_num"];
			}elseif($question_type["input_type"]=="text"){
				$str .= $question["answer_text"];
			}elseif($question_type["input_type"]=="select" || $question_type["input_type"]=="radio"){
				$str .= $question_type["select_list"][$question["answer_num"]];
			}elseif($question_type["input_type"]=="checkbox"){
				if($question["answer_num"]){
					$str .= "はい";
				}else{
					$str .= "いいえ";
				}
			}
			if($question_type["after"]) $str .= $question_type["after"];
			$str .="</td></tr>";
	}

	return $str;

}
?>