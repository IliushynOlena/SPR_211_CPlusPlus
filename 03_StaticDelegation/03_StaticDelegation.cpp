#include <iostream>

using namespace std;

inline void Hello()
{
    cout << "Hello World!\n";
}

class Human
{
    string name;
    int age;
    int weight;
    static int countHuman;
public:
    static int getCount()
    {
        return countHuman;
    }
    Human() :name(""), age(0), weight(0) { cout << "Deafult" << endl; countHuman++; }
    //Human():name{""},age{0},weight{0}
    //{
     /*   name = "";
        age = 0;
        weight = 0;*/
    //}
    Human(string name):  Human() 
    {
        this->name = name;
        //age = 0;
        //weight = 0;
    }
    Human(string name, int age):Human(name)
    {
        //this->name = name;
        this->age =age;
        //weight = 0;
    }
    Human(string name, int age, int weight):Human(name, age)
    {
        //this->name = name;
        //this->age = age;
        this->weight = weight;
    }
   
    void Print()const
    {
        cout<< this->age;
        //this->age = 10;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Weight : " << weight << endl;
        cout << "countHuman : " << countHuman << endl;
    }
    ~Human()
    {
     
        countHuman--;
    }
};

int Human::countHuman = 0;
int main()
{
    Human h; //h.countHuman = 10;
    h.Print();
    Human h2("Oleg"); //h2.countHuman = 20;
    h2.Print();
    Human h3("Ivanka", 12); //h3.countHuman = 33;
    h3.Print();
    if (true)
   {
        Human h4("Ivan", 25, 100);// h4.countHuman = 40;
        h4.Print();
   }
    cout << "Count of Human : " << h2.getCount() << endl;
    cout << "Count of Human : " << h.getCount() << endl;
    cout << "Count of Human : " << h3.getCount() << endl;
    cout << "Count of Human : " << Human::getCount() << endl;
  



    //Hello();



}

