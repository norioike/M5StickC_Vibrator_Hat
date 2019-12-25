# M5StickC Vibrator Hat　マニュアル

![gifDemo](https://user-images.githubusercontent.com/14104069/71437896-e01dfb80-2736-11ea-80e0-31f284552189.gif)

このReadMeではM5StickC用に開発したVibrator Hatの説明をさせていただきます。

ちなみにこのM5StickC用の Vibrator Hatですが、<br>
**rino prodouctsが開発、製造、頒布しているものであり、M5Stack社とは関係ありません。**<br>
ただ本製品を作るにあたり、M5Stack社から製造の許可は頂いております。

## What's Vibrator Hat?
M5StickCは色々なハットが販売されていますが、M5StickCが個人的にバイブレーションとの相性がいいデバイスだと思い、
このVibrator Hatの開発をしました。
Vibrator Hatは円盤型の振動モーターが内蔵されており、M5StickCの制御により、任意の強さで振動させることができます。

![製品写真](https://user-images.githubusercontent.com/14104069/71438011-4a36a080-2737-11ea-8691-4a0ddb229e8c.png)

また写真でわかるように、基板だけではありません！筐体もセットになっています。
筐体はナイロンの３Dプリントで製造しています。強度もしっかりしています。

このrino productsで開発したVibrator Hatを使って、面白いガジェットを作ってもらえればと思います。

## 使い方
写真の用にHatをM5StickCに接続します。向きを間違えても壊れることはありません。
![挿入時](https://user-images.githubusercontent.com/14104069/71437930-fd52ca00-2736-11ea-81b6-baa6bb67e05a.png)

## 使用しているピン
Vibrator Hatは**GPIO26番**を使用しています。
制御する際はGPIO26番を設定してください。
他のピンを設定して使っても、ピンが繋がっていないため、何も起こりません。
また電源はBATから取っています。5Vを使用していません。

![準備](https://user-images.githubusercontent.com/14104069/71437942-02b01480-2737-11ea-8d23-d39bd776c497.png)

## サンプルコード
このリポジトリではArduno IDEで開発をしたサンプルコードを提供しております。

・"M5"ボタンを押すと振動するシンプルなサンプル<br>PWM制御のサンプルにもなっているので、FastLEDライブラリが必要です。

・"M5"ボタンを押すとカウントダウンが始まり、０になると振動するキッチンタイマーサンプル

を提供しています。

## Licence
This software is released under the MIT License, see LICENSE.

## Authors
Norippy in rino products(https://www.rino-make-fun.com/)
