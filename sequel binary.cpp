#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int input, cari,cek,cek2;
	int arr[6]={5,20,3,15,7,8};
	cout<<"5  20  3  15  7  8\n";
	cout<<" ";cin>>cari;
	cek2=0;
	for(int i=0;i<=5;i++)
	{
		if (arr[i]==cari)
		{
			cek=i;
			cek2=1;
		}
		
	}
	if (cek2==1)
	{
		cout<<" \n";
		cout<<"Angka yang anda cari ada diurutan "<<cek+1;
	}
	else
	{
		cout<<" \n";
		cout<<"Angka tidak ditemukan";
	}
	getch();
}
