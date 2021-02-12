#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;

//template<typename, T>

class OpenKios{
    public:
    void menu_utama(){
        int pil;
        cout << "Silahkan pilih jenis user [1-3] : " << endl;
        cout << "1. Penjual" << endl;
        cout << "2. Pembeli "<< endl;
        cout << "3. Tutup Aplikasi" << endl;
        cout << "Pilihan : "; cin >> pil;
        setpilihanJenisUser(pil);
    }
    
    void setpilihanJenisUser(int a){
        pilihan_jenis_user = a;
    }

    int getPilihanJenisUser(){
        return pilihan_jenis_user;
    }

    private:
    int pilihan_jenis_user;

};

class Penjual: public OpenKios{
    public:
    Penjual(string nama){
        setNama(nama);
    }
    void setNama(string nama){
        this->nama = nama;
    }

    string getNama(){
        return nama;
    }

    void menu_penjual()
    {
        // cout << "Halo " << getNama() << " !" << endl;
        cout << "Pilih jenis layanan [1-5] : " << endl;
        cout << "1. OpenSaham" << endl;
        cout << "2. OpenEmas" << endl;
        cout << "3. OpenBarang" << endl;
        cout << "4. OpenReksa" << endl;
        cout << "5. Kembali ke menu utama" << endl;
        cout << "Masukkan pilihan : "; cin >> pil_penjual;
        setPilihan_penjual(pil_penjual);
    }

    void setPilihan_penjual(int a){
        pilihan_penjual = a;
    }

    int getPilihan_penjual(){
        return pilihan_penjual;
    }
    virtual void print(){
        cout << "Halo " << getNama() << " !"<< endl;
    }

    private:
    string nama;
    int pilihan_penjual;
    int pil_penjual;


};

class Pembeli: public OpenKios{
    public:

    Pembeli(string nama){
        setNama(nama);
    }
    void setNama(string nama){
        this->nama = nama;
    }

    string getNama(){
        return nama;
    }

    void menu_pembeli(){
        int a;
        cout << "Silahkan pilih jenis layanan : " << endl;
        cout << "1. OpenSaham" << endl;
        cout << "2. OpenEmas" << endl;
        cout << "3. OpenBarang" << endl;
        cout << "4. OpenReksa" << endl;
        cout << "5. Top up saldo" << endl;
        cout << "6. Cek riwayat belanja" << endl;
        cout << "7. Kembali ke menu utama" << endl;
        cout << "Masukkan pilihan [1-7] : "; cin >> a;
        setPilihan_pembeli(a);
    }

    void setPilihan_pembeli(int b){
        pilihan_pembeli = b;
    }
    int getPilihan_pembeli(){
        return pilihan_pembeli;
    }

    void setTambahsaldo(int tambah){
        if(tambah < 0){
            tambahsaldo = 0;
        } else {
            tambahsaldo = tambah;
        }

    }

    int getTambahsaldo(){
        return tambahsaldo;
    }

    void menuTambahSaldo(){
        int saldo;
        cout << "Selamat datang di layanan Top up saldo." << endl;
        cout << "Masukkan nominal saldo yang ingin ditambahkan : "; cin >> saldo;
        setTambahsaldo(saldo);
    }

    private:
    string nama;
    int tambahsaldo;
    int pilihan_pembeli;
};

class Penjual_saham:public Penjual{
    public:
    string penjual_saham[100];
    string nama_saham[100];
    string prediksi_saham[100];
    int harga_saham[100];
    int count_saham;

    //constructor
    Penjual_saham(string nama):Penjual(nama){
        count_saham = 0;
    }

    //setter getter
    void setNama_penjual_saham(string nama_penjual){ nama_penjual_saham = nama_penjual; }
    string getNama_penjual_saham(){ return nama_penjual_saham; }

    void setNama_saham_dijual(string nama_saham){ nama_saham_dijual = nama_saham;}
    string getNama_saham_dijual(){ return nama_saham_dijual; }

    void setPrediksi_saham_dijual(string prediksi_saham){ prediksi_saham_dijual = prediksi_saham; }
    string getPrediksi_saham_dijual(){ return prediksi_saham_dijual; }
    
