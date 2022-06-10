#include <iostream>
#include <vector>
#include <algorithm>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"

using namespace std;

template <typename T> int cariNamadiDatabase(T &rec, string nama);

int main(){
	vector<Mahasiswa> recMhs;
	vector<Dosen> recDosen;
	vector<Tendik> recTendik;
    vector<Matkul> recMatkul;

    // untuk pilihan user
	int menu_terpilih;
    char lanjutKah;
    // char lanjutKah, tunjukinIPS, tunjukinDatabase;
    // untuk memberi id pada tiap person
    int idMhs = 0;
    int idDosen = 0;
    int idTendik = 0;
    int idMatkul = 0;

	while(1){
        system("clear");
		cout << "Selamat datang di Universitas Laros Jenggirat Tangi" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  => Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  => Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  => Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tenaga kependidikan" << endl;
		cout << "  => Jumlah Mata Kuliah           : " << recMatkul.size() << " mata kuliah" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
        cout << "  7. Tambah Mata Kuliah" << endl;
        cout << "  8. Tambah Dosen ke Mata Kuliah" << endl;
        cout << "  9. Tambah Mahasiswa ke Mata Kuliah" << endl;
        cout << "  10. Tampilkan semua Mata Kuliah" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch(menu_terpilih){
			case 1:{
                idMhs++;
                string id, nama, nrp, departemen;
                int dd, mm, yy, tahunmasuk, semesterke, skslulus;
                float ips_temp;  // menampung ips sementara sebelum di push_back ke vector ips
                vector <float> ips;
                // membersihkan layar konsol
                system("clear");
                // mengambil input
                id = "mhs" + to_string(idMhs);
                cout << "masukkan nama mahasiswa : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir : ";
                cin >> mm;
                cout << "masukkan tahun lahir : ";
                cin >> yy;
                cout << "masukkan nrp : ";
                cin >> nrp;
                cout << "masukkan departemen : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "masukkan tahun masuk : ";
                cin >> tahunmasuk;
                cout << "masukkan semester ke berapa sekarang : ";
                cin >> semesterke;
                if(semesterke > 1){
                    cout << "masukkan jumlah sks lulus : ";
                    cin >> skslulus;
                }
                for(int i = 1 ; i < semesterke; i++){
                    cout << "masukkan ips semester ke-" << i << " : ";
                    cin >> ips_temp; cin.ignore();
                    ips.push_back(ips_temp);
                }
                // assign inputan ke object penampung bernama inputMhs
                Mahasiswa inputMhs = Mahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk);
                inputMhs.setSemester(semesterke);
                inputMhs.setSKSLulus(skslulus);
                for(int i = 1; i < semesterke; i++){
                    inputMhs.setIPS(i, ips[i-1]);
                }
                // push_back inputMhs ke vector recMhs sebagai database
                recMhs.push_back(inputMhs);
            } break;

			case 2:{
                idDosen++;
                string id, nama, npp, departemen, pendidikan;
                int dd, mm, yy;
                // membersihkan layar konsol
                system("clear");
                // mengambil input
                id = "dsn" + to_string(idDosen);
                cout << "masukkan nama dosen : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir : ";
                cin >> mm;
                cout << "masukkan tahun lahir : ";
                cin >> yy;
                cout << "masukkan npp : ";
                cin >> npp;
                cout << "masukkan departemen : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "masukkan pendidikan : ";
                getline(cin, pendidikan);
                // assign inputan ke object penampung bernama inputDosen
                Dosen inputDosen = Dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan);
                // push_back inputDosen ke vector recDosen sebagai database
                recDosen.push_back(inputDosen);
            } break;

			case 3:{
                idTendik++;
                string id, nama, npp, unit;
                int dd, mm, yy;
                // membersihkan layar konsol
                system("clear");
                // mengambil input
                id = "tdk" + to_string(idTendik);
                cout << "masukkan nama tendik : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir : ";
                cin >> mm;
                cout << "masukkan tahun lahir : ";
                cin >> yy;
                cout << "masukkan npp : ";
                cin >> npp;
                cout << "masukkan unit : ";
                cin.ignore();
                getline(cin, unit);
                // assign inputan ke object penampung bernama inputTendik
                Tendik inputTendik = Tendik(id, nama, dd, mm, yy, npp, unit);
                // push_back inputTendik ke vector recTendik sebagai database
                recTendik.push_back(inputTendik);
            } break;

			case 4:{
                char tunjukinIPS;
                // membersihkan layar konsol
                system("clear");
                // pilihan buat nunjukin detail ips atau tidak
                label2:
                cout << "apakah anda ingin melihat rincian ip per semester (IPS) juga (y/n): ";
                cin >> tunjukinIPS;
                if(tunjukinIPS != 'y' && tunjukinIPS != 'Y' && tunjukinIPS != 'n' && tunjukinIPS != 'N'){
                    cout << "input salah" << endl;
                    goto label2;
                }
                // menampilkan data
                for(int i = 0; i < idMhs; i++){
                    cout << i+1 << ". data mahasiswa dengan id: " << recMhs[i].getId() << endl;
                    cout << "\tNama        : " << recMhs[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
                    cout << "\tNRP         : " << recMhs[i].getNRP() << endl;
                    cout << "\tDepartemen  : " << recMhs[i].getDepartemen() << endl;
                    cout << "\tTahun Masuk : " << recMhs[i].getTahunmasuk() << endl;
                    cout << "\tSemester ke : " << recMhs[i].getSemester() << endl;
                    cout << "\tSKS Lulus   : " << recMhs[i].getSKSLulus() << endl;
                    printf ("\tIPK         : %.2f\n", recMhs[i].getIPK());
                    // menampilkan detail ips
                    if(tunjukinIPS == 'y' || tunjukinIPS == 'Y'){
                        cout << "   rincian IPS :\n";
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\tsem" << j;
                        }
                        cout << endl;
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\t" << recMhs[i].getIPS(j);
                        }
                        cout << endl;
                    }
                    // menampilkan matkul dan sks semester ini
                    cout << "\tSKS Tempuh Semester ini : ";
                    if(recMhs[i].getSKSTempuh() == 0){
                        cout << "belum menempuh sks di semester ini" << endl;
                    } else{
                        cout << recMhs[i].getSKSTempuh() << endl;
                    }
                    recMhs[i].printDaftarMatkul();
                    cout << endl;
                }
            } break;

			case 5:{
                // membersihkan layar konsol
                system("clear");
                // menampilkan data
                for(int i = 0; i < idDosen; i++){
                    cout << i+1 << ". data dosen dengan id: " << recDosen[i].getId() << endl;
                    cout << "\tNama        : " << recDosen[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recDosen[i].getNPP() << endl;
                    cout << "\tDepartemen  : " << recDosen[i].getDepartemen() << endl;
                    cout << "\tPendidikan  : " << recDosen[i].getPendidikan() << endl << endl;
                }
            } break;

			case 6:{
                // membersihkan layar konsol
                system("clear");
                // menampilkan data
                for(int i = 0; i < idTendik; i++){
                    cout << i+1 << ". data tendik dengan id: " << recTendik[i].getId() << endl;
                    cout << "\tNama        : " << recTendik[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recTendik[i].getNPP() << endl;
                    cout << "\tUnit        : " << recTendik[i].getUnit() << endl << endl;
                }
            } break;

            case 7:{
                idMatkul++;
                string nama_matkul;
                string id;
                int beban_sks;
                // membersihkan layar konsol
                system("clear");
                // input data
                id = "mkl" + to_string(idMatkul);
                cout << "masukkan nama matkul : ";
                cin.ignore();
                getline(cin, nama_matkul);
                cout << "masukkan beban sks : ";
                cin >> beban_sks;
                cin.ignore();
                // assign inputan ke object penampung bernama inputMatkul
                Matkul inputMatkul = Matkul(id, nama_matkul, beban_sks);
                // push_back inputMatkul ke vector recMatkul sebagai database
                recMatkul.push_back(inputMatkul);
            } break;

            case 8:{
                // membersihkan layar konsol
                system("clear");

                // mengambil input data dosen yang ingin didaftarkan ke matkul
                int indexDosen, indexMatkul;
                string nama;
                cout << "Tuliskan nama lengkap dosen yang ingin ditambahkan : ";
                cin.ignore();
                getline(cin, nama);

                // mencari nama dosen di database
                indexDosen = cariNamadiDatabase(recDosen, nama);
                if(indexDosen == -1){
                    cout << "nama tersebut tidak ditemukan" << endl;
                    break;
                }
                // mengambil input data matkul
                nama.clear();
                cout << "Tuliskan nama matkulnya : ";
                getline(cin, nama);

                // mencari nama matkul di database
                indexMatkul = cariNamadiDatabase(recMatkul, nama);
                if(indexMatkul == -1){
                    cout << "matkul tersebut tidak ditemukan" << endl;
                    break;
                }

                // assign dosen ke matkul
                dataDsn temp;
                temp.nama = recDosen[indexDosen].getNama();
                temp.npp = recDosen[indexDosen].getNPP();
                temp.departemen = recDosen[indexDosen].getDepartemen();
                recMatkul[indexMatkul].fillDatabaseDsn(temp);
            } break;

            case 9:{
                // membersihkan layar konsol
                system("clear");

                // mengambil input data mahasiswa yang ingin didaftarkan ke matkul
                int indexMhs, indexMatkul;
                string nama;
                cout << "Tuliskan nama lengkap mahasiswa yang ingin ditambahkan : ";
                cin.ignore();
                getline(cin, nama);

                // mencari nama mahasiswa di database
                indexMhs = cariNamadiDatabase(recMhs, nama);
                if(indexMhs == -1){
                    cout << "nama tersebut tidak ditemukan" << endl;
                    break;
                }
                // mengambil input data matkul
                nama.clear();
                cout << "Tuliskan nama matkulnya : ";
                getline(cin, nama);

                // mencari nama matkul di database
                indexMatkul = cariNamadiDatabase(recMatkul, nama);
                if(indexMatkul == -1){
                    cout << "matkul tersebut tidak ditemukan" << endl;
                    break;
                }

                // assign dosen ke matkul
                dataMhs temp;
                temp.nama = recMhs[indexMhs].getNama();
                temp.nrp = recMhs[indexMhs].getNRP();
                temp.departemen = recMhs[indexMhs].getDepartemen();
                recMatkul[indexMatkul].fillDatabaseMhs(temp);   
            } break;

            case 10:{
                char tunjukinDatabase;
                // membersihkan layar konsol
                system("clear");
                // pilihan untuk menampilkan mahasiswa dan dosen pada matkul terkait
                label3:
                cout << "apakah anda ingin melihat mahasiswa dan dosen yang terkait matkul ini ? (y/n) : ";
                cin >> tunjukinDatabase; cin.ignore();
                if(tunjukinDatabase != 'y' && tunjukinDatabase != 'Y' && tunjukinDatabase != 'n' && tunjukinDatabase != 'N'){
                    cout << "input salah" << endl;
                    goto label3;
                }
                // menampilkan data
                for(int i = 0; i < idMatkul; i++){
                    cout << i+1 << ". data matkul dengan id: " << recMatkul[i].getId() << endl;
                    cout << "\t Nama Matkul : " << recMatkul[i].getNama() << endl;
                    cout << "\t Beban SKS   : " << recMatkul[i].getBebanSKS() << endl;
                    if(tunjukinDatabase == 'y' || tunjukinDatabase == 'Y'){
                        // menunjukkan database dosen
                        cout << "\t Data Dosen pada Matkul " << recMatkul[i].getNama() << " :\n";
                        for(int j = 0; j < recMatkul[i].getDatabaseDsn().size(); j++){
                            cout << "\t\t " << j+1 << ". " << (recMatkul[i].getDatabaseDsn())[j].nama;
                            cout << " (" << (recMatkul[i].getDatabaseDsn())[j].npp << ") - ";
                            cout << (recMatkul[i].getDatabaseDsn())[j].departemen << endl;
                        }
                        // menunjukkan database mahasiswa
                        cout << "\t Data Mahasiswa pada Matkul " << recMatkul[i].getNama() << " :\n";
                        for(int j = 0; j < recMatkul[i].getDatabaseMhs().size(); j++){
                            cout << "\t\t " << j+1 << ". " << (recMatkul[i].getDatabaseMhs())[j].nama;
                            cout << " (" << (recMatkul[i].getDatabaseMhs())[j].nrp << ") - ";
                            cout << (recMatkul[i].getDatabaseMhs())[j].departemen << endl;
                        }
                    }
                    cout << endl;
                }
            }break;

            default:
                cout << "input anda salah" << endl;
                break;
		}
        // pilihan untuk menjalankan program lagi atau tidak
        label:
        cout << "apakah anda ingin menjalankan program lagi (y/n) : ";
        cin >> lanjutKah;
        if(lanjutKah == 'n' || lanjutKah == 'N'){
            cout << "terimakasih" << endl;
            break;
        } else if(lanjutKah == 'y' || lanjutKah == 'Y'){
        } else{
            cout << "input salah" << endl;
            goto label;
        }
	}
	return 0;
}

template <typename T> int cariNamadiDatabase(T &rec, string inputNama){
    string inputNama_lowerCase, inputNama_upperCase, nama_lowerCase, nama_upperCase;

    inputNama_lowerCase = inputNama;
    transform(inputNama_lowerCase.begin(), inputNama_lowerCase.end(), inputNama_lowerCase.begin(), ::tolower);
    inputNama_upperCase = inputNama;
    transform(inputNama_upperCase.begin(), inputNama_upperCase.end(), inputNama_upperCase.begin(), ::toupper);

    for(int i = 0; i < rec.size(); i++){

        nama_lowerCase = rec[i].getNama();
        transform(nama_lowerCase.begin(), nama_lowerCase.end(), nama_lowerCase.begin(), ::tolower);
        nama_upperCase = rec[i].getNama();
        transform(nama_upperCase.begin(), nama_upperCase.end(), nama_upperCase.begin(), ::toupper);

        if((nama_lowerCase == inputNama_lowerCase) || (nama_upperCase == inputNama_upperCase)){
            return i;
        }
    }
    return -1;
}