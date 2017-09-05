// SmartPointers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <memory>

#include "B.h"
#include "A.h"
#include "Base.h"
#include "DerA.h"
#include "Factory.h"
#include "DerB.h"
#include <iostream>
#include <vector>
#include  "SharedFromUnique.h"

void Test01();
void Test02();
void Test03();
void Test04();
void Test_Reset();
void Test_Assign();
void Test_Vector_AddShPtr2Vector();
void Test_Vector2();
void Test_Vector3();
void Test_Vector4();
void Test_Vector5();
std::shared_ptr<B> createShared_B();

void doPrint3SharedPtr(std::shared_ptr<B> &pb1, std::shared_ptr<B> &pb2, std::shared_ptr<B> &pb3);

int main()
{
	{
		//Test01();
		// Test02();
		//Test03();

		S4U::Shared4Unique03();
	}
	return 0;
}

void Test01()
{
	B b;
	A a(b);
	a.print();
}

void Test02()
{
	std::unique_ptr<Base> upB(new DerA());

	//std::unique_ptr<ABC> upABCB(new B());
	//upABCB->print();

	//std::unique_ptr<ABC> upABC(upB->create());
	//upABC->print();

	std::unique_ptr<ABC> uFB(Factory::create(upB));
	uFB->print();

	std::unique_ptr<Base>upA(new DerB());
	std::unique_ptr<ABC> uFA(Factory::create(upA));
	uFA->print();
}

void doPrint3SharedPtr(std::shared_ptr<B> &pb1, std::shared_ptr<B> &pb2, std::shared_ptr<B> &pb3)
{
	std::cout << "p1=" << pb1.use_count() << ", "
		<< "p2=" << pb2.use_count() << ", "
		<< "p3=" << pb3.use_count() << std::endl;
}



void Test_Reset()
{
	B b1;

	std::shared_ptr<B> pb1(&b1);
	std::shared_ptr<B> pb2 = pb1;
	std::shared_ptr<B> pb3 = pb1;
	doPrint3SharedPtr(pb1, pb2, pb3);

	pb1.reset();
	doPrint3SharedPtr(pb1, pb2, pb3);

	pb1.reset(pb3.get());
	doPrint3SharedPtr(pb1, pb2, pb3);
}

void Test_Assign()
{
	B b1;
	std::shared_ptr<B> pb1(&b1);
	std::shared_ptr<B> pb2 = pb1;
	std::shared_ptr<B> pb3 = pb1;
	doPrint3SharedPtr(pb1, pb2, pb3);
}

void Test_Vector_AddShPtr2Vector()
{
	B b1;

	std::shared_ptr<B> pb1(&b1);
	std::shared_ptr<B> pb2 = pb1;
	std::shared_ptr<B> pb3 = pb1;
	doPrint3SharedPtr(pb1, pb2, pb3);

	std::vector<std::shared_ptr<B>> vPointers;
	vPointers.push_back(pb1);
	vPointers.push_back(pb2);
	vPointers.push_back(pb3);
	doPrint3SharedPtr(vPointers.at(0), vPointers.at(1), vPointers.at(2));
}


void Test_Vector2()
{
	B b1;

	std::shared_ptr<B> pb1(&b1);
	std::shared_ptr<B> pb2 = pb1;
	std::shared_ptr<B> pb3 = pb1;
	doPrint3SharedPtr(pb1, pb2, pb3);

	std::vector<std::shared_ptr<B>*> vPointers;
	vPointers.push_back(&pb1);
	vPointers.push_back(&pb2);
	vPointers.push_back(&pb3);
	doPrint3SharedPtr(*vPointers.at(0), *vPointers.at(1), *vPointers.at(2));
}
std::shared_ptr<B> createShared_B()
{
	return std::make_shared<B>(B());
}

void Test_Vector3()
{
	B b1;
	std::vector<std::shared_ptr<B>> vPointers;
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	doPrint3SharedPtr(vPointers.at(0), vPointers.at(1), vPointers.at(2));
	{
		std::shared_ptr<B> pb1 = vPointers.at(0);
		std::shared_ptr<B> pb2 = vPointers.at(1);
		std::shared_ptr<B> pb3 = vPointers.at(2);
		doPrint3SharedPtr(pb1, pb2, pb3);
	}
	doPrint3SharedPtr(vPointers.at(0), vPointers.at(1), vPointers.at(2));
}

void Test_Vector4()
{
	B b1;
	std::vector<std::shared_ptr<B>> vPointers;
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	doPrint3SharedPtr(vPointers.at(0), vPointers.at(1), vPointers.at(2));
	size_t size = 0;
	for(auto item: vPointers)
	{
		size += sizeof(item);
	}
	std::cout << "vPointers=" << sizeof(vPointers) << ", " << size << std::endl;


	std::vector<B> vBs;
	vBs.push_back(B());
	vBs.push_back(B());
	vBs.push_back(B());
	size = 0;
	for (auto item : vBs)
	{
		size += sizeof(item);
	}
	std::cout << "vBs=" << sizeof(vBs) << ", " << size << std::endl;
}


void Test_Vector5()
{
	B b1;
	std::vector<std::shared_ptr<B>> vPointers;
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	vPointers.push_back(createShared_B());
	doPrint3SharedPtr(vPointers.at(0), vPointers.at(1), vPointers.at(2));
	size_t size = 0;
	for (auto item : vPointers)
	{
		size += sizeof(item);
	}
	std::cout << "vPointers=" << sizeof(vPointers) << ", " << size << std::endl;
	for(auto item: vPointers)
	{
		item->print();
	}


	std::vector<B*> vBs;
	vBs.push_back(new B());
	vBs.push_back(new B());
	vBs.push_back(new B());
	size = 0;
	for (auto item : vBs)
	{
		size += sizeof(item);
	}
	std::cout << "vBs=" << sizeof(vBs) << ", " << size << std::endl;
	for (auto item: vBs)
	{
		item->print();
	}
}
void Test04(const A& a)
{
	// std::unique_ptr<ABC> myA(std::move(a));
}
