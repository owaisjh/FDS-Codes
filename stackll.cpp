#include<iostream>

using namespace std;

class st
{
	public:
	int num;
	st* prev;


};
st* top=NULL;
int menu()
{	int ch;
	cout<<"\n1 To Push";
	cout<<"\n2 To Pop";
	cout<<"\n3 To Peak";
	cout<<"\n4 To display";
	cout<<"\n5 To exit\n";
	cin>>ch;
	return ch;


}

void push()
{
	st* temp = new st;	
	cout<<"Enter the  Num and 0 for exit:";
	cin>>temp->num;
	if(temp->num != 0)
	{	
		temp->prev=top;
		top=temp;
		push();
	}
	else
	{
		delete temp;	
	}	
	
}
void pop()
{
	st* temp= new st;
	temp=top;
	top=temp->prev;
	delete temp;
}
void display(st* no)
{	
	if(no!=NULL)
	{
		cout<<endl<<no->num;
		if(no->prev!=NULL)
		display(no->prev);
	}
	else if(top==NULL)
		cout<<"\nEMPTY STACK";
	

}


int main()
{
	int ch;
	
	do
	{
	ch = menu();
		switch(ch)
		{
			case 1:
				push();
				display(top);
				cout<<endl<<endl;
				break;
			case 2:	
				pop();
				display(top);
				cout<<endl<<endl;	
				break;
			case 3: 
				if(top!=NULL)
					cout<<endl<<top->num;
				else
					cout<<"\nEMPTY STACK";
				break;
			case 4:	
				display(top);
				cout<<endl<<endl;		
				break;
			case 5:			
				break;
			default:
				cout<<"Enter Valid Value";
				

		}
	}while(ch!=5);
	
return 0;



}

