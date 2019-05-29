#include "PlayerController.h"
#include "PlayerConfig.h"
#include "CoreTask.h"	//modelに移行する

void PlayerController::initialize() {
	ct->gts->player->set_hp(PLAYER_MAX_HP);
	ct->gts->player->set_invincible(0);
	ct->gts->player->set_life(PLAYER_MAX_LIFE);
}