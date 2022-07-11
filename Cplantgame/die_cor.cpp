#include "die_cor.h"


die_cor::die_cor(void)
{
	int i=rand()%2;
	x=0;
	y=0;
	showid=3;
	m_aa=0;
}


die_cor::~die_cor(void)
{
	::DeleteObject(m_aa);
}
void die_cor::show_die(HDC hdc)
{
	
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_aa);
	if(i==1)
	::BitBlt(hdc,x,y,88,89,hmedc,0,0,SRCCOPY);
	else
	::BitBlt(hdc,x,y,85,78,hmedc,0,0,SRCCOPY);
	
	::DeleteObject(hmedc);
}
void die_cor::Init_die(HINSTANCE hinstance,int x1,int y1)
{
	
	if(i==1)
	{
	m_aa=::LoadBitmap(hinstance,MAKEINTRESOURCE(m_zk));
	}
	else
	{m_aa=::LoadBitmap(hinstance,MAKEINTRESOURCE(m_ys3));}
	x=x1;
	y=y1;
}