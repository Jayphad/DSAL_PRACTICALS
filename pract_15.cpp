/*Jay Phad
Amruvahini College Of Engineering
Department maintains a student information. The file contains roll 
number, name, division and address. Allow user to add, delete 
information of student. Display information of particular student. If 
record of student does not exist an appropriate message is 
displayed. If it is, then the system displays the student details. Use 
sequential file to main the data.*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student
{
   public:
   int roll;
   char div;
   char name[20];
   char add[20];
   public:
   void Add_Student_Info()
   {
	char ch;
        ofstream fout("jay.txt");
        if(fout.is_open())
        {
	    cout<<"File is Open in Write Mode Successfully\n";
        }
	else
        {
	     cout<<"Error in opening File\n"<<endl;
		return ;
        }
      while(ch!='n')
      {
	cout<<"Enter roll:\n";
   	cin>>roll;
   	cout<<"Enter div:\n";
   	cin>>div;
   	cout<<"Enter name:\n";
   	cin>>name;	
	cout<<"Enter address:\n";
	cin>>add;
   	fout<<roll<<endl;
   	fout<<div<<endl;
   	fout<<name<<endl;
	fout<<add<<endl;
   	
	cout<<"File Closed\n";
	cout<<"Enter y/n to add more student Info:\n";
	cin>>ch;
       }
       fout.close();
    }
    void Display_Student_Info()
    {
	ifstream  fin("jay.txt");
        if(fin.is_open())
        {
	   cout<<"File Opened in Read Mode Successfully\n";
        }
	else
        {
	     cout<<"Error in opening File\n"<<endl;
		return ;
        }

	cout<<"Roll \t Div \t Name \t Adderss \n";
	do{
	      fin>>roll>>div>>name>>add;
	     if(!fin.eof())
	      cout<<roll<<"\t"<<div<<"\t"<<name<<"\t"<<add;
              cout<<endl;
	     

	}while(!fin.eof());
	fin.close();
	cout<<"File Closed\n";
    }
    void Search_For_Record(int roll_search)
    {
	int flag=0;
	ifstream  fin("jay.txt");
        if(fin.is_open())
        {
	   cout<<"File Opened in Read Mode Successfully\n";
        }
	else
        {
	     cout<<"Error in opening File\n"<<endl;
		return ;
        }
	do{
	   fin>>roll>>div>>name>>add;
	   if(roll_search==roll)
	   {
		cout<<"Roll \t Div \t Name \t Adderss \n";
		cout<<roll<<"\t"<<div<<"\t"<<name<<"\t"<<add;
		flag=1;
		cout<<endl;
		break;
	   }


	}while(!fin.eof());
	if(flag==1)
	{
		cout<<"Record Found.\n";
	}
	else{
                cout<<"Record Not Found\n";
	
	}
	fin.close();
	cout<<"File Closed\n";


    }
	void Delete_Record(int del_roll)
	{
		//old file
		ifstream  fin("jay.txt");
		if(fin.is_open())
		{
		   cout<<"File Opened in Read Mode Successfully\n";
		}
		else
		{
		     cout<<"Error in opening File\n"<<endl;
			return ;
		}
		//new file
		ofstream fout("jay1.txt");
		if(fout.is_open())
		{
		    cout<<"File is Open in Write Mode Successfully\n";
		}
		else
		{
		     cout<<"Error in opening File\n"<<endl;
			return ;
		}
		//search for Record
		do{
		   fin>>roll>>div>>name>>add;
		   if(del_roll==roll)
		   {
			continue;
		   }
		   else
		   {
			if(!fin.eof())
			{
			fout<<roll<<endl;
		   	fout<<div<<endl;
		   	fout<<name<<endl;
			fout<<add<<endl;
			}
		   }
		}while(!fin.eof());
		cout<<"Record DELETED\n";

	
	fin.close();
	cout<<"File Closed\n";
	remove("jay.txt");
	rename("jay1.txt","jay.txt");

	cout<<"UPDATED FILE IS\n";
	Display_Student_Info();
	}
};


int  main()
{
	student s;
	int roll;
	int del_roll;
	int ch;
	do{
	cout<<"*******FILE_OPERATION*********";
	cout<<"\n1.Add_Student_Info\n";
	cout<<"2.Display_Student_Info\n";
	cout<<"3.Search_For_Record\n";
	cout<<"4.Delete Record\n";
	cout<<"0.Exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1: s.Add_Student_Info();
			break;

		case 2: s.Display_Student_Info();
			break;
		case 3:cout<<"Enter the roll of Record you want to Search for:";
			cin>>roll;

			s.Search_For_Record(roll);
			break;

		case 4: cout<<"Enter the roll no of record you want to delete for:";
			cin>>del_roll;
			s.Delete_Record(del_roll);
 		        break;
		default:
			cout<<"Enter Valid Choce:";
	}


        }while(ch!=0);
return 0;

}