    void setHarga_saham_dijual(int harga_saham){ 
        if(harga_saham < 0){
            harga_saham_dijual = 0;
        } else {
            harga_saham_dijual = harga_saham;
        } }
    int getHarga_saham_dijual(){ return harga_saham_dijual; }

    void inputSaham(){
        penjual_saham[count_saham] = getNama_penjual_saham();
        nama_saham[count_saham] = getNama_saham_dijual();
        prediksi_saham[count_saham] = getPrediksi_saham_dijual();
        harga_saham[count_saham] = getHarga_saham_dijual();
        count_saham++;
    }

    void inputSahamDijual(){
        string a,b;
        int c;
        setNama_penjual_saham(getNama());
        cout << "Masukkan nama saham perusahaan : "; cin.ignore(); getline(cin,a);
        cout << "Masukkan harga saham [Rp] : "; cin >> c;
        cout << "Masukkan prediksi saham [naik/turun] : "; cin.ignore(); getline(cin,b);
        setNama_saham_dijual(a);
        setHarga_saham_dijual(c);
        setPrediksi_saham_dijual(b);
    }

    void print(){
        Penjual::print();
        cout << "Selamat datang di layanan OpenSaham" << endl;
    }

    void tampilkansaham(){
        cout << "-----------------------------------" << endl;
        cout << "Daftar penjual saham : " << endl;
        for(int j=0; j<count_saham; j++){
            cout << j+1 << ". ";
            cout << "Nama penjual : " << penjual_saham[j] << endl;
            cout << "Nama saham : " << nama_saham[j] << endl;
            cout << "Harga saham : " << harga_saham[j] << endl;
            cout << "Prediksi saham : " << prediksi_saham[j] << endl;
        }
        cout << endl;
    }

    string nama_sahambeli(int number){
        string value;
        value = nama_saham[number-1];
        return value;
    }

    int harga_sahambeli(int number_harga){
        int value_harga;
        value_harga = harga_saham[number_harga-1];
        return value_harga;
    }

    private:
    string nama_penjual_saham;
    string nama_saham_dijual;
    string prediksi_saham_dijual;
    int harga_saham_dijual;

};

class Penjual_emas:public Penjual{
    public:
    string penjual_emas[100];
    int berat_emas[100];
    int harga_emas[100];
    string prediksi_emas[100];
    int count_emas;

    //constructor
    Penjual_emas(string nama):Penjual(nama){
        count_emas = 0;
    }

    //setter getter
    void setNama_penjual_emas(string nama_penjual){ nama_penjual_emas = nama_penjual; }
    string getNama_penjual_emas(){ return nama_penjual_emas; }

    void setBerat_emas_dijual(int berat_emas){   berat_emas_dijual = berat_emas; }
    int getBerat_emas_dijual(){ return berat_emas_dijual; }

    void setHarga_emas_dijual(int harga_emas){ 
        if(harga_emas < 0){
            harga_emas_dijual = 0;
        } else {
            harga_emas_dijual = harga_emas; 
        } }
    int getHarga_emas_dijual(){ return harga_emas_dijual; }

    void setPrediksi_emas_dijual(string prediksi_emas){ prediksi_emas_dijual = prediksi_emas; }
    string getPrediksi_emas_dijual(){ return prediksi_emas_dijual; }

    void inputEmas(){
        penjual_emas[count_emas] = getNama_penjual_emas();
        berat_emas[count_emas] = getBerat_emas_dijual();
        harga_emas[count_emas] = getHarga_emas_dijual();
        prediksi_emas[count_emas] = getPrediksi_emas_dijual();
        count_emas++;
    }

    void print(){
        Penjual::print();
        cout << "Selamat datang di layanan OpenEmas" << endl;
    }


    void inputEmasDijual(){
        string a;
        int b,c;
        setNama_penjual_emas(getNama());
        cout << "Masukkan berat emas [gr] : "; cin >> b;
        cout << "Masukkan harga emas [Rp] : "; cin >> c;
        cout << "Prediksi harga emas [naik/turun] : "; cin.ignore(); getline(cin,a);
        setBerat_emas_dijual(b);
        setHarga_emas_dijual(c);
        setPrediksi_emas_dijual(a);
    }

