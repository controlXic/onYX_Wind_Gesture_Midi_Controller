

#include "byteToSound.h"
#include "app_device_audio_midi.h"
#include "stdbool.h"



////////////////////////////////////////////////////////////////////////////////    
// Variables
////////////////////////////////////////////////////////////////////////////////


// // Data polsadors mandos //
extern uint16_t buttonByte;
extern uint8_t vel;
extern uint8_t vel2;
extern uint8_t channel;

// Flags //
extern bool flg1, flg2, flg3, flg4, flg5, flg6, flg7, flg8, flg9, flg10;
extern bool flg11, flg12, flg13, flg14, flg15, flg16, flg17, flg18, flg19, flg20;
extern bool flg21, flg22, flg23, flg24, flg25, flg26, flg27, flg28, flg29, flg30;
extern bool flg31, flg32, flg33, flg34, flg35, flg36, flg37, flg38, flg39, flg40;
extern bool flg41, flg42, flg43, flg44, flg45, flg46, flg47, flg48, flg49, flg50;
extern bool flg51, flg52, flg53, flg54, flg55, flg56, flg57, flg58, flg59, flg60;
extern bool flg61, flg62, flg63, flg64, flg65, flg66, flg67, flg68, flg69, flg70;
extern bool flg71, flg72, flg73, flg74, flg75, flg76, flg77, flg78, flg79, flg80;
extern bool flg81, flg82, flg83, flg84, flg85, flg86, flg87, flg88, flg89, flg90;
extern bool flg91, flg92, flg93, flg94, flg95, flg96, flg97, flg98, flg99, flg100;
extern bool flg101, flg102, flg103, flg104, flg105, flg106, flg107, flg108, flg109, flg110;
extern bool flg111, flg112, flg113, flg114, flg115, flg116, flg117, flg118, flg119, flg120;
extern bool flg121, flg122, flg123, flg124, flg125, flg126, flg127, flg128, flg129, flg130;
extern bool flg131, flg132, flg133, flg134, flg135, flg136, flg137, flg138, flg139, flg140;
extern bool flg141, flg142, flg143, flg144, flg145, flg146, flg147, flg148, flg149, flg150;
extern bool flg151, flg152, flg153, flg154, flg155, flg156, flg157, flg158, flg159, flg160;
extern bool flg161, flg162, flg163, flg164, flg165, flg166, flg167, flg168, flg169, flg170;
extern bool flg171, flg172, flg173, flg174, flg175, flg176, flg177, flg178, flg179, flg180;
extern bool flg181, flg182, flg183, flg184, flg185, flg186, flg187, flg188, flg189, flg190;
extern bool flg191;



void Octave_0_On(void)
{
    // C //
    if(buttonByte == 487 && flg11 == false)
    {
        noteOn(channel, 36, vel2);
        flg11 = true;
    }
    // C# //
    if(buttonByte == 495 && flg12 == false)
    {
        noteOn(channel, 37, vel2);
        flg12 = true;
    }
    // D //
    if(buttonByte == 231 && flg13 == false)
    {
        noteOn(channel, 38, vel2);
        flg13 = true;
    }
    // D# //
    if(buttonByte == 743 && flg14 == false)
    {
        noteOn(channel, 39, vel2);
        flg14 = true;
    }
    // E //
    if(buttonByte == 103 && flg15 == false)
    {
        noteOn(channel, 40, vel2);
        flg15 = true;
    }
    // F //
    if(buttonByte == 39 && flg16 == false)
    {
        noteOn(channel, 41, vel2);
        flg16 = true;
    }
    // F# //
    if((buttonByte == 71|| buttonByte == 135 || buttonByte == 167) && flg17 == false)
    {
        noteOn(channel, 42, vel2);
        flg17 = true;
    }
    // G //
    if(buttonByte == 7 && flg18 == false)
    {
        noteOn(channel, 43, vel2);
        flg18 = true;
    }
    // G# //
    if(buttonByte == 15 && flg19 == false)
    {
        noteOn(channel, 44, vel2);
        flg19 = true;
    }
    // A //
    if(buttonByte == 3 && flg20 == false)
    {
        noteOn(channel, 45, vel2);
        flg20 = true;
    }
    // A# //
    if((buttonByte == 17 || buttonByte == 35 || buttonByte == 33 || buttonByte == 65) && flg21 == false)
    {
        noteOn(channel, 46, vel2);
        flg21 = true;
    }
    // B //
    if(buttonByte == 1 && flg22 == false)
    { 
        noteOn(channel, 47, vel2);
        flg22 = true;
    }
    // C2 //
    if((buttonByte == 2 || buttonByte == 5 || buttonByte == 486 || buttonByte == 21) && flg23 == false)
    {
        noteOn(channel, 48, vel2);
        flg23 = true;
    }      
    // C#2 //
    if((buttonByte == 494 || buttonByte == 0) && flg24 == false)
    { 
        noteOn(channel, 49, vel2);
        flg24 = true;
    }
    // D2 //
    if(buttonByte == 230 && flg41 == false)
    {
        noteOn(channel, 50, vel2);
        flg41 = true;
    }
    // D#2 //
    if(buttonByte == 742 && flg42 == false)
    {
        noteOn(channel, 51, vel2);
        flg42 = true;
    }
    // E2 //
    if(buttonByte == 102 && flg43 == false)
    { 
        noteOn(channel, 52, vel2);
        flg43 = true;
    }
    // F2 //
    if(buttonByte == 38 && flg44 == false)
    {
        noteOn(channel, 53, vel2);
        flg44 = true;
    }
    // F#2 //
    if((buttonByte == 70 || buttonByte == 134 || buttonByte == 166) && flg45 == false)
    {
        noteOn(channel, 54, vel2);
        flg45 = true;
    }
    // G2 //
    if((buttonByte == 6 || buttonByte == 263) && flg46 == false)
    {
        noteOn(channel, 55, vel2);
        flg46 = true;
    }
    // G#2 //
    if((buttonByte == 14 || buttonByte == 271) && flg47 == false)
    {
        noteOn(channel, 56, vel2);
        flg47 = true;
    }
    // A2 //
    if(buttonByte == 259 && flg48 == false)
    { 
        noteOn(channel, 57, vel2);
        flg48 = true;
    }
    // A#2 //
    if((buttonByte == 273 || buttonByte == 291 || buttonByte == 289 || buttonByte == 321) && flg49 == false)
    {
        noteOn(channel, 58, vel2);
        flg49 = true;
    }
    // B2 //
    if(buttonByte == 257 && flg50 == false)
    { 
        noteOn(channel, 59, vel2);
        flg50 = true;
    }
    // C3 //
    if((buttonByte == 258 || buttonByte == 261 || buttonByte == 484 || buttonByte == 277) && flg51 == false)
    {
        noteOn(channel, 60, vel2);
        flg51 = true;
    }
    // C#3 //
    if((buttonByte == 256 || buttonByte == 492) && flg52 == false)
    { 
        noteOn(channel, 61, vel2);
        flg52 = true;
    }
    // D3 //
    if(buttonByte == 228 && flg53 == false)
    { 
        noteOn(channel, 62, vel2);
        flg53 = true;
    }
    // D#3 //
    if(buttonByte == 740 && flg54 == false)
    { 
        noteOn(channel, 63, vel2);
        flg54 = true;
    }
    // E3 //
    if(buttonByte == 100 && flg55 == false)
    {
        noteOn(channel, 64, vel2);
        flg55 = true;
    }
    // F3 //
    if(buttonByte == 36 && flg56 == false)
    { 
        noteOn(channel, 65, vel2);
        flg56 = true;
    }
    // F#3 //
    if((buttonByte == 68 || buttonByte == 132 || buttonByte == 164) && flg57 == false)
    {
        noteOn(channel, 66, vel2);
        flg57 = true;
    }
    // G3 //
    if((buttonByte == 4 || buttonByte == 391) && flg58 == false)
    {
        noteOn(channel, 67, vel2);
        flg58 = true;
    }
    // G#3 //
    if((buttonByte == 12 || buttonByte == 399) && flg59 == false)
    { 
        noteOn(channel, 68, vel2);
        flg59 = true;
    }
    // A3 //
    if(buttonByte == 387 && flg60 == false)
    { 
        noteOn(channel, 69, vel2);
        flg60 = true;
    }
    // A#3 //
    if((buttonByte == 401 || buttonByte == 419 || buttonByte == 417 || buttonByte == 449) && flg61 == false)
    {
        noteOn(channel, 70, vel2);
        flg61 = true;
    }
    // B3 //
    if(buttonByte == 385 && flg62 == false)
    { 
        noteOn(channel, 71, vel2);
        flg62 = true;
    }
    // C4 //
    if((buttonByte == 386 || buttonByte == 389 || buttonByte == 405) && flg63 == false)
    {
        noteOn(channel, 72, vel2);
        flg63 = true;
    }
    // C#4 //
    if(buttonByte == 384 && flg64 == false)
    { 
        noteOn(channel, 73, vel2);
        flg64 = true;        
    }       
}




