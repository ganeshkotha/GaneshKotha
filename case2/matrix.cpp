/*Program	: Matrix Program size M*N with only 0s and 1s, provide the options to perform Row wise, Column Wise and DiagonaL wise replace with *
  Filename	: matrixrepresentation
  Name      : Kotha Ganesh
  Date		: 13-05-2020
*/
#include<iostream>
#include<string.h>
using namespace std;
void rowreplace()
{
	int rowcount,columncount;
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;
	char **matrix;
	int rowposition,columnposition;
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
	int rtrue=0;
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
	        if(rtrue==0)
	        {
	            duplicaterowposition = rowposition;
	            duplicatecolumnposition= matrixarray[columnposition]; 
	            duplicate_rowposition = rowposition;
	            duplicate_columnposition= matrixarray[columnposition + 1];
	        }
	        else
	        {
	            duplicatecolumnposition = rowposition;
	            duplicaterowposition = matrixarray[columnposition];
	            duplicate_columnposition = rowposition;
	            duplicate_rowposition = matrixarray[columnposition + 1];
	        }
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
	           if(rtrue==0)
	                matrix[rowposition][positioninmatrix] = matrix[rowposition][columnposition];
	           else
	                matrix[positioninmatrix][rowposition] = matrix[columnposition][rowposition];
	            positioninmatrix++;
	       }
	    }
        while (positioninmatrix!= columncount)
	    {
	        if(rtrue==0)
	            matrix[rowposition][positioninmatrix] = '*';
	       else
	        matrix[positioninmatrix][rowposition] = '*';
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
	int rowcount,columncount;
    cout<<"Enter the count of rows:"<<endl;
    cin >> rowcount;
    cout<<"Enter the count of columns"<<endl;
    cin>>columncount;
	char **matrix;
	int rowposition,columnposition;
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
	int ctrue=1;
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
	        if(ctrue==0)
	        {
	            duplicaterowposition = rowposition;
	            duplicatecolumnposition= matrixarray[columnposition]; 
	            duplicate_rowposition = rowposition;
	            duplicate_columnposition= matrixarray[columnposition + 1];
	        }
	        else
	        {
	            duplicatecolumnposition = rowposition;
	            duplicaterowposition = matrixarray[columnposition];
	            duplicate_columnposition = rowposition;
	            duplicate_rowposition = matrixarray[columnposition + 1];
	        }
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
	           if(ctrue==0)
	                matrix[rowposition][positioninmatrix] = matrix[rowposition][columnposition];
	           else
	                matrix[positioninmatrix][rowposition] = matrix[columnposition][rowposition];
	            positioninmatrix++;
	       }
	    }
        while (positioninmatrix!= columncount)
	    {
	        if(ctrue==0)
	            matrix[rowposition][positioninmatrix] = '*';
	       else
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
int main (int argc,char **argv)
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
    	cout<<" For help please press '-h' in Command line argument \n Press 3 to exit and go for help"<<endl;
	while(1)
	{
		int option;
        cout<<"-------------------------------------------------"<<endl;
        cout<<" 1.Row Replacement\n 2.Column Replacement\n 3.Exit "<<endl;
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
                        exit(1);
                default:
                        cout<<" Sorry! Invalid option!!! "<<endl;
                    	break;                    
            }
    }
	}
  	return 0;
}
