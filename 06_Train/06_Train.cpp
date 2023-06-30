#include<iostream>
#include<string>

using namespace std;

struct Vagon
{
	int number = 0;
	int plases = 0;
	int pass = 0;
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
			cout << "Number: " << vagons[i].number << "\t";
			cout << "Plases: " << vagons[i].plases << "\t";
			cout << "Pass: " << vagons[i].pass << endl;
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
	Train operator+(const Train& other)
	{
		Train result(*this);

		for (int i = 0; i < other.countVagons; i++)
		{
			result.AddVagon(other.vagons[i]);
		}
		return result;
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




}