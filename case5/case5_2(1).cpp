/*Program    : Program defines the order of execution of constructor and destructor using virtual
  Name       : Kotha Ganesh
  File Name  : case5_2(1).cpp
  Date       : 10/04/2020
  Modified Date: 23/04/2020
*/ 
#include<iostream>
#include<string.h>
using namespace std;
class car
{
public:
	car()
	{
	cout<<"car constructor invoked"<<endl;
	}	
	//virtual destructor of car
	virtual ~car()
	{
	cout<<"car destructor invoked"<<endl;
	}
};
class bmw:public car
{
	public:
	bmw(int wheels)
	{
	cout<<"bmw constructor"<<endl;
	cout<<"wheels= "<<wheels<<endl;
	}
	//virtual destructor of bmw class
	~bmw()
	{
	cout<<"bmw desctructor"<<endl;
	}
};
int main(int argc,char  *argv[])
{
	 
    if(argc == 2 && strcmp(argv[1], "-h")==0)
	{	
		cout<<"This program gives description of orderof constructor and destructors execution with virtual"<<endl;
	}
    else
	{
		//Invoking constructors and virtual destructors creating pointers to the objects.
		bmw *d = new bmw(4);
		car *b = d;
		delete b;
	}
}
