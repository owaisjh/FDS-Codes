#include<iostream>
using namespace std;

class emp
{
	public:
	int id;
	emp* link;
};
emp* rear;
emp* first;
	
int menu()
{	
	int ch;
	cout<<"\n1)To Create a list:";
	cout<<"\n2)To Display a list:";
	cout<<"\n3)To do operations at posi";
	cout<<"\n4)To do operations at an id";
	cout<<"\n5)To add more elements at the end";
	cout<<"\n6)To exit\n";	
	cin>>ch;
	return ch;
}
void create(emp* first)
{
	emp* temp=new emp;	
	cout<<"\nEnter Id:";
	cin>>temp->id;
	if(temp->id != 0)
	{
		first->link=temp;
		create(temp);
	}
	else if(temp->id==0)
	{
		first->link=NULL;
		rear=first;
	}
}

void display(emp* first)
{
	cout<<first->id<<endl;
	if(first->link!=NULL)
	{
		display(first->link);
	}

}
emp* search(emp* first,int pos,int count)
{
	if (pos==count)
	{
		return(first);
	}
	else if(first==rear && pos!=count)
	{
		return NULL;
	}
	else 
	{
		search(first->link,pos,++count);
	}
}
void adda(emp* temp)
{
	emp* add= new emp;
	cout<<"\nEnter id:";
	cin>>add->id;
	if (temp!=rear)
	{	
		add->link=temp->link;
		temp->link=add;
	}
	else
	{
		temp->link=add;
		add->link=NULL;
		rear=add;
	}
}
void addb(emp* temp,emp** first)
{
	emp* add= new emp;
	emp* lol= *first;
	cout<<"\nEnter id:";
	cin>>add->id;
	add->link=temp;
	if(temp!=*first)	
	{
		while(lol->link!=temp)
		{
			lol=lol->link;
		}
		lol->link=add;
	}
	else
	{
		*first=add;
	}
}
void del(emp* temp,emp** first)
{
	if(temp==(*first))
	{
		*first= (*first)->link;
		delete temp;
	}
	else if(temp ==rear)
	{
		emp* lol=*first;
		while(lol->link!=temp)
			lol=lol->link;
		lol->link=NULL;
		rear=lol;
		delete temp;
	}
	else if (temp!= *first && temp!=rear)
	{
		emp* lol=*first;
		while(lol->link!=temp)
			lol=lol->link;
		lol->link=temp->link;

	} 	

}
emp* search2(emp* first, int num)
{	
	if (num == first->id)
		return first;
	else if(first==rear && num!=first->id)
		return NULL;
	else
		search2(first->link,num);

}
void func(emp* temp,emp** first)
{
	cout<<"\nFound:"<<temp->id;
	cout<<"\n1)To add before";
	cout<<"\n2)To add after:";
	cout<<"\n3)To delete:";
	cout<<"\n0)To exit:";
	int c;
	cin>>c;
	cout<<endl<<endl;
	if(c==1)
		addb(temp,&(*first));
	else if(c==2)
		adda(temp);
	else if(c==3)
		del(temp,&(*first));
	else if(c==0)
		cout<<"\nMoving back to main menu:\n";
	else 
	{
		cout<<"\nEnter Valid";	
		func(temp,&(*first));
	}

}
int main()
{
	int ch;
	while (ch!=6)
	{
		ch= menu();
		if(ch==1)
		{	
			first=new emp;
			cout<<"\nEnter Id:";
			cin>>first->id;	
			if(first->id!=0)		
			{
				create(first);
			}
			else
			{
				first->link=NULL;
				rear=first;
			}
			display(first);
		}
		else if(ch==2)
		{
			cout<<"\n\n";
			display(first);
		}
		else if(ch==3)
		{
			int pos;
			cout<<"\nEnter Position:";
			cin>>pos;
			emp* temp=search(first,pos,1);
			if(temp!=NULL)
				func(temp,&first);

			else 
				cout<<"\nNOT FOUND";				
		}
		else if(ch==4)
		{
			int num;
			cout<<"\nEnter the id:";
			cin>>num;
			emp* temp=search2(first,num);
			if(temp!=NULL)
				func(temp,&first);

			else 
				cout<<"\nNOT FOUND";
		}
		else if(ch==5)
		{
			create(rear);
			display(first);
		}
	}
	return 0;
}
