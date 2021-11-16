/**
   Medicoes do monitor serial
*/
void printSerial(void)
{
  Serial.println("");
  Serial.print("PWM (%): \t");
  Serial.print(pwmVal * 100.0 / MAX_PWM);
  Serial.print("\tTensao (V): \t");
  Serial.print(busvoltage);      // teste
  Serial.print("\tCorr. (mA): \t");
  Serial.print(current_mA);     // teste
  Serial.print("\tTemp. (°C): \t");
  Serial.println(temp.cel());  // teste
}
