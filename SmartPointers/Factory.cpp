#include "stdafx.h"
#include "Factory.h"


std::unique_ptr<ABC> Factory::create(std::unique_ptr<Base>& up)
{
	return up->create();
}
