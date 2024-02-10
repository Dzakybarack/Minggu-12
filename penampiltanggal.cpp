#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

main(){
int jum_hari[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int bulan, tahun, jhari;

cout<<"=======================================================\n";
cout<<" 1 = Januari    2 = Februari 3 = Maret     4 = April\n";
cout<<" 5 = Mei        6 = Juni     7 = Juli      8 = Agustus\n";
cout<<" 5 = September 10 = Oktober 11 = November 12 = Desember\n";
cout<<"=======================================================\n";

cout<<"\nMasukkan bulan [1-12] : ";
cin>>bulan;
cout<<"Masukkan tahun        : ";
cin>>tahun;
    if(bulan == 2){
        if((tahun % 4 == 0) && (tahun % 100 != 0))
            jhari = 29;
        else
            jhari = 28;
    }
    else {
        jhari = jum_hari[bulan-1];
    }
    cout<<"\nJumlah hari bulan "<<bulan<<" tahun "<<tahun<<" = "<<jhari<<"\n";

getch();
}