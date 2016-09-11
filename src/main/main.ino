/*
    // ------------------------------------------------------------------
    // --- main.ino                                                   ---
    // ------------------------------------------------------------------
    // --- Descr  : Arduino sample of signalFunction.c functionality  ---
    // --- Author : Jaime Martin Soler                                ---
    // --- Date   : 2016-09-08                                        ---
    // --- Circuit: Arduino_OUT9 - R(100ohms) - LED - Arduino_GND     ---
    // ------------------------------------------------------------------
*/


// INCLUDES -------------------------------------------------------------
#include "signalFunction.h"




// VARIABLES ------------------------------------------------------------
const int PIN_SIGNAL = 9;  // the PWM analog output pin (Arduino_UNO_PWM:3,5,6,9,10,11) with the signal function
int loop_delay = 1;        // time (in ms) between every execution of refresh()
SignalFunction sf = SignalFunction();




// SETUP ----------------------------------------------------------------
void setup() {
  
  // set pin mode signal
  pinMode(PIN_SIGNAL, OUTPUT);

  // pick-up (uncomment) one only of the following signalFunction setups

  // ALWAYS ON/OFF FUNCTION
  /*
  int sf_enable               = ENABLE_ALWAYS_HIGH;  // ON:ENABLE_ALWAYS_HIGH, OFF:ENABLE_ALWAYS_LOW
  int sf_type                 = TYPE_DIGITAL;
  int sf_period               = 0;
  const int sf_VTsize         = 0;
  short int sf_Vn[sf_VTsize]  = {};
  short int sf_Tn[sf_VTsize]  = {};
  */
  
  // DUTY CYCLE X% FUNCTION
  /*
  int dc = 50;  // duty cycle from 0% to 100%
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_DIGITAL;
  int sf_period               = 1000; 
  const int sf_VTsize         = 2;
  short int sf_Vn[sf_VTsize]  = {100,  0};
  short int sf_Tn[sf_VTsize]  = {  0, dc};
  */

  // TRIANGULAR FUNCTION
  /*
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 1000;
  const int sf_VTsize         = 2;
  short int sf_Vn[sf_VTsize]  = {0, 100};
  short int sf_Tn[sf_VTsize]  = {0, 50};
  */

  // SAWTOOTH FUNCTION
  /*
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 1000;
  const int sf_VTsize         = 3;
  short int sf_Vn[sf_VTsize]  = {0, 100, 0};
  short int sf_Tn[sf_VTsize]  = {0, 50, 51};
  */
  
  // SAWTOOTH INVERTED FUNCTION
  /*
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 1000;
  const int sf_VTsize         = 3;
  short int sf_Vn[sf_VTsize]  = {0,  0, 100};
  short int sf_Tn[sf_VTsize]  = {0, 50,  51};
  */

  // SINUSOID FUNCTION
  /*
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 1000;
  const int sf_VTsize         = 20;
  short int sf_Vn[sf_VTsize]  = {50, 65, 79, 90, 97, 100, 97, 90, 79, 65, 50, 35, 21, 10,  3,  0,  3, 10, 21, 35};
  short int sf_Tn[sf_VTsize]  = { 0,  5, 10, 15, 20,  25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
  */
  
  // BREATHING FUNCTION
  /*
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 3000;     // Slow:6000; Normal:3000; Fast:2000; VeryFast:1000
  const int sf_VTsize         = 3;
  short int sf_Vn[sf_VTsize]  = {0,  0, 100};
  short int sf_Tn[sf_VTsize]  = {0, 30,  80};
  */

  // DOUBLE HEARTBEAT FUNCTION(default)
  int sf_enable               = ENABLE_NORMAL;
  int sf_type                 = TYPE_ANALOG;
  int sf_period               = 1500;  // Slow:3000; SlowNormal:2250; Normal:1500; FastNormal:1125; Fast:750
  const int sf_VTsize         = 20;
  short int sf_Vn[sf_VTsize]  = {0, 50,100, 66, 33,  0,  0, 50,100, 66, 33,  0,  0,  0,  0,  0,  0,  0,  0,  0};
  short int sf_Tn[sf_VTsize]  = {0,  5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95}; 
  
  // set sf
  sf.set(sf_enable, PIN_SIGNAL, sf_type, sf_period, sf_Vn, sf_Tn, sf_VTsize);
}




// LOOP -----------------------------------------------------------------
void loop() {
  
  // add delay (with some delay the loop is not executed unnecesarly fast)
  sf.refresh(loop_delay);   // equivalent to:  delay(loop_delay); sf.refresh()
}



