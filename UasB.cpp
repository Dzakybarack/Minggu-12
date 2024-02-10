#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi buku
struct Book {
    string judul;
    string pengarang;
    int tahunPublished;
    int jumlah;
    double harga;
};

// Fungsi untuk menambahkan buku baru ke dalam inventaris
void addBook(Book gudang[], int& bookCount) 
{
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, gudang[bookCount].judul);

    cout << "Masukkan nama pengarang: ";
    getline(cin, gudang[bookCount].pengarang);

    cout << "Masukkan tahun diterbitkan: ";
    cin >> gudang[bookCount].tahunPublished;

    cout << "Masukkan jumlah buku yang masuk: ";
    cin >> gudang[bookCount].jumlah;

    cout << "Masukkan harga satuan: ";
    cin >> gudang[bookCount].harga;

    bookCount++;
}

// Fungsi untuk menampilkan seluruh buku yang tersimpan
void displayInventory(const Book gudang[], int bookCount) 
{
    cout << "Inventaris Buku:\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << "Judul: " << gudang[i].judul << endl;
        cout << "Pengarang: " << gudang[i].pengarang << endl;
        cout << "Tahun Diterbitkan: " << gudang[i].tahunPublished << endl;
        cout << "Jumlah: " << gudang[i].jumlah << endl;
        cout << "Harga Satuan: " << gudang[i].harga << endl << endl;
    }
}

// Fungsi untuk menyimpan data buku dalam file
void saveInventoryToFile(const Book gudang[], int bookCount) 
{
    ofstream outFile("inventory.txt");
    for (int i = 0; i < bookCount; ++i) {
        outFile << gudang[i].judul << "," << gudang[i].pengarang << "," << gudang[i].tahunPublished
                << "," << gudang[i].jumlah<< "," << gudang[i].harga << "\n";
    }
    outFile.close();
}

// Fungsi untuk melakukan pembelian buku
void purchaseBook(Book inventory[], int& bookCount) 
{
    if (bookCount > 0) {
        displayInventory(inventory, bookCount);
        string buyerName, bookTitle, purchaseDate;
        int jumlah;
        float totalPrice = 0;

        cout << "Nama pembeli: ";
        cin.ignore();
        getline(cin, buyerName);
        cout << "Pilih judul buku yang akan dibeli: ";
        getline(cin, bookTitle);
        cout << "Jumlah buku yang akan dibeli: ";
        cin >> jumlah;
        cout << "Tanggal pembelian (dd/mm/yyyy): ";
        cin >> purchaseDate;
            
        for (int i = 0; i < bookCount; ++i) {
            if (inventory[i].judul == bookTitle) {
                if (inventory[i].jumlah >= jumlah) {
                    totalPrice = inventory[i].harga * jumlah;
                    inventory[i].jumlah -= jumlah;
                    cout << "Pembelian berhasil.\nTotal harga yang harus dibayar: " << totalPrice << endl;
                    saveInventoryToFile(inventory, bookCount);

                    ofstream purchaseFile("transactions.txt", ios::app);
                    if (purchaseFile.is_open()) {
                        purchaseFile << buyerName << "," << bookTitle << "," << jumlah << "," << totalPrice << "," << purchaseDate << "\n";
                        purchaseFile.close();
                    } else {
                        cout << "Gagal menyimpan transaksi pembelian ke file.\n";
                    }
                    return;
                } else {
                    cout << "Maaf, jumlah buku tidak mencukupi.\n";
                    return;
                }
            }
        }
        cout << "Buku tidak ditemukan dalam inventaris.\n";
    } else {
        cout << "Inventaris kosong.\n";
    }
}


int main() 
{
    const int MAX_BOOKS = 100;
    Book inventory[MAX_BOOKS];
    int bookCount = 0;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Inventaris\n";
        cout << "3. Simpan Inventaris ke File\n";
        cout << "4. Pembelian Buku\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(inventory, bookCount);
                break;
            case 2:
                displayInventory(inventory, bookCount);
                break;
            case 3:
                saveInventoryToFile(inventory, bookCount);
                cout << "Inventaris disimpan ke dalam file.\n";
                break;
            case 4:
                purchaseBook(inventory, bookCount);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

}