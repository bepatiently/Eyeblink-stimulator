#include <PWM.h>

int led = 13, pwm = 9, ir = 0, duration = 250, frequency = 150, threshold = 5, latest = -9999, checking = true;

void setup(){
    /**/
    Serial.begin(9600); // configure the baud rate of the serial monitor
    /**/
    pinMode(led, OUTPUT);  // configure led pin as output
    /**/
    InitTimersSafe();
    /**/
    SetPinFrequencySafe(pwm, frequency); // stimulation functions
    /**/
}

void loop(){
    /**/
    int value = analogRead(ir); // read data from pin 0
    /**/
    if (checking && value - latest >= threshold){
        /**/
        stimulated();
        /**/
        checking = false;
        /**/
    }
    else {
        /**/
        unstimulated();
        /**/
        checking = true;
        /**/
    }
    /**/
    latest = value;
    /**/
} 

void stimulated(){
    /**/
    digitalWrite(led, HIGH); // turn the led on
    /**/
    pwmWrite(pwm, 127);
    /**/
  //delay(duration); 
    /**/
}

void unstimulated(){
    /**/
    digitalWrite(led, LOW); // turn the led off
    /**/
    pwmWrite(pwm, 0); 
    /**/
}
