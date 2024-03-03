int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 725; //in microseconds
int pulseMax = 2125; //in microseconds
int speedMin = -100; //in degrees
int speedMax = 100; //in degrees (56 is max)
int MAX_ITERATIONS = 1; //depends on hardware
int ITERATION_DELAY = 0; //depends on hardware
int pulse;
int speed;
int period;

void setup(){
  pinMode(controlPin, OUTPUT); //set GPIO out
  period = 1.0/frequency * 1000000; //convert to microseconds


  
  for(int i = 0; i < 100; i++){ //calibrating motor center
    Serial.println(1500);
    digitalWrite(controlPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(controlPin, LOW);
    delayMicroseconds(period - 1500);
    delay(2);

  }

  Serial.begin(9600);
  Serial.println("Enter an speed (-100 to 100):"); //open serial and prompt user
}


void loop(){

  if (Serial.available() > 0) { //if data is inputted
    speed = Serial.parseInt(); //get number

    if(speed < speedMin){ //keep input in range
      speed = speedMin;
    } else if (speed > speedMax){
      speed = speedMax;
    }

    Serial.print("speed: "); //print back input
    Serial.println(speed);
    Serial.print("pulse: "); //print back input
    Serial.println(pulse);

    pulse = map(speed, speedMin, speedMax, pulseMin, pulseMax); //mapping input to pulse

    for(int i = 0; i < MAX_ITERATIONS; i++){ //setting it, may take multiple pulses, with delays in between, need to test on hardware
      Serial.println(pulse);
      digitalWrite(controlPin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(controlPin, LOW);
      delayMicroseconds(period - pulse);
      delay(ITERATION_DELAY);

    }
  }

}