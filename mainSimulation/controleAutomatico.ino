/**
   Controle automatico: utiliza variaveis de controle configuradas no supervisorio
*/
void controleAutomatico(void)
{
  myPID.Compute();

  if (pwmVal > MAX_PWM) {
    pwmVal = MAX_PWM;
  }

  analogWrite(pwmPin, pwmVal);
}
