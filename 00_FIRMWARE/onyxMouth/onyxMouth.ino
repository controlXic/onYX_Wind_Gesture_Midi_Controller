/*
 * .:Control Xic:.
 * 
 * Josep Puig Villalon
 * 
 * ESP32 module = "ESP32 Dev Module"
 * 
 */


#include <WiFiUdp.h>
#include <WiFi.h>
//#include <driver/adc.h>


// SSID & pass
const char* ssid = "C_X_Saxpler_1";
const char* password = "1a3c5e7g9";

// Wifi vars
unsigned int localUdpPort = 3000;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char replyPacekt[255] = "";  // a reply string to send back
char incomingByte = 0;   // for incoming serial data

// wind vars
uint16_t adcValWind = 0;
uint8_t valWind = 0;
uint8_t valWindold = 0;
uint8_t valWindMin = 16;


// re sent wind interval
unsigned long offWindTime = 0;
int offWindInterval = 100;
bool flgWind = false;
bool flgSent = false;

// UDP vars
char valDigital[5];
String strData;
String strDataOld;

// USP config
WiFiUDP Udp;
IPAddress APlocal_IP(192, 168, 4, 166);
IPAddress APgateway(192, 168, 4, 1); // set gateway to match your network
IPAddress APsubnet(255, 255, 255, 0); // set subnet mask to match your network


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("mouth");
  Serial.printf("Connecting to %s ", ssid);
  
  WiFi.config(APlocal_IP,APgateway,APsubnet);
  WiFi.begin(ssid, password);
  
  Udp.begin(APlocal_IP,localUdpPort);
  Serial.printf("Local IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
}


void loop(){


////////////////////////////////////////////////////////////////////
// ACD read & create string
////////////////////////////////////////////////////////////////////


  delay(10);// delay de so
  
  adcValWind = analogRead(34);
  //Serial.println(adcValWind);////new debug
  
  // V > 2.5V //
  if(adcValWind > 1900)
    valWind = map(adcValWind, 1900, 3700, 0, 127);// presure sensor
  else
    valWind = 0;

    
    
  if(valWind > 127)
    valWind = 127;
  if(valWind <= valWindMin)
    valWind = 1;
  
  //Serial.println(valWind);////new debug
  

  if(valWind <= valWindMin)
  {
    valWind = 1;
    
    if(flgWind == true)
    {
     offWindTime = millis(); 
     flgWind = false;        
    }    
  }
  
  else
  {    
    flgWind = true;
    flgSent = false;
  }


  valDigital[0] = 'M';
  valDigital[1] = valWind;
  valDigital[2] = valWind;
  valDigital[3] = 250;  
  //Serial.println(valWind, DEC);////new debug


////////////////////////////////////////////////////////////////////
// Envia la presio del vent per UDP 
////////////////////////////////////////////////////////////////////


  strData="";
  for(int i=0;i<5;i++){strData.concat(valDigital[i]);}
  strData.toCharArray(replyPacekt, 5);
    
  if(strData != strDataOld && valWind < valWindold - 5 || valWind > valWindold + 5)
  {
    const char ip2[] = "192.168.4.1"; 
    Udp.beginPacket(ip2,2000);
    Udp.printf(replyPacekt);
    Udp.endPacket();
    //Serial.println(replyPacekt); // debug
    //Serial.println(valWind);////new debug
  }
  valWindold = valWind;
  strDataOld = strData;

} 
