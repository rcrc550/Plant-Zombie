#include "wd.h"


wd::wd(void)
{
	m_aa=0;
	x=0;
	 y=0;
}


wd::~wd(void)
{
	::DeleteObject(m_aa);
}
void wd::show_wd(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_aa);
	::BitBlt(hdc,x,y,71,78,hmedc,0,0,SRCCOPY);
	::DeleteObject(hmedc);
}
void wd::Init_wd(HINSTANCE hinstance,int x1,int y1)
{
	m_aa=::LoadBitmap(hinstance,MAKEINTRESOURCE(m_ys2));
	x=x1;
	y=y1;
}
void wd::send_shot(HINSTANCE hinstance,shotbox &c_box)
{
	shot *c_shot=new shot;
	c_shot->Init_shot(hinstance,x+66,y);
	c_box.c_shotbox.push_back(c_shot);
}

