#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct filePasien{
  string namaPasien;
  long long NIKPasien;
  string namaDokter;
  string jamRujukan;
  string tanggalRujukan;
};

class Layanan{
  private:
    int kapasitasFix = 10;
  public:
    void menuAwal(); void menuPasien(); //Untuk menampilkan menu setiap pengguna
    void pilihanPasien(); void pilihanAdmin(); //Untuk memilih layanan pengguna
    void masukPasien(); void daftarPasien(); void lupaSandiPasien(); //Untuk pasien masuk sebuah layanan 
    void masukAdmin();
    void pasienDaftarMasuk(); void pasienKeluar(); void antrianPasien(); void pasienMasuk(); //Daftar antrian pasien
    void rujukanPasien(); void aturKapasitas();
    int kapasitas = 10;
    int posisiData;
    int nomorPasien;
    string pilihan; int ubah; int tipe;
    string jamM; string jamK; string tanggalK;
    string namaPasien[999]; string dokterPasien[999]; string jamDaftar[999];
    filePasien pasien[999];

    void setKapasitasFix(int f){
        kapasitasFix = f;
      }
    int getKapasitasFix(){
        return kapasitasFix;
      }
};

void Layanan::menuAwal()
{
  cout<<"\t ________________________________________\n";
	cout<<"\t|   Selamat Datang Di Layanan Kesehatan  |\n";
  cout<<"\t|          Rumah Sakit TechCure          |\n";
	cout<<"\t|________________________________________|\n";
	cout<<"\t|	ketik 1 untuk PASIEN             "<<"|\n";
	cout<<"\t|	ketik 2 untuk ADMIN              "<<"|\n";
  cout<<"\t|	ketik 3 untuk KELUAR             "<<"|\n";
	cout<<"\t|________________________________________|\n";

  string a;
  cout<<"\t Silahkan masukkan pilihan Anda : ";
  cin >> a;
  if (a == "1"){
    system("cls");
    menuPasien();
  }else if (a == "2"){
    system("cls");
    masukAdmin();
  }else if(a == "3"){
    system("cls");
    cout<<"Terima Kasih sudah menggunakan Layanan\n";
  }else{
    system("cls");
    cout<<"\t\t\t Tolong masukkan pilihan anda \n" << endl;
    menuAwal();
  }
}

void Layanan::menuPasien()
{
  cout<<"\t ________________________________________\n";
	cout<<"\t|   Selamat Datang Di Layanan Kesehatan  |\n";
	cout<<"\t|________________________________________|\n";
	cout<<"\t|	Ketik 1 untuk MASUK              "<<"|"<<endl;
	cout<<"\t|	ketik 2 untuk DAFTAR             "<<"|"<<endl;
	cout<<"\t|	ketik 3 untuk LUPA SANDI         "<<"|"<<endl;
	cout<<"\t|	ketik 4 untuk MENU AWAL          "<<"|"<<endl;
	cout<<"\t|________________________________________|\n";

  string c;
  cout<<"\t Silahkan masukkan pilhan Anda :  ";
  cin >> c;
  if (c == "1"){
    system("cls");
    masukPasien();
  }else if (c == "2"){
    system("cls");
    daftarPasien();
  }else if (c == "3"){
    system("cls");
    lupaSandiPasien();
  }else if (c == "4"){
    system("cls");
    menuAwal();
  }else{
    system("cls");
    cout<<"\t\t\t Tolong masukkan pilihan anda dengan benar\n" << endl;
    menuAwal();
  }
}

void Layanan::masukPasien()
{
	int count;
	string userId, password, id, pass;
	system("cls");
  
	cout<<"Tolong masukkan nama pengguna dan sandi "<<endl;
	cout<<"Nama Pengguna\t: ";
  cin.ignore();
	  getline(cin,userId) ;

	cout<<"Kata Sandi\t: ";
	cin>>password;

	ifstream input("dataAkunPasien.txt");
	while(input>>id>>pass){
		if(id==userId && pass==password){
			count=1;
			system("cls");
		}
	}
	input.close();

	if(count==1){
		cout<<"Login kamu berhasil \n\n";
		pilihanPasien();
	}else {
		system("cls");
		cout<<"\n\t\tLOGIN SALAH, COBA LAGI \n";
		menuPasien();
	}
}

