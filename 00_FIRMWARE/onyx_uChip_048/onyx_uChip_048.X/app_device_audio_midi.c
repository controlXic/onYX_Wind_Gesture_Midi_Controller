/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

/** INCLUDES *******************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "system.h"
#include "code/inc/usb/usb.h"
#include "code/inc/usb/usb_device_midi.h"
#include "code/inc/uart/uart1.h"
#include "byteToSound.h"
#include "app_device_audio_midi.h"
#include "chanels.h"
#include "samplerMode.h"



//printf("vel= %d --- buttonByte= %d\n", vel, buttonByte); //DEBUG

////////////////////////////////////////////////////////////////////////////////    
// Variables
////////////////////////////////////////////////////////////////////////////////

// Data input
uint8_t inData;
uint8_t dataLength = 0;

unsigned char strData[20];
unsigned char leftData[20];
unsigned char rightData[20];
unsigned char mouthData[20];

uint8_t leftDataOld2[20];
uint8_t leftDataOld[20];
uint8_t rightDataOld[20];

uint8_t inDataOldMouth;
uint8_t inDataOldRight;
uint8_t inDataOldRight2;
uint8_t inDataOldLeft;
uint8_t inDataOldLeft2;

// Timer_1 tick 1ms //
extern uint32_t millis;

// Long pres giroscopis //
uint32_t pushTimeF2LongPress;
uint32_t sendTime;
uint32_t sendTimeVel;

// Retard parada giroscopis //
uint8_t stopDelayGiroscopis = 50;
uint32_t stopMillisCc106;
bool stopCc106 = false;
uint32_t stopMillisPitchBend;
bool stopPitchBend = false;
uint32_t stopMillisCc116;
bool stopCc116 = false;


// Retard de canvi de nota, fa que soni lligat //
uint32_t changeNoteTick = 0;
uint8_t changeNoteDelay = 15;//15

// Retard presure controllers CC //
uint32_t presureMillis;
uint8_t persureSendInterval = 15;
uint8_t flgPreusreInterval = 0;

// Data polsadors mandos //
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

uint8_t channel = 0;
uint8_t octave = 0;

// sincronitza la polsacio de varis dits 
// perque sonin a l'hora
uint8_t delaynoteOnOff = 20; //20;
uint8_t delayVel = 5;

uint8_t tramposer = 12;

// Wind vars //
uint8_t vel = 0;
uint8_t velOld = 0;
uint8_t vel2 = 0;
uint8_t velStatus = 0;

// gyroscopes //
uint8_t giroXd = 0;
uint8_t giroYd = 0;
uint8_t giroXe = 0;
uint8_t giroYe = 0;

uint8_t giroXd2;
uint8_t giroYd2;
uint8_t giroYd3;
int giroYdPB = 0;
int giroYdPB2 = 0;
int giroYdPB2Old = 0;
uint8_t giroXdOld = 0;
uint8_t giroYdOld = 0;
uint8_t giroYd3Old = 0;

uint8_t giroYd3Old2 = 0;
uint8_t giroYe3Old2 = 0;
int giroYdPB2Old2 = 0;

uint8_t giroXe2;
uint8_t giroYe2;
uint8_t giroYe3;
uint8_t giroXeOld = 0;
uint8_t giroYeOld = 0;
uint8_t giroYe3Old = 0;

// Sampler delay time //
uint32_t tickSampler = 0;
uint8_t samplerPeriode = 5;

// Flags serial read //
bool flgMouth = false;
bool flgRight = false;
bool flgLeft = false;

// Buttons //
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

// Flags octaves //
bool octave0 = false;
bool octave1 = false;
bool octave2 = false;
bool octave3 = false;

// Flags notes //
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
bool flg191, flg192 = false;


// Test vars //
bool flgData = false;
bool flgStop = false;


////////////////////////////////////////////////////////////////////////////////    
// Initializations
////////////////////////////////////////////////////////////////////////////////    


#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata DEVICE_AUDIO_MIDI_RX_DATA_BUFFER=DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS
            static uint8_t ReceivedDataBuffer[64];
        #pragma udata DEVICE_AUDIO_MIDI_EVENT_DATA_BUFFER=DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS
            static USB_AUDIO_MIDI_EVENT_PACKET midiData;
        #pragma udata
    #elif defined(__XC8)
        static uint8_t ReceivedDataBuffer[64] DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS;
        static USB_AUDIO_MIDI_EVENT_PACKET midiData DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS;
    #endif
#else
    static uint8_t ReceivedDataBuffer[64];
    static USB_AUDIO_MIDI_EVENT_PACKET midiData;
#endif

static USB_HANDLE USBTxHandle;
static USB_HANDLE USBRxHandle;

//static uint8_t pitch;
//static bool sentNoteOff;
//static USB_VOLATILE uint8_t msCounter;


void APP_DeviceAudioMIDIInitialize()
{
    USBTxHandle = NULL;
    USBRxHandle = NULL;

    //pitch = 0x3C;
    //sentNoteOff = true;

    //msCounter = 0;

    //enable the HID endpoint
    USBEnableEndpoint(USB_DEVICE_AUDIO_MIDI_ENDPOINT,USB_OUT_ENABLED|USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

    //Re-arm the OUT endpoint for the next packet
    USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64);
   
}

void APP_DeviceAudioMIDISOFHandler()
{
   /* if(msCounter != 0)
    {
        msCounter--;
    }*/
}
    

