#define LED1 PD5
#define LED2 PD4
#define BOTAO PD2
#define BOTAO2 PD3

ISR(INT0_vect){
  // Piscando o led
  PORTD |= (1<<LED2);
  _delay_ms(1000);
  PORTD &= ~(1<<LED2);
}

ISR(INT1_vect){
  EIMSK ^= (1<<INT0); // Habilita a interrupção externa 0
}

int main(void){
  DDRD |= (1<<LED1) | (1<<LED2); // Configura os pinos 5 (PD5) e 4 (PD4) como saída
  PORTD |= (1<<BOTAO)|(1<<BOTAO2); // Habilita o resistor interno de pull-up no pino 2 (PD2)
  
  EICRA |= (1<<ISC11)|(1<<ISC10); // Configura a interrupção externa 1 para transição de subida
  EICRA |= (1<<ISC00)|(1<<ISC01); // Configura a interrupção externa 0 para transição de descida

  EIMSK |= (1<<INT1); // ativando apenas o INT1
  
  // Habilita a interrupção global
  sei();
  
  //Super loop
  while (1){
    PORTD ^= (1<<LED1);
    _delay_ms(500);
  }
  
}
