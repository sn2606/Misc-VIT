<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>19BCE0977 8C</title>
</head>

<body>
    <?php
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

    $sql = "SELECT department, COUNT(*) FROM employee GROUP BY department";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "dept: " . $row["department"] . " - Count: " . $row["COUNT(*)"] . "<br>";
        }
    } else {
        echo "No employees to display.";
    }
    $conn->close();
    ?>

</body>

</html>