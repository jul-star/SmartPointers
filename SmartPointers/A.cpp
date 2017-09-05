#include "stdafx.h"
#include "A.h"
#include <iostream>

A::A(const B& inB):
	vB(std::make_shared<B>(inB))
{
}

void A::print() const
{
	std::cout << "A:" << std::endl;
	vB->print();
	std::cout << vB.use_count() << std::endl;
}

A::~A()
{
}
