#define sensor1 PD2
#define sensor2 PD3
#define forno PB0

ISR(INT0_vect){
    PORTB &= ~(1 << forno); // Desliga apenas o bit do forno
}

ISR(INT1_vect){
    PORTB |= (1 << forno);  // Liga apenas o bit do forno
}

int main(){
    DDRD = 0; // Configura todas as portas D como entrada
    PORTD |= (1 << sensor1) | (1 << sensor2); // Habilita pull-ups internos para evitar flutuação

    DDRB |= (1 << forno); // Configura forno como saída

    EICRA |= (1<<ISC01) | (1<<ISC00); // Configura INT0 para borda de subida
    EICRA |= (1<<ISC11) | (1<<ISC10); // Configura INT1 para borda de subida
    EIMSK |= (1<<INT0) | (1<<INT1);   // Habilita interrupções externas

    sei(); // Habilita interrupções globais

    while(1){
        // O loop pode conter sleep_mode(); para economia de energia
    }
}
