#include <NewPing.h>
 
#define TRIGGER_PIN  3
#define ECHO_PIN     2
#define MAX_DISTANCE 35
unsigned distance = 0;
unsigned OldDistance = 0;
int redPin = 8;
int yellowPin = 9;
int greenPin = 10;
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

 
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
 
void loop() {
  delay(50);
  distance = sonar.ping_cm();
 
  //sent the value only if it's a new value
  if (OldDistance != distance) {
    Serial.println(distance);
    digitalWrite(yellowPin, LOW);
  }
  if (distance < 15) {
      digitalWrite(redPin, HIGH); 
      digitalWrite(greenPin, LOW);
    }
    if (distance == OldDistance + 1 || distance == OldDistance - 1) {
      digitalWrite(yellowPin, HIGH); 
    }
    if (distance > 15) {
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
    }
  
    OldDistance = distance;
  
}
