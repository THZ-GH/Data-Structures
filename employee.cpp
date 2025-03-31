#include <iostream>
#include <vector>

using namespace std;

class emp {
	public:
		int empNum;
		float pay;
};

int main(){

	vector<emp> elist;
	emp tempEmp;

	elist.resize(0);

	cout << "Size of vector: " << elist.size() << endl;

	cout << "What is the employee number?" << endl;
	cin >> tempEmp.empNum;
	cout << endl << "What is the employee pay?" << endl;
	cin >> tempEmp.pay;

	elist.push_back(tempEmp);

	cout << endl << elist.begin()->empNum << endl;

	tempEmp.pay = 99;
	tempEmp.empNum = 3456;
	elist.push_back(tempEmp);

	tempEmp.pay = 1234.56;
	tempEmp.empNum = 9999999 ;
	elist.push_back(tempEmp);

	cout << "Size of vector: " << elist.size() << endl;

	

	return 0;
}