#include <iostream>
#include <string>
using namespace std;

#include "TextUI.h"
#include "ComplexNumbers.h"

TextUI::TextUI()
{
	ComplexNumbers compA(0, 0);// DEFAULT complex numbers
	ComplexNumbers compB(0, 0);
	cout << "input complex number 1:";
	cin >> compA;
	cout << "input complex number 2:";
	cin >> compB;
	ComplexNumbers multi(compA*compB);//copy constructor 
	cout << "Multi:" << multi << endl;
}
