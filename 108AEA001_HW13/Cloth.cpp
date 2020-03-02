#include <iostream>
#include <string>
using namespace std;
#include "Cloth.h"
#include "Shop.h"

int Cloth::_currentId = 0;

Cloth::Cloth(string name, string description, double price)
{
	_name = name;
	_description = description;
	_price = price;
	_Id= _currentId++;
}

Cloth::Cloth(string name, string description)
{
	_name = name;
	_description = description;
}

Cloth::Cloth()
{

}

string Cloth::GetName() 
{
	return _name;
}

string Cloth::GetDecription() 
{
	return _description;
}

string Cloth::GetInformation()
{
	return string();
}

double Cloth::GetPrice() 
{
	return _price;
}

int Cloth::GetId() 
{
	return _Id;
}








