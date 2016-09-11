/*
    // ----------------------------------------------------------------------
    // --- signalFunction.h                                               ---
    // ----------------------------------------------------------------------
    // --- Library for easy custom signal design for LEDs, Buzzers, etc   ---
    // --- Author: Jaime Martin Soler                                     ---
    // --- Date  : 2016-09-08                                             ---
    // ----------------------------------------------------------------------
*/

#ifndef SIGNALFUNCTION_H
#define SIGNALFUNCTION_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// DEFINES --------------------------------------------------------------
// define TYPE
#define TYPE_ANALOG true
#define TYPE_DIGITAL false
// define ENABLE
#define ENABLE_ALWAYS_LOW 0
#define ENABLE_NORMAL 1
#define ENABLE_ALWAYS_HIGH 2
// define MIN, MAX
#define VnMIN 0
#define VnMAX 100
#define TnMIN 0
#define TnMAX 100

class SignalFunction
{
  public:
    // PARAMETERS -----------------------------------------------------------
    int enable;     // ALWAYS_LOW(0), NORMAL(1), ALWAYS_HIGH(2)
    int pin;        // the Arduino pin where it takes the signal
    int type;       // TYPE_ANALOG(true), TYPE_DIGITAL(false)
    int period;     // the ms to take a cycle (signal function is periodical)
    short int *Vn;  // array with all voltage points (normalized to [VnMIN,VnMAX])
    short int *Tn;  // array with all time    points (normalized to [VnMIN,VnMAX])
    int VTsize;     // number of points of the function (size of Vn and Tn)
    // CONSTRUCTORS ---------------------------------------------------------
    SignalFunction();
    SignalFunction(int enable, int pin, int type, int period, short int Vn[], short int Tn[], int VTsize);
    ~SignalFunction();
    // FUNCTIONS ------------------------------------------------------------
    void set(int enable, int pin, int type, int period, short int Vn[], short int Tn[], int VTsize);
    void refresh();
    void refresh(int delayMs);
};

#endif

