#pragma once

class BasicUI {
protected:
	int x;
	int y;
	int strwidth;//������̕����i�[
public:
	BasicUI();
	void get_width(const char*);
	void update_txt(const char*);
	void draw_txt(const char*);
	int get_lextx();
	int get_y();
};