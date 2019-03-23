/* 
* Arduino Uno
* 
* A0: NC
* A1: NC
* A2: NC
* A3: NC
* A4: NC
* A5: NC
* 
* D0 : RX rs232 non utilise
* D1 : TX rs232 non utilise
* D2 : NC
* D3 : NC
* D4 : SS Shield-Wifi-Arduino carte SD
* D5 : NC
* D6 : NC
* D7 : Shield-Wifi-Arduino
* D8 : NC
* D9 : NC
* D10 : SS Shield-Wifi-Arduino WiFi
* D11 : MOSI Shield-Wifi-Arduino
* D12 : MISO Shield-Wifi-Arduino
* D13 : SCK Shield-Wifi-Arduino
* 
* I2C : NC
* I2C : NC
* 
* Shield Wifi
* 
*/

#include <WiFi.h>
#include <SPI.h>
#include <Wire.h>

//Shield Wifi
int status = WL_IDLE_STATUS;
char ssid[] = "MarcusEtire";         // Nom du réseau wifi
char pass[] = "5D9D659735CE67DD367942A137";       // votre mot de passe réseau wifi(utilisez pour WPA ou comme clé pour WEP)
int keyIndex = 0;                 // votre numéro d'index de clé de réseau (nécessaire uniquement pour WEP)

//TCP protocole
unsigned int port_local=5500;
WiFiServer server(port_local);

String save_message;
String cmd_message;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Début Setup");
  status = WiFi.begin(ssid,pass);
  printWifiStatus();
  server.begin();
  Serial.println("Fin Setup");
}

void loop() 
{
  // Protocole TCP
  String conv_message_to_string;
  WiFiClient client = server.available();
  
    //Capteur
  float capteur1 = 10.10;
  int capteur2 = 20;
  String string_capteur1 (capteur1);
  String string_capteur2 (capteur2);
  //  Serial.print("capteur1 : ");
  //  Serial.println(string_capteur1);
  //  Serial.print("capteur2 : ");
  //  Serial.println(string_capteur2);

 //Requete TCP
 if (client) 
 {
    client.flush();
    conv_message_to_string="";    
    while (client.available() > 0) 
    {
      char c = client.read();
      conv_message_to_string+=c;
//      Serial.print("Commande b4a :");
//      Serial.println(conv_message_to_string);
    }
//    Serial.print("Commande b4a :");
//    Serial.println(conv_message_to_string);
    
    if(conv_message_to_string=="")
    {
      //Ne rien faire
        save_message="";
        cmd_message="";
    }
    else
    {
      if(conv_message_to_string=="Acquer")
      {
        save_message=conv_message_to_string; 
      }
      else
      {
        cmd_message=conv_message_to_string;
      }
    }
            
    if (save_message=="Acquer") 
    {
      Serial.println("Client connecte");
      Serial.print("Message : ");
      Serial.println(conv_message_to_string);
      Serial.print("capteur1 : ");
      Serial.println(string_capteur1);
      Serial.print("capteur2 : ");
      Serial.println(string_capteur2);
      client.print("Message recu :"+conv_message_to_string+"\n"+"Capteur1 : "+string_capteur1+"\n"+"capteur2 : "+string_capteur2);
     }
  }
  
   /*Liste instruction pour B4A :
   * Arrete : Arreter le store
   */

   if(cmd_message=="Arrete")
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
