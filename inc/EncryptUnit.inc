<?php
require_once('Crypt/Blowfish.php');

class EncryptUnit {

	function EncryptUnit(){
	}
	
	/**
	 * 引数で指定された文字列を、暗号化＋Base64符号化する.
	 */
	static public function blowfish_encrypt($str, $key){
	
		$blowfish = new Crypt_Blowfish($key);
		
		
#		$iv = substr(md5(uniqid(rand(), 1)), 0, 8);

#		$blowfish = Crypt_Blowfish::factory('cbc', $key, $iv);
		
		$str = base64_encode($blowfish->encrypt($str));

		return $str;
	}

	/**
	 * 引数で指定された文字列が、暗号化＋Base64符号化された文字列とみなし、
	 * 復号化を試みる.
	 */
	static public function blowfish_decrypt($str, $key){
		$blowfish =& new Crypt_Blowfish($key);

		$str = $blowfish->decrypt(base64_decode($str));
		$str = rtrim($str,"\0");

		return $str;
	}
}
?>