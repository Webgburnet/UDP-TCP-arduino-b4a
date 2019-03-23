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
* D4 : SS Shield-Ethernet-Arduino SD
* D5 : NC
* D6 : NC
* D7 : NC
* D8 : NC
* D9 : NC
* D10 : SS Shield-Ethernet-Arduino
* D11 : MOSI Shield-Ethernet-Arduino
* D12 : MISO Shield-Ethernet-Arduino
* D13 : SCK Shield-Ethernet-Arduino
* 
* I2C : NC
* I2C : NC
* 
* Shield Ethernet sans POE
* 
*/

#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>

//Shield Ethernet sans Aoe Numero 2
byte mac[]={0x90,0xA2,0xDA,0x0F,0x21,0xAD};
IPAddress ip_shield(192,168,1,205);

EthernetUDP UDP;

void setup() {
  Ethernet.begin(mac,ip_shield);
  UDP.begin(5500);  
  Serial.begin(9600);
}

void loop() {
  // Protocole UDP
  int Size=UDP.parsePacket();
  char message[Size];
  String conv_message_to_string;

  //Variable Capteur temperature et humidité
  float capteur1 = 10.10;
  int capteur2 = 20;
  
   if(Size>0)
  {
    IPAddress remote = UDP.remoteIP();
    UDP.read(message,Size);

    //Convertion du message char UDP en string
    int cases = 0;
    while (cases != Size)
    {
      conv_message_to_string = conv_message_to_string + message[cases];
      cases = cases+1;
    }
    Serial.print("Paquet reçu de taille : ");
    Serial.println(Size);
    Serial.print("Adresse IP de  ");
    Serial.print(remote);
    Serial.print(", sur le port ");
    Serial.println(UDP.remotePort());
    Serial.print("Msg UDP:");
    Serial.println(conv_message_to_string);
    
    delay(500);

    if(conv_message_to_string=="Acquer")
    {
      Serial.print("Le message est : ");
      Serial.print("Capteur actualisé");
      
      delay(1);
      
      UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
      
      UDP.write("Capteur 1 = ");
      UDP.print(capteur1);
      UDP.write(" unite");
      UDP.write("\n");
      UDP.write("Pression = ");
      UDP.print(capteur2);
      UDP.write(" unite");
      UDP.write("\n");
      UDP.endPacket();
    }
    else
    {
      char  ReplyBuffer[] = "acknowledged";
      UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
      UDP.write(ReplyBuffer);
      UDP.endPacket();
    }
  }

  /*Liste instruction pour B4A :
   * Arrete : Arreter le store
   */

   if(conv_message_to_string=="Arrete")
   {
    Serial.println("Action de l'arduino");
   }
}
