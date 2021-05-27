<!-- Design a PHP program to update the salary of ‘SALE’ department by 10% and 
display the number of employees who get benefit -->

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

    $sql = "SELECT id, salary FROM employee WHERE department = 'SALE'";
    $result = $conn->query($sql);
    $salary = array();
    
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $s = (int)$row["salary"];
            $id = $row["id"];
            $s += (0.1*$s);
            $upd = "UPDATE employee SET salary='$s' WHERE id='$id'";
            $conn->query($upd);
            array_push($salary, $s);
        }
        echo "<h1>Number of employees benefitted:".count($salary)."</h1>";
    } else {
        echo "No employees in SALE.";
    }
    $conn->close();
    ?>

</body>

</html>