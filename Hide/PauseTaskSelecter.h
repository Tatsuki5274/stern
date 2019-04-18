#pragma once

enum class PauseButton {
	returngame,
	exit,
	backssts
};

class PauseSelecter {
private:
	int x;
	int y;
	int graph;
public:
	PauseButton button;
	PauseSelecter();
	void update(int, int, int);
	void draw();
	void switch_button();
	void move(int, int,int);
};