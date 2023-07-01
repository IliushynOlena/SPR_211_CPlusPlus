#include<iostream>
#include<string>

using namespace std;

struct Vagon
{
	int number = 0;
	int plases = 0;
	int pass = 0;
	void Show()
	{
		cout << "Number: " << number << "\t";
		cout << "Plases: " << plases << "\t";
		cout << "Pass: " << pass << endl;
	}
};

class Train
{
private:
	string model;
	int countVagons;
	Vagon* vagons;

public:
	Train()
	{
		model = "";
		countVagons = 0;
		vagons = nullptr;
	}

	Train(string model)
	{
		this->model = model;
		this->countVagons = 0;
		this->vagons = nullptr;
	}

	Train(const Train& cp)
	{
		this->model = cp.model;
		this->countVagons = cp.countVagons;
		this->vagons = nullptr;

		if (countVagons)
		{
			this->vagons = new Vagon[countVagons];
			for (int i = 0; i < countVagons; i++)
			{
				vagons[i] = cp.vagons[i];
			}
		}
	}

	~Train()
	{
		if (vagons != nullptr)
			delete[] vagons;
	}

	void Show()
	{
		cout << "-------- MY TRAIN [" << model << "] ---------\n";
		cout << "Vagons: " << countVagons << endl;
		for (int i = 0; i < countVagons; i++)
		{
			vagons[i].Show();
		}
		cout << endl;
	}


	void AddVagon(int number, int plases = 0, int pass = 0)
	{
		for (int i = 0; i < countVagons; i++)
		{
			if (vagons[i].number == number)
			{
				cout << "Vagon is already exist(" << endl;
				return;
			}
		}
		Vagon* temp = new Vagon[countVagons + 1];
		for (int i = 0; i < countVagons; i++)
		{
			temp[i] = vagons[i];
		}
		temp[countVagons].number = number;
		temp[countVagons].plases = plases;
		temp[countVagons].pass = pass;

		if (vagons != nullptr)
			delete[] vagons;
		vagons = temp;

		countVagons++;
	}void AddVagon(Vagon v)
	{
		Vagon* temp = new Vagon[countVagons + 1];
		for (int i = 0; i < countVagons; i++)
		{
			temp[i] = vagons[i];
		}
		temp[countVagons] =v;
		if (vagons != nullptr)
			delete[] vagons;
		vagons = temp;
		countVagons++;
	}

	void AddPass(int numberVagon)
	{
		for (int i = 0; i < countVagons; i++)
		{
			if (vagons[i].number == numberVagon)
			{
				vagons[i].pass++;
				cout << "Added!" << endl;
				return;
			}
		}
		cout << "Vagon not fined(" << endl;
	}
	void operator++()
	{
		for (int i = 0; i < countVagons; i++)
		{
			vagons[i].pass++;
		}
	}
	Train operator+(const Train& other)
	{
		Train result(*this);

		for (int i = 0; i < other.countVagons; i++)
		{
			result.AddVagon(other.vagons[i]);
		}
		return result;
	}

	Vagon GetVagon(int index)//20
	{
		if (index < 0 || index >= countVagons) return Vagon();
		return vagons[index];
	}
	Vagon operator[](int index)//20
	{
		if (index < 0 || index >= countVagons) return Vagon();
		return vagons[index];
	}
	void ChangePassangers(int count)
	{
		for (int i = 0; i < countVagons; i++)
		{
			vagons[i].pass += count;
		}
	}
	void operator()(int count)
	{
		for (int i = 0; i < countVagons; i++)
		{
			vagons[i].pass += count;
		}
	}
	void operator()(int count, int numberVagon)
	{

		for (int i = 0; i < countVagons; i++)
		{
			if (vagons[i].number == numberVagon)
			{
				vagons[i].pass += count;
			}
		}
	}
	operator string ()
	{
		//string res = "";
		//for (int i = 0; i < countVagons; i++)
		//{
		//	//"" + "1" + " " + "2" + " ";
		//	res += to_string(vagons[i].number) + " ";//1 2 3 1 2 3 
		//}
		//return res;
		return model;
	}
	string ConvertToString ()
	{		
		return model;
	}
};


int main()
{

	Train tr1("Tesla");
	tr1.AddVagon(1, 40, 10);
	tr1.AddVagon(2, 50, 20);
	tr1.AddVagon(3, 60, 30);
	tr1.AddVagon(3, 70, 40);
	tr1.AddPass(3);
	tr1.Show();

	Train tr2(tr1);
	tr2.AddPass(2);
	tr2.Show();
	cout << "----------------------------" << endl;
	Train superTrain = tr1 + tr2;
	superTrain.Show();
	cout << "----------------------------" << endl;
	++superTrain;
	superTrain.Show();

	cout << "_________________________________" << endl;
	Vagon v = superTrain.GetVagon(2);
	v.Show();

	v = superTrain[1];
	v.Show();
	cout << "_________________________________" << endl;
	superTrain.ChangePassangers(5);
	superTrain.Show();

	superTrain(10);
	superTrain.Show();

	superTrain(5, 1);
	superTrain.Show();

	cout << (string)superTrain << endl;

	//iostream




}