/* 107AEA002_HW5  107AEA002 張育祿 二技陸生
自UI讀入一連串的數字，從這些數字中找出中位數(median)，列印至螢幕。



*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#include "Median.h"




int main() 
{
	Median median;
	median.Insert();
	cout << "中位數：" << median.ShowMedian() << endl;

	system("pause");
	return 0;

}