/*case 1:Parsing the command line argument to main function for calculating the type,value and size of the value*/
/*Purpose	:program for calculating the type,value and size of the value by using command line arguments
  filename	:case1.cpp
  Name   	:Kotha Ganesh
  Date   	:07/04/2020*/
#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
/* Function name:string_check
 * Input parameters:String
 * return type:bool
 * */
//Function string_check identify length of string is '1' 0r not
bool string_check(string Strinput)
{
	int i;
	for(i=0;Strinput.length()==1;i++)
	{
		return true;	//condition satisfies it return '1'.
	}
}
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)							//if loop for comparing the input string with "-h"
	    {
    		cout<<"Usage:The main purpose of this program is to calculate the datatype,value and sizeof the value"<<endl;
    		cout<<"user should give the input the following format:"<<endl;
    		cout<<"Input:"<<"\t"<<"1"<<"\t"<<"a"<<"\t"<<"sss"<<"\t"<<"4.5643"<<endl;
			cout<<"output is displayed in the form of:"<<endl;
			cout<<"Type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
			cout<<"char"<<"\t"<<"a"<<"\t"<<"1"<<endl;
			cout<<"int"<<"\t"<<"1"<<"\t"<<"4"<<endl;
			cout<<"string"<<"\t"<<"sss"<<"\t"<<"3"<<endl;
			cout<<"float"<<"\t"<<"4.5643"<<"\t"<<"4"<<endl;
	    }
    	else
    	{
	    	int iI=1;
	    	cout<<argv[0]<<endl;								//print the filename.exe by using argv[0]
	    	cout<<"type"<<"\t"<<"value"<<"\t"<<"size"<<endl;
	    	for(iI=1;iI<argc;iI++)                                      //for loop for checking the argcount
	    	{
		    	int iA=atoi(argv[iI]);							//atoi function convert string to int
		    	float fB=atof(argv[iI]);					//atof function convert string to float
		    	if(iA==0)										//if the 'if' loop is true then char and string will be displayed
		    	{
			    	if(string_check(argv[iI]))	//if condition satisfies means it will print char
					{
						cout<<"char";
						cout<<"\t"<<argv[iI]<< "\t"<<strlen(argv[iI])<<endl;
					}
					else		//it will print string
					{			
						cout<<"string";
						cout<<"\t"<<argv[iI]<< "\t"<<strlen(argv[iI])<<endl;
					}
		    	}
		   		 else											//else case for displaying int and float values
		    	{
			    
			    	if(iA==fB)
			    	{	
				    	cout<<endl<<"int"<<"\t"<<iA<<"\t"<<sizeof(iA);
			    	}
			    	else
			    	{
				    	cout<<endl<<"float"<<"\t"<<fB<<"\t"<<sizeof(fB);
					}
				}
    		}
    	}
	}
}
