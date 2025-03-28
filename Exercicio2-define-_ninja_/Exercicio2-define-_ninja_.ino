#define temperatura PD2
#define pressao PD4
#define nivel PD5
#define peso PD7
#define led PC5
#define liga_led PORTC!=(1<<led)

int main(){
  // iniciando as entradas e saidas 
  DDRD |= (1<<led);
  // Iniciando todos os pinos como desligados
  PORTD = 0;

  while(1){
    PORTC = 0;
    
    switch(PIND){
      case(52): liga_led;
        break;
      case(132): liga_led;
        break;
      case(16): liga_led;
        break;
      case(4): liga_led;
        break;
    }
  }
}
