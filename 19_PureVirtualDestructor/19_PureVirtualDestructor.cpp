//#include <iostream>
//using namespace std;
//
//class Student
//{
//    string name;
//    string spetialization;
//    int* marks;
//    int markCount;
//public:
//    Student() :name("no name"), spetialization("no spetialization"),
//        marks(nullptr), markCount(0) {}
//    Student(string name, string spetialization) :name(name), spetialization(spetialization)
//    {
//        markCount = rand() % 10 + 1;
//        marks = new int[markCount];
//        for (int i = 0; i < markCount; i++)
//        {
//            marks[i] = rand() % 5 + 8;    //8-12;
//        }
//    }
//    virtual void Print()const
//    {
//        cout << "Student name : " << name << endl;
//        cout << "Spetialization : " << spetialization << endl;
//        cout << "Marks : " ;
//        for (int i = 0; i < markCount; i++)
//        {
//            cout << marks[i] << " ";
//        }
//        cout << "\n________________________________" << endl;
//    } 
//    virtual ~Student()
//    {
//        cout << "Destructor Student " << endl;
//        if (marks != nullptr)
//            delete[]marks;
//    }
//};
//class Aspirant : public Student
//{
//    string *subjects;
//    int countSubj;
//public:
//    Aspirant(string name, string spetialization, initializer_list<string> subjects) :
//        Student(name, spetialization) 
//    {
//        this->countSubj = subjects.size();
//        this->subjects = new string[countSubj];
//        int i = 0;
//        for (string sub : subjects)
//        {
//            this->subjects[i] = sub;
//            i++;
//        }
//    
//    }
//     void Print()const override
//    {
//        Student::Print();
//        cout << "Subject : " ;
//        for (int i = 0; i < countSubj; i++)
//        {
//            cout << subjects[i] << " ";
//        }cout << endl;
//    }
//    ~Aspirant()
//    {
//        cout << "Destructor Aspirant " << endl;
//        if (subjects != nullptr)
//            delete[]subjects;
//    }
//};
//
//int main()
//{
//    srand(time(0));
//    Student st("Oleg", "Programmer");
//    st.Print();
//
//    Aspirant asp("Kateruna", "Design", { "UI/UX", "Main page in Rozetka","Trends in Design"});
//    asp.Print();
//
//    Student* group[3]
//    {
//        new Student("Oleg", "Programmer"),
//        new  Aspirant("Kateruna", "Design", { "UI/UX", "Main page in Rozetka","Trends in Design"}),
//        new  Aspirant("Ivanka", "Design", { "UI/UX", "Trends in Design"})
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        cout << "****************************************" << endl;
//        group[i]->Print(); 
//        delete group[i];
//        cout << "****************************************" << endl;
//    }
//    
//}
//
