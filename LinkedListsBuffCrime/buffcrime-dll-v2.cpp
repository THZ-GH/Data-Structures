#include <iostream>
#include <sstream>
#include <fstream>
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

	crimeclass(string cn, int co, string cm,
			   int cy, string cd)
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

	bool IsEmpty() { return head == nullptr; }

	void print()
	{
		if (IsEmpty())
			cout << "List is Empty" << endl;
		else
		{
			crimeclass *temphead = head;
			while (temphead != nullptr)
			{
				cout << "Crime: " << temphead->GetTheCrime() << endl;
				temphead = temphead->GetNext();
			}
		}
	}

	void AddAfter(crimeclass *newcrime)
	{
		crimeclass *temphead = head->GetNext()->GetNext()->GetNext()->GetNext();
		// linking newcrime's previous to temphead's next, and newcrime's next to the next element's previous
		newcrime->SetPrev(temphead);
		newcrime->SetNext(temphead->GetNext());
		// order of statements is critical, this would leave newcrime pointing to itself
		temphead->SetNext(newcrime);
		newcrime->GetNext()->SetPrev(newcrime);
	}

	void AddToFront(crimeclass *newcrime)
	{
		newcrime->SetNext(head);
		head->SetPrev(newcrime);
		head = newcrime;
	}

	void AddtoEnd(crimeclass *newcrime)
	{
		if (IsEmpty())
			head = newcrime;
		else
		{
			crimeclass *temphead = head;
			while (temphead->GetNext() != nullptr)
				temphead = temphead->GetNext();
			temphead->SetNext(newcrime);
			newcrime->SetPrev(temphead);
		}
	}

	// linear search
	bool FindCrime(string keyCrime, crimeclass *&foundCrime)
	{
		if (IsEmpty())
			return false;
		else
		{
			foundCrime = head;
			while (keyCrime != foundCrime->GetTheCrime())
			{
				foundCrime = foundCrime->GetNext();
				if (foundCrime == nullptr)
					return false;
			}
			return true;
		}
	}

	void DeleteCrime(crimeclass *&foundCrime)
	{

		// method 1

		// crimeclass *Helper1, *Helper2;

		// Helper1 = foundCrime->GetPrev();
		// Helper2 = foundCrime->GetNext();

		// Helper1->SetNext(Helper2);
		// Helper2->SetPrev(Helper1);

		// method 2

		foundCrime->GetPrev()->SetNext(foundCrime->GetNext());
		foundCrime->GetNext()->SetPrev(foundCrime->GetPrev());
	}
};

crimeclass *GetCrime(ifstream &buffcrime)
{
	string crime, cmonth, cdate;
	int count, cyear;
	crimeclass *temp = new crimeclass();

	getline(buffcrime, crime, '\t');
	cout << crime << endl;
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

	mydll crimelist;

	crimeclass *temp;

	ifstream buffcrime;
	buffcrime.open("buffcrime2024.txt");

	if (crimelist.IsEmpty())
		cout << "We are doing good so far" << endl;

	cout << "Head is looking at " << crimelist.head << endl;

	crimelist.print();

	temp = GetCrime(buffcrime);

	while (!buffcrime.eof())
	{
		crimelist.AddtoEnd(temp);
		temp = GetCrime(buffcrime);
	}

	//	cout << "Temp is looking at "  << temp  << endl;
	//	cout << "Head is looking at "  << crimelist.head << endl;

	crimelist.print();

	if (crimelist.FindCrime("\nHomicide", temp))
		cout << "Item found." << temp << endl;
	else
		cout << "Item missing." << endl;

	// temp = new crimeclass("Sucker Stealer", 8, "March", 2025, "3/12/2025");
	// cout << endl
	// 	 << "#####################################################" << endl
	// 	 << endl;

	// crimelist.AddToFront(temp);

	// crimelist.print();

	return 0;
}
