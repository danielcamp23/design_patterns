#pragma once
#include <string>;
#include <vector>

class PersistenceManager {
public:
	PersistenceManager();
	~PersistenceManager();
	void save(const std::vector<std::string>& entries, const std::string& fileName);
	void read(const std::string& fileName);
};

