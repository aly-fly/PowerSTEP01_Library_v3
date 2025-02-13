#ifndef _dspin_constants_h_
#define _dspin_constants_h_

// Constant definitions provided by ST

// STEP_MODE option values.
// First comes the "microsteps per step" options...
#define STEP_MODE_STEP_SEL 0x07  // Mask for these bits only.
#define STEP_SEL_1     0x00
#define STEP_SEL_1_2   0x01
#define STEP_SEL_1_4   0x02
#define STEP_SEL_1_8   0x03
#define STEP_SEL_1_16  0x04
#define STEP_SEL_1_32  0x05
#define STEP_SEL_1_64  0x06
#define STEP_SEL_1_128 0x07

// ...next, define the SYNC_EN bit. When set, the BUSYN pin will instead
//  output a clock related to the full-step frequency as defined by the
//  SYNC_SEL bits below.
#define STEP_MODE_SYNC_EN	 0x80  // Mask for this bit
#define SYNC_EN 0x80

// ...last, define the SYNC_SEL modes. The clock output is defined by
//  the full-step frequency and the value in these bits- see the datasheet
//  for a matrix describing that relationship (page 46).
#define STEP_MODE_SYNC_SEL 0x70
#define SYNC_SEL_1_2 0x00
#define SYNC_SEL_1   0x10
#define SYNC_SEL_2   0x20
#define SYNC_SEL_4   0x30
#define SYNC_SEL_8   0x40
#define SYNC_SEL_16  0x50
#define SYNC_SEL_32  0x60
#define SYNC_SEL_64  0x70

// CM_VM bit
#define STEP_MODE_CM_VM 0x08
#define VOLTAGE_MODE 0x00
#define CURRENT_MODE 0x01

// Bit names for the ALARM_EN register.
//  Each of these bits defines one potential alarm condition.
//  When one of these conditions occurs and the respective bit in ALARM_EN is set,
//  the FLAG pin will go low. The register must be queried to determine which event
//  caused the alarm.
#define ALARM_EN_OVERCURRENT       0x01
#define ALARM_EN_THERMAL_SHUTDOWN	 0x02
#define ALARM_EN_THERMAL_WARNING   0x04
#define ALARM_EN_UNDER_VOLTAGE     0x08
#define ALARM_EN_ADC_UVLO          0x10
#define ALARM_EN_STALL_DETECT      0x20
#define ALARM_EN_SW_TURN_ON        0x40
#define ALARM_EN_CMD_ERROR         0x80

// CONFIG register renames.

// Oscillator options.
// The dSPIN needs to know what the clock frequency is because it uses that for some
//  calculations during operation.
#define CONFIG_OSC_SEL                 0x000F // Mask for this bit field.
#define CONFIG_INT_16MHZ               0x0000 // Internal 16MHz, no output
#define CONFIG_INT_16MHZ_OSCOUT_2MHZ   0x0008 // Default; internal 16MHz, 2MHz output
#define CONFIG_INT_16MHZ_OSCOUT_4MHZ   0x0009 // Internal 16MHz, 4MHz output
#define CONFIG_INT_16MHZ_OSCOUT_8MHZ   0x000A // Internal 16MHz, 8MHz output
#define CONFIG_INT_16MHZ_OSCOUT_16MHZ  0x000B // Internal 16MHz, 16MHz output
#define CONFIG_EXT_8MHZ_XTAL_DRIVE     0x0004 // External 8MHz crystal
#define CONFIG_EXT_16MHZ_XTAL_DRIVE    0x0005 // External 16MHz crystal
#define CONFIG_EXT_24MHZ_XTAL_DRIVE    0x0006 // External 24MHz crystal
#define CONFIG_EXT_32MHZ_XTAL_DRIVE    0x0007 // External 32MHz crystal
#define CONFIG_EXT_8MHZ_OSCOUT_INVERT  0x000C // External 8MHz crystal, output inverted
#define CONFIG_EXT_16MHZ_OSCOUT_INVERT 0x000D // External 16MHz crystal, output inverted
#define CONFIG_EXT_24MHZ_OSCOUT_INVERT 0x000E // External 24MHz crystal, output inverted
#define CONFIG_EXT_32MHZ_OSCOUT_INVERT 0x000F // External 32MHz crystal, output inverted

