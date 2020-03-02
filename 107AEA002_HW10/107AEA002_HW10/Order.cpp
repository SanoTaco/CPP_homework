#include <iostream>
#include <vector>	
#include <string>

using namespace std;
#include "Shop.h"
#include "Cloth.h"
#include "Order.h"



Order:: Order(Shop* shop)
{
	_shop = shop;
}

Shop* Order::getShop()
{
	return _shop;
}

void Order::addCloth(Cloth * clothToAdd)
{
	_orderedClothes.push_back(clothToAdd);
	
}

double Order::getTotalPrice()
{
	double price = 0;
	for (size_t i = 0; i != _orderedClothes.size(); i++)
	{
		price += _orderedClothes[i]->getPrice();
	}
	return price;
}


