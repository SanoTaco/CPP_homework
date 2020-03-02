#ifndef  SHOP_H
#define SHOP_H
using namespace std;
#include <vector>

class Cloth;

class Shop 
{
public:
	Shop(string name);
	string GetName();
	void createNewCloth(string name, string description, double price);
	vector<Cloth*>* GetClothes();
	Cloth* findCloth(int id);
private:
	string _name;
	vector <Cloth*> _clothes;
};

#endif // ! SHOP_H