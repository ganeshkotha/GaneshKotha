/*case 2:Find the formula for given expression and write the program for the given input expression:1+4+9+16+....+100*/
/*purpose	:Program for calculating the sum of the squares of a given number
  Filename	:case2.cpp
  Name 	    :Kotha Ganesh
  Date   	:07/04/2020*/
#include<iostream>
#include<string.h>
using namespace std;
/* Function name:sumofsquares
 * Input parameter:int
 * Output parameter:int
 * */
void sumofsquares()
{
        int kP,input_num,Sumvalue=0;							//intialialize the required variables
        cout<<"calculating the sum of the series (1*1)+(2*2)+(3*3)+(4*4)+(5*5)+...+(n*n):"<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"enter the value:";		
        cin>>input_num;								
        for(kP=1;kP<=input_num;kP++) 						//for loop to calculate the sum of series up to the nth term
	    {
            Sumvalue+=kP*kP;							
        }
        cout<<"The sum of the above series is:"<<Sumvalue<<endl;   
}
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)					//if loop for comparing the input string with "-h"
	    {
            cout<<"Usage:The main purpose of this program is to calculate the sum of the squares of a given number which is the following format:\n (1*1)+(2*2)+(3*3)+......(n*n) "<<endl;
            cout<<"After compile and execute it will ask value 'User need to enter the integer value'"<<endl;
	    }
	    
    }
	else
	{
        sumofsquares();
    }
    
}
