/*----------------------------------------------------
    Nama Program    : Rata.cpp
    Nama            : Muhammad Fahmi Algifari
    NPM             : 140810260088
    Tanggal buat    : Kamis, 03 September 2026
    Deskripsi       : Algoritma Rata Rata
----------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {

    int jumlah_data;
    float data;
    float total = 0;

    cout << "Masukkan jumlah data: ";
    cin >> jumlah_data;

    for(int i = 1; i <= jumlah_data; i++) {
        cout << "Masukkan data ke-" << i << ": ";
        cin >> data;
        total += data;
    }
    
    float rata_rata = total / jumlah_data;
    cout <<"Jumlah Rata-Ratanya adalah : " << rata_rata;

    return 0;
}