void Octave_0_Off(void)
{    
    // C //
    if((buttonByte != 487 || vel < 10) && flg11 == true) 
    {
        noteOff(channel, 36, 0);
        flg11 = false;
    }
    // C# //
    if((buttonByte != 495 || vel < 10) && flg12 == true) 
    {
        noteOff(channel, 37, 0);
        flg12 = false;
    }
    // D //
    if((buttonByte != 231 || vel < 10) && flg13 == true) 
    {
        noteOff(channel, 38, 0);
        flg13 = false;
    }
    // D# //
    if((buttonByte != 743 || vel < 10) && flg14 == true)
    {
        noteOff(channel, 39, 0);
        flg14 = false;
    }
    // E //
    if((buttonByte != 103 || vel < 10) && flg15 == true)
    {
        noteOff(channel, 40, 0);
        flg15 = false;
    }
    // F //
    if((buttonByte != 39 || vel < 10) && flg16 == true)
    {
        noteOff(channel, 41, 0);
        flg16 = false;
    }
    // F# //
    if((buttonByte != 71 && buttonByte != 135 && buttonByte != 167 || vel < 10) && flg17 == true)
    {
        noteOff(channel, 42, 0);
        flg17 = false;
    }
    // G //
    if((buttonByte != 7 || vel < 10) && flg18 == true)
    {
        noteOff(channel, 43, 0);
        flg18 = false;
    }
    // G# //
    if((buttonByte != 15 || vel < 10) && flg19 == true)
    {
        noteOff(channel, 44, 0);
        flg19 = false;
    }
    // A //
    if((buttonByte != 3 || vel < 10) && flg20 == true)
    {
        noteOff(channel, 45, 0);
        flg20 = false;
    }
    // A# //
    if((buttonByte != 17 && buttonByte != 35 && buttonByte != 33 && buttonByte != 65 || vel < 10) && flg21 == true)
    {
        noteOff(channel, 46, 0);
        flg21 = false;
    }
    // B //
    if((buttonByte != 1 || vel < 10) && flg22 == true)
    {
        noteOff(channel, 47, 0);
        flg22 = false;
    }
    // C2 //
    if((buttonByte != 2 && buttonByte != 5 && buttonByte != 486 && buttonByte != 21 || vel < 10) && flg23 == true)
    {
        noteOff(channel, 48, 0);
        flg23 = false;
    }
    // C#2 //
    if((buttonByte != 494 && buttonByte != 0 || vel < 10) && flg24 == true)
    {
        noteOff(channel, 49, 0);
        flg24 = false;
    }
    // D2 //
    if((buttonByte != 230 || vel < 10) && flg41 == true)
    {
        noteOff(channel, 50, 0);
        flg41 = false;
    }
    // D#2 //
    if((buttonByte != 742 || vel < 10) && flg42 == true)
    {
        noteOff(channel, 51, 0);
        flg42 = false;
    }
    // E2 //
    if((buttonByte != 102 || vel < 10) && flg43 == true)
    {
        noteOff(channel, 52, 0);
        flg43 = false;
    }
    // F2 //
    if((buttonByte != 38 || vel < 10) && flg44 == true)
    {
        noteOff(channel, 53, 0);
        flg44 = false;
    }
    // F#2 //
    if((buttonByte != 70 && buttonByte != 134 && buttonByte != 166 || vel < 10) && flg45 == true) 
    {
        noteOff(channel, 54, 0);
        flg45 = false;
    }
    // G2 //
    if((buttonByte != 6 && buttonByte != 263 || vel < 10) && flg46 == true) 
    {
        noteOff(channel, 55, 0);
        flg46 = false;
    }
    // G#2 //
    if((buttonByte != 14 && buttonByte != 271 || vel < 10) && flg47 == true)
    {
        noteOff(channel, 56, 0);
        flg47 = false;
    }
    // A2 //
    if((buttonByte != 259 || vel < 10) && flg48 == true) 
    {
        noteOff(channel, 57, 0);
        flg48 = false;
    }
    // A#2 //
    if((buttonByte != 273 && buttonByte != 291 && buttonByte != 289 && buttonByte != 321 || vel < 10) && flg49 == true) 
    {
        noteOff(channel, 58, 0);
        flg49 = false;
    }
    // B2 //
    if((buttonByte != 257 || vel < 10) && flg50 == true) 
    {
        noteOff(channel, 59, 0);
        flg50 = false;
    }
    // C3 //
    if((buttonByte != 258 && buttonByte != 261 && buttonByte != 484 && buttonByte != 277 || vel < 10) && flg51 == true) 
    {
        noteOff(channel, 60, 0);
        flg51 = false;
    }
    // C#3 //
    if((buttonByte != 256 && buttonByte != 492 || vel < 10) && flg52 == true) 
    {
        noteOff(channel, 61, 0);
        flg52 = false;
    }
    // D3 //
    if((buttonByte != 228 || vel < 10) && flg53 == true) 
    {
        noteOff(channel, 62, 0);
        flg53 = false;
    }
    // D#3 //
    if((buttonByte != 740 || vel < 10) && flg54 == true)
    {
        noteOff(channel, 63, 0);
        flg54 = false;
    }
    // E3 //
    if((buttonByte != 100 || vel < 10) && flg55 == true) 
    {
        noteOff(channel, 64, 0);
        flg55 = false;
    }
    // F3 //
    if((buttonByte != 36 || vel < 10) && flg56 == true) 
    {
        noteOff(channel, 65, 0);
        flg56 = false;
    }
    // F#3 //
    if((buttonByte != 68 && buttonByte != 132 && buttonByte != 164 || vel < 10) && flg57 == true) 
    {
        noteOff(channel, 66, 0);
        flg57 = false;
    }
    // G3 //
    if((buttonByte != 4 && buttonByte != 391 || vel < 10) && flg58 == true)
    {
        noteOff(channel, 67, 0);
        flg58 = false;
    }
    // G#3 //
    if((buttonByte != 12 && buttonByte != 399 || vel < 10) && flg59 == true)
    {
        noteOff(channel, 68, 0);
        flg59 = false;
    }
    // A3 //
    if((buttonByte != 387 || vel < 10) && flg60 == true)
    { 
        noteOff(channel, 69, 0);
        flg60 = false;
    }
    // A#3 //
    if((buttonByte != 401 && buttonByte != 419 && buttonByte != 417 && buttonByte != 449 || vel < 10) && flg61 == true)
    {
        noteOff(channel, 70, 0);
        flg61 = false;
    }
    // B3 //
    if((buttonByte != 385 || vel < 10) && flg62 == true) 
    {
        noteOff(channel, 71, 0);
        flg62 = false;
    }
    // C4 //
    if((buttonByte != 386 && buttonByte != 389 && buttonByte != 405 || vel < 10) && flg63 == true) 
    {
        noteOff(channel, 72, 0);
        flg63 = false;
    }
    // C#4 //
    if((buttonByte != 384 || vel < 10) && flg64 == true) 
    {
        noteOff(channel, 73, 0);
        flg64 = false;
    }
}



