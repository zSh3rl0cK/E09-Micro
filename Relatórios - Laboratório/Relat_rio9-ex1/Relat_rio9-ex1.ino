#define pwm_out PD6
#define botao PD1
unsigned int Ton = 0; // tempo ligado

ISR(PCINT2_vect){
  if(!(PIND&(1<<botao))){
      OCR0A = 128; // 255 (100%) * 1/2
  }
  else{
    OCR0A = 0;
  }
}

int main(){
  DDRD = 0;
  DDRD |= (1<<pwm_out); // saida
  PORTD |= (1<<botao); // pull-up

  // configurando o pwm
  TCCR0A |= (1<<COM0A1);
  TCCR0A |= (1<<WGM01)|(1<<WGM00);
  TCCR0B |= (1<<CS01);

  OCR0A = 0;

  PCICR |= (1<<PCIE2);
  PCMSK2 |= (1<<PCINT17);
  sei();

  while(1){
    
  }
}
