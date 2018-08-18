<?php
/*
* メール送信クラス
  正常なﾒｰﾙｱﾄﾞﾚｽならtrueそうでなければfalseを返す
*/

class SendMail
{

  var $subject;		//件名
  var $body;		//本文
  var $to;			//受信者
  var $fromname;	//送信者の名前
  var $fromAdress;	//送信者のアドレス
  var $fileName;	//ファイル名
  var $mailPart;	//メール本文のデータ
  var $mailCarrier;	//メールのキャリア
  var $attachedFileName;

  var $pram;
  
  var $smarty;
  
  function SendMail(){
	
	$this->pram =  array(
		'host'=> 'localhost',
		'port'=> 25,
		'from'=> "",
		'protocol'=>'SMTP',
	);
	
	//smartyのオブジェクトを生成
	$this->smarty = new Smarty();
	//デリミタを設定
	
	$this->smarty->left_delimiter = '#{';
	$this->smarty->right_delimiter = '}#';

	//キャッシュ
	$this->smarty->compile_dir  = SMARTY_TPL_CORE_DIR.'mail_templates_c/';
	$this->smarty->config_dir   = SMARTY_TPL_CORE_DIR.'configs/';
	$this->smarty->cache_dir    = SMARTY_TPL_CORE_DIR.'cache/';

	//自作プラグインの場所を登録
	$this->smarty->addPluginsDir(array(SMARTY_TPL_CORE_DIR.'my_plugins/'));
	
	// メール文字化け対策
	mb_detect_order('ASCII,JIS,UTF-8,EUC-JP,SJIS');
	mb_internal_encoding('UTF-8');
	mb_language('ja');
  }

  #function setMailItems($to, $fromAdress, $subject, $body, $attachedFileName=""){
  function setMailItems($to, $fromAdress, $subject, $body, $attachedFileName=array()){
	$this->pram['from']= $fromAdress;
	
  	$this->to = $to;								//ユーザーのメールアドレス
	$this->fromAdress = $fromAdress;				//ファイルの名前
	$this->attachedFileName = $attachedFileName;	//添付ファイル

	$this->subject = $subject;						//メールタイトル
	$this->body = $body;							//メール本文
  }
  
  //メール文で変換する文字列(配列)をセットする
  function setMailBodyParts($mailPart){
  	  if(!is_array($mailPart)) return false;
  	  $this->mailPart = $mailPart;		//本文に使う文字列群
  }
  
  //本文をセットする
  function setBodyByFile($path){
  	$this->body="";//初期化

	//本文で使用する変数をsmartyに転換する
	foreach($this->mailPart as $k=>$v){
		$this->smarty->assign($k, $v);
	}

	//本文の生成
	$this->body = $this->smarty->fetch($path);
  }
  
  function isSend(){

		$header="";
		$this->to = '<'.$this->to.'>';
		$this->body =mb_convert_encoding($this->body,"utf8",'auto');
		
		#$recipients = explode(',', str_replace(' ','',_RECIPIENTS_));
		#$recipient_names = explode(',', str_replace(' ','',_RECIPIENTS_NAME_));
		
		
		$mail = & new Qdmail();
		//$mail -> smtp(true);
		$mail -> smtp(false);
		$mail -> smtpServer( $this->pram );
		
		$mail -> charsetHeader( 'iso-2022-jp' , '7bit' );
		$mail -> charsetBody( 'utf-8' , 'base64' );
		
		$mail->simpleAttach(true);

		//添付ファイル
		#if(strlen($this->attachedFileName) && is_file($this->attachedFileName))		$mail->attach($this->attachedFileName);
		if(count($this->attachedFileName) )	$mail->attach($this->attachedFileName);
		#if(strlen($this->attachedFileName) && is_file(ATTACHED_FILE_PATH.$this->attachedFileName))
		#$mail -> attach (ATTACHED_FILE_PATH.$this->attachedFileName);

		#$mail -> to($recipients, $recipient_names);
		$mail -> to($this->to);
		$mail -> subject($this->subject);
		$mail -> from($this->fromAdress );
		$mail -> replyto($this->fromAdress );
		$mail -> text($this->body);
		$mail -> addHeader( 'errors_to' , $this->fromAdress );
		$mail -> addHeader( 'X-sender' ,$this->fromAdress );
		
$this->mailLog();
$return_flag=true;

		//$return_flag = $mail ->send();
		
		if(!$return_flag)	return false;
		
		return true;
	
  }

	function mailLog(){
		$handle = fopen(dirname(dirname(__FILE__)).'/mail_log.txt', 'a+');
		fwrite($handle, "--------------------------------------------------\n");
		fwrite($handle, date("Y/m/d H:i:s")."\n");
		fwrite($handle, 'TO: '.$this->to . "\n");
		fwrite($handle, 'SUBJECT: '.$this->subject . "\n");
		fwrite($handle, "\n".$this->body . "\n");
	}


}
?>