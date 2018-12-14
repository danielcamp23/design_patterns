#include "pch.h"
#include "BasicFilter.h"


BasicFilter::BasicFilter() {
}


BasicFilter::~BasicFilter() {
}

std::vector<Product*> BasicFilter::filterBySize(const std::vector<Product*>& inProducts, Size inSize) {
	std::vector<Product*> products;
	for (const auto& product : inProducts) {
		if (product->getSize() == inSize) {
			products.push_back(product);
		}
	}

	return products;
}

std::vector<Product*> BasicFilter::filterByColor(const std::vector<Product*>& inProducts, Color inColor) {
	std::vector<Product*> products;
	for (const auto& product : inProducts) {
		if (product->getColor() == inColor) {
			products.push_back(product);
		}
	}

	return products;
}
