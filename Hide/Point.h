#pragma once

class Point {
public:
	//À•W‚Æ•‚Æ‚‚³
	int x;
	int y;
	int w;
	int h;
	bool operator!=(Point& a) {
		return &a != this;
	}
};