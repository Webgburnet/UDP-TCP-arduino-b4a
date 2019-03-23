/* 
* PROJET DOMOTIQUE STI2D SIN
* 
* Arduino Uno
* 
* A0: NC
* A1: NC
* A2: NC
* A3: NC
* A4: NC
* A5: NC
* 
* pin0 : NC
* pin1 : NC
* pin2 : NC
* pin3 : NC
* 
* pin4 : NC
* pin5 : NC
* pin6 : NC
* pin7 : NC
* pin8 : NC
* 
* pin9 : NC
* pin10 : NC
* pin11 : NC
* pin12 : NC
* pin13 : NC 
* 
* I2C : NC
* I2C : NC
* 
* Shield Wifi
* 
*/

#include <WiFi.h>
#include <SPI.h>

//Shield Ethernet sans Aoe Numero 2
int status = WL_IDLE_STATUS;
char ssid[] = "MarcusEtire";         // Nom du réseau wifi
char pass[] = "5D9D659735CE67DD367942A137";       // votre mot de passe réseau wifi(utilisez pour WPA ou comme clé pour WEP)
int keyIndex = 0;                 // votre numéro d'index de clé de réseau (nécessaire uniquement pour WEP)

void setup() {
  Serial.begin(9600);
  Serial.println("Début Setup");
  status = WiFi.begin(ssid,pass);
  printWifiStatus();
  Serial.println("Fin Setup");
}

void loop() {
  // Protocole TCP
  String conv_message_to_string;
  
    //Variable Capteur temperature et humidité
  float capteur1 = 10.10;
  int capteur2 = 20;
  
   /*Liste instruction pour B4A :
   * Arrete : Arreter le store
   */

   if(conv_message_to_string=="Arrete")
   {
    Serial.println("Action de l'arduino");
   }
}

void printWifiStatus() {
  // affiche le SSID du réseau auquel vous êtes connecté :
  Serial.print("SSID : ");
  Serial.println(WiFi.SSID());

  // affiche l'adresse IP du Shield WiFi :
  IPAddress ip = WiFi.localIP();
  Serial.print("Addresse IP : ");
  Serial.println(ip);

  // affiche la longeur du signal reçu :
  long rssi = WiFi.RSSI();
  Serial.print("longeur du Signal (RSSI) : ");
  Serial.print(rssi);
  Serial.println(" dBm");
}
