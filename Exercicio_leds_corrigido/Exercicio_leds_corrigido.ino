int main(){
  // Configura todos os pinos do PORTD e PORTB como entrada
  DDRD = 0;
  DDRB = 0;
  
  // Configura todos os pinos do PORTC como saída
  DDRC = 0b111111;
  
  // Habilita resistores de pull-up em PD0 e PD1 (Chaves A e B)
  PORTD |= ((1<<PD0)|(1<<PD1));
  
  // Garante que todos os LEDs estão apagados inicialmente
  PORTC = 0;

  while(true){

    //--------  Configurando a porta A ----------
    if(!(PIND & (1<< PD0))){
      PORTC = 0;
      _delay_ms(300);
      PORTC = 255;
      _delay_ms(300);
    }

    //--------  Configurando a porta b  ---------
    if(!(PIND & (1<< PD1))){
      PORTC = 0;
      _delay_ms(300);
      PORTC |= (1<<PC0) | (1<<PC2);
      _delay_ms(300);
      PORTC = 0;
      _delay_ms(300);
      PORTC |= (1<<PC1) | (1<<PC3);
      _delay_ms(300);
    }

    // -------- Configurando a porta C ----------
    if(!(PINB & (1<< PB0))){
      PORTC = 0;
      _delay_ms(300);
      PORTC |= (1<<PC0);
      _delay_ms(300);
      PORTC |= (1<<PC1);
      _delay_ms(300);
      PORTC |= (1<<PC2);
      _delay_ms(300);
      PORTC |= (1<<PC3);
      _delay_ms(300);
    }

    //  -------- Configurando a porta D ---------
    if(!(PINB & (1<< PB1))){
      PORTC |= (1<<PC1) | (1<<PC3)|(1<<PC0) | (1<<PC2);

      _delay_ms(300);
      PORTC &= ~(1<<PC0);
      _delay_ms(300);
      PORTC &= ~(1<<PC1);
      _delay_ms(300);
      PORTC &= ~(1<<PC2);
      _delay_ms(300);
      PORTC &= ~(1<<PC3);
      _delay_ms(300);
      
    }
  }
}
