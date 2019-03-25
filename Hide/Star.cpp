#include"Star.h"

//---------------------------------
//¯‘S”Ê
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
	for (int i = 0; i < 4; ++i) {//¯‚ª“G‚ÌŠp‚ÉG‚ê‚Ä‚¢‚éê‡
		if ((p[i].x - point.x)*(p[i].x - point.x) + (p[i].y - point.y)*(p[i].y - point.y) >= radius * radius) {//ŽO•½•û‚Ì’è—‚Å’¸“_‚ÆG‚ê‚Ä‚¢‚é‚©”»’è
			return true;
		}
	}


	if (point.x + radius > p[0].x&&point.x - radius<p[1].x&&point.y + radius>p[0].y&&point.y - radius < p[2].y) {//¯‚ª“G‚Ì’†‚É“ü‚Á‚Ä‚éê‡,¯‚ª•Ó‚ÆÚ‚µ‚Ä‚¢‚éê‡iradius‚Å”»’èŠg‘å‚·‚é‚±‚Æ‚É‚æ‚Á‚ÄŽÀŒ»j
		return true;
	}
	return false;
}

bool Star::damage(int)
{

	return false;
}


