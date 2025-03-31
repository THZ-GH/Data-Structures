#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector <int> nums = { 3, 4, 5, 6, 7, 8, 9 };
	int i;

	for (i = 0; i < nums.size(); i++)
		{
			cout << nums.at(i) << endl;
		}

	for (auto k : nums){
		cout << k << endl;
		// cout << k.rating << endl;
		// ex to use in project maybe
	}

	for (auto m = nums.begin(); m != nums.end(); m++){
		cout << *m << endl;
		// asterisk de-references the pointer
		// increment is necessary here
		// rbegin and rend for reverse
	}

	nums.push_back(247);

	for (i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << endl;
	}

	// nums = { 3, 4, 5, 6, 7, 8, 9, 247};
	nums.erase(nums.end()-4);
	// you can add or subtract the position of the end or begin
	// use for project
	// when searching for something, you need to know where to remove it
	

	return 0;
}