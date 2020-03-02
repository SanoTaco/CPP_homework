#ifndef  SUITE_H
#define SUITE_H
using namespace std;
#include <string>
#include <vector>
#include "Cloth.h"

class Suite : public Cloth
{
public:
	Suite(string name, string description) :Cloth(name, description) {}
	Suite() {}
	void add(Cloth*);
	double GetPrice();
private:
	vector <Cloth*> _clothes;
	double _priceTemp;
};

#endif // ! SUITE_H