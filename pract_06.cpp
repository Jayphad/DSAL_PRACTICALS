/*Jay Phad
Amruvahini College Of Engineering
Beginning with an empty binary search tree, Construct binary 
search tree by inserting the values in the order given. After 
constructing a binary tree - 
  i. Insert new node 
 ii. Find number of nodes in longest path from root  
iii. Minimum data value found in the tree */
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct  node* right;
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
int height(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=height(root->left);
	int rh = height(root->right);
	if(rh>lh)
	{
		rh=rh+1;
		return rh;	
	}
	else{
		lh=lh+1;
		return lh;
	}
}
int min(struct node* root)
{
	if(root==NULL)
	{
		return -1;
	}
	return min(root->left);	
}
int main()
{
	int ch;
	struct node* root=NULL;
	do{
			cout<<"\n1.Insert a value to bst:";
			cout<<"\n2.Display using Inorder";
			cout<<"\n3.Height";
			cout<<"\n4.Find Minimum";
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
				case 3: 
					cout<<"\nheight of Tree is:"<<height(root);
						break;
				case 4: 
					
					if(min(root)==-1)
						cout<<"tree is empty";
					else
						cout<<"Minumum node is :"<<min(root);		
			}
	}while(ch!=0);



}
