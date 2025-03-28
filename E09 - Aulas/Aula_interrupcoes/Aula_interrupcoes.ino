#define chave1 PD1
#define chave2 PD2
#define led1 PC5
#define led2 PC0

unsigned char j; // gasta menos memória
ISR(INT0_vect){
  PORTC &= ~(1<<led1); // desliga o led1

  // pisca o led de alerta
  for(j = 0; j <20; j++){
    PORTC ^= (1<<led2);
    _delay_ms(200);
  }
}

int main(){
  DDRD = 0; // Entradas
  DDRC = 0; // garantindo
  DDRC |= (1<<led1)|(1<<led2); // Saídas

  EICRA |= (1<<ISC00); // Interrompe na mudança de nível lógico
  EIMSK |= (1<<INT0); // Habilita o INT0
  sei(); // Habilita a interrupção

  // chave 1 liga o led
  while(1){
    if(PIND & (1<<chave1)){
      PORTC |= (1<<led1);
      _delay_ms(5000);
      PORTC &= ~(1<<led1);
    }
  }
}
