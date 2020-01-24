#include <iostream>
using namespace std;
char stk1[100];
int top1=-1;

char stk2[100];
int top2=-1;

void push1(int ch)
{
	if(top<100)
	{
		top1++;
		stk1[top]=ch
	}
	else
		cout<<"\n\nSTACK OVERFLOW";
}
void push2(char ch)
{
	if(top<100)
	{
		top1++;
		stk2[top]=ch
	}
	else
		cout<<"\n\nSTACK OVERFLOW";
}
int pop1()
{
	if(top>=0)
	{
		return(stk1[top1--]);
	}
	else
	{
		cout<<"\n\nEmpty Stack";
	}
}
char pop2()
{
	if(top>=0)
	{
		return(stk2[top2--]);
	}
	else
	{
		cout<<"\n\nEmpty Stack";
	}
}
int chkpri(char ch)
{
	if(ch=='*'||ch=='/')
		return 1;
	if(ch=='+'||ch=='-')
		return 2;

}

int main()
{
	char str[100];
	cin.getline(str,100);
	for(int i=0;str[i]!='\0';i++)
	{
		if(isnum(str[i])==1)
		{
			push1(str[i])
		}

	}	
	



	return 0;
}
