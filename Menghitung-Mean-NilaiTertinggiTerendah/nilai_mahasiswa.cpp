#include<iostream>
using namespace std;

int jumlahMahasiswa(int jumlah){
    cin >> jumlah;
    return jumlah;
}

int nilaiMahasiswa(int nilai[], int i){
    cin >> nilai[i];
    return nilai[i];

}

void TinggiRendah(int nilai, int &total, int &tertinggi, int &terendah) {
    total += nilai;

    if (nilai > tertinggi) {
        tertinggi = nilai;
    }
    if (nilai < terendah) {
        terendah = nilai;
    }
}

float ratarata(int total, int jumlah){
    return (float)total / jumlah;;
}

void hasil(int tertinggi, int terendah, int rata){
    cout << "Hasil\n";
    cout << "Rata-rata\t:" << rata << "\n" ;
    cout << "Nilai tertinggi\t:" << tertinggi << "\n";
    cout << "Nilai terendah\t:" << terendah << "\n";
}

int main(){

    int jumlah;
    int tertinggi = -1;
    int terendah = 1000;
    int total = 0;

    cout << "Jumlah Mahasiswa : ";
    jumlah = jumlahMahasiswa(jumlah);

    int nilai[jumlah];

    for(int i = 0; i < jumlah; i++){
        cout << "Nilai Mahasiswa Ke-" << i + 1 << " : ";
        nilaiMahasiswa(nilai, i);
        TinggiRendah(nilai[i], total, tertinggi, terendah);
    }

    float rata;
    rata = ratarata(total, jumlah);

    hasil(tertinggi, terendah, rata);

    return 0;
}