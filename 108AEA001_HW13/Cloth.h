#ifndef  CLOTH_H
#define CLOTH_H
using namespace std;
#include <string>
#include <vector>
class Shop;

class Cloth
{
public:
	Cloth(string name, string description, double price);
	Cloth(string name, string description);
	Cloth();
	string GetName();
	string GetDecription();
	string GetInformation();
	double GetPrice();
	int GetId();


protected:
	string _name;
	string _description;
	static int _currentId;
	int _Id;
	double _price;
	
};

#endif // ! CLOTH.H