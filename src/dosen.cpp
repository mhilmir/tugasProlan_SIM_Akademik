#include <iostream>

#include "include/dosen.hpp"


dosen::dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan)
		: person(id, nama, dd, mm, yy), npp(npp), departemen(departemen), pendidikan(pendidikan)
{
}

void dosen::setPendidikan(std::string pendidikan)
{
	this->pendidikan = pendidikan;
}

std::string dosen::getPendidikan()
{
	return this->pendidikan;
}

