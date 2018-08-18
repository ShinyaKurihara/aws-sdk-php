<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.smarty_function_get_customer_result_dates.php
 * Type:     function
 * Name:     smarty_function_get_customer_result_dates
 * Purpose:  顧客画面用ので警備内容を表示
 * -------------------------------------------------------------
 */
//require_once(SMARTY_TPL_CORE_DIR.'my_plugins/function.get_customer_form_questions.php');

function smarty_function_get_customer_result_dates($params){

	$dates =  $params["proposal_guard_type_dates"];
	$rest =  $params["rest"];

	$str = "";
	if($dates){
		$str .= "<table class=\"tbl04\">";
		// ヘッダ部分
		$str .= "<thead><tr>";
		$str .= "<th>開始日</th>";
		$str .= "<th>開始時間</th>";
		$str .= "<th>終了日</th>";
		$str .= "<th>終了時間</th>";
		if($rest) $str .= "<th>休憩可否</th>";
		$str .= "</tr></thead>";
		
		// データ部分
		$str .= "<tbody>";
		foreach($dates as $num => $date){
			$str .= "<tr>";

			$str .= "<td>".date('Y/m/d', strtotime($date["date_from"]))."</td>";
			$str .= "<td>".date('G:i', strtotime($date["time_from"]))."</td>";
			$str .= "<td>".date('Y/m/d', strtotime($date["date_to"]))."</td>";
			$str .= "<td>".date('G:i', strtotime($date["time_to"]))."</td>";
			if($rest) $str .= "<td>".($date["rest_flag"] ? "可" : "不可")."</td>";

			$str .= "</tr>";
		}
		$str .= "</tbody>";
		$str .= "</table>";
	}
	return $str;

}
?>