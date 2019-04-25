#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//�����^��
//----------------------------------

/*Physic::Physic(Point point, PhysicState physic_state) 
{
	gravity = physic_state.gravity;
	velocity = 0;
}*/


int Physic::fall(Point p_)
{
	//�d�͂ɂ�闎��
	velocity += int(gravity);  //gravity�̕��������������Ă���

	int prevel = velocity;//�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {//�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }//prevel�������Ă������Ƃ�while�𔲂�����悤��
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_bottom(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			velocity = velocity-prevel-1;//���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
			break;
		}
	
	}
	return velocity;

}
int Physic::Movement_X(Point p_,int velocity_)
{

	int prevel = velocity_;//�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {//�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.x += 1;  prevel -= 1; }
		if (prevel <= -1) { p_.x -= 1;  prevel += 1; }
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_left(hit) == 1|| ct->gts->map->get_right(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel - 1;//���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
			}
			else if (velocity_<0) {
				velocity_ = velocity_ - prevel + 1;
			}
			break;
		}

	}
	return velocity_;

}

int Physic::Movement_Y(Point p_, int velocity_)
{

	int prevel = velocity_;//�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {//�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }
		if (prevel <= -1) { p_.y -= 1;  prevel += 1; }
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_top(hit) == 1 || ct->gts->map->get_bottom(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel + 1;//���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
			}
			else if(velocity_ < 0){
				velocity_ = velocity_ - prevel - 1;
			}
			break;
		}

	}
	return velocity_;

}

/*void Physic::rebound_X()//�o�E���h�̏������K�v�ɂȂ����珑����
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}*/

