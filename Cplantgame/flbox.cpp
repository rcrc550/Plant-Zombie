#include "flbox.h"


flbox::flbox(void)
{
}


flbox::~flbox(void)
{
	list<fl*>::iterator ite=m_fbox.begin();
	while(ite!=m_fbox.end())
	{
		delete(*ite);
		++ite;
	}
}
void flbox::Create_fl(HINSTANCE hi,int x1,int y1)
{
	fl *c_fl=new fl;
	c_fl->Init_fl(hi,x1,y1);
	m_fbox.push_back(c_fl);

}
void flbox::Allfl_show(HDC hdc)
{
	list<fl*>::iterator ite=m_fbox.begin();
	while(ite!=m_fbox.end())
	{
		(*ite)->show_fl(hdc);
		++ite;
	}
}