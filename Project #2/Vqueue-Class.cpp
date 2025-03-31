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

class buyers{

public:
	vector <shopper> list;
	

	
   buyers() {
   	list.resize(0);
   }

int SizeofList()
{
	return list.size();	
}

bool IsEmpty()
{
	return list.empty();
}

void EnQue(shopper person)
{
    list.push_back(person);
}


void DeQue()
{
	if (IsEmpty())
	  cout << "list is empty"  << endl;
	else  
	  list.erase(list.begin());
}

void Front(shopper &temp)
{
	if (IsEmpty())
	  cout << "list is empty"  << endl;	  
	else  
	{
	  temp.SetName(list.at(0).GetName());
	  temp.SetPizzas(list.at(0).GetPizzas());	
    }
}

// shopper Back(vector <shopper> list)

void ShowList()
{
	if (IsEmpty())
	  cout << "list is empty"  << endl;	  
	else  
	{
	  cout << endl  << endl;
	  for (auto k : list)
	     cout << k.GetName() << "\t"  << k.GetPizzas() << endl;		
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
	shopper me;
	char action;
	int bakedpizzas = MakePizzas();
    ifstream torture;
    torture.open("shoppers.txt");
	
	torture >> action;
	while (!torture.eof())
      {
		if (!list.IsEmpty())
		  SellPizzas(list, bakedpizzas);
		 
		 switch (toupper(action))
	     {
	     	case 'A': me = NewShopper(torture);
	     	          list.EnQue(me);
			          break;
	     	case 'L': bakedpizzas = bakedpizzas + MakePizzas();
	     	          cout << "Pizzas on hand " << bakedpizzas << endl;
			          break;
			case 'P': list.ShowList();
			          break;
			default: cout << "Bad Action" << endl; 	      
	     }

	     torture >> action;
      }
	
	torture.close();	
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
	int bakedpizzas = rand() % 10 + 1;
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
	       bakedpizzas = bakedpizzas -  pizzaswanted;
	       list.DeQue();
	       if (!list.IsEmpty())
	        {
               list.Front(you);	
	           pizzaswanted = you.GetPizzas();
			}
	   }
}   
