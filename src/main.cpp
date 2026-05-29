//Libraries
#include <Arduino.h>
#include <WiFiMulti.h>
#include <WebServer.h>

//Leds definitions
#define builtin LED_BUILTIN
#define Led1 GPIO_NUM_4
#define Led2 GPIO_NUM_5
#define Led3 GPIO_NUM_18

// Automatically selects and connects to the strongest configured Wi-Fi network
WiFiMulti Multi;

// HTTP server instance running on port 80
WebServer server(80);

//function to store the http page
void handle_root();

void setup() {
  //start serial communication
Serial.begin (115200);

//Leds pinModes/initial status
pinMode(builtin, OUTPUT);
digitalWrite(builtin, LOW);
pinMode(Led1, OUTPUT);
digitalWrite(Led1, LOW);
pinMode(Led2, OUTPUT);
digitalWrite(Led2, LOW);
pinMode(Led3, OUTPUT);
digitalWrite(Led3, LOW);

//wifi network credential list
Multi.addAP("ssid1", "password1");
Multi.addAP("ssid2", "password2");

//connecting to wifi loop
while (Multi.run() != WL_CONNECTED){
digitalWrite(builtin, LOW);
Serial.println("Não Conectado");
}
digitalWrite(builtin, HIGH);
Serial.println ("conectado");
Serial.println ("seu IP é : ");
Serial.println (WiFi.localIP());


//server routes
server.on("/", handle_root);
server.on("/Led1/ON", []{
  digitalWrite(Led1, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
});
server.on("/Led1/OFF", []{
  digitalWrite(Led1, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
});
server.on("/Led2/ON", []{
  digitalWrite(Led2, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
});
server.on("/Led2/OFF", []{
  digitalWrite(Led2, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
});
server.on("/Led3/ON", []{
  digitalWrite(Led3, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
});
server.on("/Led3/OFF", []{
  digitalWrite(Led3, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
});

// Initializes the web server and starts listening for client connections
server.begin();
}

void loop() {

  // Processes incoming HTTP requests from connected clients in loop
  server.handleClient();
}

void handle_root(){
  
  //HTML page
  String HTML = 
  "<h1>CONTROLADOR DE LED</h1>";
  if(digitalRead(Led1)==LOW){
    HTML += "<p>clique<a href=\"/Led1/ON\">aqui</a>para ligar o Led verde</p>";}
    else{
      HTML +="<p> clique<a href=/Led1/OFF>aqui</a>para desligar o Led verde</p>";}
  
  if(digitalRead(Led2)==LOW){
    HTML += 
  "<p> clique<a href=/Led2/ON>aqui</a>para ligar o led azul</p>";}
  else{
    HTML += "<p>clique<a href=/Led2/OFF>aqui</a>para desligar o led azul</p>";}

  if(digitalRead(Led3)==LOW){
    HTML +="<p>clique<a href=/Led3/ON>aqui</a>para ligar o led vermelho</p>";}
  else{
    HTML += "<p>clique<a href=/Led3/OFF>aqui</a>para desligar o led vermelho</p>";}

  server.send(200,"text/html", HTML);

}