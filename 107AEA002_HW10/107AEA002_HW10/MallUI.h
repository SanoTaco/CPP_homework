#ifndef UI_H
#define UI_H

class Shop;
class Mall;
class MallUI
{
public:
	MallUI( Mall* mall);
	void showCustomer();
	void run();
	void ErrorChoice(int number);
	void ErrorNumber();
	void ErrorLoading();
	bool CheckChoice(int &num);
	bool CheckNumber(double price);
	bool CheckInput(string str);
	void selectCustomerAndShop();
	

private:
	Mall* _mall;
	void AddNewCloth();
	void ShopMenu(int customerIndex,int choice);
	void showMenu(int customerIndex);
	void InputShop(int &choice);
	void showAllCloth();
	void Exit();
	void endOrder();
	void buyClothes(int chosenShop);
	void getRemainPoints(int index);
	void getCurrentOrder();
	void makeNewOrder();



};





#endif // !UI_H
