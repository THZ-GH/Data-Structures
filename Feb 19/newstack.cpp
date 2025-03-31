#include <iostream>
#include <string>
using namespace std;

class numnode
{
private:
	int value;
	numnode *next;

public:
	numnode()
	{
		value = 0;
		next = nullptr;
	}

	int getvalue() { return value; }
	void setvalue(int newvalue) { value = newvalue; }
	numnode *getnext() { return next; }
	void setnext(numnode *newnext) { next = newnext; }
};

bool isempty(numnode *stacktop)
{
	if (stacktop == nullptr)
	{
		return true;
	}
	return false;
}

void printstack(numnode *stacktop)
{
	numnode *temp = stacktop;
	if (!isempty(stacktop))
		while (temp != nullptr)
		{
			cout << temp->getvalue() << endl;
			temp = temp->getnext();
		}
	else
	{
		cout << "Empty Stack" << endl;
	}
}

void push(numnode *&stacktop, numnode *newnode)
{
	if (isempty(stacktop)) // empty stack
	{
		stacktop = newnode;
	}
	else
	{
		newnode->setnext(stacktop);
		stacktop = newnode;
	}
}

void pop(numnode *&stacktop)
{
	numnode *garbnode;
	if (isempty(stacktop))
	{
		cout << "Stack is empty." << endl;
	}
	else
		garbnode = stacktop;
	stacktop = stacktop->getnext();
	delete (garbnode); // not deleting pointer, deleting what it's pointing to
}

int stacksize(numnode *stacktop)
{
	numnode *temp = stacktop;
	int count = 0;
	if (!isempty(stacktop))
	{
		while (temp != nullptr)
		{
			count++;
			temp = temp->getnext();
		}
	}

	// cout << endl << endl << count << endl << endl;
	return count;
}

numnode *GetTop(numnode *stacktop)
{
	numnode *topgunnode;
	if (isempty(stacktop))
	{
		cout << "stack empty" << endl;
	}
	else
	{
		topgunnode = stacktop;
		return topgunnode;
	}
}

int main()
{
	numnode *mytop = nullptr; // declare a stack
	numnode *newvalues;

	// printstack(mytop);

	// pop(mytop);
	printstack(mytop);

	newvalues = new (numnode);
	newvalues->setvalue(7);

	cout << newvalues << endl;

	push(mytop, newvalues);

	newvalues = new (numnode);
	newvalues->setvalue(11);

	cout << &newvalues << endl;

	push(mytop, newvalues);

	newvalues = new (numnode);
	newvalues->setvalue(27);

	// cout << &newvalues << endl;

	// cout << &newvalues << endl;

	push(mytop, newvalues);

	pop(mytop);

	cout << stacksize(mytop);

	printstack(mytop);

	return 0;
}