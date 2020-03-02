/*
this is a MallUI class it contains cin and cout opreations 


*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#include "MallUI.h"
#include "Shop.h"
#include "Cloth.h"
#include "Mall.h"
class Mall;
MallUI::MallUI(Mall* mall)
{
	_mall = mall;
}
void MallUI::showCustomer()
{
	for (size_t i = 0; i < _mall->customerNumbers(); i++)
	{
		cout << i+1 <<"."<< _mall->showCustomers(i) << endl;
	}
	cout << _mall->customerNumbers() + 1 << "." << "Exit program" << endl;
}
void MallUI::run()
{
	selectCustomerAndShop();
}
void MallUI::Exit()
{
	cout << "Bye Bye!" << endl;
	system("pause");
	exit(0);
}

void MallUI::endOrder()
{
	if (_mall->getCurrentOrder() == nullptr)
	{
		cout << "Please create an Order first !" << endl;
	}
	else if(_mall->isPointEnough())
	{
		_mall->reducePointFromOrder();
		cout << "Order ends successfully!!!" << endl;
	}
	else
	{
		_mall->cancelOrder();
		cout << "lack of points , unable to purchase!" << endl;
	}
}
void InputQuantity(int& quantity)
{
	do
	{
		while (!(cin >> quantity))
		{
			
			cout << "Please enter valid numbers: ";

		}
		if (quantity < 1)
		{
			cout << "Please enter valid numbers:";
		}

		if (cin.rdbuf()->in_avail() >= 2)
		{
			
			quantity = 0;
			cout << "Please enter valid numbers: ";

		}
	} while (quantity < 1);
}
void MallUI::buyClothes(int chosenShop)
{
	if (_mall->getCurrentOrder() == NULL)
	{
		cout << "Create new Orders to buy clothes" << endl << endl;
	}
	else
	{
		
		vector <Cloth*>* result = _mall->getShops()->at(chosenShop)->getClothes(); //use vector to get all loaded clothes , a copy of vector 
		vector <Cloth*>::iterator it;
		cout << std::left << setw(5) << "NO." << std::left << setw(50) << "Name" << std::left << setw(20) << "Price" << std::left << setw(100) << "Description" << endl;
		for (it = result->begin(); it != result->end(); it++)
		{
			cout << std::left << setw(5) << (*(*it)).getId() << std::left << setw(50) << (*(*it)).getName() << std::left << setw(20) << (*(*it)).getPrice() << std::left << setw(100) << (*(*it)).getDiscription() << endl;
		}

		int choice;
		int quantity;
		while (1)
		{
			cout << "Enter ID of clothes , enter -1 to leave: ";
			cin >> choice;
			if (choice == -1)
			{
				break;
			}
			else
			{

				cout << "enter the number you want to buy： " << endl;
				InputQuantity(quantity);
				for (size_t i = 0; i < quantity; i++)
				{
					_mall->addClothToOrder(choice);
				}


			}

		}
	}
	
}
void MallUI::getRemainPoints(int index)
{
	
	cout << "You have :" << _mall->getRemainPoint(index) << "left" << endl;
}
void MallUI::getCurrentOrder()
{
	if (_mall->getCurrentOrder() == nullptr)
	{
		cout << "You dont have any Order yet" << endl;
	}
	else
	{
		
		cout << "Your recent Order costs :" << " " << endl;
	}
}
void MallUI::makeNewOrder()
{
	if (_mall->getCurrentOrder() == NULL)
	{
		_mall->makeNewOrder();
		cout << "Create new Order successfully!" << endl << endl;
	}
	else
	{
		cout << "You already have an Order!!!" << endl;

	}
}
void MallUI::showMenu(int customerIndex)
{
	
	
	while (1)
	{
		for (size_t i = 0; i < _mall->getShops()->size(); i++)
		{
			cout << i + 1 << "." << _mall->getShops()->at(i)->getName() << endl;
		}
		
		cout << "Select Shop：";
		int choice;
		InputShop(choice);
		cout << endl;
		int chosenShop = choice-1 ;
		
		_mall->selectCustomerAndShop(customerIndex, chosenShop);
		cout << "Dear customer :" << _mall->showCustomers(customerIndex) << "  Welcome!" << endl;
		
		ShopMenu(customerIndex,chosenShop);
	}
}
void MallUI::ShopMenu(int customerIndex,int choice)
{
	int selectedNumber=0;
	while (selectedNumber != 8)
	{
		
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "1.Add new clothes" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "2.Check all clothes" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "3.Create new Order" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "4.Buy clothes" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "5. End the Order" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "6.Check remain points" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "7.Check history recipt" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "8.Back" << endl;
		
		cin >> selectedNumber;
		if (CheckChoice(selectedNumber) == false)
		{
			ErrorChoice(selectedNumber);
			
		}
		else
		{
			switch (selectedNumber)
			{
			case 1:
				
				AddNewCloth();
				break;

			case 2:
				
				showAllCloth();
				break;

			case 3:
				
				makeNewOrder();
				break;

			case 4:
				
				buyClothes(choice);
				break;

			case 5:
				
				endOrder();
				break;
			case 6:
				
				getRemainPoints(customerIndex);
				break;
			case 7:
				
				getCurrentOrder();
				break;

			case 8:
				
				break;

			default:
				break;
			}
			
			
		}
	}
}
void MallUI::showAllCloth()
{
	vector <Cloth*> result = *(_mall->getClothes()); //use vector to get all loaded clothes , a copy of vector 
	vector <Cloth*>::iterator it;
	cout << std::left << setw(5) << "NO." << std::left << setw(50) << "Name" << std::left << setw(20) << "Price" << std::left << setw(100) << "Description" << endl;
	for (it = result.begin(); it != result.end(); it++)
	{
		cout << std::left << setw(5) << (*(*it)).getId() << std::left << setw(50) << (*(*it)).getName() << std::left << setw(20) << (*(*it)).getPrice() << std::left << setw(100) << (*(*it)).getDiscription() << endl;
	}
}
bool CheckInput(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int temp = (int)str[i];
		if (str[0] == 46)//fool proof  If only input  a dot ,take it as an invalid state
		{
			return false;
		}
		if ((temp >= 48 && temp <= 57) || temp == 46)
		{
			continue;// check every simple character in string array by ASCII and the number from 48 to 57 represent number 0 - 9
					 // and the 46 th represent dot 
		}
		else
		{
			return false;// imply the string contains letters 
		}
	}
	return true;
}
void ClearCinBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void MallUI::InputShop(int& choice)
{
	do
	{
		while (!(cin >> choice))
		{
			ClearCinBuffer();
			cout << "Please Select shops above：";

		}

		int flag = 1;

		if (!(choice >= 1 && choice <= 8))
		{
			cout << "Please Select shops above：：";
			flag = 0;
			choice = -1;
		}

		if (cin.rdbuf()->in_avail() >= 2)
		{
			ClearCinBuffer();
			choice = -1;

			if (flag == 1)
			{
				cout << "Please Select shops above：：";

			}
		}
	} while (choice < 0);
}
void InputId(int &clothId)
{
	int id;
	while (true)
	{
		cout << "Please input id of clothes" << endl;
		cin >> id;
		if (id <= 0)
		{
			cout << "Please input valid id" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			clothId = id;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

}
void InputPrice(double &clothPrice)
{
	while (true)
	{
		string input;
		cout << "Pliease input the price of clothes:";
		cin >> input;
		if (CheckInput(input) == false)//fool proof
		{
			cout << "Input Error , Please Enter Again!" << endl;
			cin.clear();

		}
		else if (cin.fail())//fool proof
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input Error , Please Enter Again!" << endl;

		}
		else
		{
			clothPrice = stod(input);//transform string variable into double
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

	}

}

void MallUI::AddNewCloth()
{
	string clothName, clothDes;
	double clothPrice=0;
	int clothId=0;
	while (true)
	{
		cout << "Please input the name of clothes" << endl;
		cin >> clothName;
		cin.clear();
		cout << "Please input description of clothes " << endl;
		cin >> clothDes;
		cin.clear();
		InputId(clothId);
		InputPrice(clothPrice);
		_mall->createNewCloth(clothName, clothDes, clothPrice);
		break;
		

	}
}
void MallUI::ErrorChoice(int number)
{
	if (CheckChoice(number) == false)
	{
		cout << "Please input correct choice！" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
}
void MallUI::ErrorNumber()
{
	cout << "Please input correct number！" << endl;
}
void MallUI::ErrorLoading()
{
	cout << "Loading data Error!" << endl;
}
bool MallUI::CheckChoice(int &num)
{
	if (num < 1 || num >8)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool MallUI::CheckNumber(double price)
{
	if (price < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void MallUI::selectCustomerAndShop()
{
	int customerId;
	showCustomer();
	cout << "Please select customer : " << endl;
	cin >> customerId;
	if (customerId == 4)
	{
		Exit();
	}
	else
	{
		customerId -= 1;
		showMenu(customerId);
	}
	

}

