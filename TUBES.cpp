// Kelompok 6
// Dhesta Athaya Shahada (4.34.23.3.06)
// Dzaky Abdurrahman Mubarok (4.34.23.3.07)
// Rachmadhani Aji (4.34.23.3.18)
// Rakha Ramiro (4.34.23.3.19)
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<iomanip>
using namespace std;

struct keuangan
{
    string deskripsi,waktu,catatan;
    double pemasukan, pengeluaran;
    
};

struct pengeluaran
{
    string waktu, deskripsi;
    double pengeluaran;
};

struct catatan
{
    string waktu,deskripsi,catatan;
};

vector<keuangan> bacakeuangan()
{
    vector<keuangan> datakeuangan;
    ifstream file("pemasukan.txt");

    if (file.is_open())
    {
        keuangan duit;
        while (file >> duit.waktu >>duit.deskripsi >> duit.pemasukan )
        {
            datakeuangan.push_back(duit);
        }
        file.close();
    }
    return datakeuangan;
}

vector<pengeluaran> bacapengeluaran()
{
    vector<pengeluaran> datapengeluaran;
    ifstream file("pengeluaran.txt");

    if (file.is_open())
    {
        pengeluaran duit;
        while (file >> duit.waktu >> duit.deskripsi >> duit.pengeluaran )
        {
            datapengeluaran.push_back(duit);
        }
        file.close();
    }
    return datapengeluaran;
}

vector<catatan> bacapengingat()
{
    vector<catatan> datacatatan;
    ifstream file("pengingat.txt");

    if (file.is_open())
    {
        catatan pengingat;
        while (file >> pengingat.waktu >> pengingat.deskripsi >> pengingat.catatan )
        {
            datacatatan.push_back(pengingat);
        }
        file.close();
    }
    return datacatatan;
}

void simpankeuangan(const vector<keuangan> & datakeuangan)
{
    ofstream file("pemasukan.txt");
    for (const auto& duit : datakeuangan)
    {
        file <<duit.waktu <<" " <<duit.deskripsi << " " <<duit.pemasukan << "\n ";
    }
    file.close();
}

void simpanpengeluaran(const vector<pengeluaran> & datapengeluaran)
{
    ofstream file("pengeluaran.txt");
    for (const auto & duit : datapengeluaran)
    {
        file << duit.waktu << " " <<duit.deskripsi << " " << duit.pengeluaran << "\n";
    }
    file.close();
}

void simpanpengingat(const vector<catatan> & datacatatan)
{
    ofstream file("pengingat.txt");
    for (const auto & pengingat : datacatatan)
    {
        file << pengingat.waktu << " " << pengingat.deskripsi << " " << pengingat.catatan << "\n";
    }
    file.close();
}

void tambahkeuangan (vector<keuangan>& datakeuangan)
{
    keuangan keuanganbaru;
    cout <<" Tanggal (format : DD - MM - YYYY) = ";
    cin >> keuanganbaru.waktu;

    cout <<" Jenis Pemasukan = ";
    cin >> keuanganbaru.deskripsi;

    cout <<" Nominal Pemasukan = ";
    cin >> keuanganbaru.pemasukan;
    keuanganbaru.pemasukan = max(0.0, keuanganbaru.pemasukan);

    datakeuangan.push_back(keuanganbaru);
    simpankeuangan(datakeuangan);
    cout <<" Catatan Berhasil Ditambahkan \n";
}

void tambahpengeluaran (vector<pengeluaran>& datapengeluaran)
{
    pengeluaran pengeluaranbaru;
    cout <<" Tanggal (format : DD - MM - YYYY) = ";
    cin >> pengeluaranbaru.waktu;

    cout <<" Jenis Pengeluaran = ";
    cin >> pengeluaranbaru.deskripsi;

    cout <<" Nominal Pengeluaran = ";
    cin >> pengeluaranbaru.pengeluaran;
    pengeluaranbaru.pengeluaran = max(0.0, pengeluaranbaru.pengeluaran);

    datapengeluaran.push_back(pengeluaranbaru);
    simpanpengeluaran(datapengeluaran);
    cout <<" Catatan Berhasil Ditambahkan \n";
}

