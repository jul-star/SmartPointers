#pragma once
#include "Base.h"
class DerB :
	public Base
{
public:
	DerB();
	~DerB();
	std::unique_ptr<ABC> create() override;
};

