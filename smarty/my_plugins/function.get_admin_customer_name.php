<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_customer_name.php
 * Type:     function
 * Name:     admin_customer_name
 * Purpose:  案件検索 会員(顧客)IDから会員(顧客)名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_customer_name($params){

	if(!$params["customer_id"])	return "";

	//会員(顧客)のDBインスタンスを生成
	$dbCustomersObj = new DbCustomers(new MyPdo());
		
	$data = $dbCustomersObj->getData(array("id"=>$params["customer_id"]));
	
	return $data["name_sei"]." ".$data["name_mei"];

}
?>