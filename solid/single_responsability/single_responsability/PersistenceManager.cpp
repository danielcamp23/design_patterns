#include "pch.h"
#include "PersistenceManager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>


PersistenceManager::PersistenceManager() {
}


PersistenceManager::~PersistenceManager() {
}

void PersistenceManager::save(const std::vector<std::string>& entries, const std::string& fileName) {
	std::ofstream ofs(fileName, std::ofstream::out);
	if (ofs.fail()) {
		throw std::exception();
	}

	ofs << "***** " << fileName << " *****\n";
	for (const std::string& entry : entries) {
		ofs << entry << "\n";
	}

	ofs.close();
}

void PersistenceManager::read(const std::string & fileName) {
	std::ifstream ifs;
	char tmp;
	std::string str;
	ifs.open(fileName);
	if (ifs.fail()) {
		throw std::invalid_argument("Unable to open the file");
	}

	while (!ifs.eof() && !ifs.fail()) {
		std::getline(ifs, str);
		std::cout << str << "\n";
	}

	if (!ifs.eof()) {
		throw std::runtime_error("OEF never reached");
	}

	ifs.close();
}


