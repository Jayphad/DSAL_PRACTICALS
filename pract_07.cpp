/*
Beginning with an empty binary search tree, Construct binary 
search tree by inserting the values in the order given. After 
constructing a binary tree - 
i.   Insert new node  
ii.  Search a specific value in a tree   
iii. Change a tree so that the roles of the left and right pointers are 
swapped at every node (Mirror image) */
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* left,*right;
};
struct node* create_node(int data)
{
	struct node* newnode=NULL;
	newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
void create_bst(struct node** root)
{
	int val;
	struct  node* temp=NULL;
	struct node* newnode=NULL;

	cout<<"Enter the value to be inserted:";
	cin>>val;
	newnode=create_node(val);
    if(*root==NULL)
    {
		*root=newnode;
		return;
	}
	temp=*root;
	while(1)
	{
		if(temp->data>newnode->data)
		{
			if(temp->left==NULL)
			{
				temp->left=newnode;
				return;
			}
			temp=temp->left;
		}
		else{
			if(temp->right==NULL)
			{
				temp->right=newnode;
				return;
			}
			temp=temp->right;
		}
	}
}
void inorder(struct node* root)
{
		
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
}
void search(struct node* temp,int s)
{
	while(temp!=NULL)
	{
		if(temp->data>s)
			temp=temp->left;
		else if(temp->data<s)
			temp=temp->right;
		else
			break;	
	}
	if(temp==NULL)
	{
		cout<<"\nElement Not Found";
	}
	else{cout<<"Element Found:";
	}
	
}
void mirror(struct node* root)
{
	struct node* temp=NULL;
	if(root==NULL)
	{
		return;
	}
	mirror(root->left);
	mirror(root->right);
	
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	
}
int main()
{
	int s;
	struct node* root=NULL;
	int ch;
	do{
			cout<<"\n1.Insert a value to bst:";
			cout<<"\n2.Display using Inorder";
			cout<<"\n3.Search";
			cout<<"\n4.Mirror ";
			cout<<"\nEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1: 
						create_bst(&root);
						break;
				case 2: 
						inorder(root);
						break;
				case 3: cout<<"Enter the Value You want to search:";
						cin>>s;
				 search(root,s);
				 	break;
				case 4: mirror(root);
				break;
			}
	}while(ch!=0);
	return 0;
}

