#include <ESP8266WiFi.h>

WiFiServer server(80);
String  i;
void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);  // GPIO pin16=D0 of NodeMCU 12E or in place of '16' you can write'D0' directly || -->Connected to motordriver
  pinMode(5, OUTPUT);  // GPIO pin5=D1 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver
  pinMode(4, OUTPUT);  // GPIO pin4=D2 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver
  pinMode(0, OUTPUT);  // GPIO pin0=D3 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver
  // second motor driver
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT); 
  pinMode(2, OUTPUT);
  
WiFi.disconnect();

  delay(300);
  Serial.begin(9600);
  delay(3000);
  Serial.println("Connecting to WIFI");
  WiFi.begin("NET_NHI_MILEGA", "baapbaaphotaha");
  while ((!(WiFi.status( ) == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");

  } Serial.println("I am Connected");
  Serial.println("My Local IP is : ");
  Serial.print((WiFi.localIP()));
  server.begin();

}



void loop() {
  // put your main code here, to run repeatedly:


  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  i = (client.readStringUntil('\r'));
  i.remove(0, 5);
  i.remove(i.length() - 9, 9);
  Serial.print(i);
  if (i == "FORWARD") {
    
    digitalWrite(16, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(0, LOW);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("forward");
    client.println("</html>");
    //client.stop();
    Serial.println("on");
    delay(1);

  }
  if (i == "REVERSE") {
    digitalWrite(16, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(0, HIGH);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("reverse");
    client.println("</html>");
    //client.stop();
    delay(1);

  }
  if (i == "RIGHT") {
    digitalWrite(16, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(0, LOW);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("right");
    client.println("</html>");
    //client.stop();
    delay(1);

  }
  if (i == "LEFT") {
    digitalWrite(16, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); 
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("left");
    client.println("</html>");
    //client.stop();
    delay(1);

  }
  if (i == "STOP1" || i == "STOP2" || i == "STOP" ) {
    digitalWrite(16, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("stop");
    client.println("</html>");
    //client.stop();
    delay(1);

  }

  if (i == "OPEN") {
    Serial.println("ACTIVE");
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("open");
    client.println("</html>");
   // client.stop();
    delay(1);

  }
  if (i == "CLOSE") {
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("close");
    client.println("</html>");
    //client.stop();
    delay(1);

  }
  if (i == "UP") {

    digitalWrite(10, HIGH);
    digitalWrite(2, LOW);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("up");
    client.println("</html>");
    //client.stop();
    delay(1);

  }

  if (i == "DOWN") {

    digitalWrite(10, LOW);
    digitalWrite(2, HIGH);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("down");
    client.println("</html>");
    //client.stop();
    delay(1); 

  }
}
