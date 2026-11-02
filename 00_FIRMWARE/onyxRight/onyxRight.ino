/*
 * .:Control Xic:.
 * 
 * Josep Puig Villalon
 * 
 * ESP32 module = "ESP32 Dev Module"
 * 
 * I2C Pins:
 * 
 * SCL: D22
 * SDA: D21
 * IRQ: No
 * 
 * Led pin: 2
 * 
 * 
 */


#include <WiFiUdp.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_MPR121.h>



#define TouchThre 10 // Touch threshold 
#define ReleaThre 8 // Release threshold 
#define Prox_TouchThre 6 // Proximity threshold 
#define Prox_ReleaThre 4 // Proximity release threshold


// SSID & pass //
const char* ssid = "C_X_Saxpler_1";
const char* password = "1a3c5e7g9";

// Wifi UDP config //
WiFiUDP Udp;
IPAddress APlocal_IP(192, 168, 4, 177);
IPAddress APgateway(192, 168, 4, 1); 
IPAddress APsubnet(255, 255, 255, 0); 
IPAddress ipRouter(192, 168, 4, 1);

// Wifi vars //
unsigned int localUdpPort = 4000;  
char incomingPacket[255];  
char replyPacekt[255] = "e";  
char incomingByte = 0;   

// Wifi msg vars //
String strData;
String strDataOld;
char valDigital[30];

// MPR121 //
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// Touch vars //
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

// Giroscopis  push modes //
unsigned long pushTimeF2;
unsigned long aliveMillis = 0;
uint8_t alivePeriod = 100;

// MPU6050 //
const int MPU_addr=0x68;
double x;
double y;
double z;
int16_t AcX;
int16_t AcY;
int16_t AcZ;
int minVal=265;
int maxVal=402;
int xAng;
int yAng;
int zAng;
double analogX = 0;
double analogY = 0;
double analogZ = 0;
double analogXOld = 0;
double analogYOld = 0;
double analogZOld = 0;

// LED //
uint8_t ledStatus = 255;
unsigned long ledTick = 0;
uint8_t ledInterval = 2;
bool flgLed = false;

// Input vars, touch & analogs signals //
int val1 = '0';       
int val2 = '0';       
int val3 = '0';       
int val4 = '0';       
int val5 = '0';       
int val6 = '0';       
int val7 = '0';      
int val8 = '0';
int val9 = '0';
int val10 = '0';
int val11 = '0';
int val12 = '0';

// Flags //
bool F2 = false;
bool F3 = false;
bool flg2 = false;
bool flg2a = false;
bool flg3 = false;
bool flg4 = false;

// Touch result var //
Adafruit_MPR121 cap = Adafruit_MPR121();






////////////////////////////////////////////////////////////////////
// Scan touch sensors
////////////////////////////////////////////////////////////////////

void scanTouch()
{
  currtouched = cap.touched();

  for (uint8_t i=0; i<9; i++)
  { 
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)))
    {
      if(i == 0){val1 = '2';} // index - 5
      if(i == 1){val2 = '2';} // mig   - 6
      if(i == 2){val3 = '2';} // menut - 8
      if(i == 3){val4 = '2';} // menut - D#
      if(i == 4){val5 = '2';} // anular - 7
      if(i == 5){val6 = '2';} // S2
      if(i == 6){val7 = '2';} // F1
      if(i == 7){val8 = '2';} // F2
      if(i == 8){val9 = '2';} // F3
    }
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)))
    {
      if(i == 0){val1 = '0';} // index - 5
      if(i == 1){val2 = '0';} // mig   - 6
      if(i == 2){val3 = '0';} // menut - 8
      if(i == 3){val4 = '0';} // menut - D#
      if(i == 4){val5 = '0';} // anular - 7
      if(i == 5){val6 = '0';} // S2
      if(i == 6){val7 = '0';} // F1
      if(i == 7){val8 = '0';} // F2
      if(i == 8){val9 = '0';} // F3 
    }
  }
  lasttouched = currtouched;/////////////reset our state
}


