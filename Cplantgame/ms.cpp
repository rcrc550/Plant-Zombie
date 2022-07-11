#include "ms.h"


ms::ms(void)
{
}


ms::~ms(void)
{
}

void ms::show_ms(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_aa);
	::BitBlt(hdc,x,y,72,77,hmedc,0,0,SRCCOPY);
	::DeleteObject(hmedc);
}
void ms::Init_ms(HINSTANCE hi,int x1,int y1)
{
	x=x1;
	y=y1;
	m_aa=::LoadBitmap(hi,MAKEINTRESOURCE(m_ms));
}