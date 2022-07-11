#pragma once
#include"sys.h"
class Cback
{
public:
	Cback(void);
	~Cback(void);
public:
	int x;
	int y;
	HBITMAP m_back;
	HBITMAP m_f;
	HBITMAP m_w;
	HBITMAP m_s;
public:
	void Init_back(HINSTANCE m_hin);
	void Show_back(HDC hdc);
};

