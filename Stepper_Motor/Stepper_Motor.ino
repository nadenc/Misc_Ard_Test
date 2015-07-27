int Control1 = A0;
int Control2 = A1;
int Control3 = A2;
int Control4 = A3;

int motorState, val;
int stepSettleTime = 2; // time between each step in milliseconds

// This array keeps track of the current motor position
int motorPos[4][4] = {
  {1, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 1}
};

int controlPins[4] = {Control1, Control2, Control3, Control4};

void setup(){
  pinMode(Control1, OUTPUT);
  pinMode(Control2, OUTPUT);
  pinMode(Control3, OUTPUT);
  pinMode(Control4, OUTPUT);
  
  // Sets initial motor position
  motorState = 1;
  digitalWrite(Control1, 1);
  digitalWrite(Control2, 0);
  digitalWrite(Control3, 0);
  digitalWrite(Control4, 0);
  
  //Serial.begin(9600);
}

void loop(){
  for(int i=0;i<10000;i++){
    moveStep(-1);
    delay(stepSettleTime);
  }
  for(int i=0;i<10000;i++){
    moveStep(1);
    delay(stepSettleTime);
  }
}

// Rotate stepper a single step(1 for pos direction, -1 for neg direction)
void moveStep(int moveDir){
  motorState = motorState + moveDir;
  if(motorState == 5)
    motorState = 1;
  else if(motorState == 0)
    motorState = 4;
  
  //Serial.println("Control:");
  for(int controlStep=0;controlStep<4;controlStep++){
    val = motorPos[motorState-1][controlStep];
    digitalWrite(controlPins[controlStep], val);
    //Serial.print(val);
  }
  
  //Serial.println();
  
  return;
}

// This was my attempt at maintaining tension with SW, it worked OK but not great, our weighted line for tensioning should be much better
void tension(){
  for(int stateStep=0;stateStep<51;stateStep++){
    if(stateStep<50){
      for(int controlStep=0;controlStep<5;controlStep++){
        val = motorPos[stateStep%4][controlStep];
        digitalWrite(controlPins[controlStep], val);
      }
      delay(2);
    }
    else{
      for(int controlStep=0;controlStep<4;controlStep++){
        digitalWrite(controlPins[controlStep], 0);
      }
      delay(1000);
    }
  }
  return;
}