void Layanan::daftarPasien()
{ 
	string ruserId, rpassword, rid, rpass; 
	system("cls");

	cout<<"Masukkan Nama Pengguna : "; 
	cin.ignore();
    getline(cin,ruserId);

	cout<<"Masukkan Kata Sandi : "; 
	  cin>>rpassword;

	int panjangRpassword = rpassword.length();

	if(panjangRpassword >= 8){
	  ofstream f1("dataAkunPasien.txt", ios::app);
	  f1<<ruserId<<' '<<rpassword<<endl;
	  system("cls"); 
	  cout<<"\n\t\tRegistrasi Berhasil \n"; 
	  menuPasien();
	}else{
		cout<<"Kata Sandi minimal 8 huruf";
		cin.ignore();
		cout<<"\n\nTekan ENTER untuk kembali masukkan sandi....";
		cin.get();
		system("cls");
		daftarPasien();
	}
}

void Layanan::lupaSandiPasien()
{
	int option;
  int count = 0;
	string suserId, sId, spass;
	system("cls");
	cout<<"masukkan nama pengguna anda : ";
	cin>>suserId;
	system("cls");

	ifstream f2("dataAkunPasien.txt");

	while(f2>>sId>>spass){
		if(sId==suserId){
			  count=1;
		}
	}

	f2.close();

	if(count==1){
		cout<<"Kata sandi anda : "<<spass<<endl;
    cout << "Tekan \"ENTER\" untuk melanjutkan........";
		cin.get();
    cin.get();
    system("cls");
    menuPasien();
	} else {
		cout<<"Maaf, Anda harus membuat ulang akun Anda";
		menuPasien();
	}
}

void Layanan::pilihanPasien()
{
    cout << " ========================" << endl;    
    cout << "|       Pilih Menu       |"<< endl;
    cout << "|========================|" << endl;
    cout << "|Kapasitas rujukan (" << kapasitas<<")\t |"<<endl;
    cout << "|========================|" << endl;
    cout << "|1. Daftar Rujukan       |"<< endl;
    cout << "|2. Bukti Rujukan        |"<< endl;
    cout << "|3. Keluar               |"<< endl;
    cout << " ========================" << endl;

    string pilih;
    cout << "\nMasukkan pilihan anda : ";
    cin >> pilih;
    if (pilih == "1"){
      if (kapasitas == 0){
        cout << "Tidak ada rujukan yang tersedia, Tekan \"ENTER\" untuk melanjutkan" << endl;
        cin.get();
        cin.get();
        system("cls");
        pilihanPasien();
      }else if (pasien[0].namaPasien != ""){
        cout << "Anda sudah terdaftar ";
        cout << "Tekan \"ENTER\" untuk melanjutkan" << endl;
        cin.get();
        cin.get();
        system("cls");
        pilihanPasien();
      
      }else{
        system("cls");
        pasienDaftarMasuk();
        system("cls");
        pilihanPasien();
      }

    }else if (pilih == "2"){
      system("cls");
      rujukanPasien();

    }else if (pilih == "3"){
      system("cls");
      menuAwal();

    }else{
      cout << "Pilihan yang anda masukkan tidak valid!!, Tekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      system("cls");
      masukAdmin();
  }
}

