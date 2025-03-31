#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class gameInfo
{

	// Members
public:
	string gameTitle, date, rating;
	int gameID;

	// Constructor
public:
	gameInfo()
	{
		gameTitle = "";
		date = "";
		rating = "";
		gameID = -1;
	}
};

// implement this at some point, for delete (searching)
string casecorrection(string oldstring)
{
	string newstring;
	for (int i = 0; i < oldstring.length(); i++)
		newstring += tolower(oldstring[i]);
	return newstring;
}

// choose either reference or pointer, get vector into function.
// load each element into vector
void initList(ifstream &masterList, gameInfo vectorMaster, vector<gameInfo> &heapList)
{

	masterList >> vectorMaster.gameID;
	// Ignore one tab character, setting up for the first getline
	masterList.ignore(1, '\t');
	getline(masterList, vectorMaster.gameTitle, '\t');
	getline(masterList, vectorMaster.date, '\t');
	getline(masterList, vectorMaster.rating);

	heapList.push_back(vectorMaster);
};

// Finish making this a loop, so it goes through entire transaction file
gameInfo addTransaction(ifstream &transList)
{
	gameInfo tempList;

	transList >> tempList.gameID;
	transList.ignore(1, '\t');
	getline(transList, tempList.gameTitle, '\t');
	getline(transList, tempList.date, '\t');
	getline(transList, tempList.rating);

	return tempList;
};

void deleteTransaction(); // Extra credit?

// Maybe use auto in the for loop to detect when vector is stepped through all the way
gameInfo printList(gameInfo &vectorMaster, vector<gameInfo> &heapList)
{

	gameInfo i;
	cout << "Game Title" << setw(20) << "Rating" << endl;
	for (auto i : heapList)
	{
		if (i.gameID != -1)
		{
			// cout << i.gameID << "	";
			cout << left << fixed << setw(25) << i.gameTitle << i.rating << endl;
			// cout << i.date << "	";
		}
	}
	cout << endl;
	return i;
};

gameInfo readTransFile(ifstream &transList, char transInput, gameInfo &vectorMaster, vector<gameInfo> &heapList)
{

	transList >> transInput;

	gameInfo defaultInput;
	string discardLine;

	switch (transInput)
	{
	case 'A':
		return addTransaction(transList);
		break;
	case 'a':
		return addTransaction(transList);
		break;
	case 'D':
		cout << "(Deletion has not been implemented yet.)" << endl
			 << endl;
		getline(transList, discardLine);
		return defaultInput;
		// return deleteTransaction();
	case 'd':
		cout << "(Deletion has not been implemented yet.)" << endl
			 << endl;
		getline(transList, discardLine);
		return defaultInput;

		// return deleteTransaction();

	case 'P':
		return printList(vectorMaster, heapList);
		break;
	case 'p':
		return printList(vectorMaster, heapList);
		break;
	default:
		cout << "End of Transaction File (Invalid Input Encountered)" << endl
			 << endl;
		break;
	}

	// if (transInput == 'A' || transInput == 'a'){
	// 	return addTransaction(transList);
	// } else if (transInput == 'D' || transInput == 'd'){
	// 	// return deleteTransaction();
	// } else if (transInput == 'P' || transInput == 'p'){
	// 	return printList(vectorMaster, heapList);
	// }
};

int main()
{
	ifstream masterList, transList;
	string name, newname;
	char transInput;
	gameInfo vectorMaster;
	vector<gameInfo> heapList;

	try
	{
		masterList.open("TestMaster.txt");
		if (masterList.is_open())
		{

			// make loop to go until file has ended
			while (!masterList.eof())
			{
				initList(masterList, vectorMaster, heapList);
			}
		}
		else
		{
			throw(401);
		}
	}
	catch (int errorcode)
	{
		cout << "Error " << errorcode << " has occurred." << endl;
		cout << "(Your master list file is not present)" << endl;
	}

	try
	{
		transList.open("TestTrans.txt");
		if (transList.is_open())
		{
			// Step through trans file, processing until it's empty
			while (transList)
			{
				heapList.push_back(readTransFile(transList, transInput, vectorMaster, heapList));
			}
			printList(vectorMaster, heapList);
		}
		else
		{
			throw(401);
		}
	}
	catch (int errorcode)
	{
		cout << "Error " << errorcode << " has occurred." << endl;
		cout << "(Your transaction file is not present)" << endl;
	}

	// try {
	// 	transList.open("TestTrans.txt");
	// 		if (transInput == 'A' || transInput == 'a'){
	// 			addTransaction;
	// 		} else if (transInput == 'P' || transInput == 'd'){
	// 			deleteTransaction;
	// 		} else if (transInput == 'P' || transInput == 'p'){
	// 			printList;
	// 		}
	// }

	masterList.close();
	transList.close();
	return 0;
}

// // testing for an empty file
// if (!learning.eof())
//  {
//    getline(learning, name);
//    cout << name << endl;
//    newname = casecorrection(name);
//    cout << newname << endl;
//    if (newname == "molly")
//       {
//       	cout << "Molly has been found!!!" << endl;
//       }
//    else
//       {
//          cout << "there is no Molly"  << endl;
//       }
//  }
// else
//  {
//    cout << "Your file is Empty" << endl;
//  }

// cout << "arrived at b" << endl;