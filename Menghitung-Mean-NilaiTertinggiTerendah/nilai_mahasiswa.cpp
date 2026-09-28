#include<iostream>
using namespace std;

int main(){

    int jumlah;
    int tertinggi = 0;
    int terendah = 1000;
    int total = 0;

    cout << "Jumlah Mahasiswa : ";
    cin >> jumlah;

    int nilai[jumlah];

    for(int i = 0; i < jumlah; i++){
        cout << "Nilai Mahasiswa Ke-" << i + 1 << " : ";
        cin >> nilai[i];
        total += nilai[i];
        if(nilai[i] > tertinggi){
            tertinggi = nilai[i];
        }
        if(nilai[i] < terendah){
            terendah = nilai[i];
        }
    }

    float rata = total / jumlah;

    cout << "Hasil\n";
    cout << "Rata-rata\t:" << rata << "\n" ;
    cout << "Nilai tertinggi\t:" << tertinggi << "\n";
    cout << "Nilai terendah\t:" << terendah << "\n";
    return 0;
}