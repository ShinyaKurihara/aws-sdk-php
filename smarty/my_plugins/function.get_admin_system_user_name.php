<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_system_user_name.php
 * Type:     function
 * Name:     admin_system_user_name
 * Purpose:  案件検索 事業所ユーザーIDから事業所ユーザー名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_system_user_name($params){

	if(!$params["system_user_id"])	return "";

	//会員(顧客)のDBインスタンスを生成
	$dbSystemUsersObj = new DbSystemUsers(new MyPdo());
		
	$data = $dbSystemUsersObj->getData(array("id"=>$params["system_user_id"]));
	
	return $data["name_sei"]." ".$data["name_mei"];

}
?>