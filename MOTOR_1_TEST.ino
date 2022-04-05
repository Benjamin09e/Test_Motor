#include <AFMotor.h>
#include <Ultrasonic.h>
#include <Servo.h >
AF_DCMotor MD(3), MG(2);
Servo pince;
int val;
int d;
int droite;
droite=pince.Ranging(CM);
Ultrasonic ultrasonic(A4,A3); // (Trig PIN,Echo PIN)
void setup() {
 Serial.begin (9600);
 pince.attach(9);
 pince.write(180);  
  // put your setup code here, to run once:
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(FORWARD);
  MG.run(FORWARD);
}

void loop() {
 Serial.println(ultrasonic.Ranging(CM));
 
  // put your main code here, to run repeatedly:
if (ultrasonic.Ranging(CM)>20)
{
  avancer ();
}
else{
  arreter ();
 pince.write(droite);
 d_droite=pince.Ranging(CM);
  }
}
void avancer() {
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(FORWARD);
  MG.run(FORWARD);
  }
void reculer() {
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(BACKWARD);
  MG.run(BACKWARD);
}
void arreter() {
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(RELEASE);
  MG.run(RELEASE);
}
void droite() {
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(BACKWARD);
  MG.run(FORWARD);
}
void gauche() {
  MD.setSpeed(200);
  MG.setSpeed(200);
  MD.run(FORWARD);
  MG.run(BACKWARD);
}
 
