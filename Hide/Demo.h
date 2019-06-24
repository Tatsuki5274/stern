#pragma once

class Demo {
private:
	static int movie_handle;//映像を格納する

	static bool check_state();//再生状態を調べる(1 再生中,0 停止中 -1 エラー)
public:
	static void initialize();
	static void finalize();
	static void update();
	static void draw();
};