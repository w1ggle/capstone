int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int angleMin = 0; //in degrees
int angleMax = 180; //in degrees
int pulse;
int angle;
int period;

void setup(){
  pinMode(controlPin, OUTPUT);
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
  Serial.println("Enter an angle (0 to 180):");
}


void loop(){

  if (Serial.available() > 0) {
    angle = Serial.parseInt();

    if(angle < angleMin){ //keeping input in range
      angle = angleMin;
    } else if (angle > angleMax){
      angle = angleMax;
    }

    pulse = map(angle, angleMin, angleMax, pulseMin, pulseMax);
    
    Serial.print("Angle: ");
    Serial.println(angle);
  }

    digitalWrite(controlPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(controlPin, LOW);
    delayMicroseconds(period - pulse);
}