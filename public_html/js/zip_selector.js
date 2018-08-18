/*
 郵便番号から住所取得
 */
;( function( $ ) {
	var changeAddress = function($target, data){
		if(!data){
			data = {
				'pref' : '',
				'pref_number' : '',
				'address1' : '',
				'address2' : ''
			}
		}
		var $parent = $target.closest('table');
		$parent.find('input.pref_input').val(data.pref);
		$parent.find('select.pref_select').val(data.pref_number);
		$parent.find('input.address1_input').val(data.address1 + data.address2).change();
	};

	var zipChangeHandler = function(){
		var $this = $(this);
		var value = $this.val();
		var oldValue = $this.data('zipOldValue');
		oldValue = oldValue ? oldValue : "";

		if(oldValue != value && value.match(/^\d{7}$/)){
			$.get('/ajax_zip/z2a/' + value + '/', function(data, textStatus, jqXHR){
				if(textStatus == 'success' && data && data.status){
					if(data.status == 'success'){
//alert("OK:"+data.status);
						changeAddress($this, data);
					}else{
//alert("fail:"+data.status);
						changeAddress($this, 0);
					}
				}
			});
		}
		$this.data('zipOldValue', value);
	};

	$(document).on('keyup', 'input.zip_input', zipChangeHandler);
	$(document).on('input', 'input.zip_input', zipChangeHandler);

} )( jQuery );