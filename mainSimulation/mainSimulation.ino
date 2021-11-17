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
int configuracao = MANUAL;   // configuracao padrao: MANUAL
int confManual = CONTINUO;   // configuracao manual padrao: sinal CONTINUO

int delayPulseOn = DEFAULT_DELAY;  // tempo em que o sinal pulsativo fica ligado (milisegundos)
int delayPulseOff = DEFAULT_DELAY; // tempo em que o sinal pulsativo fica desligado (milisegundos)

int tensao_V = 0; /*definição tensão no bus 0-1023 (int) */
double current_mA = 0; /*definição corrente */
int temperatura_C = 0; /*definição temperatura */

double pwmVal = 0;        // valor do PWM: 0-255

// Controle
double Setpoint, Input;
double Kp = DEFAULT_KP, Ki = DEFAULT_KI, Kd = DEFAULT_KD;

// UART
char configMsg[25]; // comando na entrada serial
int cont = 0;       // contador de bytes

PID myPID(&current_mA, &pwmVal, &Setpoint, Kp, Ki, Kd, DIRECT);

/**
   Setup
*/
void setup()
{
  // PWM
  pinMode(pwmPin, OUTPUT);
  pinMode(tensao_V, INPUT);
  pinMode(current_mA, INPUT);
  pinMode(temperatura_C, INPUT);

  Serial.begin(115200); /*inicia serial com baudrate de 115200 */
  while (!Serial)
  {
    delay(1);
  }

  // Timer, para mostrar dados no monitor
  initTimer1();

  Setpoint = DEFAULT_SETPOINT;        // usuario seta

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

/**
   Loop principal
*/
void loop()
{

  if (Serial.available() > 0) {    // is a character available?
    readSerialInput(Serial.read());    // le o caractere (ou mensagem) e muda as configuracoes
  }

  // leitura de tensao, corrente e temperatura
  tensao_V = analogRead(analogPin_Tensao);
  current_mA = analogRead(analogPin_Corrente);
  temperatura_C = analogRead(analogPin_Temperatra);

  switch (configuracao) {
    case MANUAL:
      controleManual();    // controle manual: continuo ou pulsativo
      break;
    case AUTO:
      controleAutomatico();  // controle automatico: variaveis de controle
      break;
    default:
      break;
  }
}

/**
   Rotina do TIMER1
*/
ISR(TIMER1_OVF_vect)
{
  TCNT1 = 0xC2F7;   // reinicia o timer
  printSerial();    // mostra a leitura das entradas e o valor do PWM no monitor Serial
}
