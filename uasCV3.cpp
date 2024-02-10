#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur 
struct Karyawan {
    string Nama,Alamat;
    int umur;
    string Jabatan;
};

// Fungsi untuk menambahkan data karyawan
void tambahkaryawan(Karyawan karyawan[], int& datakaryawan) 
{
    cout<<endl;
    cout << "Masukkan Nama Karyawan : ";
    cin >> karyawan[datakaryawan].Nama;

    cout << "Masukkan Alamat Karyawan : ";
    cin >> karyawan[datakaryawan].Alamat;

    cout << "Masukkan Umur Karyawan: ";
    cin >> karyawan[datakaryawan].umur;
    
    cout << "Masukkan Jabatan Karyawan: \n";
    cin >> karyawan[datakaryawan].Jabatan;
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
    ofstream outFile("Data karyawan.txt");
    for (int i = 0; i < datakaryawan; ++i) {
        outFile << karyawan[i].Nama << "," << karyawan[i].Alamat << "," << karyawan[i].umur
                << "," << karyawan[i].Jabatan << "\n";
    }
    outFile.close();
}

// Fungsi untuk menghitung gaji total karyawan
double hitungGajiTotal(double gajiPerBulan, int jamLembur) 
{
    // Upah lembur 1% dari gaji per bulan per jam
    double upahLembur = 0.01 * gajiPerBulan * jamLembur;
    return gajiPerBulan + upahLembur;
}

// Fungsi untuk melakukan pembayaran gaji
void bayarGaji(Karyawan karyawan[], int datakaryawan) 
{
    // Menampilkan nama-nama karyawan
    cout << "=== Nama Karyawan ===" << endl;
    for (int i = 0; i < datakaryawan; i++) 
    {
        cout << i + 1 << ". " << karyawan[i].Nama << endl;
    }

    // Memilih karyawan untuk pembayaran gaji
    int pilihan;
    cout << "Pilih nomor karyawan untuk pembayaran gaji: ";
    cin >> pilihan;
    pilihan--;

    // Menampilkan informasi gaji dan lembur
    double gajiPerBulan;
    cout << "Masukkan gaji per bulan untuk " << karyawan[pilihan].Nama << ": ";
    cin >> gajiPerBulan;

    int jamLembur;
    cout << "Masukkan jumlah jam lembur untuk " << karyawan[pilihan].Nama << ": ";
    cin >> jamLembur;

    // Menghitung gaji total dan menyimpan data pembayaran gaji ke dalam file
    double gajiTotal = hitungGajiTotal(gajiPerBulan, jamLembur);
    ofstream file("Pembayaran Gaji.txt", ios::app);
    file << karyawan[pilihan].Nama << " "
         << "BulanTahun: " << "Januari2023" << " "
         << "Gaji: " << gajiPerBulan << " "
         << "UpahLembur: " << gajiTotal - gajiPerBulan << " "
         << "TotalGaji: " << gajiTotal << endl;
    file.close();

    cout << "Pembayaran gaji berhasil!" << endl;
}

// Fungsi untuk menampilkan keseluruhan data pembayaran gaji
void tampilkanDataGaji() 
{
    cout << setprecision (0) << fixed << "=== Data Pembayaran Gaji ===" << endl;
    ifstream file("Pembayaran gaji.txt");
    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else 
    {
        cout << "File tidak dapat dibuka." << endl;
    }
}

int main() 
{
    const int MAX_Karyawan = 100;
    Karyawan karyawan[MAX_Karyawan];
    int datakaryawan = 0;

    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Tampilkan Data Karyawan\n";
        cout << "3. Pembayaran Gaji dan Lembur\n";
        cout << "4. Tampilkan Data Gaji\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkaryawan(karyawan, datakaryawan);
                break;
            case 2:
                tampilkanKaryawan(karyawan, datakaryawan);
                break;
            case 3:
                bayarGaji(karyawan, datakaryawan);
                break;
            case 4:
                tampilkanDataGaji();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
    return 0;

}