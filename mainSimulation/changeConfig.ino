void changeConfig (void)
{
  configuracao = rg_holding[10];    // muda configuracao global
  
  if (configuracao == CONTINUO) {
    pwmVal = rg_holding[3];         // valor do pwm
  }

  else if (configuracao == PULSATIVO) {
    pwmVal = rg_holding[3];
    delayPulseOn = rg_holding[4];   // valor do tempo em que o pwm fica ligado
    delayPulseOff = rg_holding[5];  // valor do tempo em que o pwm fica desligado
  }

  else if (configuracao == AUTO) {
    // ler variaveis de controle
    Kp = rg_holding[6] / 100.0;
    Kp = rg_holding[7] / 100.0;
    Kp = rg_holding[8] / 100.0;
    Setpoint = rg_holding[9];

    // aplicar novas variaveis de controle
    myPID.SetTunings(Kp, Ki, Kd);
  }
}
