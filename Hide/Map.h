#pragma once

//---------------------------------
//�}�b�v�f�[�^
//---------------------------------

class Map {
public:
	/*
	Map():
	{}
	*/
	void Init();
	void Draw();

private:
	int data[1][1];//���̐��l
	int graph;//�G
	int maxsizex;
	int maxsizey;
	int chip;//�}�b�v�`�b�v
};