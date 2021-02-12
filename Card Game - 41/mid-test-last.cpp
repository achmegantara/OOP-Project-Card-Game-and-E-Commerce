#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class Empatsatu{
	private:
	int card[52];
	int kartu_pemain[6][6];
	int deck_buang[2];
	int nilai_pemain[6];
	int jumlah_kartu[4];
	int kode[6][4];
	int hasil_jumlah[6];
	int nilai_konversi[6][4];

	
	public:
	int jumlah_pemain;
	char mulai_main;
	int turn;
	int buang_kartu;
	string aksi;
	int index;
	int ambilkartu;
	int giliran;
	int hasil_pemain;
	int maksimal;
	int indeks_maksimal;
	int nilaikode;
	int hati=0, wajik=0, kriting=0, waru=0;
	
	//membuat constructor
	Empatsatu(){
		cout << "Selamat datang di permainan 41" << endl;
		cout << "-------------------------------" << endl;
	}
	//memasukkan nilai pada decc kartu
	void inputkartu(){
		for(int a=0; a<52; a++){
			card[a] = (a+1);
		}
	}
	//menampilkan semua kartu
	void show_semuakartu(){
		for(int b=0; b<52; b++){
			cout << card[b] << " ";
		}
		cout << endl;
	}
	//shuffling card
	void shuffle(){
		cout << "Proses pengacakan kartu..." << endl;
		int temp[52];
		int randomIndex = 0;
		srand(time(0));
		for(int c=0; c<52; c++){
		randomIndex = rand()%52;
		temp[c] = card[c];
		card[c] = card[randomIndex];
		card[randomIndex]=temp[c];
		}
	}
	//dealing card for each player
	void dealkartu(){
		int d=0;
		for(int e=0; e<jumlah_pemain; e++){
		for(int f=0; f<=3; f++){
			kartu_pemain[e][f] = card[d];
			d++;
		}}	
	}
	//show 5 kartu
	void show_limakartu(){
		cout << "Kartu anda saat ini adalah : ";
			string* namakartu = new string[5];
		
		int urutanz = 0;
		for(int x=0; x<=4; x++){
			if(kartu_pemain[giliran][x] == 1){ namakartu[urutanz] = "As hati"; }
			else if (kartu_pemain[giliran][x] == 2){ namakartu[urutanz] = "2 hati"; }
			else if (kartu_pemain[giliran][x] == 3){ namakartu[urutanz] = "3 hati";}
			else if (kartu_pemain[giliran][x] == 4){ namakartu[urutanz] = "4 hati";}
			else if (kartu_pemain[giliran][x] == 5){ namakartu[urutanz] = "5 hati";}
			else if (kartu_pemain[giliran][x] == 6){ namakartu[urutanz] = "6 hati";}
			else if (kartu_pemain[giliran][x] == 7){ namakartu[urutanz] = "7 hati";}
			else if (kartu_pemain[giliran][x] == 8){ namakartu[urutanz] = "8 hati";}
			else if (kartu_pemain[giliran][x] == 9){ namakartu[urutanz] = "9 hati";}
			else if (kartu_pemain[giliran][x] == 10){ namakartu[urutanz] = "10 hati";}
			else if (kartu_pemain[giliran][x] == 11){ namakartu[urutanz] = "jack hati";}
			else if (kartu_pemain[giliran][x] == 12){ namakartu[urutanz] = "queen hati";}
			else if (kartu_pemain[giliran][x] == 13){ namakartu[urutanz] = "king hati";}
			else if (kartu_pemain[giliran][x] == 14){ namakartu[urutanz] = "Ace wajik";}
			else if (kartu_pemain[giliran][x] == 15){ namakartu[urutanz] = "2 wajik";}
			else if (kartu_pemain[giliran][x] == 16){ namakartu[urutanz] = "3 wajik";}
			else if (kartu_pemain[giliran][x] == 17){ namakartu[urutanz] = "4 wajik";}
			else if (kartu_pemain[giliran][x] == 18){ namakartu[urutanz] = "5 wajik";}
			else if (kartu_pemain[giliran][x] == 19){ namakartu[urutanz] = "6 wajik";}
			else if (kartu_pemain[giliran][x] == 20){ namakartu[urutanz] = "7 wajik";}
			else if (kartu_pemain[giliran][x] == 21){ namakartu[urutanz] = "8 wajik";}
			else if (kartu_pemain[giliran][x] == 22){ namakartu[urutanz] = "9 wajik";}
			else if (kartu_pemain[giliran][x] == 23){ namakartu[urutanz] = "10 wajik";}
			else if (kartu_pemain[giliran][x] == 24){ namakartu[urutanz] = "jack wajik";}
			else if (kartu_pemain[giliran][x] == 25){ namakartu[urutanz] = "queen wajik";}
			else if (kartu_pemain[giliran][x] == 26){ namakartu[urutanz] = "king wajik";}
			else if (kartu_pemain[giliran][x] == 27){ namakartu[urutanz] = "Ace kriting";}
			else if (kartu_pemain[giliran][x] == 28){ namakartu[urutanz] = "2 kriting";}
			else if (kartu_pemain[giliran][x] == 29){ namakartu[urutanz] = "3 kriting";}
			else if (kartu_pemain[giliran][x] == 30){ namakartu[urutanz] = "4 kriting";}
			else if (kartu_pemain[giliran][x] == 31){ namakartu[urutanz] = "5 kriting";}
			else if (kartu_pemain[giliran][x] == 32){ namakartu[urutanz] = "6 kriting";}
			else if (kartu_pemain[giliran][x] == 33){ namakartu[urutanz] = "7 kriting";}
			else if (kartu_pemain[giliran][x] == 34){ namakartu[urutanz] = "8 kriting";}
			else if (kartu_pemain[giliran][x] == 35){ namakartu[urutanz] = "9 kriting";}
			else if (kartu_pemain[giliran][x] == 36){ namakartu[urutanz] = "10 kriting";}
			else if (kartu_pemain[giliran][x] == 37){ namakartu[urutanz] = "jack kriting";}
			else if (kartu_pemain[giliran][x] == 38){ namakartu[urutanz] = "queen kriting";}
			else if (kartu_pemain[giliran][x] == 39){ namakartu[urutanz] = "king kriting";}
			else if (kartu_pemain[giliran][x] == 40){ namakartu[urutanz] = "Ace waru";}
			else if (kartu_pemain[giliran][x] == 41){ namakartu[urutanz] = "2 waru";}
			else if (kartu_pemain[giliran][x] == 42){ namakartu[urutanz] = "3 waru";}
			else if (kartu_pemain[giliran][x] == 43){ namakartu[urutanz] = "4 waru";}
			else if (kartu_pemain[giliran][x] == 44){ namakartu[urutanz] = "5 waru";}
			else if (kartu_pemain[giliran][x] == 45){ namakartu[urutanz] = "6 waru";}
			else if (kartu_pemain[giliran][x] == 46){ namakartu[urutanz] = "7 waru";}
			else if (kartu_pemain[giliran][x] == 47){ namakartu[urutanz] = "8 waru";}
			else if (kartu_pemain[giliran][x] == 48){ namakartu[urutanz] = "9 waru";}
			else if (kartu_pemain[giliran][x] == 49){ namakartu[urutanz] = "10 waru";}
			else if (kartu_pemain[giliran][x] == 50){ namakartu[urutanz] = "jack waru";}
			else if (kartu_pemain[giliran][x] == 51){ namakartu[urutanz] = "queen waru";}
			else if (kartu_pemain[giliran][x] == 52){ namakartu[urutanz] = "king waru";}
			urutanz++;
			}
			
				for(int yyx=0; yyx<=4; yyx++){
				cout << namakartu[yyx] << ", ";
			}
		
		cout<<endl;
	}
	//show 4 kartu
	void show_empatkartu(){
		cout << "Kartu anda saat ini adalah : ";
		
		string* namakartu = new string[5];
		int urutanz = 0;
		for(int x=0; x<=4; x++){
			if(kartu_pemain[giliran][x] == 1){ namakartu[urutanz] = "As hati"; }
			else if (kartu_pemain[giliran][x] == 2){ namakartu[urutanz] = "2 hati"; }
			else if (kartu_pemain[giliran][x] == 3){ namakartu[urutanz] = "3 hati";}
			else if (kartu_pemain[giliran][x] == 4){ namakartu[urutanz] = "4 hati";}
			else if (kartu_pemain[giliran][x] == 5){ namakartu[urutanz] = "5 hati";}
			else if (kartu_pemain[giliran][x] == 6){ namakartu[urutanz] = "6 hati";}
			else if (kartu_pemain[giliran][x] == 7){ namakartu[urutanz] = "7 hati";}
			else if (kartu_pemain[giliran][x] == 8){ namakartu[urutanz] = "8 hati";}
			else if (kartu_pemain[giliran][x] == 9){ namakartu[urutanz] = "9 hati";}
			else if (kartu_pemain[giliran][x] == 10){ namakartu[urutanz] = "10 hati";}
			else if (kartu_pemain[giliran][x] == 11){ namakartu[urutanz] = "jack hati";}
			else if (kartu_pemain[giliran][x] == 12){ namakartu[urutanz] = "queen hati";}
			else if (kartu_pemain[giliran][x] == 13){ namakartu[urutanz] = "king hati";}
			else if (kartu_pemain[giliran][x] == 14){ namakartu[urutanz] = "Ace wajik";}
			else if (kartu_pemain[giliran][x] == 15){ namakartu[urutanz] = "2 wajik";}
			else if (kartu_pemain[giliran][x] == 16){ namakartu[urutanz] = "3 wajik";}
			else if (kartu_pemain[giliran][x] == 17){ namakartu[urutanz] = "4 wajik";}
			else if (kartu_pemain[giliran][x] == 18){ namakartu[urutanz] = "5 wajik";}
			else if (kartu_pemain[giliran][x] == 19){ namakartu[urutanz] = "6 wajik";}
			else if (kartu_pemain[giliran][x] == 20){ namakartu[urutanz] = "7 wajik";}
			else if (kartu_pemain[giliran][x] == 21){ namakartu[urutanz] = "8 wajik";}
			else if (kartu_pemain[giliran][x] == 22){ namakartu[urutanz] = "9 wajik";}
			else if (kartu_pemain[giliran][x] == 23){ namakartu[urutanz] = "10 wajik";}
			else if (kartu_pemain[giliran][x] == 24){ namakartu[urutanz] = "jack wajik";}
			else if (kartu_pemain[giliran][x] == 25){ namakartu[urutanz] = "queen wajik";}
			else if (kartu_pemain[giliran][x] == 26){ namakartu[urutanz] = "king wajik";}
			else if (kartu_pemain[giliran][x] == 27){ namakartu[urutanz] = "Ace kriting";}
			else if (kartu_pemain[giliran][x] == 28){ namakartu[urutanz] = "2 kriting";}
			else if (kartu_pemain[giliran][x] == 29){ namakartu[urutanz] = "3 kriting";}
			else if (kartu_pemain[giliran][x] == 30){ namakartu[urutanz] = "4 kriting";}
			else if (kartu_pemain[giliran][x] == 31){ namakartu[urutanz] = "5 kriting";}
			else if (kartu_pemain[giliran][x] == 32){ namakartu[urutanz] = "6 kriting";}
			else if (kartu_pemain[giliran][x] == 33){ namakartu[urutanz] = "7 kriting";}
			else if (kartu_pemain[giliran][x] == 34){ namakartu[urutanz] = "8 kriting";}
			else if (kartu_pemain[giliran][x] == 35){ namakartu[urutanz] = "9 kriting";}
			else if (kartu_pemain[giliran][x] == 36){ namakartu[urutanz] = "10 kriting";}
			else if (kartu_pemain[giliran][x] == 37){ namakartu[urutanz] = "jack kriting";}
			else if (kartu_pemain[giliran][x] == 38){ namakartu[urutanz] = "queen kriting";}
			else if (kartu_pemain[giliran][x] == 39){ namakartu[urutanz] = "king kriting";}
			else if (kartu_pemain[giliran][x] == 40){ namakartu[urutanz] = "Ace waru";}
			else if (kartu_pemain[giliran][x] == 41){ namakartu[urutanz] = "2 waru";}
			else if (kartu_pemain[giliran][x] == 42){ namakartu[urutanz] = "3 waru";}
			else if (kartu_pemain[giliran][x] == 43){ namakartu[urutanz] = "4 waru";}
			else if (kartu_pemain[giliran][x] == 44){ namakartu[urutanz] = "5 waru";}
			else if (kartu_pemain[giliran][x] == 45){ namakartu[urutanz] = "6 waru";}
			else if (kartu_pemain[giliran][x] == 46){ namakartu[urutanz] = "7 waru";}
			else if (kartu_pemain[giliran][x] == 47){ namakartu[urutanz] = "8 waru";}
			else if (kartu_pemain[giliran][x] == 48){ namakartu[urutanz] = "9 waru";}
			else if (kartu_pemain[giliran][x] == 49){ namakartu[urutanz] = "10 waru";}
			else if (kartu_pemain[giliran][x] == 50){ namakartu[urutanz] = "jack waru";}
			else if (kartu_pemain[giliran][x] == 51){ namakartu[urutanz] = "queen waru";}
			else if (kartu_pemain[giliran][x] == 52){ namakartu[urutanz] = "king waru";}
			urutanz++;
			}
			
				for(int yyx=0; yyx<4; yyx++){
				cout << namakartu[yyx] << ", ";
			}
		
		cout << endl;
	}
	//otomatis ambil satu kartu dari deck utama untuk giliran pertama
	void buang_firstturn(){
		kartu_pemain[0][4] = card[index];
	}
	//buang satu kartu
	void buangkartu(){
		do{
		cout << "Pilih kartu yang anda buang (1-5) : "; cin >> buang_kartu;
		}while(buang_kartu<1 || buang_kartu>5);
		do{
		cout << "Pilih aksi selanjutnya (open/close) : "; cin >> aksi;
		}while(aksi != "open" && aksi != "Open" && aksi != "OPEN" && aksi != "close" && aksi != "Close" && aksi != "CLOSE");
		deck_buang[0] = kartu_pemain[giliran][buang_kartu-1];
		for(int i=buang_kartu-1; i<5; i++){
			kartu_pemain[giliran][i] = kartu_pemain[giliran][i+1];
		}
	}
	//mengambil kartu dari deck utama
	void ambiltengah(){
		kartu_pemain[giliran][4] = card[index];
		index = index+1;
	}
	//mengambil kartu terakhir dibuang
	void ambilteman(){
		kartu_pemain[giliran][4] = deck_buang[0];
	}
	//menampilkan kartu yang terakhir dibuang
	void terakhir_buang(){
			string* namakartu = new string[5]; 
			int urutanz = 0;
			if(deck_buang[0] == 1){ namakartu[urutanz] = "As hati"; }
			else if (deck_buang[0] == 2){ namakartu[urutanz] = "2 hati"; }
			else if (deck_buang[0] == 3){ namakartu[urutanz] = "3 hati";}
			else if (deck_buang[0] == 4){ namakartu[urutanz] = "4 hati";}
			else if (deck_buang[0] == 5){ namakartu[urutanz] = "5 hati";}
			else if (deck_buang[0] == 6){ namakartu[urutanz] = "6 hati";}
			else if (deck_buang[0] == 7){ namakartu[urutanz] = "7 hati";}
			else if (deck_buang[0] == 8){ namakartu[urutanz] = "8 hati";}
			else if (deck_buang[0] == 9){ namakartu[urutanz] = "9 hati";}
			else if (deck_buang[0] == 10){ namakartu[urutanz] = "10 hati";}
			else if (deck_buang[0] == 11){ namakartu[urutanz] = "jack hati";}
			else if (deck_buang[0] == 12){ namakartu[urutanz] = "queen hati";}
			else if (deck_buang[0] == 13){ namakartu[urutanz] = "king hati";}
			else if (deck_buang[0] == 14){ namakartu[urutanz] = "Ace wajik";}
			else if (deck_buang[0] == 15){ namakartu[urutanz] = "2 wajik";}
			else if (deck_buang[0] == 16){ namakartu[urutanz] = "3 wajik";}
			else if (deck_buang[0] == 17){ namakartu[urutanz] = "4 wajik";}
			else if (deck_buang[0] == 18){ namakartu[urutanz] = "5 wajik";}
			else if (deck_buang[0] == 19){ namakartu[urutanz] = "6 wajik";}
			else if (deck_buang[0] == 20){ namakartu[urutanz] = "7 wajik";}
			else if (deck_buang[0] == 21){ namakartu[urutanz] = "8 wajik";}
			else if (deck_buang[0] == 22){ namakartu[urutanz] = "9 wajik";}
			else if (deck_buang[0] == 23){ namakartu[urutanz] = "10 wajik";}
			else if (deck_buang[0] == 24){ namakartu[urutanz] = "jack wajik";}
			else if (deck_buang[0] == 25){ namakartu[urutanz] = "queen wajik";}
			else if (deck_buang[0] == 26){ namakartu[urutanz] = "king wajik";}
			else if (deck_buang[0] == 27){ namakartu[urutanz] = "Ace kriting";}
			else if (deck_buang[0] == 28){ namakartu[urutanz] = "2 kriting";}
			else if (deck_buang[0] == 29){ namakartu[urutanz] = "3 kriting";}
			else if (deck_buang[0] == 30){ namakartu[urutanz] = "4 kriting";}
			else if (deck_buang[0] == 31){ namakartu[urutanz] = "5 kriting";}
			else if (deck_buang[0] == 32){ namakartu[urutanz] = "6 kriting";}
			else if (deck_buang[0] == 33){ namakartu[urutanz] = "7 kriting";}
			else if (deck_buang[0] == 34){ namakartu[urutanz] = "8 kriting";}
			else if (deck_buang[0] == 35){ namakartu[urutanz] = "9 kriting";}
			else if (deck_buang[0] == 36){ namakartu[urutanz] = "10 kriting";}
			else if (deck_buang[0] == 37){ namakartu[urutanz] = "jack kriting";}
			else if (deck_buang[0] == 38){ namakartu[urutanz] = "queen kriting";}
			else if (deck_buang[0] == 39){ namakartu[urutanz] = "king kriting";}
			else if (deck_buang[0] == 40){ namakartu[urutanz] = "Ace waru";}
			else if (deck_buang[0] == 41){ namakartu[urutanz] = "2 waru";}
			else if (deck_buang[0] == 42){ namakartu[urutanz] = "3 waru";}
			else if (deck_buang[0] == 43){ namakartu[urutanz] = "4 waru";}
			else if (deck_buang[0] == 44){ namakartu[urutanz] = "5 waru";}
			else if (deck_buang[0] == 45){ namakartu[urutanz] = "6 waru";}
			else if (deck_buang[0] == 46){ namakartu[urutanz] = "7 waru";}
			else if (deck_buang[0] == 47){ namakartu[urutanz] = "8 waru";}
			else if (deck_buang[0] == 48){ namakartu[urutanz] = "9 waru";}
			else if (deck_buang[0]== 49){ namakartu[urutanz] = "10 waru";}
			else if (deck_buang[0] == 50){ namakartu[urutanz] = "jack waru";}
			else if (deck_buang[0] == 51){ namakartu[urutanz] = "queen waru";}
			else if (deck_buang[0] == 52){ namakartu[urutanz] = "king waru";}
			
		cout << "Kartu yang tearkhir dibuang : " << namakartu[0];
	}
	
	//menghitung nilai masing - masing pemain
	void hitung(){
		//menampilkan kartu masing - masing pemain
		cout << endl;
		string* namakartu = new string[24];
		
		int urutanz = 0;
		for(int y=0; y<jumlah_pemain; y++){
			cout << "kartu pemain ke - " << (y+1) << " ";
		for(int x=0; x<4; x++){
			if(kartu_pemain[y][x] == 1){ namakartu[urutanz] = "As hati"; }
			else if (kartu_pemain[y][x] == 2){ namakartu[urutanz] = "2 hati"; }
			else if (kartu_pemain[y][x] == 3){ namakartu[urutanz] = "3 hati";}
			else if (kartu_pemain[y][x] == 4){ namakartu[urutanz] = "4 hati";}
			else if (kartu_pemain[y][x] == 5){ namakartu[urutanz] = "5 hati";}
			else if (kartu_pemain[y][x] == 6){ namakartu[urutanz] = "6 hati";}
			else if (kartu_pemain[y][x] == 7){ namakartu[urutanz] = "7 hati";}
			else if (kartu_pemain[y][x] == 8){ namakartu[urutanz] = "8 hati";}
			else if (kartu_pemain[y][x] == 9){ namakartu[urutanz] = "9 hati";}
			else if (kartu_pemain[y][x] == 10){ namakartu[urutanz] = "10 hati";}
			else if (kartu_pemain[y][x] == 11){ namakartu[urutanz] = "jack hati";}
			else if (kartu_pemain[y][x] == 12){ namakartu[urutanz] = "queen hati";}
			else if (kartu_pemain[y][x] == 13){ namakartu[urutanz] = "king hati";}
			else if (kartu_pemain[y][x] == 14){ namakartu[urutanz] = "Ace wajik";}
			else if (kartu_pemain[y][x] == 15){ namakartu[urutanz] = "2 wajik";}
			else if (kartu_pemain[y][x] == 16){ namakartu[urutanz] = "3 wajik";}
			else if (kartu_pemain[y][x] == 17){ namakartu[urutanz] = "4 wajik";}
			else if (kartu_pemain[y][x] == 18){ namakartu[urutanz] = "5 wajik";}
			else if (kartu_pemain[y][x] == 19){ namakartu[urutanz] = "6 wajik";}
			else if (kartu_pemain[y][x] == 20){ namakartu[urutanz] = "7 wajik";}
			else if (kartu_pemain[y][x] == 21){ namakartu[urutanz] = "8 wajik";}
			else if (kartu_pemain[y][x] == 22){ namakartu[urutanz] = "9 wajik";}
			else if (kartu_pemain[y][x] == 23){ namakartu[urutanz] = "10 wajik";}
			else if (kartu_pemain[y][x] == 24){ namakartu[urutanz] = "jack wajik";}
			else if (kartu_pemain[y][x] == 25){ namakartu[urutanz] = "queen wajik";}
			else if (kartu_pemain[y][x] == 26){ namakartu[urutanz] = "king wajik";}
			else if (kartu_pemain[y][x] == 27){ namakartu[urutanz] = "Ace kriting";}
			else if (kartu_pemain[y][x] == 28){ namakartu[urutanz] = "2 kriting";}
			else if (kartu_pemain[y][x] == 29){ namakartu[urutanz] = "3 kriting";}
			else if (kartu_pemain[y][x] == 30){ namakartu[urutanz] = "4 kriting";}
			else if (kartu_pemain[y][x] == 31){ namakartu[urutanz] = "5 kriting";}
			else if (kartu_pemain[y][x] == 32){ namakartu[urutanz] = "6 kriting";}
			else if (kartu_pemain[y][x] == 33){ namakartu[urutanz] = "7 kriting";}
			else if (kartu_pemain[y][x] == 34){ namakartu[urutanz] = "8 kriting";}
			else if (kartu_pemain[y][x] == 35){ namakartu[urutanz] = "9 kriting";}
			else if (kartu_pemain[y][x] == 36){ namakartu[urutanz] = "10 kriting";}
			else if (kartu_pemain[y][x] == 37){ namakartu[urutanz] = "jack kriting";}
			else if (kartu_pemain[y][x] == 38){ namakartu[urutanz] = "queen kriting";}
			else if (kartu_pemain[y][x] == 39){ namakartu[urutanz] = "king kriting";}
			else if (kartu_pemain[y][x] == 40){ namakartu[urutanz] = "Ace waru";}
			else if (kartu_pemain[y][x] == 41){ namakartu[urutanz] = "2 waru";}
			else if (kartu_pemain[y][x] == 42){ namakartu[urutanz] = "3 waru";}
			else if (kartu_pemain[y][x] == 43){ namakartu[urutanz] = "4 waru";}
			else if (kartu_pemain[y][x] == 44){ namakartu[urutanz] = "5 waru";}
			else if (kartu_pemain[y][x] == 45){ namakartu[urutanz] = "6 waru";}
			else if (kartu_pemain[y][x] == 46){ namakartu[urutanz] = "7 waru";}
			else if (kartu_pemain[y][x] == 47){ namakartu[urutanz] = "8 waru";}
			else if (kartu_pemain[y][x] == 48){ namakartu[urutanz] = "9 waru";}
			else if (kartu_pemain[y][x] == 49){ namakartu[urutanz] = "10 waru";}
			else if (kartu_pemain[y][x] == 50){ namakartu[urutanz] = "jack waru";}
			else if (kartu_pemain[y][x] == 51){ namakartu[urutanz] = "queen waru";}
			else if (kartu_pemain[y][x] == 52){ namakartu[urutanz] = "king waru";}
			cout << namakartu[urutanz] << ", " ;
			urutanz++;
			}
			cout << endl;
			}
			
		//menjumlahkan kartu masing - masing pemain
		//klasifikasi masing - masing nilai dan diberi kode
		for(int q=0; q<jumlah_pemain; q++){
		for(int p=0; p<4; p++){
			if(kartu_pemain[q][p]>0 && kartu_pemain[q][p]<=13){
				kode[q][p] = 1;
			} else if(kartu_pemain[q][p]>13 && kartu_pemain[q][p]<=26){
				kode[q][p] = 2;
			} else if(kartu_pemain[q][p]>26 && kartu_pemain[q][p]<=39){
				kode[q][p] = 3;
			} else if(kartu_pemain[q][p]>39 && kartu_pemain[q][p]<=52){
				kode[q][p] = 4;
			}
		}}
		//konversi nilai menjadi nilai kartu
		for(int s=0; s<jumlah_pemain; s++){
		for(int r=0; r<4; r++){
		if(kartu_pemain[s][r] == 1 || kartu_pemain[s][r] == 14 || kartu_pemain[s][r] == 27 || kartu_pemain[s][r] == 40){
			nilai_konversi[s][r] = 11;
		} else if(kartu_pemain[s][r] == 11 || kartu_pemain[s][r] == 12 || kartu_pemain[s][r] == 13){
			nilai_konversi[s][r] = 10;
		} else if(kartu_pemain[s][r] == 24 || kartu_pemain[s][r] == 25 || kartu_pemain[s][r] == 26){
			nilai_konversi[s][r] = 10;
		} else if(kartu_pemain[s][r] == 37 || kartu_pemain[s][r] == 38 || kartu_pemain[s][r] == 39){
			nilai_konversi[s][r] = 10;
		}  else if(kartu_pemain[s][r] == 50 || kartu_pemain[s][r] == 51 || kartu_pemain[s][r] == 52){
			nilai_konversi[s][r] = 10;
		} else if(kartu_pemain[s][r] >1 && kartu_pemain[s][r]<11){
			nilai_konversi[s][r] = kartu_pemain[s][r];
		} else if(kartu_pemain[s][r]>14 && kartu_pemain[s][r]<24){
			nilai_konversi[s][r] = (kartu_pemain[s][r]%13);
		} else if(kartu_pemain[s][r]>27 && kartu_pemain[s][r]<37){
			nilai_konversi[s][r] = (kartu_pemain[s][r]%13);
		} else if(kartu_pemain[s][r]>40 && kartu_pemain[s][r]<50){
			nilai_konversi[s][r] = (kartu_pemain[s][r]%13);
		} 
		}
		}
		//didapat nilai konversi
		//menjumlahkan hasil msaing - masing jenis kartu
		for(int t=0; t<jumlah_pemain; t++){
			for(int u=0; u<4; u++){
				if(kode[t][u] == 1){
					hati = hati+nilai_konversi[t][u];
				} else if(kode[t][u] == 2){
					wajik = wajik+nilai_konversi[t][u];
				} else if(kode[t][u] == 3){
					kriting = kriting+nilai_konversi[t][u];
				} else if(kode[t][u] == 4){
					waru = waru+nilai_konversi[t][u];
				}
			}
			jumlah_kartu[0] = hati;
			jumlah_kartu[1] = wajik;
			jumlah_kartu[2] = kriting;
			jumlah_kartu[3] = waru;
			int temp_jumlah_kartu=0;

//			buble sort
			for(int aa=0; aa<3; aa++){
				for(int bb=0; bb<4; bb++){
					if(jumlah_kartu[aa] > jumlah_kartu[bb]){
						temp_jumlah_kartu = jumlah_kartu[aa];
						jumlah_kartu[aa] = jumlah_kartu[bb];
						jumlah_kartu[bb] = temp_jumlah_kartu;
					}
				}
			}
			
// 			mendapatkan nilai masing - masing pemain
			nilai_pemain[t] = jumlah_kartu[0] - jumlah_kartu[1] - jumlah_kartu[2] - jumlah_kartu[3];
			hati =0;
			wajik=0;
			kriting=0;
			waru=0;
			
		}
		
		//menampilkan jumlah nilai masing - masing pemain
		for(int n=0; n<jumlah_pemain; n++){
			cout << "Nilai pemain ke - " << (n+1) << " " << nilai_pemain[n]; 
			cout << endl;
		}
		//mencari nilai terbesar
		maksimal = nilai_pemain[0];
		for(int o=0; o<jumlah_pemain; o++){
			if(nilai_pemain[o] > maksimal){
				maksimal = nilai_pemain[o];
				indeks_maksimal = o;
			}
		}
		//menampilkan nilai terbesar
		cout << "Nilai terbesar yaitu : " << maksimal << " ";
		cout << "Pada pemain ke : " << indeks_maksimal+1 << endl;
			
		exit(0);	
	}

};


