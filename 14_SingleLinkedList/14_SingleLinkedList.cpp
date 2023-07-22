
#include <iostream>
using namespace std;


struct Node
{
    int value;
    Node *next;
    Node(int value, Node* next) :value(value), next(next) {}
};
class List
{
private:
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value,head);
        //newNode->value = value;
        //newNode->next = head;
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
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }      
    }
    int GetElementByPosition(int pos)//3
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
    int operator[](int pos)//3
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
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
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
};
int main()
{
    List l; 
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.PrintList();
    cout << "Element position 1 : " << l.GetElementByPosition(1) << endl;
    cout << "Element position 33 : " << l.GetElementByPosition(33) << endl;
    cout << "Element position 3 : " << l[3] << endl;
    //l.DeleteFromTail();
    //l.DeleteFromTail();
    //l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();
}
