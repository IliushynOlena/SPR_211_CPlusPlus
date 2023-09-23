#include <iostream>
#include <map>
using namespace std;


map<string, int>::iterator findByValue(map<string, int>& m, int value)
{
    for (map<string, int>::iterator i = m.begin();  i != m.end();  i++)
    {
        if (i->second == value)
            return i;
    }
    return m.end();
}
struct ID
{
    int id;
    string name;

    ID() {}
    ID(int id, string name) : id(id), name(name) {}

    void Show() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
    bool operator < (const ID& other)const
    {
        return this->name < other.name;
    }

};
int main()
{
    map<ID, int> newMap;

    ID first(1, "Taras");
    pair<ID, int> pair2(first, 78);

    newMap.insert(pair2);
    newMap.insert(make_pair(ID(2, "Anna"), 97));
    newMap.insert(make_pair(ID(3, "Hanna"), 88));
    for (auto i : newMap)
    {
        i.first.Show();
        cout << "Value : " << i.second << endl;
        cout << "___________________________" << endl;
    }
    cout << "******************************" << endl;
    newMap[ID(7, "Anna")] = 40;//insert...edit
    cout << "Anna : " << newMap[ID(7, "Anna")] << endl;//get

    for (auto i : newMap)
    {
        i.first.Show();
        cout << "Value : " << i.second << endl;
        cout << "___________________________" << endl;
    }



    /*
    map<string, int> m;
    pair<string, int> p("Valia", 5);

    m.insert(p);
    m.insert(pair<string, int>("Olga", 7));
    m.insert(make_pair("Petro", 3));

    for (auto i : m)
    {
        cout << "Key : "<<  i.first <<" Value : "<< i.second << endl;
    }
    cout << "--------------------------------" << endl;
    auto res =  m.insert(make_pair("Olga", 9));
    pair<map<string, int>::iterator, bool> res2 =  m.insert(make_pair("Ivanka", 9));
    if (res.second)
    {
        cout << "Olga was added" << endl;
    }
    else
    {
        cout << "Olga was not added" << endl;
    }
    if (res2.second)
    {
        cout << "Ivanka was added" << endl;
    }
    else
    {
        cout << "Ivanka was not added" << endl;
    }
    for (auto i : m)
    {
        cout << "Key : " << i.first << " Value : " << i.second << endl;
    }

    cout << "Value : " << m["Olga"] << endl;//get
    cout << "Value : " << m["Valia"] << endl;//get
    cout << "Value : " << m["Ivan"] << endl;//get

    map<string, int>::iterator it = m.find("Olga");
    if (it == m.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found!" << endl;
        cout << "Key : " << it->first << " Value : " << it->second << endl;
        //it->first = "Oleg";
        it->second = 333;
        cout << "Key : " << it->first << " Value : " << it->second << endl;
    }
    cout << "--------------------------" << endl;
    for (auto i : m)
    {
        cout << "Key : " << i.first << " Value : " << i.second << endl;
    }
    it =  findByValue(m, 333);
    if(it!= m.end())
        cout << "Key : " << it->first << " Value : " << it->second << endl;

    if (it != m.end())
        m.erase(it);
    cout << "--------------------------" << endl;

    for (auto i : m)
    {
        cout << "Key : " << i.first << " Value : " << i.second << endl;
    }
    m["Valia"] = 10200;
    m["Sasha"] = 10000;
    m["Sasha"] = 500;
    cout << "--------------------------" << endl;

    for (auto i : m)
    {
        cout << "Key : " << i.first << " Value : " << i.second << endl;
    }
    */

}

