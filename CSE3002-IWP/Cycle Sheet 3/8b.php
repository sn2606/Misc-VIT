<!-- Get value for ‘Dept’ from user and list those employee detail in HTML table format. 
Write the necessary HTML and PHP program. -->


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 8B</title>
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

        $dept = mysqli_real_escape_string($conn, $_POST['dept']);

        $sql = "SELECT * FROM employee WHERE department = '$dept'";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "id: " . $row["id"]. " - Name: " . $row["name"]. ", DOB: " . $row["dob"]. ", Salary: " . $row["salary"]."<br>";
            }
        } else {
            echo "No employees to display.";
        }
        $conn->close();
    } else {
    ?>
        <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" id="form">
            <table>
                <tr>
                    <td>Department</td>
                    <td><input type="text" name="dept"></td>
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