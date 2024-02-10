#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur 
struct Karyawan {
    string Nama,Alamat,Jabatan;
    int umur;
};

// Fungsi untuk menambahkan buku baru ke dalam inventaris
void tambahrute(Karyawan karyawan[], int& datakaryawan) 
{
    cout<<endl;
    cout << "Masukkan Nama Karyawan : ";
    cin.ignore();
    getline(cin, karyawan[datakaryawan].Nama);

    cout << "Masukkan Alamat Karyawan : ";
    getline(cin, karyawan[datakaryawan].Alamat);

    cout << "Masukkan Umur Karyawan: ";
    cin, karyawan[datakaryawan].umur;
    
    cout << "Masukkan Jabatan Karyawan: ";
    getline(cin,karyawan[datakaryawan].Jabatan);

    datakaryawan++;
}

// Fungsi untuk menampilkan seluruh buku yang tersimpan
void tampilkanKaryawan(const Karyawan karyawan[], int datakaryawan) 
{
    cout<<endl;
    cout << "Data Karyawan:\n";
    for (int i = 0; i < datakaryawan; ++i) {
        cout << "Nama Karyawan: " << karyawan[i].Nama << endl;
        cout << "Alamat Karyawan: " << karyawan[i].Alamat << endl;
        cout << "Umur Karyawan: " << karyawan[i].umur << endl;
        cout << "Jabatan Karyawan: " << karyawan[i].Jabatan << endl;
    }
}

// Fungsi untuk menyimpan data buku dalam file
void saveInventoryToFile(const Karyawan karyawan[], int datakaryawan) 
{
    ofstream outFile("Data Karyawan.txt");
    for (int i = 0; i < datakaryawan; ++i) {
        outFile << karyawan[i].Nama << "," << karyawan[i].Alamat << "," << karyawan[i].umur
                << "," << karyawan[i].Jabatan << "\n";
    }
    outFile.close();
}

// Fungsi untuk melakukan pembelian buku
void pembeliantiket(Karyawan karyawan[], int& datakaryawan) 
{
    if (datakaryawan > 0) {
        tampilkanKaryawan(karyawan, datakaryawan);
        string namakaryawan, Alamatkaryawan, ;
        int gaji, lembur;
        float totalgaji = 0, gajilembur=0, gajisetahun=0;

        cout << "Nama Karyawan: ";
        cin.ignore();
        getline(cin, namakaryawan);

        for (int i = 0; i < datakaryawan; ++i) {
            if (karyawan[i].Nama == namakaryawan) 
            {       for (int i = 0; i < 12; i++)
                    {
                    cout << "Jumlah gaji perbulan: ";
                    cin >> gaji;
                    cout << "Lembur Bulan ini: "<<" jam";
                    cin >> lembur;
                    gajilembur = gaji*lembur*0.01;
                    totalgaji = gaji + gajilembur;
                    cout << "Gaji Karyawan: " << gaji << endl;
                    cout << "Gaji Satu Bulan: " <<totalgaji << endl;
                    }
                    gajisetahun = gajisetahun + totalgaji;
                    cout << "Gaji Satu Tahun: " <<gajisetahun << endl;
                    saveInventoryToFile(karyawan, datakaryawan);

                    ofstream purchaseFile("Pembayaran.txt", ios::app);
                    if (purchaseFile.is_open()) {
                        purchaseFile <<"nama:"<< buyerName <<endl<<"rute: "<< tikettujuan <<endl 
                        <<"jumlah tiket: "<< jumlah <<endl<<"total harga: "<< totalPrice <<endl
                        <<"tanggal pembelian: "<< purchaseDate << "\n";
                        purchaseFile.close();
                    } else {
                        cout << "Gagal menyimpan transaksi pembelian ke file.\n";
                    }
                    return;
                
            }
        }
        cout << "tiket tidak ditemukan dalam inventaris.\n";
    } else {
        cout << "Inventaris kosong.\n";
    }
}


int main() 
{
    const int MAX_rute = 100;
    ruteper gudang[MAX_rute];
    int ruteCount = 0;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Tiket\n";
        cout << "2. Tampilkan Tiket dalam Investaris\n";
        cout << "3. Simpan Inventaris ke File\n";
        cout << "4. Pembelian Tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tambahrute(gudang, ruteCount);
                break;
            case 2:
                tampilkangudang(gudang, ruteCount);
                break;
            case 3:
                saveInventoryToFile(gudang, ruteCount);
                cout << "Inventaris disimpan ke dalam file.\n";
                break;
            case 4:
                pembeliantiket(gudang, ruteCount);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

}