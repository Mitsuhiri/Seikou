#include<iostream>
using namespace std;

int tambah(int a, int b){
    return a + b;
}

int kurang(int a, int b){
    return a - b;
}

int kali(int a, int b){
    return a * b;
}

int bagi(int a, int b){
    return a / b;
}

int main(){
    int a;
    int b;
    char operasi;

    cout << "masukan angka pertama : ";
    cin >> a;
    cout << "masukan operasi(+-/*) : ";
    cin >> operasi;
    cout << "masukan angka kedua : ";
    cin >> b;
    switch (operasi){
        case '+':
            cout << "hasil = " <<  tambah(a, b);
            break;
        case '-':
            cout << "hasil = " <<  kurang(a, b);
            break;
        case '*':
            cout << "hasil = " <<  kali(a, b);
            break;
        case '/':
            cout << "hasil = " << bagi(a, b);
            break;
    default:
        cout << "operasi tidak valid.";
    }
    return 0;
}
