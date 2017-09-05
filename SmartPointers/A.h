#pragma once
#include  <memory>
#include "B.h"
#include "ABC.h"

class A: public ABC
{
public:
	A(const B &inB);
	~A();
	void print() const override;
private:
	std::shared_ptr<B> vB;
};

