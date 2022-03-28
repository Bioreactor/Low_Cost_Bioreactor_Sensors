int value = 0;
float voltage;
float current;
float DO;

void setup() {
  // setup serial monitor
  Serial.begin(9600); 
}

void loop() {

  value = analogRead(A0); //Read analog input at A0
  voltage = value * 5.0/1024.0; //calculating voltage
  DO = -(5.0*voltage-4.0)/0.5; //calculating DO

  if (DO <= 1.50) {
    //Serial.print("Warning: DO Low: ");
    Serial.println(DO, 2);
    delay(500);
    }
  else if (1.50 <= DO <= 7.00) {
    //Serial.print("Optimal DO: ");
    Serial.println(DO, 2);
    delay(500);
    }
  else {
    //Serial.print("Warning: DO High: ");
    Serial.println(DO, 2);
    delay(500);
    }

}
