#pragma once
#include"sys.h"
class shot
{
public:
	shot(void);
	~shot(void);
public:
	HBITMAP c_shot;
	int x;
	int y;
public:
	void shot_move();
	void show_shot(HDC hdc);
	void Init_shot(HINSTANCE m_hi,int x,int y);
};

