#{include file='../header.tpl' title=$page_title my_name=$my_name}#

<div class="wrapper">
	<h2><span>S3 TEST</span></h2>
	<div class="loginbox">
		<p class="mB30">S3へ画像をアップロードする</p>

		<div class="alignC mB30">
		
		<form method="post" action="#{$smarty.const.FRONT_DIR_NAME}#s3/up/" enctype="multipart/form-data">
		ファイル:<input type="file" name="up_file"><br><br>
		ディレクトリ:
		#{if $dir_list}#
		<select id="imgDir" name="imgDir">
			<option value="">選択してください</option>
			#{html_options options=$dir_list selected=$formData["pref_number"]}#
		</select>
		#{/if}#
		　新規:<input type="text" name="newImgDir" value=""><br><br>
		#{*<input type="hidden" name="mode" value="up">*}#
		<input type="submit" value="upload">
		</form>
		
		#{if $image_list }#
		<br>
		#{foreach from=$image_list item=url key=key}#
		<img src="#{$url}#"><br>
		<form method="post" action="#{$smarty.const.FRONT_DIR_NAME}#s3/del/">
			<input type="hidden" name="delKey" value="#{$key}#" >
			<input type="submit" value="delete">
		</form>
		<br>
		#{/foreach}#
		#{else}#
		画像がありません
		#{/if}#
<!--			<p class="linkbtn"><a href="#{$smarty.const.FRONT_DIR_NAME}#upload/"><span>申込スタート</span></a></p>-->
		</div>
		
		

		
		<div class="caution_box">
			<h3 class="caution_title">注意</h3>
			<p>テキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキストテキスト</p>
		</div>
#{*		
		<p class="linkbtn"><a href="#{$smarty.const.FRONT_DIR_NAME}#test.php"><span>test.php</span></a></p>
		<p class="linkbtn"><a href="#{$smarty.const.FRONT_DIR_NAME}#test/"><span>test.php.php</span></a></p>
*}#		
	</div><!-- /.box -->
</div><!-- /.wrapper -->

<script>
//$(function(){
	$('div.head_Rcol').load("#{$smarty.const.FRONT_DIR_NAME}#ajax_header/");
	
//});
</script>
#{include file='../footer.tpl'}#
