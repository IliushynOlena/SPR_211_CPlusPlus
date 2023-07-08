#pragma once
#include <iostream>
#include<string>
using namespace std;

//const int None = 0;
//const int Comedy = 1;
//const int History = 2;
//const int Drama = 3;
enum Genre
{
	None, Comedy, History, Drama, Horror, Science, Fantasy, Novel, Programming, Detective
};
class Book
{
private:
	string title;
	string author;
	int year;
	int pages;
	Genre genre;
public:
	Book();
	Book(string t, string a, int y, int p, Genre g) :title(t), year(y), author(a), pages(p), genre(g) {}
	void ShowInfo()const;
};
