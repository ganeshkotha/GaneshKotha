/*Program     : program tells the different ways to initialize private data members.
  Name        : Kotha Ganesh
  Filename    : case5_1scope.cpp
  Date        : 09/04/2020
*/
#include<iostream>
#include<string.h>>
using namespace std;
class Rectangle
{ 
	//Declaration int variable
	int iLength;
	int ibreadth;
	static int iLen;
	static int iBre;
	public:
		/*Function name		:calculatearea
		 *Return type		:void
		 *Input parameters	:int,int
		*/
		void calculatearea(int iLength,int ibreadth)
        {	   
            int Area;
		  	//calculating area of rectangle
		 	Area=(iLength*ibreadth);
            cout<<"\n\tArea of Rectangle:"<<Area<<endl;
        }

		/*Function Name		:calculateperimeter()
		 * Return Type		:void
		 * Input Parameters	:int,int
		 */
	    void calculateperimeter()
		{
			int iPeri;
			iPeri=2*(iLen+iBre);
			cout<<"\n\tPerimeter of Rectangle:"<<iPeri<<endl;
		}

};
//private data member using scope resolution and assigning value.
int Rectangle::iLen=70;
int Rectangle::iBre=60;
//MainFunction
int main(int argc ,char **argv)
{
	//declaration of object for rectangle class
        Rectangle rect;
        if(argc == 2 && strcmp(argv[1], "-h")==0)
        {
          cout<<"This program gives description of initializing private data members in different ways i.e.,Scope resolution operator,indirect initialisation and friend function"<<endl;
        }
	else
	{
		//accessing calculatearea function
        	rect.calculatearea(5,6);
		rect.calculateperimeter();
	}
	return 0;
}
