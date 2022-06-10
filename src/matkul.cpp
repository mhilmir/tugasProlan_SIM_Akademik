#include <iostream>
#include <vector>
#include "include/matkul.hpp"

Matkul::Matkul(std::string id, std::string nama, int sks)
        : id(id), nama_matkul(nama), beban_sks(sks) {}

void Matkul::fillDatabaseMhs(dataMhs inputData){
    this->databaseMhs.push_back(inputData);
}

void Matkul::fillDatabaseDsn(dataDsn inputData){
    this->databaseDsn.push_back(inputData);
}

std::string Matkul::getId(){
    return this->id;
}

std::string Matkul::getNama(){
    return this->nama_matkul;
}

int Matkul::getBebanSKS(){
    return this->beban_sks;
}

std::vector<dataDsn> Matkul::getDatabaseDsn(){
    return this->databaseDsn;
}

std::vector<dataMhs> Matkul::getDatabaseMhs(){
    return this->databaseMhs;
}