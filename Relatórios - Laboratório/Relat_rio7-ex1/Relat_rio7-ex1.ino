#define led1 PD5
#define led2 PD7
#define led3 PD6
#define led4 PB1

// Na interrupção PCINT0 (botão em PB0)
ISR(PCINT0_vect){
  if(!(PINB & (1<<PB0))){ 
    PORTD |= (1<<led2);
    _delay_ms(1000);
    PORTD &= ~(1<<led2);
  }

  if(!(PINB & (1<<PB2))){
    PORTD |= (1<<led3);
    _delay_ms(500);
    PORTD &= ~(1<<led3);
  }
}

// Na interrupção PCINT2 (botão em PD4)
ISR(PCINT2_vect){
  if(!(PIND & (1<<PD4))){
    PORTB |= (1<<led4);
    _delay_ms(2000);
    PORTB &= ~(1<<led4);
  }
}

int main(void){
  DDRD |= (1<<led1)|(1<<led2)|(1<<led3);
  DDRB |= (1<<led4);

  PORTB |= (1<<PB0) | (1<<PB2); // Ativar pull-up nos botões em PB0 e PB2
  PORTD |= (1<<PD4); // Ativar pull-up no botão em PD4
  
  // Habilita interrupção no grupo PCINT0 e PCINT2
  PCICR |= (1<<PCIE0) | (1<<PCIE2);
  
  // Habilita interrupções individuais para PB0 e PB2 no PCINT0
  PCMSK0 |= (1<<PCINT0) | (1<<PCINT2);
  // Habilita interrupção individual para PD4 no PCINT2
  PCMSK2 |= (1<<PCINT20);
  
  // Habilita Interrupções globais
  sei();
  
  while (1){
    PORTD ^= (1<<led1);
    _delay_ms(250);
  }
}
