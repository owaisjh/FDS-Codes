#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int a[100][100]={0};
//int ans[100000][2];
int size=0;
vector <int> t;
void func(int x1,int y1, int x2, int y2,int n)
{
	if(x1==n && y1==n)
	{
		
		size++;			
	}
	else if(a[x1][y1+1]!= 0 || a[x1][y1-1]!=0 || a[x1+1][y1]!=0 || a[x1-1][y1]!=0)
	{	
	
			if(a[x1][y1+1]== 1 && y1+1!=y2 )
			{	
				int l=(x1*10) + (y1+1);
				
				if(find(t.begin(),t.end(),l) != t.end())
					return ;
				
				else 
				{
					t.push_back(l);
					func(x1,y1+1,x1,y1,n);	
				
				}

			}	
		
	
			if( a[x1][y1-1]==1 && y1-1!=y2)
			{	
				int l=(x1*10) + (y1-1);
				
				if(find(t.begin(),t.end(),l) != t.end())
					return ;
				
				else
				{
					t.push_back(l);
					func(x1,y1-1,x1,y1,n);
				}
			}		
	
			if( a[x1+1][y1]==1 && x1+1!=x2)
			{
				int l=((x1+1)*10) + y1;
				
				if(find(t.begin(),t.end(),l) != t.end())
					return ;

				
				else
				{
					t.push_back(l);
					func(x1+1,y1,x1,y1,n);
				}

			}	
		
			if( a[x1-1][y1]==1 && x1-1!=x2)
			{
				int l=((x1-1)*10) + y1;
	
				if(find(t.begin(),t.end(),l) != t.end())
					return ;

				
				else
				{
					t.push_back(l);
					func(x1-1,y1,x1,y1,n);
				}
				
			}
		
	}

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
	func(1,1,1,1,n);
	cout<<"\nThe number of paths="<<size;
	return 0;
}
