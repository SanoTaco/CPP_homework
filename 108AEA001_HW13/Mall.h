#ifndef  MALL_H
#define MALL_H
using namespace std;
#include <vector>
#include <map>
#include "Cloth.h"
class Cloth;
class Shop;
class Order;
class Customer;

class Mall 
{
public:
	Mall();
	void createNewCloth(string name, string description, double price);
	vector<Cloth*>* GetClothes();
	vector<Shop*>* GetShops();
	vector<Customer*>* GetCustomers();
	void makeNewOrder();
	void addClothToOrder(int id);
	void selectCustomerAndShop(int customerIndex, int shopIndex);
	bool isPointEnough();
	void reducePointFromOrder();
	void cancelOrder();
	Order* getCurrentOrder();
private:
	int _shopIndex;
	int _customerIndex;
	map<int, Cloth> mapClothes;
	vector <Shop*> _shops;
	vector <Customer*> _customers;
	string _txtLocation;
	void ReadFromTxt(string txtLocation);
	void AddClothes(string line, int i);
	int AddShops(string line, int i);
	void GetLine(fstream &inputStream, string line, int i);
	void NonSuite(string lineTemp, int i, int iValue);
	void ConfirmSuite(string lineTemp, int i, string::size_type idx);
	void CountSuite(int num, string name, string description, string lineNumber, int i);
};
#endif // ! MALL_H
