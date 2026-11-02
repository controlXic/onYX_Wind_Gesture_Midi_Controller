///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

  .:Control Xic:.

      -Utilizar driver especializado (tarjeta de sonido), o, en su defecto, el genérico ASIO4ALL


*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "MIDIUSB.h"
//#include "FastLED.h"


// Led def & var
//#define NUM_LEDS 1
//CRGB leds[NUM_LEDS];

// Data input
String strData;
String leftData;
String rightData;
String mouthData;

String leftDataOld;
String rightDataOld;

// Long pres giroscopis
unsigned long pushTimeF2LongPress;
unsigned long sendTime;
unsigned long sendTimeVel;


// Retard de canvi de nota, fa que soni  lligat
unsigned long changeNoteTick = 0;
int changeNoteDelay = 5;


// Data polsadors mandos
uint16_t buttonByte;
uint16_t buttonByteOld;
bool buttonShift1 = false;
bool buttonShift2 = false;
bool buttonOctave1 = false;
bool buttonOctave2 = false;
bool buttonOctave3 = false;
bool F2 = false;
bool F3 = false;
bool S2O3 = false;

bool flgF2 = false;
bool flgF3 = false;
bool flgS2O3 = false;

char inData;
char inDataOldMouth;
char inDataOldRight;
char inDataOldRight2;
char inDataOldLeft;
char inDataOldLeft2;

byte channel = 0;
byte octave = 0;

byte delaynoteOnOff = 20;
byte delayVel = 5;

byte vel = 0;
byte velOld = 0;
byte vel2 = 0;
byte velStatus = 0;


byte giroXd = 0;
byte giroYd = 0;
byte giroXe = 0;
byte giroYe = 0;

byte giroXd2;
byte giroYd2;
byte giroYd3;
int giroYdPB = 0;
int giroYdPB2 = 0;
int giroYdPB2Old = 0;
byte giroXdOld = 0;
byte giroYdOld = 0;
byte giroYd3Old = 0;

byte giroYd3Old2 = 0;
byte giroYe3Old2 = 0;
int giroYdPB2Old2 = 0;

byte giroXe2;
byte giroYe2;
byte giroYe3;
byte giroXeOld = 0;
byte giroYeOld = 0;
byte giroYe3Old = 0;

// Flags serial read
bool flgMouth = false;
bool flgRight = false;
bool flgLeft = false;

// Buttons
bool button1 = false;
bool button2 = false;
bool button3 = false;
bool button4 = false;
bool buttonP = false;
bool button5 = false;
bool button6 = false;
bool button7 = false;
bool button8 = false;
bool buttonD = false;

// Flags
bool flg1, flg2, flg3, flg4, flg5, flg6, flg7, flg8, flg9, flg10 = false;
bool flg11, flg12, flg13, flg14, flg15, flg16, flg17, flg18, flg19, flg20 = false;
bool flg21, flg22, flg23, flg24, flg25, flg26, flg27, flg28, flg29, flg30 = false;
bool flg31, flg32, flg33, flg34, flg35, flg36, flg37, flg38, flg39, flg40 = false;
bool flg41, flg42, flg43, flg44, flg45, flg46, flg47, flg48, flg49, flg50 = false;
bool flg51, flg52, flg53, flg54, flg55, flg56, flg57, flg58, flg59, flg60 = false;
bool flg61, flg62, flg63, flg64, flg65, flg66, flg67, flg68, flg69, flg70 = false;
bool flg71, flg72, flg73, flg74, flg75, flg76, flg77, flg78, flg79, flg80 = false;
bool flg81, flg82, flg83, flg84, flg85, flg86, flg87, flg88, flg89, flg90 = false;
bool flg91, flg92, flg93, flg94, flg95, flg96, flg97, flg98, flg99, flg100 = false;
bool flg101, flg102, flg103, flg104, flg105, flg106, flg107, flg108, flg109, flg110 = false;
bool flg111, flg112, flg113, flg114, flg115, flg116, flg117, flg118, flg119, flg120 = false;
bool flg121, flg122, flg123, flg124, flg125, flg126, flg127, flg128, flg129, flg130 = false;
bool flg131, flg132, flg133, flg134, flg135, flg136, flg137, flg138, flg139, flg140 = false;
bool flg141, flg142, flg143, flg144, flg145, flg146, flg147, flg148, flg149, flg150 = false;
bool flg151, flg152, flg153, flg154, flg155, flg156, flg157, flg158, flg159, flg160 = false;
bool flg161, flg162, flg163, flg164, flg165, flg166, flg167, flg168, flg169, flg170 = false;
bool flg171, flg172, flg173, flg174, flg175, flg176, flg177, flg178, flg179, flg180 = false;
bool flg181, flg182, flg183, flg184, flg185, flg186, flg187, flg188, flg189, flg190 = false;
bool flg191 = false;



////////////////////////////////////////////////////////////////////
// MIDI Functions
////////////////////////////////////////////////////////////////////


void noteOn(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}
void noteOff(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}


