#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class crimeclass
{

	// These are the class members // fields  // attributes
private:
	string crime, cmonth, cdate;
	int count, cyear;
	crimeclass *next, *prev;

	// Class Constructor

public:
	crimeclass()
	{
		crime = "";
		count = -1;
		cmonth = "";
		cyear = -1;
		cdate = "";
		next = nullptr;
		prev = nullptr;
	}

	crimeclass(string cn, int co, string cm, int cy, string cd)
	{
		crime = cn;
		count = co;
		cmonth = cm;
		cyear = cy;
		cdate = cd;
		next = nullptr;
		prev = nullptr;
	}

	// Getters

	string GetTheCrime() { return this->crime; }
	int GetTheCounts() { return this->count; }
	string GetTheMonth() { return this->cmonth; }
	int GetTheYear() { return this->cyear; }
	string GetTheDate() { return this->cdate; }
	crimeclass *GetNext() { return this->next; }
	crimeclass *GetPrev() { return this->prev; }

	// Setters

	void SetTheCrime(string crime) { this->crime = crime; }
	void SetTheCounts(int count) { this->count = count; }
	void SetTheMonth(string month) { this->cmonth = month; }
	void SetTheYear(int year) { this->cyear = year; }
	void SetTheDate(string _cdate) { cdate = _cdate; }
	void SetNext(crimeclass *newnext) { next = newnext; }
	void SetPrev(crimeclass *newprev) { prev = newprev; }

	// Example of not using the "this->" method
};

class mydll
{
public:
	crimeclass *head = nullptr;
	// crimeclass * tail = nullptr;

	bool isEmpty()
	{
		return head == nullptr;
	}

	void print()
	{
		crimeclass *temphead = head;
		if (isEmpty())
			cout << "List is currently empty." << endl;
		else
			while (temphead != nullptr)
			{
				cout << "Crime: " << temphead->GetTheCrime() << endl;
				temphead = temphead->GetNext();
			}
	}

	void addToEnd(crimeclass *newCrime)
	{

		if (isEmpty())
			head = newCrime;
		else
		{
			crimeclass *temphead = head;
			while (temphead->GetNext() != nullptr)
			{

				temphead = temphead->GetNext();
			}
			temphead->SetNext(newCrime);
			newCrime->SetPrev(temphead);
		}
	}
};

crimeclass *GetCrime(ifstream &buffcrime)
{

	string crime, cmonth, cdate;
	int count, cyear;
	crimeclass *temp = new crimeclass();

	getline(buffcrime, crime, '\t');
	buffcrime >> count >> cmonth >> cyear >> cdate;
	buffcrime.ignore();

	temp->SetTheCrime(crime);
	temp->SetTheCounts(count);
	temp->SetTheMonth(cmonth);
	temp->SetTheYear(cyear);
	temp->SetTheDate(cdate);

	return temp;
}

int main()
{

	mydll crimeList;

	crimeclass *temp;

	ifstream buffcrime;
	buffcrime.open("buffcrime.txt");

	// if (crimeList.isEmpty())
	// cout << "nice" << endl;

	crimeList.print();

	temp = GetCrime(buffcrime);

	while (!buffcrime.eof())
	{
		crimeList.addToEnd(temp);
		temp = GetCrime(buffcrime);
	}

	// cout << "Temp is pointing to " << temp << endl;
	// cout << "Head is pointing to " << crimeList.head << endl;

	crimeList.print();

	// getline(buffcrime, temp, '	');
	// report[0].SetTheCrime(temp);

	// // buffcrime >> count >> cmonth >> cyear >> cdate;

	// cout << report[0].GetTheCrime() << endl;

	// //<< count << cmonth  << cyear
	// //     << cdate << endl;

	return 0;
}