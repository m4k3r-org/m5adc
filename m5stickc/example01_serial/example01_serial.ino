/*******************************************************************************
Example 01: ADC Input Voltage Monitor for M5StickC
・A/Dコンバータの読み値をシリアル・モニタへ表示します

                                          Copyright (c) 2019-2020 Wataru KUNINO
********************************************************************************
【参考文献】
Arduino IDE 開発環境イントール方法：
https://github.com/m5stack/M5Stack/blob/master/docs/getting_started_ja.md
https://docs.m5stack.com/#/en/related_documents/Arduino_IDE

M5Stack Arduino Library API 情報：
https://docs.m5stack.com/#/ja/api
https://docs.m5stack.com/#/en/arduino/arduino_api
*******************************************************************************/

#include <M5StickC.h>                           // M5StickC用ライブラリ
#define ADC_PIN 36                              // HAT部の GPIO 36 ピン(ADC1_0)

void setup(){                                   // 起動時に一度だけ実行する関数
    M5.begin();                                 // M5StickC用ライブラリの起動
    pinMode(ADC_PIN, ANALOG);                   // HAT部のGPIO36をアナログ入力に
}

void loop(){                                    // 繰り返し実行する関数
    int adc, mv;                                // 変数adcとmvを定義
    adc = analogRead(ADC_PIN);                  // ADC値をadcへ代入
    mv = adc * 3300 / 4095;                     // ADC値を電圧に変換してmvへ代入
    Serial.printf("adc=%d, mv=%d\n", adc, mv);  // ADC値と電圧値mvをシリアル出力
    delay(500);                                 // 0.5秒（500ms）の待ち時間処理
}
