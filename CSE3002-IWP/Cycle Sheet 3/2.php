<?php
if(isset($_POST['sub'])){
    $fn = $_POST['full-name'];
    $pwd = $_POST['pwd'];
    $gender = $_POST['gender'];
    $dob = $_POST['dob'];
    $edu = $_POST['edu'];
    $email = $_POST['email'];
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 Q2</title>
</head>

<body>
    <form id="q2">
        <table>
            <tr>
                <td>Full Name</td>
                <td><?php echo $fn;?></td>
            </tr>
            <tr>
                <td>Password</td>
                <td><?php echo $pwd;?></td>
            </tr>
            <tr>
                <td>Gender</td>
                <td><?php echo $gender;?></td>
            </tr>
            <tr>
                <td>Date of Birth</td>
                <td><?php echo $dob;?></td>
            </tr>
            <tr>
                <td>Education</td>
                <td><?php 
                foreach($edu as $value) {
                  echo "$value;";
                }
                ?></td>
            </tr>
            <tr>
                <td>Email</td>
                <td><?php echo $email;?></td>
            </tr>
            <tr>
                <td></td>
                <td><input type="submit" name="sub" id="register" value="Go"></td>
            </tr>
        </table>
    </form>
</body>

</html>

<?php
}
?>
