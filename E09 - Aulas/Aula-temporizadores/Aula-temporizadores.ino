#define led1 PC0
#define chave PD4

int main(){
  DDRD = 0;
  DDRC = 255;

  TCCR0A = 0;
  TCCR0B |= (1<<CS02)|(1<<CS01)|(1<<CS00); // valor lido na tabela - CLK externo com borda de subida]

  

  PORTC = 0;
  while(1){
    if(TCNT0 == 255){
      PORTC ^= (1<<led1); // liga o led
      TCNT0 = 0; // reinicia o contador
    }
  }
}
