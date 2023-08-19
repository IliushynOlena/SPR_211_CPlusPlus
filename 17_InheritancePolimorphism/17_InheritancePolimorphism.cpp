// 17_InheritancePolimorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
protected:
    string model;
    int year;
    float volume;
    int speed;
public:
    Car() :model("none"), year(0), volume(0), speed(0) {}
    Car(string m, int y, float v) :model(m), year(y), volume(v), speed(0) {}
    virtual void Drive()const
    {
        cout << "I am a Car. I can drive with speed :  " << speed << " km/h" << endl;
    }
    virtual void Print()const
    {
        cout << " Model : " << model << endl;
        cout << " Year : " << year << endl;
        cout << " Volume : " << volume << endl;
        cout << " Speed : " << speed << endl;
    }
    void SetSpeed(int speed)
    {
        if(speed >= 0)
            this->speed = speed;
    }    
};
class PoliceCar : public Car
{
    int soundVolume;
public:
    PoliceCar() : soundVolume(0), Car() {}
    PoliceCar(string m, int y, float v, int sV) : soundVolume(sV), Car(m,y,v) {}
    void Drive()const override
    {
        cout << "I am a Police Car. I can drive with speed :  " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();
        cout << " soundVolume : " << soundVolume << endl;
    }
    void BeepBeep()
    {
        Beep(494, 250);
        Beep(523, 250);
        Beep(587, 500);
        Beep(523, 250);
        Beep(494, 250);
        Beep(440, 500);
    }
};

class SportCar : public Car
{
    int turbo;
public:
    SportCar() :turbo(0), Car() {}
    SportCar(string m, int y, float v, int t) : turbo(t), Car(m, y, v) {}
    void Drive()const override
    {
        cout << "I am a Sport Car. I can drive with speed :  " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();
        cout << " turbo Speed : " << turbo << endl;
    }
    void Nitro()
    {
        cout << "Enable  speed : " << speed << " km/h" << endl;
        speed += turbo;
        cout << "------------> " << speed << " Km/h" << endl;
    }

};

void TestDrive(Car& car)
{
    car.SetSpeed(60);
    car.Drive();
    
}


int main()
{
    Car simpleCar("Megan", 2018, 1.6);
    simpleCar.SetSpeed(80);
    simpleCar.Drive();
    simpleCar.Print();

    PoliceCar p("Duster",2019,2.0,450);
    p.SetSpeed(100);
    p.Drive();
    p.Print();
    p.BeepBeep();

    SportCar sport("Formula1", 2022, 3.6, 45);
    sport.SetSpeed(120);
    sport.Drive();
    sport.Nitro();
    sport.Print();
    cout << "--------------------------------" << endl;
    TestDrive(&simpleCar);
    TestDrive(&p);
    TestDrive(&sport);


    Car* collection[3]
    {
        new Car("Megan", 2018, 1.6),
        new PoliceCar("Duster",2019,2.0,450),
        new SportCar("Formula1", 2022, 3.6, 45)
    };
    for (int i = 0; i < 3; i++)
    {
        collection[i]->Drive();
        collection[i]->Print();
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete collection[i];
    }

    
}

