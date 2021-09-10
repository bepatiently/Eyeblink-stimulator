
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = (sensorValue); /*we will multiply the raw value with the result 
  we get after the calculation of serial monitor
  then change the code to outputValue = (sensorValue*calculation) he found 0.005
  in the video then run the serial monitor again
  */

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue); //RAM value from analog read
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}

/*open serial monitor when you run the code
 *
 */
