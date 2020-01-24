#include <iostream>

using namespace std;

int q[10];
int size=10;
int f=-1;
int r=-1;

void enqueue(int a)
{
	if(f==-1)
		f++;
	if(r+1!=size)	
	{
		r++;
		q[r]=a;
	}
}
bool IsFull()
{
	if(r==size-1)
		return true;
	else 
		return false;
}
bool IsEmpty()
{
	if(r==-1 && f==-1)
		return true;
	else 
		return false;
}
int dequeue()
{
	if (f!=-1)
	{
		int temp=q[f];
		q[f]=0;
		f++;
		if(f>r)
			f=r=-1;
		return temp;
	}
	else 
		cout<<"\nEMPTY";
}
void display()
{
	for(int x=f;x<=r;x++)
		cout<<q[x]<<endl;

}

int menu()
{
	int ch;
	cout<<"\n1) To add elements";
	cout<<"\n2) To display elements";
	cout<<"\n3) To delete elements";
	cout<<"\n4) To check full";
	cout<<"\n5) To check empty";
	cout<<"\n6) To exit\n";
	cin>>ch;
	return ch;
}


int main()
{
	int ch;
	do
	{
		ch=menu();
		if(ch==1)
		{
			int e;
			cout<<"\nEnter the element to add-";
			cin>>e;
			enqueue(e);
			display();
		}
		else if(ch==2)	
		{
			display();
		}	
		else if(ch==3)	
		{	
			dequeue();
			display();
		}
		else if(ch==4)
		{
			cout<<IsFull()<<endl;
		}
		else if(ch==5)
		{
			cout<<IsEmpty()<<endl;
		}
		
		

	}while(ch!=6);


	return 0;
}