void Layanan::rujukanPasien()
{
  int i = 0;
  cout << "        Bukti Rujukan      " << endl;
  cout << "===========================" << endl;
  cout << "    Rumah Sakit TechCare " << endl;
  cout << "===========================" << endl;
  cout << "Nama Pasien\t\t: " << pasien[i].namaPasien<< endl;
  cout << "NIK Pasien\t\t: " << pasien[i].NIKPasien<< endl;  
  cout << "Dokter Pasien\t\t: " << pasien[i].namaDokter << endl;
  cout << "Waktu Daftar\t\t: " << pasien[i].jamRujukan << endl;   
  cout << "Tanggal Daftar\t\t: " << pasien[i].tanggalRujukan << endl; 
  cout << "===========================" << endl;
  cout << "\nTekan \"ENTER\" untuk melanjutkan";
  i++;
  cin.get();
  cin.get();
  system("cls");
  pilihanPasien();

}


void Layanan::masukAdmin()
{
  int count;
	string userId, password, id, pass;
  cout<<"\t ________________________________________\n";
	cout<<"\t|     Selamat Datang Di Administrasi     |\n";
	cout<<"\t|________________________________________|\n\n";
	cout<<"Tolong masukkan nama Admin dan sandi "<<endl;
  cout<<"PERINGATAN!! SANDI DITENTUKAN OLEH RUMAH SAKIT, HANYA ADMIN YANG BISA MASUK "<<endl;
	
	cout<<"Kata Sandi\t: ";
	cin>>password;

	ifstream input("dataAkunAdmin.txt");

	while(input>>pass){
		if(pass==password){
			count=1;
			system("cls");
		}
	}
	input.close();

	if(count==1){
		cout<<"Login kamu berhasil \n\n";
		pilihanAdmin();
	}else {
		system("cls");
		cout<<"\n\t\tLOGIN SALAH, COBA LAGI \n";
		menuAwal();
	}
}

void Layanan::pilihanAdmin()
{
  cout << " ========================" << endl;    
  cout << "|       Pilih Menu       |"<< endl;
  cout << "|========================|" << endl;
  cout << "|Kapasitas rujukan (" << kapasitas<<")\t |"<<endl;
  cout << "|========================|" << endl;
  cout << "|1. Daftar Rujukan       |"<< endl;
  cout << "|2. Keluar Rujukan       |"<< endl;
  cout << "|3. Antrian Rujukan      |"<< endl;
  cout << "|4. Atur Kapasitas       |"<< endl;
  cout << "|5. Keluar               |"<< endl;
  cout << " ========================" << endl;

  string pilih;
  cout << "\nMasukkan pilihan anda : ";
  cin >> pilih;
  if (pilih == "1"){
    if (kapasitas == 0){
      cout << "Tidak ada rujukan yang tersedia, Tekan \"ENTER\" untuk melanjutkan" << endl;
      cin.get();
      cin.get();
      system("cls");
      pilihanAdmin();
    }else{
      system("cls");
      pasienMasuk();
      system("cls");
      pilihanAdmin();
    }
 
  }else if (pilih == "2"){
    if (kapasitas == getKapasitasFix()){
      cout << "Saat ini tidak ada pasien yang sedang rujukan, Tekan \"ENTER\" untuk melanjutkan........";
      cin.get();
      cin.get();
      system("cls");
      pilihanAdmin();
    }else{
      system("cls");
      pasienKeluar();
      system("cls");
      pilihanAdmin();
    }
      system("cls");
      pasienKeluar();
      system("cls");
      pilihanAdmin();

  }else if (pilih == "3"){
      system("cls");
      antrianPasien();
      system("cls");
      pilihanAdmin();
  }else if (pilih == "5"){
    system("cls");
    menuAwal();
  }else if (pilih == "4"){
     if (kapasitas != getKapasitasFix()){
      system("cls");
      cout << "Semua pasien rujukan harus kosong dahulu" << endl;
      cout << "Tekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      system("cls");
      pilihanAdmin();
    }else{
      system("cls");
      aturKapasitas();
      system("cls");
      pilihanAdmin();
    }
      system("cls");
      menuAwal();
      
  }else{
      cout << "Pilihan yang anda masukkan tidak valid!!, Tekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      system("cls");
  }
}


