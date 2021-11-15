/**
   configuracao inicial do TIMER 1

*/

void initTimer1(void)
{
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1 << CS10) | (1 << CS12); // configura prescaler para 1024: CS12 = 1 e CS10 = 1
  TCNT1 = 0xC2F7;     // incia timer com valor para que estouro ocorra em 1 segundo   (16 bits)
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
}
