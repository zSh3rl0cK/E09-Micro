#define LED PD0
#define LED2 PD4

int valor_contagem_min = 0;
int valor_contagem_seg = 0;

ISR(TIMER0_COMPA_vect){
  valor_contagem_min++;
  valor_contagem_seg++;

  if(valor_contagem_seg >= 10000){ // (1s)
    PORTD |= (1<<LED);
    
    if(valor_contagem_seg == 11000){ // desliga apos 100ms
      PORTD &= ~(1<<LED);
      valor_contagem_seg = 0;
    }
  }

  if(valor_contagem_min >= 600000){ // 60s 
    PORTD |= (1<<LED2);
    
    if(valor_contagem_min == 11000){ // desliga apos 100ms
      PORTD &= ~(1<<LED2);
      valor_contagem_min = 0;
    }
  }
}

int main(){
  DDRD = 255; // definindo entrada
  PORTD = 0;

  TCCR0A |= (1<< WGM01); // TCT - Comparação
  TCCR0B |= (1<<CS01); // Prescaler 8 (0 1 0)

  OCR0A = 199; // ticks (0 a 149) - 500ns * 200 = 100 us

  TIMSK0 |= (1<<OCIE0A); // Habilita interrupção no 0CR0A

  sei();

  while(1){
  }
}
