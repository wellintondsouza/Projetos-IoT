// C++ code for Arduino

// Define the trigger and echo pins
const int triggerPin = 7;
const int echoPin = 6;
const int ledPin1 = 9; // Primeiro LED na porta 9
const int ledPin2 = 8; // Segundo LED na porta 8

void setup() {
    pinMode(triggerPin, OUTPUT); // Set trigger pin as output
    pinMode(echoPin, INPUT);     // Set echo pin as input
    pinMode(ledPin1, OUTPUT);    // Set primeiro LED pin as output
    pinMode(ledPin2, OUTPUT);    // Set segundo LED pin as output
    Serial.begin(9600);          // Initialize serial communication for debugging
}

long readUltrasonicDistance() {
    // Send a 10-microsecond pulse to trigger the sensor
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Read the echo pulse duration
    long duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in cm
    long distance = duration * 0.0344 / 2; // Speed of sound: 0.0344 cm/µs
    return distance;
}

void loop() {
    long distancia = readUltrasonicDistance();
    Serial.print("Distance: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Control the first LED based on distance
    if (distancia < 180) {
        digitalWrite(ledPin1, HIGH);
    } else {
        digitalWrite(ledPin1, LOW);
    }

    // Control the second LED based on distance
    if (distancia < 90) { // Ajuste o valor conforme necessário para o segundo LED
        digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
    }

    delay(100); // Delay a bit to improve performance
}
