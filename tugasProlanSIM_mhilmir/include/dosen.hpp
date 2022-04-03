#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include "include/person.hpp"

class dosen : public person {
private:
	std::string npp;
	std::string departemen;
	int pendidikan;

public:
	dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, int pendidikan);

	void setPendidikan(int pendidikan);
	int getPendidikan();
};

#endif 
