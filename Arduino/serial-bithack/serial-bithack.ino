
uint16_t a0;
uint16_t a1;
uint16_t a2;
uint16_t a3;

byte str[12];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  delay(2000);
}

void loop() {

  delayMicroseconds(250);
  a0 = analogRead(0) ;
  delayMicroseconds(250);
  a1 = analogRead(1)| (1<<10) ;
  delayMicroseconds(250); 
  a2 = analogRead(2) | (0<<10) |(1<<11);
  delayMicroseconds(250);  
  a3 = analogRead(3) | (1<<10) | (1<<11);
  delayMicroseconds(250);

  //Preamble bytes
  str[0] = 0b00010000;
  str[1] = 0b00100000; 
  str[2] = a0; //lsb
  str[3] = a0 >> 8; //msb
  str[4] = a1; //lsb
  str[5] = a1 >> 8; //msb
  str[6] = a2; //lsb
  str[7] = a2 >> 8; //msb
  str[8] = a3; //lsb
  str[9] = a3 >> 8; //msb
  str[10] = 0b01000000; 
  str[11] = 0b10000000;

  Serial.write(str,12);
  delay(10);

  }
