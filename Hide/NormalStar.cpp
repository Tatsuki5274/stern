#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//���ʂ̐�
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//���̈ړ�//move�i�j���ˁH
	if (contact) {
		x += (int)(-sin(angle) * velocityX);
		y += (int)(cos(angle) * velocityY);
		if (ct->gts->map->get_bottom&&ct->gts->map->get_top&&ct->gts->map->get_left&&ct->gts->map->get_right) {
			contact = true;

		}
	}
	else {
		this->exercise();
	}
	if (attack()) {
		//enemy�̃_���[�W���Ă�
	}

	draw();
	if (damage(1)) {
		ct->gts->normalstar->destroy();
	}
	//if(gravitystar�����邩�ǂ���)�o//�d�͂�������͈͂����߂ċ߂��ɂȂ�������false�ł���������
	//gravitystar�̍��W����葱����
	//inhale(gravitystar�̍��W);
	//�p
}

void NormalStar::inhale(int, int, float)
{
	//�ړ��ʂ�gravitystar�̍��W�Ƃ̍����o���đ���������
}

