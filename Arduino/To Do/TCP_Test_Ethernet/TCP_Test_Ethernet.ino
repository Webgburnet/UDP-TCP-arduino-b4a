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
* Shield Ethernet sans POE
* 
*/

#include <Ethernet.h>
#include <SPI.h>

//Shield Ethernet sans Aoe Numero 2
byte mac[]={0x90,0xA2,0xDA,0x0F,0x21,0xAD};
IPAddress ip_shield(192,168,1,205);

EthernetUDP UDP;

void setup() {
  Ethernet.begin(mac,ip_shield);
  Serial.begin(9600);
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
