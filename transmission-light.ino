/*
 * Transmission light project
 * 
 * Code by Liam Burnand
 * 
 * Designed for Adruino Uno
 * 
 * To control this you need to have be able to access this from your local network
 * You send commands to it in the format of <IP address>/?[request]
 * 
 * Turn on rehearsal light - <IP address>/?rehearsal_on
 * Turn on transmission light - <IP address>/?transmission_on
 * Turn on both rehearsal and transmission light - <IP address>/?rehearsal_transmission_on
 * Turn off both rehearsal  lights - <IP address>/?rehearsal_transmission_off
 */

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Sets the MAC address of the shield
byte ip[] = { 10, 104, 19, 4 };                       // Sets the IP address of the shield
byte gateway[] = { 10, 104, 19, 1 };                  // Sets the gateway of the network
byte subnet[] = { 255, 255, 255, 0 };                 // Sets the subnet of the network

EthernetServer server(80);  // Starts the web server on port 80

String readString;

void setup() {
  /*
   * Initial setup of the pins
   * The pins are inverted so when the pin is high then the relay is off and visa versa
   * Pin 4 is connected to the transmission light and pin 5 to the rehearsal light
   */
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  server.begin(); // Begins the web server

  Serial.begin(9600);
}

/*
 * Turns on the rehearsal light and turns off the transmission light
 */
void rehearsalOn(EthernetClient client) {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  Serial.println("REHEARSAL ON");
  client.println("HTTP/1.1 204 No Content");
}

/*
 * Turns on the transmission light and turns off the rehearsal light
 */
void transmissionOn(EthernetClient client) {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  Serial.println("TRANSMISSION ON");
  client.println("HTTP/1.1 204 No Content");
}

/*
 * Turns on the rehearsal light and the transmission light
 */
void rehearsalTransmissionOn(EthernetClient client) {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.println("REHEARSAL TRANSMISSION ON");
  client.println("HTTP/1.1 204 No Content");
}

/*
 * Turns off the rehearsal light and the transmission light
 */
void rehearsalTransmissionOff(EthernetClient client) {
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("REHEARSAL TRANSMISSION OFF");
  client.println("HTTP/1.1 204 No Content");
}

void loop() {
  EthernetClient client = server.available(); // Allows for a GET request to be recieved
  
  if (client) // Checks if there is a client connected to the web server
      if (client.available()) {
        client.setConnectionTimeout(100);
        char c = client.read(); // Reads the GET request
        
        if (readString.length() < 100) readString += c;
        
        if (c == '\n') {
          Serial.println(readString); // Prints the full GET request to the serial monitor

          delay(1);

          // This is the logic to decide which state to be in due to the request
          if (readString.indexOf("/?rehearsal_on") > 0) rehearsalOn(client);
          else if (readString.indexOf("/?transmission_on") > 0) transmissionOn(client);
          else if (readString.indexOf("/?rehearsal_transmission_on") > 0) rehearsalTransmissionOn(client);
          else if (readString.indexOf("/?rehearsal_transmission_off") > 0) rehearsalTransmissionOff(client);
          else {  // This is in case there is a bad request then the sender knows that they sent a bad request, the default is a 204
            client.println("HTTP/1.1 400 Bad Request");
            Serial.println("BAD REQUEST");
          }

          client.stop();
          
          readString = "";
        }
      }
}
