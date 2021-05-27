<?php

function isPalindrome($str) {
    $i = 0;
    $j = strlen($str)-1;
    $flag = 1;
    while($i < $j){
        if($str[$i] != $str[$j]){
            echo "<h1>Not Palindrome</h1>";
            $flag = 0;
            break;
        }
        $i++;
        $j--;
    }

    if($flag === 1){
        echo "<h1>Palindrome</h1>";
    }
}

if(isset($_POST['sub'])){
    $str = $_POST['str'];
    isPalindrome($str);
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 1D</title>
</head>
<body>
    <form action="1d.php" method="post">
        Enter a string: <input type="text" name="str">
        <br>
        <input name="sub" type="submit" value="Submit">
    </form>
</body>
</html>