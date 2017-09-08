#include "stdafx.h"
#include "VectorOfSharedPtr.h"
#include "B.h"
#include <iostream>
namespace Vectors {
	void InitializeVector(std::vector<std::shared_ptr<B>> &vValues)
	{
		std::shared_ptr<B> b1(new B());
		std::shared_ptr<B> b2(new B());
		std::shared_ptr<B> b3(new B());
		std::shared_ptr<B> b4(new B());
		std::shared_ptr<B> b5(new B());


		vValues.emplace_back(b1);
		vValues.emplace_back(b2);
		vValues.push_back(b3);
		vValues.push_back(b4);
		vValues.push_back(b5);
	}

	void doPrint(std::string vMessage,
		std::vector<std::shared_ptr<B>> &Vec)
	{
		std::cout << vMessage.c_str() << std::endl;
		for (auto item : Vec)
		{
			std::cout << "ptrs="<< item.use_count() << " ";
			item->print();
		}
	}

	void AssignVectors()
	{
		std::vector<std::shared_ptr<B>> Result;
		{
			std::vector<std::shared_ptr<B>> Input;
			InitializeVector(Input);
			Result = Input;
			doPrint(std::string("InScope"), Result);
		}
		doPrint(std::string("OutScope"), Result);
	}

	std::vector<std::shared_ptr<B>> createVector()
	{
		std::vector<std::shared_ptr<B>> Output;
		InitializeVector(Output);
		return Output;
	}

	void TestcreateVector()
	{
		std::vector<std::shared_ptr<B>> Result = createVector();
		doPrint(std::string("Create Vector"), Result);
	}



}