
<?php
include "config.php";
include "login.php";
include "loginad.php";
include "conn.php";

if($_SERVER['REQUEST_METHOD'] === 'POST')
{
  $name = isset($_POST['name']) ? $_POST['name'] : '';
  $email = isset($_POST['email']) ? $_POST['email'] : '';
  $subject = isset($_POST['subject']) ? $_POST['subject'] : '';
  $message = isset($_POST['message']) ? $_POST['message'] : '';

  // Insert data into feedback table
  $sql = "INSERT INTO feedback (email, subject, name, message) VALUES ('$email', '$subject', '$name', '$message')";
  if ($conn->query($sql) === TRUE) {
    echo "New record added successfully";
  } else {
    echo "Error: " . $sql . "<br>" . $conn->error;
  }

  // Close database connection
  $conn->close();
}




?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title><?php echo BANKNAME ?></title>

        <!-- Favicons  use for icon-->
  <link href="assets/bank.png" rel="icon">
  <link href="assets/bank.png" rel="apple-touch-icon">

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.4/jquery.min.js"></script>
<!--------------------------------------CDNs---------------------------------------->

  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script>
  













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



.background-image {
  position: relative;
  background-size: cover;
}

.background-image::before {
  content: "";
  background-image: url('assets/divh.jpg');
  opacity: 0.5;
  position: absolute;
  background-size: cover;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
}

.img-round {
            height: 150px;
            width: 150px;
            border: 4px solid white;
            border-radius: 100%;
        }











</style>
</head>
<body>


<!-----------navbar-------------->



<div class="container-fluid">





<div class="row">

<nav class="navbar navbar-expand-sm">
    <a class="navbar-brand" href="#"><img src="assets/bank.png" alt="bank logo" style="height:30%"></a>
    <button class="navbar-toggler d-lg-none" type="button" data-bs-toggle="collapse" data-bs-target="#collapsibleNavId" aria-controls="collapsibleNavId"
        aria-expanded="false" aria-label="Toggle navigation"></button>
    
    <div class="collapse navbar-collapse" id="collapsibleNavId">
        <ul class="navbar-nav me-auto mt-2 mt-lg-0">
            <li class="nav-item">
                <a class="nav-link" href="#div1" aria-current="page">Home </a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="#div2" aria-current="page">About Us</a>
            </li>
    

            <li class="nav-item">
                <a class="nav-link" href="#div3" aria-current="page">Contact Us</a>
            </li>

        </ul>
        
            <button class="btn btn-outline-success my-2 my-sm-0 mx-4"  id="log" data-toggle="modal" data-target="#login" >User</button>
        

        
        
            <button class="btn btn-outline-warning my-2 my-sm-0 mx-4" type="submit" id="logie" data-toggle="modal" data-target="#login">Admin</button>
        
    </div>
</nav>



  </div>
<div>
    <div data-bs-spy="scroll" data-bs-target="#nav-example" data-bs-smooth-scroll="true" tabindex="0">

        <div id="div1"   class="background-image" >
      
        <div class="container" >

        <div class="row">

        <div class="col-md-7">

        <h1 style="margin-top:150px;">Welcome to,<h1>
        <h2>SwiftDigi Online Banking Portal</h2>
        <a href="#" id="c"><h5>Details</h5></a>
        <p id="details"> 
      
        SwiftDigi is a helpfull online banking portal,<br>
        which provides all functionality online Acessesable<br>
        Online banking allows you to conduct financial transactions<br>
        via the Internet.<br>
        Online banking is also known as Internet banking or web banking.<br>
        Online banking offers customers,<br>
         almost every service traditionally available,<br>
        through a local branch including deposits, transfers,<br>
        and online bill payments.

        </p> <!---------------------------------------------display or hide content using jQuery------------------------------->

        </div>


        <div class="col-md-5">




<!-- The Modal -->
<div id="login" class="modal ">

  <!-- Modal content -->
  <div class="modal-content bg-dark" style="width:450px;margin-left:auto;margin-right:auto;margin-top:150px;color:white;">
    <div class="modal-header">
      <h2 style="margin-left:auto;margin-right:auto;">SwiftDigi</h2>
      <span class="close">&times;</span>

    </div>
    <div class="modal-body">
    <form  method="post" >
             
                    Account No:
                    <input type="text" class="form-control" name="account" id="account"
                        placeholder=" Enter Account Number" required onkeyup="username()">
                    <br>
                    Pin:
                    <input type="password" class="form-control" name="pin" id="pin" placeholder="Enter Pin" required
                        onkeyup="pin()">
                    <br>
                    <input type="checkbox" onclick="fun()"> Show Pin
                    <br>
                    <br>
    </div>
    <div class="modal-footer">
    <input type="submit" class="btn btn-success" value="Login">

