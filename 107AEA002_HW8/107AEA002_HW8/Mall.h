#ifndef  MALL_H
#define  MALL_H
#include <vector>
class Shop;
class Cloth;
class Mall
{
public:
	Mall();
	~Mall();
	void createNewCloth(string name, string description, double price);
	void selectShop(int shopIndex);
	//vector<Cloth*>* getClothes();
	//vector<Shop*>* getShops();
	vector<Cloth*>* getClothes();
	vector<Shop*>* getShops();
private:
	int _shopIndex;
	
	vector<Shop*> _shops;
	void load();



};




#endif // ! MALL_H
