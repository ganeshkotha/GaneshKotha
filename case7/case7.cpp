/*Program	: To perform the add delete modiefy of configuration into a file.
  Filename	: Case7.cpp
  Name      : Kotha Ganesh
  Date		: 11-04-2020
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Notes
{
private:

        char cNotes[400];
        char cDirectory[400];
        int iKit;
        int iInstall;
        int iPartitionnum;
        int iControllerstatus;        
        char cService[400];
        char cRecovery[400];
        int iTimezone;
        int iDst;
        int iDstlaw;
        char cFiledir[400];
        void goback(){
                cout<<" Press enter to go back "<<endl;
                cin.get();
        }
		//creating addnote function
		void addNotes(void)
		{
                char moreRecords;  
				do{              
                        cout<<"----------------------------------------"<<endl;
                        cout<<" NotesProgram name= ";
                        cin>>cNotes;
                        cout<<" Directory= ";
                        cin>>cDirectory;
                        cout<<" Kit Type= ";
                        cin>>iKit;
                        cout<<" Install Type= ";
                        cin>>iInstall;
                        cout<<" Partition Number= ";
                        cin>>iPartitionnum;
                        cout<<" show Controller Status Window= ";
                        cin>>iControllerstatus;
                        cout<<" Service Name= ";
                        cin>>cService;                        
                        cout<<" Fault Recovery_Build= ";
                        cin>>cRecovery;                        
                        cout<<" Timezone= ";
                        cin>>iTimezone;                        
                        cout<<" DST= ";
                        cin>>iDst;                        
                        cout<<" DST LAW= ";
                        cin>>iDstlaw;                        
                        cout<<" FileDlg Directory= ";
                        cin>>cFiledir;                        
                        cout<<"----------------------------------------"<<endl;
                        char ch;
                        cout<<"Enter 'y' to save above information "<<endl;
                        cin>>ch;
                        //if statment to add more file or not
                        if(ch=='y'){
                                FILE  *file;
                                file= fopen("config.ini","a");
                                fprintf(file," NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cNotes, cDirectory, iKit, iInstall, iPartitionnum, iControllerstatus, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                                fclose(file);
                                cout<<" Information is added to database\n";
                        }
                        else
                        //returning to add another note
                        addNotes();
                        goback();
                        getchar();
                        cout<<"do you want to add more records? (Y/N)"<<endl;
                        cin>>moreRecords;
                }while(moreRecords=='y');
        }
        // declaring list functon
		void listconfig(void){

                FILE *file;
                // commands to open file for read
                file= fopen("config.ini", "r");
                cout<<"      ListConfig	\n";
                // displaying the data
                while(fscanf(file," NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cNotes[0], &cDirectory[0], &iKit, &iInstall, &iPartitionnum, &iControllerstatus, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
				{
                	cout<<"----------------------------------------"<<endl;
                        cout<<" NotesProgram= "<<cNotes<<endl;
                        cout<<" Directory= "<<cDirectory<<endl;
                        cout<<" KitType= "<<iKit<<endl;
                        cout<<" InstallType= "<<iInstall<<endl;
                        cout<<" PartitionNumber= "<<iPartitionnum<<endl;
                        cout<<" showControllerStatusWindow= "<<iControllerstatus<<endl;
                        cout<<" ServiceName= "<<cService<<endl;                        
                        cout<<" FaultRecovery_Build= "<<cRecovery<<endl;                        
                        cout<<" Timezone= "<<iTimezone<<endl;                        
                        cout<<" DST= "<<iDst<<endl;                        
                        cout<<" DSTLAW= "<<iDstlaw<<endl;                        
                        cout<<" FileDlgDirectory= "<<cFiledir<<endl;                        
                        cout<<"----------------------------------------"<<endl;
				}
        		//closing the file
                fclose(file);
                goback();
        }
 		// declaring edit functiom
 		void editExisting(void)
		{
                char checkId[30];
                cout<<"\nEnter notes program name = ";
                cin>>checkId;
                char newFiledir[300];
                cout<<"\n-----------------------------";
                cout<<"\nEnter new notes program name = ";
                cin>>newFiledir;
                
                FILE *file, *tempfile;
                //opening configure file for read
                file= fopen("config.ini", "r");
                //opening tempfile to write
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file,"\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cNotes[0], &cDirectory[0], &iKit, &iInstall, &iPartitionnum, &iControllerstatus, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
				{
                        //statment to check given note program name is present
						if(strcmp(checkId, cNotes)==0)
                                fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", newFiledir, cDirectory, iKit, iInstall, iPartitionnum, iControllerstatus, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                        else
                                fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cNotes, cDirectory, iKit, iInstall, iPartitionnum, iControllerstatus, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                }
                fclose(file);
                fclose(tempfile);
                //removing the configuration file
                int isRemoved= remove("config.ini");
                // renaming the temp file into configuration file
                int isRenamed= rename("temp.txt", "config.ini");
                goback();
        }
        //declaring delete function
        void deleteConfig(void){

                char checkId[30];
                cout<<"Enter notes program Name= "<<endl;
                cin>>checkId;
                char ch;
                //asking user to conformely delete the file
                cout<<" Confirmation\n Enter 'y' To Confirm Deletion "<<endl;
                cin>>ch;
                if(ch=='y'){
                        FILE *file, *tempfile;
                        file= fopen("config.ini", "r");
                        tempfile= fopen("temp.ini", "w");
                        while(fscanf(file, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cNotes[0], &cDirectory[0], &iKit, &iInstall, &iPartitionnum, &iControllerstatus, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
                                //statment to check given note program name is present
								if(strcmp(checkId, cNotes)!=0)
                                        fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cNotes, cDirectory, iKit, iInstall, iPartitionnum, iControllerstatus, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                                        fclose(file);
                                        fclose(tempfile);
                                        //removing the configuration file
                                        int isRemoved= remove("config.ini");
                                        // renaming the temp file into configuration file
                                        int isRenamed= rename("temp.ini", "config.ini");
                                        cout<<"\nRemoved data Successfully"<<endl;
                }
                else
                    deleteConfig();
        }
		
public:
        //declaring option function
		void options(void){
                while(true){

                        cout<<"           Notes Config List     "<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"         1:   AddConfig"<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"         2:   listconfig"<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"         3:   editExisting"<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"         4:   deleteConfig"<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"         0:   To Exit     "<<endl;
                        cout<<"      ---------------------------"<<endl;
                        cout<<"       Please Enter Your Choice: "<<endl;

                        int choice;
                        cin>>choice;
						// using switch case to execute the user requirments
                        switch (choice) {
                                case 0:
                                        cout<<" Notes Domino List  "<<endl;
                                        return;
                                case 1:
                                        addNotes();
                                        break;
                                case 2:
                                		listconfig();
                                		break;
                                case 3:
                                		editExisting();
                                		break;
                                case 4: 
                                		deleteConfig();
                                		break;
                                default:
                                        cout<<" Sorry! Invalid option!!! "<<endl;
                                        break;
                        }
                }
        }
};
int main(int argc, char *argv[])
{
	if(argc>=2)
    	{
	    	//For comparing input string through command line is -h
			if(strcmp(argv[1],"-h")==0)	
	    {
            cout<<"program is to add delete and edit the configuration in a file "<<endl;
	    }
    }
	else
	{
		//Object declaration
        Notes n;
        n.options();
        return 0;
	}	
}
