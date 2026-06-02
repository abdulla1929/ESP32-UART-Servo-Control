#include<Servo.h>

Servo servo;
String input="";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo.attach(10);
  servo.write(90);

}

void loop() {
  while(Serial.available()){
    char c=Serial.read();
    if(c=='\n'){
      int angle=input.toInt();
      angle=constrain(angle,0,180);
      servo.write(angle);
      input="";
    }
    else{
      input+=c;
    }
  }
  // put your main code here, to run repeatedly:

}
