#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

struct node
{
	char ch;
	node* left;
	node* right;
};

node* stk[100];
int top=-1;

void push(node* ch)
{
	stk[++top]=ch;
}
node* pop()
{
	if(top!=-1)
		return stk[top--]; 
}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->ch;
		inorder(root->right);
	}
}
void preorder(node* root)
{
	if(root!=NULL)
	{
		cout<<root->ch;		
		preorder(root->left);		
		preorder(root->right);
	}
}
void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->ch;
	}
}
int main()
{
	char post[100];
	cin>>post;
	node* newnode;
	for(int i=0;post[i]!='\0';i++)
	{
		newnode= new node;
		newnode->ch=post[i];
		newnode->left=newnode->right=NULL;
		if(isalpha(post[i]))
		{
			push(newnode);
		}
		else
		{
			newnode->right=pop();
			newnode->left=pop();
			push(newnode);
		}
	}
	node* root=pop();
	cout<<"\n\nINORDER:\n";
	inorder(root);

 	cout<<"\n\nPREORDER:\n";
	preorder(root);

	cout<<"\n\nPOSTORDER:\n";
	postorder(root);




	return 0;
}
