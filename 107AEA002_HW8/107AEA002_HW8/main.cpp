/* 107AEA002_HW6  二技陸生 張育祿
本次作業是 關於衣服商店的OOP程式，未來還會繼續擴充



*/


#include <iostream>
using namespace std;
#include "MallUI.h"
#include "Mall.h"
#include "Shop.h"

int main()
{
	Mall mall;
	MallUI uiSystem(&mall);
	uiSystem.run();
	
	system("pause");
	return 0;
}