void tambahpengingat (vector<catatan>& datacatatan)
{
    catatan pengingatbaru;
    cout <<" Tanggal (format : DD - MM - YYYY) = ";
    cin >> pengingatbaru.waktu;

    cout <<" Jenis Ingatan = ";
    cin >> pengingatbaru.deskripsi;

    cout <<" Isi Pengingat = ";
    cin.ignore();
    getline(cin, pengingatbaru.catatan);
   
    datacatatan.push_back(pengingatbaru);
    simpanpengingat(datacatatan);
    cout <<" Catatan Berhasil Ditambahkan \n";
}

void tampilkeuangan(const vector<keuangan>& datakeuangan)
{
    if (datakeuangan.empty()) 
    {
        cout << "Catatan kosong.\n";
    }
    else 

    {
        for (const auto & keuangan : datakeuangan) 
        {
            cout << setprecision(0) << fixed<< "\nWaktu: " << keuangan.waktu << "\n"
            << "Jenis Penmasukan: " << keuangan.deskripsi << "\n"
            << "Nominal Pemasukan: " << keuangan.pemasukan << "\n";
        }
    }
}

void tampilpengeluaran(const vector<pengeluaran>& datapengeluaran)
{
    if (datapengeluaran.empty()) 
    {
        cout << "Catatan kosong.\n";
    }
    else 

    {
        for (const auto & pengeluaran : datapengeluaran) 
        {
            cout << setprecision(0) << fixed << "\nWaktu: " << pengeluaran.waktu << "\n"
            << "Jenis Pengeluaran: " << pengeluaran.deskripsi << "\n"
            << "Nominal Pengeluaran: " << pengeluaran.pengeluaran << "\n";
        }
    }
}

void tampilpengingat(const vector<catatan>& datacatatan)
{
    if (datacatatan.empty()) 
    {
        cout << "Catatan kosong.\n";
    }
    else 

    {
        for (const auto & pengingat : datacatatan) 
        {
            cout << "\nWaktu: " << pengingat.waktu << "\n"
            << "Jenis Ingatan: " << pengingat.deskripsi << "\n"
            << "Isi Pengingat: " << pengingat.catatan << "\n";
        }
    }
}

void hitungpemasukan(const vector<keuangan>& datakeuangan) 
{
    int totalpemasukan = 0;

    for (const auto& keuangan : datakeuangan) 
    {
        totalpemasukan = totalpemasukan + keuangan.pemasukan;
    }

    cout << "\nTotal Pemasukan : " << totalpemasukan << "\n";
       
}

void hitungpengeluaran(const vector<pengeluaran>& datapengeluaran) 
{
    int totalpengeluaran = 0;

    for (const auto& pengeluaran : datapengeluaran) 
    {
        totalpengeluaran = totalpengeluaran + pengeluaran.pengeluaran;
    }

    cout << "\nTotal Pemasukan : " << totalpengeluaran << "\n";      
}

int main()
{
    vector<keuangan> datakeuangan = bacakeuangan();
    vector<pengeluaran> datapengeluaran = bacapengeluaran();
    vector<catatan> datacatatan = bacapengingat();
    while (true) 
    {
        cout << "\nMenu:\n"
                  << "1. Tambahkan Pemasukan\n"
                  << "2. Tambahkan Pengeluaran\n"
                  << "3. Tambahkan Catatan\n"
                  << "4. Tampilkan Pemasukan\n"
                  << "5. Tampilkan Pengeluaran\n"
                  << "6. Tampilkan Catatan\n"
                  << "7. Total Pemasukan\n"
                  << "8. Total Pengeluaran\n" 
                  << "0. Keluar\n";

        int pilihan;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                tambahkeuangan(datakeuangan);
                break;
            case 2:
                tambahpengeluaran(datapengeluaran);
                break;
            case 3:
                tambahpengingat(datacatatan);
                break;
            case 4:
                tampilkeuangan(datakeuangan);
                break;
            case 5: 
                tampilpengeluaran(datapengeluaran);
                break;
            case 6:
                tampilpengingat(datacatatan);
                break;
            case 7:
                hitungpemasukan(datakeuangan);
                break;
            case 8:
                hitungpengeluaran(datapengeluaran);
                break;
            case 0:
                cout << "Program berakhir.\n";
                break;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
    return 0;
}
