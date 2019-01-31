<?php
$data = $_GET['data'];
$filename = "status.txt";
if($data=='a'){
    $fp = fopen($filename, 'r');
    $contents = fread($fp, filesize($filename));
    print($contents);
    fclose($fp);
}
else
{
    echo "<p>data：" . $data ."</p>";
}
?>