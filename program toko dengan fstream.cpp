#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<windows.h>
using namespace std;

	typedef struct member
	{
		char nama[1000], alamat[10000], nohp[30];
	}member;
	member mb;

	typedef struct barang
	{
		char nama_barang[1000], id_barang1, id_barang2[50];
		int harga, jumlah;
	}barang;
	barang brg;

void buat_member()
{	
	ifstream fi;
	ofstream fo;
	fo.open("member.dat",ios::binary | ios::app);
		cout<<"\nNama   : ";fflush(stdin);gets(mb.nama);
		cout<<"\nAlamat : ";fflush(stdin);gets(mb.alamat);
		cout<<"\nNo. HP : ";fflush(stdin);gets(mb.nohp);
	fo.write((char*) &mb, sizeof(mb));
	fo.close();
}

void info_member()
{
	ifstream fi;
	fi.open("member.dat");
	while(!fi.eof())
	{
		cout<<"\nNama   : "<<mb.nama;
		cout<<"\nAlamat : "<<mb.alamat;
		cout<<"\nNo. HP : "<<mb.nohp;
		cout<<"\n";
		fi.read((char*) &mb, sizeof(mb));
	}fi.close();
	getch();
}

void tambah_barang()
{
	ifstream fi;
	ofstream fo;
	char ulang;
	int pil;
	cout<<"1. Minuman\n";
	cout<<"2. Makanan\n";
	cout<<"3. Alat Rumah Tangga \n";
	cout<<"4. Obat-obatan\n";
	cout<<"Pilihan>>  ";cin>>pil;
	switch(pil)
	{
		case 1 : 
		do
		{
			fo.open("stokbarang.dat",ios::in | ios::app);
			system("cls");
			cout<<"\n";
			cout<<"\nNama makanan : ";fflush(stdin);gets(brg.nama_barang);
			cout<<"\nJumlah       : ";cin>>brg.jumlah;
			cout<<"\nHarga	 	  : ";cin>>brg.harga;
			cout<<"Tambah barang lagi?? (Y/N)";cin>>ulang;
			fo.write((char*) &brg, sizeof(brg));	
			fo.close();
		}while(ulang=='y');
		break;
	}
}

void tampil_barang()
{
	ifstream fi;
	fi.open("stokbarang.dat",ios::out);
	while(!fi.eof())
	{
		cout<<"\n";
		cout<<"\nKode barang 		: "<<brg.id_barang1;
		cout<<"\nNama barang 		: "<<brg.nama_barang;
		cout<<"\nJumlah				: "<<brg.jumlah;
		cout<<"\nHarga per barang	: "<<brg.harga;
		cout<<"\n";
		fi.read((char*) &brg, sizeof(brg));
	}fi.close();
}

//======================================================================================================

void gudang()
{
	int pil;
	do
			{
				system("cls");		
				cout<<"\n";
				cout<<"                   ";
				cout<<"TOKO AMANATUL UMMAH\n";
				cout<<"======================================================";
				cout<<"\n";
				cout<<"\n";
				cout<<"1. Tambah Barang\n";
				cout<<"2. Hapus Barang\n";
				cout<<"3. Tampilkan Seluruh Barang\n";
				cout<<"4. Keluar\n";
				cout<<"pilihan=>  ";cin>>pil;
				switch(pil)
				{
					case 1 : tambah_barang();
					break;
					case 3 : tampil_barang();
					break;
				}
			}while(pil!=4);
}

void kasir()
{
	int pil;
	do
			{
				system("cls");		
				cout<<"\n";
				cout<<"                   ";
				cout<<"TOKO AMANATUL UMMAH\n";
				cout<<"======================================================";
				cout<<"\n";
				cout<<"\n";
				cout<<"1. Member\n";
				cout<<"2. Bukan member\n";
				cout<<"3. Buat member\n";
				cout<<"4. Info member\n";
				cout<<"5. Keluar\n";
				cout<<"pilihan=>  ";cin>>pil;
				switch(pil)
				{
					case 3 : buat_member(); 
					break; 
					case 4 : info_member();
					break;
				}
			}while(pil!=5);
}

int main()
{
	//variabel=============
	typedef struct akun
	{
		char nama[100], kode[50];
	}akun;
	ifstream fi;
	ofstream fo;
	akun akn;
	int ctr;
	//variabel=============
	fi.open("karyawan.dat",ios::out | ios::binary);
	ctr=0;
	char user[100],ch;
	while(ctr==0)
	{
		string pass="";
		cout<<"\n";
		cout<<"                   ";
		cout<<"TOKO AMANATUL UMMAH\n";
		cout<<"======================================================";
		cout<<"\n";
		cout<<"\n";
		cout<<"Username : ";cin>>user;
		cout<<"Password : ";
		ch = _getch();
            while(ch != 13) //character 13 is enter 8=backspace, esc=27
			{
            	pass.push_back(ch);
            	cout << '*';
            	ch = _getch();
            }
        system("cls");
        fi.read((char*) &akn, sizeof(akn));
		if ((strcmp(user,akn.nama)==0) && (pass==akn.kode))
		{
			cout<<"\n";
			ctr=1;
			if (strcmp(akn.nama,"kasir")==0)
			{
				kasir();
			}else if (strcmp(akn.nama,"gudang")==0)
			{
				gudang();
			}
		}else if ((strcmp(user,akn.nama)==0) && (pass!=akn.kode))
		{
			system("cls");
			cout<<"\n";
			cout<<"login gagal, password anda salah\n";
			cout<<"silahkan ulangi\n";
			cout<<"\n";
		}else
		{
			cout<<"\n";
			cout<<"login gagal\n";
			cout<<"silahkan ulangi\n";
			cout<<"\n";
		}
	}
}
