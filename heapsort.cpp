#include <iostream>

using namespace std;


void heapsort(int x[], int size)
{
	for(int i=0;i<size;i++)
	{
		int c=i;
		int temp;
		do
		{
			int r=(c-1)/2;
			if(x[c]>x[r])
			{
				temp=x[r];
				x[r]=x[c];
				x[c]=temp;
			}
			c=r;
		}while(c!=0);
		
		temp=x[0];
		x[0]=x[size-1];
		x[size-1]=temp;
	}
	if(size>1)
		heapsort(x,size-1);
}


int main()
{
	int size;
	

	cout<<"\nEnter Size:";
	cin>>size;
	int heap[size];
	cout<<"Enter elements:\n";
	for(int i=0;i<size;i++)
	{
		cin>>heap[i];
	}
	heapsort(heap,size);

	cout<<"\nSorted:\n";
	for(int i=0;i<size;i++)
	{
		cout<<heap[i]<<" ";
	}
	return 0;
}


mail kar heap sort,im sleeping, bye thanks love you too
	for(int i=0;i<size;i++)
	{
		int c=i;
		do
		{
			int r= (c-1)/2;
			if(x[c]>x[r])
			{
				int temp= x[r];
				x[r]=x[c];
				x[c]=temp;
			}
			c=r;
		}while(c!=0);
	}

	int temp=x[0];
	x[0]=x[size-1];
	x[size-1]=temp;
	
	if(size>1)
		heapsort(x,size-1);
