#include <string>
#include <iostream>


using namespace std;

#include "ComplexNumbers.h"


ComplexNumbers::ComplexNumbers(double realPart, double imaginaryPart)
{
	_realNumber = realPart;
	_imagineNumber = imaginaryPart;
}

ostream& operator<<(ostream& outputstream, ComplexNumbers& rhs)
{
	outputstream << "(" << rhs._realNumber << " " << "+" << rhs._imagineNumber<<"i)" << endl;
	return outputstream;
}

istream& operator>>(istream& inputstrem, ComplexNumbers& rhs)
{
	double real, imagine;
	inputstrem >> real;
	inputstrem.ignore(256,',');
	inputstrem >> imagine;
	if (inputstrem.good())
	{
		rhs._realNumber = real;
		rhs._imagineNumber = imagine;
	}

	return inputstrem;

}

ComplexNumbers& operator*(ComplexNumbers& lhs, ComplexNumbers& rhs)
{
	double realNumber = ((lhs._realNumber * rhs._realNumber) - (lhs._imagineNumber*rhs._imagineNumber));
	double imagineNumber = ((lhs._realNumber*rhs._imagineNumber) + (lhs._imagineNumber * rhs._realNumber));
	ComplexNumbers result(realNumber, imagineNumber);
	return result;
}
