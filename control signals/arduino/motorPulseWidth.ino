int controlPin = 8;
int frequency = 1000; //in hertz (1k to 16k?)
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int speedMin = -100; //in percent
int speedMax = 100; //in percent
int pulse; 
int speed = 50; //hardcode test
int period;

void setup(){
  pinMode(controlPin, OUTPUT);
  period = 1.0/frequency * 1000000; //convert to microseconds

 

  if(speed < speedMin){ //keeping input in range
    speed = speedMin;
  } else if (speed > speedMax){
    speed = speedMax;
  }

  Serial.begin(9600);
  Serial.print("Speed: ");
  Serial.print(speed);
  pulse = map(speed, speedMin, speedMax, pulseMin, pulseMax);
  

}


void loop(){

  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delayMicroseconds(period - pulse);

}