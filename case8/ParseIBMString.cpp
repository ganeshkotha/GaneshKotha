// ParseIBMString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

std::string FileName(const std::string& str)
{
	size_t found = str.find_last_of("/\\");
	std::string path = str.substr(found + 1); // check that is OK
	return path;
}

std::string dirnameOf(const std::string& fname)
{
	size_t pos = fname.find_last_of("\\/");
	return (std::string::npos == pos)
		? ""
		: fname.substr(0, pos);
}
bool HasIBM(string str, string searchString)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	transform(searchString.begin(), searchString.end(), searchString.begin(), ::toupper);
	if (str.find(searchString) != std::string::npos)
	{
		return true;
	}
	return false;
}

string Copyright(string str)
{
	if (HasIBM(str, "Confidential"))
	{
		return "Copyright";
	}
	if (HasIBM(str, "Copyright") && HasIBM(str, "Corp"))
	{
		return "Copyright";
	}
	return "";
}
string isMacro(string str)
{
	if (HasIBM(str, "#define"))
	{
		if (HasIBM(str, ".ibm.")) return "MacroWith.com";
		else if(HasIBM(str, "KEY")) return "MacroWithRegistry";
		else 
		return "Macro";
	}
	return "";
}

string url(string str)
{
	if (HasIBM(str, "http:") || HasIBM(str, "https:"))
	{		
		return "URL";
	}
	return "";
}
string ServerName(string str)
{
	if (HasIBM(str, "O=IBM") && HasIBM(str, "CN=") )
	{
		return "ServerName";
	}
	return "";
}

string registry(string str)
{
	if (HasIBM(str, "HKLM"))
	{
		return "Registry";
	}
	return "";
}

string os(string str)
{
	if (HasIBM(str, "IBMRT") || HasIBM(str, "IBMPC") ||
		HasIBM(str, "ibmOS390") || HasIBM(str, "IBMCP") || HasIBM(str, "ibmAS400")
		|| HasIBM(str, "OS2") || HasIBM(str, "IBMC") || HasIBM(str, "IBMRT"))
	{
		return "OS Specific";
	}
	return "";
}

string comment(string str)
{
	string pattern("(/\\*([^*]|[\r\n]|(\\*+([^*/]|[\r\n])))*\\*+/)|(//.*)");
	regex r(pattern, regex_constants::egrep);
	string s1("//");
	string s2("/*");
	string s3(" * ");
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (sregex_iterator it(str.begin(), str.end(), r), end;
		it != end;
		++it)
	{		
		int pos = str.find(s1);
		int pos1 = str.find("IBM");
		int pos2 = str.find(s2);
		if (pos == 0 || (pos > 0 && pos1 > pos))
		{
			return "CommentedLine";
		}
		else if( pos2 >= 0)
		{
			return "CommentedLine";
		}		
	} 
	int pos = str.find(s2);
	int pos1 = str.find("IBM");
	if (pos == 0 || (pos > 0 && pos1 > pos))
	{
		return "CommentedLine";
	}
	pos = str.find(s3);
	if (pos == 0)
	{
		return "CommentedLine";
	}
	return "";
}


string debug(string str)
{
	string str1("xprintf");
	int pos = str.find(str1);
	if (pos >= 0)
	{
		return "Debug";
	}
	return "";
}

string washType(string str)
{
	string type;
	type.append(Copyright(str));
	type.append(isMacro(str));
	type.append(os(str));
	type.append(registry(str));
	type.append(ServerName(str));
	type.append(url(str));	
	type.append(comment(str));
	type.append(debug(str));
	return type;
}

string fileType(string filename, string filepath)
{
	string filetype;
	if (HasIBM(filename, "IBM"))
	{
		filetype = "FileNameHasIBM";
	}
	if (HasIBM(filepath, "IBM"))
	{
		filetype = "PathNameHasIBM";
	}
	if (HasIBM(filename, "IBM") && HasIBM(filepath, "IBM"))
	{
		filetype = "File&PathNameHasIBM";
	}
	if (filename.substr(filename.length() - 3) == ".rc" || filename.substr(filename.length() - 4) == ".dlg")
	{
		filetype = "UI";
	}
	if (filename.substr(filename.length() - 4) == ".def")
	{
		filetype = "External API";
	}
	if (filename.substr(filename.length() - 3) == ".sh")
	{
		filetype = "Script";
	}
	return filetype;
}
bool getIBM(string fileName)
{
	ifstream file(fileName);
	ofstream myfile;
	string newFile = fileName.c_str();
	std::string toReplace(".txt");
	size_t pos = newFile.find(toReplace);
	newFile.replace(pos, toReplace.length(), "_updated.txt");
	myfile.open(newFile);
	if (file.is_open()) {
		string line;
		string filename;
		string LineNumber;
		string filepath;
		string existingFormat;
		string filetype;
		string type;
		regex r("[0-9]: +");
		printf("\nFileName File Path LineNumber Existing Format\n");
		while (getline(file, line))
		{	
			cmatch results;
			if (regex_search(line.c_str(), results, r))
			{
				string delimiter = ":";
				size_t pos = 0;
				
				pos = line.find(delimiter);
				LineNumber = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				existingFormat = line;
				type = washType(line);
				printf("\n%s^%s^%s^%s^%s^%s", filetype.c_str(),filename.c_str(), filepath.c_str(), LineNumber.c_str(), existingFormat.c_str(), type.c_str());
				myfile << filetype.c_str() << "^" << filename.c_str() 
					   << "^" << filepath.c_str() << "^" << LineNumber.c_str() << "^" 
					   << existingFormat.c_str() << "^" << type.c_str() << endl;
			}
			else
			{
				 filetype = "---";
				 filename = FileName(line.c_str());
				 filepath = dirnameOf(line.c_str());
				 if (filepath.empty())
				 {
					 filepath = "*****";
				 }
				 else
				 {
					 filetype = fileType(filename, filepath);
				 }
			}
			
		}
		myfile.close();
		file.close();
	}
	return false;
}




int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Usage ParselIBMString <<inputFileName>>\n");
		return -1;
	}
	getIBM(argv[2]);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
