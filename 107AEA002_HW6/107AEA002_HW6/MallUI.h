#ifndef UI_H
#define UI_H

class Shop;
class Mall;
class MallUI
{
public:
	MallUI( Mall* mall);
	void run();
	void ErrorChoice(int number);
	void ErrorNumber();
	void ErrorLoading();
	bool CheckChoice(int num);
	bool CheckNumber(double price);
	bool CheckInput(string str);

private:
	Mall* _mall;
	void AddNewCloth();
	void ShopMenu(int choice);
	void showMenu();
	void InputShop(int &choice);
	void showAllCloth();
	void Exit();
};





#endif // !UI_H
