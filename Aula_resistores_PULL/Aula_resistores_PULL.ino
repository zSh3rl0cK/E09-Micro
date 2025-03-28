int main(){
  DDRD = (1<<PD6); // Todos os pinos como entrada
  PORTD = 0b11111111; // Liga o PULL-UP em todos os pinos de entrada
  while(1){
    PORTD &= ~(1<<PD6);
    _delay_ms(1000);
    
    PORTD |= (1<<PD6);
    _delay_ms(1000);
  }
}
