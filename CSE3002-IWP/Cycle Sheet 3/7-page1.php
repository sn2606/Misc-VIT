<?php
if(isset($_POST['submit'])) {
    $uname = $_POST["username"];
    setcookie("username", $uname);
    echo "<h1>Username is $uname </h1>";
    echo "<a href=\"7-page2.php\"><input type=\"button\" value=\"Next page\"></a>";
}