////////////////////////////////////////////////////////////////////////////////    
// MIDI Functions
////////////////////////////////////////////////////////////////////////////////
 

void noteOn(uint8_t channel, uint8_t pitch, uint8_t velocity)
{
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_NOTE_ON;
    midiData.DATA_0 = 0x90 | channel;         
    midiData.DATA_1 = pitch + tramposer;         
    midiData.DATA_2 = velocity; 

    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}

void noteOff(uint8_t channel, uint8_t pitch, uint8_t velocity)
{
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_NOTE_OFF;
    midiData.DATA_0 = 0x80 | channel;         
    midiData.DATA_1 = pitch + tramposer;        
    midiData.DATA_2 = velocity;  
      
    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}
    
void controlChange(uint8_t channel, uint8_t control, uint8_t value) 
{
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_CONTROL_CHANGE;
    midiData.DATA_0 = 0xB0 | channel;         
    midiData.DATA_1 = control;         
    midiData.DATA_2 = value; 
    
    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}

void chPressure(uint8_t channel, uint8_t velocity)
{
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_CHANNEL_PREASURE;
    midiData.DATA_0 = 0xD0 | channel;         
    midiData.DATA_1 = velocity;         
    //midiData.DATA_2 = velocity; 
    
    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}

void Polyphonic(uint8_t channel, uint8_t pitch, uint8_t velocity) 
{
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_POLY_KEY_PRESS;
    midiData.DATA_0 = 0xA0 | channel;         
    midiData.DATA_1 = pitch;         
    midiData.DATA_2 = velocity; 
    
    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}

void pitchBendChange(uint8_t channel, int value) 
{  
    uint8_t lowValue = value & 0xff; //0x7F
    uint8_t highValue = value >> 7;  //7
    
    midiData.Val = 0;
    midiData.CableNumber = 0;
    midiData.CodeIndexNumber = MIDI_CIN_PITCH_BEND_CHANGE;
    midiData.DATA_0 = 0xE0 | channel;         
    midiData.DATA_1 = lowValue;         
    midiData.DATA_2 = highValue; 

    USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
}


////////////////////////////////////////////////////////////////////////////////    
// Map Function
////////////////////////////////////////////////////////////////////////////////
 

long map(long x, long in_min, long in_max, long out_min, long out_max) 
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


////////////////////////////////////////////////////////////////////////////////    
// Delay Function Nop() = 160ns
////////////////////////////////////////////////////////////////////////////////


uint16_t delayMs(uint16_t delayM)
{
    // 1000 delayM = 160us
    //6.250.000 delayM = 1s
    int i;
    for(i = 0;i < 6000;i++)
        for(i = 0;i < delayM;i++)
            Nop();
}

////////////////////////////////////////////////////////////////////////////////    
// App Loop
////////////////////////////////////////////////////////////////////////////////


