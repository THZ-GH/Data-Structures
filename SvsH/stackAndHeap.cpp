#include <iostream>
#include <vector>

using namespace std;

void TestFunction(int &a, float &b){
	cout << "Contents of a: " << a << endl;
	cout << "Address of a: " << &a << endl;
	cout << "Contents of b: " << b << endl;
	cout << "Address of b: " << &b << endl;
}

int main(){

	int i = 1;
	float value = 1.1;

	int *p;
	int *h;

	h = new (int);

	

	p = &i;
	*p = 2;
	*h = i;
	cout << "I: " << i << endl;
	cout << &i << endl;

	cout << "P: " << p << endl;
	cout << &p << endl;

	cout << "H: " << h << endl;
	cout << &h << endl;
	cout << *h << endl;

	// cout << "Value: " << value << endl;
	// cout << &value << endl;

	// TestFunction(i, value);

	return 0;
}