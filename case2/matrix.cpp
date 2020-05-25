/*Program	: Matrix Program size M*N with only 0s and 1s, provide the options to perform Row wise, Column Wise and DiagonaL wise replace with *
  Filename	: matrix
  Name      : Kotha Ganesh
  Date		: 13-05-2020
*/
#include<iostream>
#include<string.h>
using namespace std;
void rowreplace();
void columnreplace();
void diagonalreplace();
//Declaring values globally
int rowcount,columncount,rowposition,columnposition;
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
void rowreplace()
{
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;
	char **matrix;
	matrix= new char*[columncount];
	cout<<"Pleas enter 0 or 1 only!!!"<<endl;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
    	matrix[rowposition] = new char[columncount];
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
            cin>>matrix[rowposition][columnposition];
        }
    }
    cout << "Entered Matrix "<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<matrix[rowposition][columnposition]<<"\t";
        }
        cout<<endl;
    }
	int matrixarray[columncount];
	int duplicaterowposition,duplicatecolumnposition,duplicate_rowposition,duplicate_columnposition;
	int rrows=rowcount;
    for (rowposition = 0; rowposition < rrows; rowposition++)
    {
        for (columnposition = 0; columnposition < columncount; columnposition++)
	    {
	        matrixarray[columnposition] = columnposition;
	    }
	    for (columnposition = 0; columnposition < columncount - 1; columnposition++)
	    {
	            duplicaterowposition = rowposition;
	            duplicatecolumnposition= matrixarray[columnposition]; 
	            duplicate_rowposition = rowposition;
	            duplicate_columnposition= matrixarray[columnposition + 1];
	        if (matrix[duplicaterowposition][duplicatecolumnposition] == matrix[duplicate_rowposition][duplicate_columnposition])
	    	{
		        matrixarray[columnposition + 1] = columnposition;
		    }
	    }

        int positioninmatrix=0;
        for (columnposition = 0; columnposition < columncount; columnposition++)
	    {
	        if (matrixarray[columnposition] == columnposition)
	       {
	                matrix[rowposition][positioninmatrix] = matrix[rowposition][columnposition];
	            positioninmatrix++;
	       }
	    }
        while (positioninmatrix!= columncount)
	    {
	            matrix[rowposition][positioninmatrix] = '*';
	        positioninmatrix++;

	    }
    }
    cout << "\nRow wise Output * Representation"<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<matrix[rowposition][columnposition]<<"\t";
        }
        cout<<endl;
    }
}
void columnreplace()
{
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;
	char **matrix;
	matrix= new char*[columncount];
	cout<<"Pleas enter 0 or 1 only!!!"<<endl;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
    	matrix[rowposition] = new char[columncount];
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
            cin>>matrix[rowposition][columnposition];
        }
    }
    cout << "Entered Matrix "<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<matrix[rowposition][columnposition]<<"\t";
        }
        cout<<endl;
    }

	int matrixarray[columncount];
	int duplicaterowposition,duplicatecolumnposition,duplicate_rowposition,duplicate_columnposition;
    int crows=rowcount;
    for (rowposition = 0; rowposition < crows; rowposition++)
    {
        for (columnposition = 0; columnposition < columncount; columnposition++)
	    {
	        matrixarray[columnposition] = columnposition;
	    }
	    for (columnposition = 0; columnposition < columncount - 1; columnposition++)
	    {

	            duplicatecolumnposition = rowposition;
	            duplicaterowposition = matrixarray[columnposition];
	            duplicate_columnposition = rowposition;
	            duplicate_rowposition = matrixarray[columnposition + 1];

	        if (matrix[duplicaterowposition][duplicatecolumnposition] == matrix[duplicate_rowposition][duplicate_columnposition])
	    	{
		        matrixarray[columnposition + 1] = columnposition;
		    }
	    }

        int positioninmatrix=0;
        for (columnposition = 0; columnposition < columncount; columnposition++)
	    {
	        if (matrixarray[columnposition] == columnposition)
	       {
	                matrix[positioninmatrix][rowposition] = matrix[columnposition][rowposition];
	            positioninmatrix++;
	       }
	    }
        while (positioninmatrix!= columncount)
	    {
	        matrix[positioninmatrix][rowposition] = '*';
	        positioninmatrix++;
	    }
    }
    cout << "\nColumn wise Output * Representation"<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<matrix[rowposition][columnposition]<<"\t";
        }
        cout<<endl;
    }
}
void diagonalreplace()
{
	char diagonalmatrix[50][50];
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;
	cout<<"Pleas enter 0 or 1 only!!!"<<endl;
    for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<"Enter ("<<rowposition<<","<<columnposition<<") value: ";
            cin>>diagonalmatrix[rowposition][columnposition];
        }
    }
    cout << "Entered Matrix "<<endl;
	for(rowposition=0;rowposition<rowcount;rowposition++)
    {
        for(columnposition=0;columnposition<columncount;columnposition++)
        {
            cout<<diagonalmatrix[rowposition][columnposition]<<"\t";
        }
        cout<<endl;
    }
	char temporarymatrix[50][50];
	
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
    		for(columnposition=0;columnposition<columncount;columnposition++)
    		{
       			temporarymatrix[rowposition][columnposition]=diagonalmatrix[rowposition][columnposition];
    		}
	}
	char digonal1[50];
	char digonal2[50];
	for(rowposition=0;rowposition<rowcount;rowposition++)
	{
		digonal1[rowposition]=diagonalmatrix[rowposition][rowposition];
	}
	int indicesvalue=0;
	for(columnposition=rowcount-1;columnposition>=0;columnposition--)
	{
		digonal1[indicesvalue]=diagonalmatrix[indicesvalue][columnposition];
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
	cout<<"\nDiagonalMatrix "<<endl;
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