////////////////////////////////////////////////////////////////////
// Long press i giroscopis
////////////////////////////////////////////////////////////////////

void setPressFunctions()
{
  
  if(val8 == '2' && flg2 == false)//////////////////////////////////F2 
  {
    F2 = false;
    flg2 = true;
    pushTimeF2 = millis();
  }
  if(val8 == '2' && flg2 == true && flg2a == false && millis() > pushTimeF2 + 300)////F2 
  {
    F2 = true;
    flg2a = true;
    aliveMillis = millis();
  }
  if(val8 == '0' && flg2 == true )///////////////////////////////////F2
  { 
    F2 = false;
    flg2 = false;
    flg2a = false;
  }
  if((val7 == '2' || val6 == '2') && flg3 == false)/////////////F3 directe sense long press 
  {
    F3 = true;
    flg3 = true;
    aliveMillis = millis();
  }  
  if(val7 == '0' && val6 == '0' && flg3 == true )///////////////////////////////////F3 
  {
    F3 = false;
    flg3 = false;
  }  

}


////////////////////////////////////////////////////////////////////
// Histeresis i adaptació dels rangs
////////////////////////////////////////////////////////////////////

void readGiroscope()
{
  
  if(F2 == true || F3 == true)
  { 

    
    if(flg4 == false || millis() > aliveMillis + alivePeriod)
    {
      aliveMillis = millis();
      flg4 = true;
      
      char giroStatus[6] = "start";
      Udp.beginPacket(ipRouter, 2000);
      Udp.printf(giroStatus);
      Udp.endPacket();
    }

    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr,14,true);
    
    AcX=Wire.read()<<8|Wire.read();
    AcY=Wire.read()<<8|Wire.read();
    AcZ=Wire.read()<<8|Wire.read();
    
    xAng = map(AcX,minVal,maxVal,-90,90);
    yAng = map(AcY,minVal,maxVal,-90,90);
    zAng = map(AcZ,minVal,maxVal,-90,90);
     
    x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
    y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
    z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

    val10 = analogX = x;
    val11 = analogZ = z;

 /*

    Serial.print(analogX);//debug
    Serial.print(" - ");
    Serial.print(analogY);
    Serial.print(" - ");
    Serial.println(analogZ);
 
    Serial.print(val10);//debug
    Serial.print(" - ");
    Serial.println(val11);
*/
    
    delay(15);


    if(analogX <= 89 || (analogX > 250 && analogX <= 360))
    {
      val10 = 90;
      analogXOld = 90;
    }
    if(analogX >= 180 || (analogX > 180 && analogX <= 240)) 
    {
      val10 = 180;
      analogXOld = 180;
    }
    if((analogZ >= 130 || analogZ <= 60) && analogZOld != 90)
    {
      analogX = 90;
      val10 = 90;
      analogXOld = 90;
    }
    
    if(analogZ <= 3 || (analogZ > 250 && analogZ <= 360))
    {
      val11 = 1;
      analogZOld = 1;
    }
    if((analogZ >= 180 && analogZOld > 179) || (analogZ > 180 && analogZ <= 240 && analogZOld > 179)) 
    {
      val11 = 180;
      analogZOld = 180;
    }
    if(analogX >= 140) 
    {
      analogZ = 90;
      val11 = 90;
      analogZOld = 90;
    }
/*
    Serial.print(val10);//debug
    Serial.print(" - ");
    Serial.println(val11);
    Serial.print(" - ");
    Serial.println(val12);
*/

    analogXOld = analogX;
    analogZOld = analogZ;
  }

  if(F2 == false && F3 == false && flg4 == true)
  {
    //val10 = 1;  //X
    //val11 = 20;  //Y
    flg4 = false;

    char giroStatus[6] = "stop";
    Udp.beginPacket(ipRouter, 2000);
    Udp.printf(giroStatus);
    Udp.endPacket();
  }

}


