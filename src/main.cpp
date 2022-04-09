#include <iostream>
#include <vector>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
    int idMhs = 0;
    int idDosen = 0;
    int idTendik = 0;
    char lanjutKah, tunjukinIPS;

	while(1) {
        system("clear");
		cout << "Selamat datang di Universitas X" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " mahasiswa" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:{
                idMhs++;
                string id, nama, nrp, departemen, stringIPS;
                int dd, mm, yy, tahunmasuk, semesterke, skslulus;
                float ips_container;
                vector <float> ips;
                id = "mhs" + to_string(idMhs);
                system("clear");
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
                cout << "masukkan jumlah sks lulus : ";
                cin >> skslulus;
                for(int i = 1 ; i < semesterke; i++){
                    cout << "masukkan ips semester ke-" << i << " : ";
                    cin >> ips_container;
                    ips.push_back(ips_container);
                }
                mahasiswa inputMhs = mahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk);
                inputMhs.setSemester(semesterke);
                inputMhs.setSKSLulus(skslulus);
                for(int i = 1; i < semesterke; i++){
                    inputMhs.setIPS(i, ips[i-1]);
                }
                recMhs.push_back(inputMhs);
            }   break;

			case 2:{
                idDosen++;
                string id, nama, npp, departemen, pendidikan;
                int dd, mm, yy;
                id = "dsn" + to_string(idDosen);
                system("clear");
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
                // cin.ignore();
                getline(cin, pendidikan);
                dosen inputDosen = dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan);
                recDosen.push_back(inputDosen);
            }   break;

			case 3:{
                idTendik++;
                string id, nama, npp, unit;
                int dd, mm, yy;
                id = "tdk" + to_string(idTendik);
                system("clear");
                cout << "masukkan nama tendik : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir : ";
                cin >> mm;
                cout << "masukkan tahun lahir : ";
                cin >> yy;
                cout << "masukkan nrp : ";
                cin >> npp;
                cout << "masukkan unit : ";
                cin.ignore();
                getline(cin, unit);
                tendik inputTendik = tendik(id, nama, dd, mm, yy, npp, unit);
                recTendik.push_back(inputTendik);
            }   break;

			case 4:{
                system("clear");
                label2:
                cout << "apakah anda ingin melihat rincian ip per semester (IPS) juga (y/n): ";
                cin >> tunjukinIPS;
                if(tunjukinIPS != 'y' && tunjukinIPS != 'Y' && tunjukinIPS != 'n' && tunjukinIPS != 'N'){
                    cout << "input salah" << endl;
                    goto label2;
                }
                for(int i = 0; i < idMhs; i++){
                    cout << i+1 << ". data mahasiswa dengan id: " << recMhs[i].getId() << endl;
                    cout << "\tNama        : " << recMhs[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
                    cout << "\tNRP         : " << recMhs[i].getNRP() << endl;
                    cout << "\tDepartemen  : " << recMhs[i].getDepartemen() << endl;
                    cout << "\tTahun Masuk : " << recMhs[i].getTahunmasuk() << endl;
                    cout << "\tSemester ke : " << recMhs[i].getSemester() << endl;
                    cout << "\tSKS lulus   : " << recMhs[i].getSKSLulus() << endl;
                    cout << "\tIPK         : " << recMhs[i].getIPK() << endl;
                    if(tunjukinIPS == 'y' || tunjukinIPS == 'Y'){
                        cout << "rincian IPS :\n";
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\tsem" << j;
                        }
                        cout << endl;
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\t" << recMhs[i].getIPS(j);
                        }
                        cout << endl;
                    }
                }
                cout << endl;
                // cout << "tekan enter untuk melanjutkan";
                // cin.get();
                // cin.get();
            }   break;

			case 5:{
                system("clear");
                for(int i = 0; i < idDosen; i++){
                    cout << i+1 << ". data dosen dengan id: " << recDosen[i].getId() << endl;
                    cout << "\tNama        : " << recDosen[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recDosen[i].getNPP() << endl;
                    cout << "\tDepartemen  : " << recDosen[i].getDepartemen() << endl;
                    cout << "\tPendidikan  : " << recDosen[i].getPendidikan() << endl << endl;
                }
                // cout << "tekan enter untuk melanjutkan";
                // cin.get();
                // cin.get();
            }   break;

			case 6:{
                system("clear");
                for(int i = 0; i < idTendik; i++){
                    cout << i+1 << ". data tendik dengan id: " << recTendik[i].getId() << endl;
                    cout << "\tNama        : " << recTendik[i].getNama() << endl;
                    cout << "\tdd/mm/yy    : " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recTendik[i].getNPP() << endl;
                    cout << "\tUnit        : " << recTendik[i].getUnit() << endl << endl;
                }
                // cout << "tekan enter untuk melanjutkan";
                // cin.get();
                // cin.get();
            }   break;
		}
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
        // i++;
	}

	return 0;
}