#include <iostream> 
#include <iomanip>
#include <fstream>
#include <regex>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include<algorithm>
using namespace std;
#include "MallUI.h"
#include "Cloth.h"
#include "Shop.h"
#include "Customer.h"
#include "Order.h"
#include "Suite.h"

MallUI::MallUI(Mall * mall)
{
	_mall = *mall; 
}

void MallUI::start()
{
	CustomerMenu();
}

void MallUI::CustomerMenu()
{
	string options;

	int i = 1;
	cout << "1.Amber" << endl;
	cout << "2.Tim" << endl;
	cout << "3.Marry" << endl;
	cout << "4.Exit" << endl;
	cout << "Select Customer:";
	cin >> options;
	if (options == "1")
	{
		ShopMenu(1);
	}
	else if (options == "2")
	{
		ShopMenu(2);
	}
	else if (options == "3")
	{
		ShopMenu(3);

	}
	else if (options == "4")
	{
		exit(0);
	}
	else
	{
		cout << "Please select the shop on the screen." << endl;
		CustomerMenu();
	}
}

void MallUI::ShopMenu(int customerIndex)
{
	string options;
	int i = 1;
	vector<Shop*> _shop = *(_mall.GetShops());
	vector<Customer*> _customer = *(_mall.GetCustomers());
	vector<Shop*>::iterator it;
	string customerName = _customer.at(customerIndex - 1)->getName();
	for (it = _shop.begin(); it != _shop.end(); it++)
	{
		cout << i << "." << (*it)->GetName() << endl;
		i++;
	}
	cout << "Select Shop:";
	cin >> options;
	if (options == "1")
	{
		cout << "Dear Customer:" << customerName << ", Welcome!" << endl;
		_mall.selectCustomerAndShop(customerIndex, 1);
		ClothesOperaion(1, customerIndex);
	}
	else if (options == "2")
	{
		cout << "Dear Customer:" << customerName << ", Welcome!" << endl;
		_mall.selectCustomerAndShop(customerIndex, 2);
		ClothesOperaion(2, customerIndex);
	}
	else if (options == "3")
	{
		cout << "Dear Customer:" << customerName << ", Welcome!" << endl;
		_mall.selectCustomerAndShop(customerIndex, 3);
		ClothesOperaion(3, customerIndex);
	}
	else
	{
		cout << "Please select the shop on the screen." << endl;
		ShopMenu(customerIndex);
	}
}

void MallUI::ClothesOperaion(int shopIndex, int customerIndex)
{
	vector<Shop*> _shop = *(_mall.GetShops());
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "1. Add clothes" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "2. View all clothes" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "3. Create new order" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "4. Buy clothes" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "5. Close order" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "6. View remaining points" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "7. View historical receipts" << endl;
	cout << "(" << _shop.at(shopIndex - 1)->GetName() << ")" << "8. Leave" << endl;
	cout << "Please enter a option:";
	switchClothes(shopIndex, customerIndex);
}

void MallUI::switchClothes(int shopIndex, int customerIndex)
{
	string options;
	cin >> options;
	if (options == "1")
	{
		AddClothes(shopIndex, customerIndex);
	}
	else if (options == "2")
	{
		ViewClothes();
		ClothesOperaion(shopIndex, customerIndex);
	}
	else if (options == "3")
	{
		MakeNewOrder(shopIndex, customerIndex);
	}
	else if (options == "4")
	{
		AddClothToOrder(shopIndex, customerIndex);
	}
	else if (options == "5")
	{
		CloseOrder(shopIndex, customerIndex);
	}
	else if (options == "6")
	{
		GetCash(shopIndex, customerIndex);
	}
	else if (options == "7")
	{
		GetHistory(shopIndex, customerIndex);
		ClothesOperaion(shopIndex, customerIndex);
	}
	else if (options == "8")
	{
		CustomerMenu();
	}
	else
	{
		cout << "Please enter the correct option:";
		switchClothes(shopIndex, customerIndex);
	}
}

void MallUI::AddClothes(int shopIndex, int customerIndex)
{
	string name;
	string decrption;
	string str;
	string temp;
	double price;
	//getline(cin, str);
	cout << "Please enter the name:";
	//getline(cin, name);
	cin >> name;
	cout << "Please enter the decrption:";
	cin >> decrption;
	//getline(cin, decrption);
	cout << "Please enter the price:";
	cin >> temp;
	while (!JudgeNumber(temp))//Judge Price
	{
		cout << "The price cannot be less than or equal to 0, please re-enter" << endl;
		cout << "Please enter the price:";
		cin >> temp;
	}
	istringstream stream(temp);
	stream >> price;
	_mall.createNewCloth(name, decrption, price);
	ClothesOperaion(shopIndex, customerIndex);
}

bool MallUI::JudgeNumber(const string &token)
{
	return std::regex_match(token, regex("^0*[1-9][0-9]*(.[0-9]+)?|0+.[0-9]*[1-9][0-9]*$"));
}

