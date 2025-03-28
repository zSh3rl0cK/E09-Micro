#define VERMELHO_ON (1<<PC5)
#define AMARELO_ON (1<<PC1)
#define VERDE_ON (1<<PB5)

int main() {
  // put your setup code here, to run once:
  DDRB = VERDE_ON;
  DDRC = VERMELHO_ON | AMARELO_ON;
  
    while(1){
      //Ligando apenas o led vermelho
      PORTB = 0;
      PORTC = VERMELHO_ON;
      _delay_ms(2000);
      
      //Ligando apenas o led verde
      PORTB = VERDE_ON;
      PORTC = 0;
      _delay_ms(2000);

      // Ligando apenas o led amarelo
      PORTB = 0;
      PORTC = AMARELO_ON;
      _delay_ms(2000);
    }
}
