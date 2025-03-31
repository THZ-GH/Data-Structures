#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int> mystack)
{
	while (!mystack.empty())
	{
		cout << mystack.top() << endl;
		mystack.pop();
	}
}

void rewot(int n, stack<int> start, stack<int> end, stack<int> sideline)
{
	int temp;

	if (n == 1)
	{
		temp = start.top();
		start.pop();
		end.push(temp);
	}
	// if (n == 3 || n == 2)
	// {
	// 	temp = start.top();
	// 	start.pop();
	// 	end.push(temp);
	// 	temp = start.top();
	// 	sideline.push(temp);
	// }
}

int main()
{
	stack<int> a, b, c;

	// a.push(3);
	// a.push(2);
	a.push(1);

	cout << "Stack A:" << endl;
	showstack(a);
	cout << "Stack B:" << endl;
	showstack(b);
	cout << "Stack C:" << endl;
	showstack(c);

	cout << "-----------------" << endl;

	rewot(a.size(), a, b, c);

	cout << "Stack A:" << endl;
	showstack(a);
	cout << "Stack B:" << endl;
	showstack(b);
	cout << "Stack C:" << endl;
	showstack(c);

	return 0;
}