#include "pch.h"
#include "ColorSpecification.h"



ColorSpecification::ColorSpecification(Color inColor) : color(inColor) {

}

ColorSpecification::~ColorSpecification() {
}

bool ColorSpecification::isSatisfied(const Product * inItem) {
	return inItem->getColor() == color;
}
