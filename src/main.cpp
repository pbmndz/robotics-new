#include <Arduino.h>
#include <Servo.h>

//MOTOR 1
#define MOTOR_A1_PIN 3
#define MOTOR_B1_PIN 5
//MOTOR 2
#define MOTOR_A2_PIN 6
#define MOTOR_B2_PIN 9
//Servo
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
// servos
  servo1.attach(11);
  servo2.attach(10);
  servo1.write(0);
  servo2.write(90);
// distance sensors
  pinMode(7, INPUT); // D7
  pinMode(4, INPUT); // D4
  pinMode(2, INPUT); // D2
  pinMode(A3, INPUT); // A3
  pinMode(8, INPUT); // D8
}

void servo_start() {
  servo1.write(90);
  servo2.write(0);
} 
void servo_close(){
  servo1.write(0);
  servo2.write(90);
}
void Stop(){
  analogWrite(MOTOR_A1_PIN, 0 );
  analogWrite(MOTOR_B1_PIN, 0);
  analogWrite(MOTOR_A2_PIN, 0);
  analogWrite(MOTOR_B2_PIN, 0);
}
void Forward(){
  analogWrite(MOTOR_A1_PIN, 50);
  analogWrite(MOTOR_B1_PIN, 0);
  analogWrite(MOTOR_A2_PIN, 50);
  analogWrite(MOTOR_B2_PIN, 0);  
}
void ATTACK(){
  analogWrite(MOTOR_A1_PIN, 50); 
  analogWrite(MOTOR_B1_PIN, 0);
  analogWrite(MOTOR_A2_PIN, 50);
  analogWrite(MOTOR_B2_PIN, 0);  
}
void Backward(){
  analogWrite(MOTOR_A1_PIN, 0);
  analogWrite(MOTOR_B1_PIN, 50);
  analogWrite(MOTOR_A2_PIN, 0);
  analogWrite(MOTOR_B2_PIN, 50);  
}
void right(){
  analogWrite(MOTOR_A1_PIN, 50 );
  analogWrite(MOTOR_B1_PIN, 0 );
  analogWrite(MOTOR_A2_PIN, 0);
  analogWrite(MOTOR_B2_PIN, 50 );
}
void left(){
  analogWrite(MOTOR_A1_PIN, 0 );
  analogWrite(MOTOR_B1_PIN, 50 );
  analogWrite(MOTOR_A2_PIN, 50);
  analogWrite(MOTOR_B2_PIN, 0 );
}


void loop() {
  // line sensors
  int analogA0 = analogRead(A0);
  int analogA1 = analogRead(A1);
  int analogA2 = analogRead(A2);
  
  // distance sensors
  int digitalD7 = digitalRead(7); // D7
  int digitalD4 = digitalRead(4); // D4
  int digitalD2 = digitalRead(2); // D2
  int digitalA3 = digitalRead(A3); // A3
  int digitalD8 = digitalRead(8); // D8

// for debug
  // LINE SENSORS
  Serial.print(" ");
  Serial.print(analogA0);
  Serial.print(" ");
  Serial.print(analogA1);
  Serial.print(" ");
  Serial.print(analogA2);
  Serial.print(" ");
  // DISTANCE
  Serial.print(digitalD7);
  Serial.print(" ");
  Serial.print(digitalD4);
  Serial.print(" ");
  Serial.print(digitalD2);
  Serial.print(" ");
  Serial.print(digitalA3);
  Serial.print(" ");
  Serial.println(digitalD8);

if (analogA2 < 100 and analogA1 < 100){
  Backward();
  delay(150);
  right();
  delay(200);
}
else if(analogA0 > 100){
  // left 
}
else if(analogA1 > 100){
  // right 
}
else if(analogA2 > 100){
  // back
}
else{
  if(digitalA3 == 1){
    Forward();
  }
  else if(digitalD2 == 1 or digitalD8 == 1){
    left();
        delay(100);
  }
  else if(digitalD7 == 1 or digitalD4 == 1){
    right();
    delay(100);
  }
  else{
    right();
    }
  }
}
