int controlPin = 8;
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
}


void loop(){

  pulse = 0;

  if(pulse < pulseMin){
    pulse = pulseMin;
  } else if (pulse > pulseMax){
    pulse = pulseMax;
  else {
    //do nothing
  }
  
  speed = map(pulse, pulseMin, pulseMax, speedMin, speedMax);
  Serial.println(speed);
  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delayMicroseconds(period - pulse);


}