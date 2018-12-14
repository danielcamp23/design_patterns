#pragma once
#include "Specification.h"
#include "Product.h"

class ColorSpecification : public  Specification<Product> {
public:
	ColorSpecification(Color inColor);
	~ColorSpecification();
	virtual bool isSatisfied (const Product* inItem) override;

private:
	Color color;
};

