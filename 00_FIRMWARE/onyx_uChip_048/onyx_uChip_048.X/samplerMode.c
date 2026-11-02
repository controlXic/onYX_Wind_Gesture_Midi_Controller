/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "samplerMode.h"
#include "app_device_audio_midi.h"


// mode vars //
extern uint16_t buttonByte;
extern bool buttonShift1;
extern bool buttonShift2;
extern uint8_t channel;

// Buttons //
extern bool button1;
extern bool button2;
extern bool button3;
extern bool button4;
extern bool buttonP;
extern bool button5;
extern bool button6;
extern bool button7;
extern bool button8;
extern bool buttonD;

// time vars //
extern uint32_t millis;
extern uint32_t tickSampler;
extern uint16_t samplerPeriode;

// flags //
extern bool flg33, flg34, flg35, flg36, flg37, flg38, flg39, flg40;


////////////////////////////////////////////////////////////////////////////////
// Sampler mode, Shift 1 && 2 + buton note
////////////////////////////////////////////////////////////////////////////////


void samplerMode()
{
    if(buttonShift1 == true && buttonShift2 == true /*&& millis >= tickSampler + samplerPeriode*/)   
    {
        if(button1 == true && flg33 == false)/////////////////////C--
        { 
            noteOn(channel, 24, 127);
            flg33 = true;
            tickSampler = millis;
            return;
        }
        if(button1 == false && flg33 == true) 
        {            
            noteOff(channel, 24, 0);
            flg33 = false;
            tickSampler = millis;
            return;
        }

        if(button2 == true && flg34 == false)///////////////////C#--
        { 
            noteOn(channel, 25, 127);
            flg34 = true;
            tickSampler = millis;
            return;
        }
        if(button2 == false && flg34 == true) 
        {
            noteOff(channel, 25, 0);
            flg34 = false;
            tickSampler = millis;
            return;
        }

        if(button3 == true && flg35 == false)////////////////////D--
        { 
            noteOn(channel, 26, 127);
            flg35 = true;
            tickSampler = millis;
            return;
        }
        if(button3 == false && flg35 == true) 
        {
            noteOff(channel, 26, 0);
            flg35 = false;
            tickSampler = millis;
            return;
        }

        if(button4 == true && flg36 == false) /////////////////////D#--
        { 
            noteOn(channel, 27, 127);
            flg36 = true;
            tickSampler = millis;
            return;
        }
        if(button4 == false && flg36 == true) 
        {
            noteOff(channel, 27, 0);
            flg36 = false;
            tickSampler = millis;
            return;
        }

        if(button5 == true && flg37 == false)//////////////////////E--
        { 
            noteOn(channel, 28, 127);
            flg37 = true;
            tickSampler = millis;
            return;
        }
        if(button5 == false && flg37 == true) 
        {
            noteOff(channel, 28, 0);
            flg37 = false;
            tickSampler = millis;
            return;
        }

        if(button6 == true && flg38 == false)///////////////////////F--
        { 
            noteOn(channel, 29, 127);
            flg38 = true;
            tickSampler = millis;
            return;
        }
        if(button6 == false && flg38 == true)
        {
            noteOff(channel, 29, 0);
            flg38 = false;
            tickSampler = millis;
            return;
        }

        if(button7 == true && flg39 == false) //////////////////////F#--
        { 
            noteOn(channel, 30, 127);
            flg39 = true;
            tickSampler = millis;
            return;
        }

        if(button7 == false && flg39 == true) 
        {
            noteOff(channel, 30, 0);
            flg39 = false;
            tickSampler = millis;
            return;
        }

        if(button8 == true && flg40 == false) //////////////////////////G--
        { 
            noteOn(channel, 31, 127);
            flg40 = true;
            tickSampler = millis;
            return;
        }
        if(button8 == false && flg40 == true) 
        {
            noteOff(channel, 31, 0);
            flg40 = false;
            tickSampler = millis;
            return;
        }
    }
}


/* *****************************************************************************
 End of File
 */
