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

#include <stdint.h>



////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void APP_DeviceAudioMIDIInitialize(void);

void APP_DeviceAudioMIDITasks(void);

void APP_DeviceAudioMIDISOFHandler(void);

void noteOn(uint8_t channel, uint8_t pitch, uint8_t velocity);

void noteOff(uint8_t channel, uint8_t pitch, uint8_t velocity);
    
void controlChange(uint8_t channel, uint8_t control, uint8_t value);

void chPressure(uint8_t channel, uint8_t velocity);

void Polyphonic(uint8_t channel, uint8_t pitch, uint8_t velocity); 

void pitchBendChange(uint8_t channel, int value);

long map(long x, long in_min, long in_max, long out_min, long out_max);

