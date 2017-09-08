#pragma once
#include <memory>
#include "ABC.h"

class B: public ABC
{
public:
	B();
	~B();
	void print() const override;
private:
	static unsigned int index;
	unsigned int ID;
};

