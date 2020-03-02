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
	size_t sizeOfclothes = _cloth.size();

	for (size_t i = 0; i < sizeOfclothes; i++)
	{
		delete _cloth[i];
	}
}
Cloth * Shop::findCloth(int id)
{
	for (int i = 0; i != _cloth.size(); i++)
	{
		if (id == _cloth[i]->getId())
		{
			return _cloth[i];;
		}
	}
	
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
