


int sonidos[] = {3830, 3400, 3038, 2864};

byte melodia[1024];
int mSize = 0;

void setup() {
 for (byte i = 0; i < 4; i++) {
  pinMode(2*i, INPUT);
  pinMode(2*i+1, OUTPUT);
 }
 
 randomSeed(analogRead(0));
 start();
 
}

void loop() {
 
 if (mSize < 1023) {
  int valor = random(4);
   melodia[mSize] = valor;
   mSize++;
 }
 
 for (int i = 0; i < mSize; i++) 
   encender(melodia[i]);

  
 for (int i = 0; i < mSize; i++) {
  int leido = pulsado();
  encender(leido);
  
  if (leido != melodia[i]) {
    mSize = 0; 
    start(); 
  }
    
 } 
  
  
  
  delay(400);
}


void encender(int i) {
 digitalWrite(2*i+1, HIGH);
 tone(9, sonidos[i], 100);  
 delay(500);
 digitalWrite(2*i+1, LOW);
 
}


byte pulsado() {
  
 while (true) {
  for (byte i = 0; i < 4; i++)
    if (digitalRead(2*i))
      return i;
  
  
  delay(100);
  
 } 
 
 return 0; 
  
}


void start() {
  for (byte j = 0; j < 5; j++) {
    
   for (byte i = 0; i < 4; i++) 
     digitalWrite(2*i+1, HIGH);
    
    delay(200);
     
   for (byte i = 0; i < 4; i++) 
     digitalWrite(2*i+1, LOW); 
     
    delay(200);
  }
  
}
