#pragma once
#include <memory>
#include "ABC.h"

class Base
{
public:
	Base();
	virtual ~Base();
	virtual std::unique_ptr<ABC> create() = 0;
};

