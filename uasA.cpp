#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct Rute
{
    string tujuan, waktu;
    int hargatiket, jumlahkuota;
};

vector<Rute> bacarute()
{
    vector<Rute> datarute;
    ifstream file("Inventaris.txt");

    if (file.is_open())
    {
        Rute tiket;
        while(file >> tiket.tujuan >> tiket.waktu >> tiket.hargatiket >> tiket.jumlahkuota)
        {
            datarute.push_back(tiket);
        }
        file.close();
    }
    return datarute;
}

void simpandata(const vector<Rute>& datarute)
{
    ofstream file("Inventaris.txt");
    for (const auto & tiket : datarute)
    {
        file << tiket.tujuan <<" " << tiket.waktu <<" " << tiket.hargatiket <<" " << tiket.jumlahkuota<<"\n";
    }
    file.close();
}

void tambahtiket(vector<Rute>&datarute)
{
    Rute tiketbaru;
    cout <<"Masukan Tujuan ";
    cin >> tiketbaru.tujuan;

    cout <<"Masukan Waktu Keberangkatan ";
    cin >> tiketbaru.waktu;

    cout<<"Masukan Harga Tiket";
    cin >> tiketbaru.hargatiket;

    cout<<"Masukan Jumlah Kuota";
    cin>> tiketbaru.jumlahkuota;

    datarute.push_back(tiketbaru);
    simpandata(datarute);
    cout << "Tiket Telah Ditambahkan.\n";
}

void tampiltiket(const vector<Rute>& datarute)
{
    if(datarute.empty())
    {
        cout<<"Tiket Kosong.\n";
    }
    else
    {
        for(const auto & tiket : datarute)
        {
            cout<<"\nTujuan ="<<tiket.tujuan <<"\n"
                <<"Waktu Keberangkatan = "<< tiket.waktu<<"\n"
                <<"Harga Tiket = "<<tiket.hargatiket<<"\n"
                <<"Jumlah Kuota ="<<tiket.jumlahkuota<<"\n";
        }
    }
}

void pembelianbuku( const vector<Rute>&datarute) 
{
    if (tampiltiket > 0) 
    {
        string Namapembeli, Tujuan, Tanggalpembelian;
        int jumlah,sisatiket;
        float hargatotal = 0;

        tampiltiket(datarute);
        cout << "Nama pembeli: ";
        cin.ignore();
        getline(cin, Namapembeli);
        cout << "Pilih Tujuan Anda : ";
        getline(cin, Tujuan);
        cout << "Untuk Berapa Tiket: ";
        cin >> jumlah;
        cout << "Tanggal pembelian (dd/mm/yyyy): ";
        cin >> Tanggalpembelian;
        
        ofstream file("Inventaris.txt");
        for (const auto & tiket : datarute) {
            if (tiket.tujuan == Tujuan) {
                if (tiket.jumlahkuota >= jumlah) {
                    hargatotal = tiket.hargatiket * jumlah;
                    sisatiket = tiket.jumlahkuota - jumlah;
                    cout << "Pembelian berhasil.\nTotal harga yang harus dibayar: " << hargatotal << endl;
                    simpandata(datarute);

                    ofstream purchaseFile("Datapembeli.txt", ios::app);
                    if (purchaseFile.is_open()) {
                        purchaseFile << Namapembeli << "," << Tujuan << "," << jumlah << "," << hargatotal << "," << Tanggalpembelian << "\n";
                        purchaseFile.close();
                    } else {
                        cout << "Gagal menyimpan transaksi pembelian ke file.\n";
                    }
                    return;
                } else {
                    cout << "Maaf, jumlah kuota tidak mencukupi.\n";
                    return;
                }
            }
        }
        cout << "Tiket tidak ditemukan dalam Data.\n";
    } else {
        cout << "Inventaris kosong.\n";
    }
}

int main()
{
    vector<Rute> datarute = bacarute();

    while (true)
    {
        cout<< "\nMenu:\n"
            << "1. Tambah Rute\n"
            << "2. Tampilkan Rute\n"
            << "3. Beli Tiket\n"
            << "0. Keluar\n";

        int pilihan;
        cout<<"Pilih Menu = ";
        cin>>pilihan;

        switch(pilihan)
        {
            case 1:
                tambahtiket(datarute);
                break;
            case 2:
                tampiltiket(datarute);
                break;
            case 3:
                pembelianbuku(datarute);
                break;
            case 0:
            cout<<"Program Berakhir.\n";
            return 0;
            default:
                cout<<"Pilihan Tidak Valid. Silahkan Coba Lagi.\n";
        }
    }
    return 0;
}