#pragma once
#include"sys.h"
class fl
{
public:
	fl(void);
	~fl(void);
public:
	HBITMAP m_aa;
	int x;
	int y;
public:
	void show_fl(HDC hdc);
 void Init_fl(HINSTANCE hinstance,int x,int y);
	
};

