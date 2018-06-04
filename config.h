
//#define RX     0
//#define TX     1

#define BLDC_A0     1
#define BLDC_B0     1
#define BLDC_C0     1

#define BLDC_A1     1
#define BLDC_B1     1
#define BLDC_C1     1

#define BLDC_A2     1
#define BLDC_B2     1
#define BLDC_C2     1

#define BAT   A0

#define SDA   A4
#define SCL   A5

//----------------------------------------
// PID configuration
#define PID_P                         0.1f
#define PID_I                         0.5f
#define PID_D                         0.0f
#define PID_HZ                       10.0f
#define PID_BITS                         8
#define PID_SIGNED                   false

#define BLDC_POWER                PWMRANGE
#define BLDC_CYCLES                      8

//----------------------------------------
enum {
  PITCH=0,
  ROLL,
  YAW,
  AXIS
};

//----------------------------------------
struct config_t {
  
  struct pid_t {
    float   P    = PID_P;
    float   I    = PID_I;
    float   D    = PID_D;
    float   Hz   = PID_HZ;
    uint8_t bits = PID_BITS;
    uint8_t sign = PID_SIGNED;
  } pid;
  
  struct bldc_t {
    uint16_t power  = BLDC_POWER;
    uint8_t  cycles = BLDC_CYCLES;
  } bldc[AXIS];
  
} config;

