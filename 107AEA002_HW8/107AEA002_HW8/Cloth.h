#ifndef CLOTH_H
#define CLOTH_H

class Cloth
{
public:
	Cloth(string name, string description, double price);
	string getName();
	string getDiscription();
	string getInformation();
	double getPrice();
	int getId();
	~Cloth();

private:
	string _name;
	string _description;
	double _price;
	static int _id ;
};






#endif // ! CLOTH_H
