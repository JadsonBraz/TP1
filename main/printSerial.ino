/**
   Medicoes do monitor serial
*/
void printSerial(void)
{
//  Serial.println("");
//  Serial.print("PWM (%): \t");
//  Serial.print(pwmPrintSerial);
//  Serial.print("\tTensao (V): \t");
//  Serial.print(busvoltage);      // teste
//  Serial.print("\tCorr. (mA): \t");
//  Serial.print(current_mA);     // teste
//  Serial.print("\tTemp. (°C): \t");
//  Serial.println(temp.cel());  // teste

  sprintf(mensagem, "/*pwm%03d_V%2.1f_A%2.1f_T%03d_/", pwmVal, busvoltage, current_mA, temp.cel());
  Serial.println(mensagem);
}
