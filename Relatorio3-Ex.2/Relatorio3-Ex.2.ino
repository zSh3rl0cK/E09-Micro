void setup() {
  // put your setup code here, to run once:
  DDRD = 0b0000001110; // definindo como saida PD3/2/1 e entrada PD4
  PORTD = 0b00001110; // Setup inicial de nivel logico alto em PD3/2/1
}

void loop() {
  // put your main code here, to run repeatedly:

    // Configurando PD2 e PD1 para a saida desejada (00)
    PORTD = 0b00000000;
    _delay_ms(500);

    // Configurando PD2 e PD1 para a saida desejada (01)
    PORTD = 0b00000010;
    _delay_ms(500);

    // Configurando PD2 e PD1 para a saida desejada (10)
    PORTD = 0b00000100;
    _delay_ms(500);

    // Configurando PD2 e PD1 para a saida desejada (11)
    PORTD = 0b00000110;
    _delay_ms(500);
}
