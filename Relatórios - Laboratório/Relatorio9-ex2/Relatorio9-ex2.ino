#define pwm_out PD6
#define botao PD1
unsigned int Ton = 0; // tempo ligado

ISR(PCINT2_vect){
  if(!(PIND&(1<<botao))){
      Ton+=26;
  }
  else{
    OCR0A = Ton;
  }
  if(Ton > 255){
    Ton = 0;
  }
}

int main(){
  DDRD = 0; // entradas
  DDRD |= (1<<pwm_out); // saida
  PORTD |= (1<<botao); // pull-up

  // configurando o pwm
  TCCR0A |= (1<<COM0A1);
  TCCR0A |= (1<<WGM01)|(1<<WGM00);
  TCCR0B |= (1<<CS01);

  OCR0A = 0; // iniciando desligado

  // Configuração da interrupcao externa em PCINT2
  PCICR |= (1<<PCIE2);
  PCMSK2 |= (1<<PCINT17);
  sei();
  
  while(1){
  }
}
