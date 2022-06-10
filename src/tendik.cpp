#include <iostream>
#include "include/tendik.hpp"


Tendik::Tendik(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string unit)
		: Person(id, nama, dd, mm, yy), npp(npp), unit(unit) {}

void Tendik::setUnit(std::string unit){
	this->unit = unit;
}

std::string Tendik::getUnit(){
	return this->unit;
}

std::string Tendik::getNPP(){
	return this->npp;
}
