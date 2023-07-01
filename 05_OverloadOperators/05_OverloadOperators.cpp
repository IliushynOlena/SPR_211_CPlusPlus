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
   
    Point operator --()//префіксна форма декременту
    {
        --this->x;
        --this->y;
        return *this;
    }
    Point operator ++(int k)//постфіксна форма інкременту
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator --(int)//постфіксна форма декременту
    {
        this->x--;
        this->y--;
        return *this;
    }
    int getX()const
    {
        return x;
    }
    int getY()const
    {
        return y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    friend bool operator<(const Point& point1, const Point& point2);
    friend Point operator ++(Point& point);
    friend ostream& operator << (ostream& out, const Point& other);
    friend istream& operator >> (istream& in,  Point& other);
};

bool operator<(const Point& point1, const Point& point2)
{
    return (point1.x + point1.y) < (point2.x + point2.y);
}
Point operator ++(Point &point)//префіксна форма інкременту 10:5
{
    /*point.setX(point.getX()+1);
    point.setY(point.getY()+1);*/
    point.x++;
    point.y++;
    return point;
}
//bool operator<(const Point& point1,  const Point& point2)
//{
//    return (point1.getX() + point1.getY()) < (point2.getX() + point2.getY());
//}
ostream& operator << (ostream& out, const Point& other)
{
    out << "X : " << other.x << " Y : " << other.y << endl;
    return out;
}
istream& operator >> (istream& in,  Point& other)
{
    in >> other.x;
    in >> other.y;
    return in;
}

int main()
{
    int a = 5, b = 7;
    a++;
    cout << a << endl;
    ++a;
    cout << a << endl;
    cout << "Hello" << endl;
    cout << a++ << endl;//->
    cout << ++a << endl;//<-
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    Point p1(10, 6);
    Point p2(2, 3);
    Point p3(12, 33);
    Point p4(22, 34);
    Point p5(22, 34);
    cout << (p1 < p2) << endl;

    cout << "Ostream operator : " << endl;
    cin >> p2;
    cout << p1 << p2 << p3;
    ++p1;
    --p2;
    cout << "Point p1 : "; p1.Print();
    cout << "Point p2 : "; p2.Print();
    p1++;//p1.operator++(a);
    p2--;
    cout << "Point p1 : "; p1.Print();
    cout << "Point p2 : "; p2.Print();
    //if (p1.operator<(p2))
    //{
    //    cout << " p1 is smaller than p2" << endl;
    //}
    //else
    //    cout << " p1 is not smaller than p2" << endl;

    //if (p1>p2)
    //    cout << " p1 is bigger than p2" << endl;
    //else
    //    cout << " p1 is not bigger than p2" << endl;

    //if (p4 == p5)
    //    cout << " Points are equal" << endl;
    //else
    //    cout << " Points are not equal" << endl;



    //cout << "Point p1 : "; p1.Print();
    //cout << "Point p2 : "; p2.Print();
    //Point res = p1.Plus(p2);
    //cout << "Res  : "; res.Print();
    //res = p1.Minus(p2);
    //cout << "Res  : "; res.Print();
   
    //res = p2.operator+(p1);
    //res = p1 + p2;// res = p1.operator+(p2);
    //cout << "Res  : "; res.Print();
    //res = p1 + 100;
    //cout << "Res  : "; res.Print(); 
    //res = p1- p2;
    //cout << "Res  : "; res.Print();  
    //res = p1 * p2;
    //cout << "Res  : "; res.Print(); 
    //res = p1 / p2;
    //cout << "Res  : "; res.Print();

    //p1 += p2;
    //cout << "Point p1 : "; p1.Print();

    //res = -p1;
    //cout << "Res  : "; res.Print();

    //p1 = p2 = p3 = p4;
    //cout << "Point p1 : "; p1.Print();
    //cout << "Point p2 : "; p2.Print();
    //cout << "Point p3 : "; p3.Print();
    //cout << "Point p4 : "; p4.Print();
}

