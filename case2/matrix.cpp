/*Program	: Matrix Program size M*N with only 0s and 1s, provide the options to perform Row wise, Column Wise and DiagonaL wise replace with *
  Filename	: matrix
  Name      : Kotha Ganesh
  Date		: 13-05-2020
*/
#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
void inputmatrix();
void displaymatrix();
void rowreplace();
void columnreplace();
void diagonalreplace();
//Declaring values globally
int rowcount,columncount,rowposition,columnposition;
char matrix[100][100];
int main (int argc,char *argv[])
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
    cout<<" For help please press '-h' in Command line argument \n Press 4 to exit and go for help"<<endl;
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;  
	inputmatrix();
	displaymatrix();	
	while(1)
	{
		int option;
        cout<<"-------------------------------------------------"<<endl;
        cout<<" 1.Row Replacement\n 2.Column Replacement\n 3.Diagonal Replacement\n 4.Exit "<<endl;
        cout<<"Enter your Option: "<<endl;
    	cin >> option;
		    switch(option)
            {

                case 1:
                        rowreplace();
                        break;
                case 2:
                		columnreplace();
                		break;
                case 3:
                		diagonalreplace();
                		break;
                case 4: 
                		exit(1);
                default:
                        cout<<" Sorry! Invalid option!!! "<<endl;
                    	break;                    
            }
	}
	}
  	return 0;
}
void inputmatrix()
{
	cout<<"Pleas enter 0 or 1 only!!!"<<endl;
	cout<<"Enter  "<<rowcount<<"*"<<columncount<<"Matrix"<<endl; 
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
            cin>>matrix[rowposition][columnposition];
        }
    }
    cout<<endl;
}
void displaymatrix()
{
	cout<<"Entered Matrix:"<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<matrix[rowposition][columnposition]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void rowreplace()
{
char rowmatrix[10][10];
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
        	rowmatrix[rowposition][columnposition]=matrix[rowposition][columnposition];
		}
	}
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
    	int value=1;
    		while(value<=rowcount-1)
			{
			for(columnposition=0;columnposition<rowcount-1;columnposition++)
    		{	
    	 		int indices=columnposition+1;
       			if(rowmatrix[rowposition][columnposition]=='*' || rowmatrix[rowposition][indices]=='*')
       			{
           				break;
       			}
        			if(rowmatrix[rowposition][columnposition]==rowmatrix[rowposition][indices])
        			{
				while(indices<=rowcount-1)
            				{
                					if(indices==rowcount-1)
                					{
                  						rowmatrix[rowposition][rowcount-2]=rowmatrix[rowposition][rowcount-1];
                 						rowmatrix[rowposition][rowcount-1]='*';
                  						break;
                					}
               					rowmatrix[rowposition][indices-1]=rowmatrix[rowposition][indices];
               					indices=indices+1;
            				}
        			}
    		}
		 value=value+1;
    	}
    }
    cout<<"Row representation"<<endl;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
        	cout<<rowmatrix[rowposition][columnposition]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void columnreplace()
{
char columnmatrix[10][10];
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
        	columnmatrix[rowposition][columnposition]=matrix[columnposition][rowposition];
		}
	}
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
    	int value=1;
    		while(value<=rowcount-1)
			{
			for(columnposition=0;columnposition<rowcount-1;columnposition++)
    		{	
    	 		int indices=columnposition+1;
       			if(columnmatrix[rowposition][columnposition]=='*' || columnmatrix[rowposition][indices]=='*')
       			{
           				break;
       			}
        			if(columnmatrix[rowposition][columnposition]==columnmatrix[rowposition][indices])
        			{
				while(indices<=rowcount-1)
            				{
                					if(indices==rowcount-1)
                					{
                  						columnmatrix[rowposition][rowcount-2]=columnmatrix[rowposition][rowcount-1];
                 						columnmatrix[rowposition][rowcount-1]='*';
                  						break;
                					}
               					columnmatrix[rowposition][indices-1]=columnmatrix[rowposition][indices];
               					indices=indices+1;
            				}
        			}
    		}
		 value=value+1;
    	}
    }
    char transposecolumn[10][10];
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
        	transposecolumn[rowposition][columnposition]=columnmatrix[columnposition][rowposition];
    	}
	}
    cout<<"Column representation"<<endl;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
        	cout<<transposecolumn[rowposition][columnposition]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;	
}
void diagonalreplace()
{
	char temporarymatrix[100][100];
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
    		for(columnposition=0;columnposition<columncount;columnposition++)
    		{
       			temporarymatrix[rowposition][columnposition]=matrix[rowposition][columnposition];
    		}
	}
	char digonal1[100];
	char digonal2[100];
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
		digonal1[rowposition]=matrix[rowposition][rowposition];
	}
	int indicesvalue=0;
	for(columnposition=rowcount-1;columnposition>=0;columnposition--)
	{
		digonal2[indicesvalue]=matrix[indicesvalue][columnposition];
		indicesvalue=indicesvalue+1;
	}
	cout<<endl;
	cout<<endl;
	int value=1;
	while(value<=rowcount-1)
	{
		for(columnposition=0;columnposition<rowcount-1;columnposition++)
    		{	
    	 		int indices=columnposition+1;
       			if(digonal1[columnposition]=='*' || digonal1[indices]=='*')
       			{
           				break;
       			}
        			if(digonal1[columnposition]==digonal1[indices])
        			{
				while(indices<=rowcount-1)
            				{
                					if(indices==rowcount-1)
                					{
                  						digonal1[rowcount-2]=digonal1[rowcount-1];
                 						digonal1[rowcount-1]='*';
                  						break;
                					}
               					digonal1[indices-1]=digonal1[indices];
               					indices=indices+1;
            				}
        			}
    		}
		 value=value+1;
    	}
	value=1;
	while(value<=rowcount-1)
	{
    		for(columnposition=0;columnposition<rowcount-1;columnposition++)
    		{
       			int indices=columnposition+1;
       			if(digonal2[columnposition]=='*' || digonal2[indices]=='*')
       			{
           				break;
       			}
        			if(digonal2[columnposition]==digonal2[indices])
        			{
            				while(indices<=rowcount-1)
            				{
                					if(indices==rowcount-1)
                					{
                  						digonal2[rowcount-2]=digonal2[rowcount-1];
                  						digonal2[rowcount-1]='*';
                  						break;
                					}
               					digonal2[indices-1]=digonal2[indices];
              					indices=indices+1;
            				}
        			}
    		}
       		value=value+1;
    }
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
		temporarymatrix[rowposition][rowposition]=digonal1[rowposition];
	}
	indicesvalue=0;
	for(columnposition=rowcount-1;columnposition>=0;columnposition--)
	{
		temporarymatrix[indicesvalue][columnposition]=digonal2[indicesvalue];
		indicesvalue=indicesvalue+1;
	}
	cout<<"Diagonal Matrix "<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
    		for(columnposition=0;columnposition<columncount;columnposition++)
    		{
        			cout<<temporarymatrix[rowposition][columnposition]<<" ";
    		}
    		cout<<endl;
	}
	cout<<endl;
	cout<<endl;		
}
