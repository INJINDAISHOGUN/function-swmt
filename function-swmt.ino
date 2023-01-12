int bt=17;
int wifi=2;
int ntp=15;
int iot=12;
int sw1=16; //INPUT
int sw2=14; //INPUT

void setup() {
  pinMode(bt, OUTPUT);
  pinMode(wifi, OUTPUT);
  pinMode(ntp, OUTPUT);
  pinMode(iot, OUTPUT);
  
  pinMode(sw1,INPUT_PULLUP); //Configure the switch to be positive.(กำหนดสวิตช์ให้เป็นไฟขั้วบวก)
  pinMode(sw2,INPUT_PULLUP); //Configure the switch to be positive.(กำหนดสวิตช์ให้เป็นไฟขั้วบวก)
  
  //sw1=HIGH; //configure the led to turn off(กำหนดค่า led ให้ดับ)
  //sw2=HIGH; //configure the led to turn off(กำหนดค่า led ให้ดับ)
}

void loop() {
  Serial.begin(9600);
  if(digitalRead(sw1)==LOW){
    forward();
  }else{
    stopped();
  }
  
  if(digitalRead(sw2)==LOW){
    backward();
  }else{
    stopped();
  }

}

void forward(){ //0101
  digitalWrite(bt, HIGH);
  digitalWrite(wifi, LOW);
  digitalWrite(ntp, HIGH);
  digitalWrite(iot, LOW);
}

void backward(){ //1010
  digitalWrite(bt, LOW);
  digitalWrite(wifi, HIGH);
  digitalWrite(ntp, LOW);
  digitalWrite(iot, HIGH);
}

void stopped(){ //0000
  digitalWrite(bt, HIGH);
  digitalWrite(wifi, HIGH);
  digitalWrite(ntp, HIGH);
  digitalWrite(iot, HIGH);
}
