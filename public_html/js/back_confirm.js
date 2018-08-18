/*
 戻る：確認表示
 */
;( function( $ ) {

	$(function(){
		$('.back_confirm_1').on('click',function(){
			return window.confirm("前のページに戻ります。\nよろしいですか?");
		});
	});

} )( jQuery );
