<?php
/*
 *  テンプレートクラス
 */
class MySmarty extends Smarty{

	/*
	 *  テンプレートを読み込んで実行する。
	 *  $_context は変数名をキー、値を要素とする連想配列。
	 */
	function __construct($tplType, $contents_name){
	
		parent::__construct();

		$this->left_delimiter = '#{';
		$this->right_delimiter = '}#';

		//テンプレートのルートディレクトリ
		$_templateDirCore = SMARTY_TPL_CORE_DIR.$tplType.'_templates/';

		//テンプレート
		$this->template_dir = $_templateDirCore.$contents_name.'/';
		
		//キャッシュ
		$this->compile_dir  = $_templateDirCore.'_templates_c/';
		
		$this->config_dir   = SMARTY_TPL_CORE_DIR.'configs/';
		$this->cache_dir    = SMARTY_TPL_CORE_DIR.'cache/';

		
		$this->escape_html = true;
		
		//自作プラグインの場所を登録
		$this->addPluginsDir(array(SMARTY_TPL_CORE_DIR.'my_plugins/'));

		
		// 次の行のコメントをはずすと、デバッギングコンソールを表示します
		#$this->debugging = true;
	}
}

?>