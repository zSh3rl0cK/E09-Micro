#define temperatura PD2
#define pressao PD4
#define nivel PD5
#define peso PB0
#define led PD0

int main(){
  // iniciando as entradas e saidas
  DDRD |= (1<<led);
  DDRB = 0;

  // Iniciando todos os pinos como desligados
  PORTB = 0;

  while(1){
    PORTD = 0;
    
    // 1. Nivel alto, temperatura alta e pressao alta
    while((PIND & (1<<temperatura)) && (PIND & (1<<pressao)) &&(PIND & (1<<nivel))){
      PORTD |= (1<<led);    
    }

    // 2. Nivel baixo, temperatura alta e peso alto
    while((PIND & (1<<temperatura)) && (PIND & (1<<peso)) && !(PIND & (1<<nivel))){
      PORTD |= (1<<led);
    }

    // 3. Nivel baixo, temperatura baixa e pressao alta
    while(!(PIND & (1<<temperatura)) && !(PIND & (1<<nivel)) && (PIND & (1<<pressao))){
      PORTD |= (1<<led);
    }
  
    // 4. Nivel baixo, peso baixo e temperatura alta
    while((PIND & (1<<temperatura)) && !(PIND & (1<<nivel)) && !(PIND & (1<<peso))){
      PORTD |= (1<<led);
    }
  }
}
