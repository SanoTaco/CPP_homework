#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include <string>
#include "Shop.h"
#include "Cloth.h"

string Shop::GetName() 
{
	return _name;
}

void Shop::createNewCloth(string name, string description, double price)
{
	_clothes.push_back(new Cloth(name, description, price));
}

vector<Cloth*>* Shop::GetClothes()
{
	return &_clothes;
}

Cloth * Shop::findCloth(int id)
{
	vector<Cloth*>::iterator it;
	for (it = _clothes.begin(); it != _clothes.end(); it++) 
	{
		if (id == (*it)->GetId()) 
		{
			return *it;
		}
	}
}

Shop::Shop(string name) 
{
	_name = name;	
}



