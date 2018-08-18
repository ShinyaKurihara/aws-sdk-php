<!DOCTYPE html>
<html lang="ja">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width,initial-scale=1.0">
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Cache-Control" content="no-cache">
<meta name="copyright" AWS TEST">
<title>AWS TEST</title>
<link rel="stylesheet" type="text/css" href="#{$smarty.const.FRONT_DIR_NAME}#css/common.css" media="all">
<link rel="stylesheet" type="text/css" href="#{$smarty.const.FRONT_DIR_NAME}#css/error.css" media="all">
<script type="text/javascript" src="#{$smarty.const.FRONT_DIR_NAME}#js/jquery-1.11.0.min.js"></script>
<script type="text/javascript" src="#{$smarty.const.FRONT_DIR_NAME}#js/tb.js"></script>
<script type="text/javascript" src="#{$smarty.const.FRONT_DIR_NAME}#js/jquery-ui.min.js"></script>
<script type="text/javascript" src="#{$smarty.const.FRONT_DIR_NAME}#js/jquery.ui.datepicker-ja.min.js"></script>
<script type="text/javascript" src="#{$smarty.const.FRONT_DIR_NAME}#js/back_confirm.js"></script>
<link rel="stylesheet" type="text/css" href="#{$smarty.const.FRONT_DIR_NAME}#css/jquery-ui.css" media="all">
</head>
<body>
<header>
#{*
	<div class="wrapper">
		<h1><a href="#{$smarty.const.FRONT_DIR_NAME}#"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/logo.png" alt="ALSOK">ネットdeガードマン</a></h1>
		<div class="head_Rcol">
			<div class="clearfix">
				<p class="home"><a href="#{$smarty.const.FRONT_DIR_NAME}#">ALSOK TOPページへ</a></p>
			</div>
			#{if $loginStatus != 1 && $loginStatus != 2}#
				<form action="#{$smarty.const.FRONT_DIR_NAME}#register/" method="post">
					<button type="submit" class="member"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/person.png" alt=""/>新規会員登録</button>
				</form>
				<p class="contact"><a href="#{$smarty.const.FRONT_DIR_NAME}#login/"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/arrow05.png" alt=""/>会員の方はこちら</a></p>
				<p class="contact"><a href="#{$smarty.const.FRONT_DIR_NAME}#general_inquiry/"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/mail.png" alt=""/>お問い合わせ</a></p>
				<p class="help"><a href=""><img src="#{$smarty.const.FRONT_DIR_NAME}#images/question_header.png" alt="">ヘルプ</a></p>
			#{else}#
				<form action="#{$smarty.const.FRONT_DIR_NAME}#user/" method="post">
					<button type="submit" class="member"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/person.png" alt=""/>マイページ</button>
					<p class="contact"><a href="#{$smarty.const.FRONT_DIR_NAME}#general_inquiry/"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/mail.png" alt=""/>お問い合わせ</a></p>
					<p class="help"><a href=""><img src="#{$smarty.const.FRONT_DIR_NAME}#images/question_header.png" alt="">ヘルプ</a></p>
					<button type="button" class="logoutin" onclick="window.location.href='#{$smarty.const.FRONT_DIR_NAME}#logout/';"><img src="#{$smarty.const.FRONT_DIR_NAME}#images/arrow.png" alt=""/>ログアウト</button>
				</form>
			#{/if}#
		</div><!-- /.head_Rcol -->
	</div><!-- /.wrapper -->
*}#	
</header>
<main>

