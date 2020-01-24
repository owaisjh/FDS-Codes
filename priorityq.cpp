#include<iostream>
using namespace std;

struct node
{
	char ch;
	int pri;
};
node q[100];
int f=-1;
int r=-1;

void ENQUEUE()
{
	r++;
	node temp;
	cout<<"\n\n Enter char : ";
	cin>>temp.ch;

	cout<<"\n\n Enter pri : ";
	cin>>temp.pri;
	
	if(f==-1)
	{	
		f=0;
		q[f].pri=temp.pri;
		q[f].ch=temp.ch;
		return;
	}
	
	for(int i=f;i<r;i++)
	{

		if(temp.pri<q[i].pri)
		{	
			int rep=r;
			while(rep>i)
			{
				q[rep].pri=q[rep-1].pri;
				q[rep].ch=q[rep-1].ch;
				rep--;
			}
	

			q[i].pri=temp.pri;
			q[i].ch=temp.ch;
			break;
		}
		if(i==r-1 && !(temp.pri<q[i].pri))
		{
			q[r].pri=temp.pri;
			q[r].ch=temp.ch;

		}
		
	}	
}		

void DISP()
{
	if(f == -1)
	{
		cout<<"\n\n PRI Q IS EMPTY ";
	}
	else
	{
		for(int i=f;i<=r;i++)
		{
			cout<<"\n\n "<<q[i].ch<<"["<<q[i].pri<<"]";
			
		}
	}
}


void DEQUEUE()
{
	if(f == -1)
	{
		cout<<"\n\n PRI Q IS EMPTY ";
	}
	else
	{
		f++;
	
	}
	if(f > r)
	{
		f=r=-1;
	}
}

int menu()
{
	int ch;

	cout<<"\n\n 1] ENQUEUE ";
	cout<<"\n\n 2] DISP ";
	cout<<"\n\n 3] DEQUEUE ";
	cout<<"\n\n 4] EXIT ";

	cout<<"\n\n  Enter your choice : ";
	cin>>ch;
	return ch;

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
				ENQUEUE();
				DISP();
				break;
			case 2:
				DISP();
				break;
		   	case 3:
				DEQUEUE();
				DISP();
				break;
		  	case 4:
				cout<<"\n\n EXIT ";
			     	break;
			   
		  	default:
			   	cout<<"\n\n INVALID INPUT  ";
	       }

	  }while(ch != 4);
	return 0;
     }
