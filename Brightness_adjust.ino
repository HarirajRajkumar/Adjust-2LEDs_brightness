/* This following program ables to adjusts brightness of 2 LED by
 * reading the analog value from potentiometer.
 * One LED dims and other brightens up (vice versa). 
 * 
 * Pins Used :
 * 1st LED pin number - 9
 * 2nd LED pin number - 3
 * AnalogPin A0
 * 
 * Check the given circuit diagram for reference
 */

 // Pin Declaration
 const int nLEDpin = 9;
 const int nAnalogPin = A0;
 const int nLEDpin2 = 3;
 
 // Variable Declaration
 int nAnalogValue =0;
 int bPWMvalue = 0 ;
 int bPWMvalue2 = 0;
 // Function Declaration
  byte LEDbright( int AnalogValue );

      
 void setup()
 {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(nLEDpin , OUTPUT);
  pinMode(nLEDpin2 , OUTPUT);
  pinMode(nAnalogPin , INPUT);
 }// close setup

 void loop()
 {
  nAnalogValue = analogRead(nAnalogPin); // Read Analog Pin
  
  bPWMvalue = map(nAnalogValue,0,1023,0,255);  // mapping values from low to high.
  bPWMvalue2 = map(nAnalogValue,0,1023,255,0);  // mapping values from high to low.

  // PWM at pin 3 and 9
  analogWrite(nLEDpin , bPWMvalue);   // at pin 9
  analogWrite(nLEDpin2 , bPWMvalue2);  // at pin 3
  
  
  Serial.print(nAnalogValue);
  Serial.print("\t");
  Serial.print(bPWMvalue);
  Serial.print("\t");
  Serial.println(bPWMvalue2);

// IN Serial monitor 
// nAnalogValue bPWMvalue mPWMvalue2
  
  delay(2);  
 }// close loop

 

