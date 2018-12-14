#pragma once
#include <vector>
#include "Specification.h"

template<typename T>
class Filter {
	virtual std::vector<T*> applyFilter(const std::vector<T*>& inItems, Specification<T>& inSpecification) = 0;
};
