#include <iostream>

#include "include/dosen.hpp"


Dosen::Dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan)
		: Person(id, nama, dd, mm, yy), npp(npp), departemen(departemen), pendidikan(pendidikan) {}

// inisialisasi fungsi yang saya tambahkan ////////////
void Dosen::setNPP(std::string npp){
    this->npp = npp;
}
std::string Dosen::getNPP(){
    return this->npp;
}
void Dosen::setDepartemen(std::string departemen){
    this->departemen = departemen;
}
std::string Dosen::getDepartemen(){
    return this->departemen;
}
///////////////////////////////////////////////////////

void Dosen::setPendidikan(std::string pendidikan){
	this->pendidikan = pendidikan;
}

std::string Dosen::getPendidikan(){
	return this->pendidikan;
}