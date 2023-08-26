#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;

};
class Person
{
private:
	string name;//Viktor
	int age;//15
	int* marks;//00xkiu89
	int marksCount;//4

public:
	// Конструктор - метод, який викликається автоматично при створенні об'єкта класу.
	// Використовується для ініціалізації полів

	// Конструктора за замовчуванням (default ctor) - без параметрів
	Person()
	{
		name = "";
		age = 0;
		marks = nullptr;
		marksCount = 0;
	}

	// Параметризований конструктор - який приймає якісь параметри
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	// Деструктор - метод, який викликається автоматично при видаленні об'єкта класу
	// Використовується для очищення пам'яті, звільнення ресурсів і тд.
	Person(const Person& other)
	{
		this->name = other.name;
		this->age = other.age;
		this->marks = new int[other.marksCount];
		for (int i = 0; i < other.marksCount; i++)
		{
			marks[i] = other.marks[i];
		}
		this->marksCount = other.marksCount;//4
	}
	~Person()
	{
		if (marks != nullptr)
			delete[] marks;
		cout << "Destructor [" << name << "]...\n";
	}


	void Print() const // константний метод, який не змінює властивості класа
	{
		cout << "-------- STUDENT [" << name << "] ---------\n";
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (size_t i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void AddMark(int value);
};

void Person::AddMark(int value)
{
	int* new_arr = new int[marksCount + 1];
	for (size_t i = 0; i < marksCount; ++i)
	{
		new_arr[i] = marks[i];
	}
	new_arr[marksCount] = value;
	if (marks != nullptr)
		delete[] marks;
	marks = new_arr;

	++marksCount;
}

int main()
{

	Person testSt;					// виклик конструктора за замовчуванням
	Person st("Viktor", 15);	// виклик параметризованого конструктора

	st.AddMark(8);
	st.AddMark(7);
	st.AddMark(11);
	st.AddMark(10);


	st.Print();
	cout << "-------------------------" << endl;
	//Student copy = Student(st);
	Person copy(st);
	copy.Print();
    /*
    int a;//4b
    int b = 10;
    int c = 3.33;
    //cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    int arr[2];
    arr[0] += 2;
    cout << arr[0] << endl;

    int number = 0.33;//initialization with copy  
    cout << number << endl;
    int value(45.5);
    cout << value << endl;
    int size{ 33 };
    cout << size << endl;
    double pi{ 3.14 };
    cout << pi << endl;

    int answer{ 42 };
    const float goodTemp{ 36.6 };
    int grades[4]{ 11,11,12,8 };
    int mass[2][2] { {1,2},{3,4} };

    int* ptr{ nullptr };
    int& link{ answer };
    Point point{ 10,3 };
    */


}

