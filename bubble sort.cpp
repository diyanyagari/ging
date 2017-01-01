#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
	int data[8]={8,19,17,20,7,5,11,13};
	int i,j,temp;
	cout<<"  Program Ini Akan Mengurutkan Angka Berikut : \n";
	for (int a=0;a<=7;a++)
	{
		cout<<data[a]<<" ";
	}
	cout<<"\n==============================================\n";
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			if (data[i]>data[j])
			{
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
	cout<<"Data Setelah Diurutkan : \n";
	for (i=0;i<8;i++)
	{
		cout<<data[i]<<" ";
	}
	getch();
}
