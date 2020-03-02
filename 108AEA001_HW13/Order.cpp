#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "Order.h"
#include "Cloth.h"

Order::Order(Shop * shop)
{
	_shop = shop;
}

Shop * Order::getShop()
{
	return _shop;
}

void Order::addCloth(Cloth * clothToAdd)
{
	_orderedClothes.push_back(clothToAdd);
}

double Order::getTotalPrice()
{
	_totalPrice = 0;
	vector<Cloth*>::iterator it;
	for (it = _orderedClothes.begin(); it != _orderedClothes.end(); it++)
	{
		_totalPrice = _totalPrice + (*it)->GetPrice();
	}
	return _totalPrice;
}

vector<Cloth*> Order::getOrderClothes()
{
	return _orderedClothes;
}

