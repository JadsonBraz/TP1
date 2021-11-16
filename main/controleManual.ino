/**
   Controle manual: continuo ou pulsativo
*/
void controleManual(void)
{
  switch (confManual) {
    case CONTINUO:
      analogWrite(pwmPin, pwmVal);

      break;

    case PULSATIVO:
      analogWrite(pwmPin, MIN_PWM);
      delay(delayPulseOff * SEGUNDO);
      analogWrite(pwmPin, pwmVal);
      delay(delayPulseOn * SEGUNDO);

      break;

    default:
      break;
  }
}
