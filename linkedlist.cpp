#include <iostream>

using namespace std;




class emp
{	
	public:
	int id;

	emp* prev;
	emp* link;
};

int menu()
{	
	int a;
	cout<<"\nTo add elements :1";
	cout<<"\nTo see elements :2";
	cout<<"\nTo move up and down :3";
	cout<<"\nTo find a fixed element :4";
	cout<<"\nTo delete any number 5\n";	
	cout<<"\nTo exit press :6\n";
	cin>>a;
	return a;
	
}

void create(emp* first,emp* rear)
{
	cout<<"\n enter id:";
	cin>>first->id;
	first->prev=rear;
	if(first->id!=0)
	{
		first->link= new emp;
		create(first->link,first);
	}
	if(first->id==0)
	{
		first->prev->link=NULL;

	}	
}
void display(emp* first)
{
	cout<<first->id;
	cout<<endl;
	if(first->link != NULL)	
		display(first->link);
}
void ud(emp* first)
{
	char a=2;
	cout<<first->id;
	while (a!='0')
	{
		cin>>a;
		if(a=='w')
		{	
			if(first->prev != NULL)
			{	
				first=first->prev;
				cout<<first->id;
			}
			else
			{
				cout<<"\n1st Entry cant go more up\n";

			}
		}
		else if(a=='s')
		{
			if(first->link != NULL)
			{
				first=first->link;
				cout<<first->id;
			}
			else
			{
				cout<<"\nLast Entry cant go more down\n";

			}
		}
	}	


}
emp* search(emp* first, int n,int count)
{
	if (count!=n && first->link == NULL)
	{	
		cout<<"\n So many elements dont exist\n";
		return NULL;
	}	


	else if(count==n)
		return first;
	else
		return (search(first->link,n,++count));



}

void del(emp* save,emp** first)
{

	
	if (save-> prev == NULL)
	{
		save->link->prev=NULL;
		*first=save->link;
		delete save;

	}
	else if (save->link == NULL)
	{
		save->prev->link=NULL;
		delete save;

	}
	
	else
	{
		save->prev->link=save->link;
		save->link->prev=save->prev;
		delete save;
	}	
	

}
void adda(emp* save)
{
		
	emp* temp=new emp;
	cout<<"\nEnter id:";	
	cin>>temp->id;
	if(save->link != NULL)
	{		
		temp->link=save->link;
		temp->prev=save;
		save->link->prev=temp;
		save->link=temp;
	}
	else
	{
		temp->link=NULL;
		temp->prev=save;	
		save->link=temp;
	}
}
void addb(emp* save,emp** first)
{
	emp* temp = new emp;
	cout<<"\nEnter id:";
	cin>>temp->id;
	if(save->prev != NULL)
	{
		temp->prev=save->prev;
		temp->link=save;
		save->prev->link=temp;
		save->prev=temp;
	}
	else
	{
		temp->prev=NULL;
		temp->link=save;
		save->prev=temp;	
		*first=temp;

	}


}


void func(emp* save,emp** first)
{	int a;
	cout<<"\nEnter if you want to\n1)Delete\n2)Add After\n3)Add Before"; 
	cin>>a;
	if(a==1)
		del(save,&(*first));
	else if(a==2)
		adda(save);
	else if(a==3)
		addb(save,&(*first));
	else
		cout<<"Enter a valid value";
}
emp* search2(emp* first,int n)
{
	if(first->id==n)
		return first;
	else if(first->link != NULL)
		return search2(first->link,n);
	else if(first->link == NULL)
		return NULL;
}

void del2(emp** first,emp* temp)
{
	
	if( temp->prev != NULL && temp->link != NULL)
	{
		temp->prev->link=temp->link;
		temp->link->prev=temp->prev;
		delete temp;
	}
	else if(temp->prev == NULL && temp->link != NULL)
	{
		temp->link->prev=NULL;
		(*first)=(*first)->link;
		delete temp;
		
	}
	else if( temp->prev != NULL && temp->link == NULL)
	{
	
		temp->prev->link=NULL;
		delete temp;
	}
	else if(temp->prev == NULL && temp->link == NULL)
	{
		delete temp;
	}
	else if (temp==NULL)
		cout<<"Entry NOT FOUND";
	

}

int main()
{
	
	emp* first;
	int f=0;
	while(f!= 6)
	{
		f=menu();
		cout<<endl<<endl;
		if(f==1)
		{
			first= new emp;
			create(first,NULL);
			display(first);

		}	
		else if(f==2)
		{
			display(first);

		}
		else if (f==3)
		{	cout<<"\nW for up and S for down and 0 to Exit\n";
			ud(first);		
	
		}
		else if (f==4)
		{
			int n;
			cout<<"Enter the the number of the term :";
			cin>>n;
			emp* save;
			save=search(first,n,1);
			if(save!=NULL)
			{	cout<<endl<<save->id<<endl;
				func(save,&first);
			}
			display(first);
		
		}
		else if(f==5)
		{
			int n;
			cout<<"Enter the value to delete:";
			cin>>n;
			emp* temp=search2(first,n);		
			del2(&first,temp);
			
			display(first);
		
		}
	}
	return 0;
		
	
}

