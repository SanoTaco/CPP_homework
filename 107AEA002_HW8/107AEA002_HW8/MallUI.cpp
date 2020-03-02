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
void MallUI::run()
{
	showMenu();
}
void MallUI::Exit()
{
	cout << "Bye Bye!" << endl;
	system("pause");
	exit(0);
}
void MallUI::showMenu()
{
	while (1)
	{
		for (size_t i = 0; i < _mall->getShops()->size(); i++)
		{
			cout << i + 1 << "." << _mall->getShops()->at(i)->getName() << endl;
		}
		//cout << _mall->getShops()->size() + 1 << "." << "Exit Program" << endl;
		cout << "Select Shop：";
		int choice;
		
		InputShop(choice);
		
		
		
			cout << endl;
			int j = choice - 1;
			_mall->selectShop(j);// selec shop
			ShopMenu(j);
		


	}
}
void MallUI::ShopMenu(int choice)
{
	
	while (choice!=3)
	{
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "1.Add new clothes" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "2.Check all clothes" << endl;
		cout << "(" << _mall->getShops()->at(choice)->getName() << ")" << "3.Back to the Mall" << endl;
		
		cin >> choice;
		if (CheckChoice(choice) == false)
		{
			ErrorChoice(choice);
			
		}
		else
		{
			if (choice == 1)
			{
				AddNewCloth();
			}
			else if (choice == 2)
			{
				showAllCloth();
				
			}
			else if (choice == 3)
			{
				
				
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

		if (!(choice >= 1 && choice <= 3))
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
bool MallUI::CheckChoice(int num)
{
	if (num < 1 || num >3)
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