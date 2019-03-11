#pragma once
#include"Physic.h"
#include"DxLib.h"
#include<memory>


//---------------------------------
//�v���C���[
//---------------------------------

class Player :public Physic {
public:
	Player();
	//���\�b�h
	double get_angle();//���̈ړ��̂��߂Ɋp�x��񂪕K�v
	void update();//�X�V����
	bool damage(void);//�_���[�W���󂯂鏈��
	void draw_interface(int);//UI�`��
	void move();//�ړ�����
	void check_foot();//��������
	bool knockback(int);//�m�b�N�o�b�N

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
	class StarManager {
	public:
		StarManager();
		//���\�b�h
		void draw(double st, int x);
		void update(double ang,int x);
	private:
		int life;
		int graph;
	};

protected:
	//�ϐ�
	int life;//�c�@
	double angle;//�J�[�\���̌X��
	int invincible;//���G����
	int hp;//HP
	int interval;//���̔��ˊԊu
	bool foot_status;//�ݒu���Ă��邩
	bool knockback_status;//�m�b�N�o�b�N����
	std::unique_ptr<StarManager> starmanager;
};
