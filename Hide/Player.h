#pragma once
#include"Physic.h"
#include"DxLib.h"

//---------------------------------
//�v���C���[
//---------------------------------

class Player :public Physic {
public:
	Player()
	{
		life = 0;
		angle = 0;
		invincible = 0;
		hp = 0;
		interval = 0;
		graph = LoadGraph("img/player.png");
	}
	//���\�b�h
	void update();//�X�V����
	bool damage(void);//�_���[�W���󂯂鏈��
	void draw_interface(int);//UI�`��
	void move();//�ړ�����
	void check_foot();//��������
	bool knockback(int);//�m�b�N�o�b�N

protected:
	//�ϐ�
	int life;//�c�@
	double angle;//�J�[�\���̌X��
	int invincible;//���G����
	int hp;//HP
	int interval;//���̔��ˊԊu
	bool foot_status;//�ݒu���Ă��邩
	bool knockback_status;//�m�b�N�o�b�N����

	//�v���C���[�C���^�[�t�F�C�X
	class PlayerInterface {
	public:
		PlayerInterface() {
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