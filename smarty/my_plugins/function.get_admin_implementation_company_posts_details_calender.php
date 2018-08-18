<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * File:     function.get_admin_implementation_company_posts_details_calender.php
 * Type:     function
 * Name:     get_admin_calender
 * Purpose:  シーズン設定新規登録、編集用のカレンダーを生成し返す
 * -------------------------------------------------------------
 */


function smarty_function_get_admin_implementation_company_posts_details_calender($params){

	//$formData = $params["formData"];
	
	$ymd = $params["ym"]."01";

	$year = date("Y", strtotime($ymd));
	$month = date("m", strtotime($ymd));

	$first_weekday = date( "w", strtotime($ymd) );

	//指定年度の祝日の一覧を取得
	$holidayList = Holiday::getHolidayList($year);

	$str="";
	
	#$str.=$params["year"]."年".$params["month"]."月"."<br />\n";
	$str.='<div class="box">'."\n";
	$str.='<table class="tbl01">'."\n";
	$str.="<caption>".$year."年".$month."月"."</caption>\n";
	
	$str.="<thead>\n";
	$str.="<tr>\n";
	$str.="<td style=\"color:#C30\">日</td><td>月</td><td>火</td><td>水</td><td>木</td><td>金</td><td style=\"color:#03C\">土</td>\n";
	$str.="</tr>\n";
	$str.="</thead>\n";
	$str.="<tbody>\n";
	$str.="<tr>\n";
	 
	$i = 0; //カウント値リセット（曜日カウンター）
	while( $i != $first_weekday ){ //１日の曜日まで空白（&nbsp;）で埋める
		$str.="<td>&nbsp;</td>\n";
		$i ++;
	}
	 
	// 今月の日付が存在している間ループする
	for( $day=1; checkdate($month, $day, $year); $day++ ){
	 
	    //曜日の最後まできたらカウント値（曜日カウンター）を戻して行を変える
	    if( $i > 6 ){
	        $i = 0;
			$str.="</tr>\n";
			$str.="<tr>\n";
	    }
	 
	 $YYYYmmdd = date("Y-m-d", strtotime($year."/".$month."/".$day));
	 
	//-------------スタイルシート設定-----------------------------------
		
	    if( $i == 0 || isset($holidayList[$YYYYmmdd]))		$style = "color:#C30;";//日曜日、祝日の文字色
	    else if( $i == 6 )									$style = "color:#03C;";//土曜日の文字色
	    else												$style = "color:black;";//月曜～金曜日の文字色

	//-------------スタイルシート設定終わり-----------------------------

	   	//if(isset($formData["day_".$YYYYmmdd]))	$style.="background:#FFE4B5";
	   	
	   	$str.="<td style=\"{$style}\" id=\"td_{$YYYYmmdd}\" onclick=\"get_post_data('{$YYYYmmdd}')\">{$day}</td>\n";
	   	
/*	    
		// 日付セル作成とスタイルシートの挿入
		//入力
		if($params["mode"]=="edit"){
		
			$checked = isset($formData["day_".$YYYYmmdd]) ? "checked='checked'":"";
	    	$str.="<td style=\"{$style}\">".$day."<br /><input type='checkbox' id='day_{$YYYYmmdd}' name='day_{$YYYYmmdd}' value='{$YYYYmmdd}' {$checked}></td>\n";
	    }
	    elseif($params["mode"]=="confirm"){
	    
	    	if(isset($formData["day_".$YYYYmmdd]))	$style.="background:#FFE4B5";

	    	$str.="<td style=\"{$style}\">{$day}</td>\n";
	    }
*/
	    $i++; //カウント値（曜日カウンター）+1
	}
	 
	while( $i < 7 ){ //残りの曜日分空白（&nbsp;）で埋める
	    $str.="\t<td>&nbsp;</td>\n";
	    $i++;
	}
	$str.="</tr>\n";
	$str.="</tbody>\n";
	$str.="</table>\n";
	$str.="</div>\n";
	
	return $str;

}
?>