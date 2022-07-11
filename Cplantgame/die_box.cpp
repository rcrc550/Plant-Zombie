#include "die_box.h"


die_box::die_box(void)
{
	
}


die_box::~die_box(void)
{
	list<die_cor*>::iterator ite=m_fbox.begin();
	while(ite!=m_fbox.end())
	{
		delete(*ite);
		ite=m_fbox.erase(ite);
		if(ite!=m_fbox.end())
		++ite;
	}
}
void die_box::Create_die(HINSTANCE hi,int x1,int y1)
{
	die_cor *c_fl=new die_cor;
	c_fl->Init_die(hi,x1,y1);
	m_fbox.push_back(c_fl);

}
void die_box::Allfl_show(HDC hdc)
{
	list<die_cor*>::iterator ite=m_fbox.begin();
	while(ite!=m_fbox.end())
	{
	
		(*ite)->show_die(hdc);
		++ite;
	}
}
void die_box::Change_showid()
{
	list<die_cor*>::iterator ite=m_fbox.begin();
	while(ite!=m_fbox.end())
	{
		if((*ite)->showid<=0)
		{
			delete(*ite);
			ite=m_fbox.erase(ite);
		}
		else
		{
		(*ite)->showid--;
		ite++;
		}
	}
}