/**
   Controle automatico: utiliza variaveis de controle configuradas no supervisorio
*/
void controleAutomatico(void)
{
  Input = current_mA;

  myPID.Compute();

  if(pwmVal > 255) {
    pwmVal = 255;
  }
  
  analogWrite(pwmPin, pwmVal);
}
