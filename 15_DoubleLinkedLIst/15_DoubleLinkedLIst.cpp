
#include <iostream>
using namespace std;


template<typename T_data>
class List
{
    struct Node
    {
        Node* prev;
        T_data value;
        Node* next;
        Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}
    };
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T_data value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        //newNode->value = value;
        //newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void PrintList()
    {
        //Node* current = head;//int i = 0;

        //while (current != nullptr)//i < 10;
        //{
        //    cout << current->value << " ";
        //    current = current->next;//i++;
        //}  

        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
    void AddToTail(T_data value)
    {
        Node* newNode = new Node(tail, value, nullptr);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    T_data GetElementByPosition(int pos)//3
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
        return 0;
    }
    T_data operator[](int pos)//3
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
        return 0;
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void DeleteFromHead() {}
};
struct Vagon{};
class Train
{
    string model;
    List<Vagon> vagons;
public:
    void AddToHead()
    {
        //vagons.
    }
};
int main()
{
    List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.PrintList();
    //cout << "Element position 1 : " << l.GetElementByPosition(1) << endl;
    //cout << "Element position 33 : " << l.GetElementByPosition(33) << endl;
    //cout << "Element position 3 : " << l[3] << endl;
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();
}
