#include <iostream>
#include <conio.h>

using namespace std;
struct mahasiswa
{
	string nim;
	string nama;
	string alamat;
};

int main()
{
	mahasiswa data[999];
	int n,lok;
	string cari;
	cout<<"Masukkan jumlah data : ";cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<endl<<"Masukkan data ke-"<<i+1<<" : "<<endl;
		cout<<"NIM    : ";cin>>data[i].nim;
		cout<<"Nama   : ";cin>>data[i].nama;
		cout<<"Alamat : ";cin>>data[i].alamat;
	}
	lok=-1;
	cout<<"Masukkan nim yang dicari : ";cin>>cari;
	for (int i=0;i<=n;i++)
	{
		if (data[i].nim==cari)
		{
			lok=i;
			break;
		}
	}
	if (lok==-1)
	{
		cout<<"Tidak ditemukan";
	}
	else
	{
		cout<<endl<<"Data ditemukan pada posisi "<<lok+1<<endl;
		cout<<"Data Mahasiswa : "<<endl;
		cout<<"Nama   : "<<data[lok].nama<<endl;
		cout<<"Alamat : "<<data[lok].alamat<<endl;
	}
	getch();
	
}
