#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Animal
{
protected:
	string name;
	string place;
	float weight;
public:
	Animal() :name("no name"), place("no place"), weight(0) {}
	Animal(string name, string place, float weight) :name(name), place(place)
	{
		this->weight = (weight >= 0) ? weight : 0;
	}
	void Print()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << endl;
	}
	void Move()const
	{
		cout << "I am moving........" << endl;
	}
	friend ostream& operator <<(ostream& out, const Animal& an);
	friend istream& operator >> (istream& in,  Animal& an);
};
ostream& operator <<(ostream& out, const Animal& an)
{
	out << an.name << " " << an.place << " " << an.weight;
	return out;
}
istream& operator >> (istream& in, Animal& an)
{
	in >> an.name >> an.place >> an.weight;
	return in;
}
class Zoo
{
	string name;
	Animal* animals;
	int countAnimal;
public:
	Zoo(string name) :name(name), animals(nullptr), countAnimal(0) {}
	void AddAnimal(Animal animal)
	{
		countAnimal++;
		Animal* temp = new Animal[countAnimal];
		for (int i = 0; i < countAnimal - 1; i++)
		{
			temp[i] = animals[i];
		}
		temp[countAnimal - 1] = animal;
		if (animals != nullptr)
			delete[]animals;
		animals = temp;
	}
	void ShowZoo()const
	{
		cout << " Zoo : " << name << endl;
		for (int i = 0; i < countAnimal; i++)
		{
			animals[i].Print();
			cout << endl;
		}
	}
	~Zoo()
	{
		if (animals != nullptr)
			delete[]animals;
	}
	void SaveToFile()
	{
		ofstream out("zoo.txt", ios_base::out);
		out << name << endl;
		out << countAnimal << endl;
		for (int i = 0; i < countAnimal; i++)
		{			
			out << animals[i]<<endl;
		}
		out.close();
		cout << "Zoo is saved to file" << endl;
	}
	void LoadFromFile()
	{
		/*Zoo zoo;
		string name;// "Rivne Zoo";
		Animal* animals;
		int countAnimal; // 4*/
		ifstream in("zoo.txt", ios_base::in);
		/*string n;
		getline(in,n);
		name = n;*/
		getline(in,name);
		in >> countAnimal;
		if (animals != nullptr) delete[]animals;
		animals = new Animal[countAnimal];
		for (int i = 0; i < countAnimal; i++)
		{
			in >> animals[i];
		}
		in.close();
	}
	void BinarySave()
	{
		ofstream out("zoo.bin", ios_base::out | ios_base::binary);
		out.write((char*)&name, sizeof(name));
		out.write((char*)&countAnimal, sizeof(countAnimal));
		for (int i = 0; i < countAnimal; i++)
		{
		    out.write((char*)&animals[i], sizeof(animals[i]));			
		}
		out.close();
	}
	void BinaryLoad()
	{
		ifstream in("zoo.bin", ios_base::in | ios_base::binary);
		in.read((char*)&name, sizeof(name));
		in.read((char*)&countAnimal, sizeof(countAnimal));
		if (animals != nullptr) delete[]animals;
		animals = new Animal[countAnimal];
		for (int i = 0; i < countAnimal; i++)
		{
			in.read((char*)&animals[i], sizeof(animals[i]));
		}
		in.close();
	}

};

int main()
{

	Animal an("Tom", "Flat", 3);
	//an.Print();
	Zoo zoo("");
	/*Zoo zoo("Rivne");
	zoo.AddAnimal(an);
	zoo.AddAnimal(Animal("King Lion", "Voiler", 150));
	zoo.AddAnimal(Animal("Grey Monkey", "Tree", 25));
	zoo.AddAnimal(Animal("Green Turtle", "Lake", 5));
	zoo.ShowZoo();*/
	//zoo.BinarySave();
	zoo.BinaryLoad();
	zoo.ShowZoo();
	//zoo.SaveToFile();
	/*
	zoo.LoadFromFile();
	zoo.ShowZoo();*/
    
}

