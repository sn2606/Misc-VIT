<!-- Get user name and greet the user based on system time (like good morning) -->

<?php
if(isset($_POST['sub'])){
    $uname = $_POST['uname'];
    date_default_timezone_set('Asia/Kolkata');
    $h = (int)date("H");
    $greet = "";
    if($h < 5 && $h >= 20){
        $greet = "night";
    }elseif($h >= 5 && $h < 12){
        $greet = "morning";
    }elseif($h >= 12 && $h <= 16){
        $greet = "afternoon";
    }else{
        $greet = "evening";
    }

    echo "<h1>Good ".$greet." ".$uname."</h1>";
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 1b</title>
</head>
<body>
    <form action="1b.php" method="post">
        Username: <input type="text" name="uname" id="uname">
        <input name="sub" type="submit" value="Submit">
    </form>
</body>
</html>