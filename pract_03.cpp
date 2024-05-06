/*Jay Phad
Amruvahini College Of Engineering
There are flight paths between cities. If there is a flight between city 
A and city B then there is an edge between the cities. The cost of the 
edge can be the time that flight takes to reach city B from A or the 
amount of fuel used for the journey. Represent this as a graph. The 
node can be represented by airport name or name of the city. Use 
adjacency list representation of the graph or use adjacency matrix 
representation of the graph. Check whether the graph is connected 
or not. Justify the storage representation used.
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#define max 10
using namespace std;

vector<int>visited(max,0);
stack<int>s;
int g[max][max];
string cities[max];
int n;
void DFS(int v)
{
	cout<<cities[v]<<"->";
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if(g[v][i]!=0 && visited[i]==0)
		{
			DFS(i);
		}
		
	}
}
void DFS1(int v)
{
	s.push(v);
	while(!s.empty())
	{
		v=s.top();
		s.pop();
		if(visited[v]==0)
		{
			cout<<cities[v]<<"->";
			visited[v]=1;
			
			for(int i=0;i<n;i++)
			{
				if(g[v][i]!=0 && visited[i]==0)
				{
					s.push(i);
				}
			}
		}	
	}
	
}

int main()
{
	int val;
	int flag=0;
	
	cout<<"Enter the number of cities:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the city name: ";
		cin>>cities[i];
	}
	cout<<"Enter the hours require for city one to another or else put 0 if no Flight:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j && i<j)
			{
				cout<<cities[i]<<"->"<<cities[j]<<": ";
				cin>>val;
				g[i][j]=val;
				g[j][i]=g[i][j];
			}
		}
	}
	cout<<"There are Paths betweeen Following Cities\n";
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			DFS(i);
			cout<<endl;
		}
		
	}
//	for(int i=0;i<n;i++)
//	{
//		if(visited[i]==0)
//		{
//			flag=1;
//			break;
//		}
//	}
//	if(flag==0)
//	{
//		cout<<"\nThis is connected graph.";
//	}
//	else{
//		cout<<"\nThis is  disconnected Graph:";
//	}
	//DFS1(0);
	return 0;
}
