#pragma once

enum class Button {
	start,
	exit
};

class TitleSelecter {
private:
	int x;
	int y;
	int graph;
public:
	Button button;
	TitleSelecter();
	void update(int,int);
	void draw();
	void switch_button();
	void move(int ,int);
};
