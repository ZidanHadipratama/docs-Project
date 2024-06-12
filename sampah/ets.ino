#include <ESP32Servo.h>

#define TRIGGER_PIN  21
#define ECHO_PIN     19
#define SERVO_PIN    18

Servo myservo;

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO_PIN); // Attach the servo on pin 18 to the servo object
}

void loop() {
  long distance = 0;

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
  distance -= 4;

  // Map the distance to servo angles
  int servoAngle = map(distance, 0, 20, 0, 180);
  if (distance < 20 && distance > 0){
    myservo.write(servoAngle);
  } else if (distance >= 20){
    myservo.write(180);
  }
  // Set the servo to the mapped angle
  // myservo.write(0);

  Serial.print("Average Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Servo Angle: ");
  Serial.println(servoAngle);
}
