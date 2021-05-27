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

    $id = (int)mysqli_real_escape_string($conn, $_POST['id']);
    $name = mysqli_real_escape_string($conn, $_POST['full-name']);
    $dob = mysqli_real_escape_string($conn, $_POST['dob']);
    $dept = mysqli_real_escape_string($conn, $_POST['dept']);
    $salary = (int)mysqli_real_escape_string($conn, $_POST['salary']);

    $idquery = "SELECT * FROM employee WHERE id = '$id'";
    $idres = $conn->query($idquery);

    if ($idres->num_rows > 0) {
        echo "Employee already exists.";
    } else {
        $sql = "INSERT INTO employee(id, name, dob, department, salary) VALUES('$id', '$name', '$dob', '$dept', '$salary')";
        $result = $conn->query($sql);

        if ($result) {
            echo "<h3 color:\"green\">Added into database successfully</h3>";
        } else {
            echo "<h3 color:\"red\">Error: " . $conn->error . "</h3>";
        }
    }
    $conn->close();
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 8A</title>
</head>

<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" id="form">
        <table>
            <tr>
                <td>Id</td>
                <td><input type="text" name="id" required></td>
            </tr>
            <tr>
                <td>Full Name</td>
                <td><input type="text" name="full-name" id="full-name" required></td>
            </tr>
            <tr>
                <td>Date of Birth</td>
                <td><input type="date" placeholder="mm/dd/yyyy" name="dob" id="dob" required></td>
            </tr>
            <tr>
                <td>Department</td>
                <td><input type="text" name="dept"></td>
            </tr>
            <tr>
                <td>Salary</td>
                <td><input type="text" name="salary"></td>
            </tr>
            <tr>
                <td></td>
                <td><input type="submit" name="sub" value="Go"></td>
            </tr>
        </table>
    </form>
</body>

</html>