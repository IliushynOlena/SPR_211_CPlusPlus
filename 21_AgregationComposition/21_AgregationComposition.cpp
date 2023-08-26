#include <iostream>
using namespace std;
class Document
{
private:
    string name;
    string format;
    int pages;
public:
    Document() :name("no name"), format("no format"), pages(0) {}
    Document(string name, string format, int pages) :name(name), format(format),
        pages(pages) {}
    void ShowInfo()const
    {
        cout << "___________Document : " << name << "____________" << endl;
        cout << "Format : " << format << endl;
        cout << "Pages : " << pages << endl;
   }
};

class Cartridge
{
public:
    enum Type { Standart, XL};
private:
    float volume;
    string color;
    Type type;
public:
    Cartridge() :volume(0), color("not setted"), type(Standart) {}
    Cartridge(float v, string c, Type t) :volume(v), color(c), type(t) {}
    void ShowInfo()const
    {
        cout << "Volume : " << volume << endl;
        cout << "Color : " << color << endl;
        cout << "Type : " << type << " : ";
        switch (type)
        {
        case Cartridge::Standart:cout << "Standart" << endl; break;
        case Cartridge::XL:cout << "XL" << endl; break;
        }
        cout << endl;
    }
};
class Scaner
{
    string format;
    float resolution;
    float h, w;
public:
    Scaner():format("no format"), resolution(0), h(0), w(0) {}
    Scaner(string f, float r, float h, float w):format(f), resolution(r), h(h), w(w) {}
    void ShowInfo()const
    {
        cout << "Format : " << format << endl;
        cout << "Resolution : " << resolution << endl;
        cout << "Height : " << h << endl;
        cout << "Width : " << w << endl;
  }
};
class Printer
{
private:
    string model;
    Scaner scaner;//default c-tor
    Cartridge* cartridges;
    int countCartridges;
    Document* doc;
public:
    Printer() :model("no model"), cartridges(nullptr), countCartridges(0), doc(nullptr) {}
    Printer(string model, float resolution, float Height, float Width, string Format):
        doc(nullptr)
    {
        this->model = model;
        scaner = Scaner(Format, resolution, Height, Width);

        countCartridges = 4;
        cartridges = new Cartridge[countCartridges];
        cartridges[0] = Cartridge(100, "Blue", Cartridge::Standart);
        cartridges[1] = Cartridge(100, "Red", Cartridge::Standart);
        cartridges[2] = Cartridge(100, "Yellow", Cartridge::Standart);
        cartridges[3] = Cartridge(300, "Black", Cartridge::XL);   
    
    }
    void Scan()const
    {
        cout << "Scanning....... with settings : " << endl;
        scaner.ShowInfo(); cout << endl;
    }
    void Print()const
    {
        if (doc == nullptr)
        {
            cout << "No document to print!!!" << endl;
        }
        else
        {
            cout << "Printing.........." << endl;
            doc->ShowInfo();
        }
       
    }
    void ShowSettings()
    {
        cout << "Printing......with settings :" << endl;
        for (int i = 0; i < countCartridges; i++)
        {
            cartridges[i].ShowInfo();
        }
    }
    ~Printer()
    {
        if (cartridges != nullptr)
            delete[]cartridges;
    }
    void AddToQueue(Document& doc)
    {
        this->doc = &doc;
    }
    void Cancel()
    {
        doc = nullptr;
    }
};

int main()
{
    Printer printer("Canon", 300, 50, 30, "A0");
    printer.Print();
    printer.Scan();

    Document doc1("passport.pdf", "A5", 7);
    Document doc2("C++ for beginners", "A4", 1500);

    printer.AddToQueue(doc1);
    printer.Print();

    printer.AddToQueue(doc2);
    printer.Cancel();
    printer.Print();
    
}

