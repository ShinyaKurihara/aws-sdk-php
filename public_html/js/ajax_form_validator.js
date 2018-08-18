/*
	Ajax Form Validator Version 0.01
*/
;(function($) {
	// enterキーで送信は困るから無効化
	$("input").on("keydown", function(e) {
		if ((e.which && e.which === 13) || (e.keyCode && e.keyCode === 13)) {
			return false;
		} else {
			return true;
		}
	});

	$.fn.ajaxFormValidator = function(options) {
		var opts = $.extend({}, $.fn.ajaxFormValidator.defaults, options);
		var ajaxNow = false;
		var execNextTimeID = false;

		// デバッグログ
		var debugLog = function(debugText){
			if(opts.debugMode){
				console.log('ajaxFormValidator: ' + debugText);
			}
		};

		// 時間調整処理
		var timeOutFunc = function(){
			execNextTimeID = false;
			if(!ajaxNow){
				validateAjax();
			}else{
				execNextTimeID = window.setTimeout(timeOutFunc, opts.delay);
			}
		};

		// Ajax送信して結果を得る
		var validateAjax = function(){
			ajaxNow = true;
			var $modeInput = $targetForm.find('input[name="mode"]');
			var mode = $modeInput.val();
			$modeInput.val(mode + '_ajax');
			var serialize_data = $targetForm.serialize();
			var newFormFlag = $targetForm.hasClass('new');
			$modeInput.val(mode);
			debugLog(serialize_data);
			$targetForm.find(opts.sendButtons).prop({'disabled':true});
			$.ajax({
				url: opts.postUrl,
				type: opts.method,
				data: serialize_data,
				dataType: 'json',
				// 通信成功
				success: function(result, textStatus, xhr) {
					$targetForm.find('p.error.nobdr').hide();
					$targetForm.find('input,textarea,select,label,div.select-box01,div.radiobtn').removeClass('error');
					for(name in result){
						debugLog(name + ' = ' + result[name]);
						var message = result[name];
						if(message.substr(0, 1) == '#'){
							if(newFormFlag && !$targetForm.find('input[name="'+name+'"],textarea[name="'+name+'"],select[name="'+name+'"]').hasClass('changed')){
								message = "";
							}else{
								message =  message.substr(1);
							}
						}
						if(result[name] != '#'){
							$('#form_error_' + name).text(message).show();
						}
						$targetForm.find('input[name="'+name+'"],textarea[name="'+name+'"]').addClass('error').parent('label,div.radiobtn').addClass('error');
						$targetForm.find('select[name="'+name+'"]').parent('div.select-box01').addClass('error');
					}
					if(Object.keys(result).length === 0){
						$targetForm.find(opts.sendButtons).prop({'disabled':false});
					}else{
						$targetForm.find(opts.sendButtons).prop({'disabled':true});
					}
					ajaxNow = false;
					debugLog('OK.');
				},
				// 通信失敗
				error: function(xhr, textStatus, error) {
					ajaxNow = false;
					debugLog('NG.');
				}
			});
		};

		if(!opts.postUrl){
			debugLog('No postUrl.');
			return;
		}
		if(!$(this).is('form')){
			debugLog('Object is not a form.');
			return;
		}
		var $targetForm = $(this);

		var doNextTime = function(){
			$(this).addClass('changed');
			if(execNextTimeID) window.clearTimeout(execNextTimeID);
			execNextTimeID = window.setTimeout(timeOutFunc, opts.delay);
		}

		// text textareaは入力あるごとに投げる
		$targetForm.find('input,textarea').on('input', doNextTime);

		// radio checkbox selectは選択するたびに投げる
		$targetForm.find('input[type="radio"],input[type="checkbox"],input[type="file"],select').on('change', doNextTime);

	/*
		$targetForm.find('input[type="text"],textarea,select').each(function(){
			var $this = $(this);
			var value = $this.val();
			$this.data('zipOldValue', value);
		});
		$targetForm.find('input[type="text"],textarea,select').on('input', function(){
			var $this = $(this);
			var value = $this.val();
			var oldValue = $this.data('formOldValue');
			oldValue = oldValue ? oldValue : "";
			if(value != oldValue) $(this).change();
			$this.data('zipOldValue', value);
		});
*/
		if(!ajaxNow) validateAjax();
	};

	$.fn.ajaxFormValidator.defaults = {
		method: "post",
		postUrl: "",
		sendButtons: '#register_',
		delay: 300,
		debugMode: false
	};
})(jQuery);
