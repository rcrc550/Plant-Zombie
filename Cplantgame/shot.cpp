#include "shot.h"


shot::shot(void)
{
	x=0;
	y=0;
	c_shot=0;


}


shot::~shot(void)
{
	::DeleteObject(c_shot);

}
void shot::shot_move()
{
	x+=1;

}
void shot::show_shot(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,c_shot);
	::BitBlt(hdc,x,y,66,85,hmedc,0,0,SRCCOPY);
	::DeleteDC(hmedc);

}
void shot::Init_shot(HINSTANCE m_hi,int x1,int y1)
{
	c_shot=::LoadBitmap(m_hi,MAKEINTRESOURCE(m_feng));
	x=x1;
	y=y1;

}