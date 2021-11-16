/**
   Lê o que foi passado na porta serial
*/

void readSerialInput (char msg)
{
  // pwm(%), tempo ligado e desligado (segundos, na conf. pulsativa)
  //  '/' inicia a menagem e 'e' termina
  char configMsg[22];     //  /pwm100_ton001_toff001_e
  int cont = 0;

  if (msg == 'm') {
    configuracao = MANUAL;
  } else if (msg == 'a') {
    configuracao = AUTO;
  } else if (msg == 'c' && configuracao == MANUAL) {
    confManual = CONTINUO;
  } else if (msg == 'p' && configuracao == MANUAL) {
    confManual = PULSATIVO;
  }

  // read many bytes
  if (msg == '/') {
    while (msg != 'e') {
      msg = Serial.read();
      if (msg == -1 || msg == '/' || msg == 'e' ) continue;
      configMsg[cont] = msg;
      cont++;
    }
    cont = 0;

    pwmVal = ((configMsg[3] - '0') * 100 + (configMsg[4] - '0') * 10 + (configMsg[5] - '0')) * FRAC_PWM;
    if (pwmVal > MAX_PWM) pwmVal = MAX_PWM;
    if (pwmVal < MIN_PWM) pwmVal = MIN_PWM;

    if (confManual == PULSATIVO) {
      delayPulseOn = (configMsg[10] - '0') * 100 + (configMsg[11] - '0') * 10 + (configMsg[12] - '0');
      delayPulseOff = (configMsg[18] - '0') * 100 + (configMsg[19] - '0') * 10 + (configMsg[20] - '0');
    }

    // setar variaveis de controle:
    // myPID.SetTunings(consKp, consKi, consKd);
  }
}
