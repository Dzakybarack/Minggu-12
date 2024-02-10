
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

struct baranggudang
{
    string deskripsi;
    int kuantitas;
    double biayagrosir, biayaecer;
    string tanggalmasuk;
};

vector<baranggudang> bacagudang()
{
    vector<baranggudang> datagudang;
    ifstream file("gudang.txt");

    if (file.is_open()) 
    {
        baranggudang barang;
        while (file >> barang.deskripsi >> barang.kuantitas >> barang.biayagrosir 
        >> barang.biayaecer >> barang.tanggalmasuk) 
        {
            datagudang.push_back(barang);
        }
        file.close();
    }

    return datagudang;
}

void simpangudang(const vector<baranggudang>& datagudang)
{
    ofstream file("gudang.txt");
    for (const auto& barang : datagudang)
    {
        file << barang.deskripsi << " " << barang.kuantitas << " " << barang.biayagrosir 
        << " " << barang.biayaecer << " " << barang.tanggalmasuk << "\n";
    }
    file.close();
}

void tambahbarang(vector<baranggudang>& datagudang)
{
    baranggudang barangbaru;
    cout << "Masukkan Deskripsi Barang: ";
    cin >> barangbaru.deskripsi;

    cout << "Masukkan Jumlah di Tangan: ";
    cin >> barangbaru.kuantitas;
    barangbaru.kuantitas = max(0, barangbaru.kuantitas);

    cout << "Masukkan Biaya Grosir: ";
    cin >> barangbaru.biayagrosir;
    barangbaru.biayagrosir = max(0.0, barangbaru.biayagrosir);

    cout << "Masukkan Biaya Eceran: ";
    cin >> barangbaru.biayaecer;
    barangbaru.biayaecer = max(0.0, barangbaru.biayaecer);

    cout << "Masukkan Tanggal Ditambahkan (format: DD-MM-YYYY): ";
    cin >> barangbaru.tanggalmasuk;

    datagudang.push_back(barangbaru);
    simpangudang(datagudang);
    cout << "Catatan berhasil ditambahkan.\n";
}

void tampilgudang(const vector<baranggudang>& datagudang)
{
    if (datagudang.empty()) 
    {
        cout << "Gudang kosong.\n";
    }
    else 

    {
        for (const auto & barang : datagudang) 
        {
            cout << "\nDeskripsi Barang: " << barang.deskripsi << "\n"
            << "Jumlah di Tangan: " << barang.kuantitas << "\n"
            << "Biaya Grosir: " << barang.biayagrosir << "\n"
            << "Biaya Eceran: " << barang.biayaecer << "\n"
            << "Tanggal Ditambahkan: " << barang.tanggalmasuk << "\n";
        }
    }
}

void barangterbaru(vector<baranggudang>& datagudang)
{
    tampilgudang(datagudang);

    if (datagudang.empty())
    {
        cout << "Tidak ada catatan untuk diperbarui.\n";
    }
    else

    {
        int indeks;
        cout << "Masukkan nomor barang yang ingin diperbarui: ";
        cin >> indeks;
        indeks--;

        if (indeks >= 0 && indeks < datagudang.size())
        {
            string perbarui;
            cout << "Masukkan nama atribut yang ingin diperbarui: ";
            cin >> perbarui;

            if (perbarui == "Jumlah di Tangan" || perbarui == "Biaya Grosir" || perbarui == "Biaya Eceran") {
                double nilaibaru;
                cout << "Masukkan nilai baru untuk " << perbarui << ": ";
                cin >> nilaibaru;
                datagudang[indeks].kuantitas = (perbarui == "Jumlah di Tangan") ? max(0, static_cast<int>(nilaibaru)) : max(0.0, nilaibaru);
            } 
            else 
            {
                cout << "Tidak valid.\n";
            }

            simpangudang(datagudang);
            cout << "Catatan berhasil diperbarui.\n";
        } 
        else 
        {
            cout << "Nomor barang tidak valid.\n";
        }
    }
}

void hitungtotal(const vector<baranggudang>& datagudang) 
{
    double totalgrosir = 0.0;
    double totaleceran = 0.0;
    int totalkuantitas = 0;

    for (const auto& barang : datagudang) 
    {
        totalgrosir += barang.biayagrosir * barang.kuantitas;
        totaleceran += barang.biayaecer * barang.kuantitas;
        totalkuantitas += barang.kuantitas;
    }

    cout << "\nTotal Nilai Grosir : " << totalgrosir << "\n"
        << "Total Nilai Eceran : " << totaleceran << "\n"
        << "Jumlah Total Barang dalam Gudang : " << totalkuantitas << "\n";
}

int main()
{
    vector<baranggudang> datagudang = bacagudang();

    while (true) 
    {
        cout << "\nMenu:\n"
                  << "1. Tambahkan Catatan Baru\n"
                  << "2. Tampilkan Catatan\n"
                  << "3. Perbarui Catatan\n"
                  << "4. Hitung Total Nilai dan Jumlah\n"
                  << "0. Keluar\n";

        int pilihan;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                tambahbarang(datagudang);
                break;
            case 2:
                tampilgudang(datagudang);
                break;
            case 3:
                barangterbaru(datagudang);
                break;
            case 4:
                hitungtotal(datagudang);
                break;
            case 0:
                cout << "Program berakhir.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    return 0;
}
