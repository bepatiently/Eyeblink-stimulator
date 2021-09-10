#include <PWM.h>

int IRsensorPin = 0;
int LedPin = 13;
int latestLevel = 0;
int latestChange = 0;
int changeThreshold = 5;

int led_pin_pwm= 9;
int frequency = 150;

int duration = 100;
float startPoint = 0;

void setup() {

  Serial.begin(9600);
  pinMode(13,OUTPUT);

  InitTimersSafe();
  SetPinFrequencySafe(led_pin_pwm, frequency);

}

void loop() {
  
  int IRsensorValue = analogRead(IRsensorPin);
  Serial.println(IRsensorValue);

  latestChange = IRsensorValue - latestLevel;
  latestLevel = IRsensorValue;

  if( latestChange >= changeThreshold){
    
    digitalWrite( LedPin, HIGH );
    startPoint = millis();
  }
  if( millis() >= startPoint + duration ){

    digitalWrite( LedPin, LOW );
  }

  pwmWrite(led_pin_pwm, 127);
}
