/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2023 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AUDIO_BOARD_DEFINITION_H_
#define _AUDIO_BOARD_DEFINITION_H_

/**
 * @brief LCD SCREEN Function Definition
 */
#define FUNC_LCD_SCREEN_EN          (1)
#define LCD_CTRL_GPIO               GPIO_NUM_47
#define LCD_RST_GPIO                GPIO_NUM_48
#define LCD_DC_GPIO                 GPIO_NUM_13
#define LCD_CS_GPIO                 GPIO_NUM_12
#define LCD_CLK_GPIO                GPIO_NUM_11
#define LCD_MOSI_GPIO               GPIO_NUM_4
// The LCD pixel number in horizontal and vertical
#define LCD_H_RES                   (368)
#define LCD_V_RES                   (448)
#define LCD_SWAP_XY                 (false)
#define LCD_MIRROR_X                (true)
#define LCD_MIRROR_Y                (true)
#define LCD_COLOR_INV               (false)
#define LCD_COLOR_SPACE             ESP_LCD_COLOR_SPACE_BGR

/**
 * @brief SDCARD Function Definition
 */
#define FUNC_SDCARD_EN              (1)
#define SDCARD_OPEN_FILE_NUM_MAX    (5)
#define SDCARD_INTR_GPIO            (-1)
#define SDCARD_PWR_CTRL             (-1)
#define ESP_SD_PIN_CLK              GPIO_NUM_2
#define ESP_SD_PIN_CMD              GPIO_NUM_1
#define ESP_SD_PIN_D0               GPIO_NUM_3
#define ESP_SD_PIN_D1               (-1)
#define ESP_SD_PIN_D2               (-1)
#define ESP_SD_PIN_D3               (-1)
#define ESP_SD_PIN_D4               (-1)
#define ESP_SD_PIN_D5               (-1)
#define ESP_SD_PIN_D6               (-1)
#define ESP_SD_PIN_D7               (-1)
#define ESP_SD_PIN_CD               (-1)
#define ESP_SD_PIN_WP               (-1)

/**
 * @brief LCD TOUCH PANEL Function Definition
 */
#define FUNC_LCD_TOUCH_EN          (1)
#define TOUCH_PANEL_SWAP_XY        (0)
#define TOUCH_PANEL_INVERSE_X      (1)
#define TOUCH_PANEL_INVERSE_Y      (0)

/**
 * @brief  Audio Codec Chip Function Definition
 */
#define FUNC_AUDIO_CODEC_EN       (1)
#define CODEC_ADC_I2S_PORT        ((i2s_port_t)0)
#define CODEC_ADC_BITS_PER_SAMPLE ((i2s_data_bit_width_t)32)  /* 32bit */
#define CODEC_ADC_SAMPLE_RATE     (48000)
#define RECORD_HARDWARE_AEC       (true)
#define BOARD_PA_GAIN             (0)  /* Power amplifier gain defined by board (dB) */
#define PA_ENABLE_GPIO            GPIO_NUM_46
#define HEADPHONE_DETECT          (-1)
#define ES7210_MIC_SELECT         (ES7210_INPUT_MIC1 | ES7210_INPUT_MIC2 | ES7210_INPUT_MIC3)

extern audio_hal_func_t AUDIO_CODEC_ES8311_DEFAULT_HANDLE;
#define AUDIO_CODEC_DEFAULT_CONFIG(){                   \
        .adc_input  = AUDIO_HAL_ADC_INPUT_LINE1,        \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_ALL,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_BOTH,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_SLAVE,               \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_48K_SAMPLES,           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};

/**
 * @brief Button Function Definition
 */
#define FUNC_BUTTON_EN              (1)
#define INPUT_KEY_NUM               (2)
#define BUTTON_VOLUP_ID             (-1)
#define BUTTON_VOLDOWN_ID           (-1)
#define BUTTON_SET_ID               (-1)
#define BUTTON_PLAY_ID              (0)
#define BUTTON_MODE_ID              (-1)
#define BUTTON_REC_ID               (1)

#define INPUT_KEY_DEFAULT_INFO() {                     \
    {                                                  \
        .type = PERIPH_ID_BUTTON,                      \
        .user_id = INPUT_KEY_USER_ID_REC,              \
        .act_id = BUTTON_REC_ID,                       \
    },                                                 \
    {                                                  \
        .type = PERIPH_ID_BUTTON,                      \
        .user_id = INPUT_KEY_USER_ID_PLAY,             \
        .act_id = BUTTON_PLAY_ID,                      \
    }                                                  \
}
#endif
