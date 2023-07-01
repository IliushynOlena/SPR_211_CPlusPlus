#include <iostream>
using namespace std;

class Square;
class Rectangle
{
private:
    int h;
    int w;
public:
    Rectangle() : h(2), w(2) {}
    Rectangle(int v) : h(v), w(v) {}
    Rectangle(int h, int w) : h(h), w(w) {}
    void Show()const
    {
        cout << "Height : " << h << " ";
        cout << "Width : " << w << endl;
    }  
    //operator typename() {}//1
    //operator typename()const {}//2
    //explicit operator typename()const {}//3
    explicit operator int()
    {
        return h * w;
    }
    explicit operator Square();
};


class Square
{
private:
    int side;
public:
    Square() :side(0) {}
    Square(int side) :side(side) {}
    void Show()const
    {
        cout << "Height : " << side << " ";
        cout << "Width : " << side << endl;
    }
    explicit operator Rectangle()
    {
        Rectangle rect(side, side + 10);
        return rect;
    }
};

Rectangle::operator Square()
{
    return Square(h + w);
}

int main()
{
    //int a = 3.33;//double -> int implicit = 3
    int a = (int)3.33;//double -> int explicit = 3 tandart to standart
    
    int valueInt = 9;
    double valueDob = valueInt;//int -> double implicit - standart to standart - 9.000000000000

    Square sq(5);//standart to abstract
    Rectangle rect(10, 15);//standart to abstract
    sq.Show();
    rect.Show();

    //valueInt = (int) rect;//Rectangle -> int - abstract to  standart 
    //cout << "Rectangle to int = " << valueInt << endl;

    //rect = (Rectangle) sq;//abstract to abstract
    //rect.Show();


    sq = (Square) rect;//abstract to abstract
    sq.Show();
}

