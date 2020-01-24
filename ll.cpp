#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};
node* front=NULL;


void display(node* pashva)
{
	cout<<pashva->data<<endl;
	if(pashva->next != NULL)
		display(pashva->next);
}
void add(int num)
{
	node* temp= new node;
	temp->data=num;
	if(front==NULL)
		front=temp;
	else
		
		


}





int menu()
{
	cout<<"\n1)";







}

int main()
{














	return 0;
}
