
//
// This example code controls 2 x HS785xx 
// This code is in the public domain.
// Author assumes no responsibility whatsoever.
// On Uno etc pins 4 and 5 used for servo pwm
// Pins 9,10.11.12 for switches. These pins are pulled low with 10k resistors in this example
// Pin A0 is used to switch mosfet gate to disconnect power ground from servos

#include <Servo.h> 

//change these values to set start up position and limits

// for servo1
#define PWM1_MIN  950
#define PWM1_MID 1250
#define PWM1_MAX 1550

// for servo2
#define PWM2_MIN  1200
#define PWM2_MID 1300
#define PWM2_MAX 1400

// how far the servo moves each step
#define PWM_STEP  20 // can be 1 for highest resolution 
 
Servo servo1, servo2; // create servo objects to control servos
int pwm1 = 1250;      // starting position value for PWM in microseconds
int pwm2 = 1500;      

//joystick switch or button pin connections
  const int moveL = 9; 
  const int moveR = 11;
  const int moveDn = 10;  
  const int moveUp = 12;


void setup() 
{ 
  // 4x joystick switches as inputs
  pinMode(moveL, INPUT);
  pinMode(moveR, INPUT);
  pinMode(moveUp, INPUT);
  pinMode(moveDn, INPUT);
  
  pinMode(A0, OUTPUT); 
  digitalWrite (A0,LOW); // turn mosfet off at startup
  
  // initialize servo 1
  servo1.attach(4, PWM1_MIN, PWM1_MAX); // attaches the servo on pin 4 to the servo object 
  servo1.writeMicroseconds(pwm1);       // set servo to position set for pwm1

  // initialize servo 2
  servo2.attach(5, PWM2_MIN, PWM2_MAX); // attaches the servo on pin 9 to the servo object 
  servo2.writeMicroseconds(pwm2);       // set servo to position set for pwm2

  // initialize serial port
  Serial.begin(4800);
  Serial.println("HS785 -- Ready");
  Serial.flush();
}
 
void loop() 
{ 

      if (digitalRead(moveL)==HIGH) {
      if (pwm1 > PWM1_MIN) pwm1 -= PWM_STEP;
       digitalWrite (A0,HIGH);
  servo1.writeMicroseconds(pwm1);
      
  Serial.print("pin 9 is high ");
  Serial.println();
    }
     if (digitalRead(moveR)==HIGH) {
      if (pwm1 < PWM1_MAX)pwm1 += PWM_STEP;
       digitalWrite (A0,HIGH);
  servo1.writeMicroseconds(pwm1);    

  Serial.print("pin 11 is high ");
  Serial.println();
    }
    if (digitalRead(moveUp)==HIGH) {
      if (pwm2 < PWM2_MAX)pwm2 += PWM_STEP;
       digitalWrite (A0,HIGH);
  servo2.writeMicroseconds(pwm2);
    
  Serial.print("pin 12 is high ");
  Serial.println();
}
    if (digitalRead(moveUp)==LOW) {
 
  Serial.print("pin 12 is low ");
  Serial.println();
}
   if (digitalRead(moveDn)==HIGH){ 
      if (pwm2 > PWM2_MIN)pwm2 -= PWM_STEP;
       digitalWrite (A0,HIGH);
  servo2.writeMicroseconds(pwm2); 

  Serial.print("pin 10 is high ");
  Serial.println();
  }

  if ((moveL==LOW)&&(moveR==LOW)&&(moveUp==LOW)&&(moveDn==LOW)){
  //switch off gnd & data so servos stop as soon as switches are off
   digitalWrite (A0,LOW); 
   digitalWrite (4,LOW);
   digitalWrite (5,LOW);   
    }

  
// report pwm values
  Serial.print("Servo1 - ");
  Serial.println(pwm1);
  Serial.print("Servo2 - ");
  Serial.println(pwm2); 

}
