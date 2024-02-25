int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int angleMin = 0; //in degrees
int angleMax = 180; //in degrees
int MAX_ITERATIONS = 6; //depends on hardware
int ITERATION_DELAY = 120; //depends on hardware
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

    pulse = map(angle, angleMin, angleMax, pulseMin, pulseMax); //mapping input to pulse
    for(int i = 0; i < MAX_ITERATIONS; i++){ //setting it, may take multiple pulses, with delays in between
      
      digitalWrite(controlPin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(controlPin, LOW);
      delayMicroseconds(period - pulse);
      delay(ITERATION_DELAY);

    }
  }

}