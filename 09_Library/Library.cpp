#include "Library.h"
Library::Library()
{
	name = "no name";
	address = "no address";
	books = nullptr;
	countBooks = 0;
}

Library::Library(string name, string address)
{
	this->name = name;
	this->address = address;
	books = nullptr;
	countBooks = 0;
}
void Library::Show() const
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	for (int i = 0; i < countBooks; i++)
	{
		books[i].ShowInfo();
		cout << endl;
	}
}

void Library::AddNewBook(Book book)
{
	Book* newBooks = new Book[countBooks + 1];
	for (int i = 0; i < countBooks; i++)
	{
		newBooks[i] = books[i];
	}
	newBooks[countBooks] = book;
	if (books != nullptr)
		delete[]books;
	books = newBooks;
	countBooks++;
}

Library::Library(const Library& other)
{
	this->name = other.name;
	this->address = other.address;
	this->countBooks = other.countBooks;
	books = new Book[countBooks];
	for (int i = 0; i < countBooks; i++)
	{
		books[i] = other.books[i];
	}
	cout << "Copy c-tor" << endl;
}
