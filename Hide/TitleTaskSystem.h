#pragma once
#include<memory>

class TitleTaskSystem {
private:
	class TitleStar {
	private:
		int graph;
		int x;
		int y;
		//�P�x��ύX����
		bool switchbright;
		int bright;//RGB�S�ē����l�œ�����
	public:
		TitleStar();
		void draw();
		void update();
		void bright_switch();
	};
	int graph;
public:
	TitleTaskSystem();
	void update();
	void draw();
	std::unique_ptr<TitleStar> titlestar;
};