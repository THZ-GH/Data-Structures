#include <iostream>
#include <vector>

using namespace std;

long long fibby(long long position, long long saved[])
{
	if (saved[position] != -1)
	{
		return saved[position];
	}

	if (position == 0 || position == 1)
	{
		saved[position] = position;
		return position;
	}
	else
	{
		long long temp = fibby(position - 1, saved) + fibby(position - 2, saved);
		saved[position] = temp;
		return temp;
	}
}

int main()
{
	long long position;
	long long saved[1000];

	for (int i = 0; i <= 101; i++)
		saved[i] = -1;

	cout << "Enter a position in the Fibonacci Sequence to find." << endl;

	cin >> position;

	cout << "The number is: " << fibby(position, saved) << "." << endl;

	return 0;
}