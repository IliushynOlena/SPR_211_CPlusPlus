#include <iostream>
using namespace std;

class Animal//Abstract class
{
	string name;
	string place;
	float weight;
public:
	Animal() :name("no name"), place("no place"), weight(0) {}
	Animal(string n, string p, float w) :name(n), place(p)
	{
		/*if (w < 0)
			this->weight = 0;
		else
			this->weight = w;*/

		this->weight = w >= 0 ? w : 0;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << endl;
	}
	virtual void Move()const
	{
		cout << "I am moving......." << endl;
	}
	virtual void MakeSound() const = 0;//pure virtual
	
};
class Lion : public Animal
{
	float runSpeed;
public:
	Lion() :runSpeed(0), Animal() {}
	Lion(string n, string p, float w, float r) :runSpeed(r), Animal(n,p,w) {}
	void MakeSound()const override
	{
		cout << "Rrrr-rrrrr-rrrrr-rrrrr" << endl;
	}
	void Move()const override
	{
		cout << "I am running with speed : " << runSpeed << " km/h" << endl;
	}
};
class Duck: public Animal
{
	float flyHeight;
public:
	Duck() :flyHeight(0), Animal() {}
	Duck(string n, string p, float w, float f) :flyHeight(f), Animal(n,p,w) {}
	void MakeSound()const override
	{
		cout << "Kra-kra-kra-kra" << endl;
	}
	void Move()const override
	{
		cout << "I am swimming and flying up to " << flyHeight << " m" << endl;
	}
};

class Reptile : public Animal// Abstract class
{
	float swimDeep;
public:
	Reptile() :swimDeep(0), Animal() {}
	Reptile(string n, string p, float w, float s) :swimDeep(s), Animal(n,p,w) {}
	void Move() const override
	{
		cout << " I am crowling and swimming up to " << swimDeep << " m" << endl;
	}
};
class Frog: public Reptile
{
public:
	Frog() :Reptile() {}
	Frog(string n, string p, float w, float d) :Reptile(n, p, w, d) {}
	void MakeSound()const
	{
		cout << "Kva-kva-kva-kva" << endl;
	}
};

void RollCall(Animal& animal)
{
	cout << endl;
	animal.MakeSound();
	animal.Move();
}

int main()
{
	Frog frog("Crazy frog", "Boloto", 0.3, 0.5);
	frog.MakeSound();
	Duck duck("Scruzh Mack Duck","Lake",2.7, 6500);
	duck.MakeSound();
	duck.Move();
	duck.ShowInfo();

	Lion lion("King Lion","Savana",150,81);
	lion.MakeSound();
	lion.Move();
	lion.ShowInfo();

	RollCall(duck);
	RollCall(lion);
	RollCall(frog);

	Animal* zoo[2]{ &lion, &duck };
	/*Animal animal;
	animal.Move();
	animal.ShowInfo();
	animal.MakeSound();*/
   
}

