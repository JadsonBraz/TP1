/**
   Lê o que foi passado na porta serial

   Comandos de 1 byte:
    'a' - configuração automática
    'm' - configuração manual
      'c' - configuração continua
      'p' - configuração pulsativa

  Comandos com mais de 1 byte:
    '/pwm***_e' - configura pwm (0-254) na configuração manual continua
    '/pwm***_ton***_toff***_e' - configura pwm, tempo ligado e tempo desligado na configuração pulsativa

    '/p***_i***_d***_s****_e' - configura variaveis de controle: kp, ki, kd, setpoint, na configuração automática

*/

void readSerialInput (char msgByte)
{
  if (msgByte == 'm') {
    configuracao = MANUAL;
  } else if (msgByte == 'a') {
    configuracao = AUTO;
  } else if (msgByte == 'c' && configuracao == MANUAL) {
    confManual = CONTINUO;
  } else if (msgByte == 'p' && configuracao == MANUAL) {
    confManual = PULSATIVO;
  }

  // read many bytes
  //  '/' inicia a menagem e 'e' termina
  if (msgByte == '/' && configuracao == MANUAL) {
    while (msgByte != 'e') {
      msgByte = Serial.read();
      if (msgByte == -1 || msgByte == '/' || msgByte == 'e' ) continue;
      configMsg[cont] = msgByte;
      cont++;
    }
    cont = 0;

    // /pwm***_e
    pwmVal = ((configMsg[3] - '0') * 100 + (configMsg[4] - '0') * 10 + (configMsg[5] - '0')) * FRAC_PWM;
    if (pwmVal >= MAX_PWM) pwmVal = MAX_PWM;

    // /pwm***_ton***_toff***_e
    if (confManual == PULSATIVO) {
      delayPulseOn = (configMsg[10] - '0') * 100 + (configMsg[11] - '0') * 10 + (configMsg[12] - '0');
      delayPulseOff = (configMsg[18] - '0') * 100 + (configMsg[19] - '0') * 10 + (configMsg[20] - '0');
    }
  }

  else if (msgByte == '/' && configuracao == AUTO) {
    while (msgByte != 'e') {
      msgByte = Serial.read();
      if (msgByte == -1 || msgByte == '/' || msgByte == 'e' ) continue;
      configMsg[cont] = msgByte;
      cont++;
    }
    cont = 0;

    // /p***_i***_d***_s****_e
    Kp = ((configMsg[1] - '0') * 100 + (configMsg[2] - '0') * 10 + (configMsg[3] - '0')) / 10.0;
    Ki = ((configMsg[6] - '0') * 100 + (configMsg[7] - '0') * 10 + (configMsg[8] - '0')) / 10.0;
    Kd = ((configMsg[11] - '0') * 100 + (configMsg[12] - '0') * 10 + (configMsg[13] - '0')) / 10.0;

    Setpoint = ((configMsg[16] - '0') * 1000 + (configMsg[17] - '0') * 100 + (configMsg[18] - '0') * 10 + (configMsg[19] - '0'));

    if (Setpoint > 1023) Setpoint = 1023;

    // setar variaveis de controle:
    myPID.SetTunings(Kp, Ki, Kd);
  }
}
