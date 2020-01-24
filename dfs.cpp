#include <iostream>

using namespace std;


int n;
int adj[10][10]={0}, visited[10];

void dfs(int node)
{
	cout<<node+1<<" ";
	visited[node]=1;
	for(int i=0;i<n;i++)
	{
		if(adj[node][i]==1 && visited[i]==0)
		{
			dfs(i);
		}

	}


}

int main()
{
	int e;
	cout<<"\nEnter  number of nodes:";
	cin>>n;
	cout<<"\nEnter  number of edges:";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int v1,v2;
		cout<<"\nEnter vertex one:";
		cin>>v1;
		cout<<"\nEnter vertex two:";
		cin>>v2;
		adj[v1-1][v2-1]=1;
		adj[v2-1][v1-1]=1;

	}
	int node;
	cout<<"\nEnter the starting node:";
	cin>>node;
	cout<<"\nDFS\n";
	dfs(node-1);

}
