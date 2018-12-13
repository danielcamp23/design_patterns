#pragma once
#include <vector>
#include <string>

class Journal
{
public:
	Journal(const std::string& title);
	~Journal();
	void addEntry(const std::string& entry);
	void readEntries() const;
	const std::vector<std::string>& getEntries() const;
	const std::vector<std::string>& getEntries();
	std::string getTitle() const;
private:
	std::string title;
	std::vector<std::string> entries;
	static size_t entriesCounter;
};

