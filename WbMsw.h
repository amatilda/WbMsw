#ifndef WB_MSW_H
#define WB_MSW_H

#define WB_MSW_TIMEOUT 2000
#define WB_MSW_ON 255
#define WB_MSW_OFF 0

#ifdef ZUNO_CUSTOM_OTA_OFFSET
#define WB_MSW_UPDATE_ADDRESS (BOOTLOADER_STORAGE_AREA_START + ZUNO_CUSTOM_OTA_OFFSET)
#else
#define WB_MSW_UPDATE_ADDRESS (BOOTLOADER_STORAGE_AREA_START)
#endif

#define WB_MSW_INPUT_REG_AVAILABILITY_TIMEOUT_MS 10000 // ms

#define WB_MSW_INPUT_REG_TEMPERATURE_VALUE_ERROR 0x7FFF
#define WB_MSW_INPUT_REG_TEMPERATURE_VALUE_PRECISION SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS
#define WB_MSW_INPUT_REG_TEMPERATURE_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_TWO_BYTES

#define WB_MSW_INPUT_REG_HUMIDITY_VALUE_ERROR 0xFFFF
#define WB_MSW_INPUT_REG_HUMIDITY_VALUE_PRECISION SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS
#define WB_MSW_INPUT_REG_HUMIDITY_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_TWO_BYTES

#define WB_MSW_INPUT_REG_CO2_VALUE_ERROR 0xFFFF
#define WB_MSW_INPUT_REG_CO2_VALUE_PRECISION SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS
#define WB_MSW_INPUT_REG_CO2_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_TWO_BYTES

#define WB_MSW_INPUT_REG_VOC_VALUE_ERROR 0xFFFF
#define WB_MSW_INPUT_REG_VOC_VALUE_PRECISION SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS
#define WB_MSW_INPUT_REG_VOC_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_TWO_BYTES

#define WB_MSW_INPUT_REG_NOISE_LEVEL_PRECISION SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS
#define WB_MSW_INPUT_REG_NOISE_LEVEL_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_TWO_BYTES

#define WB_MSW_INPUT_REG_LUMEN_VALUE_ERROR 0xFFFFFFFF
#define WB_MSW_INPUT_REG_LUMEN_VALUE_PRECISION SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS
#define WB_MSW_INPUT_REG_LUMEN_VALUE_SIZE SENSOR_MULTILEVEL_SIZE_FOUR_BYTES

#define WB_MSW_INPUT_REG_MOTION_VALUE_ERROR 0xFFFF

typedef enum
{
    WB_MSW_CONFIG_PARAMETER_FIRST = 64,

    // Motion sensor settings
    WB_MSW_CONFIG_PARAMETER_MOTION_DELAY_SEND_OFF_COMMANDS = WB_MSW_CONFIG_PARAMETER_FIRST,
    WB_MSW_CONFIG_PARAMETER_MOTION_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_MOTION_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_MOTION_ON_OFF_COMMANDS_RULE,

    // Temperature channel settings
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_TEMPERATURE_ON_OFF_COMMANDS_RULE,

    // Humidity sensor settings
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_HUMIDITY_ON_OFF_COMMANDS_RULE,

    // Lumen sensor settings
    WB_MSW_CONFIG_PARAMETER_LUMEN_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_LUMEN_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_LUMEN_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_LUMEN_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_LUMEN_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_LUMEN_ON_OFF_COMMANDS_RULE,

    // CO2 sensor settings
    WB_MSW_CONFIG_PARAMETER_CO2_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_CO2_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_CO2_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_CO2_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_CO2_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_CO2_ON_OFF_COMMANDS_RULE,

    // VOC sensor settings
    WB_MSW_CONFIG_PARAMETER_VOC_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_VOC_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_VOC_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_VOC_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_VOC_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_VOC_ON_OFF_COMMANDS_RULE,

    // Noise level sensor settings
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_LEVEL_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_HYSTERESIS_SEND_BASIC,
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_ON_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_OFF_COMMANDS,
    WB_MSW_CONFIG_PARAMETER_NOISE_LEVEL_ON_OFF_COMMANDS_RULE,

    // Intrusion sensor settings
    WB_MSW_CONFIG_PARAMETER_INTRUSION_REPORT_THRESHOLD,
    WB_MSW_CONFIG_PARAMETER_INTRUSION_DELAY_SEND_OFF_COMMANDS,

    WB_MSW_CONFIG_PARAMETER_LAST
} WbMswConfigParameter;

#define WB_MSW_MAX_CONFIG_PARAM ((WB_MSW_CONFIG_PARAMETER_LAST - WB_MSW_CONFIG_PARAMETER_FIRST) + 1)

#define WB_MSW_UART_BAUD 9600
#define WB_MSW_UART_MODE SERIAL_8N2
#define WB_MSW_UART_RX 8 // Z-Uno receiver pin
#define WB_MSW_UART_TX 7 // Z-uno transmitter pin

#define WB_MSW_UART_BOOTLOADER_BAUD 9600
#define WB_MSW_UART_BOOTLOADER_MODE SERIAL_8N2

typedef enum WbMswLedMode_s
{
    WB_MSW_LED_MODE_IDLE = 0x0,
    WB_MSW_LED_MODE_LERN = 0x2,
    WB_MSW_LED_MODE_GREEN = 0x4,
    WB_MSW_LED_MODE_RED = 0x8,
    WB_MSW_LED_MODE_RED_GREEN = (WB_MSW_LED_MODE_GREEN | WB_MSW_LED_MODE_RED),
    WB_MSW_LED_MODE_DUO = 0x10,
} WbMswLedMode_t;

#endif // WB_MSW_H
