#pragma once
#include "Filter.h"
#include "Product.h"

class ProductFilter : Filter<Product>{
public:
	ProductFilter();
	~ProductFilter();
	virtual std::vector<Product*> applyFilter(const std::vector<Product*>& inItems, Specification<Product>& inSpecification);

};

