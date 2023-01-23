<?php
if($_SERVER["REQUEST_METHOD"]=="GET"){
    require_once "conexion.php";
    $nombre=$_GET['nombre'];
    $query="SELECT nombre,contra FROM usuarios WHERE nombre='".$nombre."'";
    $resultado=$mysql->query($query);
    if($mysql->affected_rows > 0){
        while($row=$resultado->fetch_assoc()){
            $array=$row;
        }
        echo json_encode($array);
    }
    else{
        $array= array("nombre"=>"n","contra"=>"0");
        echo json_encode($array);  
    }
    $resultado->close();
    $mysql->close();
}
?>