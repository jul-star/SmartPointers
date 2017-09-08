#include "stdafx.h"
#include "B.h"
#include <iostream>

unsigned int B::index=0;
B::B():
	ID(++index)
{
}


B::~B()
{
}

void B::print() const
{
	std::cout << "hello from B:" << ID << " "<< std::endl;
}
