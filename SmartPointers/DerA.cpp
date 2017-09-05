#include "stdafx.h"
#include "DerA.h"
#include "A.h"


DerA::DerA()
{
}


std::unique_ptr<ABC> DerA::create()
{

	return std::unique_ptr<ABC>(new A(*new B()));
}

DerA::~DerA()
{
}
