#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "GasPump.h"


 GasPump::GasPump(double gallonPrice)
{
	 _gallonPrice = gallonPrice;
	 
}
 GasPump::GasPump()
 {
	 _gallonPrice = -1;//init variable , -1 represent this variable has not been changed yet , it is used to do fool proof 
	 
 }
 bool GasPump::CheckInput(string str)
 {
	 for (unsigned int i = 0; i < str.length(); i++)
	 {
		 int temp = (int)str[i];
		 if (str[0] == 46)//fool proof  If only input  a dot ,take it as an invalid state
		 {
			 return false;
		 }
		 if ((temp >= 48 && temp <= 57) || temp == 46)
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
 void GasPump::SetPrice()
 {
	 
	 while (true)
	 {
		 string price;
		 cout << "Ոݔ��1�Ӂ��ăr��";
		 cin >> price;
		 if (CheckInput(price) == false)//fool proof
		 {
			 cout << "�oЧݔ��!\n" << endl;
			 cin.clear();
			 break;
		 }
		 else if (cin.fail())//fool proof
		 {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout << "�oЧݔ��!\n" << endl;
			 break;
		 }
		 else
		 {
			 _gallonPrice = stod(price);
			 GasPump(stod(price));//transform string variable into double
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 break;
		 }

	 }
 }
 void GasPump::ShowPresentPrice()//show price
 {
	 if (_gallonPrice == -1)
	 {
		 cout << "Ո���O���̓r��\n" << endl;
	 }
	 else
	 {
		 cout << "Ŀǰ�~�̓r�飺ÿ�Ӂ���" << GetGallonPrice() << "Ԫ ,ÿ������ " << GetLiterPrice() << "Ԫ\n" << endl;
	 }
 }
 double GasPump::GetGallonPrice()
 {
	 return _gallonPrice;	 
 }
 double GasPump::GetLiterPrice()
 {
	 return _gallonPrice / 3.785411784;
 }
 double GasPump::GetAmountDispense() // return the cost of last time
 {
	 if (infomation.empty())
	 {
		 return 0;
	 }
	 else
	 {
		 int order = infomation.size()-1;
		 string lastPrice = infomation[order];
		 return stod(lastPrice);
	 }
	
 }
 double GasPump::GetAmountCharged() // return the volumn of last time
 {
	 if (infomation.empty())
	 {
		 return 0;
	 }
	 else
	 {
		 int order = infomation.size() - 2;
		 string lastAmount = infomation[order];
		 return stod(lastAmount);
	 }
	
 }
 vector<string> GasPump::Start(int amountLiter)
 {
	 for (int i = 0; i < amountLiter; i++)
	 {
		 cout << "Ŀǰ���� " << i + 1 << "������" << endl;

	 }
	 infomation.push_back(to_string(amountLiter));
	 infomation.push_back(to_string(GetLiterPrice()*amountLiter));
	 cout << "�� " << amountLiter << "������" << GetLiterPrice()*amountLiter << "Ԫ\n"<<endl;


	 return infomation;
 }

 void GasPump::Pump()
 {
	 if (_gallonPrice == -1)
	 {
		 cout << "Ո���O���̓r��" << endl;
	 }
	 else
	 {
		 cout << "Ոݔ��Ҫ�Ӽ��������ͣ�";
		 int liter;
		 cin >> liter;
		 if (liter < 0)
		 {
			 cout << "Ոݔ�����_�Ĕ��֣�" << endl;
		 }
		 else
		 {

			 _amountCharged = liter;
			 Start(liter);
		 }
	 }
	

 }
 void GasPump::ShowLastInfomation()
 {
	 if (_gallonPrice == -1)
	 {
		 cout << "Ո���O���̓r��" << endl;
	 }
	 else
	 {
		 cout << GetAmountCharged() << "������ " << GetAmountDispense() << " Ԫ" << endl;

	 }
 }
 void GasPump::Console()
 {
	 while (true)
	 {
		 cout << "1" << ".�O���̓r" << endl;//setprice
		 cout << "2" << ".�@ʾĿǰ���̓r" << endl;//show present price
		 cout << "3" << ".�@ʾ��һ�μ��͵��YӍ" << endl; //get amount dispense
		 cout << "4" << ".�_ʼ����" << endl;// pump
		 cout << "5" << ".�Y��" << endl;
		 cout << "Ոݔ��ָ�" << endl;
		 int order;

		 cin >> order;
		
		 if (order == 1 || order == 2 || order == 3 || order == 4 || order == 5)
		 {
			 switch (order)
			 {
			 case 1:
				 SetPrice();
				 break;
			 case 2:
				 ShowPresentPrice();
				 break;
			 case 3:
				 ShowLastInfomation();
				 break;
			 case 4:
				 Pump();
				 break;
			 case 5:
				 infomation.clear();
				 exit(1);
				 break;
			 default:
				 break;
			 }
		 }
		 else
		 {
			 cout << "�oЧݔ�룡" << endl;
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');

		 }
		 
	 }

 }
 