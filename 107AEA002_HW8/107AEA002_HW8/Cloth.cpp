#include <iostream> 
#include <vector>
#include <string>
using namespace std;
#include "Cloth.h"
int Cloth::_id = 1;
Cloth::Cloth(string name, string description, double price)
{
	_name = name;
	_description = description;
	_price = price;
	_id++;
}
Cloth::~Cloth()
{

}
string Cloth::getName()
{

	return _name;
}

string Cloth::getDiscription()
{
	return _description;
}
double Cloth::getPrice()
{
	return _price;
}
int Cloth::getId()
{
	return _id;
}