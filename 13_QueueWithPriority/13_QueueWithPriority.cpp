#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
    struct Element
    {
        T value;
        int priority;
    };
private:
    Element* arr;
    int top;
public:
    Queue() :arr(nullptr), top(0) {}
    ~Queue()
    {
        delete[]arr;
    }
    void Enqueue(T value, int priority)
    {
        int index = 0;
        while (index < top && arr[index].priority < priority) { index++; }
        top++;
        Element* temp = new Element[top];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{value,priority};
        for (int i = index; i < top-1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr)
            delete[]arr;
        arr= temp;
    }
    bool IsEmpty()const
    {
        return top == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (int i = 0; i < top-1; i++)
            {
                arr[i] = arr[i + 1];
            }
            top--;
            return first;
        }
    }
    void Print()const
    {
        cout << "-------------- Queue ------------" << endl;
        for (int i = 0; i < top; i++)
        {
            cout << arr[i].value << " : "<< arr[i].priority << endl;
        }
        cout << endl;
        cout << "_____________________________________" << endl;
    }
};

int main()
{
    Queue<string> q;
    Queue<string>::Element newEl{ "A",1 };
    q.Enqueue("A", 1);
    q.Enqueue( "B",2 );
    q.Enqueue("K",8 );
    q.Enqueue( "G",5 );
    q.Enqueue("C",3 );
    q.Print();
    q.Enqueue( "D",4 );
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Element : " << q.Dequeue().value << endl;

    }
    
}

