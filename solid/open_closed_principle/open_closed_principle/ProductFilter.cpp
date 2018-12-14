#include "pch.h"
#include "ProductFilter.h"
#include <vector>


ProductFilter::ProductFilter() {
}


ProductFilter::~ProductFilter() {
}

std::vector<Product*> ProductFilter::applyFilter(const std::vector<Product*>& inItems, Specification<Product>& inSpecification) {
	std::vector<Product*> products;

	for (const auto& item : inItems) {
		if (inSpecification.isSatisfied(item)) {
			products.push_back(item);
		}
	}
	return products;
}
