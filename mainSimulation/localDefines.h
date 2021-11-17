// configuracoes: manual ou automatica
#define MANUAL 0
#define AUTO   1

// a configuracao manual possui duas outras opcoes: saida continua ou plsativa
#define CONTINUO  0
#define PULSATIVO 1

// valores do pwm
#define MAX_PWM   254     // maior valor na saida do PWM  (8bits)
#define MIN_PWM   0         // menor valor na saida do PWM
#define FRAC_PWM  2.55      // valor de 1% no PWM

// PID
#define DEFAULT_SETPOINT  500.0     // 0-1023
#define DEFAULT_KP        1.0
#define DEFAULT_KI        0.2
#define DEFAULT_KD        1.0

// delay padrao da configuracao manual pulsativa (segundos)
#define DEFAULT_DELAY   1

// 1 segundo = 1000 milisegundos
#define SEGUNDO 1000
