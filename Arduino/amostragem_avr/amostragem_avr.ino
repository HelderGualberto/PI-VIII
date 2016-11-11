#define F_CPU 16000000UL
#define BAUD 115200

#include <util/setbaud.h>
#include<avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
//Beginning of Auto generated function prototypes by Atmel Studio
void adc_init();
ISR(ADC_vect );
ISR(TIMER0_COMPA_vect );
uint16_t adc_read(uint8_t ch);
int main(void );
//End of Auto generated function prototypes by Atmel Studio

void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
}

void send_str(byte b){
    while (( UCSR0A & (1<<UDRE0))  == 0){};
    UDR0 = b; 
}

void adc_init()
{
  ADMUX = (1 << REFS0);
  ADCSRA = 0x8F;
  ADCSRA = (1 << ADEN) | (0 << ADPS2) | (0 << ADPS1) | (1 << ADPS0);
}

ISR(ADC_vect)
{ 
  ADMUX ^= 1 << MUX0;
  ADMUX ^= (MUX0 ^ MUX1) << MUX1;
  
  send_str(ADCL);
  send_str(ADCH);

  
  
  ADCSRA |= 1 << ADSC;
}

uint16_t adc_read(uint8_t ch)
{
  ADMUX = (ADMUX & 0xF8) | ch;
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));
  return (ADC);
}

int main(void)
{
  ADCSRA = 0x8F;
  ADMUX = 0b01000000;
  sei();
  ADCSRA |= 1 << ADSC;
  uart_init();
  while (1);
}
