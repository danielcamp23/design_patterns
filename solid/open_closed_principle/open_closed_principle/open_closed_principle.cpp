// open_closed_principle.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
/*
It it is wanted to add more filters, what one normally would do is to modify the BasicFilter class and keep adding them.

What open-closed principle states is to keep your design open for new extensions (by extending or inheriting) rather than jumping
into code already written to add the new functionality
*/
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Product.h"
#include "BasicFilter.h"
#include "ColorSpecification.h"
#include "SizeSpecification.h"
#include "ProductFilter.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Product apple("Apple", Color::Red, Size::Large);
	Product tshirt("Tshirt", Color::Yellow, Size::Medium);
	Product orange("Orange", Color::Green, Size::Medium);
	Product melon("Melon", Color::Green, Size::Large);
	Product juice("Juice", Color::Blue, Size::Small);
	Product shorts("Shorts", Color::Green, Size::Medium);

	vector<Product*> products = {&apple , &tshirt, &orange , &melon , &juice, &shorts};
	vector<Product*> filteredProductsColor = BasicFilter::filterByColor(products, Color::Green);
	vector<Product*> filteredProductsSize = BasicFilter::filterBySize(products, Size::Large);

	cout << "Filter by color " << endl;
	for (const auto& product : filteredProductsColor) {
		cout << product->getName() << " - green"<< endl;
	}

	cout << "\nFilter by size " << endl;
	for (const auto& product : filteredProductsSize) {
		cout << product->getName() << " - Large" << endl;
	}

	ColorSpecification colorSpecification(Color::Blue);
	SizeSpecification sizeSpecification(Size::Large);
	ProductFilter productFilter;

	cout << "\n\nAdvanced Filter by size " << endl;
	for (const auto& product : productFilter.applyFilter(products, sizeSpecification)) {
		cout << product->getName() << " - Large" << endl;
	}

	cout << "\n\nAdvanced Filter by solor " << endl;
	for (const auto& product : productFilter.applyFilter(products, colorSpecification)) {
		cout << product->getName() << " - Blue" << endl;
	}



	return 0;
}
