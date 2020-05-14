/*Program	: Matrix Program size M*N with only 0s and 1s, provide the options to perform Row wise, Column Wise and DiagonaL wise replace with *
  Filename	: matrixrepresentation
  Name      : Kotha Ganesh
  Date		: 13-05-2020
*/
#include<iostream>
#include<string.h>
using namespace std;
class matrixrepresentation
{
private:
int matrix[10][10],rowcount,columncount,rowposition,columnposition;
void inputmatrix()
{
    	cout<<"Enter Rows and coloumns"<<endl;
    	cout<<"Enter the count of rows:";
    	cin>>rowcount;
    	cout<<"Enter the count of columns:";
    	cin>>columncount;
		int rowposition,columnposition;
    	for(rowposition=0;rowposition<rowcount;rowposition++)
    	{
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            bool check=true;
            cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
            cin>>matrix[rowposition][columnposition];
            while(check)
            {
                if(matrix[rowposition][columnposition]==1 || matrix[rowposition][columnposition]==0)
                {
                    check=false;
                }
                else
                {
                    cout<<"Pleas enter 0 or 1 only!!!"<<endl;
                    cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
                    cin>>matrix[rowposition][columnposition];
                }
            }
        }
    	}
    	cout<<endl;
    	cout<<"Entered Matrix :"<<"\n";
    	for(rowposition=0;rowposition<rowcount;rowposition++)
    	{
        	for(columnposition=0;columnposition<columncount;columnposition++)
        	{
            	cout<<matrix[rowposition][columnposition]<<"\t";
        	}
        	cout<<"\n";
    	}
}
void rowreplace()
{
 	cout<<"Row wise * matrix"<<"\n";  
    int rowposition,columnposition=1,countvariable;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        int duplicatecolumncount=columncount;
        int temp=matrix[rowposition][0];
        columnposition=1,countvariable=0;
        while(columnposition<duplicatecolumncount)
        {
            if(matrix[rowposition][columnposition]==temp)
            {
                countvariable++;
                int duplicatecolumnposition=columnposition;
                while(duplicatecolumnposition<duplicatecolumncount-1)
                {
                    matrix[rowposition][duplicatecolumnposition]=matrix[rowposition][duplicatecolumnposition+1];
                    duplicatecolumnposition++;
                }
                duplicatecolumncount--;
            }
            temp=matrix[rowposition][columnposition];
            columnposition++;
        }
        cout<<matrix[rowposition][0]<<"\t";
        int temp1=matrix[rowposition][0];
        int duplicatecolumnposition=1;
        while(duplicatecolumnposition<duplicatecolumncount)
        {
            
            if(matrix[rowposition][duplicatecolumnposition]==temp1)
             {
                cout<<"*"<<"\t";
             }
            else
            {
                cout<<matrix[rowposition][duplicatecolumnposition]<<"\t";
            }
            temp1=matrix[rowposition][duplicatecolumnposition];
            duplicatecolumnposition++;
        }
        while(countvariable>0)
        {
            cout<<"*"<<"\t";
            countvariable--;
        }
        cout<<endl;
    }      
}
public:
	void options()
	{

        while(1)
        { 
			int option;
            cout<<"-------------------------------------------------"<<endl;
        	cout<<" 1.Enter matrix\n 2.Row Replacement (note: only row opeation works)\n 3.Column Replacement\n 4.Diagnol Replacement\n 5.Corner\n 6.Exit "<<endl;
            cout<<"Enter your Choice: "<<endl;
            cin>>option;
            cout<<"--------------------------------------------------"<<endl;
		    switch(option)
            {
                case 1:
                        inputmatrix();
                        break;
                case 2:
                        rowreplace();
                        break;
               /*case 3:
                		columnreplace();
                		break;
                case 4:
                		Diagonalreplace();
                		break;
                case 5:
                		corner();
                		break;*/
                case 6:
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
			if(strcmp(argv[1],"-h")==0)			//strcmp is for comparing input string of command line -h
	    {
            cout<<" This program is about matrix representation provide the options to perform Row wise, Column Wise and DiagonaL wise to replace with * "<<endl;
            cout<<" You have to choose the options"<<endl;
	    }
    	}
		else
		{
			cout<<" For help please press '-h' in Command line argument"<<endl;
			cout<<" Press 6 to exit and go for help"<<endl;
			cout<<"Only row operation works"<<endl;
			matrixrepresentation object;
			object.options();
			return 0;
			
        }	
}

