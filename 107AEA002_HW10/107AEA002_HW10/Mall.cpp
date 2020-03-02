#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
#include "Mall.h"
#include "MallUI.h"
#include "Shop.h"
#include "Customer.h"

Mall::Mall()
{
	load();
}
Mall::~Mall()
{
	size_t sizeOfshops = _shops.size();

	for (size_t i = 0; i < sizeOfshops; i++)
	{
		delete _shops[i];
	}
}
void Mall::selectShop(int shopIndex)
{
	_shopIndex = shopIndex;
}
void Mall::createNewCloth(string name, string description, double price)
{
	_shops[_shopIndex]->CreateNewCloth(name, description, price);
}
vector<Cloth*>* Mall::getClothes()
{
	return _shops[_shopIndex]->getClothes();
}
vector<Shop*>* Mall::getShops()
{
	return &_shops;
}

string Mall::getShopName(int shopId)
{
	shopId = _shopIndex;
	return _shops[shopId]->getName();
	
}

vector<Customer*>* Mall::getCustomer()
{
	return &_customers;
	
}



void Mall::makeNewOrder()
{
	_customers[_customerIndex]->makeNewOrder(_shops[_shopIndex]);
}

void Mall::addClothToOrder(int id)
{
	_customers[_customerIndex]->addClothToOrder(_shops[_shopIndex]->findCloth(id));
}

void Mall::selectCustomerAndShop(int customerIndex, int shopIndex)
{
	_customerIndex = customerIndex;
	_shopIndex = shopIndex;
}

bool Mall::isPointEnough()
{
	return _customers[_customerIndex]->isPointEnough();
	
}

void Mall::reducePointFromOrder()
{
	_customers[_customerIndex]->reducePointFromOrder();
}

void Mall::cancelOrder()
{
	_customers[_customerIndex]->cancelOrder();
}

Order* Mall::getCurrentOrder()
{
	return _customers[_customerIndex]->getCurrentOrder();
	
}

string Mall::showCustomers(int customerIndex)
{
	return _customers[customerIndex]->getName();
}

void Mall::load()
{
	
	string file;
	string line;
	string shopName;
	char firstLetter;
	file = "Cloth.txt";
	string::size_type start = 0;
	string::size_type first, last, end;
	fstream inputStream;
	inputStream.open(file);
	int flag = -1;
	while (!inputStream.eof())
	{
		getline(inputStream, line);
		firstLetter = line[0];
		if (firstLetter == 'S')
		{
			shopName = line.substr(5, line.length() - 2);
			_shops.push_back(new Shop(shopName));
			flag++;
		}
		else if(firstLetter != 'S')
		{
			first = line.find_first_of(",") + 2;
			last = line.find_last_of(",") + 2;
			end = line.length();
			string name = line.substr(start, first - start - 2);
			string description = line.substr(first, last - first - 2);
			double price = stod(line.substr(last, end - last));
			for (size_t i = 0; i < _shops.size(); i++)
			{
				if (_shops[i]->getName() == shopName)
				{

					_shops[flag]->CreateNewCloth(name, description, price);// store clothes into its owner shop
				}
			}
			
			//_cloth.push_back(new Cloth(name, description, price)); //creat new clothes
		}
			


	}
	inputStream.close();
	swap(_shops[1], _shops[2]);
	_customers.push_back(new Customer("Amber"));
	_customers.push_back(new Customer("Tim"));
	_customers.push_back(new Customer("Marry"));



}

double Mall::getRemainPoint(int index)
{
	_customerIndex = index ;
	return _customers[_customerIndex]->getCash();
}

double Mall::getCurrentPaid()
{
	
	return _customers[_customerIndex]->getCash();
}

int Mall::customerNumbers()
{
	
	return _customers.size();
}
