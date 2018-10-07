#include <Servo.h> 

const unsigned int TRIG_PIN = 12;
const unsigned int ECHO_PIN = 11;

const unsigned int SERVO_PIN = 8;

const unsigned int BAUD_RATE= 9600;


unsigned int angle = 0; 

Servo servo;

void setup() {

  servo.attach(SERVO_PIN);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);

}

int distance(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  return duration/29/2;
  
  }

int pos = 0; 
void loop() {

  for (pos = 0; pos <= 180; pos += 1) {
 
    servo.write(pos); 
    
    Serial.print("D");    
    Serial.println(distance());

    Serial.print("A");
    Serial.println(pos);            
    delay(50);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos); 
    
    Serial.print("D");    
    Serial.println(distance());

    Serial.print("A");
    Serial.println(pos);            
    delay(50);                     
  }
    

}
