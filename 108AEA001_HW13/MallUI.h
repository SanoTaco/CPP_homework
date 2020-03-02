#ifndef  MALLUI_H
#define MALLUI_H
#include <vector>
#include <map>
#include "Mall.h"
class Mall;
class Order;

class MallUI
{
public:
	MallUI(Mall *mall);
	void start();
private:
	Mall _mall;
	map<string, int> mapCount;
	void AddClothes(int shopIndex, int customerIndex);
	void ViewClothes();
	void switchClothes(int shopIndex, int customerIndex);
	void ShopMenu(int customerIndex);
	void CustomerMenu();
	void ClothesOperaion(int shopIndex, int customerIndex);
	bool JudgeNumber(const string &token);
	void AddClothToOrder(int shopIndex, int customerIndex);
	void CloseOrder(int shopIndex, int customerIndex);
	void MakeNewOrder(int shopIndex, int customerIndex);
	void GetCash(int shopIndex, int customerIndex);
	void GetHistory(int shopIndex, int customerIndex);
	void CountCloth(vector<Cloth*> &temp);
	void SortClothAndOutput(vector<Cloth*> &temp);
	bool flag=false;
};
#endif // ! MALLUI_H

