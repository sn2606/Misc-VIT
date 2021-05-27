<?php

$read = fopen("4-read.txt", "r");
$write = fopen("4-write.txt", "r+");
// copying data
while(!feof($read)){
    $str = fgets($read);
    fwrite($write, $str);
}
fclose($read);
fclose($write);

// displaying data in browser
$write = fopen("4-write.txt", "r+");
while(!feof($write)){
    $str = fgets($write);
    echo $str."<br>";
}
fclose($write);
?>