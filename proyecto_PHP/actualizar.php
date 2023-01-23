<?php
if($_SERVER["REQUEST_METHOD"]=="PUT"){
    require_once 'conexion.php';
    $seleccion=$_PUT["seleccion"];
    $idR=$_PUT["idR"];
    $query="UPDATE rutinas SET seleccion=$seleccion WHERE idR=$idR";

    $resultado =$mysql->query($query);
    if($resultado==true){
        echo "actualización completa";
    }
    else{
        echo "Error al actualizar rutina";
        echo $resultado;
    }
}
?>