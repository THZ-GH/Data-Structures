#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class shopper
{
private:
	string name;
	int pizzas;
	shopper *next;

public:
	shopper()
	{
		name = "";
		pizzas = -1;
		next = nullptr;
	}

	shopper(string _name, int _pizzas)
	{
		name = _name;
		pizzas = _pizzas;
		next = nullptr;
	}

	string GetName() { return name; }
	int GetPizzas() { return pizzas; }
	shopper *GetNext() { return this->next; }

	void SetName(string _name) { name = _name; }
	void SetPizzas(int _pizzas) { pizzas = _pizzas; }
	void SetNext(shopper *newnext) { next = newnext; }
};

class buyers
{

public:
	shopper *head = nullptr;
	shopper *tail = nullptr;

	buyers()
	{
	}

	// Destructor
	~buyers()
	{
		while (!IsEmpty())
		{
			DeQue();
		}
	}

	int SizeofList()
	{
		if (IsEmpty())
			return 0;

		int size = 0;
		shopper *tempShopper = head;

		while (tempShopper != nullptr)
		{
			size++;
			tempShopper = tempShopper->GetNext();
		}

		return size;
	}

	bool IsEmpty()
	{
		return head == nullptr;
	}

	void EnQue(shopper *person)
	{
		if (IsEmpty())
		{
			head = person;
			tail = person;
		}
		else
		{
			tail->SetNext(person);
			tail = person;
		}
	}
	// check for memory leaks
	void DeQue()
	{
		if (IsEmpty())
			cout << "Error: List is empty." << endl;
		else
		{
			shopper *temphead = head;
			head = head->GetNext();
			delete temphead;

			// if queue is empty now that head has been deleted
			if (head == nullptr)
				tail = nullptr;
		}
	}

	void Front(shopper &temp)
	{
		if (IsEmpty())
			cout << "Front: list is empty" << endl;
		else
		{
			temp.SetName(head->GetName());
			temp.SetPizzas(head->GetPizzas());
		}
	}

	void ShowList()
	{
		if (IsEmpty())
			cout << "ShowList: List is empty" << endl;
		else
		{
			cout << endl
				 << endl;
			shopper *temphead = head;
			while (temphead != nullptr)
			{
				cout << temphead->GetName() << "\t" << temphead->GetPizzas() << endl;
				temphead = temphead->GetNext();
			}
		}
	}
};

void SellPizzas(buyers &list, int &bakedpizzas);
int MakePizzas();
shopper NewShopper(ifstream &data);

int main()
{
	srand(time(NULL));

	buyers list;
	shopper *newShopper = nullptr;
	shopper person;
	char action;
	int bakedpizzas = MakePizzas();
	ifstream shopperStream;
	shopperStream.open("shoppers.txt");
	string name;
	int pizzas;

	shopperStream >> action;
	while (!shopperStream.eof())
	{
		if (!list.IsEmpty())
			SellPizzas(list, bakedpizzas);

		switch (toupper(action))
		{
		case 'A':
			person = NewShopper(shopperStream);
			cout << "New shopper: " << person.GetName() << endl;
			newShopper = new shopper(person.GetName(), person.GetPizzas());
			list.EnQue(newShopper);
			break;
		case 'L':
			bakedpizzas = bakedpizzas + MakePizzas();
			cout << "Pizzas on hand " << bakedpizzas << endl;
			break;
		case 'P':
			list.ShowList();
			break;
		default:
			cout << "Bad Action" << endl;
		}

		shopperStream >> action;
	}

	shopperStream.close();
	return 0;
}

shopper NewShopper(ifstream &data)
{
	shopper person;
	string name;
	int pizzas;

	data >> name >> pizzas;
	person = shopper(name, pizzas);
	return person;
}

int MakePizzas()
{
	int bakedpizzas = rand() % 100 + 1;
	return bakedpizzas;
}

void SellPizzas(buyers &list, int &bakedpizzas)
{
	shopper you;
	int pizzaswanted;

	list.Front(you);
	pizzaswanted = you.GetPizzas();

	while ((pizzaswanted <= bakedpizzas) && (!list.IsEmpty()))
	{
		bakedpizzas = bakedpizzas - pizzaswanted;
		list.DeQue();
		if (!list.IsEmpty())
		{
			list.Front(you);
			pizzaswanted = you.GetPizzas();
		}
	}
}
