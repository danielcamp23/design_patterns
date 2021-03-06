// fluent_builder.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
The Builder is a design pattern designed to provide a flexible solution to various object creation problems in object-oriented programming. 
The intent of the Builder design pattern is to separate the construction of a complex object from its representation. 
It is one of the Gang of Four design patterns.

Separate the construction of a complex object from its representation so that the same construction process can create 
different representations.

Rules of thumb
Sometimes creational patterns are complementary: Builder can use one of the other patterns to implement which components get built. 
Abstract Factory, Builder, and Prototype can use Singleton in their implementations.
Builder focuses on constructing a complex object step by step. Abstract Factory emphasizes a family of product objects 
(either simple or complex). Builder returns the product as a final step, but as far as the Abstract Factory is concerned, 
the product gets returned immediately.
Builder often builds a Composite.
Often, designs start out using Factory Method (less complicated, more customizable, substructes proliferate) and evolve 
toward Abstract Factory, Prototype, or Builder (more flexible, more complex) as the designer discovers where more flexibility 
is needed.
*/


#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlBuilder;

struct HtmlElement {
	HtmlElement() = default;
	HtmlElement(const string& inName, const string& inText);
	~HtmlElement() = default;
	string str(size_t indent = 0) ;
	static unique_ptr<HtmlBuilder> create(const string& inRootName);

	string name;
	string text;
	const size_t identSize = 3;
	vector<HtmlElement> elements;
};

struct HtmlBuilder {
	HtmlBuilder(const string& inRootName);
	~HtmlBuilder() = default;
	HtmlBuilder* addElement(const string& inName, const string& inText);
	string str();
	HtmlElement build();
	HtmlElement root;
};

HtmlElement::HtmlElement(const string& inName, const string& inText) : name(inName), text(inText) {}

/*
HtmlElement::~HtmlElement() {
	cout << "HtmlElement Destructor" << endl;
}
*/

string HtmlElement::str(size_t indent)  {
	ostringstream os;
	os << string(identSize * indent, ' ');
	os << "<" << name << ">\n";
	if (text.size() > 0) {
		os << string(identSize * (indent + 1), ' ') << text << "\n";
	}

	for (auto& element : elements) {
		os << element.str(indent+1);
	}
	os << string(identSize * indent, ' ');
	os << "</" << name << ">\n";
	return os.str();
}

unique_ptr<HtmlBuilder> HtmlElement::create(const string & inRootName) {
	return make_unique<HtmlBuilder>(inRootName);
}





HtmlBuilder::HtmlBuilder(const string& inRootName) {
	root.name = inRootName;
}

/*
HtmlBuilder::~HtmlBuilder() {
	cout << "HtmlBuilder Destructor" << endl;
}
*/

HtmlBuilder* HtmlBuilder::addElement(const string& inName, const string& inText) {
	root.elements.push_back(HtmlElement(inName, inText));
	return this;
}

string HtmlBuilder::str() {
	return root.str();
}


HtmlElement HtmlBuilder::build() {
	return root;
}


int main()
{
	//HtmlBuilder builder("ul1");
	//builder.addElement("li", "hola")->addElement("li", "adios")->addElement("li", "ahora si me voy");
    //std::cout << "builder 1: " << builder.str()<<endl; 

	HtmlElement htmlElement = HtmlElement::create("ul2")->addElement("li", "lista 1")->addElement("li", "lista2")->build();
	cout << htmlElement.str() << endl;

	return 0;

}



/*
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

struct HtmlElement {
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement() {}
	HtmlElement(const string& name, const string& text)
		: name(name),
		text(text) {
	}

	string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size*indent, ' ');
		oss << i << "<" << name << ">" << endl;
		if (text.size() > 0)
			oss << string(indent_size*(indent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}

	static unique_ptr<HtmlBuilder> build(string root_name) {
		return make_unique<HtmlBuilder>(root_name);
	}
};

struct HtmlBuilder {
	HtmlBuilder(string root_name) {
		root.name = root_name;
	}

	// void to start with
	HtmlBuilder& add_child(string child_name, string child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return *this;
	}

	// pointer based
	HtmlBuilder* add_child_2(string child_name, string child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return this;
	}

	string str() { return root.str(); }

	operator HtmlElement() const { return root; }
	HtmlElement root;
};

int main() {
	// <p>hello</p>
	auto text = "hello";
	string output;
	output += "<p>";
	output += text;
	output += "</p>";
	printf("<p>%s</p>", text);

	// <ul><li>hello</li><li>world</li></ul>
	string words[] = { "hello", "world" };
	ostringstream oss;
	oss << "<ul>";
	for (auto w : words)
		oss << "  <li>" << w << "</li>";
	oss << "</ul>";
	//printf(oss.str().c_str());

	// easier
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello").add_child("li", "world");
	//cout << builder.str() << endl;


	const auto builder2 = HtmlElement::build("ul")
		->add_child_2("li", "hello")->add_child_2("li", "world");
	cout << builder2->str() << endl;


	return 0;
}

*/