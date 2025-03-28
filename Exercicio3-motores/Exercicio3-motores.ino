#define chave1 PD5
#define motor1 PD0 // 30
#define motor2 PD1 // 50
#define chave2 PB0
#define chave3 PD4
#define motor3 PD3 // 70

int main() {

  // Configura os pinos dos motores como saída
  DDRD |= (1 << motor1) | (1 << motor2) | (1 << motor3);
  DDRB &= ~(1 << chave2); // Configura chave2 como entrada
  DDRD &= ~((1 << chave1) | (1 << chave3)); // Configura chave1 e chave3 como entrada

  // Inicializa portas
  PORTD &= ~((1 << motor1) | (1 << motor2) | (1 << motor3));
  PORTB &= ~(1 << chave2);

  int soma_pot = 0;

  while (1) {
    // Verifica chave1
    if(PIND & (1 << chave1)){
      if(!(PORTD & (1 << motor1))){ // Verifica se o motor já está ligado
        soma_pot += 30;
      }
      
      PORTD |= (1 << motor1);
    } 
    else {
      if(PORTD & (1 << motor1)){
        soma_pot -= 30;
        PORTD &= ~(1 << motor1);
      }
    }

    // Verifica chave2
    if(PINB & (1 << chave2)){
      if(!(PORTD & (1 << motor2))){
        soma_pot += 50;
      }
      
      PORTD |= (1 << motor2);
    } 
    else {
      if(PORTD & (1 << motor2)){
        soma_pot -= 50;
        PORTD &= ~(1 << motor2);
      }
    }

    // Verifica chave3
    if(PIND & (1 << chave3)){
      if(!(PORTD & (1 << motor3))){
        soma_pot += 70;
      }
      
      PORTD |= (1 << motor3);
    } 
    else {
      if(PORTD & (1 << motor3)){
        soma_pot -= 70;
        PORTD &= ~(1 << motor3);
      }
    }

    // Verifica se a soma de potência excede 90
    while(soma_pot > 90){
      if(PORTD & (1 << motor1)){
        PORTD &= ~(1 << motor1);
        soma_pot -= 30;
      }
      else if(PORTD & (1 << motor2)){
        PORTD &= ~(1 << motor2);
        soma_pot -= 50;
      }
    }
  }
} 
