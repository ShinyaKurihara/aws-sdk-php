<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_implementation_company_name_list
 * Type:     function
 * Name:     admin_implementation_company_name
 * Purpose:  事業所ユーザー登録、編集 事業所IDから事業所名を返す
 * -------------------------------------------------------------
 */

function smarty_function_get_admin_office_name_list($params){

	if(!$params["office_id_list"])	return "事業所を選択出来ます。";

	$office_id_list = explode(",", $params["office_id_list"]);

	//実施会社マスタのDBインスタンスを生成
	$dbOfficesObj = new DbOffices(new MyPdo());
		
	$officeList = $dbOfficesObj->getList(array("id_list"=>$office_id_list));
	
	$officeNameList=array();

	foreach($officeList as $num=>$office){
		$officeNameList[]=$office["name"];
	
	}

	return join("、", $officeNameList);

}
?>