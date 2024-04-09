int controlPin = 8; //pin out
int frequency = 50; //in hertz (40-200)
int pulseMin = 0; //in microseconds
int pulseMax = 3000; //in microseconds
int MAX_ITERATIONS = 2; //depends on hardware
int ITERATION_DELAY = 120; //depends on hardware
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
  
  }

  Serial.println(pulse);
  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delayMicroseconds(period - pulse);
  delay(ITERATION_DELAY);

}