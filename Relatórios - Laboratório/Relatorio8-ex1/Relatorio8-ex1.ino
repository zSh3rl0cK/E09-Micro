#define LED PD0

int valor_contagem = 0;

ISR(TIMER0_COMPA_vect){
  valor_contagem++;

  if(valor_contagem >= 2000){ // 2000 * 75us = 150ms
    valor_contagem = 0;
    PORTD ^=(1<<LED); // Pisca o led
  }
}

int main(){
  DDRD = 255; // definindo entrada
  PORTD = 0;

  TCCR0A |= (1<< WGM01); // TCT - Comparação
  TCCR0B |= (1<<CS01); // Prescaler 8 (0 1 0)

  OCR0A = 149; // ticks (0 a 149) - 50ns * 150 = 75 us - X = 150ms/75us = 2000

  TIMSK0 |= (1<<OCIE0A); // Habilita interrupção no 0CR0A

  sei();

  while(1){
  }
}
