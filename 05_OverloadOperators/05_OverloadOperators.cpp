#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        x = y = value;
    }
    Point(int x, int y) :x(x), y(y) {}
   /* {
        this->x = x;
        this->y = y;
    }*/
    void Print()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    Point Plus( const Point& other)const   //Point Plus(Point * const this, const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point& other)const//Point Plus(Point * const this, const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    //Type operator [symbol]() {}
    Point operator +(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator +(int value)const
    {
        Point res(this->x + value, this->y + value);
        return res;
    }
    Point operator -(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)const
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)const
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator-()
    {
      /*  Point res(this->x * -1, this->y * -1);
        return res;*/
        return Point(-x, -y);
    }
    Point operator =(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    bool operator<(const Point& other)const
    {
        //if ((this->x + this->y) < (other.x + other.y))
        //    return true;
        //else
        //    return false;

        return (this->x + this->y) < (other.x + other.y);
    }
    bool operator>(const Point& other)const
    {
        return (this->x + this->y) > (other.x + other.y);
    }
    bool operator>=(const Point& other)const
    {
        return (this->x + this->y) >= (other.x + other.y);
    }
    bool operator<=(const Point& other)const
    {
        return (this->x + this->y) <= (other.x + other.y);
    }
    bool operator ==(const Point& other)const
    {
        return (this->x == other.x ) && (this->y == other.y);
    }
    bool operator !=(const Point& other)const
    {
        return !(*this == other);
    }
};

int main()
{
    int a = 5, b = 7;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    Point p1(10, 6);
    Point p2(2, 3);
    Point p3(12, 33);
    Point p4(22, 34);
    Point p5(22, 34);
    if (p1.operator<(p2))
    {
        cout << " p1 is smaller than p2" << endl;
    }
    else
        cout << " p1 is not smaller than p2" << endl;

    if (p1>p2)
        cout << " p1 is bigger than p2" << endl;
    else
        cout << " p1 is not bigger than p2" << endl;

    if (p4 == p5)
        cout << " Points are equal" << endl;
    else
        cout << " Points are not equal" << endl;



    cout << "Point p1 : "; p1.Print();
    cout << "Point p2 : "; p2.Print();
    Point res = p1.Plus(p2);
    cout << "Res  : "; res.Print();
    res = p1.Minus(p2);
    cout << "Res  : "; res.Print();
   
    res = p2.operator+(p1);
    res = p1 + p2;// res = p1.operator+(p2);
    cout << "Res  : "; res.Print();
    res = p1 + 100;
    cout << "Res  : "; res.Print(); 
    res = p1- p2;
    cout << "Res  : "; res.Print();  
    res = p1 * p2;
    cout << "Res  : "; res.Print(); 
    res = p1 / p2;
    cout << "Res  : "; res.Print();

    p1 += p2;
    cout << "Point p1 : "; p1.Print();

    res = -p1;
    cout << "Res  : "; res.Print();

    p1 = p2 = p3 = p4;
    cout << "Point p1 : "; p1.Print();
    cout << "Point p2 : "; p2.Print();
    cout << "Point p3 : "; p3.Print();
    cout << "Point p4 : "; p4.Print();
}

