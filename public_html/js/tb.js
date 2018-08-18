$(function(){
	if(window.innerWidth >= 980) return;

	$("#Lcol dt").click(function(e){
		if($(this).hasClass("open")){
			$("#Lcol dd").removeClass("open").slideUp();
		}else{
			$("#Lcol dt").removeClass("open");
			$("#Lcol dd").slideUp();
			$(this).next("#Lcol dd").slideDown();
			$(this).addClass("open");
		}
		e.stopPropagation();
	});

	$(document).click(function(e){
		$("#Lcol dd").removeClass("open").slideUp();
	});
});