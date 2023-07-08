#pragma once
#include"Book.h"
class Library
{
private:
	string name;//User Library
	string address;//Soborna 16
	Book* books;//0x125HGG
	int countBooks;//5
public:
	Library();
	Library(string name, string address);
	
	void Show()const;
	void AddNewBook(Book book);
	Library(const Library& other);
	Library operator =(const Library& other)
	{
		this->name = other.name;
		this->address = other.address;
		this->countBooks = other.countBooks;
		if (books != nullptr)
			delete[]books;

		books = new Book[countBooks];
		for (int i = 0; i < countBooks; i++)
		{
			books[i] = other.books[i];
		}
		cout << "Operator =" << endl;
		return *this;
	}
	Library(Library&& other)//Move c-tor
	{
		this->name = other.name;
		this->address = other.address;
		this->countBooks = other.countBooks;
		this->books = other.books;
		other.books = nullptr;
		cout << "C-tor MOVE" << endl;
	
	}

	~Library()
	{
		if (books != nullptr)
			delete[]books;
	}

};

