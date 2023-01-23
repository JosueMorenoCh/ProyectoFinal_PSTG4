<?php
if($_SERVER["REQUEST_METHOD"]=="POST"){
    require_once 'conexion.php';
    $nombre=$_POST["nombre"];
    $medicamento=$_POST["medicamento"];
    $stock=$_POST["stock"];
    $dias=$_POST["dias"];
    $horas=$_POST["horas"];
    $dosis=$_POST["dosis"];
    $query="INSERT INTO rutinas(idU,medicamento,stock,dias,horas,dosis) VALUES((SELECT id FROM usuarios WHERE nombre='".$nombre."'  ),'$medicamento','$stock','$dias','$horas','$dosis')";

    $resultado =$mysql->query($query);
    if($resultado==true){
        echo "rutina insertada con exito ";
    }
    else{
        echo "Error al insertar  rutina";
        echo $resultado;
    }
}
?>