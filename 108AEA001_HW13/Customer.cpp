#include "Customer.h"
#include "Order.h"
#include "Shop.h"
#include <vector>
Customer::Customer(string name)
{
	_name = name;
	//vector<Order*> *_orders = new vector<Order*>;
}

string Customer::getName()
{
	return _name;
}

double Customer::getCash()
{
	return _point;
}

void Customer::makeNewOrder(Shop * shop)
{
	//_orders.pop_back();
	_orders.push_back(new Order(shop));
	
	//_orders = new Order(shop);
}

void Customer::addClothToOrder(Cloth * cloth)
{
	this->getCurrentOrder()->addCloth(cloth);
	//this->addCloth
}

double Customer::getOrderTotalPrice()
{
	return this->getCurrentOrder()->getTotalPrice();
}

bool Customer::isPointEnough()
{
	if (_point - getOrderTotalPrice() > 0) 
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
	_point = _point - getOrderTotalPrice();
	//delete this->getCurrentOrder();
	//Order * back = this->getCurrentOrder();
	//_orders.back() = NULL;
}

void Customer::cancelOrder()
{
	delete this->getCurrentOrder();
	//Order * back = this->getCurrentOrder();
	//_orders.back() = NULL;
}

Order * Customer::getCurrentOrder()
{
	return _orders.back();
}

vector<Order*>* Customer::getPurchasedHistoryFrom(Shop * shop)
{
	vector<Order*>::iterator it;
	vector<Cloth*>::iterator itC;
	vector<Order*> orderTemp = this->_orders;
	for (it = orderTemp.begin(); it != orderTemp.end(); it++)
	{
		
		vector<Cloth*>* getClothes=shop->GetClothes();
		vector<Cloth*> orderClothes = (*it)->getOrderClothes();
		if(orderClothes.size() != 0)
		{
			if ((*it)->getShop()->GetName() == shop->GetName() && (*it)->getTotalPrice() != 0)
			{
				orderHistory.push_back(*it);
				//return *it;
			}
		} 
	}
	return 	&orderHistory;
	;
}

