#include "Demo.h"
#include"DxLib.h"
#include"System.h"

bool Demo::check_state()
{
	bool check = false;//デフォルトで未再生状態とする
	//再生中なら
	if (GetMovieStateToGraph(this->movie_handle) == 1){
		check = true;
	}
	//エラーが発生したら例外処理
	else if (GetMovieStateToGraph(this->movie_handle) == -1) throw "mp4 file is not found";
	return check;
}

void Demo::initialize()
{
	this->movie_handle = LoadGraph("./img/PV.mp4");
	PlayMovieToGraph(this->movie_handle);
}

void Demo::finalize()
{
	DeleteGraph(this->movie_handle);
}

void Demo::update()
{
	draw();
}

void Demo::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, this->movie_handle, FALSE);
}
