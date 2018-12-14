#pragma once
#include "Specification.h"
#include "Product.h"

class SizeSpecification : public Specification<Product> {
public:
	SizeSpecification(Size inSize);
	~SizeSpecification();
	virtual bool isSatisfied(const Product* inItem);

private:
	Size size;
};

