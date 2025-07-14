# GP2Y0E03_sample
## 概要
[GP2Y0E03ライブラリ](https://github.com/ygdstmidn/GP2Y0E03)のサンプルプロジェクトです．\
[GP2Y0E03(秋月電子通商)](https://akizukidenshi.com/catalog/g/g107547/)

| 項目         | 仕様                                                             |
| ------------ | ---------------------------------------------------------------- |
| 使用マイコン | [NUCLEO_F446RE](https://os.mbed.com/platforms/ST-Nucleo-F446RE/) |
| 使用IDE      | CubeIDE,VSCode                                                   |
| 使用言語等   | C++,STM32CubeHAL                                                 |

## ピン設定
| ピン | 設定        | ラベル      | 備考           |
| ---- | ----------- | ----------- | -------------- |
| PA5  | GPIO_Output | DebugLED    | ラベルのみ変更 |
| PC13 | GPIO_EXTI13 | DebugButton | ラベルのみ変更 |

## クロック設定
| 項目 | 内容 | 備考 |
| ---- | ---- | ---- |
|      |      |      |

## 変更した設定
### Project Manager
Code Generator, Generated files\
✅Generate peripheral initialization as a pair of '.c/.h' files per peripheral

### I2C1
MODE: I2C
#### Parameter Settings
| 項目            | 設定      | 備考                        |
| --------------- | --------- | --------------------------- |
| I2C Speed Mode  | Fast Mode | Standard Modeじゃ無理だった |
| I2C Clock Speed | 400000Hz  | GP2Y0E03                    |

## プログラム概要
### setup()
Hello WorldとPCに送信
### loop()
now = HAL_GetTick()
#### 0.1秒ごとに
現在の経過時間をPCに送信\
ボタンが押されていた場合，LEDの点灯/消灯を切り替える
