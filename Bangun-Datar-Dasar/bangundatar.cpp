#include<iostream>
using namespace std;

int main(){
    int tinggi;
    int lebar;
    char simbol;
    cin >> tinggi;
    cin >> lebar;
    cin >> simbol;

    for(int i = 1; i <= tinggi; i++){
        for(int j = 1; j <= tinggi - 1; j++){
            cout << " ";
        }
        for(int k = 1; k <= ((2 * i) - 1); k++){
            cout << simbol;
        }
    cout << "\n";
}
    return 0;
}   