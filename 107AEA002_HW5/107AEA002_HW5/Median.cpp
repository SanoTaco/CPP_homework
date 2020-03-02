#include <iostream>
#include <vector>
#include <string> 
#include <sstream>
#include <algorithm>

using namespace std;

#include "Median.h"


Median::Median()
{
	
}
bool Check(string str)// valid return true else return false
{
	for (unsigned int i = 0; i < (str.size()); i++)
	{
		
		int temp = (int)str[i];
		if (i < str.size() && (int)str[i] == 46 && (int)str[i + 1] == 46) // write dot twice is invlaid
		{
			return false;
		}

		if (str[0] == 46)//fool proof  If only input  a dot ,take it as an invalid state
		{
			return false;
		}
		
		if ((temp >= 48 && temp <= 57) || temp == 46 || temp == 32)
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

void Split(const std::string& src, const std::string& separator, std::vector<std::string>& dest) //字符串分割到数组
{

	

	string str = src; //input string
	string substring;
	string::size_type start = 0, index;
	dest.clear();
	index = str.find_first_of(separator, start);
	do
	{
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = index + separator.size();
			index = str.find(separator, start);
			if (start == string::npos) break;
		}
	} while (index != string::npos);

	//the last part
	substring = str.substr(start);
	dest.push_back(substring);
}
void Median::Insert()
{
	string input; //use string to store input number and do fool proof
	while (true)
	{
		cout << "請輸入一串多組數字：" << endl;
		getline(cin,input);// get cin data
		if (Check(input) == false)
		{
			cout << "輸入資料有誤！" << endl;
			input.clear();
			_input.clear();
			_numbers.clear();
		}
		else if(Check(input)==true)
		{
			vector<string>::iterator it;
			Split(input, " ", _input);
			for (it = _input.begin(); it != _input.end(); it++)
			{
				
				_numbers.push_back(stod(*it));
			}
			
			sort(_numbers.begin(), _numbers.end());
			break;
			
		}
		
	}
	
	
}


double Median::ShowMedian()
{
	
	if (_numbers.size() % 2 == 0)
	{
		int a, b;
		a = _numbers.size() / 2;
		b = a - 1;
		_median = (_numbers[a] + _numbers[b])/2;

	}
	else
	{
		int a = (_numbers.size() - 1) /2;
		_median = _numbers[a];
	}
	return _median;
}