////////////////////////////////////////////////////////////////////
// Assignar valors & enviar per UDP
////////////////////////////////////////////////////////////////////

void assingAndSend()
{
  
  valDigital[0] = 'R';
  valDigital[1] = val1;
  valDigital[2] = val2;
  valDigital[3] = val5;
  valDigital[4] = val3;
  valDigital[5] = val4;
  valDigital[6] = val6;
  valDigital[7] = val9;
  valDigital[8] = val8;
  valDigital[9] = val7;
  valDigital[10] = val10;
  valDigital[11] = val11;
  valDigital[12] = 252;
   
/////////////////////
// Enviar per  UDP 
/////////////////////

  strData="";
  for(int i=0;i<16;i++){strData.concat(valDigital[i]);}
  strData.toCharArray(replyPacekt, 16);
    
  if(strData != strDataOld)
  {
    //const char ipR[] = "192.168.4.1"; 
    Udp.beginPacket(ipRouter, 2000);
    Udp.printf(replyPacekt);
    Udp.endPacket();
    
    //Serial.print("Data out: "); //debug
    //Serial.println(replyPacekt); 
    ledStatus = 255;
  }
  strDataOld = strData;

}

////////////////////////////////////////////////////////////////////
// Led status
////////////////////////////////////////////////////////////////////

void updateLed()
{
  
  if(ledStatus > 0 && flgLed == false)
  {
    ledTick = millis();
    flgLed = true;
  }

  if(ledStatus > 0 && millis() >= ledTick + ledInterval && flgLed == true)
  {   
    ledStatus--;
    analogWrite(2, ledStatus);
    ledTick = millis();
  }
  if(ledStatus == 0 && flgLed == true)
  {
    flgLed = false;
  }
}


////////////////////////////////////////////////////////////////////
// MPR121 init config
////////////////////////////////////////////////////////////////////

