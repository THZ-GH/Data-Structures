#include <iostream>
#include <fstream>
using namespace std;

class crimeclass
{

	// These are the class members // fields  // attributes
private:
	string crime, cmonth, cdate;
	int count, cyear;

	// Class Constructor

public:
	crimeclass()
	{
		crime = "";
		count = -1;
		cmonth = "";
		cyear = -1;
		cdate = "";
	}

	crimeclass(string cn, int co, string cm,
			   int cy, string cd)
	{
		crime = cn;
		count = co;
		cmonth = cm;
		cyear = cy;
		cdate = cd;
	}

	// Getters

	string GetTheCrime() { return this->crime; }
	int GetTheCounts() { return this->count; }
	string GetTheMonth() { return this->cmonth; }
	int GetTheYear() { return this->cyear; }
	string GetTheDate() { return this->cdate; }

	// Setters

	void SetTheCrime(string crime) { this->crime = crime; }
	void SetTheCounts(int count) { this->count = count; }
	void SetTheMonth(string month) { this->cmonth = month; }
	void SetTheYear(int year) { this->cyear = year; }
	void SetTheDate(string _cdate) { cdate = _cdate; }

	// Example of not using the "this->" method
};

int main()
{

	crimeclass report[10];

	string temp;

	ifstream buffcrime;
	buffcrime.open("buffcrime2024.txt");

	getline(buffcrime, temp, '	');
	report[0].SetTheCrime(temp);

	// buffcrime >> count >> cmonth >> cyear >> cdate;

	cout << report[0].GetTheCrime() << endl;

	//<< count << cmonth  << cyear
	//     << cdate << endl;

	return 0;
}