    void tampilkanemas(){
        cout << "-----------------------------------" << endl;
        cout << "Daftar penjualan emas : " << endl;
        for(int i=0; i<count_emas; i++){
            cout << i+1 << ". ";
            cout << "Nama penjual : " << penjual_emas[i] << endl;
            cout << "Berat emas : " << berat_emas[i] << endl;
            cout << "Harga emas : " << harga_emas[i] << endl;
            cout << "Prediksi emas : " << prediksi_emas[i] << endl;
        }
        cout << endl;
    }

    int berat_emasbeli(int number_berat){
        int value_berat;
        value_berat = berat_emas[number_berat-1];
        return value_berat;
    }

    int harga_emasbeli(int number_harga){
        int value_harga;
        value_harga = harga_emas[number_harga-1];
        return value_harga;
    }


    private:
    string nama_penjual_emas;
    int berat_emas_dijual;
    int harga_emas_dijual;
    string prediksi_emas_dijual;


};

class Penjual_barang:public Penjual{
    public:
    string penjual_barang[100];
    string nama_barang[100];
    int harga_barang[100];
    int count_barang;

    //constructor
    Penjual_barang(string nama):Penjual(nama){
        count_barang = 0;
    }

    //setter getter
    void setNama_penjual_barang(string nama_penjual){
        nama_penjual_barang = nama_penjual;
    }
    string getNama_penjual_barang(){
        return nama_penjual_barang;
    }
    void setNama_barang_dijual(string nama_barang){
        nama_barang_dijual = nama_barang;
    }
    string getNama_barang_dijual(){
        return nama_barang_dijual;
    }
    void setHarga_barang_dijual(int harga_barang){
        if(harga_barang < 0){
            harga_barang_dijual = 0;
        } else {
            harga_barang_dijual = harga_barang;
        }
    }
    int getHarga_barang_dijual(){
        return harga_barang_dijual;
    }

    void inputBarang(){
        penjual_barang[count_barang] = getNama_penjual_barang();
        nama_barang[count_barang] = getNama_barang_dijual();
        harga_barang[count_barang] = getHarga_barang_dijual();
        count_barang++;
    }

    void inputBarangdijual(){
        string a;
        int b;
        setNama_penjual_barang(getNama());
        cout << "Masukkan nama barang : "; cin.ignore(); getline(cin,a);
        cout << "Masukkan harga barang [Rp] : "; cin >> b;
        setNama_barang_dijual(a);
        setHarga_barang_dijual(b);
    }

    void print(){
        Penjual::print();
        cout << "Selamat datang di layanan OpenBarang" << endl;
    }

    void tampilkanBarangJual(){
        cout << "-----------------------------------" << endl;
        cout << "Daftar barang yang dijual : " << endl;
        for(int i=0; i<count_barang; i++){
            cout << i+1 << ". ";
            cout << "Nama penjual : " << penjual_barang[i] << endl;
            cout << "Nama barang : " << nama_barang[i] << endl;
            cout << "Harga barang : " << harga_barang[i] << endl;
        }
        cout << endl;
    }

    string nama_barangbeli(int number_barang){
        string value_nama;
        value_nama = nama_barang[number_barang-1];
        return value_nama;
    }
    
    int harga_barangbeli(int number_harga){
        int value_harga;
        value_harga = harga_barang[number_harga-1];
        return value_harga;
    }

    private:
    string nama_penjual_barang;
    string nama_barang_dijual;
    int harga_barang_dijual;

};

class Penjual_reksa:public Penjual{
    public:
    string penjual_reksa[100];
    string prediksi_reksa[100];
    string nama_reksa[100];
    int harga_reksa[100];
    int count_reksa;

    //constructor
    Penjual_reksa(string nama):Penjual(nama){
        count_reksa = 0;
    }

    //setter getter
    void setNama_penjual_reksa(string nama_penjual){
        nama_penjual_reksa = nama_penjual;
    }
    string getNama_penjual_reksa(){
        return nama_penjual_reksa;
    }
    void setPrediksi_harga_reksa(string prediksi_reksa){
        prediksi_harga_reksa = prediksi_reksa;
    }
    string getPrediksi_harga_reksa(){
        return prediksi_harga_reksa;
    }
    void setNama_reksa_dijual(string nama_reksa){
        nama_reksa_dijual = nama_reksa;
    }
    string getNama_reksa_dijual(){
        return nama_reksa_dijual;
    }
    void setHarga_reksa_dijual(int harga_reksa){
        if(harga_reksa < 0){
            harga_reksa_dijual = 0;
        } else {
            harga_reksa_dijual = harga_reksa;
        }
    }
    int getHarga_reksa_dijual(){
        return harga_reksa_dijual;
    }

