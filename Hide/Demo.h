#pragma once

class Demo {
private:
	int movie_handle;//�f�����i�[����

	bool check_state();//�Đ���Ԃ𒲂ׂ�(1 �Đ���,0 ��~�� -1 �G���[)
public:
	void initialize();
	void finalize();
	void update();
	void draw();
};