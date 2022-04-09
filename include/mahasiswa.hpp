#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__


#include <iostream>
#include "include/person.hpp"

class mahasiswa : public person {
private:
	std::string nrp;
	std::string departemen;
	int tahunmasuk;
	int semesterke;
	int skslulus;
	float ipk;
	std::vector<float> ips;

public:
	mahasiswa(std::string id, std::string nama, int dd, int mm, int yy,
					std::string nrp, std::string departemen, int tahunmasuk);

    // membuat fungsi untuk akses nrp
    void setNRP(std::string nrp);
    std::string getNRP();

    // membuat fungsi untuk akses departemen
    void setDepartemen(std::string departemen);
    std::string getDepartemen();

    // membuat fungsi untuk akses tahunmasuk
    void setTahunmasuk(int tahunmasuk);
    int getTahunmasuk();

	void setSemester(int semesterke);
	int getSemester();

	void setSKSLulus(int skslulus);
	int getSKSLulus();

	void hitungIPK();
    float getIPK();  // menambahkan fungsi untuk mengambil ipk

	void setIPS(int semester, float ips);
	float getIPS(int semester);
	std::vector<float> getAllIPS();

};

#endif