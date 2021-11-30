/* PT2322 6 channel audio processor library for arduino.
written by zuhail
https://github.com/zuhl-c */

#ifndef  PT2322_H
#define  PT2322_H

#define ADDRESS 0x44 // address//
#define IN_SW   0xC7 //activation inputs//
#define VOL_1S  0xD0 //volume per 1dB step//
#define VOL_10S 0xE0 //volume per 10dB step//
#define ATT_FL  0x10 //fl//
#define ATT_FR  0x20 //fr//
#define ATT_CT  0x30 //ct//
#define ATT_SL  0x40 //sl
#define ATT_SR  0x50 //sr//
#define ATT_SUB 0x60 //sub//
#define FUNC    0x70 //function//
#define BASS    0x90 //bass//
#define MID     0xA0 //mid//
#define TREBLE  0xB0 //treble//
#define TRIM    0x0F //trim volume max


#include <Arduino.h>

class  PT2322
{
  public:
     PT2322();
        void ActiveIn(); //first call this function for enable inputs

        // -15...0dB (15...0)
        void setFrontLeft(int fl);// front L
        void setFrontRight(int fr);// front R
        void setCenter(int cn);     // center
        void setSurroundLeft(int sl); // surround L
        void setSurroundRight(int sr); // surround R
        void setSubwoofer(int sub);      // SUB
        
        void setFunc(int mute, int _3d, int tone);// mute (0/1),3d(0/1),tone controll(0/1)

        void setBass(int bass);   // BASS    -14...0...14 dB (2dB/step,-7..0..7)
        void setMiddle(int mid);  // MIDDLE  -14...0...14 dB (2dB/step,-7..0..7)
        void setTreble(int treble);  // TREBLE  -14...0...14 dB (2dB/step,-7..0..7)
        
        void setVolume(int vol);     // VOLUME  -79...0 dB (0...79)
  private:
	void writeWire(char a);
};
	
#endif // PT2322_H