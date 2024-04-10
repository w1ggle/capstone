int pwmEmulatorPin = 8;
int maxRange = 20000;
int dutyCyclePercent = 20; //hardcode test
float activeTime;
float nonActiveTime;

void setup(){
  pinMode(pwmEmulatorPin, OUTPUT);
  activeTime = maxRange * (dutyCyclePercent / 100.0);
  nonActiveTime = maxRange * ((100 - dutyCyclePercent) / 100.0);
}

void loop(){
  digitalWrite(pwmEmulatorPin, HIGH);
  delayMicroseconds(activeTime);
  digitalWrite(pwmEmulatorPin, LOW);
  delayMicroseconds(nonActiveTime);
}