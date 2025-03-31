#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class gameInfo {
	
	// Members
	public:
		string gameTitle, date, rating;
		int gameID;

	// Constructor
	public:
		gameInfo() {
			gameTitle = "";
			date = "";
			rating = "";
			gameID = -1;
		}
};	


void initList(ifstream& masterList, gameInfo vectorMaster, vector<gameInfo>& heapList){

	masterList >> vectorMaster.gameID;
	// Ignore one tab character, setting up for the first getline
	masterList.ignore(1, '\t');
	getline(masterList, vectorMaster.gameTitle, '\t');
	getline(masterList, vectorMaster.date, '\t');
	getline(masterList, vectorMaster.rating);

	heapList.push_back(vectorMaster);
};


gameInfo addTransaction(ifstream& transList){

	gameInfo tempList;

	transList >> tempList.gameID;
	transList.ignore(1, '\t');
	getline(transList, tempList.gameTitle, '\t');
	getline(transList, tempList.date);
	getline(transList, tempList.rating);

	return tempList;

};

void deleteTransaction();

gameInfo printList(gameInfo& vectorMaster, vector<gameInfo>& heapList){

	gameInfo i;
	for (auto i : heapList){
	cout << i.gameID << "	";
	cout << i.gameTitle << "	";
	cout << i.date << "	";
	cout << i.rating << endl;
	}

	return i;

};

gameInfo readTransFile(ifstream& transList, char transInput, gameInfo& vectorMaster, vector<gameInfo>& heapList){

	transList >> transInput;

	gameInfo defaultInput;
	
	switch (transInput)
	{
	case 'A':
		return addTransaction(transList);
		break;
	case 'a':
		return addTransaction(transList);
		break;
	case 'D':
		cout << "Deletion has not been implemented yet." << endl;
		return defaultInput;
	case 'd':
		cout << "Deletion has not been implemented yet." << endl;
		return defaultInput;
	case 'P':
		return printList(vectorMaster, heapList);
		break;
	case 'p':
		return printList(vectorMaster, heapList);
		break;
	default:
		cout << "Invalid Transaction Input" << endl;
		break;
	}


};

int main()
{
	ifstream masterList, transList;
	string name, newname;
	char transInput;
	gameInfo vectorMaster;
	vector<gameInfo> heapList;


	try {	
		masterList.open("TestMaster.txt");
	    	if (masterList.is_open()){


				while (!masterList.eof()){
				initList(masterList, vectorMaster, heapList);
				}
				
			}
     	     else
			{
			      throw (401);
	 	   }
   		}
		catch (int errorcode)
		{
			cout << "Error " << errorcode << " has occurred." << endl;
			cout << "(Your master list file is not present)" << endl;
		}

	try {	
		transList.open("TestTrans.txt");
			if (transList.is_open()){

				// Step through trans file, processing until it's empty
				while (transList){
				heapList.push_back(readTransFile(transList, transInput, vectorMaster, heapList));
				printList(vectorMaster, heapList);	
			}
			}
			  else
			{
				  throw (401);
			}
		   }
		catch (int errorcode)
		{
			cout << "Error " << errorcode << " has occurred." << endl;
			cout << "(Your transaction file is not present)" << endl;
		}

    masterList.close(); 
	transList.close();
	return 0;
}
