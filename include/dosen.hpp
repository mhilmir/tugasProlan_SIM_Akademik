#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include "include/person.hpp"

class dosen : public person {
private:
	std::string npp;
	std::string departemen;
	std::string pendidikan;

public:
	dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan);

    // menambahkan fungsi buat akses npp
    void setNPP(std::string npp);
    std::string getNPP();

    // menambahkan fungsi buat akses departemen
    void setDepartemen(std::string departemen);
    std::string getDepartemen();

	void setPendidikan(std::string pendidikan);
	std::string getPendidikan();
};

#endif 