void controlChange(byte channel, byte control, byte value) 
{
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void chPressure(byte channel, byte velocity)
{
  midiEventPacket_t event = {0x0D, 0xD0 | channel, velocity};
  MidiUSB.sendMIDI(event);
}

void Polyphonic(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t event = {0x0A, 0xA0 | channel, pitch, velocity};
  MidiUSB.sendMIDI(event);
}

void pitchBendChange(byte channel, int value) 
{
  byte lowValue = value & 0xff; //0x7F
  byte highValue = value >> 7;  //7
  midiEventPacket_t event = {0x0E, 0xE0 | channel, lowValue, highValue};
  MidiUSB.sendMIDI(event);
}



void setup() 
{
  Serial.begin(115200);
  Serial.println();
  
  Serial1.begin(115200);
  Serial1.println();
  
  Serial.println("Control Xic");
  Serial1.println("Control Xic 1");
  
  delay(400);
/*
  FastLED.addLeds<WS2812B, 2>(leds, NUM_LEDS); 
  leds[0] = CRGB(10, 10, 0); 
  FastLED.show(); 
*/
}




void loop() 
{

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Read serial
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(Serial1.available() > 0) 
  {
    inData = Serial1.read();
    strData.concat(inData);
  }
  
  if(inData == '*') 
  {
    mouthData = strData;
    strData = "";
    vel = inDataOldMouth;
    //Serial.print(mouthData); // Debug
    //Serial.println(vel, DEC); // Debug mouth
  }
  if(inData == 'M') 
  {
    flgMouth = true;
  }
  if(inData == '*') 
  {
    flgMouth = false;
  }
  if(flgMouth == true)
  {
    inDataOldMouth = inData;
  }
  
  if (inData == '!') 
  {
    leftData = strData;
    strData = "";
    //Serial.print(leftData); // Debug
    giroXe = inDataOldLeft2;
    giroYe = inDataOldLeft;
  }
  if(inData == 'L')
  {
    flgLeft = true;
  }
  if(inData == '!') 
  {
    flgLeft = false;
  }
  if(flgLeft == true)
  {
    inDataOldLeft2 = inDataOldLeft;
    inDataOldLeft = inData;
  }
  
  if(inData == '?') 
  {
    rightData = strData;
    strData = "";
    //Serial.print(rightData); // Debug
    
    giroXd = inDataOldRight2;
    giroYd = inDataOldRight;
  }
  if(inData == 'R') 
  {
    flgRight = true;
  }
  if(inData == '?')
  {
    flgRight = false;
  }
  if(flgRight == true) 
  {
    inDataOldRight2 = inDataOldRight;
    inDataOldRight = inData;
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Button left & right to byte note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if((leftData != leftDataOld || rightData != rightDataOld) && flg70 == false) /////delay multi press
  {
    sendTime = millis();
    flg70 = true;
  }
  if(flg70 == true && millis() > sendTime + delaynoteOnOff) ////////////////////////delay multi press
  {

    if(leftData.substring(3, 4) == "1" && flg1 == false)///////////////1
    { 
      buttonByte = buttonByte + 1;
      button1 = true;
      flg1 = true;
    }
    if(leftData.substring(3, 4) == "0" && flg1 == true) 
    {
      buttonByte = buttonByte - 1;
      button1 = false;
      flg1 = false;
    }

    if (leftData.substring(4, 5) == "1" && flg2 == false)  ///////////////2
    {
      buttonByte = buttonByte + 2;
      button2 = true;
      flg2 = true;
    }
    if(leftData.substring(4, 5) == "0" && flg2 == true) 
    {
      buttonByte = buttonByte - 2;
      button2 = false;
      flg2 = false;
    }

    if(leftData.substring(5, 6) == "1" && flg3 == false) ///////////////3
    { 
      buttonByte = buttonByte + 4;
      button3 = true;
      flg3 = true;
    }
    if(leftData.substring(5, 6) == "0" && flg3 == true) 
    {
      buttonByte = buttonByte - 4;
      button3 = false;
      flg3 = false;
    }

    if(leftData.substring(7, 8) == "1" && flg5 == false && button2 == false) ///////////////P // Funció especial 2
    { 
      buttonByte = buttonByte + 16;      
      buttonP = true;
      flg5 = true;
    }
    if((leftData.substring(7, 8) == "0" && flg5 == true) || (button2 == true && flg5 == true))
    {
      buttonByte = buttonByte - 16;
      buttonP = false;
      flg5 = false;
    }

    if(rightData.substring(3, 4) == "2" && flg6 == false)//////////////5
    { 
      buttonByte = buttonByte + 32;
      button5 = true;
      flg6 = true;
    }
    if(rightData.substring(3, 4) == "0" && flg6 == true)
    {
      buttonByte = buttonByte - 32;
      button5 = false;
      flg6 = false;
    }

    if(rightData.substring(4, 5) == "2" && flg7 == false)//////////////6
    { 
      buttonByte = buttonByte + 64;
      button6 = true;
      flg7 = true;
    }
    if (rightData.substring(4, 5) == "0" && flg7 == true) 
    {
      buttonByte = buttonByte - 64;
      button6 = false;
      flg7 = false;
    }

    if(rightData.substring(5, 6) == "2" && flg8 == false)//////////////7
    { 
      buttonByte = buttonByte + 128;
      button7 = true;
      flg8 = true;
    }
    if(rightData.substring(5, 6) == "0" && flg8 == true)
    {
      buttonByte = buttonByte - 128;
      button7 = false;
      flg8 = false;
    }

    if(rightData.substring(6, 7) == "2" && flg9 == false)  //////////////8
    {
      buttonByte = buttonByte + 256;
      button8 = true;
      flg9 = true;
    }
    if(rightData.substring(6, 7) == "0" && flg9 == true) 
    {
      buttonByte = buttonByte - 256;
      button8 = false;
      flg9 = false;
    }

    if(rightData.substring(7, 8) == "2" && flg10 == false) ////////////D#
    { 
      buttonByte = buttonByte + 512;
      buttonD = true;
      flg10 = true;
    }
    if(rightData.substring(7, 8) == "0" && flg10 == true) 
    {
      buttonByte = buttonByte - 512;
      buttonD = false;
      flg10 = false;
    }
    
    if(leftData.substring(6, 7) == "1" && flg4 == false && ((button5 == false && button6 == false && button7 == false) || (button8 == true)))///////4 // Funció especial 1
    { 
      buttonByte = buttonByte + 8;
      button4 = true;
      flg4 = true;
    }
    if((leftData.substring(6, 7) == "0" && flg4 == true) || ((button5 == true || button6 == true || button7 == true) && button8 == false && flg4 == true)) 
    {
      buttonByte = buttonByte - 8;
      button4 = false;
      flg4 = false;
    }

    // lligar notes
    //changeNoteTick = millis();

    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Octaves, Shifts, portamento
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(leftData.substring(8, 9) == "1" && flg25 == false)///////////////Shift1
    { 
      buttonShift1 = true;
      flg25 = true;
    }
    if(leftData.substring(8, 9) == "0" && flg25 == true) 
    {
      buttonShift1 = false;
      flg25 = false;
    }

    if(rightData.substring(8, 9) == "2" && flg26 == false)//////////////Shift2 
    { 
      buttonShift2 = true;
      flg26 = true;
    }
    if(rightData.substring(8, 9) == "0" && flg26 == true)
    { 
      buttonShift2 = false;
      flg26 = false;
    }

    if(leftData.substring(9, 10) == "1" && flg27 == false)///////////////O1
    { 
      buttonOctave1 = true;
      flg27 = true;
    }
    if(leftData.substring(9, 10) == "0" && flg27 == true)
    {
      buttonOctave1 = false;
      flg27 = false;
    }
    if(leftData.substring(10, 11) == "1" && flg28 == false)///////////////O2
    { 
      buttonOctave2 = true;
      flg28 = true;
    }
    if(leftData.substring(10, 11) == "0" && flg28 == true) 
    {
      buttonOctave2 = false;
      flg28 = false;
    }
    if(leftData.substring(11, 12) == "1" && flg29 == false) ///////////////O3
    { 
      buttonOctave3 = true;
      flg29 = true;
    }
    if(leftData.substring(11, 12) == "0" && flg29 == true) 
    {
      buttonOctave3 = false;
      flg29 = false;
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions, time press; ControlChange i giroscopis. F1, F2, F3,
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    if(buttonShift1 == false && buttonShift2 == false)
    {
      if (rightData.substring(9, 10) == "2" && flg30 == false) ////////////////////////////////////////////////// CC F1 
      {
        flg30 = true;
        controlChange(channel, 64, 127);
        MidiUSB.flush();
      }
      if (rightData.substring(9, 10) == "0" && flg30 == true) 
      {
        flg30 = false;
        controlChange(channel, 64, 0);
        MidiUSB.flush();
      }
     
      if (rightData.substring(10, 11) == "2" && flg31 == false) //////////////////////////////////////////F2 start press
      { 
        controlChange(channel, 114, 127);
        MidiUSB.flush();
        flg31 = true;
        flg72 = true;
        pushTimeF2LongPress = millis();
      }
      if (rightData.substring(10, 11) == "2" && flg72 == true &&  millis() > pushTimeF2LongPress + 300) ////F2 long press
      { 
        F2 = true;
      }
      if (rightData.substring(10, 11) == "0" && flg72 == true)
      {
        controlChange(channel, 114, 0);
        MidiUSB.flush();
        F2 = false;
        flg31 = false;
        flg72 = false;
      }
  
      if (rightData.substring(11, 12) == "2" && flg32 == false) //////////////////////////////////////////// F3 instantani
      { 
        flg32 = true;
        F3 = true;
      }
      if (rightData.substring(11, 12) == "0" && flg32 == true ) 
      {
        flg32 = false;
        F3 = false;
      }
    }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shift 1 + F1-2-3
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    if(buttonShift1 == true && buttonShift2 == false)
    {
       if (rightData.substring(9, 10) == "2" && flg71 == false) ///////////////////////// Shift1 + F1 
      {
        noteOn(channel, 0, 127);
        MidiUSB.flush();
        flg71 = true;
      }
      if (rightData.substring(9, 10) == "0" && flg71 == true) 
      {      
        noteOff(channel, 0, 0);
        MidiUSB.flush(); 
        flg71 = false;
      }
     
      if (rightData.substring(10, 11) == "2" && flg190 == false) ////////////////////////// Shift1 + F2 
      { 
        noteOn(channel, 1, 127);
        MidiUSB.flush();
        flg190 = true;
      }
      if (rightData.substring(10, 11) == "0" && flg190 == true)
      {
        noteOff(channel, 1, 0);
        MidiUSB.flush(); 
        flg190 = false;
      }
  
      if (rightData.substring(11, 12) == "2" && flg191 == false) /////////////////////////// Shift1 + F3
      { 
        noteOn(channel, 2, 127);
        MidiUSB.flush();        
        flg191 = true;
      }
      if (rightData.substring(11, 12) == "0" && flg191 == true ) 
      {
        noteOff(channel, 2, 0);
        MidiUSB.flush();         
        flg191 = false;
      }
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Portamento, acords, configurable & giroscopis
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(buttonOctave1 == true && buttonShift2 == true && flg73 == false) /////////////// Shift2 + O1
    { 
      noteOn(0, 3, 127);
      MidiUSB.flush();
      flg73 = true;
    }
    if((buttonOctave1 == false || buttonShift2 == false) && flg73 == true) 
    {
      noteOff(0, 3, 0);
      MidiUSB.flush();      
      flg73 = false;
    }

    if(buttonOctave2 == true && buttonShift2 == true && flg74 == false) ///////////////Shift2 + O2
    { 
      noteOn(0, 4, 127);
      MidiUSB.flush();
      flg74 = true;
    }
    if((buttonOctave2 == false || buttonShift2 == false) && flg74 == true) 
    {
      noteOff(0, 4, 0);
      MidiUSB.flush();       
      flg74 = false;
    }

    if(buttonOctave3 == true && buttonShift2 == true && flg75 == false)///////////////Shift2 + O3
    { 
      S2O3 = true;
      flg75 = true;
    }
    if((buttonOctave3 == false || buttonShift2 == false) && flg75 == true)
    {
      S2O3 = false;   
      flg75 = false;
    }
    
    
    flg70 = false;
  }
  leftDataOld = leftData;//////////////////////////////////////////////////////////////fi del delay noteOn/Off
  rightDataOld = rightData;////////////////////////////////////////////////////////////fi del delay noteOn/Off


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Change Channel, Shift 1 || 2 + button note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(buttonShift1 == true && buttonShift2 == false)
  {
    if(buttonByte == 1 || buttonByte == 17)
    {
      channel = 0;
    }
    else if(buttonByte == 2)
    {
      channel = 1;
    }
    else if(buttonByte == 4)
    {
      channel = 2;
    }
    else if(buttonByte == 8)
    {
      channel = 3;
    }
    else if(buttonByte == 32)
    {
      channel = 4;
    }
    else if(buttonByte == 64)
    {
      channel = 5;
    }
    else if(buttonByte == 128)
    {
      channel = 6;
    }
    else if(buttonByte == 256)
    {
      channel = 7;
    }
  }

  if(buttonShift1 == false && buttonShift2 == true)
  {
    if(buttonByte == 1 || buttonByte == 17)
    {
      channel = 8;
    }
    else if(buttonByte == 2)
    {
      channel = 9;
    }
    else if(buttonByte == 4)
    {
      channel = 10;
    }
    else if(buttonByte == 8)
    {
      channel = 11;
    }
    else if(buttonByte == 32)
    {
      channel = 12;
    }
    else if(buttonByte == 64)
    {
      channel = 13;
    }
    else if(buttonByte == 128)
    {
      channel = 14;
    }
    else if(buttonByte == 256)
    {
      channel = 15;
    }
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sampler mode, Shift 1 && 2 + buton note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(buttonShift1 == true && buttonShift2 == true) 
  {
    if(button1 == true && flg33 == false)/////////////////////C--
    { 
      noteOn(channel, 24, 127);
      MidiUSB.flush();
      flg33 = true;
    }
    if(button1 == false && flg33 == true) 
    {
      noteOff(channel, 24, 0);
      MidiUSB.flush();
      flg33 = false;
    }

    if(button2 == true && flg34 == false)///////////////////C#--
    { 
      noteOn(channel, 25, 127);
      MidiUSB.flush();
      flg34 = true;
    }
    if(button2 == false && flg34 == true) 
    {
      noteOff(channel, 25, 0);
      MidiUSB.flush();
      flg34 = false;
    }

    if(button3 == true && flg35 == false)////////////////////D--
    { 
      noteOn(channel, 26, 127);
      MidiUSB.flush();
      flg35 = true;
    }
    if(button3 == false && flg35 == true) 
    {
      noteOff(channel, 26, 0);
      MidiUSB.flush();
      flg35 = false;
    }

    if(button4 == true && flg36 == false) /////////////////////D#--
    { 
      noteOn(channel, 27, 127);
      MidiUSB.flush();
      flg36 = true;
    }
    if(button4 == false && flg36 == true) 
    {
      noteOff(channel, 27, 0);
      MidiUSB.flush();
      flg36 = false;
    }

    if(button5 == true && flg37 == false)//////////////////////E--
    { 
      noteOn(channel, 28, 127);
      MidiUSB.flush();
      flg37 = true;
    }
    if(button5 == false && flg37 == true) 
    {
      noteOff(channel, 28, 0);
      MidiUSB.flush();
      flg37 = false;
    }

    if(button6 == true && flg38 == false)///////////////////////F--
    { 
      noteOn(channel, 29, 127);
      MidiUSB.flush();
      flg38 = true;
    }
    if(button6 == false && flg38 == true)
    {
      noteOff(channel, 29, 0);
      MidiUSB.flush();
      flg38 = false;
    }

    if(button7 == true && flg39 == false) //////////////////////F#--
    { 
      noteOn(channel, 30, 127);
      MidiUSB.flush();
      flg39 = true;
    }

    if(button7 == false && flg39 == true) 
    {
      noteOff(channel, 30, 0);
      MidiUSB.flush();
      flg39 = false;
    }

    if(button8 == true && flg40 == false) //////////////////////////G--
    { 
      noteOn(channel, 31, 127);
      MidiUSB.flush();
      flg40 = true;
    }
    if(button8 == false && flg40 == true) 
    {
      noteOff(channel, 31, 0);
      MidiUSB.flush();
      flg40 = false;
    }
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Byte to sound
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(vel <= 1)  /////delay init pressure
  {
    velStatus = 1;
  }
  if(vel > 1 && velStatus == 1) 
  {
    sendTimeVel = millis();
    velStatus = 2;
  }
  if(vel > 1 && millis() > sendTimeVel + delayVel && velStatus == 2 || velStatus == 0) 
  {
    vel2 =  map(vel, 0, 127, 0, 127); //normal
    velStatus = 0;
  }

  if(velStatus == 0 || velStatus == 1)
  {


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Byte to sound. Block 1 - octave = 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(buttonOctave1 == false && buttonOctave2 == false && buttonOctave3 == false && vel > 20) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-0 ON
    { 
      
      if(buttonByte == 487 && flg11 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C
      {
        noteOn(channel, 36, vel2);
        MidiUSB.flush();
        flg11 = true;
      }
      if(buttonByte == 495 && flg12 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#
      {
        noteOn(channel, 37, vel2);
        MidiUSB.flush();
        flg12 = true;
      }
      if(buttonByte == 231 && flg13 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D
      {
        noteOn(channel, 38, vel2);
        MidiUSB.flush();
        flg13 = true;
      }
      if(buttonByte == 743 && flg14 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#
      {
        noteOn(channel, 39, vel2);
        MidiUSB.flush();
        flg14 = true;
      }
      if(buttonByte == 103 && flg15 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E
      {
        noteOn(channel, 40, vel2);
        MidiUSB.flush();
        flg15 = true;
      }
      if(buttonByte == 39 && flg16 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F
      {
        noteOn(channel, 41, vel2);
        MidiUSB.flush();
        flg16 = true;
      }
      if((buttonByte == 71|| buttonByte == 135 || buttonByte == 167) && flg17 == false) ////////////////////////////////////////////////////////////////////////////////////F#
      {
        noteOn(channel, 42, vel2);
        MidiUSB.flush();
        flg17 = true;
      }
      if(buttonByte == 7 && flg18 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G
      {
        noteOn(channel, 43, vel2);
        MidiUSB.flush();
        flg18 = true;
      }
      if(buttonByte == 15 && flg19 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#
      {
        noteOn(channel, 44, vel2);
        MidiUSB.flush();
        flg19 = true;
      }
      if(buttonByte == 3 && flg20 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A
      {
        noteOn(channel, 45, vel2);
        MidiUSB.flush();
        flg20 = true;
      }
      if((buttonByte == 17 || buttonByte == 35 || buttonByte == 33 || buttonByte == 65) && flg21 == false) /////////////////////////////////////////////////////////////////A#
      {
        noteOn(channel, 46, vel2);
        MidiUSB.flush();
        flg21 = true;
      }
      if(buttonByte == 1 && flg22 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B
      { 
        noteOn(channel, 47, vel2);
        MidiUSB.flush();
        flg22 = true;
      }
      if((buttonByte == 2 || buttonByte == 5 || buttonByte == 486 || buttonByte == 21) && flg23 == false) //////////////////////////////////////////////////////////////////C2
      {
        noteOn(channel, 48, vel2);
        MidiUSB.flush();
        flg23 = true;
      }      
      if((buttonByte == 494 || buttonByte == 0) && flg24 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////C#2
      { 
        noteOn(channel, 49, vel2);
        MidiUSB.flush();
        flg24 = true;
      }
      if(buttonByte == 230 && flg41 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D2
      {
        noteOn(channel, 50, vel2);
        MidiUSB.flush();
        flg41 = true;
      }
      if(buttonByte == 742 && flg42 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#2
      {
        noteOn(channel, 51, vel2);
        MidiUSB.flush();
        flg42 = true;
      }
      if(buttonByte == 102 && flg43 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E2
      { 
        noteOn(channel, 52, vel2);
        MidiUSB.flush();
        flg43 = true;
      }
      if(buttonByte == 38 && flg44 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F2
      {
        noteOn(channel, 53, vel2);
        MidiUSB.flush();
        flg44 = true;
      }
      if((buttonByte == 70 || buttonByte == 134 || buttonByte == 166) && flg45 == false) //////////////////////////////////////////////////////////////////////////////////F#2
      {
        noteOn(channel, 54, vel2);
        MidiUSB.flush();
        flg45 = true;
      }
      if((buttonByte == 6 || buttonByte == 263) && flg46 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////G2
      {
        noteOn(channel, 55, vel2);
        MidiUSB.flush();
        flg46 = true;
      }
      if((buttonByte == 14 || buttonByte == 271) && flg47 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////G#2
      {
        noteOn(channel, 56, vel2);
        MidiUSB.flush();
        flg47 = true;
      }
      if(buttonByte == 259 && flg48 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A2
      { 
        noteOn(channel, 57, vel2);
        MidiUSB.flush();
        flg48 = true;
      }
      if((buttonByte == 273 || buttonByte == 291 || buttonByte == 289 || buttonByte == 321) && flg49 == false) ////////////////////////////////////////////////////////////A#2
      {
        noteOn(channel, 58, vel2);
        MidiUSB.flush();
        flg49 = true;
      }
      if(buttonByte == 257 && flg50 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B2
      { 
        noteOn(channel, 59, vel2);
        MidiUSB.flush();
        flg50 = true;
      }
      if((buttonByte == 258 || buttonByte == 261 || buttonByte == 484 || buttonByte == 277) && flg51 == false) /////////////////////////////////////////////////////////////C3
      {
        noteOn(channel, 60, vel2);
        MidiUSB.flush();
        flg51 = true;
      }
      if((buttonByte == 256 || buttonByte == 492) && flg52 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////C#3
      { 
        noteOn(channel, 61, vel2);
        MidiUSB.flush();
        flg52 = true;
      }
      if(buttonByte == 228 && flg53 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D3
      { 
        noteOn(channel, 62, vel2);
        MidiUSB.flush();
        flg53 = true;
      }
      if(buttonByte == 740 && flg54 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#3
      { 
        noteOn(channel, 63, vel2);
        MidiUSB.flush();
        flg54 = true;
      }
      if(buttonByte == 100 && flg55 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E3
      {
        noteOn(channel, 64, vel2);
        MidiUSB.flush();
        flg55 = true;
      }
      if(buttonByte == 36 && flg56 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F3
      { 
        noteOn(channel, 65, vel2);
        MidiUSB.flush();
        flg56 = true;
      }
      if((buttonByte == 68 || buttonByte == 132 || buttonByte == 164) && flg57 == false) //////////////////////////////////////////////////////////////////////////////////F#3
      {
        noteOn(channel, 66, vel2);
        MidiUSB.flush();
        flg57 = true;
      }
      if((buttonByte == 4 || buttonByte == 391) && flg58 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////G3
      {
        noteOn(channel, 67, vel2);
        MidiUSB.flush();
        flg58 = true;
      }
      if((buttonByte == 12 || buttonByte == 399) && flg59 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////G#3
      { 
        noteOn(channel, 68, vel2);
        MidiUSB.flush();
        flg59 = true;
      }
      if(buttonByte == 387 && flg60 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A3
      { 
        noteOn(channel, 69, vel2);
        MidiUSB.flush();
        flg60 = true;
      }
      if((buttonByte == 401 || buttonByte == 419 || buttonByte == 417 || buttonByte == 449) && flg61 == false) ////////////////////////////////////////////////////////////A#3
      {
        noteOn(channel, 70, vel2);
        MidiUSB.flush();
        flg61 = true;
      }
      if(buttonByte == 385 && flg62 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B3
      { 
        noteOn(channel, 71, vel2);
        MidiUSB.flush();
        flg62 = true;
      }
      if((buttonByte == 386 || buttonByte == 389 || buttonByte == 405) && flg63 == false) //////////////////////////////////////////////////////////////////////////////////C4
      {
        noteOn(channel, 72, vel2);
        MidiUSB.flush();
        flg63 = true;
      }
      if(buttonByte == 384 && flg64 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#4
      { 
        noteOn(channel, 73, vel2);
        MidiUSB.flush();
        flg64 = true;
      }   
    }




    if(buttonByte != buttonByteOld || vel < 10 || buttonOctave1 == true || buttonOctave2 == true || buttonOctave3 == true) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-0 OFF
        //&& millis() > changeNoteTick + changeNoteDelay)
    {
    
      if(flg11 == true) /////////////////////////////////////C
      {
        noteOff(channel, 36, 0);
        MidiUSB.flush();
        flg11 = false;
      }
      if(flg12 == true) ////////////////////////////////////C#
      {
        noteOff(channel, 37, 0);
        MidiUSB.flush();
        flg12 = false;
      }
      if(flg13 == true) /////////////////////////////////////D
      {
        noteOff(channel, 38, 0);
        MidiUSB.flush();
        flg13 = false;
      }
      if(flg14 == true) ////////////////////////////////////D#
      {
        noteOff(channel, 39, 0);
        MidiUSB.flush();
        flg14 = false;
      }
      if(flg15 == true) /////////////////////////////////////E 
      {
        noteOff(channel, 40, 0);
        MidiUSB.flush();
        flg15 = false;
      }
      if(flg16 == true) /////////////////////////////////////F
      {
        noteOff(channel, 41, 0);
        MidiUSB.flush();
        flg16 = false;
      }
      if(flg17 == true) ////////////////////////////////////F#
      {
        noteOff(channel, 42, 0);
        MidiUSB.flush();
        flg17 = false;
      }
      if(flg18 == true) /////////////////////////////////////G
      {
        noteOff(channel, 43, 0);
        MidiUSB.flush();
        flg18 = false;
      }
      if(flg19 == true) ////////////////////////////////////G#
      {
        noteOff(channel, 44, 0);
        MidiUSB.flush();
        flg19 = false;
      }
      if(flg20 == true) /////////////////////////////////////A
      {
        noteOff(channel, 45, 0);
        MidiUSB.flush();
        flg20 = false;
      }
      if(flg21 == true) ////////////////////////////////////A#
      {
        noteOff(channel, 46, 0);
        MidiUSB.flush();
        flg21 = false;
      }
      if(flg22 == true) /////////////////////////////////////B
      {
        noteOff(channel, 47, 0);
        MidiUSB.flush();
        flg22 = false;
      }
      if(flg23 == true) /////////////////////////////////////C2
      {
        noteOff(channel, 48, 0);
        MidiUSB.flush();
        flg23 = false;
      }
      if(flg24 == true) ////////////////////////////////////C#2
      {
        noteOff(channel, 49, 0);
        MidiUSB.flush();
        flg24 = false;
      }   
      if(flg41 == true) /////////////////////////////////////D2
      {
        noteOff(channel, 50, 0);
        MidiUSB.flush();
        flg41 = false;
      }
      if(flg42 == true) ////////////////////////////////////D#2
      {
        noteOff(channel, 51, 0);
        MidiUSB.flush();
        flg42 = false;
      }
      if(flg43 == true) /////////////////////////////////////E2
      {
        noteOff(channel, 52, 0);
        MidiUSB.flush();
        flg43 = false;
      }
      if(flg44 == true) /////////////////////////////////////F2
      {
        noteOff(channel, 53, 0);
        MidiUSB.flush();
        flg44 = false;
      }
      if(flg45 == true) ////////////////////////////////////F#2
      {
        noteOff(channel, 54, 0);
        MidiUSB.flush();
        flg45 = false;
      }
      if(flg46 == true) /////////////////////////////////////G2
      {
        noteOff(channel, 55, 0);
        MidiUSB.flush();
        flg46 = false;
      }
      if(flg47 == true) ////////////////////////////////////G#2
      {
        noteOff(channel, 56, 0);
        MidiUSB.flush();
        flg47 = false;
      }
      if(flg48 == true) /////////////////////////////////////A2
      {
        noteOff(channel, 57, 0);
        MidiUSB.flush();
        flg48 = false;
      }
      if(flg49 == true) ////////////////////////////////////A#2
      {
        noteOff(channel, 58, 0);
        MidiUSB.flush();
        flg49 = false;
      }
      if(flg50 == true) /////////////////////////////////////B2
      {
        noteOff(channel, 59, 0);
        MidiUSB.flush();
        flg50 = false;
      }
      if(flg51 == true) /////////////////////////////////////C3
      {
        noteOff(channel, 60, 0);
        MidiUSB.flush();
        flg51 = false;
      }
      if(flg52 == true) ////////////////////////////////////C#3
      {
        noteOff(channel, 61, 0);
        MidiUSB.flush();
        flg52 = false;
      }
      if(flg53 == true) /////////////////////////////////////D3
      {
        noteOff(channel, 62, 0);
        MidiUSB.flush();
        flg53 = false;
      }
      if(flg54 == true) ////////////////////////////////////D#3
      {
        noteOff(channel, 63, 0);
        MidiUSB.flush();
        flg54 = false;
      }
      if(flg55 == true) /////////////////////////////////////E3
      {
        noteOff(channel, 64, 0);
        MidiUSB.flush();
        flg55 = false;
      }
      if(flg56 == true) /////////////////////////////////////F3
      {
        noteOff(channel, 65, 0);
        MidiUSB.flush();
        flg56 = false;
      }
      if(flg57 == true) ////////////////////////////////////F#3
      {
        noteOff(channel, 66, 0);
        MidiUSB.flush();
        flg57 = false;
      }
      if(flg58 == true) /////////////////////////////////////G3
      {
        noteOff(channel, 67, 0);
        MidiUSB.flush();
        flg58 = false;
      }
      if(flg59 == true) ////////////////////////////////////G#3
      {
        noteOff(channel, 68, 0);
        MidiUSB.flush();
        flg59 = false;
      }
      if(flg60 == true) /////////////////////////////////////A3
      { 
        noteOff(channel, 69, 0);
        MidiUSB.flush();
        flg60 = false;
      }
      if(flg61 == true) ////////////////////////////////////A#3
      {
        noteOff(channel, 70, 0);
        MidiUSB.flush();
        flg61 = false;
      }
      if(flg62 == true) /////////////////////////////////////B3
      {
        noteOff(channel, 71, 0);
        MidiUSB.flush();
        flg62 = false;
      }
      if(flg63 == true) /////////////////////////////////////C4
      {
        noteOff(channel, 72, 0);
        MidiUSB.flush();
        flg63 = false;
      }
      if(flg64 == true) ////////////////////////////////////C#4
      {
        noteOff(channel, 73, 0);
        MidiUSB.flush();
        flg64 = false;
      }
      
    }
  

    if(buttonOctave1 == true && vel > 20) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-1 ON
    {  
      
      if(buttonByte == 487 && flg76 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C-O1
      {
        noteOn(channel, 48, vel2);
        MidiUSB.flush();
        flg76 = true;
      }
      if(buttonByte == 495 && flg79 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#-O1
      {
        noteOn(channel, 49, vel2);
        MidiUSB.flush();
        flg79 = true;
      }
      if (buttonByte == 231 && flg82 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D-O1
      {
        noteOn(channel, 50, vel2);
        MidiUSB.flush();
        flg82 = true;
      }
      if(buttonByte == 743 && flg85 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#-O1
      {
        noteOn(channel, 51, vel2);
        MidiUSB.flush();
        flg85 = true;
      }
      if(buttonByte == 103 && flg88 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E-O1
      {
        noteOn(channel, 52, vel2);
        MidiUSB.flush();
        flg88 = true;
      }
      if(buttonByte == 39 && flg91 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F-O1
      {
        noteOn(channel, 53, vel2);
        MidiUSB.flush();
        flg91 = true;
      }
      if((buttonByte == 71 || buttonByte == 135 || buttonByte == 167) && flg94 == false) //////////////////////////////////////////////////////////////////////////////////F#-O1
      {
        noteOn(channel, 54, vel2);
        MidiUSB.flush();
        flg94 = true;
      }
      if(buttonByte == 7 && flg97 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G-O1
      {
        noteOn(channel, 55, vel2);
        MidiUSB.flush();
        flg97 = true;
      }
      if(buttonByte == 15 && flg100 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#-O1
      {
        noteOn(channel, 56, vel2);
        MidiUSB.flush();
        flg100 = true;
      }
      if(buttonByte == 3 && flg103 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A-O1
      {
        noteOn(channel, 57, vel2);
        MidiUSB.flush();
        flg103 = true;
      }
      if((buttonByte == 17 || buttonByte == 35 || buttonByte == 33 || buttonByte == 65) && flg106 == false) ///////////////////////////////////////////////////////////////A#-O1
      {
        noteOn(channel, 58, vel2);
        MidiUSB.flush();
        flg106 = true;
      }
      if(buttonByte == 1 && flg109 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B-O1
      { 
        noteOn(channel, 59, vel2);
        MidiUSB.flush();
        flg109 = true;
      }
      if((buttonByte == 2 || buttonByte == 5 || buttonByte == 486 || buttonByte == 21) && flg112 == false) ////////////////////////////////////////////////////////////////C2-O1
      {
        noteOn(channel, 60, vel2 );
        MidiUSB.flush();
        flg112 = true;
      }
      if((buttonByte == 494 || buttonByte == 0) && flg115 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////C#2-O1
      { 
        noteOn(channel, 61, vel2 );
        MidiUSB.flush();
        flg115 = true;
      }
      if(buttonByte == 230 && flg118 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D2-O1
      {
        noteOn(channel, 62, vel2 );
        MidiUSB.flush();
        flg118 = true;
      }
      if(buttonByte == 742 && flg121 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#2-O1
      {
        noteOn(channel, 63, vel2 );
        MidiUSB.flush();
        flg121 = true;
      }
      if(buttonByte == 102 && flg124 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E2-O1
      { 
        noteOn(channel, 64, vel2 );
        MidiUSB.flush();
        flg124 = true;
      }
      if(buttonByte == 38 && flg127 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F2-O1
      {
        noteOn(channel, 65, vel2 );
        MidiUSB.flush();
        flg127 = true;
      }
      if((buttonByte == 70 || buttonByte == 134 || buttonByte == 166) && flg130 == false) ////////////////////////////////////////////////////////////////////////////////F#2-O1
      {
        noteOn(channel, 66, vel2);
        MidiUSB.flush();
        flg130 = true;
      }
      if((buttonByte == 6 || buttonByte == 263) && flg133 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////G2-O1
      {
        noteOn(channel, 67, vel2);
        MidiUSB.flush();
        flg133 = true;
      }
      if((buttonByte == 14 || buttonByte == 271) && flg136 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////G#2-O1
      {
        noteOn(channel, 68, vel2);
        MidiUSB.flush();
        flg136 = true;
      }
      if(buttonByte == 259 && flg139 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A2-O1
      { 
        noteOn(channel, 69, vel2 );
        MidiUSB.flush();
        flg139 = true;
      }
      if((buttonByte == 273 || buttonByte == 291 || buttonByte == 289 || buttonByte == 321) && flg142 == false) //////////////////////////////////////////////////////////A#2-O1
      {
        noteOn(channel, 70, vel2);
        MidiUSB.flush();
        flg142 = true;
      }
      if(buttonByte == 257 && flg145 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B2-O1
      { 
        noteOn(channel, 71, vel2);
        MidiUSB.flush();
        flg145 = true;
      }
      if((buttonByte == 258 || buttonByte == 261 || buttonByte == 484 || buttonByte == 277) && flg148 == false) ///////////////////////////////////////////////////////////C3-O1
      {
        noteOn(channel, 72, vel2 );
        MidiUSB.flush();
        flg148 = true;
      }
      if((buttonByte == 256 || buttonByte == 492) && flg151 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////C#3-O1
      { 
        noteOn(channel, 73, vel2 );
        MidiUSB.flush();
        flg151 = true;
      }
      if(buttonByte == 228 && flg154 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D3-O1
      { 
        noteOn(channel, 74, vel2 );
        MidiUSB.flush();
        flg154 = true;
      }
      if(buttonByte == 740 && flg157 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#3-O1
      { 
        noteOn(channel, 75, vel2 );
        MidiUSB.flush();
        flg157 = true;
      }
      if(buttonByte == 100 && flg160 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E3-O1
      {
        noteOn(channel, 76, vel2 );
        MidiUSB.flush();
        flg160 = true;
      }
      if(buttonByte == 36 && flg163 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F3-O1
      { 
        noteOn(channel, 77, vel2 );
        MidiUSB.flush();
        flg163 = true;
      }
      if((buttonByte == 68 || buttonByte == 132 || buttonByte == 164) && flg166 == false) ////////////////////////////////////////////////////////////////////////////////F#3-O1
      {
        noteOn(channel, 78, vel2);
        MidiUSB.flush();
        flg166 = true;
      }
      if((buttonByte == 4 || buttonByte == 391) && flg169 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////G3-O1
      {
        noteOn(channel, 79, vel2);
        MidiUSB.flush();
        flg169 = true;
      }
      if((buttonByte == 12 || buttonByte == 399) && flg172 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////G#3-O1
      { 
        noteOn(channel, 80, vel2);
        MidiUSB.flush();
        flg172 = true;
      }
      if(buttonByte == 387 && flg175 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A3-O1
      { 
        noteOn(channel, 81, vel2 );
        MidiUSB.flush();
        flg175 = true;
      }
      if((buttonByte == 401 || buttonByte == 419 || buttonByte == 417 || buttonByte == 449) && flg178 == false) //////////////////////////////////////////////////////////A#3-O1
      {
        noteOn(channel, 82, vel2);
        MidiUSB.flush();
        flg178 = true;
      }
      if(buttonByte == 385 && flg181 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B3-O1
      { 
        noteOn(channel, 83, vel2);
        MidiUSB.flush();
        flg181 = true;
      }
      if((buttonByte == 386 || buttonByte == 389 || buttonByte == 405) && flg184 == false) ////////////////////////////////////////////////////////////////////////////////C4-O1
      {
        noteOn(channel, 84, vel2 );
        MidiUSB.flush();
        flg184 = true;
      }
      if(buttonByte == 384 && flg187 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#4-O1
      { 
        noteOn(channel, 85, vel2 );
        MidiUSB.flush();
        flg187 = true;
      }

    }  





    if(buttonOctave1 == false || buttonByte != buttonByteOld || vel < 10) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-1 OFF
    {
      if(flg76 == true) //////////////////////////////////////C-O1
      {
        noteOff(channel, 48, 0);
        MidiUSB.flush();
        flg76 = false;
      }
      if(flg79 == true) /////////////////////////////////////C#-O1
      {
        noteOff(channel, 49, 0);
        MidiUSB.flush();
        flg79 = false;
      }
      if(flg82 == true) //////////////////////////////////////D-O1
      {
        noteOff(channel, 50, 0);
        MidiUSB.flush();
        flg82 = false;
      }
      if(flg85 == true) /////////////////////////////////////D#-O1
      {
        noteOff(channel, 51, 0);
        MidiUSB.flush();
        flg85 = false;
      }
      if(flg88 == true) //////////////////////////////////////E-O1
      {
        noteOff(channel, 52, 0);
        MidiUSB.flush();
        flg88 = false;
      }
      if(flg91 == true) //////////////////////////////////////F-O1
      {
        noteOff(channel, 53, 0);
        MidiUSB.flush();
        flg91 = false;
      }
      if(flg94 == true) /////////////////////////////////////F#-O1
      {
        noteOff(channel, 54, 0);
        MidiUSB.flush();
        flg94 = false;
      }
      if(flg97 == true) //////////////////////////////////////G-O1
      {
        noteOff(channel, 55, 0);
        MidiUSB.flush();
        flg97 = false;
      }
      if(flg100 == true) ////////////////////////////////////G#-O1
      {
        noteOff(channel, 56, 0);
        MidiUSB.flush();
        flg100 = false;
      }
      if(flg103 == true) /////////////////////////////////////A-O1
      {
        noteOff(channel, 57, 0);
        MidiUSB.flush();
        flg103 = false;
      }
      if(flg106 == true) ////////////////////////////////////A#-O1
      {
        noteOff(channel, 58, 0);
        MidiUSB.flush();
        flg106 = false;
      }
      if(flg109 == true) /////////////////////////////////////B-O1
      {
        noteOff(channel, 59, 0);
        MidiUSB.flush();
        flg109 = false;
      } 
      if(flg112 == true) ////////////////////////////////////C2-O1
      {
        noteOff(channel, 60, 0);
        MidiUSB.flush();
        flg112 = false;
      }
      if(flg115 == true) ///////////////////////////////////C#2-O1
      {
        noteOff(channel, 61, 0);
        MidiUSB.flush();
        flg115 = false;
      }
      if(flg118 == true) ////////////////////////////////////D2-O1
      {
        noteOff(channel, 62, 0);
        MidiUSB.flush();
        flg118 = false;
      }
      if(flg121 == true) ///////////////////////////////////D#2-O1
      {
        noteOff(channel, 63, 0);
        MidiUSB.flush();
        flg121 = false;
      }
      if(flg124 == true) ////////////////////////////////////E2-O1
      {
        noteOff(channel, 64, 0);
        MidiUSB.flush();
        flg124 = false;
      }
      if(flg127 == true) ///////////////////////////////////F2-O1
      {
        noteOff(channel, 65, 0);
        MidiUSB.flush();
        flg127 = false;
      }
      if(flg130 == true) ///////////////////////////////////F#2-O1
      {
        noteOff(channel, 66, 0);
        MidiUSB.flush();
        flg130 = false;
      }
      if(flg133 == true) ////////////////////////////////////G2-O1
      {
        noteOff(channel, 67, 0);
        MidiUSB.flush();
        flg133 = false;
      }
      if(flg136 == true) ///////////////////////////////////G#2-O1
      {
        noteOff(channel, 68, 0);
        MidiUSB.flush();
        flg136 = false;
      }
      if(flg139 == true) ////////////////////////////////////A2-O1
      {
        noteOff(channel, 69, 0);
        MidiUSB.flush();
        flg139 = false;
      }
      if(flg142 == true) ///////////////////////////////////A#2-O1
      {
        noteOff(channel, 70, 0);
        MidiUSB.flush();
        flg142 = false;
      }
      if(flg145 == true) ////////////////////////////////////B2-O1
      {
        noteOff(channel, 71, 0);
        MidiUSB.flush();
        flg145 = false;
      }
      if(flg148 == true) ////////////////////////////////////C3-O1
      {
        noteOff(channel, 72, 0);
        MidiUSB.flush();
        flg148 = false;
      }
      if(flg151 == true) ///////////////////////////////////C#3-O1
      {
        noteOff(channel, 73, 0);
        MidiUSB.flush();
        flg151 = false;
      }
      if(flg154 == true) ////////////////////////////////////D3-O1
      {
        noteOff(channel, 74, 0);
        MidiUSB.flush();
        flg154 = false;
      }
      if(flg157 == true) ///////////////////////////////////D#3-O1
      {
        noteOff(channel, 75, 0);
        MidiUSB.flush();
        flg157 = false;
      }
      if(flg160 == true) ////////////////////////////////////E3-O1
      {
        noteOff(channel, 76, 0);
        MidiUSB.flush();
        flg160 = false;
      }
      if(flg163 == true) ////////////////////////////////////F3-O1
      {
        noteOff(channel, 77, 0);
        MidiUSB.flush();
        flg163 = false;
      }
      if(flg166 == true) ///////////////////////////////////F#3-O1
      { 
        noteOff(channel, 78, 0);
        MidiUSB.flush();
        flg166 = false;
      }
      if(flg169 == true) ////////////////////////////////////G3-O1
      {
        noteOff(channel, 79, 0);
        MidiUSB.flush();
        flg169 = false;
      }
      if(flg172 == true) ///////////////////////////////////G#3-O1
      {
        noteOff(channel, 80, 0);
        MidiUSB.flush();
        flg172 = false;
      }
      if(flg175 == true) ////////////////////////////////////A3-O1
      { 
        noteOff(channel, 81, 0);
        MidiUSB.flush();
        flg175 = false;
      }
      if(flg178 == true) ///////////////////////////////////A#3-O1
      {
        noteOff(channel, 82, 0);
        MidiUSB.flush();
        flg178 = false;
      }
      if(flg181 == true) ////////////////////////////////////B3-O1
      {
        noteOff(channel, 83, 0);
        MidiUSB.flush();
        flg181 = false;
      }
      if(flg184 == true) ////////////////////////////////////C4-O1
      {
        noteOff(channel, 84, 0);
        MidiUSB.flush();
        flg184 = false;
      }

      if(flg187 == true) ///////////////////////////////////C#4-O1
      {
        noteOff(channel, 85, 0);
        MidiUSB.flush();
        flg187 = false;
      }

    }

  
    if(buttonOctave2 == true && vel > 20) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-2 ON
    {  
      
      if(buttonByte == 487 && flg77 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C-O2
      {
        noteOn(channel, 60, vel2);
        MidiUSB.flush();
        flg77 = true;
      }
      if(buttonByte == 495 && flg80 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#-O2
      {
        noteOn(channel, 61, vel2);
        MidiUSB.flush();
        flg80 = true;
      }
      if(buttonByte == 231 && flg83 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D-O2
      {
        noteOn(channel, 62, vel2);
        MidiUSB.flush();
        flg83 = true;
      }
      if(buttonByte == 743 && flg86 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#-O2
      {
        noteOn(channel, 63, vel2);
        MidiUSB.flush();
        flg86 = true;
      }
      if(buttonByte == 103 && flg89 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E-O2
      {
        noteOn(channel, 64, vel2);
        MidiUSB.flush();
        flg89 = true;
      }
      if(buttonByte == 39 && flg92 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F-O2
      {
        noteOn(channel, 65, vel2);
        MidiUSB.flush();
        flg92 = true;
      }
      if((buttonByte == 71 || buttonByte == 135 || buttonByte == 167) && flg95 == false)///////////////////////////////////////////////////////////////////////////////////////////F#-O2
      {
        noteOn(channel, 66, vel2);
        MidiUSB.flush();
        flg95 = true;
      }
      if(buttonByte == 7 && flg98 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G-O2
      {
        noteOn(channel, 67, vel2);
        MidiUSB.flush();
        flg98 = true;
      }
      if(buttonByte == 15 && flg101 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#-O2
      {
        noteOn(channel, 68, vel2);
        MidiUSB.flush();
        flg101 = true;
      }
      if(buttonByte == 3 && flg104 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A-O2
      {
        noteOn(channel, 69, vel2);
        MidiUSB.flush();
        flg104 = true;
      }
      if((buttonByte == 17 || buttonByte == 35 || buttonByte == 33 || buttonByte == 65) && flg107 == false) ///////////////////////////////////////////////////////////////////////A#-O2
      {
        noteOn(channel, 70, vel2);
        MidiUSB.flush();
        flg107 = true;
      }
      if(buttonByte == 1 && flg110 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B-O2
      { 
        noteOn(channel, 71, vel2);
        MidiUSB.flush();
        flg110 = true;
      }
      if((buttonByte == 2 || buttonByte == 5 || buttonByte == 486 || buttonByte == 21) && flg113 == false) ////////////////////////////////////////////////////////////////////////C2-O2
      {
        noteOn(channel, 72, vel2 );
        MidiUSB.flush();
        flg113 = true;
      }
      if((buttonByte == 494 || buttonByte == 0) && flg116 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////C#2-O2
      { 
        noteOn(channel, 73, vel2 );
        MidiUSB.flush();
        flg116 = true;
      }
      if(buttonByte == 230 && flg119 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D2-O2
      {
        noteOn(channel, 74, vel2 );
        MidiUSB.flush();
        flg119 = true;
      }
      if(buttonByte == 742 && flg122 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#2-O2
      {
        noteOn(channel, 75, vel2 );
        MidiUSB.flush();
        flg122 = true;
      }
      if(buttonByte == 102 && flg125 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E2-O2
      { 
        noteOn(channel, 76, vel2 );
        MidiUSB.flush();
        flg125 = true;
      }
      if(buttonByte == 38 && flg128 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F2-O2
      {
        noteOn(channel, 77, vel2 );
        MidiUSB.flush();
        flg128 = true;
      }
      if((buttonByte == 70 || buttonByte == 134 || buttonByte == 166) && flg131 == false) ////////////////////////////////////////////////////////////////////////////////////////F#2-O2
      {
        noteOn(channel, 78, vel2);
        MidiUSB.flush();
        flg131 = true;
      }
      if((buttonByte == 6 || buttonByte == 263) && flg134 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////G2-O2
      {
        noteOn(channel, 79, vel2);
        MidiUSB.flush();
        flg134 = true;
      }
      if((buttonByte == 14 || buttonByte == 271) && flg137 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////G#2-O2
      {
        noteOn(channel, 80, vel2);
        MidiUSB.flush();
        flg137 = true;
      }
      if(buttonByte == 259 && flg140 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A2-O2
      { 
        noteOn(channel, 81, vel2 );
        MidiUSB.flush();
        flg140 = true;
      }
      if((buttonByte == 273 || buttonByte == 291 || buttonByte == 289 || buttonByte == 321) && flg143 == false) //////////////////////////////////////////////////////////////////A#2-O2
      {
        noteOn(channel, 82, vel2);
        MidiUSB.flush();
        flg143 = true;
      }
      if(buttonByte == 257 && flg146 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B2-O2
      { 
        noteOn(channel, 83, vel2);
        MidiUSB.flush();
        flg146 = true;
      }
      if((buttonByte == 258 || buttonByte == 261 || buttonByte == 484 || buttonByte == 277) && flg149 == false) ///////////////////////////////////////////////////////////////////C3-O2
      {
        noteOn(channel, 84, vel2 );
        MidiUSB.flush();
        flg149 = true;
      }
      if((buttonByte == 256 || buttonByte == 492) && flg152 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////C#3-O2
      { 
        noteOn(channel, 85, vel2 );
        MidiUSB.flush();
        flg152 = true;
      }
      if(buttonByte == 228 && flg155 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D3-O2
      { 
        noteOn(channel, 86, vel2 );
        MidiUSB.flush();
        flg155 = true;
      }
      if(buttonByte == 740 && flg158 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#2-O2
      { 
        noteOn(channel, 87, vel2 );
        MidiUSB.flush();
        flg158 = true;
      }
      if(buttonByte == 100 && flg161 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E3-O2
      {
        noteOn(channel, 88, vel2 );
        MidiUSB.flush();
        flg161 = true;
      }
      if(buttonByte == 36 && flg164 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F3-O2
      { 
        noteOn(channel, 89, vel2 );
        MidiUSB.flush();
        flg164 = true;
      }
      if((buttonByte == 68 || buttonByte == 132 || buttonByte == 164) && flg167 == false) ////////////////////////////////////////////////////////////////////////////////////////F#3-O2
      {
        noteOn(channel, 90, vel2);
        MidiUSB.flush();
        flg167 = true;
      }
      if((buttonByte == 4 || buttonByte == 391) && flg170 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////G3-O2
      {
        noteOn(channel, 91, vel2);
        MidiUSB.flush();
        flg170 = true;
      }
      if((buttonByte == 12 || buttonByte == 399) && flg173 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////G#3-O2
      { 
        noteOn(channel, 92, vel2);
        MidiUSB.flush();
        flg173 = true;
      }
      if(buttonByte == 387 && flg176 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A3-O2
      { 
        noteOn(channel, 93, vel2 );
        MidiUSB.flush();
        flg176 = true;
      }
      if((buttonByte == 401 || buttonByte == 419 || buttonByte == 417 || buttonByte == 449) && flg179 == false) //////////////////////////////////////////////////////////////////A#3-O2
      {
        noteOn(channel, 94, vel2);
        MidiUSB.flush();
        flg179 = true;
      }
      if(buttonByte == 385 && flg182 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B3-O2
      { 
        noteOn(channel, 95, vel2);
        MidiUSB.flush();
        flg182 = true;
      }
      if((buttonByte == 386 || buttonByte == 389 || buttonByte == 405) && flg185 == false) ////////////////////////////////////////////////////////////////////////////////////////C4-O2
      {
        noteOn(channel, 96, vel2 );
        MidiUSB.flush();
        flg185 = true;
      }
      if(buttonByte == 384 && flg188 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#4-O2
      { 
        noteOn(channel, 97, vel2 );
        MidiUSB.flush();
        flg188 = true;
      }

    }

    if(buttonOctave2 == false || buttonByte != buttonByteOld || vel < 10) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-2 OFF
    {
      
      if(flg77 == true) //////////////////////////////////////C-O2
      {
        noteOff(channel, 60, 0);
        MidiUSB.flush();
        flg77 = false;
      }
      if(flg80 == true) /////////////////////////////////////C#-O2
      {
        noteOff(channel, 61, 0);
        MidiUSB.flush();
        flg80 = false;
      }
      if(flg83 == true) //////////////////////////////////////D-O2
      {
        noteOff(channel, 62, 0);
        MidiUSB.flush();
        flg83 = false;
      }    
      if(flg86 == true) /////////////////////////////////////D#-O2
      {
        noteOff(channel, 63, 0);
        MidiUSB.flush();
        flg86 = false;
      }
      if(flg89 == true) //////////////////////////////////////E-O2
      {
        noteOff(channel, 64, 0);
        MidiUSB.flush();
        flg89 = false;
      }
      if(flg92 == true) //////////////////////////////////////F-O2
      {
        noteOff(channel, 65, 0);
        MidiUSB.flush();
        flg92 = false;
      }
      if(flg95 == true) /////////////////////////////////////F#-O2
      {
        noteOff(channel, 66, 0);
        MidiUSB.flush();
        flg95 = false;
      }
      if(flg98 == true) //////////////////////////////////////G-O2
      {
        noteOff(channel, 67, 0);
        MidiUSB.flush();
        flg98 = false;
      }
      if(flg101 == true) ////////////////////////////////////G#-O2
      {
        noteOff(channel, 68, 0);
        MidiUSB.flush();
        flg101 = false;
      }
      if(flg104 == true) /////////////////////////////////////A-O2
      {
        noteOff(channel, 69, 0);
        MidiUSB.flush();
        flg104 = false;
      }
      if(flg107 == true) ////////////////////////////////////A#-O2
      {
        noteOff(channel, 70, 0);
        MidiUSB.flush();
        flg107 = false;
      }
      if(flg110 == true) /////////////////////////////////////B-O2
      {
        noteOff(channel, 71, 0);
        MidiUSB.flush();
        flg110 = false;
      } 
      if(flg113 == true) ////////////////////////////////////C2-O2
      {
        noteOff(channel, 72, 0);
        MidiUSB.flush();
        flg113 = false;
      }
      if(flg116 == true) ///////////////////////////////////C#2-O2
      {
        noteOff(channel, 73, 0);
        MidiUSB.flush();
        flg116 = false;
      }    
      if(flg119 == true) ////////////////////////////////////D2-O2
      {
        noteOff(channel, 74, 0);
        MidiUSB.flush();
        flg119 = false;
      }
      if(flg122 == true) ///////////////////////////////////D#2-O2
      {
        noteOff(channel, 75, 0);
        MidiUSB.flush();
        flg122 = false;
      }
      if(flg125 == true) ////////////////////////////////////E2-O2
      {
        noteOff(channel, 76, 0);
        MidiUSB.flush();
        flg125 = false;
      }
      if(flg128 == true) ////////////////////////////////////F2-O2
      {
        noteOff(channel, 77, 0);
        MidiUSB.flush();
        flg128 = false;
      }
      if(flg131 == true) ///////////////////////////////////F#2-O2
      {
        noteOff(channel, 78, 0);
        MidiUSB.flush();
        flg131 = false;
      }
      if(flg134 == true) ////////////////////////////////////G2-O2
      {
        noteOff(channel, 79, 0);
        MidiUSB.flush();
        flg134 = false;
      }
      if(flg137 == true) ///////////////////////////////////G#2-O2
      {
        noteOff(channel, 80, 0);
        MidiUSB.flush();
        flg137 = false;
      }
      if(flg140 == true) ////////////////////////////////////A2-O2
      {
        noteOff(channel, 81, 0);
        MidiUSB.flush();
        flg140 = false;
      }
      if(flg143 == true) ///////////////////////////////////A#2-O2
      {
        noteOff(channel, 82, 0);
        MidiUSB.flush();
        flg143 = false;
      }
      if(flg146 == true) ////////////////////////////////////B2-O2
      {
        noteOff(channel, 83, 0);
        MidiUSB.flush();
        flg146 = false;
      }
      if(flg149 == true) ////////////////////////////////////C3-O2
      {
        noteOff(channel, 84, 0);
        MidiUSB.flush();
        flg149 = false;
      }
      if(flg152 == true) ///////////////////////////////////C#3-O2
      {
        noteOff(channel, 85, 0);
        MidiUSB.flush();
        flg152 = false;
      }
      if(flg155 == true) ////////////////////////////////////D3-O2
      {
        noteOff(channel, 86, 0);
        MidiUSB.flush();
        flg155 = false;
      }
      if(flg158 == true) ///////////////////////////////////D#3-O2
      {
        noteOff(channel, 87, 0);
        MidiUSB.flush();
        flg158 = false;
      }
      if(flg161 == true) ////////////////////////////////////E3-O2
      {
        noteOff(channel, 88, 0);
        MidiUSB.flush();
        flg161 = false;
      }
      if(flg164 == true) ////////////////////////////////////F3-O2
      {
        noteOff(channel, 89, 0);
        MidiUSB.flush();
        flg164 = false;
      }
      if(flg167 == true) ///////////////////////////////////F#3-O2
      {
        noteOff(channel, 90, 0);
        MidiUSB.flush();
        flg167 = false;
      }
      if(flg170 == true) ////////////////////////////////////G3-O2
      {
        noteOff(channel, 91, 0);
        MidiUSB.flush();
        flg170 = false;
      }
      if(flg173 == true) ///////////////////////////////////G#3-O2
      {
        noteOff(channel, 92, 0);
        MidiUSB.flush();
        flg173 = false;
      }
      if(flg176 == true) ////////////////////////////////////A3-O2
      { 
        noteOff(channel, 93, 0);
        MidiUSB.flush();
        flg176 = false;
      }
      if(flg179 == true) ///////////////////////////////////A#3-O2
      {
        noteOff(channel, 94, 0);
        MidiUSB.flush();
        flg179 = false;
      }
      if(flg182 == true) ////////////////////////////////////B3-O2
      {
        noteOff(channel, 95, 0);
        MidiUSB.flush();
        flg182 = false;
      }
      if(flg185 == true) ////////////////////////////////////C4-O2
      {
        noteOff(channel, 96, 0);
        MidiUSB.flush();
        flg185 = false;
      }
      if(flg188 == true) ///////////////////////////////////C#4-O2
      {
        noteOff(channel, 97, 0);
        MidiUSB.flush();
        flg188 = false;
      }

    }


    if(buttonOctave3 == true && vel > 20) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-3 ON
    {   
      
      if((buttonByte == 487) && flg78 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C-O3
      {
        noteOn(channel, 72, vel2);
        MidiUSB.flush();
        flg78 = true;
      }
      if((buttonByte == 495) && flg81 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#-O3
      {
        noteOn(channel, 73, vel2);
        MidiUSB.flush();
        flg81 = true;
      }
      if(buttonByte == 231 && flg84 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D-O3
      {
        noteOn(channel, 74, vel2);
        MidiUSB.flush();
        flg84 = true;
      }
      if(buttonByte == 743 && flg87 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#-O3
      {
        noteOn(channel, 75, vel2);
        MidiUSB.flush();
        flg87 = true;
      }
      if(buttonByte == 103 && flg90 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E-O3
      {
        noteOn(channel, 76, vel2);
        MidiUSB.flush();
        flg90 = true;
      }
      if(buttonByte == 39 && flg93 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F-O3
      {
        noteOn(channel, 77, vel2);
        MidiUSB.flush();
        flg93 = true;
      }
      if((buttonByte == 71 || buttonByte == 135 || buttonByte == 167) && flg96 == false) //////////////////////////////////////////////////////////////////////////////////////////////F#-O3
           
      {
        noteOn(channel, 78, vel2);
        MidiUSB.flush();
        flg96 = true;
      }
      if((buttonByte == 7) && flg99 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G-O3
      {
        noteOn(channel, 79, vel2);
        MidiUSB.flush();
        flg99 = true;
      }
      if((buttonByte == 15) && flg102 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#-O3
      {
        noteOn(channel, 80, vel2);
        MidiUSB.flush();
        flg102 = true;
      }
      if((buttonByte == 3) && flg105 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A-O3
      {
        noteOn(channel, 81, vel2);
        MidiUSB.flush();
        flg105 = true;
      }
      if((buttonByte == 17 || buttonByte == 35 || buttonByte == 33 || buttonByte == 65) && flg108 == false) ///////////////////////////////////////////////////////////////////////////A#-O3
      {
        noteOn(channel, 82, vel2);
        MidiUSB.flush();
        flg108 = true;
      }
      if(buttonByte == 1 && flg111 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B-O3
      { 
        noteOn(channel, 83, vel2);
        MidiUSB.flush();
        flg111 = true;
      }
      if((buttonByte == 2 || buttonByte == 5 || buttonByte == 486 || buttonByte == 21) && flg114 == false) ////////////////////////////////////////////////////////////////////////////C2-O3
      {
        noteOn(channel, 84, vel2 );
        MidiUSB.flush();
        flg114 = true;
      }
      if((buttonByte == 494 || buttonByte == 0) && flg117 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#2-O3
      { 
        noteOn(channel, 85, vel2 );
        MidiUSB.flush();
        flg117 = true;
      }
      if(buttonByte == 230 && flg120 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D2-O3
      {
        noteOn(channel, 86, vel2 );
        MidiUSB.flush();
        flg120 = true;
      }
      if(buttonByte == 742 && flg123 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#2-O3
      {
        noteOn(channel, 87, vel2 );
        MidiUSB.flush();
        flg123 = true;
      }
      if(buttonByte == 102 && flg126 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E2-O3
      { 
        noteOn(channel, 88, vel2 );
        MidiUSB.flush();
        flg126 = true;
      }
      if(buttonByte == 38 && flg129 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F2-O3
      {
        noteOn(channel, 89, vel2 );
        MidiUSB.flush();
        flg129 = true;
      }
      if((buttonByte == 70 || buttonByte == 134 || buttonByte == 166) && flg132 == false) ////////////////////////////////////////////////////////////////////////////////////////////F#2-O3
      {
        noteOn(channel, 90, vel2);
        MidiUSB.flush();
        flg132 = true;
      }
      if((buttonByte == 6 || buttonByte == 263) && flg135 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////G2-O3
      {
        noteOn(channel, 91, vel2);
        MidiUSB.flush();
        flg135 = true;
      }
      if((buttonByte == 14 || buttonByte == 271) && flg138 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#2-O3
      {
        noteOn(channel, 92, vel2);
        MidiUSB.flush();
        flg138 = true;
      }
      if((buttonByte == 259) && flg141 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A2-O3
      { 
        noteOn(channel, 93, vel2 );
        MidiUSB.flush();
        flg141 = true;
      }
      if((buttonByte == 273 || buttonByte == 291 || buttonByte == 289 || buttonByte == 321) && flg144 == false) //////////////////////////////////////////////////////////////////////A#2-O3
      {
        noteOn(channel, 94, vel2);
        MidiUSB.flush();
        flg144 = true;
      }
      if(buttonByte == 257 && flg147 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B2-O3
      { 
        noteOn(channel, 95, vel2);
        MidiUSB.flush();
        flg147 = true;
      }
      if((buttonByte == 258 || buttonByte == 261 || buttonByte == 484 || buttonByte == 277) && flg150 == false) ///////////////////////////////////////////////////////////////////////C3-O3
      {
        noteOn(channel, 96, vel2 );
        MidiUSB.flush();
        flg150 = true;
      }
      if((buttonByte == 256 || buttonByte == 492) && flg153 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#3-O3
      { 
        noteOn(channel, 97, vel2 );
        MidiUSB.flush();
        flg153 = true;
      }
      if(buttonByte == 228 && flg156 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D3-O3
      { 
        noteOn(channel, 98, vel2 );
        MidiUSB.flush();
        flg156 = true;
      }
      if(buttonByte == 740 && flg159 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////D#3-O3
      { 
        noteOn(channel, 99, vel2 );
        MidiUSB.flush();
        flg159 = true;
      }
      if(buttonByte == 100 && flg162 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////E3-O3
      {
        noteOn(channel, 100, vel2 );
        MidiUSB.flush();
        flg162 = true;
      }
      if(buttonByte == 36 && flg165 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////F3-O3
      { 
        noteOn(channel, 101, vel2 );
        MidiUSB.flush();
        flg165 = true;
      }
      if((buttonByte == 68 || buttonByte == 132 || buttonByte == 164) && flg168 == false) ////////////////////////////////////////////////////////////////////////////////////////////F#3-O3
          
      {
        noteOn(channel, 102, vel2);
        MidiUSB.flush();
        flg168 = true;
      }
      if((buttonByte == 4 || buttonByte == 391) && flg171 == false)  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////G3-O3
      {
        noteOn(channel, 103, vel2);
        MidiUSB.flush();
        flg171 = true;
      }
      if((buttonByte == 12 || buttonByte == 399) && flg174 == false) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////G#3-O3
      { 
        noteOn(channel, 104, vel2);
        MidiUSB.flush();
        flg174 = true;
      }
      if((buttonByte == 387) && flg177 == false) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////A3-O3
      { 
        noteOn(channel, 105, vel2 );
        MidiUSB.flush();
        flg177 = true;
      }
      if((buttonByte == 401 || buttonByte == 419 || buttonByte == 417 || buttonByte == 449) && flg180 == false) //////////////////////////////////////////////////////////////////////A#3-O3
      {
        noteOn(channel, 106, vel2);
        MidiUSB.flush();
        flg180 = true;
      }
      if(buttonByte == 385 && flg183 == false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////B3-O3
      { 
        noteOn(channel, 107, vel2);
        MidiUSB.flush();
        flg183 = true;
      }
      if((buttonByte == 386 || buttonByte == 389 || buttonByte == 405) && flg186 == false) ////////////////////////////////////////////////////////////////////////////////////////////C4-O3
      {
        noteOn(channel, 108, vel2 );
        MidiUSB.flush();
        flg186 = true;
      }
      if(buttonByte == 384 && flg189 == false) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////C#4-O3
      { 
        noteOn(channel, 109, vel2 );
        MidiUSB.flush();
        flg189 = true;
      }

    }
   
    if(buttonOctave3 == false || buttonByte != buttonByteOld  || vel < 10) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////O-3 OFF
    {
      
      if(flg78 == true) ///////////////////////////////////////C-O3
      {
        noteOff(channel, 72, 0);
        MidiUSB.flush();
        flg78 = false;
      }
      if(flg81 == true) //////////////////////////////////////C#-O3
      {
        noteOff(channel, 73, 0);
        MidiUSB.flush();
        flg81 = false;
      }
      if(flg84 == true) ///////////////////////////////////////D-O3
      {
        noteOff(channel, 74, 0);
        MidiUSB.flush();
        flg84 = false;
      }
      if(flg87 == true) //////////////////////////////////////D#-O3
      {
        noteOff(channel, 75, 0);
        MidiUSB.flush();
        flg87 = false;
      }
      if(flg90 == true) ///////////////////////////////////////E-O3
      {
        noteOff(channel, 76, 0);
        MidiUSB.flush();
        flg90 = false;
      }
      if(flg93 == true) ///////////////////////////////////////F-O3
      {
        noteOff(channel, 77, 0);
        MidiUSB.flush();
        flg93 = false;
      }
      if(flg96 == true) //////////////////////////////////////F#-O3
      {
        noteOff(channel, 78, 0);
        MidiUSB.flush();
        flg96 = false;
      }
      if(flg99 == true) ///////////////////////////////////////G-O3
      {
        noteOff(channel, 79, 0);
        MidiUSB.flush();
        flg99 = false;
      }
      if(flg102 == true) /////////////////////////////////////G#-O3
      {
        noteOff(channel, 80, 0);
        MidiUSB.flush();
        flg102 = false;
      }
      if(flg105 == true)///////////////////////////////////////A-O3
      {
        noteOff(channel, 81, 0);
        MidiUSB.flush();
        flg105 = false;
      }
      if(flg108 == true) /////////////////////////////////////A#-O3
      {
        noteOff(channel, 82, 0);
        MidiUSB.flush();
        flg108 = false;
      }
      if(flg111 == true) //////////////////////////////////////B-O3
      {
        noteOff(channel, 83, 0);
        MidiUSB.flush();
        flg111 = false;
      }
      if(flg114 == true)//////////////////////////////////////C2-O3
      {
        noteOff(channel, 84, 0);
        MidiUSB.flush();
        flg114 = false;
      }
      if(flg117 == true) ////////////////////////////////////C#2-O3
      {
        noteOff(channel, 85, 0);
        MidiUSB.flush();
        flg117 = false;
      }
      if(flg120 == true) /////////////////////////////////////D2-O3
      {
        noteOff(channel, 86, 0);
        MidiUSB.flush();
        flg120 = false;
      }
      if(flg123 == true) ////////////////////////////////////D#2-O3
      {
        noteOff(channel, 87, 0);
        MidiUSB.flush();
        flg123 = false;
      }
      if(flg126 == true) /////////////////////////////////////E2-O3
      {
        noteOff(channel, 88, 0);
        MidiUSB.flush();
        flg126 = false;
      }
      if(flg129 == true) /////////////////////////////////////F2-O3
      {
        noteOff(channel, 89, 0);
        MidiUSB.flush();
        flg129 = false;
      }
      if(flg132 == true) ////////////////////////////////////F#2-O3
      {
        noteOff(channel, 90, 0);
        MidiUSB.flush();
        flg132 = false;
      }
      if(flg135 == true) /////////////////////////////////////G2-O3
      {
        noteOff(channel, 91, 0);
        MidiUSB.flush();
        flg135 = false;
      }
      if(flg138 == true) ////////////////////////////////////G#2-O3
      {
        noteOff(channel, 92, 0);
        MidiUSB.flush();
        flg138 = false;
      }
      if(flg141 == true) /////////////////////////////////////A2-O3
      {
        noteOff(channel, 93, 0);
        MidiUSB.flush();
        flg141 = false;
      }
      if(flg144 == true) ////////////////////////////////////A#2-O3
      {
        noteOff(channel, 94, 0);
        MidiUSB.flush();
        flg144 = false;
      }
      if(flg147 == true) /////////////////////////////////////B2-O3
      {
        noteOff(channel, 95, 0);
        MidiUSB.flush();
        flg147 = false;
      }
      if(flg150 == true) /////////////////////////////////////C3-O3
      {
        noteOff(channel, 96, 0);
        MidiUSB.flush();
        flg150 = false;
      }
      if(flg153 == true) ////////////////////////////////////C#3-O3
      {
        noteOff(channel, 97, 0);
        MidiUSB.flush();
        flg153 = false;
      }
      if(flg156 == true) /////////////////////////////////////D3-O3
      {
        noteOff(channel, 98, 0);
        MidiUSB.flush();
        flg156 = false;
      }
      if(flg159 == true) ////////////////////////////////////D#3-O3
      {
        noteOff(channel, 99, 0);
        MidiUSB.flush();
        flg159 = false;
      }
      if(flg162 == true) /////////////////////////////////////E3-O3
      {
        noteOff(channel, 100, 0);
        MidiUSB.flush();
        flg162 = false;
      }
      if(flg165 == true) /////////////////////////////////////F3-O3
      {
        noteOff(channel, 101, 0);
        MidiUSB.flush();
        flg165 = false;
      }
      if(flg168 == true) ////////////////////////////////////F#3-O3
      {
        noteOff(channel, 102, 0);
        MidiUSB.flush();
        flg168 = false;
      }
      if(flg171 == true) /////////////////////////////////////G3-O3
      {
        noteOff(channel, 103, 0);
        MidiUSB.flush();
        flg171 = false;
      }
      if(flg174 == true) ////////////////////////////////////G#3-O3
      { 
        noteOff(channel, 104, 0);
        MidiUSB.flush();
        flg174 = false;
      }
      if(flg177 == true) /////////////////////////////////////A3-O3
      { 
        noteOff(channel, 105, 0);
        MidiUSB.flush();
        flg177 = false;
      }
      if(flg180 == true) ////////////////////////////////////A#3-O3
      {
        noteOff(channel, 106, 0);
        MidiUSB.flush();
        flg180 = false;
      }
      if(flg183 == true) /////////////////////////////////////B3-O3
      {
        noteOff(channel, 107, 0);
        MidiUSB.flush();
        flg183 = false;
      }
      if(flg186 == true) /////////////////////////////////////C4-O3
      {
        noteOff(channel, 108, 0);
        MidiUSB.flush();
        flg186 = false;
      }
      if(flg189 == true) ////////////////////////////////////C#4-O3
      {
        noteOff(channel, 109, 0);
        MidiUSB.flush();
        flg189 = false;
      }
    }

    //if(millis() > changeNoteTick + changeNoteDelay)
    //{      
      buttonByteOld = buttonByte;
    //}
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// pressure
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(vel2 != velOld) ///////////////////////////////////////// breath Control
  {
    controlChange(channel, 2, vel2);
    MidiUSB.flush();
  }
  if(vel2 != velOld) ///////////////////////////////////////// Expression Controller
  {
    controlChange(channel, 11, vel2);
    MidiUSB.flush();
  }
  if(vel2 != velOld) ///////////////////////////////////////// Volume Control
  {
    controlChange(channel, 7, vel2);
    MidiUSB.flush();
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Giroscopi mapeig
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  giroXd2 = map(giroXd, 0, 255, 127, 0);
  giroYd2 = map(giroYd, 20, 255, 0, 127);
  giroYdPB = map(giroYd, 20, 255, 16380, 0);

  giroXe2 = map(giroXe, 0, 255, 127, 0);
  giroYe2 = map(giroYe, 20, 255, 0, 127);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Giroscopi histeresi
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(giroYd2 >= 0 && giroYd2 <= 50)////////////////////////////////////////// Y Right
  {
    giroYd3 = map(giroYd2, 0, 50, 0, 64); 
    giroYd3Old = giroYd3;   
  }
  else if(giroYd2 >= 75 && giroYd2 <= 127)
  {
    giroYd3 = map(giroYd2, 75, 127, 64, 127); 
    giroYd3Old = giroYd3;
  }
  else
  {
    giroYd3 = giroYd3Old;
  }
  if(giroYd3Old2 < 40 && giroYd3 > 70) 
  {
    giroYd3 = giroYd3Old2;
  }

////////////////////////////////////////////////////////
// giroYdPB = map(giroYd3, 127, 0, 16380, 0);
////////////////////////////////////////////////////////

  
  if(giroYdPB >= 0 && giroYdPB <= 6900)/////////////////////////// Y Right Pitch Bend
  {
    giroYdPB2 = map(giroYdPB, 0, 6900, 0, 8190); 
    giroYdPB2Old = giroYdPB2;   
  }
  else if(giroYdPB >= 9800 && giroYdPB <= 16380)
  {
    giroYdPB2 = map(giroYdPB, 9800, 16380, 8190, 16380); 
    giroYdPB2Old = giroYdPB2;
  }
  else
  {
    giroYdPB2 = giroYdPB2Old;
  }
  if(giroYdPB2Old2 > 9000 && giroYdPB2 < 6000) 
  {
    giroYdPB2 = giroYdPB2Old2;
  }
    
  if(giroYe2 >= 0 && giroYe2 <= 55)/////////////////////////////////////////// Y Left
  {
    giroYe3 = map(giroYe2, 0, 55, 0, 64); 
    giroYe3Old = giroYe3;   
  }
  else if(giroYe2 >= 85 && giroYe2 <= 127)
  {
    giroYe3 = map(giroYe2, 85, 127, 64, 127); 
    giroYe3Old = giroYe3;
  }
  else
  {
    giroYe3 = giroYe3Old;
  }
  if(giroYe3Old2 < 40 && giroYe3 > 70)
  {
    giroYe3 = giroYe3Old2;
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Giroscopis control
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


  if(F2 == true) /////////////////////////////////////////////// F2
  {      
    if(giroXd != giroXdOld || flgF2 == false) 
    { 
      controlChange(channel, 107, giroXd2);
      MidiUSB.flush();
    }
    if(giroYd != giroYdOld) 
    {
      controlChange(channel, 106, giroYd3);
      MidiUSB.flush();
    }
    if(giroXe != giroXeOld || flgF2 == false) 
    { 
      controlChange(channel, 109, giroXe2);
      MidiUSB.flush();
    }
    if(giroYe != giroYeOld) 
    {
      controlChange(channel, 108, giroYe3);
      MidiUSB.flush();
    }
    
    flgF2 = true;
  }
  if(F2 == false && flgF2 == true)
  {
    flgF2 = false;

    controlChange(channel, 106, 64);
    MidiUSB.flush();

    controlChange(channel, 108, 64);
    MidiUSB.flush();
    
    giroYd3Old = giroYd3 = 64;
    giroYe3Old = giroYe3 = 64;    
  }

  if(F3 == true) /////////////////////////////////////////////// F3
  {  
    if(giroXd != giroXdOld || flgF3 == false) 
    {
      controlChange(channel, 1, giroXd2);
      MidiUSB.flush();
    }
    if(giroYd != giroYdOld)
    {
      pitchBendChange(channel, giroYdPB2);
      MidiUSB.flush();
    }
    if(giroXe != giroXeOld || flgF3 == false) 
    { 
      controlChange(channel, 5, giroXe2);
      MidiUSB.flush();
    }
    if(giroYe != giroYeOld) 
    {
      controlChange(channel, 12, giroYe3);
      MidiUSB.flush();
    }
        
    flgF3 = true;
  }
  if(F3 == false && flgF3 == true)
  {
    flgF3 = false;
    

    pitchBendChange(channel, 8000);
    MidiUSB.flush();
    
    controlChange(channel, 12, 64);
    MidiUSB.flush();

    giroYd3Old = giroYd3 = 64;
    giroYe3Old = giroYe3 = 64;
    giroYdPB2Old = giroYdPB2  = 8190;
  }

  if(S2O3 == true) //////////////////////////////////////////// S2+O3
  {  
    if(giroXd != giroXdOld || flgS2O3 == false) 
    { 
      controlChange(0, 115, giroXd2);
      MidiUSB.flush();
    }
    if(giroYd != giroYdOld) 
    {
      controlChange(0, 116, giroYd3);
      MidiUSB.flush();
    }
    if(giroXe != giroXeOld || flgS2O3 == false) 
    { 
      controlChange(0, 117, giroXe2);
      MidiUSB.flush();
    }
    if(giroYe != giroYeOld) 
    {
      controlChange(0, 118, giroYe3);
      MidiUSB.flush();
    }    

    flgS2O3 = true;
  }
  if(S2O3 == false && flgS2O3 == true)
  {
    flgS2O3 = false;

    controlChange(0, 116, 64);
    MidiUSB.flush();

    controlChange(0, 118, 64);
    MidiUSB.flush();
    
    giroYd3Old = giroYd3 = 64;
    giroYe3Old = giroYe3 = 64;   
  }


  

  // assing actual states
  velOld = vel2 ;
  giroXdOld = giroXd;
  giroYdOld = giroYd;
  giroXeOld = giroXe;
  giroYeOld = giroYe;

  giroYd3Old2 = giroYd3;
  giroYe3Old2 = giroYe3;
  giroYdPB2Old2 = giroYdPB2;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                            fi
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////// Debug CODE /////////////
/*

            
      Serial.print("Y Dreta: "); ////debug
      Serial.print(giroYd, DEC);
      Serial.print(" -- "); 
      Serial.print(giroYd3, DEC);
      Serial.print(" -- "); 
      Serial.print(giroYdPB2, DEC);

      Serial.print(" Y Esquerra: "); 
      Serial.print(giroYe, DEC); ////debug
      Serial.print(" -- "); 
      Serial.println(giroYe3, DEC);


*/      