// Configure the functionality of the external switch input
#define CONFIG_SW_MODE                 0x0010 // Mask for this bit.
#define CONFIG_SW_HARD_STOP            0x0000 // Default; hard stop motor on switch.
#define CONFIG_SW_USER                 0x0010 // Tie to the GoUntil and ReleaseSW
                                                    //  commands to provide jog function.
                                                    //  See page 25 of datasheet.

// Configure the motor voltage compensation mode (see page 34 of datasheet)
#define CONFIG_EN_VSCOMP               0x0020  // Mask for this bit.
#define CONFIG_VS_COMP_DISABLE         0x0000  // Disable motor voltage compensation.
#define CONFIG_VS_COMP_ENABLE          0x0020  // Enable motor voltage compensation.

// Configure overcurrent detection event handling
#define CONFIG_OC_SD                   0x0080  // Mask for this bit.
#define CONFIG_OC_SD_DISABLE           0x0000  // Bridges do NOT shutdown on OC detect
#define CONFIG_OC_SD_ENABLE            0x0080  // Bridges shutdown on OC detect

// Configure the UVLO protection thresholds
#define CONFIG_UVLOVAL                 0x0100 // Mask for this bit.
#define CONFIG_UVLOVAL_LOW             0x0000 // V_ccth 6.9V-6.3V, DV_BOOTTh 6V-5.5V
#define CONFIG_UVLOVAL_HIGH            0x0100 // V_ccth 10.4V-10, DV_BOOTTh 9.2V-8.8V

// Configure the Vcc voltage regulator output
#define CONFIG_VCCVAL                  0x0200 // Mask for this bit.
#define CONFIG_VCCVAL_7_5V             0x0000 // 7.5V Vcc output
#define CONFIG_VCCVAL_15V              0x0200 // 15V Vcc output

// Integer divisors for PWM sinewave generation
//  See page 32 of the datasheet for more information on this.
#define CONFIG_F_PWM_DEC               0x1C00      // mask for this bit field
#define CONFIG_PWM_MUL_0_625           (0x00)<<10
#define CONFIG_PWM_MUL_0_75            (0x01)<<10
#define CONFIG_PWM_MUL_0_875           (0x02)<<10
#define CONFIG_PWM_MUL_1               (0x03)<<10
#define CONFIG_PWM_MUL_1_25            (0x04)<<10
#define CONFIG_PWM_MUL_1_5             (0x05)<<10
#define CONFIG_PWM_MUL_1_75            (0x06)<<10
#define CONFIG_PWM_MUL_2               (0x07)<<10

// Multiplier for the PWM sinewave frequency
#define CONFIG_F_PWM_INT               0xE000     // mask for this bit field.
#define CONFIG_PWM_DIV_1               (0x00)<<13
#define CONFIG_PWM_DIV_2               (0x01)<<13
#define CONFIG_PWM_DIV_3               (0x02)<<13
#define CONFIG_PWM_DIV_4               (0x03)<<13
#define CONFIG_PWM_DIV_5               (0x04)<<13
#define CONFIG_PWM_DIV_6               (0x05)<<13
#define CONFIG_PWM_DIV_7               (0x06)<<13

// The predictive current control method is enable or not
#define CONFIG_PRED                    0x8000     // mask for this bit field.
#define CONFIG_PRED_DISABLE            0x0000
#define CONFIG_PRED_ENABLE             0x8000

//The target switching period of the current control algorithm
#define CONFIG_TSW                     0x7C00     // mask for this bit field.

