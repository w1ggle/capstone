int controlPin = 8; //pin out
int frequency = 1000; //in hertz (1k to 16k?)
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int speedMin = -100; //in degrees
int speedMax = 100; //in degrees
int pulse;
int speed;
int period;

void setup(){
  pinMode(controlPin, OUTPUT);
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
  Serial.println("Enter an speed (-100 to 100):");
}


void loop(){

  if (Serial.available() > 0) {
    speed = Serial.parseInt();

    if(speed < speedMin){ //keeping input in range
      speed = speedMin;
    } else if (speed > speedMax){
      speed = speedMax;
    }

    pulse = map(speed, speedMin, speedMax, pulseMin, pulseMax);
    
    Serial.print("Speed: ");
    Serial.println(speed);
  }

    digitalWrite(controlPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(controlPin, LOW);
    delayMicroseconds(period - pulse);
}