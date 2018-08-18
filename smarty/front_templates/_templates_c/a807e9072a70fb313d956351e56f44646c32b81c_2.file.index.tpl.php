<?php
/* Smarty version 3.1.29, created on 2018-08-16 23:50:26
  from "/var/www/project/aws-sdk/smarty/front_templates/s3/index.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_5b758f321e1dc8_36596408',
  'file_dependency' => 
  array (
    'a807e9072a70fb313d956351e56f44646c32b81c' => 
    array (
      0 => '/var/www/project/aws-sdk/smarty/front_templates/s3/index.tpl',
      1 => 1534431017,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:../header.tpl' => 1,
    'file:../footer.tpl' => 1,
  ),
),false)) {
function content_5b758f321e1dc8_36596408 ($_smarty_tpl) {
if (!is_callable('smarty_function_html_options')) require_once '/var/www/project/aws-sdk/smarty/libs/plugins/function.html_options.php';
$_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:../header.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array('title'=>$_smarty_tpl->tpl_vars['page_title']->value,'my_name'=>$_smarty_tpl->tpl_vars['my_name']->value), 0, false);
?>


<div class="wrapper">
	<h2><span>S3 TEST</span></h2>
	<div class="loginbox">
		<p class="mB30">S3へ画像をアップロードする</p>

		<div class="alignC mB30">
		
		<form method="post" action="<?php echo htmlspecialchars(@constant('FRONT_DIR_NAME'), ENT_QUOTES, 'UTF-8');?>
s3/up/" enctype="multipart/form-data">
		ファイル:<input type="file" name="up_file"><br><br>
		ディレクトリ:
		<?php if ($_smarty_tpl->tpl_vars['dir_list']->value) {?>
		<select id="imgDir" name="imgDir">
			<option value="">選択してください</option>
			<?php echo smarty_function_html_options(array('options'=>$_smarty_tpl->tpl_vars['dir_list']->value,'selected'=>$_smarty_tpl->tpl_vars['formData']->value["pref_number"]),$_smarty_tpl);?>

		</select>
		<?php }?>
		　新規:<input type="text" name="newImgDir" value=""><br><br>
		
		<input type="submit" value="upload">
		</form>
		
		<?php if ($_smarty_tpl->tpl_vars['image_list']->value) {?>
		<br>
		<?php
$_from = $_smarty_tpl->tpl_vars['image_list']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$__foreach_url_0_saved_item = isset($_smarty_tpl->tpl_vars['url']) ? $_smarty_tpl->tpl_vars['url'] : false;
$__foreach_url_0_saved_key = isset($_smarty_tpl->tpl_vars['key']) ? $_smarty_tpl->tpl_vars['key'] : false;
$_smarty_tpl->tpl_vars['url'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['key'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['url']->_loop = false;
foreach ($_from as $_smarty_tpl->tpl_vars['key']->value => $_smarty_tpl->tpl_vars['url']->value) {
$_smarty_tpl->tpl_vars['url']->_loop = true;
$__foreach_url_0_saved_local_item = $_smarty_tpl->tpl_vars['url'];
?>
		<img src="<?php echo htmlspecialchars($_smarty_tpl->tpl_vars['url']->value, ENT_QUOTES, 'UTF-8');?>
"><br>
		<form method="post" action="<?php echo htmlspecialchars(@constant('FRONT_DIR_NAME'), ENT_QUOTES, 'UTF-8');?>
s3/del/">
			<input type="hidden" name="delKey" value="<?php echo htmlspecialchars($_smarty_tpl->tpl_vars['key']->value, ENT_QUOTES, 'UTF-8');?>
" >
			<input type="submit" value="delete">
		</form>
		<br>
		<?php
$_smarty_tpl->tpl_vars['url'] = $__foreach_url_0_saved_local_item;
}
if ($__foreach_url_0_saved_item) {
$_smarty_tpl->tpl_vars['url'] = $__foreach_url_0_saved_item;
}
if ($__foreach_url_0_saved_key) {
$_smarty_tpl->tpl_vars['key'] = $__foreach_url_0_saved_key;
}
?>
		<?php } else { ?>
		画像がありません
		<?php }?>
<!--			<p class="linkbtn"><a href="<?php echo htmlspecialchars(@constant('FRONT_DIR_NAME'), ENT_QUOTES, 'UTF-8');?>
upload/"><span>申込スタート</span></a></p>-->
		</div>
		
		

		
		<div class="caution_box">
			<h3 class="caution_title">注意</h3>
			<p>テキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキスト</p>
		</div>
		
	</div><!-- /.box -->
</div><!-- /.wrapper -->

<?php echo '<script'; ?>
>
//$(function(){
	$('div.head_Rcol').load("<?php echo htmlspecialchars(@constant('FRONT_DIR_NAME'), ENT_QUOTES, 'UTF-8');?>
ajax_header/");
	
//});
<?php echo '</script'; ?>
>
<?php $_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:../footer.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

<?php }
}
