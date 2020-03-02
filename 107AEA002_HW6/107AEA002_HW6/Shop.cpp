#include<iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;
#include"Shop.h"
#include "Cloth.h"
#include "MallUI.h"

Shop::Shop(string name)
{
	_name = name;
	//Load();//loading data form cloth.txt
}
Shop::~Shop()
{

}
string Shop::getName()
{

	return _name;
}
void Shop::CreateNewCloth(string name, string description, double price)
{
	string n, d;
	double p;
	n = name;
	d = description;
	p = price;
	_cloth.push_back(new Cloth(n, d, p));
}
vector<Cloth*>* Shop::getClothes()
{
	return &_cloth;

}
/*
void Shop::Load()
{
	MallUI MallUI;
	string file;
	string line;
	file = "Cloth.txt";
	string::size_type start = 0;
	string::size_type first, last,end;
	fstream inputStream;
	inputStream.open(file);
	if (!inputStream.is_open())
	{
		MallUI.ErrorLoading();
	}
	else
	{

		while (!inputStream.eof())
		{
			getline(inputStream, line);
			first = line.find_first_of(",") +2;
			last = line.find_last_of(",") + 2;
			end = line.length();
			string name = line.substr(start, first - start - 1);
			string description = line.substr(first,last-first -1);
			double price = stod(line.substr(last, end - last));
			_cloth.push_back(new Cloth(name, description, price)); //creat new clothes


		}
		inputStream.close();

	}



}
*/

/*

Cloth* Shop::findCloth(int id)
{

}

*/