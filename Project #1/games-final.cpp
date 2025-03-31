#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class gameInfo
{

public:
	string gameTitle, date, rating;
	int gameID;

public:
	gameInfo()
	{
		gameTitle = "";
		date = "";
		rating = "";
		gameID = -1;
	}
};

int linearSearch(vector<gameInfo> heapList, string input);

void initList(ifstream &masterList, gameInfo vectorMaster, vector<gameInfo> &heapList);

gameInfo addTransaction(ifstream &transList);

void printList(vector<gameInfo> &heapList);

int deleteTransaction(ifstream &transList, vector<gameInfo> &heapList, string input);

void readTransFile(ifstream &transList, char transInput, gameInfo &vectorMaster, vector<gameInfo> &heapList, string input);

int main()
{
	ifstream masterList, transList;
	string name, newname, input;
	char transInput;
	gameInfo vectorMaster;
	vector<gameInfo> heapList;

	try
	{
		masterList.open("TestMaster.txt");
		if (masterList.is_open())
		{

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
		masterList.close();
		return 1;
	}

	try
	{
		transList.open("TestTrans.txt");
		if (transList.is_open())
		{
			while (transList)
			{
				readTransFile(transList, transInput, vectorMaster, heapList, input);
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
		cout << "(Your transaction file is not present)" << endl;
	}

	masterList.close();
	transList.close();
	return 0;
}

int linearSearch(vector<gameInfo> heapList, string input)
{
	string tempTitle;
	for (int i = 0; i < heapList.size(); i++)
	{
		tempTitle = heapList.at(i).gameTitle;

		if (tempTitle == input)
		{

			return i;
		}
	}
	return -1;
}

void initList(ifstream &masterList, gameInfo vectorMaster, vector<gameInfo> &heapList)
{

	if (masterList >> vectorMaster.gameID)
	{
		masterList.ignore(1, '\t');
		getline(masterList, vectorMaster.gameTitle, '\t');
		getline(masterList, vectorMaster.date, '\t');
		getline(masterList, vectorMaster.rating);

		heapList.push_back(vectorMaster);
	}
};

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

int deleteTransaction(ifstream &transList, vector<gameInfo> &heapList, string input)
{
	gameInfo tempList;

	bool emptyVector = false;

	if (heapList.empty())
	{
		cout << endl
			 << "Cannot delete on empty data." << endl
			 << endl;
		emptyVector = true;
	}

	transList.ignore(1, '\t');
	getline(transList, tempList.gameTitle);

	input = tempList.gameTitle;

	int index = linearSearch(heapList, input);

	if (emptyVector == false)
	{
		if (index != -1)
		{
			heapList.erase(heapList.begin() + index);

			return 0;
		}
		else
		{
			cout << "The item to delete was not found." << endl
				 << endl;
			return -1;
		}
	}
	else
		return 0;
}

void printList(vector<gameInfo> &heapList)
{

	gameInfo i;
	cout << left << setw(25) << "Game Title" << "Rating" << endl;
	for (auto i : heapList)
	{
		if (i.gameID != -1)
		{
			cout << left << fixed << setw(25) << i.gameTitle << i.rating << endl;
		}
	}
	cout << endl;
};

void readTransFile(ifstream &transList, char transInput, gameInfo &vectorMaster, vector<gameInfo> &heapList, string input)
{

	transList >> transInput;

	switch (transInput)
	{
	case 'A':
	case 'a':
		heapList.push_back(addTransaction(transList));
		break;
	case 'D':
	case 'd':
		deleteTransaction(transList, heapList, input);
		break;
	case 'P':
	case 'p':
		printList(heapList);
		break;
	default:
		cout << "No More Updates (Transaction Input Error)" << endl
			 << endl;
	}
};
