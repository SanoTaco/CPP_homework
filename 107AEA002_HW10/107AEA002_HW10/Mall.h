#ifndef  MALL_H
#define  MALL_H
#include <vector>
class Shop;
class Cloth;
class Order;
class Customer;
class Mall
{
public:
	Mall();
	~Mall();
	void createNewCloth(string name, string description, double price);
	void selectShop(int shopIndex);
	vector<Cloth*>* getClothes();
	vector<Shop*>* getShops();
	string getShopName(int shopId);
	vector<Customer*>* getCustomer();
	void makeNewOrder();
	void addClothToOrder(int id);
	void selectCustomerAndShop(int customerIndex, int shopIndex);
	bool isPointEnough();
	void reducePointFromOrder();
	void cancelOrder();
	Order* getCurrentOrder();
	string showCustomers(int customerIndex);
	int customerNumbers();
	double getRemainPoint(int index);
	double getCurrentPaid();
private:
	int _shopIndex;
	int _customerIndex;
	vector<Customer*> _customers;
	vector<Shop*> _shops;
	void load();
	
	


};




#endif // ! MALL_H
