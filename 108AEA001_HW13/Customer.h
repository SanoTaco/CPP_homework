#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;
#include <string>
#include <vector>
class Cloth;
class Shop;
class Order;

class Customer 
{
public:
	Customer(string name);
	string getName();
	double getCash();
	void makeNewOrder(Shop *shop);
	void addClothToOrder(Cloth *cloth);
	double getOrderTotalPrice();
	bool isPointEnough();
	void reducePointFromOrder();
	void cancelOrder();
	vector<Order*>* getPurchasedHistoryFrom(Shop *shop);
	Order* getCurrentOrder();
private:
	string _name;
	double _point = 2000;
	vector<Order*> _orders;
	vector<Order*> orderHistory;
	int flag;
};
#endif // !CUSTOMER_H

