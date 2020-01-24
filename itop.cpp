#include<iostream>
#include<cstring>
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
}
char peak()
{
	if(top!=-1)
		return stk[top];
}
int chkpri(char c)
{
	if(c=='{' || c=='(' || c=='[')	
		return 0;
	else if (c=='+' || c=='-')
		return 1;
	else if(c=='/' || c=='*')
		return 2;
	


}

int main()
{
	char a[100];
	char b[100];
	cout<<"\nEnter the INFIX:\n";
	cin>>a;
	int j=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='(' || a[i]=='[' || a[i]=='{')
		{
			push(a[i]);
		}
		else if(isalpha(a[i]))
		{
			b[j]=a[i];
			j++;
		}
		else if(a[i]=='+' || a[i]=='-'  || a[i]=='*' || a[i]=='/' )
		{
			if(chkpri(a[i])>chkpri(stk[top]))
				push(a[i]);
			else
			{
				while(chkpri(a[i])<=chkpri(stk[top]) && top!=-1)
				{
					b[j]=pop();
					j++;
				}
				push(a[i]);
			}

		}
		else if(a[i]=='}' || a[i]==']' || a[i]==')')
		{
			while(stk[top]!='{' && stk[top]!='(' && stk[top]!='[')
			{
				b[j]=pop();
				j++;
			}
			pop();
		}
	}
	while(top!=-1)
	{
		b[j]=pop();
		j++;

	}

	b[j]='\0';
	cout<<"\nPOSTFIX:\n"<<b<<endl;
	return 0;
	

	


}
