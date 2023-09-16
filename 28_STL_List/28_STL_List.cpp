#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void ShowList(list<int>& l1, list<int>& l2)
{
	list<int>::iterator iter;
	cout << "list 1 : ";
	for (iter = l1.begin(); iter != l1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl << "list 2 : ";
	for (auto iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << endl;
}

struct Book
{
	string name;
	string author;
	int pages;
};

bool CompareBookByName(const Book& b1, const Book& b2)
{
	return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
	return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2)
{
	return b1.pages <  b2.pages;
}

int main()
{
	list<Book> library;
	library.assign({
		Book{"Night", "Gogol", 786},
		Book{"Maria", "Kotliarevsruy", 400},
		Book{"Harry Potter", "Royling", 800}
		});
	cout << "--------------------- Original list ----------------" << endl;
	for ( Book b : library)
	{
		cout << setw(15)<< left <<  b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}
	cout << "--------------------- Sorted list by name ----------------" << endl;
	library.sort(CompareBookByName);

	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}
	cout << "--------------------- Sorted list by author ----------------" << endl;
	library.sort(CompareBookByAuthor);
	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}
	cout << "--------------------- Sorted list by pages ----------------" << endl;
	library.sort(CompareBookByPages);

	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}

	
	/*

	list<int> list1, list2;// head = nullptr;tail = nullptr;
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;

	for (int i = 0; i < 6; i++)
	{
		list1.push_back(i); 
		list2.push_front(i);
	}
	ShowList(list1, list2);
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;

	list1.assign({ 10,20,30 });
	int& a = ++(list1.front());
	a++;
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;
	ShowList(list1, list2);

	list1.erase(list1.begin());
	ShowList(list1, list2);

	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	ShowList(list1, list2);
	list1.remove(2);//all number 2
	ShowList(list1, list2);
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;
	list1.insert(list1.end(), 15);
	list1.insert(list1.begin(), {55,66,77,88,99});
	list1.insert(list1.end(), 5 , 111);
	list1.insert(list1.end(), list2.begin(), list2.end());
	ShowList(list1, list2);
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;
	list1.resize(10);
	ShowList(list1, list2);
	cout << "Size 1 : " << list1.size() << endl;
	cout << "Size 2 : " << list2.size() << endl;
	cout << "-------------------------------------" << endl;
	list1.splice(list1.end(), list2, list2.begin());
	ShowList(list1, list2);


	list1.reverse();
	ShowList(list1, list2);

	list1.sort();
	list2.sort();
	ShowList(list1, list2);

	list1.merge(list2);
	ShowList(list1, list2);

	list1.unique();
	ShowList(list1, list2);

	list1.swap(list2);
	ShowList(list1, list2);

	*/

   
}

