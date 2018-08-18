<?php
/*
 * autoload�֐�
 * spl_autoload_register�֐����ɖ����֐����L�q���邱�Ƃ���
*/

//dirname(__FILE__)���̃f�B���N�g�����ꗗ���`
//���̃f�B���N�g�����ɊY�����Ȃ��ꍇ��dirname(__FILE__)�����ɒu������
//�V�K�ɒǉ��\
$autoloadDirs=array(
	"Db",
	"Front",
	"FormFront",
);

spl_autoload_register(
	function ($classname){
		
		//�f�B���N�g���ꗗ
		global $autoloadDirs;
	
		//�N���X�����琶�������f�B���N�g�����m�ۗp
		$classDirName = "";
		
		//�f�B���N�g�������擾
		preg_match("/^(".join("|",$autoloadDirs).")(.*)$/",$classname,$tmp);
		
		//�}�b�`�����ꍇ�̓f�B���N�g�������m��
		if(isset($tmp[1]) && strlen($tmp[1])){
			$classDirName = $tmp[1]."/";
		}
		
		//�t�@�C�������݂����ꍇ�͌Ăяo��
		if (file_exists(dirname(__FILE__)."/".$classDirName.$classname.'.inc')) {
			require_once(dirname(__FILE__)."/".$classDirName.$classname.'.inc');
		}
	}
);
?>