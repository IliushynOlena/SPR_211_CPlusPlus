#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    int* arr;
    int maxSize;
    int top;
public:
    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        top = 0;
    }
    ~Queue()
    {
        delete[]arr;
    }
    bool IsEmpty()const
    {
        return top == 0;
    }
    bool IsFull()const
    {
        return top == maxSize;
    }
    void Enqueue(int element)
    {
        if (!IsFull())
            arr[top++] = element;
    }
    int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < top; i++)
            {
                arr[i] = arr[i + 1];
            }
            //Simple queue
            //top--;

            //Cycle queue
            arr[top-1] = first;
            return first;
        }
    }
    void Clear()
    {
        top = 0;
    }
    int GetCount()const
    {
        return top;
    }
    void Print()const
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int Peek()const
    {
        if (!IsEmpty())
            return arr[0];
    }
};

int main()
{
    Queue q(25);
    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 30);
    }
    cout << "Peek : " << q.Peek() << endl;
    cout << "Count : " << q.GetCount() << endl;
    q.Print();

    cout << "\nElement : " << q.Dequeue() << endl;

    while (!q.IsEmpty())
    {
       cout << "Element : " << q.Dequeue() << endl;
       _getch();

    }
}
