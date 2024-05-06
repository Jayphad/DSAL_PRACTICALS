/*Jay Phad
Amruvahini College Of Engineering
Read the marks obtained by students of second year in an online 
examination of particular subject. Find out maximum and minimum 
marks obtained in that subject. Use heap data structure. Analyze the 
algorithm.*/
#include<iostream>
using namespace std;
class heap{
	float marks[20];
	int size;
	
	public:
	
	void getdata(){
		cout<<"Enter the number of the students : ";
		cin>>size;
		for(int i=0;i<size;i++){
			cout<<"Enter the marks of student "<<i+1<<" : ";
			cin>>marks[i];
		}
		
		//perform heapify
		for(int i = (size-1)/2;i>=0;i--){
			heapify(i);
		}
	}
	
	void heapify(int i){
		int largest = i;
		int left = 2*i+1;
		int right = 2*i+2;
		
		if(marks[left] > marks[largest] && left < size){
			largest = left;
		}
		if(marks[right] > marks[largest] && right < size){
			largest = right;
		}
		
		if(largest != i){
			float temp;
			temp = marks[i];
			marks[i] = marks[largest];
			marks[largest] = temp;
			heapify(largest);
		}
	}
	
	float getMaxMarks(){
		return marks[0];
	}
	
};

//driver code

int main(){
	heap ob;
	ob.getdata();
	cout<<"Max marks = "<<ob.getMaxMarks()<<endl;
return 0;
}
