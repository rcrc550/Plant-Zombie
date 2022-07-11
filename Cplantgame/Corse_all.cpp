#include "Corse_all.h"


Corse_all::Corse_all(void)
{
	 m_corpse=0;
	 id=0;
	 x=0;
	 y=0;
	 xl=0;
	 z=0;
}


Corse_all::~Corse_all(void)
{
	::DeleteObject(m_corpse);
}
void Corse_all::Down_xl()
{
	xl--;
}
bool Corse_all::Cor_die()
{
	if(xl==0)
		return true;
	else
		return false;
}