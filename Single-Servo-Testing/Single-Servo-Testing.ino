/*                    Instructions:
//  
//  
//  Step.1) Upload code & connect the servo to the arduino on pin #9.
//  Step.2) Code will automatically Center the motor at start, SO DO NOT HAVE IT ATTACHED TO YOUR ROBOT, take out the servo so your dont damage your robo.
//          you can stop here if you are just centering the servo, but if you want to test it further continue on.
//           
//  Step.3) Open up the Serial Monitor and you cna type "r" or "l"; for moving the servo 10 degrees to the right or left, or type "c" to center the servo at 90 degrees
//  Step.4) PROFIT
//
//  NOTE: 
//  When you are putting your servo back into your robot, I recommend have your servo powered, connected to this code and having it centered. 
//  This will make it so when you you it back into you
//
*/

#include<Servo.h> 

Servo myservo;
int pos = 90;   // Center position for a positional servo
int Min = 10;   // set to 10 and not 0 to prevent the servo from accedentally going past 0
int Max = 170;  // set to 170 and not 180 to prevent the servo from accedentally going past 180

void setup(){
myservo.attach(9);  // Servo digital pin = 9
Serial.begin(9600); // Set your Serial Monitor to a Baud Rate of 9600
}

void loop() {
char ch;
if (Serial.available())   //  Raad the incoming value for the Serial monitor
{
  ch = Serial.read();
if(ch == 'c' || ch == 'C')
{
  pos = 90;
}
else if ((ch == 'r' || ch == 'R') && pos < Max)
{
  pos = pos + 10;
}
else if ((ch == 'l' || ch=='L') && pos > Min)
{
  pos = pos - 10;
}
}
myservo.write(pos);
int poo = myservo.read();  // named it "poo" because why not
Serial.println(poo);
delay(500);
}
