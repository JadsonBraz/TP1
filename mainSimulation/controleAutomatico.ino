/**
   Controle automatico: utiliza variaveis de controle configuradas no supervisorio
*/
void controleAutomatico(void)
{
  Input = (double) current_mA;

  myPID.Compute();

  if (pwmVal > MAX_PWM) {
    pwmVal = MAX_PWM;
  }

  // escrever valor na saida
  analogWrite(pwmPin, (int) pwmVal);

  // escrever valor no holding register
  rg_holding[3] = pwmVal;
}
