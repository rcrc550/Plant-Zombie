#pragma once
#include<windows.h>
#define DELARE(THISCLASS)\
Cgameapp *Getojbectset()\
{\
	return new THISCLASS;\
}
class Cgameapp
{
protected:
	HWND m_hwnd;
	HINSTANCE m_hinstance;
public:
	Cgameapp()
    {
		m_hwnd=0;
	
		m_hinstance=0;

	}
	virtual ~Cgameapp()
	{

	}
public:
	void Sethandle(HWND hwnd,HINSTANCE hinstance)
	{
		m_hwnd=hwnd;
		m_hinstance=hinstance;
	}
public:
	
	virtual void  CreateGame(){}
	virtual void  GameRun(WPARAM ntimeid){}     //��ʱ�����
	virtual void  ButtonDown(POINT point){}     //��Ҫһ������� �������ͨ��LPARAM��ȡ�� 
	virtual void  ButtonUp(POINT point){}       //��Ҫһ������� �������ͨ��LPARAM��ȡ��
	virtual void  GameDraw(){}                  //��Ҫhwnd����
	virtual void  KeyDown(WPARAM nkey){}        //���尴�� 
	virtual void  KeyUp(WPARAM nkey ){}         //���尴��
	virtual void  MouseMove(POINT point){}      //��Ҫһ������� �������ͨ��LPARAM��ȡ��



};