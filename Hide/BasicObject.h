#pragma once

//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject():
		x(0),
		y(0),
		graph(0)
	{}
	//メソッド（関数）
	void Draw();
	void Init();
private:
	//変数
	float x, y;//座標(ポジション)
	int graph;//画像へのパス
};