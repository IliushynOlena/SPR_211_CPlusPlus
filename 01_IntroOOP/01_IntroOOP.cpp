#include <iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
/*
struct Player
{
    string name;
    short age;
    int games;
    int goals;
};

struct GoolCeaper
{
    string name;
    short age;
    int games;
    int goals;
};

void PrintPlayer(Player &pl)
{
    cout << "Name : " << pl.name << endl;
    cout << "Age : " << pl.age << endl;
    cout << "Games : " << pl.games << endl;
    cout << "Goals : " << pl.goals << endl;
}
void Init(Player& pl)
{
    cout << "Enter name :";
    cin >> pl.name;
    cout << "Enter age :";
    cin >> pl.age;
    pl.games = 0;
    pl.goals = 0;
}

void AddGame(Player& pl, int goals = 0)
{
    ++pl.games;
    pl.goals += goals;
}
*/

class Player
{
private:
    string name;
    short age;
    int games ;
    int goals;
    bool IsValidGoals(int goals)
    {
        return goals >= 0;
    }
public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void Initialize()
    {
        name = "no name";
        age = 0;
        games = 0;
        goals = 0;

    }
    void InitFromKeyBoard()
    {
        cout << "Enter name :";
        cin >> name;
        cout << "Enter age :";
        cin >> age;     
    }
  
    void AddGame( int goals = 0)
    {
        ++games;
        if(IsValidGoals(goals))
            this->goals += goals;
    }
};

//class Student
//{
// private:
//    //data members - змінні-члени класу.
//    string name;
//    int marks[3]; 
//public:
//  
//    //member function. - методи
//    double GetAverage()
//    {
//        double sum = 0;
//        for (int i = 0; i < 3; i++)
//        {
//            sum += marks[i];
//        }
//        return sum / 3;
//    }
//    void setName(string name)
//    {
//        this->name = name;
//    }
//    string getName()
//    {
//        return name;
//    }
//    void setMark(int mark, int index)
//    {
//        if (mark < 1 or mark > 12)
//            mark = 0;
//        marks[index] = mark;
//    }
//    int getMark(int index)
//    {
//        if (index >= 0 && index < 3)
//            return marks[index];
//    }
// 
//};
int Max(int a, int b)
{
    return a > b ? a : b;
}
float Max(float a, float b)
{
    return a > b ? a : b;
}
float Max(float a, float b, float c)
{
    return a > b ? a : b;
}

class Student
{
private:
    //data members - змінні-члени класу.
    string name;
    string surname;
    int age;
    int *marks;//pointer on mass int
    int markCount;
    float averageMark;
    void setAverage()
    {
        float sum = 0;
        for (int i = 0; i < markCount; i++)
        {
            sum += marks[i];
        }
        averageMark =(float) sum / markCount;
    }
public:
    //ctor + TAB
    Student()
    {
        cout << "Default constructor " << endl;
        name = "no name";
        age = 0;
        marks = nullptr;
        markCount = 0;
        averageMark = 0;
    }
    Student(string name)
    {
        cout << "Parametrized constructor "<<name << endl;
        this->name = name;
        age = 0;
        marks = nullptr;
        markCount = 0;
        averageMark = 0;
    }
    Student(string name, int age)
    {
        cout << "Parametrized constructor "<<name << endl;
        this->name = name;
        this->age = age;
        marks = nullptr;
        markCount = 0;
        averageMark = 0;
    }

    //member function. - методи
  
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setMark(int mark, int index)
    {
        if (mark < 1 or mark > 12)
            mark = 0;
        marks[index] = mark;
    }
    int getMark(int index)
    {
        if (index >= 0 && index < 3)
            return marks[index];
    }
    void Print()
    {
        gotoxy(10, 10); cout << "Name : " << name << endl;
        gotoxy(10, 11); cout << "Age : " << age << endl;
        gotoxy(10, 12); cout << "Marks  : ";
        for (int i = 0; i < markCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        gotoxy(10, 13); cout << "Average Mark : " << averageMark << endl;
    }

    void AddMark(int mark)
    {
        //int* marks = nullptr;
        //int markCount = 0;
        markCount++;
        int* temp = new int[markCount];
        for (int i = 0; i < markCount-1; i++)
        {
            temp[i] = marks[i];
        }
        temp[markCount - 1] = mark;
        if (marks != nullptr)
            delete[]marks;
        marks = temp;
        setAverage();
    }
  
    //~ + TAB
    ~Student()
    {
        cout << "Destructor  " <<name << endl;
        if (marks != nullptr)
            delete[]marks;
    }
};
int main()
{
   
    int a = 5;
    Student st;//object - Default constructor
    Student st2("Oksana");
    st2.AddMark(12);
    st2.AddMark(8);
    st2.AddMark(7);
    st2.AddMark(9);
    st2.Print();

    Student st3("Mukola", 22);
    st3.Print();


    /*
    st.setName("Ivanka");
    st.setMark(11, 0);
    st.setMark(8, 1);
    st.setMark(12, 2);


    cout << "Name : " << st.getName() << " " << st.getMark(0) << endl;
    cout << "Average : " << st.GetAverage() << endl;
    */  
    /*
    Player pl;

    pl.Initialize();
    pl.InitFromKeyBoard();
    pl.AddGame();
    pl.AddGame(2);
    pl.AddGame(5);
    pl.PrintPlayer();
    */
    /*
    Player pl;
    Init(pl);
    PrintPlayer(pl);

    AddGame(pl);
    AddGame(pl,2);
    AddGame(pl,1);
    PrintPlayer(pl);

    GoolCeaper g;
    PrintPlayer(g);
    */
}

