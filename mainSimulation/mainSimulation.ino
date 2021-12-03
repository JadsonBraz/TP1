/**
    Codigo principal
*/

#include <PID_v1.h>
#include <stdio.h>

#include "localDefines.h"

int pwmPin = 3;       // pino do PWM

int analogPin_Tensao = A0;    // leitura de tensao
int analogPin_Corrente = A3;  // leitura de corrente
int analogPin_Temperatra = A5;// leitura de temperatura

// configurar variaveis globais
int configuracao = CONTINUO;   // configuracao padrao: MANUAL CONTINUO

long delayPulseOn = DEFAULT_DELAY;  // tempo em que o sinal pulsativo fica ligado (milisegundos)
long delayPulseOff = DEFAULT_DELAY; // tempo em que o sinal pulsativo fica desligado (milisegundos)
long contOn = 0;                   // contador de tempo ligado
long contOff = 0;                  // contador de tempo desligado

int tensao_V = 0; /*definição tensão no bus 0-1023 (int) */
int current_mA = 0; /*definição corrente */
int temperatura_C = 0; /*definição temperatura */

double pwmVal = 0;        // valor do PWM: 0-255

// Controle
double Setpoint, Input;
double Kp = DEFAULT_KP / 100.0, Ki = DEFAULT_KI / 100.0, Kd = DEFAULT_KD / 100.0;

PID myPID(&Input, &pwmVal, &Setpoint, Kp, Ki, Kd, DIRECT);

extern uint16_t rg_holding[REG_SIZE];

/**
   Setup
*/
void setup()
{
  // config Pins
  pinMode(pwmPin, OUTPUT);
  pinMode(tensao_V, INPUT);
  pinMode(current_mA, INPUT);
  pinMode(temperatura_C, INPUT);

  /*inicia serial com baudrate de 9600 */
  modbus_init(9600, RE_DE, SLAVE_ADDRS);

  // configure holdings
  setupInitialValuesOfModbusRegisters();

  // Timer, para mostrar dados no monitor
  initTimer1();

  Setpoint = DEFAULT_SETPOINT;        // usuario tambem pode mudar
  Input = (double) current_mA;        // leitura da corrente

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

/**
   Loop principal
*/
void loop()
{
  modbus_check();   // espera recebimento de pacotes

  // leitura de tensao, corrente e temperatura; atualizando holding registers
  readData();

  // mudar configuracoes caso holdig registers tenham sido modificados
  changeConfig();

  switch (configuracao) {
    case CONTINUO:
      controleManualContinuo();    // controle manual: continuo ou pulsativo(timer)
      break;
    case AUTO:
      controleAutomatico();  // controle automatico: variaveis de controle
      break;
    default:
      break;
  }
}
