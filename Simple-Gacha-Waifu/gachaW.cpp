/*
Game Gacha waifu dengan fitur :
1. Gacha waifu 1x/10x
2. Buka inventory waifu
3. Ceraikan waifu
4. Buka List waifu
5. Buka Statistik
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
// Waifu 2.2
#pragma region Database_waifu
struct waifu{
    string name;
    string rarity;
};

waifu common[] = { // List waifu common
    {"Sakura Haruno", "Common"},
    {"Anzu Hoshino", "Common"},
    {"Tenten", "Common"},
    {"Mako Mankanshoku", "Common"},
    {"Tsuyu Asui", "Common"},
    {"Sasha Blouse", "Common"},
    {"Miyuki Shirogane", "Common"},
    {"Sakura Matou", "Common"},
    {"Miko Iino", "Common"},
    {"Kallen Stadtfeld", "Common"},
    {"Mem-Cho", "Common"},
};

waifu uncommon[] = { // List waifu uncommon
    {"Uraraka Ochako", "Uncommon"},
    {"Nobara Kugisaki", "Uncommon"},
    {"Kanao Tsuyuri", "Uncommon"},
    {"Lucy Heartfilia", "Uncommon"},
    {"Mai Sakurajima", "Uncommon"},
    {"Yotsuba Nakano", "Uncommon"},
    {"Momo Yaoyorozu", "Uncommon"},
    {"Aiz Wallenstein", "Uncommon"},
    {"Tohka Yatogami", "Uncommon"},
    {"Ichinose Honami", "Uncommon"},
    {"Fubuki", "Uncommon"},
};

waifu rare[] = { // List waifu rare
    {"Asuka Langley Soryu", "Rare"},
    {"Rin Tohsaka", "Rare"},
    {"Yor Forger", "Rare"},
    {"Ram", "Rare"},
    {"Tsunade", "Rare"},
    {"Maki Zenin", "Rare"},
    {"Hestia", "Rare"},
    {"Maomao", "Rare"},
    {"Ubel", "Rare"},
    {"Ruby Hoshino", "Rare"},
    {"Eris Boreas Greyrat", "Rare"},
    {"Tatsumaki", "Rare"},
};

waifu legendary[] = { // List waifu legendary
    {"Power", "Legendary"},
    {"Kaguya Shinomiya", "Legendary"},
    {"Emilia", "Legendary"},
    {"Kurumi Tokisaki", "Legendary"},
    {"Nami", "Legendary"},
    {"Miku Nakano", "Legendary"},
    {"Albedo", "Legendary"},
    {"Ryo Yamada", "Legendary"},
    {"Fern", "Legendary"},
    {"Roxy Migurdia", "Legendary"},
};

waifu mythical[] = { // List waifu mythical
    {"Saber (Artoria Pendragon)", "Mythical"},
    {"Zero Two", "Mythical"},
    {"Rem", "Mythical"},
    {"Asuna", "Mythical"},
    {"Makima", "Mythical"},
    {"Violet Evergarden", "Mythical"},
    {"Frieren", "Mythical"},
    {"Bocchi", "Mythical"},
    {"Hoshino Ai", "Mythical"},
    {"Sylphiette", "Mythical"},
};

const int jumlahCommon = size(common);
const int jumlahUncommon = size(uncommon);
const int jumlahRare = size(rare);
const int jumlahLegendary = size(legendary);
const int jumlahMythical = size(mythical);

#pragma endregion
// Fungsi untuk cek waifu yang sudah punya
bool cekDuplikat(string name, waifu inventory[], int jumlahWaifu){
    for(int i = 0;i < jumlahWaifu; i++){ // Mengecek waifu 1 per 1 yang ada di inventory
        if(inventory[i].name == name){
            return true; // Ketika waifu yang didapat ada yang sama dengan yang di inventory, fungsi langsung menyatakan true
        }
    } 
    return false;
}
// Funsi untuk menambahkan waifu ke inventory
void tambahKeInventory(string name,string rarity, waifu inventory[], int &jumlahWaifu, int &gems, int &totalDuplikat){
    if(cekDuplikat(name, inventory, jumlahWaifu)){ // Dijalankan ketika fungsi cekDuplikat bersifat true
        int reward = 0;

        if(rarity == "Common"){
            reward = 50;

        } else if(rarity == "Uncommon"){
            reward = 75;

        } else if(rarity == "Rare"){
            reward = 125;

        } else if(rarity == "Legendary"){
            reward = 200;

        } else if(rarity == "Mythical"){
            reward = 300;

        }
        gems = gems + reward;

        cout << "\n";
        cout << "-----------------------------------------\n";
        cout << "  Duplikat!\n";
        cout << "  " << name << "-mu Terkonversi menjadi " << reward << " Gems!\n";
        cout << "-----------------------------------------\n\n";

        totalDuplikat++;
    } else{ // Dijalankan ketika fungsi cekDuplikat bersifat false
        inventory[jumlahWaifu].name = name;
        inventory[jumlahWaifu].rarity = rarity;
        jumlahWaifu++;
        cout << "  Waifu Barumu Masuk Ke inventory!\n";
        cout << "----------------------------------------\n";
    }
}
// Fungsi utama untuk gacha waifu
void gacha(waifu inventory[], int &jumlahWaifu, int &gems,const int harga, int &totalGacha, int &totalDuplikat){
    
    if(gems < harga){ // Mengecek perbandingan antara gems dan harga gacha
        cout << "  Gems tidak Cukup\n";
        cout << "  Miskin lu\n";

    } else{ // Dijalankan ketika gems lebih besar dari harga atau false
        gems -= harga;
        int roll = rand() % 100 + 1; // Sistem gacha utama dari 1 sampai 100

        if(roll <= 60){
            int randomIndex = rand() % jumlahCommon; // Sistem gacha dengan ruang lingkup jumlahCommon
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << common[randomIndex].name << "\n";
            cout << "       [" << common[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(common[randomIndex].name, common[randomIndex].rarity, inventory, jumlahWaifu, gems, totalDuplikat);
        } else if(roll <= 85){
            int randomIndex = rand() % jumlahUncommon; // Sistem gacha dengan ruang lingkup jumlahUnommon
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << uncommon[randomIndex].name << "\n";
            cout << "       [" << uncommon[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(uncommon[randomIndex].name, uncommon[randomIndex].rarity, inventory, jumlahWaifu, gems, totalDuplikat);
        } else if(roll <= 95){
            int randomIndex = rand() % jumlahRare; // Sistem gacha dengan ruang lingkup jumlahRare
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << rare[randomIndex].name << "\n";
            cout << "       [" << rare[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(rare[randomIndex].name, rare[randomIndex].rarity, inventory, jumlahWaifu, gems, totalDuplikat);
        } else if(roll <= 99){
            int randomIndex = rand() % jumlahLegendary; // Sistem gacha dengan ruang lingkup jumlahLegendary
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << legendary[randomIndex].name << "\n";
            cout << "       [" << legendary[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(legendary[randomIndex].name,legendary[randomIndex].rarity, inventory, jumlahWaifu, gems, totalDuplikat);
        } else if(roll <=100){
            int randomIndex = rand() % jumlahMythical; // Sistem gacha dengan ruang lingkup jumlahMythical
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << mythical[randomIndex].name << "\n";
            cout << "       [" << mythical[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(mythical[randomIndex].name, mythical[randomIndex].rarity, inventory, jumlahWaifu, gems, totalDuplikat);
        }
        totalGacha++;
    }
}
// Funsi untuk membuka waifu yang sudah punya
void fungsiInventory(waifu inventory[],int jumlahWaifu){
    cout << "\n";
    cout << "==============================\n";
    cout << "\tList Waifumu \n";
    cout << "==============================\n";

    if(jumlahWaifu == 0){ //Dijalankan ketika tidak punya waifu
        cout << "  Kamu Belum Punya Waifu 1 pun..\n\n";
    } else{ // Dijalankan ketika mempunyai waifu minimal 1
        for (int i = 0; i < jumlahWaifu; i++){
            cout << i + 1 << ". " << inventory[i].name << " [" << inventory[i].rarity << "]\n";
        }
    }
}
// Fungsi untuk mengecek berapa waifu yang sudah dimiliki
int jumlahDimiliki(waifu database[], int jumlahDatabase, waifu inventory[], int jumlahWaifu){
    int jumlah = 0;

    for(int i = 0; i < jumlahDatabase; i++){
        if(cekDuplikat(database[i].name, inventory, jumlahWaifu)){
            jumlah++;
        }
    }
    return jumlah;
}
// Fungsi untuk membuka list waifu di Database Waifu
void listRarity(waifu inventory[], int jumlahWaifu){
    cout << "\n";
    cout << "==============================\n";
    cout << "\tCommon(60%)\n";
    cout << "==============================\n";

    for(int i = 0; i < jumlahCommon; i++){
        if(cekDuplikat(common[i].name, inventory, jumlahWaifu)){
            cout << i + 1 << ". " << common[i].name << "\n";
        } else {
            cout << i + 1 << ". ???\n";
        }
    }

    cout << "\n";
    cout << "==============================\n";
    cout << "\tUncommon(25%)\n";
    cout << "==============================\n";

    for(int i = 0; i < jumlahUncommon; i++){
        if(cekDuplikat(uncommon[i].name, inventory, jumlahWaifu)){
            cout << i + 1 << ". " << uncommon[i].name << "\n";
        } else {
            cout << i + 1 << ". ???\n";
        }
    }

    cout << "\n";
    cout << "==============================\n";
    cout << "\tRare(10%)\n";
    cout << "==============================\n";

    for(int i = 0; i < jumlahRare; i++){
        if(cekDuplikat(rare[i].name, inventory, jumlahWaifu)){
            cout << i + 1 << ". " << rare[i].name << "\n";
        } else {
            cout << i + 1 << ". ???\n";
        }
    }

    cout << "\n";
    cout << "==============================\n";
    cout << "\tLegendary(4%)\n";
    cout << "==============================\n";

    for(int i = 0; i < jumlahLegendary; i++){
        if(cekDuplikat(legendary[i].name, inventory, jumlahWaifu)){
            cout << i + 1 << ". " << legendary[i].name << "\n";
        } else {
            cout << i + 1 << ". ???\n";
        }
    }

    cout << "\n";
    cout << "==============================\n";
    cout << "\tMythical(1%)\n";
    cout << "==============================\n";

    for(int i = 0; i < jumlahMythical; i++){
        if(cekDuplikat(mythical[i].name, inventory, jumlahWaifu)){
            cout << i + 1 << ". " << mythical[i].name << "\n";
        } else {
            cout << i + 1 << ". ???\n";
        }
    }
    cout << "\n";
}
// Fungsi untuk menghapus waifu dari inventory
void cerai(waifu inventory[], int &jumlahWaifu, int &gems){
    
    int reward = 0;
    int nomor;

    if(jumlahWaifu == 0){
        cout << "\n";
        cout << "========================================\n";
        cout << "             Ceraikan Waifu\n";
        cout << "========================================\n";
        cout << "  Kamu Belum Punya Waifu 1 pun...\n\n";

    } else{
        cout << "\n";
        cout << "========================================\n";
        cout << "             Ceraikan Waifu\n";
        cout << "========================================\n";

        for (int i = 0; i < jumlahWaifu; i++){
            cout << "  [" <<i + 1 << "]" << inventory[i].name << " [" << inventory[i].rarity << "] - ";
            if(inventory[i].rarity == "Common"){
                reward = 50;

            } else if(inventory[i].rarity == "Uncommon"){
                reward = 100;

            } else if(inventory[i].rarity == "Rare"){
                reward = 175;

            } else if(inventory[i].rarity == "Legendary"){
                reward = 300;

            } else if(inventory[i].rarity == "Mythical"){
                reward = 500;
            }
            cout << reward << "Gems\n";
        }
    
        cout << "----------------------------------------\n";
        cout << "  Pilih 0 untuk batal\n";
        cout << "  Pilih waifu yang ingin diceraikan: ";
        cin >> nomor;

        if(nomor < 0 || nomor > jumlahWaifu){
            cout << "  Pilihan Tidak Valid.\n";
            return;
        } else if(nomor == 0){
            cout << "  Perceraian Dibatalkan\n";
        } else{
            int list = nomor - 1;
            int hargaCerai = 0;

            if(inventory[list].rarity == "Common"){
                hargaCerai = 50;
            } else if(inventory[list].rarity == "Uncommon"){
                hargaCerai = 100;

            } else if(inventory[list].rarity == "Rare"){
                hargaCerai = 175;

            } else if(inventory[list].rarity == "Legendary"){
                hargaCerai = 300;

            } else if(inventory[list].rarity == "Mythical"){
                hargaCerai = 500;
            }

            cout << "\n";
            cout << "----------------------------------------\n";
            cout << "  " << inventory[list].name << " Berhasil Dicerakan!\n";
            cout << "  Kamu Mendapatkan " << hargaCerai << "Gems\n";
            cout << "----------------------------------------\n";

            gems += hargaCerai;

            for(int i = list; i < jumlahWaifu - 1; i++){
                inventory[i] = inventory[i + 1];
            }
            
            jumlahWaifu--;
        }
    }
}
// Fungsi untuk membuka Statistik
void statistik(waifu inventory[], int jumlahWaifu, int gems, int totalGacha, int totalDuplikat){

    int dimilikiCommon = jumlahDimiliki(common, jumlahCommon, inventory, jumlahWaifu);
    int dimilikiUncommon = jumlahDimiliki(uncommon, jumlahUncommon, inventory, jumlahWaifu);
    int dimilikiRare = jumlahDimiliki(rare, jumlahRare, inventory, jumlahWaifu);
    int dimilikiLegendary = jumlahDimiliki(legendary, jumlahLegendary, inventory, jumlahWaifu);
    int dimilikiMythical = jumlahDimiliki(mythical, jumlahMythical, inventory, jumlahWaifu);

    cout << "\n";
    cout << "========================================\n";
    cout << "\t\tSTATISTIK\n";
    cout << "========================================\n";
    cout << "  Total Gacha      : " << totalGacha << "\n";
    cout << "  Waifu Dimiliki   : " << jumlahWaifu << "\n";
    cout << "  Duplikat         : " << totalDuplikat << "\n";
    cout << "  Gems             : " << gems << "\n";
    cout << "----------------------------------------\n";
    cout << "  Common    : " << dimilikiCommon << "/" << jumlahCommon << "\n";
    cout << "  Uncommon  : " << dimilikiUncommon << "/" << jumlahUncommon << "\n";
    cout << "  Rare      : " << dimilikiRare << "/" << jumlahRare << "\n";
    cout << "  Legendary  : " << dimilikiLegendary << "/" << jumlahLegendary << "\n";
    cout << "  Mythical   : " << dimilikiMythical << "/" << jumlahMythical << "\n";
    cout << "========================================\n";
}
// Fungsi untuk menampilkan menu
int menu(int pilihan, int gems){
    cout << "\n";
    cout << "+=======================================+\n";
    cout << "        >----{ GACHA WAIFU }----<        \n";
    cout << "+=======================================+\n";
    cout << "  Gems kamu : " << gems << "\n";
    cout << "  100 Gems/Gacha\n";  
    cout << "-----------------------------------------\n";
    cout << "  [1] Gacha Waifu\n";
    cout << "  [2] Gacha Waifu 10x\n";
    cout << "  [3] Inventory\n";
    cout << "  [4] Ceraikan Waifu\n";
    cout << "  [5] List Waifu\n";
    cout << "  [6] Statistik\n";
    cout << "  [7] Keluar\n";
    cout << "-----------------------------------------\n";
    cout << "  Pilihanmu(1-6) : ";
    cin >> pilihan;
    return pilihan;

}
// Fungsi utama untuk menjalankan fungsi-fungsi lainnya
int main (){

    srand(time(0));
    string name;
    string rarity;
    waifu inventory[1000];
    const int harga = 100;
    int pilihan;
    int gems = 10000;
    int jumlahWaifu = 0;
    int totalGacha = 0;
    int totalDuplikat = 0;

    do{
        pilihan = menu(pilihan, gems);

        if(pilihan == 1){
            gacha(inventory, jumlahWaifu, gems, harga, totalGacha, totalDuplikat);

        }else if(pilihan == 2){
            if(gems < harga * 10){
                cout << "  Gems tidak Cukup\n";
                cout << "  Miskin lu\n";
            } else{
                for(int i = 1; i <=10;i++){
                    gacha(inventory, jumlahWaifu, gems, harga, totalGacha, totalDuplikat);
                }
            }   

        }else if(pilihan == 3){
            fungsiInventory(inventory, jumlahWaifu);

        }else if(pilihan == 4){
            cerai(inventory, jumlahWaifu, gems);

        }else if(pilihan == 5){
            listRarity(inventory, jumlahWaifu);
        
        }else if(pilihan == 6){
            statistik(inventory, jumlahWaifu, gems, totalGacha, totalDuplikat);

        }else if(pilihan == 7){
            cout << "  Program Ditutup";

        }else {
            cout << "  Pilih yang bener tot";
        }
    } while (pilihan != 7);
    return 0;
}