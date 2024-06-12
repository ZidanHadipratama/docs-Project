#include <Servo.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define IR_PIN       11

Servo myservo;

unsigned long irLowStartTime = 0; // Variable to store the time when the sensor first goes LOW
bool servoLocked = false; // Variable to lock the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  long distance = 0;
  int sensorValue = digitalRead(IR_PIN);

  for(int i = 0; i < 10; i++) {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    distance += duration / 29 / 2;
    delay(10);
  }

  distance /= 10;

  Serial.print("Average Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (sensorValue == LOW) {
    Serial.println("Sensor State: LOW - Object Detected");

    // If this is the first time the sensor has gone LOW, start the timer
    if (irLowStartTime == 0) {
      irLowStartTime = millis();
    }

    Serial.print("irLowStartTime: ");
    Serial.print(irLowStartTime/1000);
    Serial.println(" s");

    // If the sensor has been LOW for 15 seconds or more, lock the servo
    if (millis() - irLowStartTime >= 15000) {
      servoLocked = true;
    }

    // Keep the program in a loop while the sensor value is LOW
    while (digitalRead(IR_PIN) == LOW) {
      // Do nothing
    }
  } else {
    Serial.println("Sensor State: HIGH - No Object Detected");

    // Reset the timer and unlock the servo when the sensor goes HIGH
    irLowStartTime = 0;
    servoLocked = false;
  }

  // Only allow the servo to move if it's not locked
  if (!servoLocked) {
    if (distance < 30) {
      Serial.println("Buka");
      myservo.write(90);
    } else {
      Serial.println("Tutup");
      myservo.write(0);
    }
  }

  delay(300);
}