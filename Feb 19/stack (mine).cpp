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

bool isEmpty(numnode *stackTop)
{
	if (stackTop == nullptr)
		return true;
	else
		return false;
}

void printStack(numnode *stackTop)
{
	numnode *temp = stackTop;
	if (!isEmpty(stackTop))
	{
		while (temp != nullptr)
		{
			cout << stackTop->getvalue() << endl;
			temp = temp->getnext();
			// stackTop = stackTop->getnext();
			// once you move a pointer off of a location, there's no going back.
		}
	}
	else
		cout << "Stack is empty." << endl;
}

void push(numnode *&stackTop, numnode *newnode)
{
	if (isEmpty(stackTop))
	{
		stackTop = newnode;
	}
	else
	{
		newnode->setnext(stackTop);
		stackTop = newnode;
	}
}

int main()
{
	numnode *mytop = nullptr; // declare the stack
	numnode *newvalues;

	newvalues = new (numnode);
	newvalues->setvalue(7);
	push(mytop, newvalues);

	newvalues = new (numnode);
	newvalues->setvalue(72);
	push(mytop, newvalues);
	newvalues = new (numnode);
	newvalues->setvalue(555);
	push(mytop, newvalues);
	newvalues = new (numnode);
	newvalues->setvalue(8);
	push(mytop, newvalues);
	printStack(mytop);

	return 0;
}