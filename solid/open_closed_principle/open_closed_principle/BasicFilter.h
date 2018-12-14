#pragma once
#include <vector>
#include "Product.h"
class BasicFilter {
public:
	BasicFilter();
	~BasicFilter();
	static std::vector<Product*> filterBySize(const std::vector<Product*>& inProducts, Size inSize);
	static std::vector<Product*> filterByColor(const std::vector<Product*>& inProducts, Color inColor);
};

