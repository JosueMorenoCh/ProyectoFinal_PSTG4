#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <TimeLib.h>
// credenciales de acceso a la red de internet 
const char* ssid="";
const char* password="";
int LED=13;// led indicador de encendido
int buzzer=3;//buzzer para alarma
Servo myservo;// servomotor para distribucion

void setup() {
  // inicializacion de led y servomotor
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  myservo.attach(6);
  WiFi.begin(ssid,password);// se accede a la red
  setTime(hora,minuto,segundo,dia,mes,año);// se colocar hora/minuto/segundos/dia/mes/año en que se inicia el programa
  // severifica conexion a la red
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Conectando...");
  }
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    http.begin("http://192.168.100.8:8080/proyecto/registroArduino.php?idU=14&&seleccion=1");
    int.httpCode = http.GET();
    if(httpCode>0){
      String horasSelecionadas = http.getString("horas");
      //obtencion de las posibles 4 dosis y horas
      String horas[4];
      int indexH;
      if(horasSeleccionadas.indexOf(",")>0){
        //12:00,13:00,14:00
        String primeraP[] = horasSelecionadas.substring(0,horasSeleccionadas.indexOf(","));
        horas[0] = primeraP[0];
        indexH++;
        if(primeraP[1].indexOf(",")>0){
          String segungdaP[] = primeraP[1].substring(0,horasSeleccionadas.indexOf(","));
          horas[1] = segundaP[0];
          indexH++;
          if(segundaP[1].indexOf(",")>0){
            String terceraP[] = segundaP[1].substring(0,horasSeleccionadas.indexOf(","));
            horas[2] = terceraP[0];
            indexH++;
            if(terceraP[1].indexOf(",")>0){
             String cuartaP[] = terceraP[1].substring(0,horasSeleccionadas.indexOf(","));
             horas[3]= cuartaP[0];
             indexH++;
            }
          }
        }
      }
      //finalmente se genera el arreglo completo
      horas = horas.substring(0,indexH);
      // se obtienen los dias
      String diasSeleccionados=http.getString("dias");
      //obtencion de los 7 posibles dias
      String dias[7];
      int indexD;
      if(diasSeleccionados.indexOf(",")>0){
        String primeraP[] = diasSelecionados.substring(0,diasSeleccionados.indexOf(","));
        dias[0] = primeraP[0];
        indexD++;
        if(primeraP[1].indexOf(",")>0){
          String segungdaP[] = primeraP[1].substring(0,horasSeleccionadas.indexOf(","));
          dias[1] = segundaP[0];
          indexD++;
          if(segundaP[1].indexOf(",")>0){
            String terceraP[] = segundaP[1].substring(0,horasSeleccionadas.indexOf(","));
            dias[2] = terceraP[0];
            indexD++;
            if(terceraP[1].indexOf(",")>0){
             String cuartaP[] = terceraP[1].substring(0,horasSeleccionadas.indexOf(","));
             dias[3]= cuartaP[0];
             indexD++;
             if(cuartaP[1].indexOf(",")>0){
                String quintaP[] = cuartaP[1].substring(0,horasSeleccionadas.indexOf(","));
                dias[4]= quintaP[0];
                indexD++;
                if(quintaP[1].indexOf(",")>0){
                    String sextaP[] = quintaP[1].substring(0,horasSeleccionadas.indexOf(","));
                    dias[5]= sextaP[0];
                    indexD++;
                    if(sextaP[1].indexOf(",")>0){
                      String septimaP[] = sextaP[1].substring(0,horasSeleccionadas.indexOf(","));
                      dias[5]= septimaP[0];
                      indexD++;
                }
                }
              }
            }
          }  
       }
       // arreglo final de dias
        dias = dias.substring(0,indexD);
        for(int i=0;i<indexD;i++){
          if(dias[i]==weekday()){
            for(int j=0;i<indexH;i++){
              String horai = horas[i].substring(horas[i].indexOf(":"))[0];
              String minutoi = horas[i].substring(horas[i].indexOf(":"))[1]; 
              if(hour()== horai and minute()==minutoi ){
                myservo.write(40);
                analogWrite(buzzer,100);
                delay(3000);
                myservo.write(0);
                analogWrite(buzzer,0);
                delay(3000);
              }
            }
          }
        }
    http.end();
  }
  delay(3000);

}