void octave_0_all_off(void)
{
    noteOff(channel, 36, 0);
    noteOff(channel, 37, 0);
    noteOff(channel, 38, 0);
    noteOff(channel, 39, 0);
    noteOff(channel, 40, 0);
    noteOff(channel, 41, 0);
    noteOff(channel, 42, 0);
    noteOff(channel, 43, 0);
    noteOff(channel, 44, 0);
    noteOff(channel, 45, 0);
    noteOff(channel, 46, 0);
    noteOff(channel, 47, 0);
    noteOff(channel, 48, 0);
    noteOff(channel, 49, 0);
    noteOff(channel, 50, 0);
    noteOff(channel, 51, 0);
    noteOff(channel, 52, 0);
    noteOff(channel, 53, 0);
    noteOff(channel, 54, 0);
    noteOff(channel, 55, 0);
    noteOff(channel, 56, 0);
    noteOff(channel, 57, 0);
    noteOff(channel, 58, 0);
    noteOff(channel, 50, 0);
    noteOff(channel, 60, 0);
    noteOff(channel, 61, 0);
    noteOff(channel, 62, 0);
    noteOff(channel, 63, 0);
    noteOff(channel, 64, 0);
    noteOff(channel, 65, 0);
    noteOff(channel, 66, 0);
    noteOff(channel, 67, 0);
    noteOff(channel, 68, 0);
    noteOff(channel, 69, 0);
    noteOff(channel, 70, 0);
    noteOff(channel, 71, 0);
    noteOff(channel, 72, 0);
    noteOff(channel, 73, 0);
}


void Octave_1_On(void)
{
    // C-O1 //
    if(buttonByte == 1511 && flg76 == false)
    {
      noteOn(channel, 48, vel2);
      flg76 = true;
    }
    // C#-O1 //
    if(buttonByte == 1519 && flg79 == false)
    {
      noteOn(channel, 49, vel2);
      flg79 = true;
    }
    // D-O1 //
    if (buttonByte == 1255 && flg82 == false)
    {
      noteOn(channel, 50, vel2);
      flg82 = true;
    }
    // D#-O1 //
    if(buttonByte == 1767 && flg85 == false)
    {
      noteOn(channel, 51, vel2);
      flg85 = true;
    }
    // E-O1 //
    if(buttonByte == 1127 && flg88 == false)
    {
      noteOn(channel, 52, vel2);
      flg88 = true;
    }
    // F-O1 //
    if(buttonByte == 1063 && flg91 == false)
    {
      noteOn(channel, 53, vel2);
      flg91 = true;
    }
    // C-O1 //
    if((buttonByte == 1095 || buttonByte == 1159 || buttonByte == 1191) && flg94 == false)
    {
      noteOn(channel, 54, vel2);
      flg94 = true;
    }
    // F#-O1 //
    if(buttonByte == 1031 && flg97 == false)
    {
      noteOn(channel, 55, vel2);
      flg97 = true;
    }
    // G#-O1 //
    if(buttonByte == 1039 && flg100 == false)
    {
      noteOn(channel, 56, vel2);
      flg100 = true;
    }
    // A-O1 //
    if(buttonByte == 1027 && flg103 == false)
    {
      noteOn(channel, 57, vel2);
      flg103 = true;
    }
    // A#-O1 //
    if((buttonByte == 1041 || buttonByte == 1059 || buttonByte == 1057 || buttonByte == 1089) && flg106 == false)
    {
      noteOn(channel, 58, vel2);
      flg106 = true;
    }
    // B-O1 //
    if(buttonByte == 1025 && flg109 == false)
    { 
      noteOn(channel, 59, vel2);
      flg109 = true;
    }
    // C2-O1 //
    if((buttonByte == 1026 || buttonByte == 1029 || buttonByte == 1510 || buttonByte == 1045) && flg112 == false)
    {
      noteOn(channel, 60, vel2 );
      flg112 = true;
    }
    // C#2-O1 //
    if((buttonByte == 1518 || buttonByte == 1024) && flg115 == false)
    { 
      noteOn(channel, 61, vel2 );
      flg115 = true;
    }
    // D2-O1 //
    if(buttonByte == 1254 && flg118 == false)
    {
      noteOn(channel, 62, vel2 );
      flg118 = true;
    }
    // D#2-O1 //
    if(buttonByte == 1766 && flg121 == false)
    {
      noteOn(channel, 63, vel2 );
      flg121 = true;
    }
    // E2-O1 //
    if(buttonByte == 1126 && flg124 == false)
    { 
      noteOn(channel, 64, vel2 );
      flg124 = true;
    }
    // F2-O1 //
    if(buttonByte == 1062 && flg127 == false)
    {
      noteOn(channel, 65, vel2 );
      flg127 = true;
    }
    // F#2-O1 //
    if((buttonByte == 1094 || buttonByte == 1158 || buttonByte == 1190) && flg130 == false)
    {
      noteOn(channel, 66, vel2);
      flg130 = true;
    }
    // G2-O1 //
    if((buttonByte == 1030 || buttonByte == 1287) && flg133 == false)
    {
      noteOn(channel, 67, vel2);
      flg133 = true;
    }
    // G#2-O1 //
    if((buttonByte == 1038 || buttonByte == 1295) && flg136 == false)
    {
      noteOn(channel, 68, vel2);
      flg136 = true;
    }
    // A2-O1 //
    if(buttonByte == 1283 && flg139 == false)
    { 
      noteOn(channel, 69, vel2 );
      flg139 = true;
    }
    // A#2-O1 //
    if((buttonByte == 1297 || buttonByte == 1315 || buttonByte == 1313 || buttonByte == 1345) && flg142 == false)
    {
      noteOn(channel, 70, vel2);
      flg142 = true;
    }
    // B2-O1 //
    if(buttonByte == 1281 && flg145 == false)
    { 
      noteOn(channel, 71, vel2);
      flg145 = true;
    }
    // C3-O1 //
    if((buttonByte == 1282 || buttonByte == 1285 || buttonByte == 1508 || buttonByte == 1301) && flg148 == false) 
    {
      noteOn(channel, 72, vel2 );
      flg148 = true;
    }
    // C#3-O1 //
    if((buttonByte == 1280 || buttonByte == 1516) && flg151 == false)
    { 
      noteOn(channel, 73, vel2 );
      flg151 = true;
    }
    // D3-O1 //
    if(buttonByte == 1252 && flg154 == false)
    { 
      noteOn(channel, 74, vel2 );
      flg154 = true;
    }
    // D#3-O1 //
    if(buttonByte == 1764 && flg157 == false)
    { 
      noteOn(channel, 75, vel2 );
      flg157 = true;
    }
    // E3-O1 //
    if(buttonByte == 1124 && flg160 == false)
    {
      noteOn(channel, 76, vel2 );
      flg160 = true;
    }
    // F3-O1 //
    if(buttonByte == 1060 && flg163 == false)
    { 
      noteOn(channel, 77, vel2 );
      flg163 = true;
    }
    // F#3-O1 //
    if((buttonByte == 1092 || buttonByte == 1156 || buttonByte == 1188) && flg166 == false) 
    {
      noteOn(channel, 78, vel2);
      flg166 = true;
    }
    // G3-O1 //
    if((buttonByte == 1028 || buttonByte == 1415) && flg169 == false)
    {
      noteOn(channel, 79, vel2);
      flg169 = true;
    }
    // G#3-O1 //
    if((buttonByte == 1036 || buttonByte == 1423) && flg172 == false)
    { 
      noteOn(channel, 80, vel2);
      flg172 = true;
    }
    // A3-O1 //
    if(buttonByte == 1411 && flg175 == false)
    { 
      noteOn(channel, 81, vel2 );
      flg175 = true;
    }
    // A#3-O1 //
    if((buttonByte == 1425 || buttonByte == 1443 || buttonByte == 1441 || buttonByte == 1473) && flg178 == false)
    {
      noteOn(channel, 82, vel2);
      flg178 = true;
    }
    // B3-O1 //
    if(buttonByte == 1409 && flg181 == false)
    { 
      noteOn(channel, 83, vel2);
      flg181 = true;
    }
    // C4-O1 //
    if((buttonByte == 1410 || buttonByte == 1413 || buttonByte == 1429) && flg184 == false) 
    {
      noteOn(channel, 84, vel2 );
      flg184 = true;
    }
    // C#4-O1 //
    if(buttonByte == 1408 && flg187 == false) 
    { 
      noteOn(channel, 85, vel2 );
      flg187 = true;
    }
}






