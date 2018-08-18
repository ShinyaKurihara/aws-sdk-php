#{include file='../header.tpl' title=$page_title my_name=$my_name}#

<div class="wrapper">
	<h2><span>Kurihara@TEST</span></h2>
		<a href="#{$smarty.const.FRONT_DIR_NAME}#s3/"><span>S3 Sample</span></a><br><br>
		
		<div class="caution_box">
			<h3 class="caution_title">TEST</h3>
			<p>AWS SDK TEST</p>
		</div>
</div><!-- /.wrapper -->

#{include file='../footer.tpl'}#
