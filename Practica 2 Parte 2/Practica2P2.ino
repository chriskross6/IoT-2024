//Paso 3 Bateria externa
/*
#include <WiFi.h>
WiFiServer server(80);
WiFiClient client;
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
void setup()
{
Serial.begin(9600);
WiFi.disconnect();
delay(3000);
Serial.println("Iniciando");
WiFi.begin("Chris's Galaxy S22 Ultra","moka5500");
while ((!(WiFi.status() == WL_CONNECTED))){
Serial.print("......");
delay(300);
}
Serial.println("Conexion establecida con el SSDI!");
Serial.println((WiFi.localIP()));
server.begin();
}
void loop()
{
client = server.available();
if (!client) { return; }
while(!client.available()){ delay(1); }
client.flush();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<title> ""MiESP32"" </title>");
client.println("</head>");
client.println("<body>");
client.println("<h1 style=""color:#3366ff"">");
client.println("");
client.println("</h1>");
client.println("<span style=""color:#33cc00;font-size:14px"">");
client.println("Bienvenidos a mi pagina web");
client.println("</span>");
client.println("<br>");
client.println("<span style=""color:#cc6600;font-size:14px"">");
client.println("Esta pagina web ha estado activa por");
client.println("</span>");
client.println("<span style=""color:#009900;font-size:20px"">");
client.println((millis()/1000));
client.println("</span>");
client.println("<span style=""color:#cc6600;font-size:14px"">");
client.println("segundos");
client.println("</span>");
client.println("<br>");
client.println("<span style=""color:#ffcc33;font-size:14px"">");
client.println("La temperatura interna del ES32 es de:");
client.println("</span>");
client.println("<span style=""color:#000000;font-size:14px"">");
client.println(((temprature_sens_read() - 32 ) / 1.8));
client.println("</span>");
client.println("<span style=""color:#ffcc33;font-size:14px"">");
client.println("grados");
client.println("</span>");
client.println("</body>");
client.println("</html>");
delay(1);
}

*/

//Paso 5 Prender y apagar un led externo desde el servidor web ESP32 

#include <WiFi.h>
#include <WiFiClient.h>
const char* ssid = "totalplay123";
const char* password = "clasificado1024";
WiFiServer server(80);
//Usar el pin 15 GPIO
#define LED 15
String estado = "";
void setup() {
Serial.begin(115200);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
// Conectando a WiFi
WiFi.begin(ssid, password);
// Checa si esta conectado
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi conectado");
Serial.print("La dirección IP es: ");
Serial.println(WiFi.localIP()); //Muestra IP
// Inicio del Servidor web.
server.begin();
Serial.println("Servidor web iniciado.");
}
void loop() {
// Consulta si se ha conectado algún cliente.
WiFiClient client = server.available();
if (!client) {
return;
}
Serial.print("Nuevo cliente: ");
Serial.println(client.remoteIP());
// Espera hasta que el cliente envíe datos.
while(!client.available()){ delay(1); }
/////////////////////////////////////////////////////
 // Lee la información enviada por el cliente.
String req = client.readStringUntil('\r');
Serial.println(req);
// Realiza la petición del cliente.
if (req.indexOf("on2") != -1) {digitalWrite(LED, HIGH);
estado = "Encendido";}
if (req.indexOf("off2") != -1){digitalWrite(LED, LOW);
estado = "Apagado";}
//////////////////////////////////////////////
// Página WEB. ////////////////////////////
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // Importante.
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head><meta charset=utf-8></head>");
client.println("<body><center><font face='Arial'>");
client.println("<h1>Servidor web con ESP32.</h1>");
client.println("<h1>Chris Larios</h1>");
client.println("<h2><font color='#009900'>Webserver 1.0</font></h2>");client.println("<h3>Práctica boton</h3>");
client.println("<br><br>");
client.println("<a href='on2'><button>Enciende LED</button></a>");client.println("<a href='off2'><button>Apaga LED</button></a>");client.println("<br><br>");
client.println(estado);
client.println("</font></center></body></html>");
Serial.print("Cliente desconectado: ");
Serial.println(client.remoteIP());
client.flush();
client.stop();
}
