#pragma once

template<typename T>
class Specification {
public:
	virtual bool isSatisfied(const T* inItem) = 0;
};

