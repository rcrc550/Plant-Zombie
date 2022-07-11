#pragma once
#include"shotbox.h"
class wd
{
public:
	wd(void);
	~wd(void);
public:
	HBITMAP m_aa;
	int x;
	int y;
public:
 void show_wd(HDC hdc);
 void Init_wd(HINSTANCE hinstance,int x,int y);
 void send_shot(HINSTANCE hinstance,shotbox &c_box);

};

