#include <PWM.h>

int IRsensorPin           = 0;
int LedPin                = 13;
int latestLevel           = 0;
int latestChange          = 0;
int changeThreshold       = 5;

int led_pin_pwm           = 9;
int frequency             = 150;
int pulse_duration        = 100;

int hysteresis            = 5; //set to what's reasonable

bool blinkCheckingFlag    = true;
bool timerFlag            = false;

int duration              = 100;

unsigned long startPoint;


//*********************
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  InitTimersSafe();
  SetPinFrequencySafe(led_pin_pwm, frequency);

} //END of setup()


//*********************
void loop()
{
  int IRsensorValue = analogRead(IRsensorPin);

  Serial.println(IRsensorValue);

  latestChange = IRsensorValue - latestLevel;
  latestLevel = IRsensorValue;

  //**********
  //if checking is enabled, was there a blink ?
  if (blinkCheckingFlag == true && latestChange >= changeThreshold)
  {
    //disable blink checking
    blinkCheckingFlag = false;

    digitalWrite( LedPin, HIGH );

    //restart the 10 second TIMER
    startPoint = millis();

    //enable the TIMER
    timerFlag = true;

    //start the pulse output
    pwmWrite(led_pin_pwm, 127);
  }

  //**********
  //if enabled should we stop the pulse output ?
  if (timerFlag == true && millis() - startPoint >= 10000)
  {
    digitalWrite( LedPin, LOW );

    //stop pulse output
    pwmWrite(led_pin_pwm, 0);

    //disable the TIMER
    timerFlag = false;
  }

  //**********
  //
  if (timerFlag == false  && latestChange < changeThreshold - hysteresis)
  {
    //enable blink checking
    blinkCheckingFlag = true;
  }

} //END of loop()
