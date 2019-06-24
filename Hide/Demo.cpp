#include "Demo.h"
#include"DxLib.h"
#include"System.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include"Scene.h"
#include"Keyboard.h"
#include"Audio.h"

int Demo::movie_handle;

bool Demo::check_state()
{
	//�@�����O���Ԃ��Ă������~���A�P�Ȃ�Đ����ƂȂ�܂��B
	//	���݂ɓ���̍Đ����I�����邩 PauseMovieGraph �֐��ōĐ��� �|�[�Y���|����ƒ�~���ƂȂ�܂��B
	bool check = false;//�f�t�H���g�Ŗ��Đ���ԂƂ���
	//�Đ����Ȃ�
	if (GetMovieStateToGraph(movie_handle) == 1){
		check = true;
	}
	//�G���[�������������O����
	else if (GetMovieStateToGraph(movie_handle) == -1) throw "mp4 file is not found";
	return check;
}

void Demo::initialize()
{
	//�ǂݍ���
	movie_handle = LoadGraph("./movie/demo.mp4");
	PlayMovieToGraph(movie_handle);
}

void Demo::finalize()
{
	//�������폜
	DeleteGraph(movie_handle);
}

void Demo::update()
{
	//�Đ���
	if (check_state() == 1) {
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
		draw();
		if (Keyboard::key_down(KEY_INPUT_Q)) {
		
		}
	}
	//�Đ��I��
	else {
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			Scene::set_scene(SceneType::title);
			finalize();
		}
	}
}

void Demo::draw()
{
	//����Đ�
	DrawExtendGraph(0, 0, System::width, System::height, movie_handle, FALSE);
	//Push to Z key�ǉ��\��
}