void Layanan::pasienDaftarMasuk()
{
  int i = 0;
  string tipe;
      if (pasien[i].namaPasien == ""){
      cout << "Masukaan nama pasien : ";
      cin.ignore();
      getline(cin,pasien[i].namaPasien);
      cout << "Masukkan NIK pasien : ";
      cin>>pasien[i].NIKPasien;
      cout << "Dokter Rujukan : " << endl;
      cout << "1. Dokter Umum" << endl;
      cout << "2. Dokter Spesialis" << endl;
      cout << "Masukkan Dokter Rujukan : ";
      cin >> tipe;
      if (tipe == "1"){
          pasien[i].namaDokter = "Dokter Umum";
      }else if (tipe == "2"){
          pasien[i].namaDokter = "Dokter Spesialis";
      }else{         
        system("cls");
        pasienMasuk();
        cout<<"Masukkan dengan benar";
      }
      cout << "Masukkan jam saat ini : ";
      cin >> pasien[i].jamRujukan;
      cout << "Masukkan tanggal saat ini : ";
      cin >> pasien[i].tanggalRujukan;
      kapasitas--;
      system("cls");

      cout << "     ANTRIAN MASUK!!!" << endl;
      cout << "===========================" << endl;
      cout << "     Antrian Rumah Sakit " << endl;
      cout << "===========================" << endl;
      cout << "Nama Pasien\t\t: " << pasien[i].namaPasien<< endl;
      cout << "NIK Pasien\t\t: " << pasien[i].NIKPasien<< endl;  
      cout << "Dokter Pasien\t\t: " << pasien[i].namaDokter << endl;
      cout << "Waktu Daftar\t\t: " << pasien[i].jamRujukan << endl;   
      cout << "Tanggal Daftar\t\t: " << pasien[i].tanggalRujukan << endl; 
      cout << "===========================" << endl;
      cout << "\nTekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      }
  
  }

void Layanan::pasienMasuk()
{
  int i;
  string tipe;
  for (i=1; i < kapasitas; i++){
      if (pasien[i].namaPasien == ""){
      cout << "Masukaan nama pasien : ";
      cin.ignore();
      getline(cin,pasien[i].namaPasien);
      cout << "Masukkan NIK pasien : ";
      cin>>pasien[i].NIKPasien;
      cout << "Dokter Rujukan : " << endl;
      cout << "1. Dokter Umum" << endl;
      cout << "2. Dokter Spesialis" << endl;
      cout << "Masukkan Dokter Rujukan : ";
      cin >> tipe;
      if (tipe == "1"){
          pasien[i].namaDokter = "Dokter Umum";
      }else if (tipe == "2"){
          pasien[i].namaDokter = "Dokter Spesialis";
      }else{         
        system("cls");
        pasienMasuk();
        cout<<"Masukkan dengan benar";
      }
      cout << "Masukkan jam saat ini : ";
      cin >> pasien[i].jamRujukan;
      cout << "Masukkan tanggal saat ini : ";
      cin >> pasien[i].tanggalRujukan;
      kapasitas--;
      system("cls");
      break;
      }
    }
    cout << "     ANTRIAN MASUK!!!" << endl;
    cout << "===========================" << endl;
    cout << "     Antrian Rumah Sakit " << endl;
    cout << "===========================" << endl;
    cout << "Nama Pasien\t\t: " << pasien[i].namaPasien<< endl;
    cout << "NIK Pasien\t\t: " << pasien[i].NIKPasien<< endl;  
    cout << "Dokter Pasien\t\t: " << pasien[i].namaDokter << endl;
    cout << "Waktu Daftar\t\t: " << pasien[i].jamRujukan << endl;   
    cout << "Tanggal Daftar\t\t: " << pasien[i].tanggalRujukan << endl; 
    cout << "===========================" << endl;
    cout << "\nTekan \"ENTER\" untuk melanjutkan";
    cin.get();
    cin.get();
} 


void Layanan::pasienKeluar()
{
  string keluar;
  string jKeluar;
  string tKeluar;
  cout << "Masukkan nama pasien : ";
  cin.ignore();
  getline(cin,keluar);
  cout << "Masukkan jam saat ini : ";
  cin >> jKeluar;
  cout << "Masukkan tanggal saat ini : ";
  cin >> tKeluar;
  jamK = jKeluar;
  tanggalK = tKeluar;
  for (int i = 0; i < getKapasitasFix(); i++){
    if (pasien[i].namaPasien == keluar){
      kapasitas += 1;
      posisiData += 1;
      system("cls");
      cout << "\tPASIEN SELESAI RUJUKAN!!!" << endl;
      cout << "==========================================" << endl;
      cout << "\tLayanan Kesehatan    " << endl;
      cout << "==========================================" << endl;
      cout << "Nama Pasien\t\t: " << pasien[i].namaPasien << endl;
      cout << "Dokter\t\t\t: " << pasien[i].namaDokter << endl;
      cout << "Jam Masuk\t\t: " << pasien[i].jamRujukan << endl;
      cout << "Tanggal Masuk\t\t: " << pasien[i].tanggalRujukan << endl;
      cout << "Jam Keluar\t\t: " << jamK << endl;
      cout << "Tanggal Keluar\t\t: " << tanggalK << endl;      
      nomorPasien++;
      cout << "==========================================" << endl;
      cout << "\nTekan \"ENTER\" untuk melanjutkan";
        ofstream dataPasien;
        dataPasien.open("dataRiwayatPasien.txt", ios::app);
        dataPasien << nomorPasien << endl;
        dataPasien << pasien[i].namaPasien<< endl;
        dataPasien << pasien[i].namaDokter<< endl;
        dataPasien << pasien[i].jamRujukan<< endl;
        dataPasien << pasien[i].tanggalRujukan<< endl;        
        dataPasien << jamK << endl;
        dataPasien << tanggalK<< endl;        
        dataPasien.close();
      pasien[i].namaPasien = "";
      pasien[i].jamRujukan = "";
     
      cin.get();
      cin.get();
      break;
    }
  }
  posisiData = 0;
}

void Layanan::antrianPasien()
{
  cout<<"\t ________________________________________\n";
	cout<<"\t|          Daftar Pasien Rujukan         |\n";
	cout<<"\t|________________________________________|\n\n";
  cout<<"=====================================\n";

  for (int i = 0; i < getKapasitasFix(); i++){
    cout<<"=====================================\n";
    cout<<i+1<<". ";
    if (pasien[i].namaPasien == ""){
      cout << "Kosong" << endl;
    }else{
      cout << "Nama Pasien\t\t: " << pasien[i].namaPasien<< endl;
      cout << "NIK Pasien\t\t: " << pasien[i].NIKPasien<< endl;  
      cout << "Dokter Pasien\t\t: " << pasien[i].namaDokter << endl;
      cout << "Waktu Daftar\t\t: " << pasien[i].jamRujukan << endl;   
      cout << "Tanggal Daftar\t\t: " << pasien[i].tanggalRujukan << endl; 
      cout<<"=====================================\n";
    }
  }
  cout << "\nTekan \"ENTER\" untuk kembali";
  cin.get();
  cin.get();
  system("cls");
}

void Layanan::aturKapasitas(){
  string pilihan;
  int ubah;
  cout << "Apakah anda yakin ingin merubah kapasitas rujukan? (y/n) : ";
  cin >> pilihan;
  if (pilihan == "y" || pilihan == "Y"){
    cout << "Masukkan jumlah dari slot pasien : ";
    cin >> ubah;
    setKapasitasFix(ubah);
    kapasitas = getKapasitasFix();
  }
}

int main()
{
    Layanan kesehatan;
    kesehatan.menuAwal();
    return 0;
}
