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

int SizeofList(vector <shopper> list);
bool IsEmpty(vector <shopper> list);
void EnQue(vector <shopper> &list, shopper person);
void DeQue(vector <shopper> &list);
void Front(vector <shopper> list, shopper &temp);
void ShowList(vector <shopper> list);

// shopper Back(vector <shopper> list);

shopper NewShopper(ifstream &data);
int MakePizzas();
void SellPizzas(vector <shopper> &list, int &bakedpizzas);
  

int main()
{
    srand(time(NULL));
    
	vector <shopper> list;
	shopper me;
	char action;
	int bakedpizzas = MakePizzas();
    ifstream torture;
    torture.open("shoppers.txt");
	
	torture >> action;
	while (!torture.eof())
      {
		if (!IsEmpty(list))
		  SellPizzas(list, bakedpizzas);
		 
		 switch (toupper(action))
	     {
	     	case 'A': me = NewShopper(torture);
	     	          EnQue(list, me);
			          break;
	     	case 'L': bakedpizzas = bakedpizzas + MakePizzas();
	     	          cout << "Pizzas on hand " << bakedpizzas << endl;
			          break;
			case 'P': ShowList(list);
			          break;
			default: cout << "Bad Action" << endl; 	      
	     }

	     torture >> action;
      }
	
	torture.close();	
	return 0;
}

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
	  cout << "list is empty"  << endl;	  
	else  
	{
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
	int bakedpizzas = rand() % 10 + 1;
	return bakedpizzas;
}

void SellPizzas(vector <shopper> &list, int &bakedpizzas)
{
     shopper you;
     int pizzaswanted;
	 
	 Front(list, you);	
	 pizzaswanted = you.GetPizzas();
	 
	 while ((pizzaswanted <= bakedpizzas) && (!IsEmpty(list)))
	   { 
	       bakedpizzas = bakedpizzas -  pizzaswanted;
	       DeQue(list);
	       if (!IsEmpty(list))
	        {
               Front(list, you);	
	           pizzaswanted = you.GetPizzas();
			}
	   }
} 