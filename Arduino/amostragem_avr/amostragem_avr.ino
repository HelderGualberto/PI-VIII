#define F_CPU 16000000UL
#define BAUD 230400

#include <util/setbaud.h>
#include<avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
typedef union _bit16{
    uint16_t __2bytes;  // or use int16_t to be more specific
    //   vs.z
    struct bit8 {
        uint8_t lsb, msb;  // or use int8_t to be more specific
    } __1byte;
    
}bit16;
void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
    UCSR0B = _BV(RXEN0) | _BV(TXEN0); 
}

void send_str(char a){
    while (( UCSR0A & (1<<UDRE0))  == 0){};
    UDR0 = a; 
}
void send_bit16(bit16 a){
  
    while (( UCSR0A & (1<<UDRE0))  == 0){};
    UDR0 = a.__1byte.msb; 
    while (( UCSR0A & (1<<UDRE0))  == 0){};
    UDR0 = a.__1byte.lsb; 
//    while (( UCSR0A & (1<<UDRE0))  == 0){};
//    UDR0 = '\n'; 
}
uint16_t adc_read(uint8_t ch)
{   //no interruption method
    ADMUX = (ADMUX & 0xF8)|ch;
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC));
    return (ADC & 0x3FF);
}
void adc_init()
{
  ADCSRA |= (1 << ADEN); // Enable the ADC
  ADCSRA |= (0 << ADPS0)|(1 << ADPS1)|(0 << ADPS2); // Set ADC frequency to be divided by 4 - less than this, it wont work.
  //ADCSRA |= (1 << ADATE); //ADC AUTO-TRIGGER
  //ADCSRB = (0 << ADTS0)|(0 << ADTS1)|(0 << ADTS2); // Set ADC to free running mode (I'm not sure what does this line, I just saw it in some examples, appears to do something xD)
  ADMUX |= (0 << ADLAR); // Set the right justified MSB, located in ADCL (8 - MSB) and ADCH (2 - LSB). ADCL need to be read before ADCH 
  ADMUX |= (1 << REFS0)|(0 << REFS1);// Set the Vref to Internal VCC

}
void debug_print(char *c , int porta){
   Serial.print(c);
   Serial.println(porta);
}
ISR(ADC_vect)
{//interruption method
  
  //ADMUX |= (0 << MUX2)|(1 << MUX1)|(1 << MUX0);
//  ADMUX |= ((b1 & ( 1 << 1 )) >> 1 ) << MUX0; //  1-th bit of n
  //ADMUX ^= (MUX0 ^MUX1 ) << MUX1;
  debug_print("ADMUX ", ADMUX);

  ADCSRA |= 1 << ADSC; // restart conversion
}
int main(void)
{
  Serial.begin(BAUD);
  adc_init();
  //ADCSRA |= (1 << ADIE); // Enable interrupts 
  //ADCSRA |= 1 << ADSC; //START CONVERSION
  
  //sei();
  //uart_init();
  while (1){
    //send_str("teste");
    //Serial.println("teste");
    bit16 ad0, ad1, ad2, ad3;
    ad0.__2bytes =  adc_read(0);
    //send_bit16(ad0);
    Serial.print(ad0.__2bytes);
    ad1.__2bytes = adc_read(1);
    ad1.__1byte.msb =  ad1.__1byte.msb | 0b00000111;
    //send_bit16(ad1);
    Serial.print(ad1.__2bytes);
    ad2.__2bytes = adc_read(2);
    ad2.__1byte.msb =  ad2.__1byte.msb | 0b00001011;
    //send_bit16(ad2);
    Serial.print(ad2.__2bytes);
    ad3.__2bytes = adc_read(3);
    ad3.__1byte.msb =  ad3.__1byte.msb | 0b00001111;
    //send_bit16(ad3);
    Serial.print(ad3.__2bytes);

  }

}

