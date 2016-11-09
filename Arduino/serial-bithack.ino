

uint16_t a = 100;
uint16_t b = 200;
uint16_t c = 300;
uint16_t d = 400;

byte str;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  str[0] = a; //lsb
  str[1] = a >> 8; //msb
  str[2] = b; //lsb
  str[3] = b >> 8; //msb
  str[4] = c; //lsb
  str[5] = c >> 8; //msb
  str[6] = d; //lsb
  str[7] = d >> 8; //msb
  Serial.write(str,8);
  */

  uint16_t a0 = analogRead(0) ;
  uint16_t a1 = analogRead(1)| (1<<10) ;
  uint16_t a2 = analogRead(2) | (0<<10) |(1<<11);
  uint16_t a3 = analogRead(3) | (1<<10) | (1<<11);
  
  str = a0; //lsb
  Serial.write(&str,1);
  str = a0 >> 8; //msb 
  Serial.write(&str,1);
  str =a1; //lsb
  Serial.write(&str,1);
  str = a1 >> 8; //msb
  Serial.write(&str,1);
  str = a2; //lsb
  Serial.write(&str,1);
  str = a2 >> 8; //msb
  Serial.write(&str,1);
  str = a3; //lsb
  Serial.write(&str,1);
  str = a3 >> 8; //msb
  Serial.write(&str,1);
  str = 0; //msb
  Serial.write(&str,1);
  str = 255; //msb
  Serial.write(&str,1);
  delay(100);
}
