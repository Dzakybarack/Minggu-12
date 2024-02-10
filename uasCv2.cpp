#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur data untuk menyimpan informasi karyawan
struct Karyawan 
{
    string Nama;
    string Alamat;
    int Umur;
    string Jabatan;
};

// Fungsi untuk menambahkan karyawan baru ke dalam daftar
void tambahKaryawan(Karyawan karyawan[], int &jumlahKaryawan) 
{
    cout << "Masukkan Nama Karyawan: ";
    cin >> karyawan[jumlahKaryawan].Nama;
    cout << "Masukkan Alamat Karyawan: ";
    cin >> karyawan[jumlahKaryawan].Alamat;
    cout << "Masukkan Umur Karyawan: ";
    cin >> karyawan[jumlahKaryawan].Umur;
    cout << "Masukkan Jabatan Karyawan: ";
    cin >> karyawan[jumlahKaryawan].Jabatan;

    // Menyimpan data karyawan ke dalam file
    ofstream file("Data Karyawan.txt", ios::app);
    file << karyawan[jumlahKaryawan].Nama << " "
         << karyawan[jumlahKaryawan].Alamat << " "
         << karyawan[jumlahKaryawan].Umur << " "
         << karyawan[jumlahKaryawan].Jabatan << endl;
    file.close();

    jumlahKaryawan++;
    cout << "Karyawan berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan seluruh data karyawan
void tampilkanDataKaryawan(Karyawan karyawan[], int jumlahKaryawan) 
{
    cout << "=== Data Karyawan ===" << endl;
    for (int i = 0; i < jumlahKaryawan; i++) 
    {
        cout << "Nama: " << karyawan[i].Nama << endl;
        cout << "Alamat: " << karyawan[i].Alamat << endl;
        cout << "Umur: " << karyawan[i].Umur << endl;
        cout << "Jabatan: " << karyawan[i].Jabatan << endl;
        cout << "---------------------" << endl;
    }
}

// Fungsi untuk menghitung gaji total karyawan
double hitungGajiTotal(double gajiPerBulan, int jamLembur) 
{
    // Upah lembur 1% dari gaji per bulan per jam
    double upahLembur = 0.01 * gajiPerBulan * jamLembur;
    return gajiPerBulan + upahLembur;
}

// Fungsi untuk melakukan pembayaran gaji
void bayarGaji(Karyawan karyawan[], int jumlahKaryawan) 
{
    // Menampilkan nama-nama karyawan
    cout << "=== Nama Karyawan ===" << endl;
    for (int i = 0; i < jumlahKaryawan; i++) 
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
    ofstream file("Pembayaran gaji.txt", ios::app);
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
    const int maxKaryawan = 100;
    Karyawan daftarKaryawan[maxKaryawan];
    int jumlahKaryawan = 0;

    int pilihan;
    do 
    {
        cout << "=== Program Manajemen Karyawan ===" << endl;
        cout << "1. Tambah Karyawan" << endl;
        cout << "2. Tampilkan Data Karyawan" << endl;
        cout << "3. Pembayaran Gaji dan Lembur" << endl;
        cout << "4. Tampilkan Data Gaji" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahKaryawan(daftarKaryawan, jumlahKaryawan);
                break;
            case 2:
                tampilkanDataKaryawan(daftarKaryawan, jumlahKaryawan);
                break;
            case 3:
                bayarGaji(daftarKaryawan, jumlahKaryawan);
                break;
            case 4:
                tampilkanDataGaji();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                break;
        }

    } while (pilihan != 5);
}