#include "pch.h"
#include "Product.h"


Product::Product(const std::string& inName, Color inColor, Size inSize) : color(inColor), size(inSize), name(inName) {
}


Product::~Product() {
}

std::string Product::getName() const {
	return name;
}

Color Product::getColor() const {
	return color;
}

Size Product::getSize() const {
	return size;
}
