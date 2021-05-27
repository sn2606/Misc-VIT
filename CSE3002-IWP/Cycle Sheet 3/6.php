<?php 
if (!isset($_COOKIE['visits'])) { 
  echo "This is the first time you have visited this page."; 
  $cookie = 1;
  setcookie("visits", $cookie);
}else{
  $cookie = ++$_COOKIE['visits'];
  setcookie("visits", $cookie); 
  echo "You have visited this page ".$_COOKIE['visits']." times."; 
  }
