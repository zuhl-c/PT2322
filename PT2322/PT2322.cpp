#include <Arduino.h>
#include <Wire.h>
#include "PT2322.h"

PT2322::PT2322(){
	Wire.begin();
}
void PT2322::setVolume(int vol){
   vol = vol - 79;
   vol = abs(vol);
   int vol_10 = vol / 10; //10dB  /step (0 for 0dB ,1 for -10dB)
   int vol_1 = vol - vol_10 * 10;//1dB /step
  writeWire(VOL_10S + vol_10);
  writeWire(VOL_1S + vol_1);
}

void PT2322::setFrontLeft(int fl){
   fl=15-fl;
   writeWire(ATT_FL+fl);
             
}

void PT2322::setFrontRight(int fr){
   fr=15-fr;
   writeWire(ATT_FR+fr);
}

void PT2322::setCenter(int ct){
   ct=15-ct;
   writeWire(ATT_CT+ct);
}

void PT2322::setSurroundLeft(int sl){
   sl=15-sl;
   writeWire(ATT_SL+sl);
}

void PT2322::setSurroundRight(int sr){
   sr=15-sr;
   writeWire(ATT_SR+sr);
}

void PT2322::setSubwoofer(int sub){
   sub=15-sub;
   writeWire(ATT_SUB+sub);
}

void PT2322::setFunc(int mute, int _3d, int tone_d){
                   switch(mute){
                      case 0: mute = 0x00; break;//unmute
                      case 1: mute = 0x08; break;//mute
                      }
                   switch(_3d){
                      case 0: _3d = 0x00; break;//3d on
                      case 1: _3d = 0x04; break;//3d off
                      }
                   switch(tone_d){
                      case 0: tone_d = 0x00; break;//tone control on
                      case 1: tone_d = 0x02; break;//tone defeat
                      }
             writeWire(FUNC + mute + _3d + tone_d);
}

void PT2322::setBass(int bass){
                   switch(bass){
                      case -7: bass = 0x00; break;//-14dB
                      case -6: bass = 0x01; break;
                      case -5: bass = 0x02; break;
                      case -4: bass = 0x03; break;
                      case -3: bass = 0x04; break;
                      case -2: bass = 0x05; break;
                      case -1: bass = 0x06; break;
                      case  0: bass = 0x07; break;//0dB
                      case  1: bass = 0x0E; break;
                      case  2: bass = 0x0D; break;
                      case  3: bass = 0x0C; break;
                      case  4: bass = 0x0B; break;
                      case  5: bass = 0x0A; break;
                      case  6: bass = 0x09; break;
                      case  7: bass = 0x08; break;//+14dB
                      }
               writeWire(BASS + bass);
}

void PT2322::setMiddle(int mid){
                   switch(mid){
                      case -7: mid = 0x00; break;//-14dB
                      case -6: mid = 0x01; break;
                      case -5: mid = 0x02; break;
                      case -4: mid = 0x03; break;
                      case -3: mid = 0x04; break;
                      case -2: mid = 0x05; break;
                      case -1: mid = 0x06; break;
                      case  0: mid = 0x07; break;//0dB
                      case  1: mid = 0x0E; break;
                      case  2: mid = 0x0D; break;
                      case  3: mid = 0x0C; break;
                      case  4: mid = 0x0B; break;
                      case  5: mid = 0x0A; break;
                      case  6: mid = 0x09; break;
                      case  7: mid = 0x08; break;//+14dB
                      }
               writeWire(MID + mid);
}

void PT2322::setTreble(int treble){
                   switch(treble){
                      case -7: treble = 0x00; break;//-14dB
                      case -6: treble = 0x01; break;
                      case -5: treble = 0x02; break;
                      case -4: treble = 0x03; break;
                      case -3: treble = 0x04; break;
                      case -2: treble = 0x05; break;
                      case -1: treble = 0x06; break;
                      case  0: treble = 0x07; break;//0dB
                      case  1: treble = 0x0E; break;
                      case  2: treble = 0x0D; break;
                      case  3: treble = 0x0C; break;
                      case  4: treble = 0x0B; break;
                      case  5: treble = 0x0A; break;
                      case  6: treble = 0x09; break;
                      case  7: treble = 0x08; break;//+14dB
                      }
               writeWire(TREBLE + treble);
}
 


void PT2322::writeWire(char a){
  Wire.beginTransmission(ADDRESS);
  Wire.write (a);
  Wire.endTransmission();
}
void PT2322::ActiveIn(){
   Wire.beginTransmission(ADDRESS);
   Wire.write (IN_SW);
   Wire.endTransmission();
}