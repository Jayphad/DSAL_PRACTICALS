/*Jay Phad
Amruvahini College Of Engineering
Represent a given graph using adjacency list to perform BFS. Use 
non-recursive method */
#include<iostream>
#include<vector>
#define max 10
using namespace std;

struct node 
{
	int data;
    struct node* next;
}*head[10];
int n;
vector<int>visited(max,0);
void create_graph()
{
	struct node* nn=NULL;
	struct node* last=NULL;
	cout<<"Enter the number of nodes:";
	cin>>n;

	//initialize array of pointer to null
	for(int i=0;i<n;i++)
	{
		head[i]=NULL;
	}
	int val;
	for(int i=0;i<n;i++)
	{
		nn=new node;
		cout<<"Enter the value to put at vertex "<<i<<":";
		cin>>val;
		nn->data=val;
		nn->next=NULL;
		head[i]=nn;
		last=head[i];
		
		int adj;
		cout<<"Enter the number of adjacent nodes of "<<i<<":";
		cin>>adj;
		for(int j=0;j<adj;j++)
		{
			nn=new node;
			cout<<"Enter the Value :";
			cin>>val;
			nn->data=val;
			nn->next=NULL;
			last->next=nn;
			last=nn;
		}
		
	}
}
void display()
{
	struct node* temp=NULL;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		temp=head[i];
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;			
		}
		cout<<endl;
	
	}
}
void BFS(int v)
{
	struct node* temp=NULL;
	int queue[max],rear,front;
	front=rear=0;
	queue[rear]=v;
	rear++;
	cout<<v<<"->";
	visited[v]=1;
	while(front!=rear)
	{
		v=queue[front];
		front++;
		temp=head[v];
		if(temp->next!=NULL)
		{
			while(temp!=NULL)
			{
				if(visited[temp->data]!=1)
				{
				    cout<<temp->data<<"->";
				    visited[temp->data]=1;
				
			       	queue[rear]=temp->data;
				    rear++;
				}
				temp=temp->next;
			}
		}
	}
	

	
}

int main()
{
	int v;
	create_graph();
	display();
	cout<<"Enter the vertex from where you want to start:";
	cin>>v;
	BFS(v);
	return 0;
}
