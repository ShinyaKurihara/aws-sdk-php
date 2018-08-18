<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.admin_office_name.php
 * Type:     function
 * Name:     admin_office_name
 * Purpose:  実施会社ユーザー登録、編集 実施会社IDから実施会社名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_office_name($params){

	if(!$params["office_id"])	return "選択してください。";

	//事業所マスタのDBインスタンスを生成
	$dbOfficesObj = new DbOffices(new MyPdo());
		
	$data = $dbOfficesObj->getData(array("id"=>$params["office_id"]));
	
	return $data["name"];

}
?>