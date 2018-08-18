<?php
class MyPdo {

	var $db = false;// コネクションハンドル
	var $stmt;
	var $errorInfo;
	var $queryStr;

	function __construct($connect = true) {
		if($connect){
		
			if(!$this->connect()){
				return false;
			}
		}

		return $this->db;
	}

	// データベースに接続する
	function connect() {

		try{
			$this->db = new PDO(DB_DNS, DB_USER, DB_PASSWORD, array(PDO::ATTR_EMULATE_PREPARES=>false));
			
		}catch(PDOException $e){
//			echo 'Error:'.$e->getMessage();
//			die("<br />DB ERROR!");
			return false;
		}
		return true;
	}

	// SQLの実行
	function execution($sql, $values=array() ){

		if(!$this->db){	$this->connect();	}
		
//SQLの文字列を生成(debug用)
#$this->makePutQuery($sql, $values);
#echo $this->getPutQueryString()."<br>";
		if(!$this->db){
			print('Error: DB ERROR');
			die("<br />DB ERROR!");
		}
		try{
			$this->stmt = $this->db->prepare($sql);
			if(!$this->stmt){
				print('Error: DB PREPARE ERROR');
				die("<br />DB SELECT ERROR!");
				return false;
			}
			$this->stmt->execute($values);
		}catch(PDOException $e){
			print('Error:'.$e->getMessage());
			die("<br />DB SELECT ERROR!");
			return false;
		}
		
		return true;
	}

	//結果数を返す
	function getRows(){
		return $this->stmt->rowCount();
	}

	//データを取得
	function getData(){
	
		return $this->stmt->fetch(PDO::FETCH_ASSOC);
	}

	//データをすべて取得
	function getDataAll(){
	
		return $this->stmt->fetchAll(PDO::FETCH_ASSOC);
	}

	//登録
	function insert($table_name, $datas){
	
		$newID = false;

		$columns=array();
		$values=array();
		$question_marks=array();
#print_r($datas);echo '<hr>';
		//配列に代入する
		foreach($datas as $k=>$v){
			if(is_array($v)) continue; // 配列が入っていたら無視
			$columns[]=$k;			//カラム名
			$values[]=$v;			//値
			$question_marks[]="?";	//?マーク
		}

		//SQL文の生成
		$sql="INSERT INTO ".$table_name." (".join(",", $columns).") VALUES(".join(",", $question_marks).")";

//SQLの文字列を生成(debug用)
#$this->makePutQuery($sql, $values);
#echo $this->getPutQueryString();
		if(!$this->db){
			print('Error: DB ERROR');
			die("<br />DB ERROR!");
		}

		//SQLを渡す
		$stmt = $this->db->prepare($sql);

		if(!$stmt){
			$this->errorInfo = 'Prepare Failed';
			return false;
		}

		//プリペアドステートメントの実行
		if(!$stmt->execute($values)){
			$this->errorInfo = $stmt->errorInfo();
			
			return false;
		}
		
		
		return true;
	}

	//更新
	function update($table_name, $data, $conditions=array(), $conditionValues=array()){
	
		$cnt = 0;

		$columns=array();
		$values=array();
		$w_columns=array();

		//更新するデータを配列に代入する
		foreach($data as $k=>$v){
			if(is_array($v)) continue; // 配列が入っていたら無視
			$columns[] = $k."=?";	//カラム名
			$values[] = $v;			//値
		}

		//条件式
		if(count($conditions)){
			//条件式はすでに出来ているので値のみを代入する
			foreach($conditionValues as $k=>$v){
				$values[] = $v;			//値
			}
		}else{
			$conditions[]=1;
		}

		
		//SQL文の生成
		$sql="UPDATE ".$table_name." SET ".join(", ", $columns)." WHERE ".join(" AND ", $conditions);


//SQLの文字列を生成(debug用)
#$this->makePutQuery($sql, $values);
#echo $this->getPutQueryString()."<br>";
		if(!$this->db){
			print('Error: DB ERROR');
			die("<br />DB ERROR!");
		}

		//SQLを渡す
		$stmt = $this->db->prepare($sql);

		if(!$stmt){
			$this->errorInfo = 'Prepare Failed';
			return false;
		}

		//プリペアドステートメントの実行
		if(!$stmt->execute($values)){
		//失敗
			$this->errorInfo = $stmt->errorInfo();
			return false;
		}

		return true;
	}

	//物理削除
	function delete($table_name, $conditions=array(), $values=array()){
	
		$cnt = 0;
		
		//SQL文の生成
		$sql="DELETE FROM ".$table_name;
		
		if(count($conditions))	$sql.=" WHERE ".join(" AND ", $conditions);


//SQLの文字列を生成(debug用)
#$this->makePutQuery($sql, $values);
#echo $this->getPutQueryString()."<br>";

		if(!$this->db){
			print('Error: DB ERROR');
			die("<br />DB ERROR!");
		}

		//SQLを渡す
		#$stmt = $this->db->prepare($sql);
		$this->stmt = $this->db->prepare($sql);

		if(!$this->stmt){
			$this->errorInfo = 'Prepare Failed';
			return false;
		}

		//プリペアドステートメントの実行
		if(!$this->stmt->execute($values)){
		//失敗
			$this->errorInfo = $this->stmt->errorInfo();
			return false;
		}

		return true;
	}

	function getErrorInfo(){
		return $this->errorInfo;
	}
	
	//直前に発行したSQLの文字列を生成
	//型などを意識していないため完全なものではないので注意
	function makePutQuery($sql, $values){
		#$this->queryStr="";
		$this->queryStr = vsprintf(preg_replace("/\?/","'%s'",$sql), $values);
	}
	
	//直前に発行したSQLの文字列を返す
	function getPutQueryString(){
		return $this->queryStr;
	}

}
?>