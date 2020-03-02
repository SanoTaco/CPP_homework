#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H
class ComplexNumbers
{
public:
	ComplexNumbers(double realPart, double imaginaryPart);
	friend ostream& operator <<(ostream& outputstream,ComplexNumbers& rhs);
	friend istream& operator >>(istream& inputstrem , ComplexNumbers& rhs);
	friend ComplexNumbers& operator *(ComplexNumbers& lhs, ComplexNumbers& rhs);


private:
	double _realNumber;
	double _imagineNumber;
};









#endif // !COMPLEXNUMBERS_H
