/**
   Controle manual: continuo ou pulsativo
*/
void controleManualContinuo(void)
{
  analogWrite(pwmPin, pwmVal);
}

/**
   Rotina do TIMER1 utilizada para configuracao manual pulsativa
*/
ISR(TIMER1_OVF_vect)
{
  TCNT1 = 0xC2F7;   // reinicia o timer

  if (configuracao == PULSATIVO) {
    contOn++;
    if (contOn >= delayPulseOn) {
      analogWrite(pwmPin, MIN_PWM);
      contOff++;
      if (contOff > delayPulseOff) {
        analogWrite(pwmPin, pwmVal);
        contOff = 0;
        contOn = 0;
      }
    } else {
      analogWrite(pwmPin, pwmVal);
    }
  }
}
