#include "Cback.h"


Cback::Cback(void)
{
	m_back=0;
	m_f=0;
	m_w=0;
	m_s=0;
	x=0;
	y=0;
}


Cback::~Cback(void)
{
	::DeleteObject(m_back);
}
void Cback::Init_back(HINSTANCE m_hi)
{
	m_back=::LoadBitmap(m_hi,MAKEINTRESOURCE(m_background));
	m_f=::LoadBitmap(m_hi,MAKEINTRESOURCE(m_fmj));
	m_s=::LoadBitmap(m_hi,MAKEINTRESOURCE(m_ys2));
	m_w=::LoadBitmap(m_hi,MAKEINTRESOURCE(m_ms));
}
void Cback::Show_back(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_back);
	::BitBlt(hdc,0,0,715,533,hmedc,0,0,SRCCOPY);
	HDC hmdc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_f);
	::BitBlt(hdc,20,0,69,82,hmedc,0,0,SRCCOPY);
	HDC hedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_w);
	::BitBlt(hdc,100,0,72,77,hmedc,0,0,SRCCOPY);
	HDC hpdc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_s);
	::BitBlt(hdc,180,0,66,84,hmedc,0,0,SRCCOPY);
	::DeleteDC(hpdc);
	::DeleteDC(hedc);
	::DeleteDC(hmedc);
	::DeleteDC(hmdc);
}