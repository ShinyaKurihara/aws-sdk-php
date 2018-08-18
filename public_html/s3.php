<?php
/*
* TOP
*/
include_once dirname(__FILE__)."/../conf/core.inc";

#print_r($_REQUEST);

$obj = new FrontS3($_REQUEST["mode"]);
