int trig = 53;
int echo = 52;
float distancia;
float duracao;
float velocidade = 0.0172316;
int buzzer = 49;

void setup()
{
  Serial.begin(9600); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(50, OUTPUT);
}

void loop()
{
  digitalWrite(trig, 0);
  delayMicroseconds(5);

  digitalWrite(trig, 1);
  delayMicroseconds(10);

  digitalWrite(trig, 0);

  duracao = pulseIn(echo, 1);
  distancia = duracao * velocidade;
 
  if (distancia < 50) {
    tone(buzzer, 10);
    digitalWrite(50, HIGH); 
  }
  else {
    noTone(buzzer);
    digitalWrite(50, LOW);
  }
  Serial.println(digitalRead(50));
  delay(100);
}
