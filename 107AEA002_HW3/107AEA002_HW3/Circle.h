#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	Circle();// default constructor
	double CalculateArea();//calculations
	double CalculateDiameter();
	double CalculateCircumference();
	void SetRadius();//ste radius 
	double GetRadius();
	void GetInformation();//after input radius ,you will see the other calculated outputs
	bool CheckInput(std::string str);//check inputs if they are not pure numbers , return false 
private:
	double  _radius;



	
};






#endif // !CIRCLE_H
