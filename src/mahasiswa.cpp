#include <iostream>
#include <vector>
#include "include/mahasiswa.hpp"


Mahasiswa::Mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, 
				std::string nrp, std::string departemen, int tahunmasuk)
		: Person(id, nama, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk)
{
	this->ipk = 0.0;
	this->semesterke = 1;
	this->skslulus = 0;

	this->ips = std::vector<float>(14,0);

    this->sksTempuhSemesterIni = 0;
}

// inisialisasi fungsi yang saya buat ///////////////////////////////////////
void Mahasiswa::setNRP(std::string nrp){
    this->nrp = nrp;
}
std::string Mahasiswa::getNRP(){
    return this->nrp;
}
void Mahasiswa::setDepartemen(std::string departemen){
    this->departemen = departemen;
}
std::string Mahasiswa::getDepartemen(){
    return this->departemen;
}
void Mahasiswa::setTahunmasuk(int tahunmasuk){
    this->tahunmasuk = tahunmasuk;
}
int Mahasiswa::getTahunmasuk(){
    return this->tahunmasuk;
}
float Mahasiswa::getIPK(){
    return this->ipk;
}
/////////////////////////////////////////////////////////////////////////////

void Mahasiswa::setSemester(int semesterke){
	this->semesterke = semesterke;
}

int Mahasiswa::getSemester(){
	return this->semesterke;
}

void Mahasiswa::setSKSLulus(int skslulus){
	this->skslulus = skslulus;
}

int Mahasiswa::getSKSLulus(){
	return this->skslulus;
}

void Mahasiswa::hitungIPK(){
    float total = 0;
    for(long unsigned int i = 0; i < ips.size(); i++){
        total += ips[i];
    }
    total /= (this->getSemester()-1);
    this->ipk = total;
}

void Mahasiswa::setIPS(int semester, float ips){
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
		this->hitungIPK();
	}
}

float Mahasiswa::getIPS(int semester){
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

std::vector<float> Mahasiswa::getAllIPS(){
	return this->ips;
}

int Mahasiswa::getSKSTempuh(){
    return this->sksTempuhSemesterIni;
}

void Mahasiswa::tambahMatkul(std::string matkul, int sks){
    this->sksTempuhSemesterIni += sks;
    this->daftarMatkul.push_back(matkul + " (" + std::to_string(sks) + " sks)");
}

void Mahasiswa::printDaftarMatkul(){
    for(int i = 0; i < this->daftarMatkul.size(); i++){
        std::cout << this->daftarMatkul[i];
        if(i != (this->daftarMatkul.size()-1)){
            std::cout << ", ";
        }
    }
}