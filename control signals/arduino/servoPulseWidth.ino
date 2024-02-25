int controlPin = 8;
int frequency = 50; //in hertz
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int angleMin = 0; //in degrees
int angleMax = 270; //in degrees
int pulse;
int angle;
int period;

void setup(){
  pinMode(controlPin, OUTPUT);
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
}


void loop(){

  pulse = 0;
  
  angle = map(pulse, pulseMin, pulseMax, angleMin, angleMax);
  Serial.println(angle);

  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delayMicroseconds(period - pulse);

}