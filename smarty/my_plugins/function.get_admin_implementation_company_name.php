<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_implementation_company_name.php
 * Type:     function
 * Name:     admin_implementation_company_name
 * Purpose:  実施会社ユーザー登録、編集 実施会社IDから実施会社名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_implementation_company_name($params){

	if(!$params["implementation_company_id"])	return "選択してください。";

	//実施会社マスタのDBインスタンスを生成
	$dbImplementationCompaniesObj = new DbImplementationCompanies(new MyPdo());
		
	$data = $dbImplementationCompaniesObj->getData(array("id"=>$params["implementation_company_id"],"is_delete"=>0));
	
	return $data["company_name"];

}
?>