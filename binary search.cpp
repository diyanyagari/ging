#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	int a[6]={2,3,5,7,11,13};
	int x,urut,awal,akhir,cek;
	awal=1;
	akhir=6;
	cek=0;
	cout<<" 2 3 5 7 11 13 \n";
	cout<<" ";cin>>x;
	while((awal<=akhir) && (cek==0))
	{
		urut=(awal+akhir)*0.5;
		if (a[urut]==x)
		{
			cek=1;
			break;
		}
		else if (a[urut]<x)
		{
			awal=urut+1;
		}
		else
		{
			akhir=urut-1;
		}
	}
	if (cek==1)
	{
		cout<<" \n";
		cout<<"Angka "<<x<<" ditemukan pada posisi "<<urut+1;
	}
	else
	{
		cout<<" \n";
		cout<<"Angka "<<x<<" tidak ditemukan";
	}
	getch();
	return 0;
}

