#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
void rev(char a[100])
{
	int b=strlen(a);
	for(int i=0;i<b/2;i++)
	{
		char temp=a[i];
		a[i]=a[b-1-i];
		a[b-1-i]=temp;

	}

}

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
}
int chkpri(char op)
{
	if(op=='+' || op=='-')
	{
		return 0;
	}
	
	else if(op=='*' || op=='/'|| op=='%')
	{
		return 1;
	}
	else
	{
		return -1;
	}

}

int main()
{
	char a[100];
	cin>>a;
	rev(a);
	char p[100];
	
	int c=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(isalpha(a[i]))
		{
			p[c]=a[i];
			c++;
		}
		else if(a[i]==')')
		{
			push(a[i]);

		}
		else if(a[i]=='*' || a[i]=='/' || a[i]=='%' || a[i]=='+' || a[i]=='-')
		{
			while(top!=-1 && chkpri(stk[top])>chkpri(a[i]))
			{
				p[c]=pop();
				c++;
			}
			push(a[i]);

		}
		else if(a[i] == '(')
		{
			while(stk[top]!=')')
			{
				p[c]=pop();
				c++;
			}
			pop();
		}
	}
	while(top!=-1)
	{
		p[c]=pop();
		c++;
	}	
	rev(p);
	cout<<p;




}
