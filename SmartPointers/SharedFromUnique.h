#pragma once
#include  "B.h"
#include <memory>

namespace S4U {
	void Shared4Unique01();
	void Shared4Unique02();
	void Shared4Unique03();
	void doPrint(std::unique_ptr<B> &uB, std::shared_ptr<B> &sB);
}
