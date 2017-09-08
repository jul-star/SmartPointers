#pragma once
#include <vector>
#include <memory>
class B;
namespace Vectors {
	void InitializeVector(std::vector<std::shared_ptr<B>> &vValues);

	void doPrint(std::string vMessage,
		std::vector<std::shared_ptr<B>> &Vec);

	void AssignVectors();

	std::vector<std::shared_ptr<B>> createVector();

	void TestcreateVector();

}
