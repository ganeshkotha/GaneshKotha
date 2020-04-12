/* 	Program Name: Program about Storage classes
	Name        : KOTHA GANESH
    File Name   : case3_3.cpp
    Date        : 09-04-2020 */
#include<iostream>
#include<string.h>
using namespace std;
int v;
static int t=77; /*gobal variable*/
class mutable_storage
{
	public:
		//mutable variable  
		mutable int kMutable;	
		//default constructor
 		mutable_storage()
		{
			kMutable=96;
		}
};
// Function containing static variables 
// memory is retained during execution 
int staticFun() 
{ 
    cout << "For static variables: "; 
    static int count = 0; 
    count++; 
    return count; 
} 
// Function containing non-static variables 
// memory is destroyed 
int nonStaticFun() 
{ 
    cout << "For Non-Static variables: ";  
    int count = 0; 
    count++; 
    return count; 
} 
void autoStorageClass() 
{ 
   cout << "Demonstrating auto class"<<endl;   
    // No data-type declaration needed 
    auto int ip = 5497; 
    auto float iq = 9.54; 
    auto string im = "Programming"; 
    auto char iw = 'k'; 
    // printing the auto variables 
    cout <<"Integer value: "<<ip<<endl; 
    cout <<"Float value: "<<iq<<endl; 
    cout <<"string: "<<im<<endl; 
    cout <<"character: "<<iw<<endl; 
}
void externStorageClass() 
{ 
	cout<<"------------------------------------------"<<endl;
    cout << "Demonstrating extern class"<<endl; 
    extern int v; 
    // printing the extern variables 'v' 
    cout << "Value of the variable 'v' declared, as extern: " <<v<<endl; 
    // value of extern variable v modified 
    cout<<"Enter modified extern variable: ";
    cin>>v; 
    // printing the modified values of 
    // extern variables 'v' 
    cout << "Modified value of the variable 'v' declared as extern:"<<v<<endl;
}
void registerstorage()
{
	cout<<"------------------------------------------"<<endl;	
	cout << "Demonstrating register class"<<endl;
	//Declaring Register storage class variable 
 	register int kg;
 	cout<<"Default value register storage class:"<<kg<<endl;
 	cout<<"Enter registar value:";
 	cin>>kg;
 	cout<<"The value of register variable:"<<kg<<endl;
}
void staticstorage()
{
	cout<<"------------------------------------------"<<endl;
	cout << "Demonstrating static storage class"<<endl;
	static int abc;
	cout<<"default value static storage class:"<<abc<<endl;
 	static int pq=89; /*local static varaible*/	
 	pq++;
 	cout<<"enter the static value:";
 	cout<<"The value local static variable:"<<pq<<endl;
 	cout<<"The value global static variable:"<<t<<endl;
}
int main(int argc,char *argv[])
{
	//Declaration of object for class storage  
	const mutable_storage j;  
	//Accessing mutable storage class value 
	j.kMutable=65; 
	if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
	{
		
		cout<<"This program is about the storage classes"<<endl;
	}
	else
	{
		cout<<"Static storage class"<<endl;
	  // Calling the static parts 
    cout<<staticFun()<<endl; 
    cout<< staticFun()<<endl;
    cout<<"Static variables have a property of preserving their value even after they are out of their scope"<<endl;
    // Calling the non-static parts 
    cout<<nonStaticFun()<<endl; 
    cout<<nonStaticFun()<<endl;
    cout<<"--------------------------------------"<<endl;
	autoStorageClass();	     						//calling auto storage function
	externStorageClass();	 						//calling extern storage function
	registerstorage();       						//calling register storage function
	staticstorage();         						//calling static storage function
	cout<<"----------------------------------------"<<endl;
	cout<<"Mutable Storgae"<<endl;
	cout<<"The Mutable Value:"<<j.kMutable<<endl;	//dispalying mutable value.
	}
	return 0;
}
