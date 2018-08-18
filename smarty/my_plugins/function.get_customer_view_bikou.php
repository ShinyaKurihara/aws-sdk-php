<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_view_bikou.php
 * Type:     function
 * Name:     smarty_function_get_customer_view_bikou
 * Purpose:  顧客画面　ご契約内容で共通質問内容を表示
 * -------------------------------------------------------------
 */

function smarty_function_get_customer_view_bikou($params){
	$proposals =  $params["proposal_data"]["proposals"];
	global $keep_key, $unlocking_list, $machine_security_list;
	$str = "";
	if($proposals['proposal_guard_types']){
		foreach($proposals['proposal_guard_types'] as $num => $guard_type){
			if($guard_type['machine_security'] != ""){
				$str .= '<tr><th class="w40p alignL">警備システムを導入されていますか？</th><td>';
				$str .= $machine_security_list[$guard_type['machine_security']]; 
				$str .= '</td></tr>';
			}

			if($guard_type['unlocking'] != ""){
				$str .= '<tr><th class="alignL">ガードマンがお客様に代わって警備対象先の鍵を開閉する業務を依頼しますか？</th><td>';
				$str .= $unlocking_list[$guard_type['unlocking']]; 
				$str .= '</td></tr>';
			}

			if($guard_type['keep_key'] != ""){
				$str .= '<tr><th class="alignL">警備システム導入にあたり、ALSOKに警備対象先の鍵を預けていますか？</th><td>';
				$str .= $keep_key[$guard_type['keep_key']]; 
				$str .= '</td></tr>';
			}

			break; // 最初の一件のみ表示
		}
	}
	return $str;

}
?>