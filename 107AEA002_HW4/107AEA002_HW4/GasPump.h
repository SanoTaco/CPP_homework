#ifndef GASPUMP_H
#define GASPUMU_H
#include <vector>

class GasPump
{
public:
	
	GasPump();
	GasPump(double gallonPrice);
	void Console();
	void SetPrice();
	void Pump();//get ready to pump gas 加油前設定加油的量
	void ShowPresentPrice();
	void ShowLastInfomation();
	double GetLiterPrice();
	double GetGallonPrice();
	double GetAmountDispense();
	double GetAmountCharged();
	bool CheckInput(string str);
	vector <string> Start(int amountLter);
	
private:
	vector<string> infomation;
	double _gallonPrice = -1;
	int _amountCharged;
	

};















#endif