#include "stdafx.h"
#include "DerB.h"
#include "B.h"


DerB::DerB()
{
}


DerB::~DerB()
{
}

std::unique_ptr<ABC> DerB::create()
{
	return std::unique_ptr<ABC>(new B());
}
