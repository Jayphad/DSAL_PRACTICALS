/*--Jay Phad
Amruvahini College Of Engineering
problem stmt : 
Implement all the functions of the dictionary using hashing and handle collisions using chaining without replacement.
data : set of (key,value) pairs, keys are mapped to values, keys must be comparable, keys must be unique.
standard operations: insert , find , delete;
*/

#include<iostream>
#include<string.h>
#define max 10
using namespace std;

//structure for dictionary
struct Dictionary{
	char word[20];
	char mean[20];
	int change;
	
};

//class for dictionary operation (hash table)
class DictOp{
	struct Dictionary hash[max];
	struct Dictionary temp;
	
	public:
	//initialize the hash data
	void init(){
		for(int i=0;i<max;i++){
			strcpy(hash[i].word,"");
			strcpy(hash[i].mean,"");
			hash[i].change = -1;
		}
	}
	
	//get word and its meaning from user	
	void getData(){
		cout<<"Enter Word: ";
		cin>>temp.word;
		cout<<"Enter Meaning: ";
		cin>>temp.mean;
		
		if(!checkDuplicate()){
			insert();	// if word not present in dictionary then insert otherwise show 'duplicate word ' msg to user
		}
		else{
			cout<<"\nDuplicate word...\n";
		}
	}
	
	//function to check duplicate word in dictionary
	bool checkDuplicate(){
		int sum=0;
		for(int i=0;i<strlen(temp.word);i++){
			sum = sum + int(temp.word[i]);
		}
		
		int index = sum % max;
		
		while(1){
			
			if(strcmp(hash[index].word,temp.word)==0){
				return true;
			}
			else if(hash[index].change != -1){
				index = hash[index].change;
			}
			else{
				return false;
			}
		}
	}
	
	// insert word and meaning in dictionary
	void insert(){
		int sum=0;
		int i;
		
		for(i=0;i<strlen(temp.word);i++){
			sum = sum + int(temp.word[i]);
		}
		
		int index = sum % max;
		int tmp;
		
		tmp = index;
		i = index;
		
		do{
			if(!strcmp(hash[i].word,"")){
				strcpy(hash[i].word,temp.word);
				strcpy(hash[i].mean,temp.mean);
				cout<<"\nWord Added to Dictionary\n\n";
				break;
			}
			else if(hash[tmp].change != -1){
				tmp = hash[tmp].change;
				i = tmp;
			}
			else{
				i = (i+1) % max;
			}
		}while(i!=index-1);
		
		if(i!=tmp){
			hash[tmp].change = i;
		}
	}
	
	//search word in dictionary
	void search(){
		cout<<"\nEnter Word to Search : ";
		cin>>temp.word;
		
		int sum=0;
		for(int i=0;i<strlen(temp.word);i++){
			sum = sum + int(temp.word[i]);
		}
		
		int index = sum % max;
		int comparisons = 0;
		while(1){
			comparisons++;
			if(strcmp(hash[index].word,temp.word)==0){
				cout<<"\n "<<hash[index].word<<" : "<<hash[index].mean<<endl;
				cout<<"Comparisons required : "<<comparisons<<endl;
				return;
			}
			else if(hash[index].change != -1){
				index = hash[index].change;
			}
			else{
				cout<<"\nWord Not found In Dictionary...\n";
				cout<<"Comparisons required : "<<comparisons<<endl;
				return;
			}
		}
	}
	
	//delete word and its meaning
	void remove(){
		cout<<"\nEnter Word to Delete : ";
		cin>>temp.word;
		
		int sum=0;
		for(int i=0;i<strlen(temp.word);i++){
			sum = sum + int(temp.word[i]);
		}
		
		int index = sum % max;
		int prevIndex = index;
		int lastIndex = index;
		while(1){
			if(strcmp(hash[index].word,temp.word)==0){
				while(hash[index].change != -1){
					strcpy(hash[index].word,hash[hash[index].change].word);
					strcpy(hash[index].mean,hash[hash[index].change].mean);
					lastIndex = index;
					index = hash[index].change;	
				}
				strcpy(hash[index].word,"");
				strcpy(hash[index].mean,"");
				hash[prevIndex].change = -1;
				hash[lastIndex].change = -1;
				cout<<"\nWord Deleted...\n";
				return;
			}
			else if(hash[index].change != -1){
				prevIndex = index;
				index = hash[index].change;
			}
			else{
				cout<<"\nWord Not found In Dictionary...\n";
				return;
			}
		}
	}
	
	// display the dictionary (hash table)
	void display(){
		cout<<endl;
		cout<<"Index : Word : Meaning : Change"<<endl;
		for(int i = 0;i < max; i++){
			cout<<i<<" : "<<hash[i].word<<" : "<<hash[i].mean<<" : "<<hash[i].change<<endl;
		}
	}
};

int main(){
	
	DictOp ob;
	ob.init(); // initialize dictionary
	
	int n,ch;
	int i;
	
	while(true){
		cout<<"\n 1. Add Word In Dictionary";
		cout<<"\n 2. Search Word In Dictionary";
		cout<<"\n 3. Display Dictionary";
		cout<<"\n 4. Delete Word";
		cout<<"\n 5. Exit";
		cout<<"\n>>> ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"How Many Word do you want to add? < 10 : ";
				cin>>n;
				for(i=0;i<n;i++){
					ob.getData();
				}
				break;
				
			case 2: ob.search(); break;
			case 3: ob.display(); break;
			case 4: ob.remove(); break;
			case 5: return 0;
			default:
				cout<<"\n Invalid choice ...";
			
		}
	}
	return 0;
}