void MallUI::ViewClothes()
{
	vector<Cloth*>_clothes = *(_mall.GetClothes());
	vector<Cloth*>::iterator it;
	cout << left << setw(10) << "No." << setw(50) << "Name" << setw(120) << "Decrption" << "Price " << endl;
	for (it = _clothes.begin(); it != _clothes.end(); it++)
		cout << left << setw(10) << (*it)->GetId() << setw(50) << (*it)->GetName() << setw(120) << (*it)->GetDecription() << (*it)->GetPrice() << endl;
	cout << endl;
}

void MallUI::MakeNewOrder(int shopIndex, int customerIndex)
{
	_mall.makeNewOrder();
	cout << "New order successfully created!!!" << endl;
	flag = true;
	ClothesOperaion(shopIndex, customerIndex);
}

void MallUI::AddClothToOrder(int shopIndex, int customerIndex)
{
	vector<Customer*> _customer = *(_mall.GetCustomers());
	if (flag!=false)
	{
		ViewClothes();
		cout << "Please enter the clothes ID, if you wanna leave please enter - 1:";
		int id, number;
		cin >> id;
		if (id != -1)
		{
			cout << "Please enter the number of clothes:";
			cin >> number;
			for (int i = 0; i < number; i++)
			{
				_mall.addClothToOrder(id);
			}
			vector<Cloth*>_clothes = *(_mall.GetClothes());
			vector<Cloth*>::iterator it;
			AddClothToOrder(shopIndex, customerIndex);
		}
		else
		{
			ClothesOperaion(shopIndex, customerIndex);
		}
	}
	else
	{
		cout << "Please create an order to buy clothes!" << endl;
		ClothesOperaion(shopIndex, customerIndex);
	}
}

void MallUI::CloseOrder(int shopIndex, int customerIndex)
{
	vector<Customer*> _customer = *(_mall.GetCustomers());
	if (flag != false)
	{
		if (!_mall.isPointEnough())
		{
			cout << "There are not enough points left to buy!" << endl;
			_mall.cancelOrder();
			flag = false;
			ClothesOperaion(shopIndex, customerIndex);
		}
		else
		{
			_mall.reducePointFromOrder();
			cout << "Order closed successfully!" << endl;
			flag = false;
			ClothesOperaion(shopIndex, customerIndex);
		}
	}
	else
	{
		cout << "Please re-create the order after closing it!" << endl;
		ClothesOperaion(shopIndex, customerIndex);
	}
}

void MallUI::GetCash(int shopIndex, int customerIndex)
{
	vector<Customer*> _customer = *(_mall.GetCustomers());
	cout << "Your remaining points are:" << _customer.at(customerIndex - 1)->getCash() << endl;
	ClothesOperaion(shopIndex, customerIndex);
}

void MallUI::GetHistory(int shopIndex, int customerIndex)
{
	vector<Customer*> _customer = *(_mall.GetCustomers());
	vector<Shop*> _shop = *(_mall.GetShops());
	vector<Order*>* orderHistory = _customer.at(customerIndex - 1)->getPurchasedHistoryFrom(_shop.at(shopIndex - 1));
	vector<Order*>::iterator it;
	vector<Cloth*>::iterator itC;
	cout << left << setw(50) << "Name" << setw(30) << "Amount" << setw(30) << "Price" << "TotalPrice " << endl;
	for (it = (*orderHistory).begin(); it != (*orderHistory).end(); it++)
	{
		vector<Cloth*> _clothes = ((*it)->getOrderClothes());
		sort(_clothes.begin(), _clothes.end());
		CountCloth(_clothes);
		SortClothAndOutput(_clothes);
		cout << right << setw(110) << "TotalPrice:" << (*it)->getTotalPrice() << endl;
		cout << endl;
	}
}

void MallUI::CountCloth(vector<Cloth*> &temp)
{
	vector<Cloth*>::iterator itC;
	for (itC = temp.begin(); itC != temp.end(); itC++)
	{
		int my_count = std::count_if(temp.begin(), temp.end(),
			[&](Cloth *s) {
			return (*itC)->GetName() == (*s).GetName();
		});
		mapCount[(*itC)->GetName()] = my_count;
	}
}

void MallUI::SortClothAndOutput(vector<Cloth*>& temp)
{
	vector<Cloth*>::iterator itC;
	map<string, int>::iterator iter;
	itC = unique(temp.begin(), temp.end());
	temp.erase(itC, temp.end());
	for (itC = temp.begin(); itC != temp.end(); itC++)
	{
		iter = mapCount.find((*itC)->GetName());
		int count = iter->second;
		cout << left << setw(50) << (*itC)->GetName() << setw(30) << count << setw(30) << (*itC)->GetPrice() << (*itC)->GetPrice()*count << endl;
	}
}



