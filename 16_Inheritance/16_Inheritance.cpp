#include <iostream>
using namespace std;

class Enemy
{
//protected://private in main, or public in child class
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy() :name("no name"), health(maxHealth), strength(0){}
    Enemy(string name, float s) :name(name), health(maxHealth), strength(s){}
    void Print()const
    {
        
        cout << "Name : " << name << endl;
        cout << "Health : " << health << " % " << endl;
        cout << "Strength : " << strength << endl;
    }
    void DecreaseHealth(int value)
    {
        if (health - value < 0)
            health = 0;
        else
            health -= value;
    }
    bool IsAlive()const
    {
        return health > 0;
    }   
};
//Inheritance
//class Child : [spetificator] Parent 

class Dragon : public Enemy
{
    float fire;
public:
    Dragon() :fire(0), Enemy() {}
    Dragon(string name, float s, float fire) :fire(fire), Enemy(name, s) {}
    void Fight(int damage)
    {
        cout << "Getting damage " << damage << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after damage " << health << " % " << endl;
    }
    void Print()
    {
        cout << "----------------- Dragon-----------------" << endl;
        Enemy::Print();
        cout << "Fire : " << fire << endl;        
    }
    float Attack()
    {
        cout << "Attacking with strenght " << strength << endl;
        return strength;
    }

};

class Monster: public Enemy
{
    float runSpeed;
public:
    Monster() :runSpeed(0), Enemy() {}
    Monster(string name, float s, float r) :runSpeed(r), Enemy(name,s) {}
    void Run()
    {
        cout << "Monster running with speed : " << runSpeed << " km/h"<<endl;
    }
    void Print()
    {
        Enemy::Print();
        cout << "Run speed : " << runSpeed << endl;
    }
};


int main()
{

    Enemy e;
    
    Monster monster("Monya", 2, 150);
    monster.Run();
    monster.Print();

    Dragon boss("Vasia",10,2);
    
    Dragon dragon("Valera",6,1);

    int i = 1;
    do
    {
        cout << "\n ------- Round [" << i++ << "]" << endl;
        boss.Fight(dragon.Attack());
        dragon.Fight(boss.Attack());

        boss.Print();
        dragon.Print();
    } while (dragon.IsAlive() && boss.IsAlive());

  
    
    
}

