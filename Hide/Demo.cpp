#include "Demo.h"
#include"DxLib.h"
#include"System.h"

bool Demo::check_state()
{
	bool check = false;//�f�t�H���g�Ŗ��Đ���ԂƂ���
	//�Đ����Ȃ�
	if (GetMovieStateToGraph(this->movie_handle) == 1){
		check = true;
	}
	//�G���[�������������O����
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
