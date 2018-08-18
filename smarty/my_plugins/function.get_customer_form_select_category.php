<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_customer_form_select_category.php
 * Type:     function
 * Name:     get_customer_form_select_category
 * Purpose:  警備カテゴリーから選ぶ選択肢を表示
 * -------------------------------------------------------------
 */


function smarty_function_get_customer_form_select_category($params){

	$guardCategoryList = $params["guardCategoryList"];
	$formData = $params["formData"];

	$str = "";

	$line_list = array('', '', '');

	foreach($guardCategoryList as $num => $category){
		$text1 = "";
		$text1 .= '<div class="ck_col">';
		$text1 .= '<input type="checkbox" name="guard_categories['.$category['id'].']" ';
		$text1 .= 'value="'.$category['id'].'" id="checkbox'.$category['gid'].'"  class="'.$category['gid'].'"  ';
		if(!empty($formData["guard_categories"]) && in_array($category['id'], $formData["guard_categories"])){
			$text1 .= 'checked ';
		}
		$text1 .= '/>';
		$text1 .= '<label for="checkbox'.$category['gid'].'" class="checkbox">'.$category['name'].'</label>';
		$text1 .= '</div>';
		$line_list[($num - 1) % 3] .= $text1;
	}

	foreach($line_list as $line){
		$str .= '<div class="box">';
		$str .= $line;
		$str .= '</div>';
	}

	return $str;

}
?>