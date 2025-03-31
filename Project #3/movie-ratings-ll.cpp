#include <iostream>
#include <fstream>
using namespace std;

class movieclass
{

	// These are the class members // fields  // attributes
private:
	string title;
	int duration, rating;
	movieclass *next;

	// Class Constructor

public:
	movieclass()
	{
		title = "";
		duration = -1;
		rating = -1;
		next = nullptr;
	}

	movieclass(string mt, int du, int rt)
	{
		title = mt;
		duration = du;
		rating = rt;
		next = nullptr;
	}

	// Getters

	string GetTitle() { return this->title; }
	int GetDuration() { return this->duration; }
	movieclass *GetNext() { return this->next; }

	// Setters

	void SetTitle(string title) { this->title = title; }
	void SetDuration(int duration) { this->duration = duration; }
	void SetRating(int rating) { this->rating = rating; }
	void SetNext(movieclass *next) { this->next = next; }
};

class mydll
{
public:
	movieclass *GetMovie(ifstream &streamList);
	movieclass *head = nullptr;

	bool IsEmpty() { return head == nullptr; }

	void print()
	{
		if (IsEmpty())
			cout << "List is Empty" << endl;
		else
		{
			movieclass *temphead = head;
			while (temphead != nullptr)
			{
				cout << "Movie: " << temphead->GetTitle() << endl;
				temphead = temphead->GetNext();
			}
		}
	}

	void AddAfter(movieclass *newmovie)
	{
		movieclass *temphead = head->GetNext()->GetNext()->GetNext()->GetNext();
		newmovie->SetNext(temphead->GetNext());
		temphead->SetNext(newmovie);
	}

	void AddToFront(movieclass *newmovie)
	{
		newmovie->SetNext(head);
		head = newmovie;
	}

	void AddtoEnd(movieclass *newmovie)
	{
		if (IsEmpty())
			head = newmovie;
		else
		{
			movieclass *temphead = head;
			while (temphead->GetNext() != nullptr)
				temphead = temphead->GetNext();
			temphead->SetNext(newmovie);
		}
	}

	bool FindMovie(string KeyMovie, movieclass *&FoundMovie)
	{
		if (IsEmpty())
			return false;
		else
		{
			FoundMovie = head;
			while (KeyMovie != FoundMovie->GetTitle())
			{
				FoundMovie = FoundMovie->GetNext();
				if (FoundMovie == nullptr)
					return false;
			}
			return true;
		}
	}

	void GetAction(ifstream &streamList)
	{
		char input;
		streamList >> input;
		streamList.ignore();
		// working atm

		switch (input)
		{
		case 'A': // Add movie
			movieclass *newMovie = new movieclass();
			newmovie = GetMovie(streamList);
			AddtoEnd(newmovie);
			break;
		default:
			break;
		}
	}
};

movieclass *GetMovie(ifstream &streamList)
{
	string title;
	int duration, rating;
	movieclass *temp = new movieclass();

	getline(streamList, title);

	cout << "title1 " << title << endl;

	streamList >> title >> duration >> rating;
	cout << "title2 " << title << endl;
	// streamList.ignore();
	temp->SetTitle(title);
	temp->SetDuration(duration);
	temp->SetRating(rating);

	return temp;
}

int main()
{

	mydll movielist;

	movieclass *temp;

	ifstream streamList;
	streamList.open("movies.txt");

	movielist.GetAction(streamList);

	while (!streamList.eof())
	{
		movielist.AddtoEnd(temp);
		temp = GetMovie(streamList);
	}

	// TESTING
	// ALL OF BELOW IS MANUAL, USE CASE INSTEAD, DELETE EVENTUALLY
	if (movielist.IsEmpty())
		cout << "We are doing good so far" << endl;
	else
		cout << "not empty" << endl;

	cout << "Head is looking at " << movielist.head << endl;

	movielist.print();

	// temp = GetMovie(streamList);

	while (!streamList.eof())
	{
		movielist.AddtoEnd(temp);
		temp = GetMovie(streamList);
	}

	//	cout << "Temp is looking at "  << temp  << endl;
	//	cout << "Head is looking at "  << movielist.head << endl;

	movielist.print();

	if (movielist.FindMovie("Burglary", temp))
		//	   cout << "You have been found"  << temp << endl;
		;

	else
		cout << "You are missing" << temp << endl;

	cout << "*******************************************" << endl
		 << endl;

	movielist.print();

	/*
		temp = new movieclass("Sucker Stealer", 8, "March", 2025, "03/12/2025");
		cout << "*******************************************" << endl << endl;
		movielist.AddToFront(temp);

		movielist.print();
	*/

	return 0;
}

// WAS AT END OF MYDLL
// using previous pointer is allowed
// 	void DeleteCrime(crimeclass * FoundCrime)
//    {
//    	    // Method 1
//    	/*
//    	    crimeclass * Helper1, * Helper2;

//    	    Helper1 = FoundCrime->GetPrev();
//    	    Helper2 = FoundCrime->GetNext();

//    	    Helper1->SetNext(Helper2);
//    	    Helper2->SetPrev(Helper1);
//    	*/
//    	    // Method 2

//    	    FoundCrime->GetPrev()->SetNext(FoundCrime->GetNext());
//    	    FoundCrime->GetNext()->SetPrev(FoundCrime->GetPrev());

//    	   delete(FoundCrime);
//    }