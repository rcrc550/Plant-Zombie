#include "CplantApp.h"

DELARE(CplantApp)
CplantApp::CplantApp(void)
{
	myid=0;
	itid=3;
}


CplantApp::~CplantApp(void)
{
}
void CplantApp::CreateGame()
{
	m_back.Init_back(m_hinstance);
	
	::SetTimer(m_hwnd,CORSE_CREATE_ID,200,0);
	::SetTimer(m_hwnd,CORSE_MOVE_ID,10,0);
	::SetTimer(m_hwnd,SHOT_CRATE_ID,4000,0);
	::SetTimer(m_hwnd,SHOT_MOVE_ID,1,0);
	::SetTimer(m_hwnd,CHANGE_SHOWID_ID,100,0);
	
}
void CplantApp::GameDraw()
{
	
	PAINTSTRUCT ps={0};
	HDC hdc=::BeginPaint(m_hwnd,&ps);
	HDC hmemdc=::CreateCompatibleDC(hdc);
	HBITMAP hbitmap=::CreateCompatibleBitmap(hdc,715,533);//解决屏幕闪烁的问题
	::SelectObject(hmemdc,hbitmap);
	 m_back.Show_back(hmemdc);
	 c_fl.Allfl_show(hmemdc);
	 c_ms.Allms_show(hmemdc);
	 c_wd.Allwd_show(hmemdc);
	 c_shot.Allshot_show(hmemdc);
	 c_box.All_corshow(hmemdc);
	 d_box.Allfl_show(hmemdc);
	
	 
	 ::BitBlt(hdc,0,0,715,533,hmemdc,0,0,SRCCOPY);
	 ::DeleteObject(hbitmap);
	::DeleteDC(hdc);

	::EndPaint(m_hwnd,&ps);
}
void CplantApp::GameRun(WPARAM ntimeid)
{
	if(ntimeid==CORSE_CREATE_ID)
	{
		c_box.Create_cor(m_hinstance);
	}
	else if(ntimeid==CORSE_MOVE_ID)
	{
		c_box.All_cormove();
		c_box.Boxhit_fl(&c_fl);
		c_box.Boxhit_ms(&c_ms);
		c_box.Boxhit_wd(&c_wd);


	}
	else if(ntimeid==SHOT_CRATE_ID)
	{
		c_wd.All_sendshot(m_hinstance,c_shot);
	}
	
	else if(ntimeid==CHANGE_SHOWID_ID)
	{
		d_box.Change_showid();
	}
	
	else if(ntimeid==SHOT_MOVE_ID)
	{
		c_shot.Allshot_move();
		shothitcor();
	}
	
	RECT rect={0,0,715,533};
	::InvalidateRect(m_hwnd,&rect,FALSE);


}
void CplantApp::ButtonDown(POINT point)
{
	int x1=point.x;
	int y1=point.y;
	if(myid==0)
	{
		if(x1<89&&x1>20&&0<y1&&y1<82)
		{
			itid=1;
			myid=1;//大发明家
		}
		else if(0<y1&&y1<77&&100<x1&&172>x1)
		{
			itid=2;
			myid=1;
		}
		else if(0<y1&&84>y1&&180<x1&&x1<246)
		{
			itid=3;
			myid=1;
		}

	}
	else if(myid==1)
	{
		if(itid==1)
		{
			int x=point.x;
			int y=point.y;
			
			c_fl.Create_fl(m_hinstance,x,y);
			myid--;
			
		}
		else if(itid==2)
		{
			int x=point.x;
			int y=point.y;
			c_ms.Allms_create(m_hinstance,x,y);
			myid--;
		}
		else if(itid==3)
		{
			int x=point.x;
			int y=point.y;
			c_wd.Createwd(m_hinstance,x,y);
			myid--;
		}
		RECT rect={0,0,715,533};
	    ::InvalidateRect(m_hwnd,&rect,FALSE);
	}
	
}
void CplantApp::ButtonUp(POINT point)
{
}
void CplantApp::shothitcor()
{
	bool flag=false;
	list<shot*>::iterator itshot=c_shot.c_shotbox.begin();
	while(itshot!=c_shot.c_shotbox.end())
	{
		int x=0;
		int y=0;;
		list<Corse_all*>::iterator itcor=c_box.m_cbox.begin();
		while(itcor!=c_box.m_cbox.end())
		{
			if((*itcor)->Is_shot(*itshot)==true)
            {
				x=(*itcor)->x;
				y=(*itcor)->y;
				delete(*itshot);
				itshot=c_shot.c_shotbox.erase(itshot);
				delete(*itcor);
				c_box.m_cbox.erase(itcor);
			    d_box.Create_die(m_hinstance,x,y);
				break;
			}
			
			itcor++;
		}
		if(itshot!=c_shot.c_shotbox.end())
			itshot++;
		
			
	}
	
}
void CplantApp::changeid()
{
	list<die_cor*>::iterator ite=d_box.m_fbox.begin();
	while(ite!=d_box.m_fbox.end())
	{
		(*ite)->showid--;
	}
}