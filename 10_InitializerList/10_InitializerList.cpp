#include <iostream>
using namespace std;

class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	Array(int size )
	{
		this->size = size;//10
		arr = new int[size] {};
		/*for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}*/
	}
	Array(const initializer_list<int> &list)
	{
		this->size = list.size();//6
		arr = new int[size];
		/*for (int i = 0; i < size; i++)
		{
			arr[i] = list[i];
		}*/
		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}
	}
	void Fill(const initializer_list<int>& list)
	{
		if (arr)
		{
			delete[]arr;
		}
		this->size = list.size();//6
		arr = new int[size];
		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int static_arr[5] = { 1,2,3,4,5 };
	//int* arr = new int[5] {6, 7, 8, 9, 10};
	//Array newArr = { 10,20,30,40,50,60 };
	Array newArr;// ({ 10,20,30,40,50,60 ,70,80,90,100,101,102,103,104,105,1111,4444,555,677,888 });
	newArr.Fill({ 1,2,3,4,5,6,7,8 });
	newArr.Print();
	newArr.Fill({ 1,2,3,4,5,6,7,8 });
	newArr.Print();
   
}

