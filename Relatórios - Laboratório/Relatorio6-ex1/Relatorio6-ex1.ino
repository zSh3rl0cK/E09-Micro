#define LED1 PD5
#define LED2 PD4
#define BOTAO PD2

ISR(INT0_vect){
  // Piscando o led
  PORTD |= (1<<LED2);
  _delay_ms(1000);
  PORTD &= ~(1<<LED2);
}

int main(void){
  // Configura os pinos 5 (PD5) e 4 (PD4) como saída
  DDRD |= (1<<LED1) | (1<<LED2);
  
  // Habilita o resistor interno de pull-up no pino 2 (PD2)
  PORTD |= (1<<BOTAO);
  
  // Configura a interrupção externa 0 para transição de subida
  EICRA = 0b00000011;
  
  // Habilita a interrupção externa 0
  EIMSK = 0b00000001;
  
  // Habilita a interrupção global
  sei();
  
  //Super loop
  while (1){
    PORTD ^= (1<<LED1);
    _delay_ms(500);
  }
  
}
