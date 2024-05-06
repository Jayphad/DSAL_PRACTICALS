/*Jay Phad
Amruvahini College Of Engineering
Consider telephone book database of N clients. Make use of a hash 
table implementation to quickly look up client‘s telephone number. 
Make use of Linear & quadratic probing(without replacement) and 
compare them using number of comparisons required to find a set 
of telephone numbers*/

#include<iostream>
#include<string.h>
#define max 10
using namespace std;

struct record
{
	char name[10];
	long int tell;
}*hash[max];

void init()
{
	for(int i=0;i<max;i++)
	{
		hash[i]=new record;
		hash[i]->tell=0;
		strcpy(hash[i]->name,"");
	}
}
void insert()
{
	
	int n;
	cout<<"How many Record you want to insert:";
	cin>>n;
	char name[10];
	long int tell;
	for(int i=0;i<n;i++)
	{	
		
		cout<<"\nEnter the name:";
		cin>>name;
		cout<<"Enter the tell:";
		cin>>tell;
		
		//insert record in hash tablle;
		int sum=0;
		for(int j=0;j<strlen(name);j++)
		{
			sum=sum+int(name[j]);
		}
		int key=sum%max;
		int p=0;    
		for(int j=key;j!=(key-1);j=(j+1)%max)
		{
			p++;
			//for quadratic : if(hash[(key+j*j)%max]->tell==0)
			
			if(hash[j]->tell==0)
			{
				hash[j]->tell=tell;
				 strcpy(hash[j]->name,name);
				 cout<<"\nPasses Require to Insert:"<<p<<endl;
				 break;
			}
		}
		
	}
}
void search()
{
	
	char name[10];
	cout<<"Enter the name you want to search:";
	cin>>name;
		int sum=0;
		for(int j=0;j<strlen(name);j++)
		{
			sum=sum+int(name[j]);
		}
		int key=sum%max;
		int p=0;
	for(int j=key;j!=key-1;j=(j+1)%max)
	{
		p++;
		if(!strcmp(hash[j]->name,name))//strcmp returns 0 so we need to make it one so !
		{
			cout<<"\nRecord Found\n";
			cout<<hash[j]->name<<endl;
			cout<<hash[j]->tell<<endl;
			cout<<"Number of passes require: "<<p;
			
			break;
		}
	}
	
}

void display(){
		cout<<"\n Hash Data: "<<endl;
        for(int i=0;i<max;i++){
            cout<<i<<": "<<hash[i]->name<<" -> "<<hash[i]->tell<<endl;
        }
    }  

int main()
{
	int ch;
	init();
	do{
		cout<<"\n1.Insert record";
		cout<<"\n2.Search";
		cout<<"\n3.Display";
		cout<<"\nEnter your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: insert();break;
			case 2: search();break;
			case 3: display();break;
		}
	}while(ch!=0);
	return 0;
    
}
