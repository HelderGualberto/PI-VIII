
uint16_t a0;
uint16_t a1;
uint16_t a2;
uint16_t a3;

byte str[12];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
/*
  str[0] = 125; //lsb
  str[1] = 1; //msb
  str[2] = 123; //lsb
  str[3] = 2; //msb
  str[4] = 124; //lsb
  str[5] = 3; //msb
  str[6] = 127; //lsb
  str[7] = 0; //msb
  */

/*
  delayMicroseconds(125);
  str = a0; //lsb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a0 >> 8; //msb 
  Serial.write(&str,1);
  delayMicroseconds(125);
  str =a1; //lsb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a1 >> 8; //msb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a2; //lsb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a2 >> 8; //msb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a3; //lsb
  Serial.write(&str,1);
  delayMicroseconds(125);
  str = a3 >> 8; //msb
  Serial.write(&str,1);
  delayMicroseconds(125);*/
  }
