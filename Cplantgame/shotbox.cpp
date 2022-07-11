#include "shotbox.h"


shotbox::shotbox(void)
{
}


shotbox::~shotbox(void)
{
	list<shot*>::iterator ite=c_shotbox.begin();
	while(ite!=c_shotbox.end())
	{
		delete(*ite);
		++ite;
	}
}
void shotbox::Allshot_move()
{
	list<shot*>::iterator ite=c_shotbox.begin();
	while(ite!=c_shotbox.end())
	{
		if(((*ite)->x)>=700)
		{
			delete(*ite);
			ite=c_shotbox.erase(ite);
		}
		else
		{
		    (*ite)->shot_move();
		     ++ite;
		}
	}

}
void shotbox::Allshot_show(HDC hdc)
{
	list<shot*>::iterator ite=c_shotbox.begin();
	while(ite!=c_shotbox.end())
	{
		(*ite)->show_shot(hdc);
		++ite;
	}

}
