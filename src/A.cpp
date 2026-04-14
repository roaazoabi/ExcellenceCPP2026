#include "A.h"

static int times=0;
static int delete_times=0;

A::A()
	:m_size(0)
{
   cout<<"Start A for "<<times++<<endl;
}

A::~A()
{
   cout<<"Delete A for "<<delete_times++<<endl;
}

int A::getSize() const
{
	return m_size;
}
