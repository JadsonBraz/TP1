// configuracoes: manual ou automatica
#define MANUAL 0
#define AUTO   1

// a configuracao manual possui duas outras opcoes: saida continua ou plsativa
#define CONTINUO  0
#define PULSATIVO 1

// valores do pwm
#define MAX_PWM   255     // maior valor na saida do PWM  (8bits)
#define MIN_PWM   0         // menor valor na saida do PWM
#define FRAC_PWM  2.55      // valor de 1% no PWM
#define INC_DEC_PWM 25.5    // valor de incremento/decremento do PWM

// delay padrao da configuracao manual pulsativa (segundos)
#define DEFAULT_DELAY   1

// 1 segundo = 1000 milisegundos
#define SEGUNDO 1000
