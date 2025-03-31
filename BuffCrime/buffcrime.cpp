#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class crimeclass {

	// Members
	private:
		string crime, cmonth, cdate;
		int count, cyear;

	// Constructor
	public:
		crimeclass() {
			crime = "";
			count = -1;
			cmonth = "";
			cyear = -1;
			cdate = "";
	}

	crimeclass(string cn, int co, string cm, int cy, string cd) {
			crime = cn;
			count = co;
			cmonth = cm;
			cyear = cy;
			cdate = cd;
		}

	// Getters
	string getTheCrime() { return this->crime; }
	int getTheCount() { return this->count; }
	string getTheMonth() { return this->cmonth; }
	int getTheYear() { return this->cyear; }
	string getTheDate() { return this->cdate; }

	// Setters
	// 'this' points to class member
	// may use underscore for member under it, alternative to using 'this'
	void setTheCrime(string crime) {  this->crime = crime; }
	void setTheCount(int count) {  this->count = count; }
	void setTheMonth(string cmonth) {  this->cmonth = cmonth; }
	void setTheYear(int year) { this->cyear = cyear; }
	void setTheDate(string _cdate) { cdate = _cdate; }

};

int main() {

	crimeclass report[10];

	string temp;

	ifstream buffcrime;
	buffcrime.open("BuffCrime2024.txt");
	
	getline(buffcrime, temp, '	');
	report[0].setTheCrime(temp);
	// cout << crime << endl;
	// buffcrime >> count >> cmonth >> cyear >> cdate;
	// cout << crime << count << cmonth << cyear << cdate << endl;

	cout << report[0].getTheCrime() << endl;


	return 0;
}