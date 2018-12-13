#include "pch.h"
#include "Journal.h"
#include <iostream>
#include <sstream>

size_t Journal::entriesCounter = 0;

Journal::Journal(const std::string& inTitle) : title(inTitle)
{
}


Journal::~Journal()
{
}

void Journal::addEntry(const std::string & entry)
{
	++entriesCounter;
	std::ostringstream os;
	os << entriesCounter << ": " << entry;
	entries.push_back(os.str());
}

void Journal::readEntries() const
{
	std::cout << "\"" <<title<< "\" has "<< entriesCounter << " entries"<< std::endl;
	for (const auto & entry : entries) {
		std::cout << entry << std::endl;
	}
}

const std::vector<std::string>& Journal::getEntries() const {
	return entries;
}

const std::vector<std::string>& Journal::getEntries() {
	return entries;
}

std::string Journal::getTitle() const {
	return title;
}