    void inputReksa(){
        penjual_reksa[count_reksa] = getNama_penjual_reksa();
        nama_reksa[count_reksa] = getNama_reksa_dijual();
        harga_reksa[count_reksa] = getHarga_reksa_dijual();
        prediksi_reksa[count_reksa] = getPrediksi_harga_reksa();
        count_reksa++;
    }

    void print(){
        Penjual::print();
        cout << "Selamat datang di layanan OpenReksa" << endl;
    }

    void inputReksaDijual(){
        string a,c;
        int b;
        setNama_penjual_reksa(getNama());
        cout << "Masukkan nama reksa : "; cin.ignore(); getline(cin,a);
        cout << "Masukkan harga reksa [Rp] : "; cin >> b;
        cout << "Masukkan prediksi reksa [naik/turun] : "; cin.ignore(); getline(cin,c);
        setNama_reksa_dijual(a);
        setHarga_reksa_dijual(b);
        setPrediksi_harga_reksa(c);
    }

    void tampilkanreksajual(){
        cout << "-----------------------------------" << endl;
        cout << "Daftar reksa yang dijual : " << endl;
        for(int i=0; i<count_reksa; i++){
            cout << i+1 << ". ";
            cout << "Nama penjual reksa : " << penjual_reksa[i];
            cout << "Nama reksa : " << nama_reksa[i];
            cout << "Harga reksa : " << harga_reksa[i];
            cout << "Prediksi reksa : " << prediksi_reksa[i];
        }
        cout << endl;
    }

    string nama_reksajual(int number_nama){
        string value_nama;
        value_nama = nama_reksa[number_nama-1];
        return value_nama;
    }

    int harga_reksajual(int number_reksa){
        int value_harga;
        value_harga = harga_reksa[number_reksa-1];
        return value_harga;
    }

    private:
    string nama_penjual_reksa;
    string prediksi_harga_reksa;
    string nama_reksa_dijual;
    int harga_reksa_dijual;

};



