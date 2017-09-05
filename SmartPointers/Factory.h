#pragma once
#include <memory>
#include "Base.h"
#include "ABC.h"

class Factory
{
public:
	static std::unique_ptr<ABC> create(std::unique_ptr<Base> &up);
};

