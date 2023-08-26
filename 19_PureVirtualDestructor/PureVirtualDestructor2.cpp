#include <iostream>
using namespace std;

class Person//abstract class
{
    string name;
public:
    Person() :name("no name"){}
    Person(string name) :name(name) {}
    virtual void Print()const
    {
        cout << "Student name : " << name << endl;
    }
    virtual ~Person() = 0 {}//pure virtual destructor
};
class Aspirant : public Person
{
    string* subjects;
    int countSubj;
public:
    Aspirant(string name, initializer_list<string> subjects) :
        Person(name)
    {
        this->countSubj = subjects.size();
        this->subjects = new string[countSubj];
        int i = 0;
        for (string sub : subjects)
        {
            this->subjects[i] = sub;
            i++;
        }

    }
    void Print()const override
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSubj; i++)
        {
            cout << subjects[i] << " ";
        }cout << endl;
    }
    ~Aspirant() override
    {
        cout << "Destructor Aspirant " << endl;
        if (subjects != nullptr)
            delete[]subjects;
    }
};

int main()
{
    srand(time(0));
    Person* group[2]
    {
        //new Person("Oleg"),
        new  Aspirant("Kateruna",{ "UI/UX", "Main page in Rozetka","Trends in Design"}),
        new  Aspirant("Ivanka", { "UI/UX", "Trends in Design"})
    };
    for (int i = 0; i < 2; i++)
    {
        cout << "****************************************" << endl;
        group[i]->Print();
        delete group[i];
        cout << "****************************************" << endl;
    }

}

