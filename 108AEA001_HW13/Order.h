#ifndef ORDER_H
#define ORDER_H
using namespace std;
#include <vector>
#include <map>
class Cloth;
class Shop;
class Customer;
class Order
{
public:
	Order(Shop* shop);
	Shop* getShop();
	void addCloth(Cloth* clothToAdd);
	double getTotalPrice();
	vector<Cloth*> getOrderClothes();
private:
	Shop* _shop;
	vector<Cloth*> _orderedClothes;
	double _totalPrice;
};
#endif // !ORDER_H
