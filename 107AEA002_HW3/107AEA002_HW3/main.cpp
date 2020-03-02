/*
107AEA002_HW3    107AEA002  Zhang Yulu  ¶þ¼¼ê‘Éú
Define a class for a type called Circle. An object of type Circle is used to display
the area, diameter, and circumference of a circle based on the radius of that object.
Include a mutator function that sets the radius to a value given as an argument.
Include member function to calculate the area, diameter, and circumference of the
circle. Also include a member function that returns the radius of the circle. Embed
your class definition in a test program.
*/
#include <iostream>	
#include "Circle.h"

using namespace std;

int main()
{
	Circle circle;//declaration of the objecy
	circle.SetRadius();//set radius 
	circle.GetInformation();//function contains the calculation of diameter area and so on 


	system("pause");
	return 0;
}