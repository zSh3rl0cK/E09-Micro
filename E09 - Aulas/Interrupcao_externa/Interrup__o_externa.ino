#define snesor1 PD1
#define sensor2 PB7
#define led1 PC5
#define led2 PB5

unsigned char j;

ISR(PCINT0_vect){
  PORTC &= ~(1<<led1);

  for(j = 0; j < 10; j++){
    PORTB |= (1<<led2);
    _delay_ms(600);
    PORTB &= ~(1<<led2);
  }
}

ISR(PCINT2_vect){
  PORTC &= ~(1<<led1);
  
  for(j = 0; j < 10; j++){
    PORTB |= (1<<led2);
    _delay_ms(300);
    PORTB &= ~(1<<led2);
  }
}

int main(){
  // Entradas e saídas
  DDRD = 0;
  DDRC = 255;
  DDRB = 0;
  DDRB |= (1<<led2);
  PORTB = 0;
  PORTC = 0;

  // Interrupções
  PCICR |= (1<<PCIE0)|(1<<PCIE2);
  PCMSK0 |= (1<<PCINT7);
  PCMSK2 |= (1<<PCINT17);
  sei();

  // Piscando o led
  while(1){
    PORTC ^= (1<<led1);
    _delay_ms(5000);
  }
}
