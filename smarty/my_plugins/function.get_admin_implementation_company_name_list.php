<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_implementation_company_name_list
 * Type:     function
 * Name:     admin_implementation_company_name
 * Purpose:  実施会社ユーザー登録、編集 実施会社IDから実施会社名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_implementation_company_name_list($params){

	if(!$params["implementation_company_id_list"])	return "実施会社を選択出来ます。";

	$implementation_company_id_list = explode(",", $params["implementation_company_id_list"]);

	//実施会社マスタのDBインスタンスを生成
	$dbImplementationCompaniesObj = new DbImplementationCompanies(new MyPdo());
		
	$companyList = $dbImplementationCompaniesObj->getList(array("id_list"=>$implementation_company_id_list));
	
	$companyNameList=array();

	foreach($companyList as $num=>$company){
		$companyNameList[]=$company["company_name"];
	
	}

	return join("、",$companyNameList);

}
?>