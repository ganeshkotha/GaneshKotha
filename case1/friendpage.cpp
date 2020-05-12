/*Program	: Friendpage Program :Program is about to Add new users, Edit users ,Search users, Delete user and add friends
  Filename	: friendpage
  Name      : Kotha Ganesh
  Date		: 11-05-2020
*/
#include<iostream>
#include<stdlib.h>
#include<map>
#include<string.h>
using namespace std;
class Friendpage
{ 
private:
	string NAME;
	string MAILID;
	map<string,string> usersdata;
	map<string,string> frienddata; 
	map<string,string>::iterator itr;
	/*	Function Name :adduser
 	 	Parameters    :no parameters
  		Usage         :To add users into Data*/
	void adduser()
	{
		
		string *NAME = new string();
		string *MAILID = new string();
		cout<<"Welcome to the FRIEND page"<<endl;
		cout<<"Enter name (please give your name with out space) "<<endl;
		cin>>*NAME;
		cout<<"Enter mail id"<<endl;
		cin>>*MAILID;
		usersdata.insert({*NAME,*MAILID});
		cout<<"Your account is created successfully"<<endl;
		delete NAME;
		delete MAILID;
	}
	/*	Function Name :displayusers
 	 	Parameters    :no parameters
  		Usage         :To Display users from the Data*/		
	void displayusers()
	{
		cout<<"In this Friend Page Users list "<<endl;
		for (itr =  usersdata.begin(); itr !=  usersdata.end(); itr++)
	 	{ 
    		cout<<"Name   : "<< itr->first<<endl; 
    		cout<<"Mail id: " << itr->second << endl; 
     	}
	}
	/*	Function Name :edituser
 	 	Parameters    :no parameters
  		Usage         :To edit users in Data*/		
	void edituser()
	{
		string *newname = new string();
		string *newmailid = new string();
		string *search = new string();
		cout<<"Enter name to edit details "<<endl;
		cin>>*search;
		itr = usersdata.find(*search);
		if(itr == usersdata.end()) 
			cout << "Entered name is not present please check and try again "<<endl; 
		else
			cout << "Entered name is present : "<<endl;
			cout<<"Enter new name"<<endl;
			cin>>*newname;
			cout<<"Enter new mail id "<<endl;
			cin>>*newmailid;
			usersdata.erase(*search);
			usersdata.insert (pair< string, string >(*newname,*newmailid));
			cout<<"Your Data Updated succesfully"<<endl;
			delete newname;
			delete newmailid;
			delete search;
			
	}
	/*	Function Name :removeuser
 	 	Parameters    :no parameters
  		Usage         :To remove users in Data*/	
   void removeuser()
	{
	    string *search = new string();
		bool b=false;
		cout<<"Enter name to Remove account: "<<endl;
		cin>>*search;
		for (itr =  usersdata.begin(); itr !=  usersdata.end(); itr++)
	 	{ 
			if(itr->first==*search || itr->second==*search )
			{
		 		b=true;
		 		usersdata.erase(*search);
     		    cout<<"Deleted successfuly"<<endl;
		 		break;
			}
		}
     	if (b==false)
     	{
     		cout<<"Entered name is not present in users data"<<endl;
     	}
	}
	/*	Function Name :searchuser
 	 	Parameters    :no parameters
  		Usage         :To search users in Data*/		
	void searchuser()
	{
		string *search = new string();
		bool b=false;
		cout<<"Enter name to Search account: "<<endl;
		cin>>*search;
		for (itr =  usersdata.begin(); itr !=  usersdata.end(); itr++)
	 	{ 
			if(itr->first==*search || itr->second==*search )
			{
		 		b=true;
		 		break;
			}
		}
     	if (b==false)
     	{
     		cout<<"Entered details has no account"<<endl;
     	}
     	else
     		cout<<"Entered details has account"<<endl;
			delete search;
	}
	/*	Function Name :addnewfriend
 	 	Parameters    :no parameters
  		Usage         :To add friend for the user*/	
	void addnewfriend()
	{
		string *newname = new string();
		string *newmailid = new string();
		string *search = new string();	
		char Addrecords;
		cout<<"Enter your detils to add friends "<<endl;
		cout<<"Enter name:"<<endl;
		cin>>*newname;
		cout<<"Enter mail id:"<<endl;
		cin>>*newmailid;
		do 
		{
		    bool t=false;
		    cout<<"These are the available user accounts"<<endl;
			for (itr =  usersdata.begin(); itr !=  usersdata.end(); itr++)
	 		{ 
    			cout<<"Name: "<< itr->first<<endl; 
    			cout<< "Mail id: " << itr->second << endl; 
     		}
     		cout<<" Select the name whom you want to be friend \n "<<endl;
			cin>>*search;
			for (itr =  usersdata.begin(); itr !=  usersdata.end(); ++itr)
	 		{ 
				if(itr->first==*search || itr->second==*search )
				{
		 			t=true;
		 			frienddata.insert({itr->first,itr->second});
		 			cout<<"Friend added succesfully \n "<<endl;
		 			break;
				}
			}
     		if (t==false)
     		{
     			cout<<"Entered name is not present"<<endl;
     		}
	 		cout<<"Do you want to add more friends? (y/n)"<<endl;
     		cin>>Addrecords;   
     	}while(Addrecords=='y');
     	cout<<"Friends List"<<endl;
     	for (itr =  frienddata.begin(); itr !=  frienddata.end(); ++itr)
	 	{ 
    		cout<<"Name: "<< itr->first<<endl; 
    		cout<< "Mail id: " << itr->second << endl; 
     	}
		delete newname;
		delete newmailid;
		delete search;
 	}
public:
	/*	Function Name :options
 	 	Parameters    :no parameters
  		Usage         :user need to choose options to select*/	
 	void options()
 	{
	  	while(1)
        	{ 
            	cout<<"-------------------------------------------------"<<endl;
        		cout<<" 1.Add User \n 2.Display users \n 3.Edit User \n 4.Delete user \n 5.Search user \n 6.Add friends \n 7.exit"<<endl;
            	cout<<"Choose Option: "<<endl;
            	int choice;
            	cin>>choice;
            	cout<<"--------------------------------------------------"<<endl;
		    	switch(choice)
            	{
                         case 1:
                                adduser();
                                break;
                         case 2:
                                displayusers();
                                break;
                         case 3:
                         		edituser();
                         		break;
                         case 4:
                         		removeuser();
                         		break;
                         case 5:
                         		searchuser();
                         		break;
                         case 6:
                         		addnewfriend();
                         		break;
                         case 7:
                                exit(1);
                         default:
                                cout<<" Sorry! Invalid option!!! "<<endl;
                                break;
                                
                }
			}
		}
};
int main(int argc,char* argv[])
{
	if(argc>=2)
    {
		if(strcmp(argv[1],"-h")==0)		//strcmp is for comparing input string of command line -h
	    {
            cout<<"Friendpage Program :Program is about to Add new users, Edit users ,Search users, Delete users and add friends. User must choose the options "<<endl;
	    }
    }
	else
	{
		cout<<" Welcome to Friendpage \n For help please press '-h' in Command line argument"<<endl;
		cout<<" Press 7 to exit and go for help"<<endl;
        Friendpage p;
        p.options();
        return 0;
    }
}
