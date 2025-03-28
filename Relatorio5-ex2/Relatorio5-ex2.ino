int main() {
    // Configura os pinos dos motores (saídas)
    DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD2);
    
    // Habilita pull-up nos botões (entradas)
    PORTD |= (1<<PD5) | (1<<PD6) | (1<<PD7);

    // Inicia motores desligados
    PORTD &= ~((1<<PD0) | (1<<PD1) | (1<<PD2));

    // Estados dos motores (0 = desligado, 1 = ligado)
    int estadoM1 = 0;
    int estadoM2 = 0;
    int estadoM3 = 0;

    // Potências dos motores
    int potenciaM1 = 30;
    int potenciaM2 = 50;
    int potenciaM3 = 70;
    int potenciaMaxima = 90;

    while(1) {
        // Leitura dos botões (inversão por pull-up)
        int botaoA = !(PIND & (1<<PD5)); // Motor 1 - 30 HP
        int botaoB = !(PIND & (1<<PD6)); // Motor 2 - 50 HP
        int botaoC = !(PIND & (1<<PD7)); // Motor 3 - 70 HP

        // Alterna estados ao pressionar botão
        if (botaoA) {
            _delay_ms(2000); 
            estadoM1 = !estadoM1;
        }
        if (botaoB) {
            _delay_ms(2000); 
            estadoM2 = !estadoM2;
        }
        if (botaoC) {
            _delay_ms(2000); 
            estadoM3 = !estadoM3;
        }

        // Calcula potência total dos motores ligados
        int potenciaTotal = (estadoM1 * potenciaM1) + (estadoM2 * potenciaM2) + (estadoM3 * potenciaM3);

        // Aplica restrição de potência máxima
        if (potenciaTotal > potenciaMaxima) {
            if (estadoM1) { // Desliga o menor primeiro (M1 - 30 HP)
                estadoM1 = 0;
                potenciaTotal -= potenciaM1;
            }
        }
        
        if (potenciaTotal > potenciaMaxima) {
            if (estadoM2) { // Se ainda for >90, desliga o segundo menor (M2 - 50 HP)
                estadoM2 = 0;
                potenciaTotal -= potenciaM2;
            }
        }

        // Atualizando o LED1 - Ligado ou desligado (com base no estado)
        if (estadoM1) {
          PORTD |= (1<<PD0);
        }
        else{
          PORTD &= ~(1<<PD0);
        }

        // Atualizando o LED2 - Ligado ou desligado (com base no estado)
        if (estadoM2){
          PORTD |= (1<<PD1);
        }
        else{
          PORTD &= ~(1<<PD1);
        }

        // Atualizando o LED3 - Ligado ou desligado (com base no estado)
        if(estadoM3){
          PORTD |= (1<<PD2);
        }
        else{
          PORTD &= ~(1<<PD2);
        }
    }
}
