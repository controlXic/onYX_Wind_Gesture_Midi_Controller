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

#include <stdint.h>
#include <stdbool.h>

#include "chanels.h"

//#include "app_device_audio_midi.h"

extern uint16_t buttonByte;
extern bool buttonShift1;
extern bool buttonShift2;
extern uint8_t channel;


////////////////////////////////////////////////////////////////////////////////
// Change Channel, Shift 1 || 2 + button note
////////////////////////////////////////////////////////////////////////////////

void chanelSelect()
{
    
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
    
    
}


/* *****************************************************************************
 End of File
 */
