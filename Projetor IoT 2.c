

const int triggerPin = 7;
const int echoPin = 6;
const int ledPin1 = 9; 
const int ledPin2 = 8; 

void setup() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);     
    pinMode(ledPin1, OUTPUT);   
    pinMode(ledPin2, OUTPUT);   
    Serial.begin(9600);        
}

long readUltrasonicDistance() {

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    long distance = duration * 0.0344 / 2; 
    return distance;
}

void loop() {
    long distancia = readUltrasonicDistance();
    Serial.print("Distance: ");
    Serial.print(distancia);
    Serial.println(" cm");

    if (distancia < 180) {
        digitalWrite(ledPin1, HIGH);
    } else {
        digitalWrite(ledPin1, LOW);
    }

    if (distancia < 90) { 
        digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
    }

    delay(100);
}
