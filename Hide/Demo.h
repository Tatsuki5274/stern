#pragma once

class Demo {
private:
	static int movie_handle;//�f�����i�[����

	static bool check_state();//�Đ���Ԃ𒲂ׂ�(1 �Đ���,0 ��~�� -1 �G���[)
public:
	static void initialize();
	static void finalize();
	static void update();
	static void draw();
};