int main(){
	Empatsatu empatsatu;
	//input jumlah pemain
	do{
	cout << "Masukkan jumlah pemain [2-6] : "; cin >> empatsatu.jumlah_pemain;
	}while(empatsatu.jumlah_pemain<2 || empatsatu.jumlah_pemain>6);
	do{
	cout << "Apakah anda ingin memulai permainan? [y/n] : "; cin >> empatsatu.mulai_main;
	}while(empatsatu.mulai_main!='Y' && empatsatu.mulai_main !='y' && empatsatu.mulai_main!= 'N' && empatsatu.mulai_main!='n');
	if(empatsatu.mulai_main == 'n' || empatsatu.mulai_main == 'n'){
		cout << "Sampai jumpa dilain waktu!!!" <<endl;
		exit(0);
	}
	
	empatsatu.inputkartu();
	empatsatu.shuffle();
	empatsatu.dealkartu();
	empatsatu.index = (4*empatsatu.jumlah_pemain);
	empatsatu.turn = 1;
	for(empatsatu.giliran=0; empatsatu.giliran<empatsatu.jumlah_pemain; empatsatu.giliran++){
		cout << "pemain ke : " << empatsatu.giliran+1 << endl;
		if(empatsatu.turn ==1){
			empatsatu.buang_firstturn();
			empatsatu.show_limakartu();
			empatsatu.index = empatsatu.index+1;
			empatsatu.buangkartu();
			empatsatu.show_empatkartu();
			if(empatsatu.aksi == "close"){
				empatsatu.hitung();
			}
			cout<<endl;
		} else {
			empatsatu.show_empatkartu();
			empatsatu.terakhir_buang();
			do{
			cout << endl <<"Silahkan ambil kartu : 1. Deck utama 2.Kartu terakhir yang dibuang => ";
			cin >> empatsatu.ambilkartu;
			}while(empatsatu.ambilkartu <1 || empatsatu.ambilkartu>2);
			if(empatsatu.ambilkartu == 1){
				empatsatu.ambiltengah();
			} else if (empatsatu.ambilkartu == 2){
				empatsatu.ambilteman();
			}
			empatsatu.show_limakartu();
			empatsatu.buangkartu();
			empatsatu.show_empatkartu();
			if(empatsatu.aksi == "close"){
				empatsatu.hitung();
			} else if(empatsatu.index == 52){
				empatsatu.hitung();
			}
			
			cout << endl;
		}
		
		if(empatsatu.giliran == (empatsatu.jumlah_pemain-1)){
			empatsatu.giliran = -1;
		}
		
		empatsatu.turn = empatsatu.turn+1;
		if(empatsatu.aksi == "close"){
			cout << "--------------------------" << endl;
			cout << "Terima kasih telah bermain" << endl;
		}
		cout << endl;
	}

	cout << empatsatu.jumlah_pemain;
	return 0;
}
