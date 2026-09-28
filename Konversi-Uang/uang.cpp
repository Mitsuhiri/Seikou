#include<iostream>
using namespace std;

int main(){
    float rp, usd, jyp, eur, sgd;
    int pilihan;

    cout << "Pilih Mata Uang: \n";
    cout << "1. Rupiah(Indonesia)\n";
    cout << "2. USD(Dolar Amerika)\n";
    cout << "3. Yen(Jepang)\n";
    cout << "4. Euro(Eropa)\n";
    cout << "5. SGD(Dolar Singapura)\n";
    cout << "Masukkan pilihan Anda(1-5): ";
    cin >> pilihan;

    switch(pilihan){
        case 1:
            cout << "Masukkan jumlah Rupiah: ";
            cin >> rp;
            usd = rp / 15000;
            jyp = rp / 130;
            eur = rp / 17000;
            sgd = rp / 11000;
            cout << "USD\t: " << usd << endl;
            cout << "JPY\t: " << jyp << endl;
            cout << "EUR\t: " << eur << endl;
            cout << "SGD\t: " << sgd << endl;
            break;

        case 2:
            cout << "Masukkan jumlah USD: ";
            cin >> usd;
            rp = usd * 15000;
            jyp = usd * 110;
            eur = usd * 0.85;
            sgd = usd * 1.35;
            cout << "Rupiah\t: " << rp << endl;
            cout << "JPY\t: " << jyp << endl;
            cout << "EUR\t: " << eur << endl;
            cout << "SGD\t: " << sgd << endl;
            break;

        case 3:
            cout << "Masukkan jumlah JPY: ";
            cin >> jyp;
            rp = jyp * 130;
            usd = jyp / 110;
            eur = jyp * 0.0077;
            sgd = jyp * 0.0123;
            cout << "Rupiah\t: " << rp << endl;
            cout << "USD\t: " << usd << endl;
            cout << "EUR\t: " << eur << endl;
            cout << "SGD\t: " << sgd << endl;
            break;

        case 4:
            cout << "Masukkan jumlah EUR: ";
            cin >> eur;
            rp = eur * 17000;
            usd = eur / 0.85;
            jyp = eur * 130.5;
            sgd = eur * 1.59;
            cout << "Rupiah: " << rp << endl;
            cout << "USD: " << usd << endl;
            cout << "JPY: " << jyp << endl;
            cout << "SGD: " << sgd << endl;
            break;

        case 5:
            cout << "Masukkan jumlah SGD: ";
            cin >> sgd;
            rp = sgd * 11000;
            usd = sgd / 1.35;
            jyp = sgd * 81.3;
            eur = sgd / 1.59;
            cout << "Rupiah: " << rp << endl;
            cout << "USD: " << usd << endl;
            cout << "JPY: " << jyp << endl;
            cout << "EUR: " << eur << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
}