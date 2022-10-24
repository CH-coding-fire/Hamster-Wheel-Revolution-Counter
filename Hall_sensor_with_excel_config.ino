
  int hallSensorPin = 2;
  int ledPin = 13;
  int state = 0;
  int detectedTimes;
  int lastTime;
  int currentTime;
  float duration;
  float pi = 3.14159;
  float diameterOfWheel=32;
  int validCounterTimes;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(hallSensorPin, INPUT);
Serial.println("CLEARDATA");
Serial.println("LABEL,currentTime,detectedTimes, revolutions, speed(ms), cm/s");
Serial.println("RESETTIMER");
  
} 

void loop() {
  state = digitalRead(hallSensorPin);
  
  if(state ==LOW){
    currentTime = millis();
    duration = currentTime-lastTime;
    lastTime = currentTime;

    if(duration>200){
    detectedTimes = detectedTimes + 1;
    }
    
    if(duration>600 && duration<2500){
    Serial.print("DATA,TIME,");
    digitalWrite(ledPin,HIGH);  

    validCounterTimes = validCounterTimes+1;
    
    Serial.print(detectedTimes);
    Serial.print(",");
    Serial.print(validCounterTimes);
    Serial.print(",");
    Serial.print(duration);
    Serial.print(",");
    Serial.println((1000/duration)*diameterOfWheel*pi);
    delay(300);}
  }else{
    digitalWrite(ledPin, LOW);
  }
}
