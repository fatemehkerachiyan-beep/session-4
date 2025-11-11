
int trig = 11;
int echo = 12;
int duration;
int distances;
int led=3;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(0.002);
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distances = (duration / 2) * 0.0343;
  Serial.println(distances);
  delay(20);
  int new_distances=map(distances,30,4,0,255);
  if(distances>=4 and distances<=30){
  analogWrite(led,new_distances);
}
}
