#include <Servo.h> 
 
Servo myservo1, myservo2;

int byteRead;

int servo1[3] = {1700,1437,1300};
int servo2[3] = {1310,1429,1545};

//int servo1[3] = {1700,1428,1300};
//int servo2[3] = {1310,1435,1545};

int val1 = 0;
int val2 = 0;
 
void setup() 
{ 
  Serial.begin(9600);
  
  myservo1.attach(9);
  myservo2.attach(10);
  
  //byteRead = 50;
}
 
 
void loop() 
{ 
  if (Serial.available()){
    byteRead = Serial.read();
    if (byteRead == 49){
      va11--;
    }
    else if (byteRead == 50){
      val1++;
    }
    else if (byteRead == 51){
      val2--;
    }
    else if (byteRead == 52){
      val2++;
    }
  }
  
  Serial.print(val1);
  Serial.print("\t");
  Serial.println(val2);
  Serial.println();
  
  myservo1.writeMicroseconds(servo1[1]+val1);
  myservo2.writeMicroseconds(servo2[1]-val2);
  /*
  switch (byteRead){
    case 49:
      myservo1.writeMicroseconds(servo1[0]);
      myservo2.writeMicroseconds(servo2[0]);
      break;
    case 50:
      myservo1.writeMicroseconds(servo1[1]);
      myservo2.writeMicroseconds(servo2[1]);
      break;
    case 51:
      myservo1.writeMicroseconds(servo1[2]);
      myservo2.writeMicroseconds(servo2[2]);
      break;
  }
  */
}

