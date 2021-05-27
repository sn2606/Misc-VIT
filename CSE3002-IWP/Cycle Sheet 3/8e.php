<!-- Get input for ‘Id’ and remove that employee detail from the table. 
Design the suitable HTML and PHP program to do this. -->


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 8E</title>
</head>

<body>
    <?php
    if (isset($_POST['sub'])) {
        global $conn;
        $dbServer = "localhost:3308";
        $username = "root";
        $password = "";
        $dbName = "iwp";
        $conn = new mysqli($dbServer, $username, $password, $dbName);

        if ($conn->ping()) {
            // printf ("Our connection is ok!\n");
        } else {
            printf("Error: %s\n", $conn->error);
        }

        if ($conn->connect_error) {
            die("Error: " . $conn->connect_error);
        }

        $id = mysqli_real_escape_string($conn, $_POST['id']);

        $sql = "DELETE FROM employee WHERE id = '$id'";

        if ($conn->query($sql)) {
            echo "Employee with id = $id record deleted.";
        } else {
            echo "No employees to delete.";
        }
        $conn->close();
    } else {
    ?>
        <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" id="form">
            <table>
                <tr>
                    <td>ID</td>
                    <td><input type="text" name="id"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="submit" name="sub" value="Go"></td>
                </tr>
            </table>
        </form>

    <?php
    }
    ?>

</body>

</html>