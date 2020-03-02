#ifndef CUSTOMER_H
#define CUSTOMRER_H
class Shop;
class Cloth;
class Order;
class Customer
{
public:
	Customer(string str);
	~Customer();
	string getName();
	double getCash();
	void makeNewOrder(Shop *shop);
	void addClothToOrder(Cloth* cloth);
	double getOrderTotalPrice();
	bool isPointEnough();
	void reducePointFromOrder();
	void cancelOrder();
	Order* getCurrentOrder();

private:
	string _name;
	double _point;
	Order* _order;
	Cloth* _cloth;











};



















#endif // !CUSTOMER_H
