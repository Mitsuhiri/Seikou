#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cctype>
using namespace std;

string kataRandom(){
    string random[] = {
        "APPLE",
        "CHAIR",
        "BEACH",
        "DANCE",
        "FLAME",
        "GRAPE",
        "HOUSE",
        "JUICE",
        "KNIFE",
        "EAGLE",
    };

    const int jumlahKata = size(random);

    int acak = rand() % jumlahKata;
    return random[acak];
}

string hijau  = "\033[42m\033[30m";
string kuning = "\033[43m\033[30m";
string abu    = "\033[100m\033[37m";
string reset  = "\033[0m";

string inputKata(){
    string input;
    cin >> input;

    for(char &c : input){
    c = toupper(c);
}

    if(input.length() != 5){
        cout << "Jumlah huruf harus 5!\n";
        cout << "Jawab : ";
        return inputKata();
    }
    return input;
}

void cekInput(string input, string jawaban){

    bool sudahDipakai[5] = {false, false, false, false, false};
    int hasil[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < jawaban.length(); i++){
        if(jawaban[i] == input[i]){
            hasil[i] = 2;
            sudahDipakai[i] = true;
        }
    }
    
    for(int i = 0; i < jawaban.length(); i++){
        if(hasil[i] == 2){
            continue;
        }
        for(int j = 0; j < 5; j++){
            if(!sudahDipakai[j] && input[i] == jawaban[j]){
                hasil[i] = 1;
                sudahDipakai[j] = true;
                break;
            }
        }
    }

    for(int i = 0; i < jawaban.length(); i++){
        if(hasil[i] == 2){
            cout << hijau << " " << input[i] << " " << reset;
        } else if(hasil[i] == 1){
            cout << kuning << " " << input[i] << " " << reset;
        } else{
            cout << abu << " " << input[i] << " " << reset;
        }
    }
    cout << "\n";
}

void wordle(string jawaban, int kesempatan){

    if(kesempatan == 0){
        cout << "Kamu kalah!\n";
        cout << "Jawabannya adalah " << jawaban;
        return;
    }

    cout << "Kesempatan = " << kesempatan << "\n";
    cout << "Jawab : ";
    string input = inputKata();

    cekInput(input, jawaban);
        if(input == jawaban){
            cout << "Kamu Menang!\n";
            return;
            
        }else{
            cout << "Jawaban Salah\n";
        }
    cout << "Sisa Kesempatan : "<< kesempatan - 1 << "\n";
    wordle(jawaban, kesempatan - 1);
}

int main(){
    srand(time(0));
    int kesempatan = 6;

    string jawaban = kataRandom();
    wordle(jawaban, kesempatan);
    return 0;
}