#ifndef ORDER_H
#define ORDER_H
class Cloth;
class Shop;
class Order
{
public:
	Order(Shop* shop);
	Shop* getShop();
	void addCloth(Cloth* clothToAdd);
	double getTotalPrice();
private:
	vector<Cloth*> _orderedClothes;
	Shop* _shop;
	double _totalPrice;










};











#endif // !ORDER_H
