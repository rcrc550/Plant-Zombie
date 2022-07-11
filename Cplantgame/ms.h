#pragma once
#include"sys.h"
class ms
{
public:
	ms(void);
	~ms(void);
public:
	HBITMAP m_aa;
	int x;
	int y;
public:
	void show_ms(HDC hdc);
	void Init_ms(HINSTANCE hi,int x1,int y1);
};

