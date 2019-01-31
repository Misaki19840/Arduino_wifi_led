<?php
	$select=$_POST['led1'];
	switch ($select) {
		case "On":
			$st_led1=1;
			break;
		case "Off":
			$st_led1=0;
			break;
	}
	
	$select=$_POST['led2'];
	switch ($select) {
		case "On":
			$st_led2=1;
			break;
		case "Off":
			$st_led2=0;
			break;
	}

	$ary = array('led1'=>$st_led1, 'led2'=>$st_led2);
    $json = json_encode($ary);
    echo $json;

	$fp = fopen("status.txt", 'w');
    fwrite($fp,  $json);
    fclose($fp);
?>