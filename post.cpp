#include <iostream>
#include <cstring>
using namespace std;
float stk[100];
int top=-1;
void push(float ch)	
{
	top++;
	stk[top]=ch;
}
float pop()
{
	if(top!=-1)
		return(stk[top--]);
}
int main()
{
	char a[100];
	float n1,n2,an;
	cout<<"\n\nEnter the Postfix Statement:\n";
	cin.getline(a,100);
	int i=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>=48 && a[i] <=58)
		{
			push(a[i]-'0');
		}
		else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
		{	
			n2=pop();
			n1=pop();
			if(a[i]=='+')
			{
				an=n1+n2;
			}
			else if(a[i]=='-')
			{
				an=n1-n2;
			}
			else if(a[i]=='*')
			{
				an=n1*n2;
			}	
			else if(a[i]=='/')
			{
				an=n1/n2;				
			}
			push(an);
		}
	}
	cout<<"\nAnswer is:"<<stk[top];
	return 0;
}
