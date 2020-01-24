#include <iostream>

using namespace std;


struct node
{
	int num;
	node* left;
	node* right;

};
int count=0;
int menu()
{
	int ch;
	cout<<"\n 1] INSERT A NODE ";
	cout<<"\n 2] INORDER TRAVERSAL ";
	cout<<"\n 3] PREORDER TRAVERSAL ";
	cout<<"\n 4] POSTORDER TRAVERSAL ";
	cout<<"\n 5] COUNT ALL NODES ";
	cout<<"\n 6] COUNT LEAF NODES ";
	cout<<"\n 7] COUNT BRANCH NODES ";
	cout<<"\n 8] FIND MIN ";
	cout<<"\n 9] FIND MAX ";
	cout<<"\n 10] Delete a Node ";
	cout<<"\n 11] EXIT \n";
	cin>>ch;
	return ch;
}
node* insert(node* root,int n)
{
	if(root==NULL)
	{
		root=new node;
		root->num=n;
		root->left=root->right=NULL;
	}
	else if(n>root->num)
		root->right=insert(root->right,n);
	else if(n<=root->num)
		root->left=insert(root->left,n);
	return root;
}
void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->num;
		inorder(root->right);
	}
}
void preorder(node* root)
{
	if(root!=NULL)
	{
		cout<<" "<<root->num;
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
		cout<<" "<<root->num;
	}
}

void countall(node* root)
{
	if(root!=NULL)
	{
		countall(root->left);
		countall(root->right);
		count++;
	}

}
void countleaf(node* root)
{
	if(root!=NULL)
	{
		countleaf(root->left);
		countleaf(root->right);
		if(root->left==NULL && root->right==NULL)
			count++;
	}	


}
void countbranch(node* root)
{
	if(root!=NULL)
	{
		countbranch(root->left);
		countbranch(root->right);
		if(root->left!=NULL || root->right!=NULL)
			count++;
	}
}
node* fmin(node* root)
{
	if(root->left!=NULL)
		return fmin(root->left);
	else 
		return root;
}
node* fmax(node* root)
{
	if(root->right!=NULL)
		return fmax(root->right);
	else 
		return root;		
}

node* del(node* root,int n)
{	
	if(root==NULL)
		cout<<"\nNUM not found";
	
	else if(root->num==n)
	{
		if(root->left == NULL && root->right == NULL)
		{
			root=NULL;
		}	
		else if(root->left == NULL)
		{
			root=root->right;
		}
		else if(root->right == NULL)
		{
			root=root->left;
		}
		else
		{
			node* temp;
			temp=fmax(root->left);
			root->num=temp->num;
			del(root->left,root->num);

		}
	}

	else if(n>root->num)
		root->right=del(root->right,n);
	else if(n<root->num)
		root->left=del(root->left,n);
	

	return root;
}

int main()
{
	int ch,n;
	node* root=NULL;
	do
	{
		ch=menu();
		if(ch==1)
		{
			int num;
			cout<<"Enter the num:";
			cin>>num;	
			root=insert(root,num);
		}
		else if(ch==2)
		{
			inorder(root);	
		}
		else if(ch==3)
		{
			preorder(root);	
		}
		else if(ch==4)
		{
			postorder(root);	
		}	
		else if(ch==5)
		{
			count=0;
			countall(root);	
			cout<<"\nCount="<<count;		

		}
		else if(ch==6)
		{
			count=0;
			countleaf(root);
			cout<<"\nCount="<<count;
		}
		else if(ch==7)
		{
			count=0;
			countbranch(root);
			cout<<"\nCount="<<count;
		}
		else if(ch==8)
		{
			node* temp=fmin(root);
			cout<<"\nMin:"<<temp->num;	
		}
		else if(ch==9)
		{
			node* temp=fmax(root);
			cout<<"\nMax:"<<temp->num;
		}
		else if(ch==10)
		{
			int num;
			cout<<"\nEnter the number to delete:";
			cin>>num;
			root=del(root,num);						


		}

	}while(ch!=11);


	return 0;
}
