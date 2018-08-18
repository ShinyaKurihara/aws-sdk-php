<?php

class PagerClass{
	
	var $id;
	var $putNum;
	var $nowMax;
	var $perPage;
	var $setting=array();
	var $tmpRqu=array();
	var $numberLinks=array();
	var $phpSelf;
	
	function PagerClass($setting, $num=0){
		
		if( !is_array($setting) )	return false;
		
		$this->setting = $setting;
		
		//リクエストにidNameがあった場合は代入
		if( strlen($_REQUEST[ $this->setting["idName"] ]) )	$this->id = $_REQUEST[ $this->setting["idName"] ];
		//リクエストにidNameがない場合は指定した場所から初期化(指定無し=0)
		else												$this->id = $num;

		$this->phpSelf = !$this->setting["mod_rewrite"] ? $_SERVER[PHP_SELF] : preg_replace("/\.php$/", "/", $_SERVER[PHP_SELF]);

		//$_SERVER[PHP_SELF]がindexだった場合は削除
		$this->phpSelf = preg_replace("/index\/$/", "", $this->phpSelf);

		$this->perPage=$this->setting["perPage"];
		$this->makePutNum();
		$this->makeNowMax();
	}
	
	//出力する初期値を設定する
	function makePutNum(){
		$this->putNum = $this->setting["perPage"]*$this->id;
	}
	
	//現在のページの最大値を設定する
	function makeNowMax(){
		
		$this->nowMax = $this->setting["perPage"]+$this->putNum;
		
		//最大値の制御
		//最大値を超えたら、最大値を代入
		if( $this->setting["total"] < $this->nowMax )
			$this->nowMax = $this->setting["total"];
	}
	
	//戻るリンクの生成
	function getPrev(){
		
		//１ページ目なら「戻る」の終わりを出す
		if($this->id <= 0 || ($this->setting["total"] < $this->nowMax ) )	return false;
		//return $this->setting["prevMaxMsg"];
		
		$this->setRquest(array($this->setting["idName"]=>($this->id - 1)));
		
		$ruq = $this->makeRquestStr();	//リクエストの生成
		
		return "<a href='".$this->phpSelf.$ruq."'>".$this->setting["prevImg"]."</a>";
		#return "<a href='$_SERVER[PHP_SELF]?".$this->setting["idName"]."=".($this->id - 1).$ruq."'>".$this->setting["prevImg"]."</a>";
	}
	
	//次へリンクの生成
	function getNext(){
		//最終ページなら「次へ」の終わりを出す
		if($this->setting["total"] <= $this->nowMax)	return $this->setting["nextMaxMsg"];
		
		$this->setRquest(array($this->setting["idName"]=>($this->id + 1)));
		
		$ruq = $this->makeRquestStr();	//リクエストの生成
		
		return "<a href='".$this->phpSelf.$ruq."'>".$this->setting["nextImg"]."</a>";
		#return "<a href='$_SERVER[PHP_SELF]?".$this->setting["idName"]."=".($this->id + 1).$ruq."'>".$this->setting["nextImg"]."</a>";
	}

	//戻るリンクの生成	その２
	//「前のｘ件」
	function getPrev2(){
		
		//１ページ目なら「戻る」の終わりを出す
		if($this->id <= 0)	return $this->setting["prevMaxMsg"];
		
		$this->setRquest(array($this->setting["idName"]=>($this->id - 1)));
		
		$ruq = $this->makeRquestStr();	//リクエストの生成
		
		return "<a href='".$this->phpSelf.$ruq."'>前の".$this->setting["perPage"]."件</a>";
		#return "<a href='$_SERVER[PHP_SELF]?".$this->setting["idName"]."=".($this->id - 1).$ruq."'>前の".$this->setting["perPage"]."件</a>";
		
	}
	
	//次へリンクの生成
	//「次のｘ件」
	function getNext2(){
		//最終ページなら「次へ」の終わりを出す
		if($this->setting["total"] <= $this->nowMax)	return $this->setting["nextMaxMsg"];
		
		$this->setRquest(array($this->setting["idName"]=>($this->id + 1)));
		
		$ruq = $this->makeRquestStr();	//リクエストの生成
		
		//最終ページの件数
		if($this->setting["total"] < ($this->nowMax+$this->setting["perPage"]))
			$num = $this->setting["total"]-$this->nowMax;
		else	
			$num = $this->setting["perPage"];
			
			
		return "<a href='".$this->phpSelf.$ruq."'>次の".$num."件</a>";
	}

