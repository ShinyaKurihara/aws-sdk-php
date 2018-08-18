<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_detail_date.php
 * Type:     function
 * Name:     smarty_function_get_customer_detail_date
 * Purpose:  顧客画面　ご契約内容で警備日程を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_detail_date($params){
	$proposals =  $params["proposal_data"]["proposals"];

	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			$post = $guard_type['point'];
			if($guard_type['proposal_guard_type_targets']){
				foreach($guard_type['proposal_guard_type_targets'] as $num2 => $target){
					if($target['proposal_guard_type_dates']){
						foreach($target['proposal_guard_type_dates'] as $num3 => $date1){
							$str .= "<tr>";
								$str .= "<td>";
									$str .= date('Y/m/d', strtotime($date1["date_from"]))." ".date('G:i', strtotime($date1["time_from"]));
									$str .= " ～ ";
									$str .= date('Y/m/d', strtotime($date1["date_to"]))." ".date('G:i', strtotime($date1["time_to"]));
								$str .= "</td>";
								$str .= "<td style=\"text-align:right\">".$date1["people_num"]."</td>";
								$str .= "<td style=\"text-align:right\">".$post."</td>";
							$str .= "</tr>";
						}
					}
				}
			}
			break; // 最初の一件のみ表示
		}
	}
	return $str;

}
?>