<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_select_situation.php
 * Type:     function
 * Name:     get_customer_form_select_map
 * Purpose:  警備シチュエーションから選ぶ選択肢を表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_select_situation($params){

	$situationList = $params["situationList"];
	$formData = $params["formData"];

	$str = "";

	foreach($situationList as $num => $situation){
		$str .= '<div class="box bdr item'.(floor(($num-1) / 3)+1).'">';
		$str .= '<div class="ck_col item_head'.(floor(($num-1) / 3)+1).'">';
		$str .= '<input type="checkbox" name="situation_'.$num.'" value="'.$num.'" id="situation_'.$num.'" ';
		if(!empty($formData["situation_".$num])){
			$str .= 'checked ';
		}
		$str .= '/>';
		$str .= '<label for="situation_'.$num.'" class="checkbox">'.$situation['name'].'</label>';
		$str .= '<p class="sample mT10">'.$situation['subtitle'].'</p>';
		$str .= '</div><!-- ck_col -->';
		$str .= $situation['description'];
		$str .= '</div><!-- bdr_box -->';
	}

	return $str;

}
?>
