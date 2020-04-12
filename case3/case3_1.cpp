/* 	Program Name: program is used to describe about the scope of variables
	Name        : KOTHA GANESH
    File Name   : case3_1.cpp
    Date        : 09-04-2020 */
#include<iostream>
#include<string.h>
using namespace std;
//Global Variable 
int numb=54; 
void show() 
{ 
	cout<<"\t"<<numb<<endl; 
} 
// main function
int main(int argc,char *argv[])
{
 	if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
    {
        cout<<"The main purpose of this program is to how to use & Declare the Local & Global scope variable"<<endl;
    }
	else
	{	
	  	// Prints The Variable numb
	   	cout<<"\tGlobal value: ";
		show(); 
		numb=99;
		// numb value Changing And Assigning  to local
		//Compiler gives much precedence to Local variable than global variable
		//Because Local variable defined with Same Name as of Global Variable
		cout<<"\tLocal value: ";
		show(); 
	}
       return 0;	
}
