// configuracoes: manual ou automatica
#define AUTO   1

// a configuracao manual possui duas outras opcoes: saida continua ou plsativa
#define CONTINUO  3
#define PULSATIVO 4

// valores do pwm
#define MAX_PWM   254     // maior valor na saida do PWM  (8bits)
#define MIN_PWM   0         // menor valor na saida do PWM
#define FRAC_PWM  2.55      // valor de 1% no PWM

// PID
#define DEFAULT_SETPOINT  500.0     // 0-1023
#define DEFAULT_KP        50.0
#define DEFAULT_KI        20.0
#define DEFAULT_KD        100.0

// delay padrao da configuracao manual pulsativa (segundos)
#define DEFAULT_DELAY   1

// 1 segundo = 1000 milisegundos
#define SEGUNDO 1000

// Modbus slave
#define RE_DE 8
#define SLAVE_ADDRS 1
#define REG_SIZE 11