	//前のページがあるかをチェックする
	function prevCheck(){
		
		//１ページ目なら「戻る」の終わりを出す
		if($this->id <= 0)	return false;
		
		return true;
	}

	//次のページがあるかをチェックする
	function nextCheck(){
		//最終ページなら「次へ」の終わりを出す
		if($this->setting["total"] <= $this->nowMax)	return false;
		
		return true;
	}

	//リンクに付けるリクエストをセットする
	function setRquest( $rqu, $varName="" ){
		
		//配列の場合
		if( is_array($rqu) ){
			foreach($rqu as $k => $v){
				$this->tmpRqu[$k]=$v;
			}
		}else{
		//単体
			$this->tmpRqu[$varName]=$rqu;
		}
	}
	
	//リクエストの文字列を生成する
	//※このメソッドは外部から呼び出す必要は無い
	function makeRquestStr(){
		
		$str="";
		if(!is_array($this->tmpRqu))	return false;
			
		foreach($this->tmpRqu as $k => $v){
		
			//apacheのmod_rewriteを使用しない場合
			if(!$this->setting["mod_rewrite"]){
		
				if( !empty($v) )	$str.="&".$k."=".$v;
				else				$str.="&".$k;
			}else{
				$str.=$v."/";
			}
		}

		return $str;
	}
	
	//リンク生成　こんなの⇒　1 | 2 | 3 | 4 | 5 | 6
	function putNumbers($tag="", $selectTag="", $selectClass=""){
		
		$str="";
		
		//トータル / 一ページに表示する件数
		$links = ceil($this->setting["total"]/ $this->setting["perPage"]);
		
		//１ページしかない場合はリンクは生成しない
		//if($links==1)	return false;
		
		
		$delta = $this->setting["delta"];	//リンク数
		$deltaHalf = $delta/2;				//リンク数の半分
		
		if($links >$delta){
			
			if($this->id <= $deltaHalf){
				$start = 0;
				$end = $delta;
			}elseif($this->id <= ($links - $deltaHalf)){
				$start = $this->id - $deltaHalf;
				$end = $this->id + $deltaHalf;
				
			}else{
				$start = $links - $delta;
				$end = $links;
			}
		}else{
			$start = 0;
			$end = $links;
		}

		#$ruq = $this->makeRquestStr();	//リクエストの生成
		
		$tmp=array();
		
		//リンクテキストの生成
		for( $i=$start; $i<$end; $i++ ){
			$str="";
			
			if($i!=$this->id){	//リンク
			
				$this->setRquest(array($this->setting["idName"]=>$i));
				
				$ruq = $this->makeRquestStr();	//リクエストの生成
			
				if($tag)	$str.="<{$tag}>";
				$str.="<a href='".$this->phpSelf.$ruq."'>".($i+1)."</a>";
				if($tag)	$str.="</{$tag}>";
			}else{				//現在のページ
				if($selectTag)	$str.="<{$selectTag} class='{$selectClass}'>";
				$str.=($i+1);
				if($selectTag)	$str.="</{$selectTag}>";
			}
			$tmp[]=$str."\n";
			//セパレーター
			#if( $i!=($end-1)  )	$str.=$this->setting["separator"];
		}
		
		return join($this->setting["separator"], $tmp);
	}
	
	//page n of nの文字列を返す
	function getPageOf(){
		$str = "page ".($this->id+1)." of ".ceil($this->setting["total"]/$this->setting["perPage"]);
		
		return $str;
		
	}
	
	function showMyVariable()
	{
		echo "
		id==>  $this->id	<br>
		putNum==>  $this->putNum<br>
		nowMax==>  $this->nowMax<br>
		total==>".$this->setting[total]."<br>
		prev==>  $this->prev<br>
		next==>  $this->next<br>";
	}
}
/*
$page_setting=array(
    'perPage'=> 10,				// 一ページに表示する件数
    'delta'=> 6,				// 一ページに表示するリンク数
    'total'=> 100,   			// ページング対象データの総数
    'separator' => '　',		// ページリンクのセパレータ文字列
    'prevImg'=> '<<戻る',			// 戻るリンクのテキスト(imgタグ使用可)
    'prevMaxMsg'=> '',			// 戻るリンクの終わり(imgタグ使用可)
    'nextImg'=> '次へ>>',			// 次へリンクのテキスト(imgタグ使用可)
    'nextMaxMsg'=> '',			// 次へリンクの終わり(imgタグ使用可)
    'idName'=>'pID'				//リクエストの名前
);
*/
?>