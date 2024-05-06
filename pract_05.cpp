/*Jay Phad
Amruvahini College Of Engineering
Construct an expression tree from the given prefix expression eg. +- -a*bc/def and traverse it using post order traversal (non-recursive) 
and then delete the entire tree.
*/
#include<iostream>
#include<stack>
using namespace std;

struct node
{
	char data;
	node* left , *right;
};

struct node* create_node(char ch){
	struct node* nn = new node;
	nn->data = ch;
	nn->left = nn->right = NULL;
	return nn;
}

struct node* create_tree(char* exp,int n){
	stack<node*>stk;
	struct node* newnode = NULL;
	for(int i=n-1;i>=0;i--){
		newnode = create_node(exp[i]);
		
		if(exp[i]>='a' && exp[i]<='z'){
			stk.push(newnode);
		}
		
		else{
			if(!stk.empty()){
				newnode->left = stk.top();
				stk.pop();
				newnode->right = stk.top();
				stk.pop();
				stk.push(newnode);
			}
		}
	}
	return newnode;
}

void postorder(struct node* r){
	if(r==NULL)
		return;
	postorder(r->left);
	postorder(r->right);
	cout<<r->data;
}
void preorder(struct node* r){
	if(r==NULL)
		return;
		
	cout<<r->data;
	preorder(r->left);
	preorder(r->right);
}
int main()
{
	struct node* root=NULL;
	char a[]="+--a*bc/def";
	int length = (sizeof(a)/sizeof(char))-1;
	root = create_tree(a,length);
	
	postorder(root);
	cout<<endl;
	preorder(root);
	return 0;
}
