int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 1200; //in microseconds
int pulseMax = 1610; //in microseconds
int pulseStraight = 1374;
int angleMin = 0; //in degrees
int angleMax = 56; //in degrees
int MAX_ITERATIONS = 4; //depends on hardware
int ITERATION_DELAY = 5; //depends on hardware
int pulse;
int angle;
int period;

void setup(){
  pinMode(controlPin, OUTPUT); //set GPIO out
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
  Serial.println("Enter an angle (0 to 180):"); //open serial and prompt user
}


void loop(){

  if (Serial.available() > 0) { //if data is inputted
    angle = Serial.parseInt(); //get number

    if(angle < angleMin){ //keep input in range
      angle = angleMin;
    } else if (angle > angleMax){
      angle = angleMax;
    }

    Serial.print("Angle: "); //print back input
    Serial.println(angle);
    Serial.print("pulse: "); //print back input
    Serial.println(pulse);

    pulse = map(angle, angleMin, angleMax, pulseMin, pulseMax); //mapping input to pulse
   // if (angle == ((angleMin + angleMax)/2)){
     // pulse = pulseStraight;
    //}
    for(int i = 0; i < MAX_ITERATIONS; i++){ //setting it, may take multiple pulses, with delays in between
      Serial.println(pulse);
      digitalWrite(controlPin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(controlPin, LOW);
      delayMicroseconds(period - pulse);
      delay(ITERATION_DELAY);

    }
  }

}