</form>

  </div>
  </div>

</div>




<!--------------------------------Model for admin----------------------------------->
<!-- The Modal -->
<div id="loga" class="modal ">

  <!-- Modal content -->
  <div class="modal-content bg-dark" style="width:450px;margin-left:auto;margin-right:auto;margin-top:150px;color:white;">
    <div class="modal-header">
      <h2 style="margin-left:auto;margin-right:auto;">SwiftDigi Admin</h2>
      <span class="close">&times;</span>

    </div>
    <div class="modal-body">
    <form  method="post" >
                 
   

                    username:
                    <input type="text" class="form-control" name="username" id="username"
                        placeholder=" Enter Account Number" required>
                    <br>
                    password:
                    <input type="password" class="form-control" name="password" id="pin" placeholder="Enter password" required
                        onkeyup="pin()">
                    <br>
                    <input type="checkbox" onclick="fun()"> Show Pin
                    <br>
                    <br>
    </div>
    <div class="modal-footer">
    <input type="submit" class="btn btn-success" value="Login">

</form>

  </div>
  </div>

</div>













        </div>

        </div>
        
        </div>


       </div>

       <!----------------------------------------for about tab--------------------------------->

        <div id="div2"  style="height:80vh;">
      

        <section id="services" class="services section-bg">

        <div class="container" data-aos="fade-up">

        <div class="row">

        <div class="col">







        <div class="section-title">
            <h2 style="padding-top:70px;">About Team</h2>
            <p>Teamwork is the ability to work together toward a common vision.</p>
        </div>

        <div class="row gy-4">
            <div class="col-lg-4 col-md-6 d-flex align-items-stretch" data-aos="zoom-in" data-aos-delay="100">
                <div class="icon-box iconbox-green">
                    <div class="icon" style="width: 160px; height: 160px;">
                        <img src="assets/about1.jpeg" class="img-round" alt="ali">
                    </div>
                    <h4><a href="">Ali kahfulwara</a></h4>
                    <p class="mt-1"> <strong>(CEO)</strong></p>
                    <p class="mt-3">The Man Who Has Power of Imagination, He Has a Wings</p>

                </div>
            </div>

            <div class="col-lg-4 col-md-6 d-flex align-items-stretch" data-aos="zoom-in" data-aos-delay="200">
                <div class="icon-box iconbox-blue ">
                    <div class="icon" style="width: 160px; height: 160px;">
                        <img src="assets/about2.jpeg" class="img-round" alt="Hussain Tahir">
                    </div>
                    <h4><a href="assets/about2.jpg">Hussain Tahir</a></h4>
                    <p class="mt-1"> <strong>(Accountent)</strong></p>
                    <p class="mt-3">Everything should be made as simple as possible, but not simpler.</p>
                </div>
            </div>

            <div class="col-lg-4 col-md-6 d-flex align-items-stretch" data-aos="zoom-in" data-aos-delay="300">
                <div class="icon-box iconbox-pink">
                    <div class="icon" style="width: 160px; height: 160px;">
                        <img src="assets/about3.jpg" class="img-round" alt="Qazi Zain">
                    </div>
                    <h4><a href="">Qazi Zain</a></h4>
                    <p class="mt-1"> <strong>(Manager)</strong></p>
                    <p class="mt-3">Beauty in things exists in the mind which contemplates them.</p>
                </div>
            </div>

            <div class="col-lg-4 col-md-6 d-flex align-items-stretch" data-aos="zoom-in" data-aos-delay="100">

            </div>

            </div>

        </div>

    </div>
</section>











        </div>
      </div>








      


</div>

      </div>

    </div>
       
  </div>

  <!----------------------------------------for contact us tab--------------------------------->
      
  <footer>
      
      
      <div id="div3" class="bg-light" style="height:100vh">

      <div class="container">

      <div class="row">