void Octave_1_Off(void)
{
    // C-O1 //
    if((buttonByte != 1511 || vel < 10) && flg76 == true)
    {
      noteOff(channel, 48, 0);
      flg76 = false;
    }
    // C#-O1 //
    if((buttonByte != 1519 || vel < 10) && flg79 == true)
    {
      noteOff(channel, 49, 0);
      flg79 = false;
    }
    // D-O1 //
    if((buttonByte != 1255 || vel < 10) && flg82 == true) 
    {
      noteOff(channel, 50, 0);
      flg82 = false;
    }
    // D#-O1 //
    if((buttonByte != 1767 || vel < 10) && flg85 == true)
    {
      noteOff(channel, 51, 0);
      flg85 = false;
    }
    // E-O1 //
    if((buttonByte != 1127 || vel < 10) && flg88 == true)
    {
      noteOff(channel, 52, 0);
      flg88 = false;
    }
    // F-O1 //
    if((buttonByte != 1063 || vel < 10) && flg91 == true)
    {
      noteOff(channel, 53, 0);
      flg91 = false;
    }
    // F#-O1 //
    if((buttonByte != 1095 && buttonByte != 1159 && buttonByte != 1191 || vel < 10) && flg94 == true)
    {
      noteOff(channel, 54, 0);
      flg94 = false;
    }
    // G-O1 //
    if((buttonByte != 1031 || vel < 10) && flg97 == true)
    {
      noteOff(channel, 55, 0);
      flg97 = false;
    }
    // G#-O1 //
    if((buttonByte != 1039 || vel < 10) && flg100 == true)
    {
      noteOff(channel, 56, 0);
      flg100 = false;
    }
    // A-O1 //
    if((buttonByte != 1027 || vel < 10) && flg103 == true)
    {
      noteOff(channel, 57, 0);
      flg103 = false;
    }
    // A#-O1 //
    if((buttonByte != 1041 && buttonByte != 1059 && buttonByte != 1057 && buttonByte != 1089 || vel < 10) && flg106 == true)
    {
      noteOff(channel, 58, 0);
      flg106 = false;
    }
    // B-O1 //
    if((buttonByte != 1025 || vel < 10) && flg109 == true)
    {
      noteOff(channel, 59, 0);
      flg109 = false;
    } 
    // C2-O1 //
    if((buttonByte != 1026 && buttonByte != 1029 && buttonByte != 1510 && buttonByte != 1045 || vel < 10) && flg112 == true)
    {
      noteOff(channel, 60, 0);
      flg112 = false;
    }
    // C#2-O1 //
    if((buttonByte != 1518 && buttonByte != 1024 || vel < 10) && flg115 == true)
    {
      noteOff(channel, 61, 0);
      flg115 = false;
    }
    // D2-O1 //
    if((buttonByte != 1254 || vel < 10) && flg118 == true)
    {
      noteOff(channel, 62, 0);
      flg118 = false;
    }
    // D#2-O1 //
    if((buttonByte != 1766 || vel < 10) && flg121 == true)
    {
      noteOff(channel, 63, 0);
      flg121 = false;
    }
    // E2-O1 //
    if((buttonByte != 1126 || vel < 10) && flg124 == true)
    {
      noteOff(channel, 64, 0);
      flg124 = false;
    }
    // F2-O1 //
    if((buttonByte != 1062 || vel < 10) && flg127 == true)
    {
      noteOff(channel, 65, 0);
      flg127 = false;
    }
    // F#2-O1 //
    if((buttonByte != 1094 && buttonByte != 1158 && buttonByte != 1190 || vel < 10) && flg130 == true) 
    {
      noteOff(channel, 66, 0);
      flg130 = false;
    }
    // G2-O1 //
    if((buttonByte != 1030 && buttonByte != 1287 || vel < 10) && flg133 == true) 
    {
      noteOff(channel, 67, 0);
      flg133 = false;
    }
    // G#2-O1 //
    if((buttonByte != 1038 && buttonByte != 1295 || vel < 10) && flg136 == true)
    {
      noteOff(channel, 68, 0);
      flg136 = false;
    }
    // A2-O1 //
    if((buttonByte != 1283 || vel < 10) && flg139 == true) 
    {
      noteOff(channel, 69, 0);
      flg139 = false;
    }
    // A#2-O1 //
    if((buttonByte != 1297 && buttonByte != 1315 && buttonByte != 1313 && buttonByte != 1345 || vel < 10) && flg142 == true) 
    {
      noteOff(channel, 70, 0);
      flg142 = false;
    }
    // B2-O1 //
    if((buttonByte != 1281 || vel < 10) && flg145 == true) 
    {
      noteOff(channel, 71, 0);
      flg145 = false;
    }
    // C3-O1 //
    if((buttonByte != 1282 && buttonByte != 1285 && buttonByte != 1508 && buttonByte != 1301 || vel < 10) && flg148 == true) 
    {
      noteOff(channel, 72, 0);
      flg148 = false;
    }
    // C#3-O1 //
    if((buttonByte != 1280 && buttonByte != 1516 || vel < 10) && flg151 == true) 
    {
      noteOff(channel, 73, 0);
      flg151 = false;
    }
    // D3-O1 //
    if((buttonByte != 1252 || vel < 10) && flg154 == true) 
    {
      noteOff(channel, 74, 0);
      flg154 = false;
    }
    // D#3-O1 //
    if((buttonByte != 1764 || vel < 10) && flg157 == true)
    {
      noteOff(channel, 75, 0);
      flg157 = false;
    }
    // E3-O1 //
    if((buttonByte != 1124 || vel < 10) && flg160 == true) 
    {
      noteOff(channel, 76, 0);
      flg160 = false;
    }
    // F3-O1 //
    if((buttonByte != 1060 || vel < 10) && flg163 == true) 
    {
      noteOff(channel, 77, 0);
      flg163 = false;
    }
    // F#3-O1 //
    if((buttonByte != 1092 && buttonByte != 1156 && buttonByte != 1188 || vel < 10) && flg166 == true) 
    {
      noteOff(channel, 78, 0);
      flg166 = false;
    }
    // G3-O1 //
    if((buttonByte != 1028 && buttonByte != 1415 || vel < 10) && flg169 == true)
    {
      noteOff(channel, 79, 0);
      flg169 = false;
    }
    // G#3-O1 //
    if((buttonByte != 1036 && buttonByte != 1423 || vel < 10) && flg172 == true)
    {
      noteOff(channel, 80, 0);
      flg172 = false;
    }
    // A3-O1 //
    if((buttonByte != 1411 || vel < 10) && flg175 == true)
    {
      noteOff(channel, 81, 0);
      flg175 = false;
    }
    // A#3-O1 //
    if((buttonByte != 1425 && buttonByte != 1443 && buttonByte != 1441 && buttonByte != 1473 || vel < 10) && flg178 == true)
    {
      noteOff(channel, 82, 0);
      flg178 = false;
    }
    // B3-O1 //
    if((buttonByte != 1409 || vel < 10) && flg181 == true) 
    {
      noteOff(channel, 83, 0);
      flg181 = false;
    }
    // C4-O1 //
    if((buttonByte != 1410 && buttonByte != 1413 && buttonByte != 1429 || vel < 10) && flg184 == true) 
    {
      noteOff(channel, 84, 0);
      flg184 = false;
    }
    // C#4-O1 //
    if((buttonByte != 1408 || vel < 10) && flg187 == true) 
    {
      noteOff(channel, 85, 0);
      flg187 = false;
    }
}

