#include<iostream>
using namespace std;

int count;
struct node
{
	int num;
	node* left;
	node* right;
};


int menu()
{
	int ch;
	cout<<"1)To Add";
	cout<<"\n2)For Inorder";
	cout<<"\n3)For Preorder";
	cout<<"\n4)For Postorder";
	cout<<"\n5)For counting all nodes";
	cout<<"\n6)For counting all leaf nodes";
	cout<<"\n7)For counting all branch nodes";
	cout<<"\n8)For Finding MIN";
	cout<<"\n9)For Finding MAX";
	cout<<"\n10)To Delete";
	cout<<"\n11)To exit\n";
	


	cin>>ch;
	return ch;

}
node* add(node* root,int n)
{
	if (root!=NULL)
	{
		if(n>root->num)
			root->right=add(root->right,n);
		else
			root->left=add(root->left,n);
	}
	else
	{
		root=new node;
		root->num=n;
		root->right=NULL;
		root->left=NULL;
		return root;
	}

	return root;

}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"  "<<root->num;
		inorder(root->right);
	}
}
void preorder(node* root)
{
	if(root!=NULL)
	{
		cout<<"  "<<root->num;
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
		cout<<"  "<<root->num;
	}
}
int countall(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		count++;
	}
	return count;
}
int countleaf(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		if(root->right==NULL && root->left==NULL)		
			count++;
	}
	return count;
}
int countbranch(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		if(root->right==NULL || root->left==NULL)		
			count++;
		
	}
	return count;
}
node* minn(node* root)
{
	if(root->left!=NULL)
		minn(root->left);
	else 
		return root;
}
node* maxx(node* root)
{
	if(root->right!=NULL)
		maxx(root->right);
	else 
		return root;
}
node* del(node* root,int n)
{
	node* temp;
	if(root==NULL)
	{
		cout<<"NUM NOT FOUND\n";
	}
	else if(n<root->num)
		root->left=del(root->left,n);
	else if(n>root->num)
		root->right=del(root->right,n);
	else
	{
		if(root->right==NULL)
		{
			temp=root->left;
			delete root;
			root=temp;
		}
		else if(root->left==NULL)
		{
			temp=root->right;
			delete root;
			root=temp;
		}
		else
		{
			temp=maxx(root->left);
			root->num=temp->num;
			root->left=del(root->left,temp->num);
		}
	}
		



}

int main()
{
	int ch;
	node* root=NULL;
	do
	{
		ch=menu();
		if(ch==1)
		{
			int n;
			cout<<"\nEnter the number you want to add";
			cin>>n;
			root=add(root,n);
		}
		else if(ch==2)
		{
			inorder(root);
			cout<<endl;
		}
		else if(ch==3)
		{
			preorder(root);
			cout<<endl;
		}

		else if(ch==4)
		{
			postorder(root);
			cout<<endl;
		}
		else if(ch==5)
		{	
			count=0;
			count=countall(root);
			cout<<"\nCount is:"<<count;
		}
		else if(ch==6)
		{	
			count=0;
			count=countleaf(root);
			cout<<"\nCount is:"<<count;
		}
		else if(ch==7)
		{	
			count=0;
			count=countbranch(root);
			cout<<"\nCount is:"<<count;
		}
		else if(ch==8)
		{
			node* temp=minn(root);
			cout<<"\nMIN="<<temp->num<<endl;
		}
		else if(ch==9)
		{
			node* temp=maxx(root);
			cout<<"\nMAX="<<temp->num<<endl;
		}
		else if(ch==10)
		{
			cout<<"Enter the num you want to delete";
			cin>>num;
			root=del(root,num);
	
		}
		

	}while(ch!=11);
	




	return 0;
}