// Status register bit renames- read-only bits conferring information about the
//  device to the user.
#define STATUS_HIZ                     0x0001 // high when bridges are in HiZ mode
#define STATUS_nBUSY                   0x0002 // mirrors BUSY pin
#define STATUS_SW_CLOS                 0x0004 // low when switch open, high when closed
#define STATUS_SW_EVNT                 0x0008 // active high, set on switch falling edge,
                                                    //  cleared by reading REG_STATUS
#define STATUS_DIR                     0x0010 // Indicates current motor direction.
                                                    //  High is FWD, Low is REV.
#define STATUS_CMD_ERROR               0x0080 // Last command not performed or valid.
#define STATUS_STCK_MOD                0x0100 // Step clock mode is active
#define STATUS_nUVLO                   0x0200 // Undervoltage lockout is active
#define STATUS_nUVLO_ADC               0x0400 // ADC Undervoltage event is active

#define STATUS_nOCD                     0x2000 // Overcurrent detected
#define STATUS_nSTALL_B                 0x4000 // Stall detected on B bridge
#define STATUS_nSTALL_A                 0x8000 // Stall detected on A bridge

// Status register thermal status field
#define STATUS_TH_STATUS               0x1800 // field mask
#define STATUS_TH_NORMAL              (0x0000)<<11  // Thermal normal
#define STATUS_TH_WARNING             (0x0001)<<11  // Thermal warning
#define STATUS_TH_BRIDGE_SHUTDOWN     (0x0002)<<11  // Thermal bridges shutdown
#define STATUS_TH_DEVICE_SHUTDOWN     (0x0003)<<11  // Thermal device shutdown

// Status register motor status field
#define STATUS_MOT_STATUS                0x0060      // field mask
#define STATUS_MOT_STATUS_STOPPED       (0x0000)<<5 // Motor stopped
#define STATUS_MOT_STATUS_ACCELERATION  (0x0001)<<5 // Motor accelerating
#define STATUS_MOT_STATUS_DECELERATION  (0x0002)<<5 // Motor decelerating
#define STATUS_MOT_STATUS_CONST_SPD     (0x0003)<<5 // Motor at constant speed

// Register address redefines.
//  See the Param_Handler() function for more info about these.
#define ABS_POS              0x01
#define EL_POS               0x02
#define MARK                 0x03
#define SPEED                0x04
#define ACC                  0x05
#define DECEL                0x06
#define MAX_SPEED            0x07
#define MIN_SPEED            0x08
#define FS_SPD               0x15
#define KVAL_HOLD            0x09
#define KVAL_RUN             0x0A
#define KVAL_ACC             0x0B
#define KVAL_DEC             0x0C
#define INT_SPD              0x0D
#define ST_SLP               0x0E
#define FN_SLP_ACC           0x0F
#define FN_SLP_DEC           0x10
#define K_THERM              0x11
#define ADC_OUT              0x12
#define OCD_TH               0x13
#define STALL_TH             0x14
#define STEP_MODE            0x16
#define ALARM_EN             0x17
#define GATECFG1             0x18
#define GATECFG2             0x19
#define CONFIG               0x1A
#define REG_STATUS           0x1B
// Current mode configuration
#define TVAL_HOLD            0x09
#define TVAL_RUN             0x0A
#define TVAL_ACC             0x0B
#define TVAL_DEC             0x0C
#define T_FAST               0x0E
#define TON_MIN              0x0F
#define TOFF_MIN             0x10

//dSPIN commands
#define NOP_CMD              0x00
#define SET_PARAM            0x00
#define GET_PARAM            0x20
#define RUN                  0x50
#define STEP_CLOCK           0x58
#define MOVE                 0x40
#define GOTO                 0x60
#define GOTO_DIR             0x68
#define GO_UNTIL             0x82
#define RELEASE_SW           0x92
#define GO_HOME              0x70
#define GO_MARK              0x78
#define RESET_POS            0xD8
#define RESET_DEVICE         0xC0
#define SOFT_STOP            0xB0
#define HARD_STOP            0xB8
#define SOFT_HIZ             0xA0
#define HARD_HIZ             0xA8
#define CMD_GET_STATUS       0xD0

#endif

