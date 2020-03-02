#ifndef SHOP_H
#define SHOP_H
#include <vector>
class Cloth;
class Shop
{
public:
	Shop(string name);
	string getName();
	void CreateNewCloth(string name, string description, double price);
	vector <Cloth*>* getClothes();
	//void Load();
	~Shop();

	Cloth* findCloth(int id);



private:	
	string _name;
	vector<Cloth* > _cloth;
	

};










#endif // ! SHOP_H
