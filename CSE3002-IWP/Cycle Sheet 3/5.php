<?php

if (($_FILES['file']['name'] != "") and ($_FILES['file']['type'] == "application/pdf") and ($_FILES['file']['size'] <= 5242880)) {
    $target_dir = "DATA/";
    $file = $_FILES['file']['name'];
    $path = pathinfo($file);
    $filename = $path['filename'];
    $ext = $path['extension'];
    $temp_name = $_FILES['file']['tmp_name'];
    $path_filename_ext = $target_dir . $filename . "." . $ext;

    // Check if file already exists
    if (file_exists($path_filename_ext)) {
        echo "File already exists.";
    } else {
        move_uploaded_file($temp_name, $path_filename_ext);
        echo "File Uploaded Successfully.";
    }
} else {
    echo "Please input a valid file.";
}
