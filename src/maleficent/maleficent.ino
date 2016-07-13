/*
#                     MALEFICENT DRESS
#
# Software to manage RBG LED strips on Maleficent dress
#
# Copyright (c) 2015 Tiziana Dallapè
# Copyright (c) 2015 Matteo Perini
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation
#
# See LICENSE file for details
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc.,59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# See https://github.com/FashionFabLab/Maleficent_dress for detailed project
*/



#include <Adafruit_NeoPixel.h>   //add libraries


/*----------------------------------------------------------------------
 objects and variables declarations and definitions list
----------------------------------------------------------------------*/
#define PIN 6           //attach strip data input to pin 6
#define num_LED 60      //define number of pixels on a strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_LED, PIN, NEO_GRB + NEO_KHZ800);   //define the strip
const int sensor = 9;   //attach push button to pin 9
//service variables
int sensor_state = 0;
//user customizable variables
int vel = 10;           /*change this value to change speed of
                          loops; default: 10ms*/
float step_fade = 40;



void setup() {
/*----------------------------------------------------------------------
 SETUP FUNCTION
   this function runs once at the start of the program which is used to
   define initial environmental settings
----------------------------------------------------------------------*/
  pinMode(sensor, INPUT);            //push button reading
  strip.begin();                     //strip initialization
  for(int i=0; i<num_LED; i++) {
    strip.setPixelColor(i, 0,0,0);   //set pixels to black color (turn off)
  }
  strip.show();                      //show pixels' color on strip
}


void wave(uint8_t R, uint8_t G, uint8_t B, uint8_t wait){
/*----------------------------------------------------------------------
 colors wave function
----------------------------------------------------------------------*/
  float nl = 30;
  for(int i=0; i<num_LED; i++) {
    for(int k=0; k<nl; k++){
      if(i < nl){
        strip.setPixelColor(i+k, 0,int(G*(1-cos((k-nl)/nl*2*3.14))/2.0),0);
      }else{
        strip.setPixelColor(i+k, 0,int(G*(1-cos((k-nl)/nl*2*3.14))/2.0),0);
      }
    }
    strip.show();  
  }
}


void fade(uint8_t R, uint8_t G, uint8_t B, uint8_t wait) {
/*----------------------------------------------------------------------
 light fade function
----------------------------------------------------------------------*/
  for(int c=0; c<step_fade; c++) {
    for(int i=0; i<num_LED; i++) {
      strip.setPixelColor(i, int(R*c/step_fade),int(G*c/step_fade),int(B*c/step_fade));
    }
    strip.show();
  }
  for(int c=step_fade; c>=0; c--) {
    for(int i=0; i<num_LED; i++) {
      strip.setPixelColor(i, int(R*c/step_fade),int(G*c/step_fade),int(B*c/step_fade));
    }
    strip.show();
  }
}


void wave_loop(){
/*----------------------------------------------------------------------
 colors wave loop function
----------------------------------------------------------------------*/
  for(int nc=0; nc<30; nc++){
    wave(0,50,0, vel);
    delay(50);
    wave(0,250,0, vel);
    delay(1500);
  }
}


void heart_loop() {
/*----------------------------------------------------------------------
 light fade loop function
----------------------------------------------------------------------*/
  for(int nc=0; nc<20; nc++){
    fade(0,255,0, vel);
    delay(50);
    fade(0,255,0, vel);
    delay(1500);
  }
}


void turn_off(){
/*----------------------------------------------------------------------
 strips turning off function
----------------------------------------------------------------------*/
  for(int i=0; i<num_LED; i++) {
    strip.setPixelColor(i, 0,0,0);
  }
}


void loop() {
/*----------------------------------------------------------------------
 LOOP FUNCTION
   if the push button is pressed, loop routine runs countless times
   calling some functions
----------------------------------------------------------------------*/
  sensor_state = digitalRead(sensor);
  delay(10);
  if(sensor_state == HIGH) {
    wave_loop();
    heart_loop();
    turn_off();
  }
}