void Octave_2_On(void)
{
    // C-O2 //
    if(buttonByte == 2535 && flg77 == false) 
    {
      noteOn(channel, 60, vel2);
      flg77 = true;
    }
    // C#-O2 //
    if(buttonByte == 2543 && flg80 == false)
    {
      noteOn(channel, 61, vel2);
      flg80 = true;
    }
    // D-O2 //
    if(buttonByte == 2279 && flg83 == false)
    {
      noteOn(channel, 62, vel2);
      flg83 = true;
    }
    // D#-O2 //
    if(buttonByte == 2791 && flg86 == false) 
    {
      noteOn(channel, 63, vel2);
      flg86 = true;
    }
    // E-O2 //
    if(buttonByte == 2151 && flg89 == false)
    {
      noteOn(channel, 64, vel2);
      flg89 = true;
    }
    // F-O2 //
    if(buttonByte == 2087 && flg92 == false) 
    {
      noteOn(channel, 65, vel2);
      flg92 = true;
    }
    // F#-O2 //
    if((buttonByte == 2119 || buttonByte == 2183 || buttonByte == 2215) && flg95 == false)
    {
      noteOn(channel, 66, vel2);
      flg95 = true;
    }
    // G-O2 //
    if(buttonByte == 2055 && flg98 == false) 
    {
      noteOn(channel, 67, vel2);
      flg98 = true;
    }
    // G#-O2 //
    if(buttonByte == 2063 && flg101 == false)
    {
      noteOn(channel, 68, vel2);
      flg101 = true;
    }
    // A-O2 //
    if(buttonByte == 2051 && flg104 == false)
    {
      noteOn(channel, 69, vel2);
      flg104 = true;
    }
    // A#-O2 //
    if((buttonByte == 2065 || buttonByte == 2083 || buttonByte == 2081 || buttonByte == 2113) && flg107 == false)
    {
      noteOn(channel, 70, vel2);
      flg107 = true;
    }
    // B-O2 //
    if(buttonByte == 2049 && flg110 == false)
    { 
      noteOn(channel, 71, vel2);
      flg110 = true;
    }
    // C2-O2 //
    if((buttonByte == 2050 || buttonByte == 2053 || buttonByte == 2534 || buttonByte == 2069) && flg113 == false) 
    {
      noteOn(channel, 72, vel2 );
      flg113 = true;
    }
    // C#2-O2 //
    if((buttonByte == 2542 || buttonByte == 2048) && flg116 == false) 
    { 
      noteOn(channel, 73, vel2 );
      flg116 = true;
    }
    // D2-O2 //
    if(buttonByte == 2278 && flg119 == false)
    {
      noteOn(channel, 74, vel2 );
      flg119 = true;
    }
    // D#2-O2 //
    if(buttonByte == 2790 && flg122 == false) 
    {
      noteOn(channel, 75, vel2 );
      flg122 = true;
    }
    // E2-O2 //
    if(buttonByte == 2150 && flg125 == false)
    { 
      noteOn(channel, 76, vel2 );
      flg125 = true;
    }
    // F2-O2 //
    if(buttonByte == 2086 && flg128 == false)
    {
      noteOn(channel, 77, vel2 );
      flg128 = true;
    }
    // F#2-O2 //
    if((buttonByte == 2118 || buttonByte == 2182 || buttonByte == 2214) && flg131 == false)
    {
      noteOn(channel, 78, vel2);
      flg131 = true;
    }
    // G2-O2 //
    if((buttonByte == 2054 || buttonByte == 2311) && flg134 == false)
    {
      noteOn(channel, 79, vel2);
      flg134 = true;
    }
    // G#2-O2 //
    if((buttonByte == 2062 || buttonByte == 2319) && flg137 == false)
    {
      noteOn(channel, 80, vel2);
      flg137 = true;
    }
    // A2-O2 //
    if(buttonByte == 2307 && flg140 == false)
    { 
      noteOn(channel, 81, vel2 );
      flg140 = true;
    }
    // A#2-O2 //
    if((buttonByte == 2321 || buttonByte == 2339 || buttonByte == 2337 || buttonByte == 2369) && flg143 == false)
    {
      noteOn(channel, 82, vel2);
      flg143 = true;
    }
    // B2-O2 //
    if(buttonByte == 2305 && flg146 == false)
    { 
      noteOn(channel, 83, vel2);
      flg146 = true;
    }
    // C3-O2 //
    if((buttonByte == 2306 || buttonByte == 2309 || buttonByte == 2532 || buttonByte == 2325) && flg149 == false) 
    {
      noteOn(channel, 84, vel2 );
      flg149 = true;
    }
    // C#3-O2 //
    if((buttonByte == 2304 || buttonByte == 2540) && flg152 == false) 
    { 
      noteOn(channel, 85, vel2 );
      flg152 = true;
    }
    // D3-O2 //
    if(buttonByte == 2276 && flg155 == false)
    { 
      noteOn(channel, 86, vel2 );
      flg155 = true;
    }
    // D3-O2 //
    if(buttonByte == 2788 && flg158 == false)
    { 
      noteOn(channel, 87, vel2 );
      flg158 = true;
    }
    // E3-O2 //
    if(buttonByte == 2148 && flg161 == false) 
    {
      noteOn(channel, 88, vel2 );
      flg161 = true;
    }
    // F3-O2 //
    if(buttonByte == 2084 && flg164 == false) 
    { 
      noteOn(channel, 89, vel2 );
      flg164 = true;
    }
    // F#3-O2 //
    if((buttonByte == 2116 || buttonByte == 2180 || buttonByte == 2212) && flg167 == false) 
    {
      noteOn(channel, 90, vel2);
      flg167 = true;
    }
    // G3-O2 //
    if((buttonByte == 2052 || buttonByte == 2439) && flg170 == false) 
    {
      noteOn(channel, 91, vel2);
      flg170 = true;
    }
    // G#3-O2 //
    if((buttonByte == 2060 || buttonByte == 2447) && flg173 == false)
    { 
      noteOn(channel, 92, vel2);
      flg173 = true;
    }
    // A3-O2 //
    if(buttonByte == 2435 && flg176 == false) 
    { 
      noteOn(channel, 93, vel2 );
      flg176 = true;
    }
    // A#3-O2 //
    if((buttonByte == 2449 || buttonByte == 2467 || buttonByte == 2465 || buttonByte == 2497) && flg179 == false)
    {
      noteOn(channel, 94, vel2);
      flg179 = true;
    }
    // B3-O2 //
    if(buttonByte == 2433 && flg182 == false)
    { 
      noteOn(channel, 95, vel2);
      flg182 = true;
    }
    // C4-O2 //
    if((buttonByte == 2434 || buttonByte == 2437 || buttonByte == 2453) && flg185 == false) 
    {
      noteOn(channel, 96, vel2 );
      flg185 = true;
    }
    // C#4-O2 //
    if(buttonByte == 2432 && flg188 == false)
    { 
      noteOn(channel, 97, vel2 );
      flg188 = true;
    }
}
void Octave_2_Off(void)
{
    // C-O2 //
    if((buttonByte != 2535 || vel < 10) && flg77 == true) 
    {
      noteOff(channel, 60, 0);
      flg77 = false;
    }
    // C#-O2 //
    if((buttonByte != 2543 || vel < 10) && flg80 == true) 
    {
      noteOff(channel, 61, 0);
      flg80 = false;
    }
    // D-O2 //
    if((buttonByte != 2279 || vel < 10) && flg83 == true) 
    {
      noteOff(channel, 62, 0);
      flg83 = false;
    }    
    // D#-O2 //
    if((buttonByte != 2791 || vel < 10) && flg86 == true)
    {
      noteOff(channel, 63, 0);
      flg86 = false;
    }
    // E-O2 //
    if((buttonByte != 2151 || vel < 10) && flg89 == true)
    {
      noteOff(channel, 64, 0);
      flg89 = false;
    }
    // F-O2 //
    if((buttonByte != 2087 || vel < 10) && flg92 == true)
    {
      noteOff(channel, 65, 0);
      flg92 = false;
    }
    // F#-O2 //
    if((buttonByte != 2119 && buttonByte != 2183 && buttonByte != 2215 || vel < 10) && flg95 == true)
    {
      noteOff(channel, 66, 0);
      flg95 = false;
    }
    // G-O2 //
    if((buttonByte != 2055 || vel < 10) && flg98 == true)
    {
      noteOff(channel, 67, 0);
      flg98 = false;
    }
    // G#-O2 //
    if((buttonByte != 2063 || vel < 10) && flg101 == true)
    {
      noteOff(channel, 68, 0);
      flg101 = false;
    }
    // A-O2 //
    if((buttonByte != 2051 || vel < 10) && flg104 == true)
    {
      noteOff(channel, 69, 0);
      flg104 = false;
    }
    // A#-O2 //
    if((buttonByte != 2065 && buttonByte != 2083 && buttonByte != 2081 && buttonByte != 2113 || vel < 10) && flg107 == true)
    {
      noteOff(channel, 70, 0);
      flg107 = false;
    }
    // B-O2 //
    if((buttonByte != 2049 || vel < 10) && flg110 == true)
    {
      noteOff(channel, 71, 0);
      flg110 = false;
    } 
    // C2-O2 //
    if((buttonByte != 2050 && buttonByte != 2053 && buttonByte != 2534 && buttonByte != 2069 || vel < 10) && flg113 == true)
    {
      noteOff(channel, 72, 0);
      flg113 = false;
    }
    // C#2-O2 //
    if((buttonByte != 2542 && buttonByte != 2048 || vel < 10) && flg116 == true)
    {
      noteOff(channel, 73, 0);
      flg116 = false;
    }    
    // D2-O2 //
    if((buttonByte != 2278 || vel < 10) && flg119 == true)
    {
      noteOff(channel, 74, 0);
      flg119 = false;
    }
    // D#2-O2 //
    if((buttonByte != 2790 || vel < 10) && flg122 == true)
    {
      noteOff(channel, 75, 0);
      flg122 = false;
    }
    // E2-O2 //
    if((buttonByte != 2150 || vel < 10) && flg125 == true)
    {
      noteOff(channel, 76, 0);
      flg125 = false;
    }
    // F2-O2 //
    if((buttonByte != 2086 || vel < 10) && flg128 == true)
    {
      noteOff(channel, 77, 0);
      flg128 = false;
    }
    // F#2-O2 //
    if((buttonByte != 2118 && buttonByte != 2182 && buttonByte != 2214 || vel < 10) && flg131 == true) 
    {
      noteOff(channel, 78, 0);
      flg131 = false;
    }
    // G2-O2 //
    if((buttonByte != 2054 && buttonByte != 2311 || vel < 10) && flg134 == true) 
    {
      noteOff(channel, 79, 0);
      flg134 = false;
    }
    // G#2-O2 //
    if((buttonByte != 2062 && buttonByte != 2319 || vel < 10) && flg137 == true)
    {
      noteOff(channel, 80, 0);
      flg137 = false;
    }
    // A2-O2 //
    if((buttonByte != 2307 || vel < 10) && flg140 == true) 
    {
      noteOff(channel, 81, 0);
      flg140 = false;
    }
    // A#2-O2 //
    if((buttonByte != 2321 && buttonByte != 2339 && buttonByte != 2337 && buttonByte != 2369 || vel < 10) && flg143 == true) 
    {
      noteOff(channel, 82, 0);
      flg143 = false;
    }
    // B2-O2 //
    if((buttonByte != 2305 || vel < 10) && flg146 == true) 
    {
      noteOff(channel, 83, 0);
      flg146 = false;
    }
    // C3-O2 //
    if((buttonByte != 2306 && buttonByte != 2309 && buttonByte != 2532 && buttonByte != 2325 || vel < 10) && flg149 == true) 
    {
      noteOff(channel, 84, 0);
      flg149 = false;
    }
    // C#3-O2 //
    if((buttonByte != 2304 && buttonByte != 2540 || vel < 10) && flg152 == true) 
    {
      noteOff(channel, 85, 0);
      flg152 = false;
    }
    // D3-O2 //
    if((buttonByte != 2276 || vel < 10) && flg155 == true) 
    {
      noteOff(channel, 86, 0);
      flg155 = false;
    }
    // D#3-O2 //
    if((buttonByte != 2788 || vel < 10) && flg158 == true)
    {
      noteOff(channel, 87, 0);
      flg158 = false;
    }
    // E3-O2 //
    if((buttonByte != 2148 || vel < 10) && flg161 == true) 
    {
       
      noteOff(channel, 88, 0);
      flg161 = false;
    }
    // F3-O2 //
    if((buttonByte != 2084 || vel < 10) && flg164 == true) 
    {
      noteOff(channel, 89, 0);
      flg164 = false;
    }
    // F#3-O2 //
    if((buttonByte != 2116 && buttonByte != 2180 && buttonByte != 2212 || vel < 10) && flg167 == true) 
    {
      noteOff(channel, 90, 0);
      flg167 = false;
    }
    // G3-O2 //
    if((buttonByte != 2052 && buttonByte != 2439 || vel < 10) && flg170 == true)
    {
      noteOff(channel, 91, 0);
      flg170 = false;
    }
    // G#3-O2 //
    if((buttonByte != 2060 && buttonByte != 2447 || vel < 10) && flg173 == true)
    {
      noteOff(channel, 92, 0);
      flg173 = false;
    }
    // A3-O2 //
    if((buttonByte != 2435 || vel < 10) && flg176 == true)
    {
      noteOff(channel, 93, 0);
      flg176 = false;
    }
    // A#3-O2 //
    if((buttonByte != 2449 && buttonByte != 2467 && buttonByte != 2465 && buttonByte != 2497 || vel < 10) && flg179 == true)
    {
      noteOff(channel, 94, 0);
      flg179 = false;
    }
    // B3-O2 //
    if((buttonByte != 2433 || vel < 10) && flg182 == true) 
    {
      noteOff(channel, 95, 0);
      flg182 = false;
    }
    // C4-O2 //
    if((buttonByte != 2434 && buttonByte != 2437 && buttonByte != 2453 || vel < 10) && flg185 == true) 
    {
      noteOff(channel, 96, 0);
      flg185 = false;
    }
    // C#4-O2 //
    if((buttonByte != 2432 || vel < 10) && flg188 == true) 
    {
      noteOff(channel, 97, 0);
      flg188 = false;
    }
}






