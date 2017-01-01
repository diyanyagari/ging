#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int temp,j;
	int angka[8]={7,5,12,30,2,19,11,8};
	cout<<"Program Insertion Sort\n";
	cout<<"=======================\n";
	cout<<"dengan data : \n";
	for (int p=0;p<8;p++)
	{
		cout<<angka[p]<<" ";
	}
	cout<<"\n";
	cout<<"=================================\n";
	for (int i=1;i<=7;i++)
	{
		j=i;
		while (j>0 && angka[j]<angka[j-1])
		{
			temp=angka[j];
			angka[j]=angka[j-1];
			angka[j-1]=temp;
			j--;
		}
	}
	cout<<"\n";
	for (int q=0;q<8;q++)
	{
		cout<<angka[q]<<" ";
	}
}
