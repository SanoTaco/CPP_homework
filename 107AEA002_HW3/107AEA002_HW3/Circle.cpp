#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;
Circle::Circle()  // default  constructor 
{

}

double Circle::CalculateArea() //calculate area  and I set pi = 3.14
{
	return _radius * _radius * 3.14;
}

double Circle::CalculateCircumference()//calculate circumference  by pi = 3.14
{
	return 2 * _radius * 3.14;
}
double Circle::CalculateDiameter()//calculate diameter by pi = 3.14
{
	return 2 * _radius;
}

double Circle::GetRadius()//
{
	return _radius;
}
bool Circle::CheckInput(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int temp = (int)str[i];
		if (str[0] == 46)//fool proof  If only input  a dot ,take it as an invalid state
		{
			return false;
		}
		if((temp>=48 && temp <=57 )||temp == 46)
		{
			continue;// check every simple character in string array by ASCII and the number from 48 to 57 represent number 0 - 9
					 // and the 46 th represent dot 
		}
		else
		{
			return false;// imply the string contains letters 
		}
	}
	return true;
}
void Circle::SetRadius()
{
	while (true)
	{
		string radius;
		cout << "Please enter the radius of the circle :";
		cin >> radius;
		if (CheckInput(radius) == false)//fool proof
		{
			cout << "Input Error , Please Enter Again!" << endl;
			cin.clear();

		}
		else if (cin.fail())//fool proof
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input Error , Please Enter Again!" << endl;
			
		}
		else 
		{
			_radius = stod(radius);//transform string variable into double
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		
	}
	
	
		
		
	
	
	
}
void Circle::GetInformation()
{
	cout << "The Diameter Of The Circle Is :" << CalculateDiameter() << endl;
	cout << "The Circumference Of The Circle Is :" << CalculateCircumference() << endl;
	cout << "The Area Of The Circle is :" << CalculateArea() << endl;

}