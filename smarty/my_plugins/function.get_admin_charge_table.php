<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_charge_table.php
 * Type:     function
 * Name:     admin_charge_table
 * Purpose:  会員(顧客)登録、編集 選択している担当営業のテーブルを生成し返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_charge_table($params){

	if(!$params["system_user_id"]){
		return $params["flag"] ? "担当営業を選択してください。":"なし";
	}
		

	$table = "";

	//DB 事業所ユーザーのインスタンスを生成
	$dbSystemUsersObj = new DbSystemUsers(new MyPdo());
			
	$systemUser = $dbSystemUsersObj->getData(array("id"=>$params["system_user_id"]), array("office"));

	$table ="<table class='tbl04'> \n";
	$table.="<tr>\n<th>氏名</th>\n<td>".$systemUser["name_sei"]." ".$systemUser["name_mei"]."(".$systemUser["name_kana_sei"]." ".$systemUser["name_kana_mei"].")</td>\n</tr>\n";
	$table.="<tr>\n<th>事業所</th>\n<td>".$systemUser["office"]["name"]."</td>\n</tr>\n";
	$table.="</table>\n";
	
	return $table;

}
?>