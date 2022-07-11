#include "fl.h"


fl::fl(void)
{
	m_aa=0;
	x=0;
	 y=0;
}


fl::~fl(void)
{
	::DeleteObject(m_aa);
}
void fl::show_fl(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_aa);
	::BitBlt(hdc,x,y,69,82,hmedc,0,0,SRCCOPY);
	::DeleteObject(hmedc);
}
void fl::Init_fl(HINSTANCE hinstance,int x1,int y1)
{
	m_aa=::LoadBitmap(hinstance,MAKEINTRESOURCE(m_fmj));
	x=x1;
	y=y1;
}
