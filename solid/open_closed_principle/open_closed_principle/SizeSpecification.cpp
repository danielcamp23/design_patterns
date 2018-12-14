#include "pch.h"
#include "SizeSpecification.h"


SizeSpecification::SizeSpecification(Size inSize) : size(inSize){

}


SizeSpecification::~SizeSpecification() {
}

bool SizeSpecification::isSatisfied(const Product * inItem) {
	return inItem->getSize() == size;
}
