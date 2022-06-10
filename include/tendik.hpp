#ifndef __TENDIK_HPP__
#define __TENDIK_HPP__

#include <iostream>
#include "include/person.hpp"


class Tendik : public Person {
private:
	std::string npp;
	std::string unit;

public:
	Tendik(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string unit);

	void setUnit(std::string unit);
	std::string getUnit();	
	std::string getNPP();	
};

#endif