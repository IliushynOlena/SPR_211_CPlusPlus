#include"Library.h"

Library TestLibrary(Library &lib)//copy ctor
{
    //some code
    Library temp;//ctor default
    temp = lib;//operator =
    //some code
    return temp;//destructor
}

int main()
{
    Book book1("C++ for Begginers", "Stiven Prata", 2000,  1500,Science);
  /*  Book book2("Harry Potter", "J.K.Rowling", 1997, 800, Fantasy);
    Book book3("Sherlock Holmes", "Arthur Conan Doyle", 1887,  2000, Genre::Detective);
    Book book4("Java for kids", "Morgan Nick", 2015, 408, Science);
    Book book5("Mowgli", "Pantera", 1893,500, Genre::Fantasy);
    Book book6("Financier", "Dreiser Theodore", 1911,  377, Genre::Science);*/

    //book1.ShowInfo();

    Library lib("Soborna 16","Users Library");
    lib.AddNewBook(book1);
    lib.AddNewBook(Book("Harry Potter", "J.K.Rowling", 1997, 800, Fantasy));
    lib.AddNewBook(Book("Sherlock Holmes", "Arthur Conan Doyle", 1887, 2000, Genre::Detective));
    lib.AddNewBook(Book("Java for kids", "Morgan Nick", 2015, 408, Science));
    lib.AddNewBook(Book("Mowgli", "Pantera", 1893, 500, Genre::Fantasy));
    lib.AddNewBook(Book("Financier", "Dreiser Theodore", 1911, 377, Genre::Science));
    //lib.Show();

    //Library lib2(lib);//copy c-tor//6
    //lib2.AddNewBook(Book("Harry Potter New Version", "J.K.Rowling", 1997, 800, Fantasy));//7
    //lib2.Show();
    //cout << "----------------------------------" << endl;
    //lib2 = lib;//7....6
    //lib2.Show();
    //int a = 5, b = 7, c = 10;
    //a = b = c;//10

    //Library lib3;
    //lib3 = lib2 = lib;

    cout << "----------------------------------" << endl;
    Library l = TestLibrary(lib);
 
    l.Show();

    
}

