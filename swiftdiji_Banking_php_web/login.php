
<?php
include "conn.php";
// Check if session is not already started
if(session_status() !== PHP_SESSION_ACTIVE) {
  session_start();
}
@$_SESSION['account']=$_POST['account'];

// Get the username and password from a form
if($_SERVER["REQUEST_METHOD"]=="POST")
{
@$account = $_POST['account'];
@$pass = $_POST['pin'];

// Query the database to check if the username and password are correct
$sql = "SELECT * FROM account WHERE account_no='$account' AND pin='$pass'";
$result = $conn->query($sql);

 // Check if the query was successful
 if ($result === false) {
  echo "error";
} 

// Check if the query returned any rows
if ($result->num_rows == 1) {
  // login successful, set session variables
  $_SESSION['loggedin'] = true;
  $_SESSION['account'] = $account;
  
  // redirect to dashboard
  header("location: user/dashboard.php");
  exit;
}
else {
  // login failed
  echo "<br><br>Incorrect username or password.";
}
}

$conn->close();

?>
