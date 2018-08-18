<!-- content3left -->
<div id="content_left">
<ul id="leftnav">

<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#">TOP</a></li>
#{if $loginStatus != 1 && $loginStatus != 2}#
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#register/">新規登録</a></li>
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#login/">ログイン</a></li>
#{else}#
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#logout/">ログアウト</a></li>
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#user/">マイページ</a></li>
#{/if}#
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#estimate/">簡易見積</a></li>
<li class="menuitem"><a href="#{$smarty.const.CUSTOMER_DIR_NAME}#general_inquiry/">お問合せ</a></li>
</ul>


</div>
<!-- content3left end -->