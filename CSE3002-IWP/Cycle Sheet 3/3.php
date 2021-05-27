<?php

function factorial($n){
    $f = 1;
    for ( $i = 2; $i <= $n; $i++){
        $f = $f * $i;
    }
    return $f;
}

function NCR($n, $r){
    $ncr = factorial($n) / (factorial($r) * factorial($n - $r));
    return $ncr;
}

if(isset($_POST['sub'])){
    $n = $_POST['n'];
    $r = $_POST['r'];

    echo "<h1>nCr = ".NCR($n, $r)."</h1>";
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 Q3</title>
</head>
<body>
    <form action="3.php" method="post">
        Enter positive integer N: <input type="text" name="n">
        <br>
        Enter positive integer R: <input type="text" name="r">
        <br>
        <input name="sub" type="submit" value="Submit">
    </form>
</body>
</html>