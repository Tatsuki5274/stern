#pragma once

class Demo {
private:
	int movie_handle;//映像を格納する

	bool check_state();//再生状態を調べる(1 再生中,0 停止中 -1 エラー)
public:
	void initialize();
	void finalize();
	void update();
	void draw();
};