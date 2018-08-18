<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_mail_proposal_dates.php
 * Type:     function
 * Name:     get_customer_mail_proposal_dates
 * Purpose:  案件の日付を表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_mail_proposal_dates($params){

	$proposal =  $params["proposal"];
	$str = "";

	$dates = array();
//print_r($proposal);
	if($proposal['proposal_guard_types'] && $proposal['proposal_guard_types'][0]['proposal_guard_type_targets'][0]['proposal_guard_type_dates']){
		foreach($proposal['proposal_guard_types'][0]['proposal_guard_type_targets'][0]['proposal_guard_type_dates'] as $date1){
			$date_from = strtotime($date1['date_from']);
			if(!in_array($date_from, $dates)) $dates[] = $date_from;
		}
	}elseif($proposal['proposal_guard_type_dates']){
		foreach($proposal['proposal_guard_type_dates'] as $date1){
			$date_from = strtotime($date1['date_from']);
			if(!in_array($date_from, $dates)) $dates[] = $date_from;
		}
	}

	sort($dates, SORT_NUMERIC);
	foreach($dates as $date2){
		$str .= date("Y/m/d", $date2) ."\n";
	}

	if($str){
		$str = "実施日：\n".$str;
	}

	return $str;

}
?>