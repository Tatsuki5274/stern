#include "Camera.h"
#include "CoreTask.h"


void Camera::update()
{
	//X,Y���W����葱����
	ct->gts->player->get_point();
	
	//�e�L�[�ɉ�����move�̏������Ă�
	if (ct->keyboard->key_press(KEY_INPUT_W)) {};//W�L�[�������ꑱ������move�̏㏈��
	if (ct->keyboard->key_press(KEY_INPUT_A)) {};//W�L�[�������ꑱ������move�̍�����
	if (ct->keyboard->key_press(KEY_INPUT_D)) {};//W�L�[�������ꑱ������move�̉E����
	if (ct->keyboard->key_press(KEY_INPUT_S)) {};//W�L�[�������ꑱ������move�̉�����
}

void Camera::move(int, int)
{
}

bool Camera::get()
{
	return false;
}