void APP_DeviceAudioMIDITasks()
{
////////////////////////////////////////////////////////////////////////////////    
// Read TIMER 1 Status
////////////////////////////////////////////////////////////////////////////////
    
    
////////////////////////////////////////////////////////////////////////////////    
// USB status
////////////////////////////////////////////////////////////////////////////////
    
   
    if( (USBGetDeviceState() < CONFIGURED_STATE) || (USBIsDeviceSuspended() == true))
    {
        return;
    }
    
    
////////////////////////////////////////////////////////////////////////////////    
// MIDI read
////////////////////////////////////////////////////////////////////////////////
    
    
    if(!USBHandleBusy(USBRxHandle))
    {
        USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64);
    }   
  
    
////////////////////////////////////////////////////////////////////////////////    
// Data input - Serial read
////////////////////////////////////////////////////////////////////////////////

    
    if(UART1_IsRxReady())
    {
        inData = UART1_Read();
        strData[dataLength] = inData; 
        dataLength++;  
    }
    
    // Mouth //
    if(inData == 250) 
    {
        strcpy(mouthData, strData);
        strcpy(strData, "");
        vel = mouthData[3];
        
        inData = 0;
        dataLength = 0;
    }
    
  
    // Left //
    if(inData == 251) 
    {
        strcpy(leftData, strData);  
        giroXe = leftData[12];
        giroYe = leftData[13];  

        strcpy(strData, "");
        inData = 0;
        dataLength = 0;
    }
    
    // Right //
    if(inData == 252) 
    {
        strcpy(rightData, strData);        
        giroXd = rightData[12];
        giroYd = rightData[13]; 

        strcpy(strData, "");
        inData = 0;
        dataLength = 0;
  
    } 
 
    // Reset data length //
    if(dataLength > 15)
    {
        dataLength = 0;
        inData = 0; 
    }
        
    

