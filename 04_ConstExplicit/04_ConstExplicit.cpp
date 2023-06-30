#include <iostream>
using namespace std;

class Date
{
	const int baseYear;
	int& currentYear;
	int day;
	int month;
	int year;
public:
	Date(int baseYear,int currentYear) :baseYear(baseYear), currentYear(currentYear), day(0), month(0), year(0) {}
	
	void setDate(int day)
	{
		this->day = day;
	}

	/*void setDate(Date* const this, int day)
	{
		this->day = day;
	}*/
	/*
	Date(const Date& other)
	{

	}*/
	int getDate()
	{
		return day;
	}
	int getDate()const
	{
		return day;
	}

	void Show()
	{
		cout << "Base Year : " << baseYear << endl;
		cout << "currentYear : " << currentYear << endl;
		cout << "day : " << day << endl;
		cout << "month : " << month << endl;
		cout << "year : " << year << endl;
	}
};

class Account
{
private:
	double sum;
	const double rate;
public:
	Account(double sum, double rate) :sum(sum), rate(rate) {}
	
	double getRate()const
	{
		return rate;
	}
	double getIncome()
	{
		return sum * rate / 100;
	}
	double getIncome()const
	{
		return sum * rate / 100;
	}
	double getSum()
	{
		return sum;
	}
	double getSum()const
	{
		return sum;
	}
	double setSum()
	{
		sum += getIncome();
		return sum;
	}
	
};
void DoSomething(long number)
{

}
float DoSomething()
{
	return 1.03;//double - float implicit
}
class Array
{
	int size;
	int* arr;
public:
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
	}
	explicit Array(const Array&other)
	{
		this->size = other.size;
		this->arr = new int[other.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	~Array()
	{
		delete[]arr;
	}
	int getSize()const
	{
		return size;
	}
	int getValue(int index)const
	{
		return arr[index];
	}
	void setValue(int index, int value)
	{
		this->arr[index] = value;
	}
	void Display(int index)const
	{
		cout << arr[index] << " ";
	}
};

void Print(const Array& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.Display(i);
	}
	cout << endl;
}

int main()
{
	int size = 4;
	Array arr(size);
	for (int i = 0; i < size; i++)
	{
		arr.setValue(i, size - i - 1);
	}
	Print(arr);//explicit - Array
	cout << "!!!!!!!" << endl;
	//Errors
	//Print(10);//int = Array = implicit
	Array arr3 = 15;

	Print(Array(10));
	Array arr2(arr);//ctor copy
	Print(arr2);
	//Array arr4 = arr;
	//Print(arr4);

	//double a(10);//int to double - implicit - 10.00000000000000
	//a = 5;//int to double - implicit - 10.00000000000000
	//DoSomething(3);//int  - long implicit
	//double d = 5.0 / 4;
	int pi = 3.14;//double => int implicit


	/*Account ac1(2000, 5);
	const Account ac2(5000, 8);
	cout << "Get rate 1 : " << ac1.getRate() << endl;
	cout << "Get rate 2 : " << ac2.getRate() << endl;

	cout << "Get summa 1 : " << ac1.getSum() << endl;
	cout << "Get summa 2 : " << ac2.getSum() << endl;

	cout << "Get income 1 : " << ac1.getIncome() << endl;
	cout << "Get income 2 : " << ac2.getIncome() << endl;

	cout << "Set summa 1 : " << ac1.setSum() << endl;*/
	//cout << "Set summa 2 : " << ac2.setSum() << endl;//error




	//int year;
	//cout << "Enter year : ";
	//cin >> year;
	//Date date(year,2023);
	//date.Show();

	////const float pi;// = 3.14;
	////pi = 3.14;
	//int a = 5;
	//int* pa;// = &a;
	//pa = &a;
	//int b = 33;
	//pa = &b;
	//int& la = a;
	////la = a;


	//Date date;
	//date.setDate(33);
	//date.setDate(17);
	//cout << "Date : " << date.getDate() << endl;

	//const int size = 3;
	//const string s{ "first day" };
	//const int days[]{ 31,31,29 };

	//const Date eventDay{ 25,06,2023 };
	////eventDay.setDate(30);//error
	//cout << "Day : " << eventDay.getDate() << endl;



	
















}

