int trim = A0;
int motor = 3;

int val;



void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  val = map(analogRead(trim), 0, 511, 0, 255);
  
  Serial.println(val);
  
  analogWrite(motor, val);
}
