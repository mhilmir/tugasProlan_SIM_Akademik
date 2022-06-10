#include <iostream>
#include "include/person.hpp"


Person::Person(std::string id, std::string nama, int dd, int mm, int yy)
		: id(id), nama(nama), dd(dd), mm(mm), yy(yy) {}

void Person::setId(std::string id){
	this->id = id;
}

std::string Person::getId() {
	return this->id;
}

void Person::setNama(std::string nama){
	this->nama = nama;
}

std::string Person::getNama(){
	return this->nama;
}

void Person::setTglLahir(int dd, int mm, int yy){
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
}

int Person::getTglLahir(){
	return this->dd;
}

int Person::getBulanLahir(){
	return this->mm;
}

int Person::getTahunLahir(){
	return this->yy;
}