#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 10,11,12,13,14 };
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	for (int item : v)
	{
		cout << item << " ";
	}
	cout << endl;
	int a = 5;
	int* ptr;// pointer ....STL - iterator
	ptr = &a;

	vector<int>::iterator it;// pointer ....STL - iterator
	//v.begin();//return pointer on first element
	//v.end();
	//v.erase(v.begin());
	//v.erase(v.begin()+1);
	//v.erase(v.begin()+3);
	//v.erase(v.end()-1);
	v.erase(v.begin()+3, v.end()-2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	Print(v);

	v.insert(v.end(), 15);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin(), { 99,88,77 });
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), 5, 55);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin(), v2.begin()+1, v2.end()-2);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v[0] = 999;
	v[2] = 999;
	v[4] = 999;
	Print(v);

	v.push_back(77);
	v.push_back(77);
	v.push_back(77);
	v.push_back(77);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.pop_back();
	v.pop_back();
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	cout << "-----------------------------------" << endl;
	/*Print(v);
	Print(v2);
	v.swap(v2);
	Print(v);
	Print(v2);*/

	cout<< "Front : "<< v.front()<<endl;

	v.resize(10);
	/*v.push_back(77);
	v.push_back(77);
	v.push_back(77);*/
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.shrink_to_fit();
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.push_back(77);
	v.push_back(77);
	v.push_back(77);
	v.push_back(77);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		///2 5 8 99 99 99 99 9 3 4 7 
		if (v[i] == 9) {
			v.insert(v.begin() + i + 1, 99);
		}
	}
	Print(v);
}

