#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void inisialisasiPapan(char papan[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            papan[i][j] = ' ';
        }
    }
}

void cetakPapan(char papan[3][3]){
    cout << "   K1  K2  K3\n";
    cout << "B1 " << papan[0][0] << " | " << papan[0][1] << " | " << papan[0][2] << "\n";
    cout << "   --+---+--\n";
    cout << "B2 " << papan[1][0] << " | " << papan[1][1] << " | " << papan[1][2] << "\n";
    cout << "   --+---+--\n";
    cout << "B3 " << papan[2][0] << " | " << papan[2][1] << " | " << papan[2][2] << "\n";
}

void isiPapan(char papan[3][3], char pemain){
    int baris, kolom;
    bool valid = false;

    while(!valid){

        cetakPapan(papan);

        cout << "Giliran Pemain [" << pemain << "]\n";
        cout << "Baris : ";
        cin >> baris;
        cout << "Kolom : ";
        cin >> kolom;

        if(baris < 1 || baris > 3 || kolom < 1 || kolom > 3){
            cout << "\narea diluar jangkauan!!\n\n";
        } else if(papan[baris - 1][kolom - 1] != ' '){
            cout << "\nkolom sudah terisi!!\n\n";
        } else{
            papan[baris - 1][kolom - 1] = pemain;
            valid = true;
        }
    }
}

char pemainPertama(){
    int pertama = rand() % 2;
    if(pertama == 1){
        return 'X';
    } else{
        return 'O';
    }
}

char gantiPemain(char pemain){
    if(pemain == 'X'){
        return 'O';
    } else{
        return 'X';
    }
}

bool cekMenang(char papan[3][3], char pemain){
    for(int i = 0; i < 3; i++){
        if(papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain){
            return true;
        }
        if(papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain){
            return true;
        }
    }
    if(papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain){
        return true;
    }
    if(papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain){
        return true;
    }
    return false;
}

bool cekSeri(char papan[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(papan[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

int main(){
    srand(time(0));
    char pemain = pemainPertama();
    char papan[3][3];

    inisialisasiPapan(papan);

    while(true){
        isiPapan(papan, pemain);

        if(cekMenang(papan, pemain)){
            cetakPapan(papan);
            cout << "Pemain [" << pemain << "] Menang!!";
            break;
        }
        if(cekSeri(papan)){
            cetakPapan(papan);
            cout << "Game Seri!!";
            break;
        }
        pemain = gantiPemain(pemain);
    }
    return 0;
}