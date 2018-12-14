#pragma once
#include <string>

enum class Color {Red, Blue, Green, Yellow};
enum class Size {Small, Medium, Large};


class Product {
public:
	Product(const std::string& inName, Color inColor, Size inSize);
	~Product();
	std::string getName() const;
	Color getColor() const;
	Size getSize() const;

private:
	std::string name;
	Color color;
	Size size;
};

