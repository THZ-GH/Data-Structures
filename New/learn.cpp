#include <iostream>
#include <fstream>

using namespace std;

string casecorrection(string oldstring){
	string newstring = "";
	for (int i = 0; i < oldstring.length(); i++ )
	{
		newstring[i] = tolower(oldstring[i]); 
	}
	return newstring;
};

int main() {

	ifstream learning;
	string name, newname;

	try {

		learning.open("learn.txt");
		if (learning.is_open()){
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

	if(!learning.eof())
	{

		getline(learning, name);
		cout << name << endl;
		newname = casecorrection(name);

		if (name == "molly")
			cout << "Molly has been found" << endl;
		else
			cout << "no molly" << endl;
	}
	else
	{
		cout << "File is empty." << endl;
	}


	learning.close();

	return 0;
}