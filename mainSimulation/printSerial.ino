/**
   Medicoes do monitor serial
*/
void printSerial(void)
{
  if (configuracao == MANUAL) {
    Serial.print("/*V");
    Serial.print(tensao_V);
    Serial.print("_A");
    Serial.print(current_mA, 0);
    Serial.print("_T");
    Serial.print(temperatura_C);
    Serial.print("_PWM");
    Serial.print(pwmVal, 0);
    Serial.println("/");

    /*      Serial.print("Tensao: ");
          Serial.print(tensao_V);
          Serial.print("\tCorrente: ");
          Serial.print(current_mA, 0);
          Serial.print("\t\tTemperatura: ");
          Serial.print(temperatura_C);
          Serial.print("\tPWM: ");
          Serial.print(pwmVal * 100 / 255.0);
          Serial.println("%");      */

  } else if (configuracao == AUTO) {
    Serial.print("/*V");
    Serial.print(tensao_V);
    Serial.print("_A");
    Serial.print(current_mA, 0);
    Serial.print("_T");
    Serial.print(temperatura_C);
    Serial.print("_PWM");
    Serial.print(pwmVal, 0);
    Serial.print("_kp");
    Serial.print(Kp, 1);
    Serial.print("_ki");
    Serial.print(Ki, 1);
    Serial.print("_kd");
    Serial.print(Kd, 1);
    Serial.println("/");

    //      Serial.print("Corrente: ");
    //      Serial.print(current_mA);
    //      Serial.print("\tPWM: ");
    //      Serial.print(pwmVal * 100 / 255.0);
    //      Serial.print("% \tKp: ");
    //      Serial.print(Kp, 1);
    //      Serial.print("\tKi: ");
    //      Serial.print(Ki, 1);
    //      Serial.print("\tKd: ");
    //      Serial.print(Kd, 1);
    //      Serial.print("\tSetpoint: ");
    //      Serial.println(Setpoint);
  }
}
