#pragma once
#include"Physical.h"

//---------------------------------
//�v���C���[
//---------------------------------

class Player :public Physical {
public:
	Player()
	{
		life = 0;
		angle = 0;
		invincible = 0;
		hp = 0;
		interval = 0;
	}
	//���\�b�h
	void Update();//�X�V����
	bool Damage(void);//�_���[�W���󂯂鏈��
protected:
	//�ϐ�
	double angle;//�����o���p�x
	int invincible;//���G����
	int hp;//�c��̗�
	int interval;//���̃N�[���^�C��
	int life;//�c�@

	//�v���C���[�C���^�[�t�F�C�X
	class PlayerInterface {
	public:
		PlayerInterface() {
			//life = Player::life;
		}
		//���\�b�h
		void Draw(int st);
	private:
		int life;
	};

	//�����o���J�[�\��
	class Cursor {
	public:
		Cursor(){}
		//���\�b�h
		void Draw(double st);
	private:
		int life;
	};

};