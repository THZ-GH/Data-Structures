#include <iostream>
#include <vector>

using namespace std;

int findBiggest(vector<int> nums, int currentsize)
{

	if (currentsize == 1)
	{
		return nums.at(0);
	}
	else
	{
		int biggest = findBiggest(nums, currentsize - 1);
		// if (last number in current list is greater than smaller list)
		if (nums.at(currentsize - 1) > biggest)
		{
			return nums.at(currentsize - 1);
		}
		else
		{
			return biggest;
		}
	}
}

int main()
{
	vector<int> nums = {22, 11, 42, 5, 224, 762, -3};
	// int biggest = nums.at(0);

	// for (int i = 0; i < nums.size(); i++)
	// 	if (biggest < nums.at(i))
	// 	{
	// 		biggest = nums.at(i);
	// 	}
	int biggest = findBiggest(nums, nums.size());
	cout << biggest << endl;

	return 0;
}