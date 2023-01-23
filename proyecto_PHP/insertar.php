<?php
if($_SERVER["REQUEST_METHOD"]=="POST"){
    require_once 'conexion.php';
    $nombre=$_POST["nombre"];
    $correo=$_POST["correo"];
    $contra=$_POST["contra"];
    $query="INSERT INTO usuarios(nombre,correo,contra) VALUES('$nombre','$correo','$contra')";

    $resultado =$mysql->query($query);
    if($resultado==true){
        echo "el usuario se inserto de forma exitosa";
    }
    else{
        echo "Error al insertar  usuario";
        echo $resultado;
    }
}
?>