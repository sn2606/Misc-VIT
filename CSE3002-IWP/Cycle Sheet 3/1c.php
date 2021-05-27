<?php
if(isset($_POST['sub'])){
    $col = $_POST['color'];
    $bg = "white";
    if($col === "r"){
        $bg = "red";
    }elseif($col === "g"){
        $bg = "green";
    }elseif($col === "b"){
        $bg = "blue";
    }elseif($col === "w"){
        $bg = "white";
    }elseif($col === "l"){
        $bg = "black";
    }elseif($col === "o"){
        $bg = "orange";
    }else{
        echo "<h3>Invalid choice</h3>";
    }

    echo '<body style="background-color:'.$bg.'">';
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 1C</title>
</head>
<body>
    <form action="1c.php" method="post">
        <p>r-red, g-green, b-blue, w-white, l-black, o-orange</p>
        Color initial from above (lowercase): <input type="text" name="color">
        <br>
        <input name="sub" type="submit" value="Submit">
    </form>
</body>
</html>