<?php
$mysql=new mysqli("localhost","root","josue","proyectopst");
if($mysql->connect_error){
    die("error de conexion");
}
else{
    //echo "Conexion exitosa";
}
?>