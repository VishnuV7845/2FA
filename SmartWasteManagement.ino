#include <Servo.h>

#define PIR_PIN 2
#define TRIGGER_PIN 4
#define ECHO_PIN 7
#define RED_LED_PIN 13
#define GREEN_LED_PIN 12
#define SERVO_PIN 8

Servo servo;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  servo.attach(SERVO_PIN);
  servo.write(0); // Initial position
  
  Serial.begin(9600);
}

void loop() {
  // Check distance using ultrasonic sensor
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Convert distance to centimeters
  
  // If distance is less than or equal to 10cm, turn on red LED, else turn on green LED
  if (distance <= 10) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
  
  // PIR sensor detection
  if (digitalRead(PIR_PIN) == HIGH) {
    servo.write(90); // Rotate servo by 90 degrees
    delay(1000); // Wait for servo to move
    
    // Additional actions when PIR sensor detects movement
    
  } else {
    servo.write(0); // Reset servo position
    
    // Additional actions when no movement is detected
    
  }
  
  delay(500); // Adjust delay as needed
}