#include "Servo.h"
#define PUMPPIN 9 //peristatic pump control pin, arduino digital pin
#define waitTime 5000 //interval time(ms) between every state
Servo myservo;
int value = 0;
float voltage;
float current;
float pH;
unsigned long sleepTime; //interval of time in sleep


void setup() {
  // setup serial monitor and pump
  Serial.begin(9600);
  sleepTime = 50000; //set sleep time for 50 seconds
  myservo.attach(PUMPPIN);
  
}

void loop() {

  value = analogRead(A0); //Read analog input at A0
  voltage = value * 5.0/1024.0; //calculating voltage
  pH = (7*(5*voltage-4))/8; //calculating pH

  if (6.9 > pH) {
    Serial.print("Warning: High pH: ");
    Serial.println(pH, 2);
    delay(500);
    myservo.write(0); //clockwise maximum speed rotation
    delay(waitTime);
    }
  else if (6.9 <= pH <= 7.1) {
    Serial.print("Optimal pH: ");
    Serial.println(pH, 2);
    delay(500);
    myservo.write(90); //stop pump
    delay(waitTime);
    }
  else if (pH > 7.1) {
    Serial.print("Warning: Low pH ");
    Serial.println(pH, 2);
    delay(500);
    myservo.write(90); //stop pump
    delay(waitTime);
  }
  else {
     Serial.print("Error: Invalid Voltage Reading");
     delay(500);
     myservo.write(90); //stop pump
     delay(waitTime);
    }
}
