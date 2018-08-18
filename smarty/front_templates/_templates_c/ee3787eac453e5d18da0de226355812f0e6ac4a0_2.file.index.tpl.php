<?php
/* Smarty version 3.1.29, created on 2018-08-16 19:41:46
  from "/var/www/project/aws-sdk/smarty/front_templates/index/index.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_5b7554eaa661b4_35278207',
  'file_dependency' => 
  array (
    'ee3787eac453e5d18da0de226355812f0e6ac4a0' => 
    array (
      0 => '/var/www/project/aws-sdk/smarty/front_templates/index/index.tpl',
      1 => 1534416022,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:../header.tpl' => 1,
    'file:../footer.tpl' => 1,
  ),
),false)) {
function content_5b7554eaa661b4_35278207 ($_smarty_tpl) {
$_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:../header.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array('title'=>$_smarty_tpl->tpl_vars['page_title']->value,'my_name'=>$_smarty_tpl->tpl_vars['my_name']->value), 0, false);
?>


<div class="wrapper">
	<h2><span>Kurihara@TEST</span></h2>
		<a href="<?php echo htmlspecialchars(@constant('FRONT_DIR_NAME'), ENT_QUOTES, 'UTF-8');?>
s3/"><span>S3 Sample</span></a><br><br>
		
		<div class="caution_box">
			<h3 class="caution_title">TEST</h3>
			<p>AWS SDK TEST</p>
		</div>
</div><!-- /.wrapper -->

<?php $_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:../footer.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

<?php }
}