void Octave_3_On(void)
{
    // C //
    if((buttonByte == 4583) && flg78 == false)
    {
      noteOn(channel, 72, vel2);
      flg78 = true;
    }
    // C# //
    if((buttonByte == 4591) && flg81 == false)
    {
      noteOn(channel, 73, vel2);
      flg81 = true;
    }
    // D //
    if(buttonByte == 4327 && flg84 == false)
    {
      noteOn(channel, 74, vel2);
      flg84 = true;
    }
    // D# //
    if(buttonByte == 4839 && flg87 == false)
    {
      noteOn(channel, 75, vel2);
      flg87 = true;
    }
    // E //
    if(buttonByte == 4199 && flg90 == false)
    {
      noteOn(channel, 76, vel2);
      flg90 = true;
    }
    // F //
    if(buttonByte == 4135 && flg93 == false)
    {
      noteOn(channel, 77, vel2);
      flg93 = true;
    }
    // F# //
    if((buttonByte == 4167 || buttonByte == 4231 || buttonByte == 4263) && flg96 == false)
    {
      noteOn(channel, 78, vel2);
      flg96 = true;
    }
    // G //
    if((buttonByte == 4103) && flg99 == false)
    {
      noteOn(channel, 79, vel2);
      flg99 = true;
    }
    // G# //
    if((buttonByte == 4111) && flg102 == false)
    {
      noteOn(channel, 80, vel2);
      flg102 = true;
    }
    // A //
    if((buttonByte == 4099) && flg105 == false)
    {
      noteOn(channel, 81, vel2);
      flg105 = true;
    }
    // A# //
    if((buttonByte == 4113 || buttonByte == 4131 || buttonByte == 4129 || buttonByte == 4161) && flg108 == false)
    {
      noteOn(channel, 82, vel2);
      flg108 = true;
    }
    // B //
    if(buttonByte == 4097 && flg111 == false)
    { 
      noteOn(channel, 83, vel2);
      flg111 = true;
    }
    // C2 //
    if((buttonByte == 4098 || buttonByte == 4101 || buttonByte == 4582 || buttonByte == 4117) && flg114 == false)
    {
      noteOn(channel, 84, vel2 );
      flg114 = true;
    }
    // C#2 //
    if((buttonByte == 4590 || buttonByte == 4096) && flg117 == false)
    { 
      noteOn(channel, 85, vel2 );
      flg117 = true;
    }
    // D2 //
    if(buttonByte == 4326 && flg120 == false)
    {
      noteOn(channel, 86, vel2 );
      flg120 = true;
    }
    // D#2 //
    if(buttonByte == 4838 && flg123 == false)
    {
      noteOn(channel, 87, vel2 );
      flg123 = true;
    }
    // E2 //
    if(buttonByte == 4198 && flg126 == false)
    { 
      noteOn(channel, 88, vel2 );
      flg126 = true;
    }
    // F2 //
    if(buttonByte == 4134 && flg129 == false)
    {
      noteOn(channel, 89, vel2 );
      flg129 = true;
    }
    // F#2 //
    if((buttonByte == 4166 || buttonByte == 4230 || buttonByte == 4262) && flg132 == false)
    {
      noteOn(channel, 90, vel2);
      flg132 = true;
    }
    // G2 //
    if((buttonByte == 4102 || buttonByte == 4359) && flg135 == false)
    {
      noteOn(channel, 91, vel2);
      flg135 = true;
    }
    // G#2 //
    if((buttonByte == 4110 || buttonByte == 4367) && flg138 == false)
    {
      noteOn(channel, 92, vel2);
      flg138 = true;
    }
    // A2 //
    if((buttonByte == 4355) && flg141 == false)
    { 
      noteOn(channel, 93, vel2 );
      flg141 = true;
    }
    // A#2 //
    if((buttonByte == 4369 || buttonByte == 4387 || buttonByte == 4385 || buttonByte == 4417) && flg144 == false)
    {
      noteOn(channel, 94, vel2);
      flg144 = true;
    }
    // B2 //
    if(buttonByte == 4353 && flg147 == false)
    { 
      noteOn(channel, 95, vel2);
      flg147 = true;
    }
    // C3 //
    if((buttonByte == 4354 || buttonByte == 4357 || buttonByte == 4580 || buttonByte == 4373) && flg150 == false)
    {
      noteOn(channel, 96, vel2 );
      flg150 = true;
    }
    // C#3 //
    if((buttonByte == 4352 || buttonByte == 4588) && flg153 == false)
    { 
      noteOn(channel, 97, vel2 );
      flg153 = true;
    }
    // D3 //
    if(buttonByte == 4324 && flg156 == false)
    { 
      noteOn(channel, 98, vel2 );
      flg156 = true;
    }
    // D#3 //
    if(buttonByte == 4836 && flg159 == false) 
    { 
      noteOn(channel, 99, vel2 );
      flg159 = true;
    }
    // E3 //
    if(buttonByte == 4196 && flg162 == false)
    {
      noteOn(channel, 100, vel2 );
      flg162 = true;
    }
    // F3 //
    if(buttonByte == 4132 && flg165 == false)
    { 
      noteOn(channel, 101, vel2 );
      flg165 = true;
    }
    // F#3 //
    if((buttonByte == 4164 || buttonByte == 4228 || buttonByte == 4260) && flg168 == false)
    {
      noteOn(channel, 102, vel2);
      flg168 = true;
    }
    // G3 //
    if((buttonByte == 4100 || buttonByte == 4487) && flg171 == false)
    {
      noteOn(channel, 103, vel2);
      flg171 = true;
    }
    // G#3 //
    if((buttonByte == 4108 || buttonByte == 4495) && flg174 == false)
    { 
      noteOn(channel, 104, vel2);
      flg174 = true;
    }
    // A3 //
    if((buttonByte == 4483) && flg177 == false)
    { 
      noteOn(channel, 105, vel2 );
      flg177 = true;
    }
    // A#3 //
    if((buttonByte == 4497 || buttonByte == 4515 || buttonByte == 4513 || buttonByte == 4545) && flg180 == false)
    {
      noteOn(channel, 106, vel2);
      flg180 = true;
    }
    // B3 //
    if(buttonByte == 4481 && flg183 == false)
    { 
      noteOn(channel, 107, vel2);
      flg183 = true;
    }
    // C4 //
    if((buttonByte == 4482 || buttonByte == 4485 || buttonByte == 4501) && flg186 == false)
    {
      noteOn(channel, 108, vel2 );
      flg186 = true;
    }
    // C#4 //
    if(buttonByte == 4480 && flg189 == false)
    { 
      noteOn(channel, 109, vel2 );
      flg189 = true;
    }
}

