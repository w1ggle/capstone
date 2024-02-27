int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 1200; //in microseconds
int pulseMax = 1610; //in microseconds
int pulseStraight = 1374;
int angleMin = -100; //in degrees
int angleMax = 100; //in degrees (56 is max)
int MAX_ITERATIONS = 1; //depends on hardware
int ITERATION_DELAY = 0; //depends on hardware
int pulse;
int angle;
int period;

void setup(){
  pinMode(controlPin, OUTPUT); //set GPIO out
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
  Serial.println("Enter an angle (-100 to 100):"); //open serial and prompt user
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
    //if (angle == ((angleMin + angleMax)/2)){ //straight? wondering if i should recalibrate now that i think about it
    //    pulse = pulseStraight;
    //}

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