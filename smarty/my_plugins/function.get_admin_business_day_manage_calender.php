<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_business_day_manage_calender.php
 * Type:     function
 * Name:     get_admin_calender
 * Purpose:  営業日管理用のカレンダーを生成し返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_business_day_manage_calender($params){

#print_r($params);

	$formData = $params["formData"];

	$first_weekday = date( "w", mktime( 0, 0, 0, $params["mm"], 1, $params["yyyy"] ) );

	//指定年度の祝日の一覧を取得
	$holidayList = Holiday::getHolidayList($params["yyyy"]);

	$str="";
	$str.="<div class='box'>\n";
	$str.="<table class='tbl01'>\n";
	$str.="<caption>{$params["mm"]}月</caption>\n";
	$str.="<thead><tr><th>日</th><th>月</th><th>火</th><th>水</th><th>木</th><th>金</th><th>土</th></tr></thead>\n";
	$str.="<tr>\n";

	$i = 0; //カウント値リセット（曜日カウンター）
	while( $i != $first_weekday ){ //１日の曜日まで空白（&nbsp;）で埋める
		$str.="<td>&nbsp;</td>\n";
		$i ++;
	}
	 
	// 今月の日付が存在している間ループする
	for( $day=1; checkdate($params["mm"], $day, $params["yyyy"] ); $day++ ){
	 
	 	$style = $class="";
	 
	    //曜日の最後まできたらカウント値（曜日カウンター）を戻して行を変える
		if( $i > 6 ){
	        $i = 0;
			$str.="</tr>\n";
			$str.="<tr>\n";
	    }
	 
		$YYYYmmdd = date("Y-m-d", strtotime($params["yyyy"]."/".$params["mm"]."/".$day));
	 
		//-------------スタイルシート設定-----------------------------------
		if( $i == 0 || isset($holidayList[$YYYYmmdd]))		$style = "color:#C30;";//日曜日、祝日の文字色
		else if( $i == 6 )									$style = "color:#03C;";//土曜日の文字色
		else												$style = "color:black;";//月曜～金曜日の文字色
		    
		//-------------スタイルシート設定終わり-----------------------------

		// 日付セル作成とスタイルシートの挿入
		//入力
		if($params["mode"]=="edit"){
		
			$checked = isset($formData["day_".$YYYYmmdd]) ? "checked='checked'":"";
			
			
			#$str.="<td style=\"{$style}\">".$day."<br /><input type='checkbox' id='day_{$YYYYmmdd}' name='day_{$YYYYmmdd}' value='{$YYYYmmdd}' {$checked}></td>\n";
		   	
			$str.="<td>\n";
			$str.="<span>\n";
			$str.="<label for='day_{$YYYYmmdd}'><font style='{$style}'>{$day}</font></label>\n";
			$str.="</span>\n";
			$str.="<div class='mmR15'>\n";
			$str.="<input type='checkbox' id='day_{$YYYYmmdd}' name='day_{$YYYYmmdd}' value='{$YYYYmmdd}' {$checked}>\n";
			$str.="<label for='day_{$YYYYmmdd}' class='checkbox'></label>\n";
			$str.="</div>\n";
			$str.="</td>\n";
		   	
		}elseif($params["mode"]=="confirm"){
		    
			if(isset($formData["day_".$YYYYmmdd]))	$class = "class='day'";
			
			#$str.="<td style=\"{$style}\">{$day}</td>\n";
			$str.="<td {$class}>\n";
			$str.="<span>\n";
			$str.="<label><font style='{$style}'>{$day}</font></label>\n";
			$str.="</span>\n";
			$str.="</td>\n";
		}
		 
		$i++; //カウント値（曜日カウンター）+1
	}
	 
	while( $i < 7 ){ //残りの曜日分空白（&nbsp;）で埋める
	    $str.="\t<td>&nbsp;</td>\n";
	    $i++;
	}
	$str.="</tr>\n";
	$str.="</table>\n";
	$str.="</div>\n";
	
	return $str;

}
?>