int main(){
    cout << fixed << setprecision( 2 );

    //boolean kondisi
    bool con_menu_utama = true;
    bool con_menu_penjualan = true;
    bool con_menu_pembelian = true;

    //keranjang pembeli
    string keranjang[]={};
    // int keranjang_emas[]={};
    int urutan = 0;
    // int urutanemas = 0;
    int saldo = 1000000;
    int &saldo_use = saldo;
    int sal = 0;
    int &saldo_emas = sal;

    //pembelian
    int pilih_barang;

    OpenKios openkios;
    Penjual penjual("achmad");
    Penjual_saham penjual_saham("achmad");
    Penjual_emas penjual_emas("achmad");
    Penjual_barang penjual_barang("achmad");
    Penjual_reksa penjual_reksa("achmad");
    Pembeli pembeli("achmad");


    do{
    cout << "-----------------------------------" << endl;
    cout << "Selamat datang di Aplikasi OpenKios" << endl;

    //user memilih penjual atau pembeli
    openkios.menu_utama();
    cout << "-----------------------------------" << endl;
    if(openkios.getPilihanJenisUser() == 1){
        //user adalah 
        //user memilih barang yang akan dijual
        do{
        penjual.menu_penjual();
        if(penjual.getPilihan_penjual()==1){
            //penjual saham
            penjual_saham.print();
            penjual_saham.inputSahamDijual();
            penjual_saham.inputSaham();
            cout << "Input penjualan saham telah berhasil!" << endl;
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = true;
        } else if(penjual.getPilihan_penjual() ==2){
            //penjual emas
            penjual_emas.print();
            penjual_emas.inputEmasDijual();
            penjual_emas.inputEmas();
            cout << "Input penjualan emas telah berhasil!" << endl;
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = true;
        } else if(penjual.getPilihan_penjual() == 3){
            //penjual barang
            penjual_barang.print();
            penjual_barang.inputBarangdijual();
            penjual_barang.inputBarang();
            cout << "Input penjualan barang telah berhasil!";
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = true;
        } else if(penjual.getPilihan_penjual() == 4){
            //penjual reksa
            penjual_reksa.print();
            penjual_reksa.inputReksaDijual();
            penjual_reksa.inputReksa();
            cout << "Input penjualan reksa telah berhasil!";
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = true;
        } else if(penjual.getPilihan_penjual() == 5){
            //kembali ke menu utama
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = false;
        }else {
            //throwback exception
            cout << "Pilihan yang anda inputkan salah!" << endl;
            cout << "-----------------------------------" << endl;
            con_menu_penjualan = true;
        }
        } while(con_menu_penjualan == true); // end of pilihan penjual
        con_menu_utama = true;
    } else if(openkios.getPilihanJenisUser() == 2){
        //user adalah pembeli
        do{
            cout << "-----------------------------------" << endl;
            cout << "Selamat datang, " << pembeli.getNama() << endl;
            cout << "Saldo anda : " << saldo << endl;
            cout << "Emas yang anda miliki : " << saldo_emas << " gram" << endl;
            pembeli.menu_pembeli();
            if(pembeli.getPilihan_pembeli() == 1){
                //pembeli saham
                bool con_beli_saham = true;
                string conf_saham;
            do{
                penjual_saham.tampilkansaham();
                cout << "Silahkan pilih barang yang ingin anda beli : "; cin >> pilih_barang;
                cout << "Apakah anda yakin membeli barang nomor " << pilih_barang << " ? [ya/tidak]: "; cin >> conf_saham;
                if(conf_saham == "Ya" || conf_saham == "ya" || conf_saham == "Ya"){
                if(saldo_use < penjual_saham.harga_sahambeli(pilih_barang)){
                    cout << "Saldo anda tidak mencukupi, silahkan isi saldo anda!" << endl;
                } else {
                    keranjang[urutan] = "saham "+penjual_saham.nama_sahambeli(pilih_barang);
                    saldo_use = saldo_use - penjual_saham.harga_sahambeli(pilih_barang);
                    urutan++;            
                    cout << "Transaksi anda telah berhasil.. " << endl;
                }
                con_beli_saham = false;
                } else {
                    char p_saham;
                    cout << "Kembali ke menu utama? [y/n] : "; cin >> p_saham;
                    if(p_saham == 'y' || p_saham == 'Y'){
                        con_beli_saham = false;
                    } else {
                       con_beli_saham = true;
                    }
                }
            }while(con_beli_saham == true);

            } else if(pembeli.getPilihan_pembeli() == 2){
                //pembeli emas
                bool con_beli_emas = true;
                string conf_emas;
                 do{
                penjual_emas.tampilkanemas();
                cout << "Silahkan pilih emas yang ingin anda beli : "; cin >> pilih_barang;
                cout << "Apakah anda yakin membeli barang nomor " << pilih_barang << " ? [ya/tidak]: "; cin >> conf_emas;
                if(conf_emas == "Ya" || conf_emas == "ya" || conf_emas == "Ya"){
                if(saldo_use < penjual_emas.harga_emasbeli(pilih_barang)){
                    cout << "Saldo anda tidak mencukupi, silahkan isi saldo anda!" << endl;
                } else {
                saldo_emas = saldo_emas + penjual_emas.berat_emasbeli(pilih_barang);
                saldo_use = saldo_use - penjual_emas.harga_emasbeli(pilih_barang);
                cout << "Transaksi anda telah berhasil.." << endl;
                }
                con_beli_emas = false;
                } else {
                    char p_emas;
                    cout << "Kembali ke menu utama? [y/n] : "; cin >> p_emas;
                    if(p_emas == 'y' || p_emas == 'Y'){
                        con_beli_emas = false;
                    } else {
                       con_beli_emas = true;
                    }
                }
            }while(con_beli_emas == true);

            } else if(pembeli.getPilihan_pembeli() == 3){
                //pembeli barang
                bool con_beli_barang = true;
                string conf_barang;
                 do{
                penjual_barang.tampilkanBarangJual();
                cout << "Silahkan pilih barang yang ingin anda beli : "; cin >> pilih_barang;
                cout << "Apakah anda yakin membeli barang nomor " << pilih_barang << " ? [ya/tidak]: "; cin >> conf_barang;
                if(conf_barang == "Ya" || conf_barang == "ya" || conf_barang == "Ya"){
                 if(saldo_use < penjual_barang.harga_barangbeli(pilih_barang)){
                    cout << "Saldo anda tidak mencukupi, silahkan isi saldo anda!" << endl;
                } else {
                keranjang[urutan] = penjual_barang.nama_barangbeli(pilih_barang);
                saldo_use = saldo_use - penjual_barang.harga_barangbeli(pilih_barang);
                urutan++;
                cout << "Transaksi anda telah berhasil.. " << endl;
                }

                con_beli_barang = false;
                } else {
                    char p_barang;
                    cout << "Kembali ke menu utama? [y/n] : "; cin >> p_barang;
                    if(p_barang == 'y' || p_barang == 'Y'){
                        con_beli_barang = false;
                    } else {
                       con_beli_barang = true;
                    }
                }
            }while(con_beli_barang == true);

            } else if(pembeli.getPilihan_pembeli() ==4){
                //pembeli reksa
                bool con_beli_reksa = true;
                string conf_reksa;
                 do{
                penjual_reksa.tampilkanreksajual();
                cout << "Silahkan pilih reksa yang ingin anda beli : "; cin >> pilih_barang;
                cout << "Apakah anda yakin membeli barang nomor " << pilih_barang << " ? [ya/tidak]: "; cin >> conf_reksa;
                if(conf_reksa == "Ya" || conf_reksa == "ya" || conf_reksa == "Ya"){
                if(saldo_use < penjual_reksa.harga_reksajual(pilih_barang)){
                cout << "Saldo anda tidak mencukupi, silahkan isi saldo anda!" << endl;
                } else {
                keranjang[urutan] = "Reksa "+penjual_reksa.nama_reksajual(pilih_barang);
                saldo_use = saldo_use - penjual_reksa.harga_reksajual(pilih_barang);
                urutan++;
                cout << "Transaksi anda telah berhasil.. " << endl;
                }
                con_beli_reksa = false;
                } else {
                    char p_reksa;
                    cout << "Kembali ke menu utama? [y/n] : "; cin >> p_reksa;
                    if(p_reksa == 'y' || p_reksa == 'Y'){
                        con_beli_reksa = false;
                    } else {
                       con_beli_reksa = true;
                    }
                }
            }while(con_beli_reksa == true);

            } else if(pembeli.getPilihan_pembeli() ==5){
                //top up saldo
            cout << "-----------------------------------" << endl;
            pembeli.menuTambahSaldo();
            keranjang[urutan] = "Top up saldo";
            saldo_use = saldo_use + pembeli.getTambahsaldo();
            urutan++;
            cout << "Saldo berhasil ditambahkan.. " << endl;
            } else if(pembeli.getPilihan_pembeli()==6){
                //cek riwayat belanja
                cout << "-----------------------------------" << endl;
                cout << "daftar belanja hari ini : " << endl;
                cout << "Keranjang belanja : " << endl;
                if(urutan > 0){
                        for(int x=0; x<urutan; x++){
                        cout << x+1 << ". ";
                        cout << keranjang[x];
                        cout << endl;
                    }
                } else {
                    cout << "Keranjang kosong" << endl;
                }
                //urutan emas
                // cout << "Keranjang emas : " << endl;
                // if(urutanemas > 0){
                //     for(int y=0; y<urutanemas; y++){
                //         cout << y+1 << ". ";
                //         cout << keranjang_emas[y] << " gram emas";
                //         cout << endl;
                //     }                    
                // } else {

                //     cout << "Keranjang emas kosong" << endl;
                // }
                cout << "Saldo anda sekarang : " << saldo << endl;
                cout << "Saldo emas anda sekarang : " << saldo_emas << " gram" << endl;
            } else if(pembeli.getPilihan_pembeli()==7){
                //kembali ke menu utama
                con_menu_pembelian = false;
            } else{
                cout << "Pilihan yang anda masukkan salah!" << endl;
                con_menu_pembelian = true;
            }

        } while(con_menu_pembelian == true);

    } else if (openkios.getPilihanJenisUser() == 3){
        //keluar dari palikasi
        con_menu_utama = false;
    } else {
        //throwback exception
        cout << "Pilihan yang anda inputkan salah!" << endl;
        con_menu_utama = true;
    }

    } while(con_menu_utama == true);




    return 0;
}
