#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Adress {
private:
	string sity;
	string street;
	int numHouse;
	int numApartment;
public:
	Adress()
	{
		sity = "unknown";
		street = "unknown";
		numHouse = 0;
		numApartment = 0;
	}
	void set_sity(string sity)
	{
		this->sity = sity;
	}
	void set_street(string street)
	{
		this->street = street;
	}
	void set_numHouse(int numHouse)
	{
		this->numHouse = numHouse;
	}
	void set_numApartment(int numApartment)
	{
		this->numApartment = numApartment;
	}
	string get_sity()
	{
		return sity;
	}
	string get_street()
	{
		return street;
	}
	int get_numHouse()
	{
		return numHouse;
	}
	int get_numApartment()
	{
		return numApartment;
	}

};

void compareTwoAdress(Adress* adress, int size, int i, int j, int letterNum)
{
	if (adress[i].get_sity()[letterNum] < adress[j].get_sity()[letterNum])
	{
		swap(adress[i], adress[j]);
	}
	else if (adress[i].get_sity()[letterNum] == adress[j].get_sity()[letterNum] && adress[i].get_sity()[letterNum+1]!=0 && adress[j].get_sity()[letterNum+1]!=0)
	{
		compareTwoAdress(adress, size, i, j, letterNum + 1);
	}
}

void sortAdress(Adress* adress,int size)
{
	int letterNum = 0;
	for (int i = 0;i < size;++i)
	{
		for (int j = 0;j < size;++j)
		{
			if (i != j)
			{
				compareTwoAdress(adress, size, i, j, letterNum);
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int amountAdresses;
	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		return 1;
	}
	fin >> amountAdresses;

	Adress* adress = new Adress[amountAdresses];

	int num;
	string title;
	for (int i = 0;i < amountAdresses;++i)
	{
		fin >> title;
		adress[i].set_sity(title);
		fin >> title;
		adress[i].set_street(title);
		fin >> num;
		adress[i].set_numHouse(num);
		fin >> num;
		adress[i].set_numApartment(num);
	}

	sortAdress(adress, amountAdresses);

	ofstream fout("out.txt");
	if (!fout.is_open()) {
		return 2;
	}

	fout << amountAdresses << endl;
	for (int i = 0;i < amountAdresses;++i)
	{
		fout << adress[i].get_sity() << ", " << adress[i].get_street() << ", " << adress[i].get_numHouse() << ", " << adress[i].get_numApartment() << endl;
	}
	fin.close();
	//fout.close();
	delete[] adress;
	return 0;
}