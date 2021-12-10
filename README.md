# m5atom-envII-raspi

M5AtomとenvII、ラズパイで環境を記録するシステム

# 役割
envII：センサ。環境情報を取得する。
M5Atom：envIIからのデータを取得して、ラズパイにシリアルで送る。
ラズパイ：pyserialでデータを取得して、どっかのDB（未決）に蓄積する。

