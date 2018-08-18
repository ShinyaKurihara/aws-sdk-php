<?php
/*
 * autoload関数
 * spl_autoload_register関数内に無名関数を記述することする
*/

//dirname(__FILE__)内のディレクトリ名一覧を定義
//このディレクトリ内に該当しない場合はdirname(__FILE__)直下に置くこと
//新規に追加可能
$autoloadDirs=array(
	"Db",
	"Front",
	"FormFront",
);

spl_autoload_register(
	function ($classname){
		
		//ディレクトリ一覧
		global $autoloadDirs;
	
		//クラス名から生成したディレクトリ名確保用
		$classDirName = "";
		
		//ディレクトリ名を取得
		preg_match("/^(".join("|",$autoloadDirs).")(.*)$/",$classname,$tmp);
		
		//マッチした場合はディレクトリ名を確保
		if(isset($tmp[1]) && strlen($tmp[1])){
			$classDirName = $tmp[1]."/";
		}
		
		//ファイルが存在した場合は呼び出す
		if (file_exists(dirname(__FILE__)."/".$classDirName.$classname.'.inc')) {
			require_once(dirname(__FILE__)."/".$classDirName.$classname.'.inc');
		}
	}
);
?>