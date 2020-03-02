#include "Suite.h"
#include "Cloth.h"
#include <vector>




void Suite::add(Cloth *cloth)
{
	_clothes.push_back(cloth);
}

double Suite::GetPrice()
{
	vector<Cloth*>::iterator it;
	for (it = _clothes.begin(); it != _clothes.end(); it++)
		_priceTemp += (*it)->GetPrice();
	return _priceTemp*0.9;
}
