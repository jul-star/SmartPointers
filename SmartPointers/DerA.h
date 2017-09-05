#pragma once
#include "Base.h"
class DerA :
	public Base
{
public:
	DerA();
	~DerA();
	std::unique_ptr<ABC> create() override;
};

