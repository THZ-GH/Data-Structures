#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class games {

};

string casecorrection(string oldstring){
	string newstring = "";
	for (int i = 0; i < oldstring.length(); i++ )
	{
		newstring[i] = tolower(oldstring[i]); 
	}
	return newstring;
};

int main(){

	ifstream gameList;
	string title, newtitle;

		try {

		gameList.open("TestMaster.txt");
		if (gameList.is_open()){
			// continue program
		}
		else
		{
			throw(401);
		}
	}
	catch (int errorcode){
		cout << "Error " << errorcode << " occurred." << endl;
		cout << "(Your file was not found)" << endl;
	}
	if(!gameList.eof())
	{

		getline(gameList, title);
		cout << title << endl;
		newtitle = casecorrection(title);

		if (title == "INSERT TITLE HERE (HARDCODED)")
			cout << " found" << endl;
		else
			cout << "not found" << endl;
	}
	else
	{
		cout << "File is empty." << endl;
	}



	return 0;
}