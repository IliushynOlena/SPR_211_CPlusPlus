#include <iostream>
using namespace std;
/*
int GetMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

long GetMax(long* arr, int size)
{
	long max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
short GetMax(short* arr, int size)
{
	short max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
*/
template<typename T>
T GetMax(T* arr, int size)
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}


template<class T_coll, class T_value>
class MyClass
{
	int size;
	T_coll* collection;
	T_value value;
public:
	MyClass()
	{
		size = 0;
		collection = nullptr;
		//point = 0;
	}
	MyClass(T_coll* coll, T_value v) :collection(coll), value(v) {}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void setCollection(T_coll* coll);
	
	void setValue(T_value value);

	void Print()
	{
		
		cout << "\nCollection : " << collection << endl;//address
		cout << "Value : " << value << endl;
	}
};

template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::setCollection(T_coll* coll)
{
	this->collection = coll;
}
template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::setValue(T_value value)
{
	this->value = value;
}

template<typename T_coord>
class Point
{
private:
	T_coord x;
	T_coord y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(T_coord x, T_coord y) :x(x), y(y) {}
	void Print()const
	{
		cout << "X : " << x << " Y : " << y << endl;
	}
	void setCoord(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
};
template<typename T_X, typename T_Y>
class NewPoint
{
private:
	T_X x;
	T_Y y;
public:
	NewPoint()
	{
		x = y = 0;
	}
	NewPoint(T_X x, T_Y y) :x(x), y(y) {}
	void Print()const
	{
		cout << "X : " << x << " Y : " << y << endl;
	}
	void setCoord(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
};
int main()
{
	Point<float> p(4, 8);
	p.Print();
	p.setCoord(4.0125, 8.1254);
	p.Print();

	Point<int> p2(50, 70);
	p2.Print();

	NewPoint<float, short> newPoint(3.14, 100);
	newPoint.Print();


	long* long_arr = new long[4];
	for (int i = 0; i < 4; i++)
	{
		long_arr[i] = i + 1; 
		cout << long_arr[i] << " ";
	}
	cout << endl;

	char* char_arr = new char[4];
	for (int i = 0; i < 4; i++)
	{
		char_arr[i] =  'a' + i ;
		cout << char_arr[i] << " ";
	}

	MyClass<long, string> cl1(long_arr, "Class with long collection");
	MyClass<char, string> cl2(char_arr, "Class with char collection");

	cl1.Print();
	cl2.Print();



	//delete[]long_arr;
	//delete[]char_arr;

   /* const int size = 10;
    int arr1[size] = { 5,7,18,4,65,32,99,7,8,12 };
	cout << "Max : " << GetMax(arr1, size) << endl;;
	long arr2[size] = { 5,7,18,4,65,32,99,7,8,12 };
	cout << "Max : " << GetMax(arr2, size) << endl;;
	short arr3[size] = { 5,7,18,4,65,32,99,7,8,12 };
	cout << "Max : " << GetMax(arr3, size) << endl;;
	float arr4[size] = { 5,7,18,4,65,32,99,7,8,12 };
	cout << "Max : " << GetMax(arr4, size) << endl;;
	int arr5[size] = { 5,7,18,4,65,32,99,7,8,12 };
	cout << "Max : " << GetMax(arr5, size) << endl;;

	string colors[6] = { "blue", "red","green", "yellow", "gray" };
	cout << "Max : " << GetMax(colors, 6) << endl;;*/

}

