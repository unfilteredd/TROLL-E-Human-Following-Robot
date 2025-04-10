//Arduino Human Following Robot with Buzzer
// Modified to include buzzer on pin 9 when moving backward

#include<NewPing.h>
#include<Servo.h>
#include<AFMotor.h>

#define RIGHT A3  // Right IR sensor
#define LEFT A2   // Left IR sensor
#define TRIGGER_PIN A4 // Ultrasonic sensor trigger
#define ECHO_PIN A5    // Ultrasonic sensor echo
#define MAX_DISTANCE 50
#define BUZZER 9 // Buzzer connected to pin 9

unsigned int distance = 0;
unsigned int Right_Value = 0;
unsigned int Left_Value = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

Servo myservo;
int pos = 0;

void setup() {
    Serial.begin(9600);
    myservo.attach(10);
    pinMode(RIGHT, INPUT);
    pinMode(LEFT, INPUT);
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);
    
    for (pos = 90; pos <= 180; pos++) {
        myservo.write(pos);
        delay(15);
    }
    for (pos = 180; pos >= 0; pos--) {
        myservo.write(pos);
        delay(15);
    }
    for (pos = 0; pos <= 90; pos++) {
        myservo.write(pos);
        delay(15);
    }
}

void loop() {
    delay(50);
    distance = sonar.ping_cm();
    Serial.print("Distance: ");
    Serial.println(distance);

    Right_Value = digitalRead(RIGHT);
    Left_Value = digitalRead(LEFT);

    Serial.print("RIGHT: ");
    Serial.println(Right_Value);
    Serial.print("LEFT: ");
    Serial.println(Left_Value);

    if ((distance > 15) && (distance < 25)) {
        // Move Backward
        Motor1.setSpeed(130);
        Motor1.run(BACKWARD);
        Motor2.setSpeed(130);
        Motor2.run(BACKWARD);
        Motor3.setSpeed(130);
        Motor3.run(BACKWARD);
        Motor4.setSpeed(130);
        Motor4.run(BACKWARD);
        digitalWrite(BUZZER, LOW);
    } else if ((distance > 1) && (distance < 7)) {
        // Move Forward
        Motor1.setSpeed(130);
        Motor1.run(FORWARD);
        Motor2.setSpeed(130);
        Motor2.run(FORWARD);
        Motor3.setSpeed(130);
        Motor3.run(FORWARD);
        Motor4.setSpeed(130);
        Motor4.run(FORWARD);
        digitalWrite(BUZZER, HIGH);
    } else if ((Right_Value == 0) && (Left_Value == 1)) {
        // Turn Right
        Motor1.setSpeed(150);
        Motor1.run(BACKWARD);
        Motor2.setSpeed(150);
        Motor2.run(BACKWARD);
        Motor3.setSpeed(150);
        Motor3.run(FORWARD);
        Motor4.setSpeed(150);
        Motor4.run(FORWARD);
        delay(150);
        digitalWrite(BUZZER, LOW);
    } else if ((Right_Value == 1) && (Left_Value == 0)) {
        // Turn Left
        Motor1.setSpeed(150);
        Motor1.run(FORWARD);
        Motor2.setSpeed(150);
        Motor2.run(FORWARD);
        Motor3.setSpeed(150);
        Motor3.run(BACKWARD);
        Motor4.setSpeed(150);
        Motor4.run(BACKWARD);
        delay(150);
        digitalWrite(BUZZER, LOW);
    } else {
        // Default case - Stay Stationary
        Motor1.setSpeed(0);
        Motor1.run(RELEASE);
        Motor2.setSpeed(0);
        Motor2.run(RELEASE);
        Motor3.setSpeed(0);
        Motor3.run(RELEASE);
        Motor4.setSpeed(0);
        Motor4.run(RELEASE);
        digitalWrite(BUZZER, LOW);
    }
}