void MPR121_init_config() 
{ 
  cap.writeRegister(0x80,0x63); // Soft reset MPR121 if not reset correctly 

  //touch pad baseline filter 
  //rising: baseline quick rising 
  cap.writeRegister(0x2B,0x01); // Max half delta Rising 
  cap.writeRegister(0x2C,0x01); // Noise half delta Rising 
  cap.writeRegister(0x2D,0x00); // Noise count limit Rising 
  cap.writeRegister(0x2E,0x00); // Delay limit Rising
  
  //falling: baseline slow falling 
  cap.writeRegister(0x2F,0x01); // Max half delta Falling 
  cap.writeRegister(0x30,0x01); // Noise half delta Falling 
  cap.writeRegister(0x31,0xFF); // Noise count limit Falling 
  cap.writeRegister(0x32,0x0); // Delay limit Falling
  
  //touched: baseline keep 
  cap.writeRegister(0x33,0x00); // Noise half delta Touched 
  cap.writeRegister(0x34,0x00); // Noise count Touched 
  cap.writeRegister(0x35,0x00); // Delay limit Touched 
  
  //Proximity baseline filter 
  
  //rising: very quick rising 
  cap.writeRegister(0x36,0x0f); // Max half delta Rising 
  cap.writeRegister(0x37,0x0f); // Noise half delta Rising 
  cap.writeRegister(0x38,0x00); // Noise count Rising
  cap.writeRegister(0x39,0x00); // Delay limit Rising
  
  //falling: very slow rising 
  cap.writeRegister(0x3A,0x01); // Max half delta Falling 
  cap.writeRegister(0x3B,0x01); // Noise half delta Falling 
  cap.writeRegister(0x3C,0xff); // Noise count Falling 
  cap.writeRegister(0x3D,0xff); // Delay limit Falling 
  
  //touched 
  cap.writeRegister(0x3E,0x00); 
  cap.writeRegister(0x3F,0x00); 
  cap.writeRegister(0x40,0x00); 
  
  //Touch pad threshold 
  cap.writeRegister(0x41,TouchThre); // ELE0 TOUCH THRESHOLD 
  cap.writeRegister(0x42,ReleaThre); // ELE0 RELEASE THRESHOLD 
  cap.writeRegister(0x43,TouchThre); // ELE1 TOUCH THRESHOLD 
  cap.writeRegister(0x44,ReleaThre); // ELE1 RELEASE THRESHOLD 
  cap.writeRegister(0x45,TouchThre); // ELE2 TOUCH THRESHOLD 
  cap.writeRegister(0x46,ReleaThre); // ELE2 RELEASE THRESHOLD 
  cap.writeRegister(0x47,TouchThre); // ELE3 TOUCH THRESHOLD 
  cap.writeRegister(0x48,ReleaThre); // ELE3 RELEASE THRESHOLD 
  cap.writeRegister(0x49,TouchThre); // ELE4 TOUCH THRESHOLD 
  cap.writeRegister(0x4A,ReleaThre); // ELE4 RELEASE THRESHOLD 
  cap.writeRegister(0x4B,TouchThre); // ELE5 TOUCH THRESHOLD 
  cap.writeRegister(0x4C,ReleaThre); // ELE5 RELEASE THRESHOLD 
  cap.writeRegister(0x4D,TouchThre); // ELE6 TOUCH THRESHOLD 
  cap.writeRegister(0x4E,ReleaThre); // ELE6 RELEASE THRESHOLD 
  cap.writeRegister(0x4F,TouchThre); // ELE7 TOUCH THRESHOLD 
  cap.writeRegister(0x50,ReleaThre); // ELE7 RELEASE THRESHOLD 
  cap.writeRegister(0x51,TouchThre); // ELE8 TOUCH THRESHOLD 
  cap.writeRegister(0x52,ReleaThre); // ELE8 RELEASE THRESHOLD 
  cap.writeRegister(0x53,TouchThre); // ELE9 TOUCH THRESHOLD 
  cap.writeRegister(0x54,ReleaThre); // ELE9 RELEASE THRESHOLD 
  cap.writeRegister(0x55,TouchThre); // ELE10 TOUCH THRESHOLD 
  cap.writeRegister(0x56,ReleaThre); // ELE10 RELEASE THRESHOLD 
  cap.writeRegister(0x57,TouchThre); // ELE11 TOUCH THRESHOLD 
  cap.writeRegister(0x58,ReleaThre); // ELE11 RELEASE THRESHOLD 
  
  
  //Proximity threshold 
  cap.writeRegister(0x59,Prox_TouchThre); // ELE12 TOUCH THRESHOLD 
  cap.writeRegister(0x5A,Prox_ReleaThre); // ELE12 RELEASE THRESHOLD 
  
  //touch and release interrupt debounce 
  cap.writeRegister(0x5B,0x00); // Not used for polling method, effective for INT mode. 
  
  //AFE and filter configuration 
  cap.writeRegister(0x5C,0x10); // AFES=6 samples, same as AFES in 0x7B, Global CDC=16uA 
  cap.writeRegister(0x5D,0x20); // CT=0.5us, TDS=4samples, TDI=16ms defalut = 0x24
  cap.writeRegister(0x5E,0x80); // Set baseline calibration enabled, baseline loading 5MSB 
  
  //Auto Configuration 
  cap.writeRegister(0x7B,0x0B); // AFES=6 samples, same as AFES in 0x5C 
  // retry=2b00, no retry, 
  // BVA=2b10, load 5MSB after AC, 
  // ARE/ACE=2b11, auto configuration enabled 
  //cap.writeRegister(0x7C,0x80); // Skip charge time search, use setting in 0x5D, 
  // OOR, AR, AC IE disabled 
  // Not used. Possible Proximity CDC shall over 63uA 
  // if only use 0.5uS CDT, the TGL for proximity cannot meet 
  // Possible if manually set Register0x72=0x03 
  // (Auto configure result) alone. 
  cap.writeRegister(0x7D,0xc8); // AC up limit /C8/BD/C0/9C 
  cap.writeRegister(0x7E,0x82); // AC low limit /82/7A/7C/65 
  cap.writeRegister(0x7F,0xb4); // AC target /B4/AA/AC/8C target for /3.0V/2.8V/1.8V 
  cap.writeRegister(0x5E,0xBC); // Run 12 touch + proximity, CL=2b10, load 5MSB to baseline 

} 


