int main(){
  DDRC = 0;
  DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2); // Tratando os pinos 0, 1 e 2  como entrada
  PORTD |= (1<<PD1)|(1<<PD2); // Habilitando o PULL-up em PD1 e PD2
  
  while(1){
    int botaoNA = (PIND & (1<<PD0)); // Mascara Botao de ligar
    int botaoNF = !(PIND & (1<<PD1)); // Mascara Botao de desligar
    int sensor = !(PIND & (1<<PD2)); // Mascara sensor
    
    // ---------- Sensor de amontoamento -----------
    if(sensor == 0){
      PORTC |= (1<<PD1); // Liga o alarme
      PORTC &= ~(1<<PD0); // Desliga o motor
    }
    else{
      // ---------- Botão de ligar -------------------
      if(botaoNA == 1){
        PORTC |= (1<<PC0); // Liga o motor
      }
    
      // ---------- Botão de desligar ----------------
      if(botaoNF == 0){
        PORTC &= ~(1<<PC0); // Desliga o motor
      }
    }

    if(sensor == 1 && botaoNA==1){
      PORTC |= (1<<PC0); // Liga o motor
    }
   
  }
}