////////////////////////////////////////////////////////////////////////////////
// Button left & right, byte to note
////////////////////////////////////////////////////////////////////////////////

    
    if((leftData != leftDataOld || rightData != rightDataOld) && flg70 == false) /////delay multi press
    {
        sendTime = millis;
        flg70 = true;
    }
    if(flg70 == true && millis > sendTime + delaynoteOnOff) ////////////////////////delay multi press
    {

        if(leftData[3] == '1' && flg1 == false)///////////////1
        { 
            buttonByte = buttonByte + 1;
            button1 = true;
            flg1 = true;
        }
        if(leftData[3] == '0' && flg1 == true) 
        {
            buttonByte = buttonByte - 1;
            button1 = false;
            flg1 = false;
        }

        if (leftData[4] == '1' && flg2 == false)  ///////////////2
        {
            buttonByte = buttonByte + 2;
            button2 = true;
            flg2 = true;
        }
        if(leftData[4] == '0' && flg2 == true) 
        {
            buttonByte = buttonByte - 2;
            button2 = false;
            flg2 = false;
        }

        if(leftData[5] == '1' && flg3 == false) ///////////////3
        { 
            buttonByte = buttonByte + 4;
            button3 = true;
            flg3 = true;
        }
        if(leftData[5] == '0' && flg3 == true) 
        {
            buttonByte = buttonByte - 4;
            button3 = false;
            flg3 = false;
        }

        if(leftData[7] == '1' && flg5 == false && button2 == false) ///////////////P // Funció especial 2
        { 
            buttonByte = buttonByte + 16;      
            buttonP = true;
            flg5 = true;
        }
        if((leftData[7] == '0' && flg5 == true) || (button2 == true && flg5 == true))
        {
            buttonByte = buttonByte - 16;
            buttonP = false;
            flg5 = false;
        }

        if(rightData[3] == '2' && flg6 == false)//////////////5
        { 
            buttonByte = buttonByte + 32;
            button5 = true;
            flg6 = true;
        }
        if(rightData[3] == '0' && flg6 == true)
        {
            buttonByte = buttonByte - 32;
            button5 = false;
            flg6 = false;
        }

        if(rightData[4] == '2' && flg7 == false)//////////////6
        { 
            buttonByte = buttonByte + 64;
            button6 = true;
            flg7 = true;
        }
        if (rightData[4] == '0' && flg7 == true) 
        {
            buttonByte = buttonByte - 64;
            button6 = false;
            flg7 = false;
        }

        if(rightData[5] == '2' && flg8 == false)//////////////7
        { 
            buttonByte = buttonByte + 128;
            button7 = true;
            flg8 = true;
        }
        if(rightData[5] == '0' && flg8 == true)
        {
            buttonByte = buttonByte - 128;
            button7 = false;
            flg8 = false;
        }

        if(rightData[6] == '2' && flg9 == false)  //////////////8
        {
            buttonByte = buttonByte + 256;
            button8 = true;
            flg9 = true;
        }
        if(rightData[6] == '0' && flg9 == true) 
        {
            buttonByte = buttonByte - 256;
            button8 = false;
            flg9 = false;
        }

        if(rightData[7] == '2' && flg10 == false) ////////////D#
        { 
            buttonByte = buttonByte + 512;
            buttonD = true;
            flg10 = true;
        }
        if(rightData[7] == '0' && flg10 == true) 
        {
            buttonByte = buttonByte - 512;
            buttonD = false;
            flg10 = false;
        }

        if(leftData[6] == '1' && flg4 == false && ((button5 == false && button6 == false && button7 == false) || (button8 == true)))///////4 // Funció especial 1
        { 
            buttonByte = buttonByte + 8;
            //button4 = true;
            flg4 = true;
        }
        if((leftData[6] == '0' && flg4 == true) || ((button5 == true || button6 == true || button7 == true) && button8 == false && flg4 == true)) 
        {
            buttonByte = buttonByte - 8;
            //button4 = false;
            flg4 = false;
        }
        if(leftData[6] == '1' && flg192 == false)///////4 // Funció especial 1 ; Correccio pel mode sampler
        { 
            button4 = true;
            flg192 = true;
        }
        if(leftData[6] == '0' && flg192 == true) 
        {
            button4 = false;
            flg192 = false;
        }
        
        // lligar notes //
        changeNoteTick = millis;

        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Octaves, Shifts, portamento
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if(leftData[8] == '1' && flg25 == false)///////////////Shift1
        { 
            buttonShift1 = true;
            flg25 = true;
        }
        if(leftData[8] == '0' && flg25 == true) 
        {
            buttonShift1 = false;
            flg25 = false;
        }

        if(rightData[8] == '2' && flg26 == false)//////////////Shift2 
        { 
            buttonShift2 = true;
            flg26 = true;
        }
        if(rightData[8] == '0' && flg26 == true)
        { 
            buttonShift2 = false;
            flg26 = false;
        }

        if(leftData[9] == '1' && flg27 == false)///////////////O1
        { 
            buttonByte = buttonByte + 1024;
            buttonOctave1 = true;
            flg27 = true;
        }
        if(leftData[9] == '0' && flg27 == true)
        {
            buttonByte = buttonByte - 1024;
            buttonOctave1 = false;
            flg27 = false;
        }
        if(leftData[10] == '1' && flg28 == false)///////////////O2
        { 
            buttonByte = buttonByte + 2048;
            buttonOctave2 = true;
            flg28 = true;
        }
        if(leftData[10] == '0' && flg28 == true) 
        {
            buttonByte = buttonByte - 2048;
            buttonOctave2 = false;
            flg28 = false;
        }
        if(leftData[11] == '1' && flg29 == false) ///////////////O3
        { 
            buttonByte = buttonByte + 4096;
            buttonOctave3 = true;
            flg29 = true;
        }
        if(leftData[11] == '0' && flg29 == true) 
        {
            buttonByte = buttonByte - 4096;
            buttonOctave3 = false;
            flg29 = false;
        }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions, time press; ControlChange i giroscopis. F1, F2, F3,
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

        if(buttonShift1 == false && buttonShift2 == false)
        {
            if (rightData[9] == '2' && flg30 == false) ////////////////////////////////////////////////// CC F1 
            {
                controlChange(channel, 64, 127);
                //noteOn(channel, 0, 127);
                flg30 = true;
            }
            if (rightData[9] == '0' && flg30 == true) 
            {
                controlChange(channel, 64, 0);
                //noteOn(channel, 0, 0);
                flg30 = false;
            }

            if (rightData[10] == '2' && flg31 == false) //////////////////////////////////////////F2 start press
            { 
                controlChange(channel, 114, 127);
                flg31 = true;
                flg72 = true;
                pushTimeF2LongPress = millis;
            }
            if (rightData[10] == '2' && flg72 == true &&  millis > pushTimeF2LongPress + 300) ////F2 long press
            { 
                F2 = true;
            }
            if (rightData[10] == '0' && flg72 == true)
            {
                controlChange(channel, 114, 0);
                F2 = false;
                flg31 = false;
                flg72 = false;
            }

            if (rightData[11] == '2' && flg32 == false) //////////////////////////////////////////// F3 instantani
            { 
                flg32 = true;
                F3 = true;
            }
            if (rightData[11] == '0' && flg32 == true ) 
            {
                flg32 = false;
                F3 = false;
            }
        }



////////////////////////////////////////////////////////////////////////////////
// Shift 1 + F1-F2-F3
////////////////////////////////////////////////////////////////////////////////
    

        if(buttonShift1 == true && buttonShift2 == false)
        {
            // Shift1 + F1 //
            if (rightData[9] == '2' && flg71 == false)
            {
                noteOn(channel, 0, 127);
                flg71 = true;
            }
            if (rightData[9] == '0' && flg71 == true) 
            {      
                noteOff(channel, 0, 0);
                flg71 = false;
            }
            // Shift1 + F2 //
            if (rightData[10] == '2' && flg190 == false) 
            { 
                noteOn(channel, 1, 127);
                flg190 = true;
            }
            if (rightData[10] == '0' && flg190 == true)
            {
                noteOff(channel, 1, 0);
                flg190 = false;
            }

            if (rightData[11] == '2' && flg191 == false) /////////////////////////// Shift1 + F3
            { 
                noteOn(channel, 2, 127);
                flg191 = true;
            }
            if (rightData[11] == '0' && flg191 == true ) 
            {
                noteOff(channel, 2, 0);
                flg191 = false;
            }
        }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Portamento, acords, configurable & giroscopis
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if(buttonOctave1 == true && buttonShift2 == true && flg73 == false) /////////////// Shift2 + O1
        { 
            noteOn(0, 3, 127);
            flg73 = true;
        }
        if((buttonOctave1 == false || buttonShift2 == false) && flg73 == true) 
        {
            noteOff(0, 3, 0);
            flg73 = false;
        }

        if(buttonOctave2 == true && buttonShift2 == true && flg74 == false) ///////////////Shift2 + O2
        { 
            noteOn(0, 4, 127);
            flg74 = true;
        }
        if((buttonOctave2 == false || buttonShift2 == false) && flg74 == true) 
        {
            noteOff(0, 4, 0);
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
    // fi del delay noteOn/Off / delay multipress //
    strcpy(leftDataOld, strData);
    strcpy(rightDataOld, strData);


////////////////////////////////////////////////////////////////////////////////
// Change Channel, Shift 1 || 2 + button note
////////////////////////////////////////////////////////////////////////////////

    chanelSelect();

////////////////////////////////////////////////////////////////////////////////
// Sampler mode, Shift 1 && 2 + buton note
////////////////////////////////////////////////////////////////////////////////

    samplerMode();
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Byte to sound
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
    if(vel <= 1)  /////delay init pressure
    {
        velStatus = 1;
//        vel2 = vel;
    }
    if(vel > 1 && velStatus == 1) 
    {
        sendTimeVel = millis;
        velStatus = 2;
    }
    if((vel > 1 && velStatus == 2 && millis > sendTimeVel + delayVel)  || velStatus == 0) 
    {
        //vel2 =  map(vel, 0, 127, 0, 127); //normal
        vel2 = vel;
        velStatus = 0;
    }

    if(velStatus == 0 || velStatus == 1)
    {
      
        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Byte to sound. Block 1 - octave = 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
        // O-0 ON //
        if(buttonOctave1 == false && buttonOctave2 == false && buttonOctave3 == false && vel > 10) 
        {   
            Octave_0_On();
            octave0 = true;
        }  
        // O-0 OFF //
        if(((vel < 10 || buttonOctave1 == true || buttonOctave2 == true || buttonOctave3 == true) || (buttonByte != buttonByteOld)) && millis > changeNoteTick + changeNoteDelay && octave0 == true)
        {
            Octave_0_Off();
            octave0 = false;
        }
        
        // O-1 ON //
        if(buttonOctave1 == true && vel > 20) 
        {    
            Octave_1_On();
            octave1 = true;
        }
        // O-1 OFF //
        if(((buttonOctave1 == false || vel < 10) || (buttonByte != buttonByteOld)) && millis > changeNoteTick + changeNoteDelay && octave1 == true) 
        {
            Octave_1_Off();
            octave1 = false;
        }
        
        // O-2 ON //
        if(buttonOctave2 == true && vel > 20) 
        {  
            Octave_2_On();
            octave2 = true;
        }
        // O-2 OFF //
        if(((buttonOctave2 == false || vel < 10) || (buttonByte != buttonByteOld)) && millis > changeNoteTick + changeNoteDelay && octave2 == true) 
        {
            Octave_2_Off();
            octave2 = false;
        }
        
        // O-3 ON //
        if(buttonOctave3 == true && vel > 20) 
        {  
            Octave_3_On();
            octave3 = true;
        }       
        // O-3 OFF // 
        if(((buttonOctave3 == false || vel < 10) || (buttonByte != buttonByteOld)) && millis > changeNoteTick + changeNoteDelay && octave3 == true) 
        {
            Octave_3_Off();
            octave3 = false;
        }
        //  assinga nota vella un cop lligada //    
        if(millis > changeNoteTick + changeNoteDelay)
        {  
            buttonByteOld = buttonByte;                   
        }     
        
        if(vel < 10 && flgStop == false)
        {
    //        printf("\n\r STOP vent!");
            controlChange(channel, 123, 0);
            flgStop = true;               
        }
        if(vel > 10 && flgStop == true)
        {
            flgStop = false;               
        }
        

    }
    
       

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// pressure controlador de vent
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(vel2 != velOld && flgPreusreInterval == 0)
    {
        presureMillis = millis;   
        flgPreusreInterval = 1;
    }
    if(millis > presureMillis + persureSendInterval && flgPreusreInterval == 1) ///////////////////////////////////////// breath Control
    {
        controlChange(channel, 2, vel2);
        flgPreusreInterval = 2;
    }

    if(millis > presureMillis + persureSendInterval + persureSendInterval && flgPreusreInterval == 2) ///////////////////////////////////////// Expression Controller
    {
        controlChange(channel, 11, vel2);
        
        flgPreusreInterval = 0;
    }
    
    
//    if(vel != velOld) ///////////////////////////////////////// Volume Control
//    {
//        controlChange(channel, 7, vel);
//    }

    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Giroscopi mapeig
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    giroXd2 = map(giroXd, 90, 180, 0, 127); // posar min a 30 - 255
    giroYd2 = map(giroYd, 1, 180, 127, 0);
    giroYdPB = map(giroYd, 1, 180, 16380, 0);

    giroXe2 = map(giroXe, 90, 180, 0, 127);
    giroYe2 = map(giroYe, 1, 180, 0, 127);  

    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Giroscopi histeresi
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Y Right //
    if(giroYd2 >= 0 && giroYd2 <= 50)
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
      

//////////////////////////////////////////////
// giroYdPB = map(giroYd3, 127, 0, 16380, 0);
//////////////////////////////////////////////

    // Y Right Pitch Bend //
    if(giroYdPB >= 0 && giroYdPB <= 6900)
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
    
    // Y Left //
    if(giroYe2 >= 0 && giroYe2 <= 55)
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
      
      

////////////////////////////////////////////////////////////////////////////////
// Giroscopis control
////////////////////////////////////////////////////////////////////////////////
    
    ////////
    // F2 //
    ////////
    if(F2 == true) 
    {      
        if(giroXd != giroXdOld) 
        { 
            controlChange(channel, 107, giroXd2);
        }
        if(giroYd != giroYdOld) 
        {
            controlChange(channel, 106, giroYd3);
        }
        if(giroXe != giroXeOld) 
        { 
            controlChange(channel, 109, giroXe2);
        }
        if(giroYe != giroYeOld) 
        {
            controlChange(channel, 108, giroYe3);
        }

        flgF2 = true;
    }
    if(F2 == false && flgF2 == true)
    {
        flgF2 = false;

        //controlChange(channel, 106, 64);
        stopMillisCc106 = millis;
        stopCc106 = true;
        
        controlChange(channel, 108, 64);

        giroYd3Old = giroYd3 = 64;
        giroYe3Old = giroYe3 = 64;    
    }

    ////////
    // F3 //
    ////////
    if(F3 == true) 
    {  
        if(giroXd != giroXdOld) 
        {
            controlChange(channel, 1, giroXd2);
        }
        if(giroYd != giroYdOld)
        {
            pitchBendChange(channel, giroYdPB2);
        }
        if(giroXe != giroXeOld) 
        { 
            controlChange(channel, 5, giroXe2);
        }
        if(giroYe != giroYeOld) 
        {
            controlChange(channel, 12, giroYe3);
        }

        flgF3 = true;
    }
    if(F3 == false && flgF3 == true)
    {
        flgF3 = false;
//        printf("PB= 8190\n"); //DEBUG

        //pitchBendChange(channel, 8000);
        stopMillisPitchBend = millis;
        stopPitchBend = true;
        
        controlChange(channel, 12, 64);

        giroYd3Old = giroYd3 = 64;
        giroYe3Old = giroYe3 = 64;
        giroYdPB2Old = giroYdPB2  = 8000;
    }
    
    ///////////
    // S2+O3 //
    ///////////
    if(S2O3 == true) 
    {  
        if(giroXd != giroXdOld/* || flgS2O3 == false*/) 
        { 
            controlChange(0, 115, giroXd2);
        }
        if(giroYd != giroYdOld) 
        {
            controlChange(0, 116, giroYd3);
        }
        if(giroXe != giroXeOld/* || flgS2O3 == false*/) 
        { 
            controlChange(0, 117, giroXe2);
        }
        if(giroYe != giroYeOld) 
        {
            controlChange(0, 118, giroYe3);
        }    

        flgS2O3 = true;
    }
    if(S2O3 == false && flgS2O3 == true)
    {
        flgS2O3 = false;

        //controlChange(0, 116, 64);
        stopMillisCc116 = millis;
        stopCc116 = true;
        
        controlChange(0, 118, 64);

        giroYd3Old = giroYd3 = 64;
        giroYe3Old = giroYe3 = 64;   
    }
    
    
////////////////////////////////////////////////////////////////////////////////
// Giroscopis STOP control
////////////////////////////////////////////////////////////////////////////////
    
    // F2 //
    if(stopCc106 == true && millis >= stopMillisCc106 + 10)
    {
        controlChange(0, 106, 64);
        stopCc106 = false;
    }
    // F3 //
    if(stopPitchBend == true && millis >= stopMillisPitchBend + stopDelayGiroscopis)
    {
        pitchBendChange(channel, 8000);
        stopPitchBend = false;
    }
    // S2+O3 //
    if(stopCc116 == true && millis >= stopMillisCc116 + stopDelayGiroscopis)
    {
        controlChange(0, 116, 64);
        stopCc116 = false;
    }
    
    
////////////////////////////////////////////////////////////////////////////////
// Assignar estats actuals com anteriors
////////////////////////////////////////////////////////////////////////////////
            
    velOld = vel2;
    giroXdOld = giroXd;
    giroYdOld = giroYd;
    giroXeOld = giroXe;
    giroYeOld = giroYe;

    giroYd3Old2 = giroYd3;
    giroYe3Old2 = giroYe3;
    giroYdPB2Old2 = giroYdPB2;      

      
    
}
