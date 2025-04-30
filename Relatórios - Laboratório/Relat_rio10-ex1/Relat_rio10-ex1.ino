#define led PD6 // pino do led

unsigned long int leituraAD = 0;
unsigned long int tenso = 0;

ISR(TIMER0_vect) { // Interrupção de overflow do Timer0
  // Inicia uma nova conversão ADC
  ADCSRA |= (1 << ADSC);

  // Espera a conversão terminar
  while (ADCSRA & (1 << ADSC));

  leituraAD = ADC; // Lê o valor convertido
  tenso = (leituraAD * 5000) / 1023;

  // Atualiza o PWM proporcional à tensão
  OCR0A = leituraAD >> 2; // Dividindo por 4 (1023/4 ≈ 255) para caber no PWM de 8 bits

  Serial.print(tenso);
  Serial.println(" mV");
}

int main() {
   Serial.begin(9600);
  
  // Configurando pinos
  DDRD = 0 // Tudo como entrada
  DDRD |= (1<<led); // PD6 como saída PWM

  // Configura o Timer0 para modo Fast PWM
  TCCR0A |= (1 << COM0A1); // Saída PWM no OC0A (pino PD6)
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM
  TCCR0B |= (1 << CS01); // Prescaler 8

  // Habilita interrupção de overflow do Timer0
  TIMSK0 |= (1 << TOIE0);

  OCR0A = 0; // Inicializa LED apagado

  // Configura o ADC
  ADMUX = (1 << REFS0); // Referência em AVcc (5V)
  ADMUX |= 0; // Leitura no canal ADC0 (pino A0)
  // ADMUX = (ADMUX & 0b11111000) + led;
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Habilita ADC e prescaler 128

  sei(); // Habilita interrupções globais

  while (1) {
    // Loop vazio - o trabalho é feito na ISR
  }
}