////////////////////////////////////////////////////////////////////
// Setup
////////////////////////////////////////////////////////////////////


void setup()
{

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("right");

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


  if (!cap.begin(0x5A)) 
  {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  } 
  Serial.println(" connected");

  // Init MPU6050 //
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Init MPR121 //
  MPR121_init_config();
 
}


////////////////////////////////////////////////////////////////////
// Loop
////////////////////////////////////////////////////////////////////


void loop()
{
  
  scanTouch();
  setPressFunctions();
  readGiroscope();
  assingAndSend();
  updateLed();
    
} 


/*


  //// new config ////

  cap.writeRegister(0x7b, 0x00); //auto config
  cap.writeRegister(0x7c, 0x00); //auto re-config

 // Electrode Baseline
  cap.writeRegister(0x1E, 0x05); //menut   touch 0
  cap.writeRegister(0x1F, 0x05); //polze   touch 1
  cap.writeRegister(0x20, 0x05); //polze   touch 2 
  cap.writeRegister(0x21, 0x05); //polze   touch 3
  cap.writeRegister(0x22, 0x05); //polze   touch 4 
  cap.writeRegister(0x23, 0x05); //menut   touch 5 *
  cap.writeRegister(0x24, 0x05); //polze   touch 6
  cap.writeRegister(0x25, 0x05); //polze   touch 7 
  cap.writeRegister(0x26, 0x05); //polze   touch 8 

  // Electrode Touch / Relese Threshold
  cap.writeRegister(0x41, 0x07); //index   touch 0
  cap.writeRegister(0x42, 0x04);
  cap.writeRegister(0x43, 0x07); //mig     touch 1
  cap.writeRegister(0x44, 0x04);
  cap.writeRegister(0x45, 0x07); //anular  touch 2
  cap.writeRegister(0x46, 0x04);
  cap.writeRegister(0x47, 0x07); //menut   touch 3
  cap.writeRegister(0x48, 0x04);
  cap.writeRegister(0x49, 0x07); //menut   touch 4 *
  cap.writeRegister(0x4A, 0x04);
  
  cap.writeRegister(0x4B, 0x07); //polze   touch 5
  cap.writeRegister(0x4C, 0x04);
  cap.writeRegister(0x4D, 0x07); //polze   touch 6
  cap.writeRegister(0x4E, 0x04);
  cap.writeRegister(0x4F, 0x07); //polze   touch 7
  cap.writeRegister(0x50, 0x04);
  cap.writeRegister(0x51, 0x07); //polze   touch 8
  cap.writeRegister(0x52, 0x04);

  // Electrode charge Current
  cap.writeRegister(0x5F, 0x15);
  cap.writeRegister(0x60, 0x15);
  cap.writeRegister(0x61, 0x15); 
  cap.writeRegister(0x62, 0x15);
  cap.writeRegister(0x63, 0x15); //menut   touch 4
  cap.writeRegister(0x64, 0x18); //polze   touch 5
  cap.writeRegister(0x65, 0x18); //polze   touch 6 
  cap.writeRegister(0x66, 0x18); //polze   touch 7
  cap.writeRegister(0x67, 0x18); //polze   touch 8 

  // ECR config
  cap.writeRegister(0x5E, 0x49); 

*/
