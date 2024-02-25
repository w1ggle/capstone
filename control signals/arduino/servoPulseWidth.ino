int controlPin = 8;
int frequency = 50; //in hertz
int pulseMin = 400; //in microseconds
int pulseMax = 2500; //in microseconds
int angleMin = 0; //in degrees
int angleMax = 180; //in degrees
int pulse;
int angle = 90; //hardcode test
int period;

void setup(){
  pinMode(controlPin, OUTPUT);
  period = 1.0/frequency * 1000000; //convert to microseconds

  if(angle < angleMin){ //keeping input in range
    angle = angleMin;
  } else if (angle > angleMax){
    angle = angleMax;
  }

  Serial.begin(9600);
  Serial.print("Angle: ");
  Serial.print(angle);
  pulse = map(angle, angleMin, angleMax, pulseMin, pulseMax);
}


void loop(){

  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delayMicroseconds(period - pulse);

}