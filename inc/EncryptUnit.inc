<?php
require_once('Crypt/Blowfish.php');

class EncryptUnit {

	function EncryptUnit(){
	}
	
	/**
	 * �����Ŏw�肳�ꂽ��������A�Í����{Base64����������.
	 */
	static public function blowfish_encrypt($str, $key){
	
		$blowfish = new Crypt_Blowfish($key);
		
		
#		$iv = substr(md5(uniqid(rand(), 1)), 0, 8);

#		$blowfish = Crypt_Blowfish::factory('cbc', $key, $iv);
		
		$str = base64_encode($blowfish->encrypt($str));

		return $str;
	}

	/**
	 * �����Ŏw�肳�ꂽ�����񂪁A�Í����{Base64���������ꂽ������Ƃ݂Ȃ��A
	 * �����������݂�.
	 */
	static public function blowfish_decrypt($str, $key){
		$blowfish =& new Crypt_Blowfish($key);

		$str = $blowfish->decrypt(base64_decode($str));
		$str = rtrim($str,"\0");

		return $str;
	}
}
?>