#include <iostream>
#include <cstring>
using namespace std;
char stk[100];
int top=-1;

void push(char ch)
{
	top++;
	stk[top]=ch;
}



char pop()
{
	if(top!=-1)
		return stk[top--];
	else 
		return 0;

}



int main()
{
	char a[100];
	cout<<"\nEnter the statement:\n";
	
	cin.getline(a,100);
	int flag=1;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
			push(a[i]);
		else
		{
			if(a[i]==')')
			{
				if (pop()!='(')
				{
					flag=0;
					break;
				}
	
			}
			
			if(a[i]=='}')
			{
				if (pop()!='{')
				{
					flag=0;
					break;
				}
\
			}
			
			if(a[i]==']')
			{
				if (pop()!='[')
				{
					flag=0;
					break;
				}	
			}
		
		}		
	}
	if (flag != 1 || top!=-1)
		cout<<"\n\nInvalid Paranthesis";
	else
		cout<<"\n\nValid";



}
