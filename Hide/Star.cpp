#include"Star.h"

//---------------------------------
//星全般
//---------------------------------

Star::Star(int power_, int life_, int weight_,int x_,double angle_)
{
	point.x = x_;
	angle = angle_;
	power = power_;
	weight = weight_;
	life = life_;
}

bool Star::attack()
{
	Enemy_point = ct->gts->enemy->get()->point;
	p[0] = { Enemy_point.x,Enemy_point.y };
	p[1] = { Enemy_point.x + Enemy_point.w,Enemy_point.y };
	p[2] = { Enemy_point.x,Enemy_point.y + Enemy_point.h };
	p[3] = { Enemy_point.x + Enemy_point.w,Enemy_point.y + Enemy_point.h };
	for (int i = 0; i < 4; ++i) {//星が敵の角に触れている場合
		if ((p[i].x - point.x)*(p[i].x - point.x) + (p[i].y - point.y)*(p[i].y - point.y) >= radius * radius) {//三平方の定理で頂点と触れているか判定
			return true;
		}
	}


	if (point.x + radius > p[0].x&&point.x - radius<p[1].x&&point.y + radius>p[0].y&&point.y - radius < p[2].y) {//星が敵の中に入ってる場合,星が辺と接している場合（radiusで判定拡大することによって実現）
		return true;
	}
	return false;
}

bool Star::damage(int)
{

	return false;
}


