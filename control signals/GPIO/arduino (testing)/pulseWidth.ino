int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 500; //in microseconds
int pulseMax = 2500; //in microseconds
int MAX_ITERATIONS = 1; //depends on hardware
int ITERATION_DELAY = 0; //depends on hardware
int pulse;
int period;

void setup(){
  pinMode(controlPin, OUTPUT); //set GPIO out
  period = 1.0/frequency * 1000000; //convert to microseconds

  Serial.begin(9600);
  Serial.println("Enter an pulse (500 to 2500):"); //open serial and prompt user
}


void loop(){

  if (Serial.available() > 0) { //if data is inputted
    pulse = Serial.parseInt(); //get number

    if(pulse < pulseMin){ //keep input in range
      pulse = pulseMin;
    } else if (pulse > pulseMax){
      pulse = pulseMax;
    }

    Serial.print("pulse: "); //print back input
    Serial.println(pulse);

    for(int i = 0; i < MAX_ITERATIONS; i++){ //setting it, may take multiple pulses, with delays in between
      
      digitalWrite(controlPin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(controlPin, LOW);
      delayMicroseconds(period - pulse);
      delay(ITERATION_DELAY);

    }
  }

}