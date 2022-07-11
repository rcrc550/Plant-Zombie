#pragma once
#include"sys.h"
class die_cor
{
public:
	die_cor(void);
	~die_cor(void);
public:
	HBITMAP m_aa;
	int x;
	int y;
	int i;
	int showid;
public:
	void show_die(HDC hdc);

 void Init_die(HINSTANCE hinstance,int x,int y);
	
};

