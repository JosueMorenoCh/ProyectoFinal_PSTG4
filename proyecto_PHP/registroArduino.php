<?php
if($_SERVER["REQUEST_METHOD"]=="GET"){
    require_once "conexion.php";
    $idU=$_GET['idU'];
    $seleccion=$_GET["seleccion"];
    $query="SELECT dias,horas FROM rutinas WHERE nombre=$idU and seleccion=$seleccion";
    $resultado=$mysql->query($query);
    if($mysql->affected_rows > 0){
        while($row=$resultado->fetch_assoc()){
            $array=$row;
        }
        echo json_encode($array);
    }
    else{
        echo "Error al buscar en la base de datos" ;
    }
    $resultado->close();
    $mysql->close();
}
?>