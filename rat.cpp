#include <iostream>
using namespace std;

int a[100][100]={0};
int ans[100000][2];
int size=-1;

int func(int x1,int y1, int x2, int y2,int n)
{
	if(x1==n && y1==n)
	{
		
		size++;
		ans[size][0]=x1;
		ans[size][1]=y1;
		return 1;			
	}
	else if(a[x1][y1+1]!= 0 || a[x1][y1-1]!=0 || a[x1+1][y1]!=0 || a[x1-1][y1]!=0 )
	{	
		if(a[x1][y1+1]== 1 && y1+1!=y2)
		{	if(func(x1,y1+1,x1,y1,n))	
			{
				size++;
				ans[size][0]=x1;
				ans[size][1]=y1;
				return 1;
			}
			
		}
	
		if( a[x1][y1-1]==1 && y1-1!=y2)
		{
			if(func(x1,y1-1,x1,y1,n))
			{
				
				size++;
				ans[size][0]=x1;
				ans[size][1]=y1;
				return 1;
			}
			
		}	
		if( a[x1+1][y1]==1 && x1+1!=x2)
		{
			if(func(x1+1,y1,x1,y1,n))
			{
				
				size++;
				ans[size][0]=x1;
				ans[size][1]=y1;
				return 1;
			}
			else
				return 0;
	
		}	
		if( a[x1-1][y1]==1 && x1-1!=x2)
		{
			if(func(x1-1,y1,x1,y1,n))
			{
				size++;
				ans[size][0]=x1;
				ans[size][1]=y1;
				return 1;
			}
			
		}
		else 
			return 0;
	}
	
	else 
		return 0;
	
		 
			



}

int main()
{
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	for(int i=1;i<n+1;i++)
	{	
		for(int j=1;j<n+1;j++)
			cin>>a[i][j];
		
	}
	if(func(1,1,1,1,n))
	for(int i=size;i>=0;i--)
	{
		cout<<ans[i][0]<<" , "<<ans[i][1]<<endl;
	}
	else 
		cout<<"\n NO path";
	return 0;
}
