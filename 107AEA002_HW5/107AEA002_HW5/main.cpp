/* 107AEA002_HW5  107AEA002 ������ �������
��UI�x��һ�B���Ĕ��֣����@Щ�������ҳ���λ��(median)����ӡ��ΞĻ��



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
	cout << "��λ����" << median.ShowMedian() << endl;

	system("pause");
	return 0;

}