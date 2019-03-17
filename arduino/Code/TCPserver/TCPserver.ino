

#include <Ethernet.h>

#include <EthernetUdp.h>

#include <SPI.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

byte mac[]={0x90,0xA2,0xDA,0x0D,0x81,0x40};
IPAddress ip_shield(192,168,1,205);
unsigned int port_local=5500;
EthernetServer server(port_local);
String message;
boolean change=false;

void setup()
{
  Ethernet.begin(mac, ip_shield);
  server.begin();
  lcd.init(); 
  lcd.backlight();
  lcd.print("Server started");
  delay(3000);
}

void loop()
{
  lcd.home();
  lcd.print("Attente client");
  
  EthernetClient client = server.available();
  
  if (client) 
    {
     while (client.connected()==true) 
       {
          
          client.flush();
          message="";
          change=false;      
                while (client.available() > 0) 
                {
                  char c = client.read();
                  message+=c;
                  change=true;
                }
                        
              if (change == true) {
                lcd.clear();  
                lcd.print("Client connecte");
                lcd.setCursor(0,1);
                lcd.print(message);
                client.print("Message recu :"+message);
                
                }
      }
       lcd.clear();
    }
}




