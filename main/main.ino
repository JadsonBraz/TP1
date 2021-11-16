/**
    Codigo principal
*/

#include <LM35.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <PID_v1.h>
#include "localDefines.h"

int pwmPin = 3;       // pino do PWM

//int analogPin_Tensao = A5;    // leitura de tensao/
//int analogPin_Corrente = A3;  // leitura de corrente
LM35 temp(A5);  // leitura de temperatura, pino A5

// configurar variaveis globais
int configuracao = MANUAL;    // configuracao padrao: MANUAL
int confManual = CONTINUO;   // configuracao manual padrao: sinal CONTINUO

int delayPulseOn = DEFAULT_DELAY;  // tempo em que o sinal pulsativo fica ligado (milisegundos)
int delayPulseOff = DEFAULT_DELAY; // tempo em que o sinal pulsativo fica desligado (milisegundos)

float busvoltage = 0; /*definição tensão no bus */
float current_mA = 0; /*definição corrente */

double pwmVal = 0;        // valor do PWM: 0-255
char msg;     // variavel que guarda o byte digitado na entrada serial

// Controle
double Setpoint, Input;
double Kp=100, Ki=0.2, Kd=1;

PID myPID(&Input, &pwmVal, &Setpoint, Kp, Ki, Kd, DIRECT);

Adafruit_INA219 ina219;

/**
   Setup
*/
void setup()
{
  // PWM
  pinMode(pwmPin, OUTPUT);

  // Serial
  //  Serial.begin(9600);

  Serial.begin(115200); /*inicia serial com baudrate de 115200 */
  while (!Serial)
  {
    delay(1);
  }

  //if (! ina219.begin())
  //{
    Serial.println("Falha ao encontrar o INA219");
//    while (1) {
//      delay(10);
//    }
  //}

  // Timer, para mostrar dados no monitor
  initTimer1();

  Input = current_mA;
  Setpoint = 10;        // usuario seta

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

  busvoltage = ina219.getBusVoltage_V(); /* comando para chamar a tensão em bus */
  current_mA = ina219.getCurrent_mA(); /* comando para chamar a corrente */

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
