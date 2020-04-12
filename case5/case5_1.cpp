/*Program     : program tells the different ways to initialize private data members.
  Name        : Kotha Ganesh
  Filename    : case5_1.cpp
  Date        : 09/04/2020
*/
#include <iostream>
#include<string.h>
using namespace std;
class Circle
{
private: 
              int ir;
public:
			Circle(int ir=5)
				{
					this->ir=ir;
				}
            void area(double ii)
              	{
                   ir=ii;
                   double da=3.14*ir*ir;
                   cout<<"Area:"<<da<<endl;             
				}
              void area()
               {
                   double da=3.14*ir*ir;
                   cout<<"Area: "<<da<<endl;                
			   }
                   
};
class Distance
{
    private:
        int imeter; 
    public:
        Distance(): imeter(0) { }
        //friend function
        friend int addFive(Distance);
};
// friend function definition
int addFive(Distance d)
{
    //accessing private data from non-member function
    d.imeter += 5;
    return d.imeter;
}
int main(int argc,char **argv)
{
             if(argc == 2 && strcmp(argv[1], "--help")==0)
          {
         
         cout<<"This program gives description of initializing private data members in different ways i.e.,Scope resolution operator,indirect initialisation and friend function"<<endl;
          }
         else
         {
         Circle obj;
         obj.area();
         obj.area(9);
         Distance D;
         cout<<"Distance: "<< addFive(D);
         return 0;
         }
}
