<?php
session_start();
session_unset();
if (isset($_SESSION)) {
    session_destroy();
}
include "index.php";
echo "Successfully logged out";
?>
