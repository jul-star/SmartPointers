#include "stdafx.h"
#include "SharedFromUnique.h"
#include <iostream>

namespace S4U {


	void doPrint(std::unique_ptr<B> &uB, std::shared_ptr<B> &sB)
	{
		std::cout << "Unique=";
		uB->print();
		std::cout << "Shared=" << sB.use_count() << std::endl;
	}

	void Shared4Unique01()
	{
		std::unique_ptr<B> uB(new B());

		std::shared_ptr<B> sB(uB.get());
		doPrint(uB, sB);
		uB.release(); // without release it crashes!!!		
	}

	void Shared4Unique02()
	{
		std::unique_ptr<B> uB(new B());
		std::shared_ptr<B> sB = std::make_shared<B>(*uB.get());
		doPrint(uB, sB);
	}

	void Shared4Unique03()
	{
		std::unique_ptr<B> uB(new B());
		std::shared_ptr<B> sB = std::make_shared<B>(*uB.get());
		doPrint(uB, sB);
		std::shared_ptr<B> sB1(sB);
		std::cout << "Shared2= " << sB1.use_count() << std::endl;
	}

}
