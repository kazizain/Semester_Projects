<?php
include "../conn.php";
include "../config.php";
session_start();
$username = $_SESSION['username'];
//include "patient.php";
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Get form data
    
    $name = $_POST['name'];
    $cnic = $_POST['cnic'];
    $address = $_POST['address'];
    $city = $_POST['city'];
    $pno = $_POST['pno'];
    $email = $_POST['email'];
    $acc_no = $_POST['acc_no'];
    $acc_type = $_POST['acc_type'];
    $balance = $_POST['balance'];
    $pin = $_POST['pin'];
    $userid = $_POST['userid'];

    // Prepare insert query
    $sql = "INSERT INTO user (user_id,name,cnic, address,city, phone_no, email)
     VALUES ('','$name', '$cnic', '$address','$city','$pno','$email')";

    // Execute query
    mysqli_query($conn, $sql);

    $sql2 = "INSERT INTO `account`(`account_id`, `account_no`, `account_type`, `balance`, `pin`, `user_id`)
     VALUES ('','$acc_no','$acc_type','$balance','$pin','$userid') ";
      mysqli_query($conn, $sql2);
    
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Create New Account</title>

        <!-- Favicons  use for icon-->
  <link href="../assets/bank.png" rel="icon">
  <link href="../assets/bank.png" rel="apple-touch-icon">


<!--------------------------------------CDNs---------------------------------------->

  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>













    <!-- Google Fonts -->
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,300i,400,400i,600,600i,700,700i|Roboto:300,300i,400,400i,500,500i,600,600i,700,700i|Poppins:300,300i,400,400i,500,500i,600,600i,700,700i" rel="stylesheet">

    <!-- Vendor CSS Files -->
    <link href="../assets/vendor/aos/aos.css" rel="stylesheet">
    <link href="../assets/vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">
    <link href="../assets/vendor/bootstrap-icons/bootstrap-icons.css" rel="stylesheet">
    <link href="../assets/vendor/boxicons/css/boxicons.min.css" rel="stylesheet">
    <link href="../assets/vendor/glightbox/css/glightbox.min.css" rel="stylesheet">
    <link href="../assets/vendor/swiper/swiper-bundle.min.css" rel="stylesheet">

    

</head>











    <!-----------------------css------------------------->
<style>
    nav {
  position: fixed;
  top: 0;
  width: 100%;
  background-color: lightgray;
  z-index: 1;
}




nav a {
  text-decoration: none;
  color: #333;
  font-size: 18px;
  font-weight: bold;
  text-transform: uppercase;
  transition: color 0.2s;
}

nav a:hover {
  color: blue;
}


nav.sticky {
  position: fixed;
  top: 0;
  background-color: #fff;
  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

body {
  background-image: url('../assets/divh.jpg');
  background-repeat: no-repeat;
  background-size: cover;
  position: relative;
}



body::before {
  content: "";
  background-image: url('../assets/divh.jpg');
  background-repeat: no-repeat;
  opacity: 0.5;
  position: absolute;
  background-size: cover;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
}


</style>
</head>
<body>


<!-----------navbar-------------->



<div class="container-fluid">





<div class="row">

<nav class="navbar navbar-expand-sm">
    <a class="navbar-brand" href="#"><img src="../assets/bank.png" alt="bank logo" style="height:30%"></a>
    <button class="navbar-toggler d-lg-none" type="button" data-bs-toggle="collapse" data-bs-target="#collapsibleNavId" aria-controls="collapsibleNavId"
        aria-expanded="false" aria-label="Toggle navigation"></button>
    
    <div class="collapse navbar-collapse" id="collapsibleNavId">
        <ul class="navbar-nav me-auto mt-2 mt-lg-0">
            <li class="nav-item">
                <a class="nav-link" href="dashboard.php" aria-current="page">Home </a>
            </li>
    

            <li class="nav-item">
                <a class="nav-link" href="create.php" aria-current="page">Add new Account</a>
            </li>

            <li class="nav-item">
                <a class="nav-link" href="feedback.php" aria-current="page">Feedback</a>
            </li>

        </ul>
        <form class="d-flex my-2 my-lg-0">
            <button class="btn btn-outline-success my-2 my-sm-0 mx-4"  id="log" data-toggle="modal" data-target="#login" >Account - <?php echo "$username"; ?></button>
        </form>

        
        
         <a href="../logout.php">   <button class="btn btn-outline-dark my-2 my-sm-0 mx-4" type="submit" id="logi">Log out</button> </a>
        
    </div>
</nav>


<div class="container mt-4">
  <div class="card w-100 text-center shadowBlue">
    <div class="card-header">
      New Account Forum
    </div>
    <div class="card-body bg-dark " >
      <table class="table" style="color:white;">
        <tbody>
          <tr>
            <form method="POST">
              <th>Name</th>
              <td><input type="text" name="name" class="form-control input-sm" required></td>
              <th>CNIC</th>
              <td><input type="number" name="cnic" class="form-control input-sm" required></td>
          </tr>
          <tr>
              <th>Account Number</th>
              <td><input type="" name="acc_no"  class="form-control input-sm" required></td>
              <th>Account Type</th>
              <td>
                <select class="form-control input-sm" name="acc_type" required>
                  <option value="current" selected>Current</option>
                  <option value="saving" selected>Saving</option>
                </select>
              </td>
          </tr>
          <tr>
              <th>City</th>
              <td><input type="text" name="city" class="form-control input-sm" required></td>
              <th>Address</th>
              <td><input type="text" name="address" class="form-control input-sm" required></td>
          </tr>
          <tr>
              <th>Email</th>
              <td><input type="email" name="email" class="form-control input-sm" required></td>
              <th>Password</th>
              <td><input type="password" name="pin" class="form-control input-sm" required></td>
          </tr>
          <tr>
              <th>Deposit</th>
              <td><input type="number" name="balance" min="500" class="form-control input-sm" required></td>
              <th>Contact Number</th>
              <td><input type="number" name="pno"  class="form-control input-sm" required></td>
          </tr>
          
          <tr>
              <!-- <th>Deposit</th> -->
              <!-- <td><input type="number" name="balance" min="500" class="form-control input-sm" required></td> -->
              <th>Userid</th>
              <td><input type="number" name="userid"  class="form-control input-sm" required></td>
          </tr>

          <tr>
              <td colspan="4">
                <button type="submit" name="saveAccount" class="btn btn-primary btn-sm">Save Account</button>
                <button type="reset" class="btn btn-secondary btn-sm">Reset</button>
              </td>
            </form> <!-- close the form tag here -->
          </tr>
        </tbody>
      </table>
    

  </div>
  <div class="card-footer text-muted">
    <?php echo BANKNAME; ?>
  </div>
</div>





















  </div>

</body>
</html>