#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
#include <vector>

struct dataMhs{
    std::string nama;
    std::string nrp;
    std::string departemen;
};

struct dataDsn{
    std::string nama;
    std::string npp;
    std::string departemen;
};

class Matkul{
private:
    std::string id;
    std::string nama_matkul;
    int beban_sks;
    std::vector <dataMhs> databaseMhs;
    std::vector <dataDsn> databaseDsn;

public:
    Matkul(std::string id, std::string nama, int sks);

    void fillDatabaseMhs(dataMhs inputData);
    void fillDatabaseDsn(dataDsn inputData);
    std::string getId();
    std::string getNama();
    int getBebanSKS();
    std::vector<dataDsn> getDatabaseDsn();
    std::vector<dataMhs> getDatabaseMhs();
};

#endif