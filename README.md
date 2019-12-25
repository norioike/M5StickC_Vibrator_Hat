# M5StickC Vibrator Hat　マニュアル
このReadMeではM5StickC用に開発したVibrator Hatの説明をさせていただきます。

ちなみにこのM5StickC用の Vibrator Hatですが、<br>
**rino prodouctsが開発、製造、頒布しているものであり、M5Stack社とは関係ありません。**<br>
ただ本製品を作るにあたり、M5Stack社から製造の許可は頂いております。

## What's Vibrator Hat?
M5StickCは色々なハットが販売されていますが、M5StickCが個人的にバイブレーションとの相性がいいデバイスだと思い、
このVibrator Hatの開発をしました。
Vibrator Hatは円盤型の振動モーターが内蔵されており、M5StickCの制御により、任意の強さで振動させることができます。

Vibrator Hatを使って、面白いガジェットを作ってもらえればと思います。

## 使い方
写真の用にHatをM5StickCに接続します。

## 使用しているGPIO
Vibrator Hatは**GPIO26番**を使用しています。
制御する際はGPIO26番を設定してください。

## サンプルコード
このリポジトリではArduno IDEで開発をしたサンプルコードを提供しております。

・ボタンを押すと振動するシンプルなサンプル

・ボタンを押すとカウントダウンが始まり、０になると振動するキッチンタイマーサンプル

を提供しています。

## Licence
This software is released under the MIT License, see LICENSE.

## Authors
Norippy in rino products(https://www.rino-make-fun.com/)
