#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class shopper{
	private:
		string name;
		int pizzas;
		
	public:
	
	shopper(){
		name = "";
		pizzas = -1;
	}	
	
	shopper(string _name, int _pizzas){
		name = _name;
		pizzas = _pizzas;
	}
	
    string GetName() { return name; }
    int GetPizzas()  { return pizzas; }
	void SetName(string _name)   { name = _name; }
	void SetPizzas(int _pizzas)  { pizzas = _pizzas; }
};

int SizeofList(vector <shopper> list)
{
	return list.size();	
}

bool IsEmpty(vector <shopper> list)
{
	return list.empty();
}

void EnQue(vector <shopper> &list, shopper person)
{
    list.push_back(person);
}


void DeQue(vector <shopper> &list)
{
	if (IsEmpty(list))
	  cout << "list is empty"  << endl;
	else  
	  list.erase(list.begin());
}

void Front(vector <shopper> list, shopper &temp)
{
	if (IsEmpty(list))
	  cout << "list is empty"  << endl;
	  
	else  
	{
	  temp.SetName(list.at(0).GetName());
	  temp.SetPizzas(list.at(0).GetPizzas());
    }
}

// shopper Back(vector <shopper> list)

void ShowList(vector <shopper> list)
{

	if (IsEmpty(list))
		cout << "List is empty" << endl;
	else {
	cout << endl  << endl;
	for (auto k : list)
	   cout << k.GetName() << "\t"  << k.GetPizzas() << endl;
	}
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
	int bakedpizzas = rand() % 9 + 1;
	return bakedpizzas;
}

void SellPizzas(vector<shopper>& list, int &bakedpizzas){

	shopper you;
	int pizzasWanted;
	
	Front(list, you);

	pizzasWanted = you.GetPizzas();

	while ((pizzasWanted <= bakedpizzas) && (!IsEmpty(list))){
	// sell pizzas
		bakedpizzas -= pizzasWanted;
		DeQue(list);
		if (!IsEmpty(list)){
			Front(list, you);
			pizzasWanted = you.GetPizzas();
		}
	}

}


int main()
{
    srand(time(NULL));
	vector <shopper> list;
	shopper me;
	char action;
	int bakedpizzas = rand() % 9 + 1;
	ifstream torture;
	torture.open("./shoppers.txt");

	torture >> action;

	while (!torture.eof()){

		if (!IsEmpty(list))
			SellPizzas(list, bakedpizzas);

		switch (toupper(action)){
			case 'A': me = NewShopper(torture);
					EnQue(list, me);
					break;
			case 'L': bakedpizzas = bakedpizzas + MakePizzas();
				cout << "Pizzas available: " << bakedpizzas << endl;
				break;
			case 'P': ShowList(list);
					break;
			default: cout << "Invalid input." << endl;
		}

		torture >> action;
	}




	// DeQue(list);
	// cout << "Number of Pizzas " << bakedpizzas << endl;
	
	// me = shopper("Don", 20);
	// EnQue(list, me);
    // ShowList(list);
    
	// me = shopper("Laura", 1);
	// EnQue(list, me);
	// me = shopper("Debbie", 2);
	// EnQue(list, me);
	// ShowList(list);
	
	// DeQue(list);
	// ShowList(list);
	
	
	
	return 0;
}