<div class="col-xxl-12">
<h1 style="margin-top:50px;">Contact us,<h1>
</div>
</div>
      <div class="section-title">
          
          <p>For Any query related to bank or account please contact us. We are trying to solve your all problems</p>
        </div>

        <div class="row">
          <div class="col-lg-6">
            <div class="info-box mb-4">
              <i class="bx bx-map"></i>
              <h3>Our Address</h3>
              <p><?php echo ADDRESS ?></p>
            </div>
          </div>

          <div class="col-lg-3 col-md-6">
            <div class="info-box  mb-4">
              <i class="bx bx-envelope"></i>
              <h3>Email Us</h3>
              <p><?php echo EMAIL ?></p>
            </div>
          </div>

          <div class="col-lg-3 col-md-6">
            <div class="info-box  mb-4">
              <i class="bx bx-phone-call"></i>
              <h3>Call Us</h3>
              <p><?php echo MOBILENO ?></p>
            </div>
          </div>

        </div>

        <div class="row">

          <div class="col-lg-6 ">
            <iframe class="mb-4 mb-lg-0" src="<?php echo LOCATION_CORDINATE ?>" frameborder="0" style="border:0; width: 100%; height: 384px;" allowfullscreen></iframe>
          </div>

          <div class="col-lg-6">
            <form  method="POST">
              <div class="row">
                <div class="col-md-6 form-group">
                  <input type="text" name="name" class="form-control" id="name" placeholder="Your Name" required>
                </div>
                <div class="col-md-6 form-group mt-3 mt-md-0">
                  <input type="email" class="form-control" name="email" id="email" placeholder="Your Email" required>
                </div>
              </div>
              <div class="form-group mt-3">
                <input type="text" class="form-control" name="subject" id="subject" placeholder="Subject" required>
              </div>
              <div class="form-group mt-3">
                <textarea class="form-control" id="message" name="message" rows="5" placeholder="Message" required></textarea>
              </div>
              <div hidden id="status"></div>
              <div hidden id="error-message" class="alert alert-danger mt-3"></div>
              <div hidden id="success-message" class="alert alert-success mt-3"></div>
              <div class="text-center"><button class="btn-custo mt-3" id="submit" name="submit">Send Message <i class='bx bxs-send'></i></button></div>
            </form>
          </div>

        </div>

      </div>
    </section><!-- End Contact Section -->

<marquee style="background-color: black; color:white;">Address: Gulshan | Phone : 03020033347 | Email: kazizain94@gmail.com</marquee>
</div>
</div>
</footer>

<!---------------------java script--------------------->

<!--------------------------Event Listner for nav scroll--------------->
<script>
window.addEventListener("scroll", function() {
  const nav = document.querySelector("nav");
  if (window.pageYOffset > nav.offsetTop) {
    nav.classList.add("sticky");
  } else {
    nav.classList.remove("sticky");
  }
});

$(document).ready(function(){
  $("#c").click(function(){
    $("#details").toggle();
  });
});

// script for display modal

// Get the modal for user login
var modal = document.getElementById("login");

// Get the button that opens the modal
var btn = document.getElementById("log");

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal 
btn.onclick = function() {
  modal.style.display = "block";
}

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
  modal.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}

// function to show pin plus regex expression for validation.
function fun() {
  let x = document.getElementById("pin");
  if (x.type == "password") {
    x.type = "text";
  }
  else {
    x.type = "password";
  }
}

function username() {
  var a = document.getElementById('account').value;
  var b = /^[A-Z]{2}[0-9]{2}[A-Z0-9]{1,30}$/;
  var c = document.getElementById('account');
  if (b.test(a)) {
    alert("True");
    c.style.border = "green 2px solid";
  }
  else {
    c.style.border = "red 2px solid";
  }
}

function pin() {
  var a = document.getElementById('pin').value;
  var b = /^[1-9]{1}[0-9]{2}\\s{0, 1}[0-9]{3}$/;
  var c = document.getElementById('inp');
  if (b.test(a)) {
    alert("True");
    c.style.border = "green 2px solid";
  }
  else {
    c.style.border = "red 2px solid";
  }
}

// model for admin login form
var modalAdmin = document.getElementById("loga");

// Get the button that opens the modal
var btnAdmin = document.getElementById("logie");

// Get the <span> element that closes the modal
var spanAdmin = document.getElementsByClassName("close")[1];

// When the user clicks the button, open the modal 
btnAdmin.onclick = function() {
  modalAdmin.style.display = "block";
}

// When the user clicks on <span> (x), close the modal
spanAdmin.onclick = function() {
  modalAdmin.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
  if (event.target == modalAdmin) {
    modalAdmin.style.display = "none";
  }
}
</script>









</body>
</html>












