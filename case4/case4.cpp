/*Program Name     :This program illustrates purpose and difference in public,private and protected access specifiers.
  Name             :Kotha Ganesh
  File Name        :case4.cpp
  Date             :08/04/2020
*/
#include <iostream>
#include<string.h>
using namespace std;
class base
{
 	private:
        int ij;
        double radius;
 	protected:
 	    int ik;
 	public:
 	    int il;
 	    void compute_area(double r) 
        {   // member function can access private  
            // data member radius 
            radius = r;       
            double area = 3.14*radius*radius; 
            cout<<"Accessing  the private data members of a class indirectly using the public member functions of the class"<<endl;
            cout << "Radius is: " << radius << endl; 
            cout << "Area is: " << area; 
        } 
 	base() 
 	{
 	   ij = 1;
 	   ik = 2;
 	   il = 3;
 	}
};
class derive: private base
{
 	public:
 	    	void showdata()
 	    	{
 	        	cout <<  "   Using Accessmode as private    " << endl;
               		cout <<  "   j is not Accessible because we declared as private " << endl;             
              	 	cout <<  "   value of k is   " << ik << endl;
               		cout <<  "   value of l is   " << il << endl;
 	    }
};
class derivea: protected base
{
 	public:
 	    	void showdata()
 	    	{
 	           	cout<<   "   Using Accessmode as protected " << endl;
 	           	cout <<  "   j is not Accessible because we declared as private " << endl;
           		cout <<  "   value of k is   " << ik << endl;
               		cout <<  "   value of l is    " << il << endl;
 	    	}
};
class deriveb: public base
{
 	public:
 	    	void showdata()
 	    	{
 	    		cout<<   "   Using Accessmode as public " << endl;;
 	           	cout <<  "   j is not Accessible because we declared as private " << endl;
               		cout <<  "   value of k is   " << ik << endl;
               		cout <<  "   value of l is   " << il << endl;
 	    	}
};
int main(int argc,char *argv[])
{
    if(argc == 2 && strcmp(argv[1], "-h")==0)
	{
    	cout<<"Main purpose of this rogram is illustration of Accesss specifiers";
	}
	else
	{
		//Creating Object To derive,aderivea,deriveb
     		derive a;	
     		derivea b;
     		deriveb c;
		//Accessing Data through object
     		a.showdata();
     		b.showdata();
     		c.showdata();
     	//Accessing private data
     	   // creating object of the class 
            base obj; 
        // trying to access private data member 
        // directly outside the class 
         obj.compute_area(3.2);  
	} 
	return 0;
}
