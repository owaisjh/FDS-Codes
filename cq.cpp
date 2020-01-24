#include <iostream>

using namespace std;
int arr[5];
int size=5;
int f=-1;
int r=-1;

int menu()
{
	
	cout<<"\n1)To Add an element.\n2)To Delete the first element.\n3)To Display all elements.\n4)To exit\n";
	int n;	
	cin>>n;
	return n;

}
void add()
{
	if((f==0 && r==size-1) || r==f-1)
	{
		cout<<"\nOVERFLOW\n";
		return;
	}
	if(f==-1)
	{
		f=0;
	}
	if(r==size-1)
	{
		r=-1;
	}
	r++;
	cout<<"\nEnter the new term:";
	cin>>arr[r];

}


void del()
{
	if(f==-1)
		cout<<"\nEMPTY\n";
	else
	{
		arr[f]=0;	
		f++;

	}
	if(f==r+1)
	{
		
		f=-1;
		r=-1;
	}
	if(f==size)
		f=0;

}
void disp()
{
	if (f<=r)
	{
		for(int i=f;i<=r;i++)
			cout<<arr[i]<<"  ";

	}
	else
	{
		for(int i=f;i<size;i++)
			cout<<arr[i]<<"  ";
		for(int i=0;i<=r;i++)
			cout<<arr[i]<<"  ";
		
	}
	cout<<endl<<endl;


}


int main()
{
	int e;
	do
	{
		e=menu();
		if(e==1)
		{		
			add();
			disp();
		}
		else if(e==2)
		{		
			del();
			disp();
		}	
		else if(e==3)
		{		
			disp();
		}
	}while(e!=4);
	return 0;
}