void Octave_3_Off(void)
{
    // C-O3 //
    if((buttonByte != 4583 || vel < 10) && flg78 == true) 
    {
      noteOff(channel, 72, 0);
      flg78 = false;
    }
    // C#-O3 //
    if((buttonByte != 4591 || vel < 10) && flg81 == true) 
    {
      noteOff(channel, 73, 0);
      flg81 = false;
    }
    // D-O3 //
    if((buttonByte != 4327 || vel < 10) && flg84 == true) 
    {
      noteOff(channel, 74, 0);
      flg84 = false;
    }
    // D#-O3 //
    if((buttonByte != 4839 || vel < 10) && flg87 == true)
    {
      noteOff(channel, 75, 0);
      flg87 = false;
    }
    // E-O3 //
    if((buttonByte != 4199 || vel < 10) && flg90 == true)
    {
      noteOff(channel, 76, 0);
      flg90 = false;
    }
    // F-O3 //
    if((buttonByte != 4135 || vel < 10) && flg93 == true)
    {
      noteOff(channel, 77, 0);
      flg93 = false;
    }
    // F#-O3 //
    if((buttonByte != 4167 && buttonByte != 4231 && buttonByte != 4263 || vel < 10) && flg96 == true)
    {
      noteOff(channel, 78, 0);
      flg96 = false;
    }
    // G-O3 //
    if((buttonByte != 4103 || vel < 10) && flg99 == true)
    {
      noteOff(channel, 79, 0);
      flg99 = false;
    }
    // G#-O3 //
    if((buttonByte != 4111 || vel < 10) && flg102 == true)
    {
      noteOff(channel, 80, 0);
      flg102 = false;
    }
    // A-O3 //
    if((buttonByte != 4099 || vel < 10) && flg105 == true)
    {
      noteOff(channel, 81, 0);
      flg105 = false;
    }
    // A#-O3 //
    if((buttonByte != 14113 && buttonByte != 4131 && buttonByte != 4129 && buttonByte != 4161 || vel < 10) && flg108 == true)
    {
      noteOff(channel, 82, 0);
      flg108 = false;
    }
    // B-O3 //
    if((buttonByte != 4097 || vel < 10) && flg111 == true)
    {
      noteOff(channel, 83, 0);
      flg111 = false;
    }
    // C2-O3 //
    if((buttonByte != 4098 && buttonByte != 4101 && buttonByte != 4582 && buttonByte != 4117 || vel < 10) && flg114 == true)
    {
      noteOff(channel, 84, 0);
      flg114 = false;
    }
    // C#2-O3 //
    if((buttonByte != 4590 && buttonByte != 4096 || vel < 10) && flg117 == true)
    {
      noteOff(channel, 85, 0);
      flg117 = false;
    }
    // D2-O3 //
    if((buttonByte != 4326 || vel < 10) && flg120 == true)
    {
      noteOff(channel, 86, 0);
      flg120 = false;
    }
    // D#2-O3 //
    if((buttonByte != 4838 || vel < 10) && flg123 == true)
    {
      noteOff(channel, 87, 0);
      flg123 = false;
    }
    // E2-O3 //
    if((buttonByte != 4198 || vel < 10) && flg126 == true)
    {
      noteOff(channel, 88, 0);
      flg126 = false;
    }
    // F2-O3 //
    if((buttonByte != 4134 || vel < 10) && flg129 == true)
    {
      noteOff(channel, 89, 0);
      flg129 = false;
    }
    // F#2-O3 //
    if((buttonByte != 4166 && buttonByte != 4230 && buttonByte != 4262 || vel < 10) && flg132 == true) 
    {
      noteOff(channel, 90, 0);
      flg132 = false;
    }
    // G2-O3 //
    if((buttonByte != 4102 && buttonByte != 4359 || vel < 10) && flg135 == true) 
    {
      noteOff(channel, 91, 0);
      flg135 = false;
    }
    // G#2-O3 //
    if((buttonByte != 4110 && buttonByte != 4367 || vel < 10) && flg138 == true)
    {
      noteOff(channel, 92, 0);
      flg138 = false;
    }
    // A2-O3 //
    if((buttonByte != 4355 || vel < 10) && flg141 == true) 
    {
      noteOff(channel, 93, 0);
      flg141 = false;
    }
    // A#2-O3 //
    if((buttonByte != 4369 && buttonByte != 4387 && buttonByte != 4385 && buttonByte != 4417 || vel < 10) && flg144 == true) 
    {
      noteOff(channel, 94, 0);
      flg144 = false;
    }
    // B2-O3 //
    if((buttonByte != 4353 || vel < 10) && flg147 == true) 
    {
      noteOff(channel, 95, 0);
      flg147 = false;
    }
    // C3-O3 //
    if((buttonByte != 4354 && buttonByte != 4357 && buttonByte != 4580 && buttonByte != 4373 || vel < 10) && flg150 == true) 
    {
      noteOff(channel, 96, 0);
      flg150 = false;
    }
    // C#3-O3 //
    if((buttonByte != 4352 && buttonByte != 4588 || vel < 10) && flg153 == true) 
    {
      noteOff(channel, 97, 0);
      flg153 = false;
    }
    // D3-O3 //
    if((buttonByte != 4324 || vel < 10) && flg156 == true) 
    {
      noteOff(channel, 98, 0);
      flg156 = false;
    }
    // D#3-O3 //
    if((buttonByte != 4836 || vel < 10) && flg159 == true)
    {
      noteOff(channel, 99, 0);
      flg159 = false;
    }
    // E3-O3 //
    if((buttonByte != 4196 || vel < 10) && flg162 == true) 
    {
      noteOff(channel, 100, 0);
      flg162 = false;
    }
    // F3-O3 //
    if((buttonByte != 4132 || vel < 10) && flg165 == true) 
    {
      noteOff(channel, 101, 0);
      flg165 = false;
    }
    // F#3-O3 //
    if((buttonByte != 4164 && buttonByte != 4228 && buttonByte != 4260 || vel < 10) && flg168 == true) 
    {
      noteOff(channel, 102, 0);
      flg168 = false;
    }
     // G3-O3 //
    if((buttonByte != 4100 && buttonByte != 4487 || vel < 10) && flg171 == true)
    {
      noteOff(channel, 103, 0);
      flg171 = false;
    }
    // G#3-O3 //
    if((buttonByte != 4108 && buttonByte != 4495 || vel < 10) && flg174 == true)
    {
      noteOff(channel, 104, 0);
      flg174 = false;
    }
    // A3-O3 //
    if((buttonByte != 4483 || vel < 10) && flg177 == true)
    { 
      noteOff(channel, 105, 0);
      flg177 = false;
    }
    // A#3-O3 //
    if((buttonByte != 4497 && buttonByte != 4515 && buttonByte != 4513 && buttonByte != 4545 || vel < 10) && flg180 == true)
    {
      noteOff(channel, 106, 0);
      flg180 = false;
    }
    // B3-O3 //
    if((buttonByte != 4481 || vel < 10) && flg183 == true) 
    {
      noteOff(channel, 107, 0);
      flg183 = false;
    }
    // C4-O3 //
    if((buttonByte != 4482 && buttonByte != 4485 && buttonByte != 4501 || vel < 10) && flg186 == true) 
    {
      noteOff(channel, 108, 0);
      flg186 = false;
    }
    // C#4-O3 //
    if((buttonByte != 4480 || vel < 10) && flg189 == true) 
    {
      noteOff(channel, 109, 0);
      flg189 = false;
    }
}