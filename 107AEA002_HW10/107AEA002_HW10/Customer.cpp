#include<string>
#include <vector>
#include <iostream>

using namespace std;

#include "Order.h"
#include "Customer.h"

Customer::Customer(string str)
{
	_name = str;
	_point = 2000.00;
	_order = nullptr;
}

Customer::~Customer()
{
	delete _order;
}

string Customer::getName()
{
	return _name;
}

double Customer::getCash()
{
	
	return _point ;
	
}

void Customer::makeNewOrder(Shop * shop)
{
	_order = new Order(shop);

}

void Customer::addClothToOrder(Cloth * cloth)
{
	
	_order->addCloth(cloth);
}

double Customer::getOrderTotalPrice()
{
	return _order->getTotalPrice();
	
}

bool Customer::isPointEnough()
{
	if (_point >= _order->getTotalPrice())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Customer::reducePointFromOrder()
{
	_point -= _order->getTotalPrice();
}

void Customer::cancelOrder()
{
	delete _order;
	 _order = nullptr;
}

Order* Customer::getCurrentOrder()
{

	return _order;
}
