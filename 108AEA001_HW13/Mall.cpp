#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
using namespace std;
#include <windows.h>
#include "Mall.h"
#include "Shop.h"
#include "Cloth.h"
#include "Customer.h"
#include "Order.h"
#include "Suite.h"

string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

Mall::Mall()
{
	_txtLocation = ExePath() + "\\Cloth.txt";
	this->ReadFromTxt(_txtLocation);
	_customers.push_back(new Customer("Amber"));
	_customers.push_back(new Customer("Tim"));
	_customers.push_back(new Customer("Marry"));
}

//Add clothes to the corresponding shop
void Mall::createNewCloth(string name, string description, double price)
{
		_shops.at(_shopIndex-1)->createNewCloth(name, description, price);
}

//Get all clothes
vector<Cloth*>* Mall::GetClothes()
{
	vector <Cloth*>* _clothes= _shops.at(_shopIndex-1)->GetClothes();
	return _clothes;
}

//Get all shops
vector<Shop*>* Mall::GetShops()
{
	return &_shops;
}

//Get all customers
vector<Customer*>* Mall::GetCustomers()
{
	return &_customers;
}

//Make new order
void Mall::makeNewOrder()
{
	_customers.at(_customerIndex - 1)->makeNewOrder(_shops.at(_shopIndex - 1));
}

//Add Cloth to order
void Mall::addClothToOrder(int id)
{
	_customers.at(_customerIndex - 1)->addClothToOrder(_shops.at(_shopIndex - 1)->findCloth(id));
}

//select Customer and shop
void Mall::selectCustomerAndShop(int customerIndex, int shopIndex)
{
	_shopIndex = shopIndex;
	_customerIndex = customerIndex;
}

//Determine whether the points are enough
bool Mall::isPointEnough()
{
	if (_customers.at(_customerIndex - 1)->isPointEnough())
		return true;
	else
		return false;
}

//Reduce point from order
void Mall::reducePointFromOrder()
{
	_customers.at(_customerIndex - 1)->reducePointFromOrder();
}

//Cancel order
void Mall::cancelOrder()
{
	_customers.at(_customerIndex - 1)->cancelOrder();
}

//Get Current Order
Order * Mall::getCurrentOrder()
{
	return _customers.at(_customerIndex - 1)->getCurrentOrder();
}

//Read the shops and clothes from .txt
void Mall::ReadFromTxt(string txtLocation)
{
	fstream inputStream;
	inputStream.open(txtLocation);
	string line;
	int i = 0;
	if (inputStream.is_open())
	{
		GetLine(inputStream, line, i);
	}
	inputStream.close();
	swap(_shops.at(1), _shops.at(2));
}

//Split and store the clothes
void Mall::AddClothes(string line, int i)
{
	string lineTemp;
	map<int, Cloth>::iterator iter;
	string::size_type idx;
	string iString = line.substr(0, line.find_first_of(","));
	int iValue = std::stoi(iString);
	lineTemp = line.erase(0, line.find_first_of(",") + 2);
	idx = lineTemp.find("Suite");
	if (idx == string::npos)
	{
		NonSuite(lineTemp, i, iValue);
	}
	else
	{
		ConfirmSuite(lineTemp, i, idx);
	}
	
}

//Split and store the shops
int Mall::AddShops(string line, int i)
{
	_shops.push_back(new Shop(line.substr(5, line.length() - 6)));
	i++;
	return i;
}

//Read line by line
void Mall::GetLine(fstream & inputStream, string line, int i)
{
	string::size_type idx;
	while (getline(inputStream, line))
	{
		if (line.empty())
		{
			continue;
		}
		idx = line.find("Shop");
		if (idx == string::npos)
		{
			AddClothes(line, i);
		}
		else
		{
			i = AddShops(line, i);
		}
	}
}

void Mall::NonSuite(string lineTemp,int i,int iValue)
{
	string name = lineTemp.substr(0, lineTemp.find_first_of(","));
	string description = lineTemp.substr(lineTemp.find_first_of(",") + 2, lineTemp.find_last_of(",") - (lineTemp.find_first_of(",") + 2));
	double price = stod(lineTemp.substr(lineTemp.find_last_of(",") + 2, lineTemp.length() - (lineTemp.find_last_of(",") + 2)));
	_shops.at(i - 1)->createNewCloth(name, description, price);
	mapClothes[iValue] = Cloth(name, description, price);
}

void Mall::ConfirmSuite(string lineTemp, int i, string::size_type idx)
{
	string lineTempTemp = lineTemp;
	string lineC = lineTemp.erase(idx - 2, lineTemp.length() - idx + 2);//切割 suite 前面
	string lineSuite = lineTempTemp.erase(0, idx);//suite 開始
	string lineNumber = lineSuite.erase(0, 7);// suite 後面 number
	string name = lineC.substr(0, lineC.find_first_of(","));
	string description = lineC.substr(lineC.find_first_of(",") + 2, lineC.find_last_of(",") - (lineC.find_first_of(",") + 2));
	int num = count(lineNumber.begin(), lineNumber.end(), ',');
	CountSuite(num, name, description, lineNumber, i);
}

void Mall::CountSuite(int num, string name, string description, string lineNumber, int i)
{
	if (num == 1)
	{
		Suite suite(name, description);
		string num1, num2;
		num1 = lineNumber.substr(0, lineNumber.find_first_of(","));
		num2 = lineNumber.substr(lineNumber.find_first_of(",") + 2, lineNumber.length() - (lineNumber.find_first_of(",") + 2));
		suite.add(&(mapClothes[stoi(num1)]));
		suite.add(&(mapClothes[stoi(num2)]));
		_shops.at(i - 1)->createNewCloth(name, description, suite.GetPrice());
	}
	else if (num == 2)
	{
		Suite suite(name, description);
		string num1, num2, num3;
		num1 = lineNumber.substr(0, lineNumber.find_first_of(","));
		num2 = lineNumber.substr(lineNumber.find_first_of(",") + 2, lineNumber.find_last_of(",") - (lineNumber.find_first_of(",") + 2));
		num3 = lineNumber.substr(lineNumber.find_last_of(",") + 2, lineNumber.length() - (lineNumber.find_last_of(",") + 2));
		suite.add(&mapClothes[stoi(num1)]);
		suite.add(&mapClothes[stoi(num2)]);
		suite.add(&mapClothes[stoi(num3)]);
		_shops.at(i - 1)->createNewCloth(name, description, suite.GetPrice());
	}
	else if (num == 0)
	{
		Suite suite(name, description);
		int iValue1 = std::stoi(lineNumber);
		suite.add(&mapClothes[iValue1]);
		_shops.at(i - 1)->createNewCloth(name, description, suite.GetPrice());
	}
}

