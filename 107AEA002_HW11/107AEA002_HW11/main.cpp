/*107AEA002 HW11 張育祿 二技陸生
class of subscriber , an exercise intended to use new and delete 



*/




#include <iostream>
#include <string>

using namespace std;


#include "Subscriber.h"
#include "UI.h"




int main()
{
	string name = "00 subscriber";
	Subscriber subscriber(name);
	UI ui(&subscriber);
	ui.Run();




	system("pause");
	return 0;







}