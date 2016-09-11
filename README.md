# SIGNAL FUNCTION LIBRARY

[Signal Function Library] for **Arduino**, for easy and custom design of signals. With this library we can easily create signals with any shape.  Instead of just abrupts on/off LEDs we can design fade in/out signals, triangular, sinusoid, sawtooth singals, or even signals that emulate the hearbeat or breath... whatever we can imagine with a little configuration. There are many examples of signal functions (main.ino) and videos in the [repository]. Check a real time emulation in [circuits.io].
![alt tag][img/circuits_io.jpg]

 

--------------------------------------------------------------------------------
## CONFIGURATION
There is a complete configuration and several examples in [main.ino]. Note that it manages the timing with the inner clock (millis()), so the execution time of the loop does not affect our function. Check examples in [main.ino].
### Parameters:
All parameters of our `SignalFunction` object are public and well explained in signalFunction.h, as below:
```c
int enable;     // ALWAYS_LOW(0), NORMAL(1), ALWAYS_HIGH(2)
int pin;        // the Arduino pin where it takes the signal
int type;       // TYPE_ANALOG(true), TYPE_DIGITAL(false)
int period;     // the ms to take a cycle (signal function is periodical)
short int *Vn;  // array with all voltage points (normalized to [VnMIN,VnMAX])
short int *Tn;  // array with all time    points (normalized to [VnMIN,VnMAX])
int VTsize;     // number of points of the function (size of Vn and Tn)
```
### Analog Signals (TYPE_ANALOG):
For analog signals, we have to give some *coordinates* of our Time-Voltage function (`Tn[], Vn[]`) and the library will linearly fill the function automatically. Keep in mind that analog singals just work with analog outputs (PWM pins 3, 5, 6, 9, 10, 11 for Arduino UNO). For example, to create a **triangular function**, we just have we aware of:
```c
int type              = TYPE_ANALOG
const int VTsize      = 2;
short int Vn[VTsize]  = {0, 100};
short int Tn[VTsize]  = {0, 50};
```
- `T=0 -> V=0`: at the beginning of the `period`, the output is 0% of the voltage.
- `T=50 -> V=100`: at 50% of the `period` the signal has been linearly raising untill the 100% of the voltage.
- `T=100 -> V=0`: at 100% of the `period` the signal has been linearly falling untill the 0% of the voltage. It is unnecessary to write the last `Tn[]` (`T=100`) because it automatically understands that for `T=100` the voltage value will be back the first value of the array `Vn[]`.

### Digital Signals (TYPE_DIGITAL):
For digital signals, it is better to talk about *intervals*. In this case, `Tn[i], Tn[i+1]` will determine an interval and `Vn[i]` will determine the value of the signal in that interval (`0->LOW`, `!=0->-HIGH`). For example, for a double-beep signal, we just have notice:
```c
int type              = TYPE_DIGITAL
const int VTsize      = 4;
short int Vn[VTsize]  = {0, 100,  0, 100};
short int Tn[VTsize]  = {0,  70, 80,  90};
```
- `T=0, T=70`: from 0% to 70% of the `period`, the output is `Vn[0]=0(LOW)`.
- `T=70, T=80`: from 70% to 80% of the `period`, the output is `Vn[1]=100(HIGH)`.
- `T=80, T=90`: from 80% to 90% of the `period`, the output is `Vn[2]=0(LOW)`.
- `T=90, T=100`: from 90% to 100% of the `period`, the output is `Vn[3]=100(HIGH)`. We don't need to write a `T=100` because it automatically understands that it has to finish in `T=100` after the last `T`.

 

 

--------------------------------------------------------------------------------
## LICENSE
Under development.


[Signal Function Library]: <https://github.com/JaimeMartinSoler/signalFunction>
[repository]: <https://github.com/JaimeMartinSoler/signalFunction>
[my project]: <https://circuits.io/circuits/2695925-signalfunction>
[circuits.io]: <https://circuits.io/circuits/2695925-signalfunction>
[main.ino]: <https://github.com/JaimeMartinSoler/signalFunction/blob/master/src/main/main.ino>
[img/circuits_io.jpg]: <https://raw.githubusercontent.com/JaimeMartinSoler/signalFunction/master/img/circuits_io.jpg>


[//]: # (.md editor: <http://dillinger.io/>)
[//]: # (.md cheatsheet: <https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet>)
[//]: # (Invisible character for extra line breaking " ": <http://stackoverflow.com/questions/17978720/invisible-characters-ascii>)
