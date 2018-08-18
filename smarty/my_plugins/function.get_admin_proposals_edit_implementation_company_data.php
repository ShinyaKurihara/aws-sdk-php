<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_proposals_edit_implementation_company_data.php
 * Type:     function
 * Name:     admin_proposals_edit_implementation_company_data
 * Purpose:  実施会社ユーザー登録、編集 実施会社IDから実施会社名を返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_proposals_edit_implementation_company_data($params){

	#$table.='<table class="list">';

	if(!$params["implementation_company_id"]){
		
		$table.='<tr><td>マッチング処理を実行してください</td></tr>';
	}else{

		//実施会社マスタのDBインスタンスを生成
		$dbImplementationCompaniesObj = new DbImplementationCompanies(new MyPdo());
			
		$data = $dbImplementationCompaniesObj->getData(array("id"=>$params["implementation_company_id"],"is_delete"=>0));
		
		$table.='<tr><th class="w25p">社名</th><td>'.$data["company_name"].'</td></tr>';
		$table.='<tr><th class="w25p">実施担当者名</th><td>'.$data["implementation_charge_name_sei"].$data["implementation_charge_name_mei"].'</td></tr>';
		$table.='<tr><th class="w25p">電話番号</th><td>'.$data["representative_tel"].'</td></tr>';
	}
	
	#$table.='</table>';
	
	return $table;

}
?>