/*Jay Phad
Amruvahini College Of Engineering
A book consists of chapters, chapters consist of sections and sections 
consist of subsections. Construct a tree and print the nodes. Find the 
time and space requirements of your method. */
#include<iostream>
#include<string>
#define max 10
using namespace std;

struct node
{
	string name;
	int count;
	struct node* child[max];
}*head=NULL;

struct node* create_book()
{
	struct node* temp=NULL;
	struct node* temp1=NULL;
	struct node* temp2=NULL;
	struct node* nn=NULL;
	nn=new node;
	
	cout<<"Enter the BOOK name:";
	cin>>nn->name;
	cout<<"Enter the number of Chapter:";
	cin>>nn->count;
	temp = nn;
	
	for(int i=0;i<temp->count;i++)
	{
		temp->child[i] = new node;
		temp1 = temp->child[i];
		
		cout<<"Enter the Chapter Name: ";
		cin>>temp1->name; //head->child[i]->name
		cout<<"Enter the number of Section:";
		cin>>temp1->count;
		
		for(int j=0;j<temp1->count;j++)
		{
			temp1->child[j] = new node;
			temp2 = temp1->child[j];
			
			cout<<"Enter the Section Name: ";
			cin>>temp2->name;
			cout<<"Enter the number of sub-Section:";
			cin>>temp2->count;
			
			for(int k=0;k<temp2->count;k++)
			{
				temp2->child[k] = new node;
				
				cout<<"Enter the subSection Name: ";
				cin>>temp2->child[k]->name;
			}
		}
		
		
	}
	return(nn);
}
display(struct node* head)
{
	cout<<head->name<<endl;
	for(int i=0;i<head->count;i++)
	{
		cout<<"  "<<head->child[i]->name<<endl;	
		for(int j=0;j<head->child[i]->count;j++)
		{
			cout<<"   "<<head->child[i]->child[j]->name<<endl;
			for(int k=0;k<head->child[i]->child[j]->count;k++)
			{
				cout<<"    "<<head->child[i]->child[j]->child[k]->name<<endl;
			}
		}
	}	
}
int main()
{
	head=create_book();
	display(head);
	return 0;
}
