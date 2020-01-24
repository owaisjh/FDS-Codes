#include <iostream>
using namespace std;


class q
{
	public:
	int num;
	q* next;
};
q* first = NULL;
q* last = NULL;


int menu()
{	int ch;
	cout<<"\nFor Creating 1:";
	cout<<"\nTo Display 2:";
	cout<<"\nTo Move Down 3:";
	cout<<"\nTo Add at the begining 4";
	cout<<"\nTo Add at the end 5";
	cout<<"\nTo Remove any Element 6";
	cout<<"\nTo add after a fixed entry 7";
	cout<<"\nTo add before a fixed entry 8 ";
	cout<<"\nTo exit 9\n";	
	cin>>ch;
	cout<<endl<<endl<<endl;
	return ch;
}

void add(q* start)
{	
	q* temp= new q;
	cout<<"\nEnter data and 0 to stop: ";
	cin>>temp->num;
	if(temp->num!=0)
	{
		start->next=temp;
		add(temp);
	}
	else
	{
		last=start;
		start->next=first;
	}

}
void ud(q* first)
{
	char a=2;
	cout<<first->num;
	while (a!='0')
	{
		cin>>a;
		
		if(a=='s')
		{
			
			
				first=first->next;
				cout<<first->num;
			
			
		}
	}	


}
void display(q* start)
{
	do
	{
		cout<<start->num<<endl;
		start=start->next;

	}while(start!=first && start!=NULL);


}
void addbig(q* start)
{
	q* temp= new q;
	cout<<"Enter the entry: ";
	cin>> temp->num;
	temp->next=start;
	first= temp;
	last->next= first;
	
}
void addend(q* start)
{
	q* temp= new q;
	cout<<"Enter the entry: ";
	cin>> temp->num;
	temp->next=start;
	last->next= temp;
	last= temp;
	
}
void rm(q* start,int n)
{
	if (first == start && n==start->num)
	{
		q* temp=first;
		first=first->next;
		last->next=first;
		delete temp;
	}
	else if(last == start && n==start->num)
	{
		q* temp = last;
		q* end=first;
		while(end->next!= last)
			end=end->next;
		last=end;
		end->next=first;
		delete temp;
	}
	else if(n==start->num)
	{
		q* temp = start;
		q* end=first;
		while(end->next!= start)
			end=end->next;
		end->next=end->next->next;
		delete temp;

	}
	else if(n!= start->num && start==last)
	{
		cout<<"\nEntry does not exit\n";

	}
	else
		rm(start->next,n);



}
void adda(q* start,int tnum, int nnum)
{
	if( tnum==start->num && start!=last)
	{
		q* temp = new q;
		temp->num=nnum;
		temp->next=start->next;
		start->next=temp;
	}
	else if (tnum!=start->num && start==last)
	{
		cout<<"\nTarget not found\n\n";
	}
	else if(tnum == start->num && start==last)
	{
		q*temp = new q;
		temp->num=nnum;
		temp->next= first;
		start->next = temp;

	}	
		
	else
		adda(start->next,tnum,nnum);


}
void addb(q* start,int tnum, int nnum)
{
	if( tnum==start->num && start==first)
	{
		q* temp = new q;
		temp->num=nnum;
		temp->next=first;
		last->next=temp;
		first=temp;
	}
	else if (tnum!=start->num && start==last)
	{
		cout<<"\nTarget not found\n\n";
	}
	else if(tnum == start->num)
	{
		q*temp = new q;
		q* end=first;
		temp->num=nnum;
		while(end->next!= start)
			end=end->next;
		temp->next=end->next;
		end->next=temp;
	}	
		
	else
		addb(start->next,tnum,nnum);


}


int main()
{
	int ch;
	do
	{		
		ch =menu();
		if (ch==1)
		{
			first = new q;
			cout<<"\nEnter data and 0 to stop:";
			cin>>first->num;
			if(first->num!=0)
			{
				add(first);
			}
			else 
			{
				first->next = NULL;
				last=first;
			}
			
		}
		else if(ch==2)
		{
			display(first);


		}

		else if(ch==3)
		{
			ud(first);


		}
		else if(ch==4)
		{
			addbig(first);
			display(first);
		}
		else if(ch==5)
		{
			addend(first);
			display(first);
		}
		else if(ch==6)
		{	
			int n;
			cout<<"\nEnter the value u want to delete:";
			cin>>n;
			rm(first,n);
			display(first);

		}
		else if(ch==7)
		{
			int tnum,nnum;
			cout<<"\nEnter Target NUM:";
			cin>>tnum;
			cout<<"\nEnter New NUM:";
			cin>>nnum;
			adda(first,tnum,nnum);
			display(first);

		}
		else if(ch==8)
		{
			int tnum,nnum;
			cout<<"\nEnter Target NUM:";
			cin>>tnum;
			cout<<"\nEnter New NUM:";
			cin>>nnum;
			addb(first,tnum,nnum);
			display(first);

		}

	}
	while(ch!=9);



	return 0;
}
	
