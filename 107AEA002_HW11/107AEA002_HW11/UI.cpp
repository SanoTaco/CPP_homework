#include <iostream> 
#include <string>	

using namespace std;

#include "Subscriber.h"
#include "UI.h"

UI::UI(Subscriber * sub)
{
	_subscriber = sub;
}

void UI::EnterNameOfSubscriber(string names)
{
	_subscriber->Subscriber::Subscriber(names);
}

void UI::EnterNumbersOfChannels(int numbers)
{
	_subscriber->SetNumberChannel(numbers);
}

void UI::ShowChannels()
{
	string* s;
	s = new string[_subscriber->GetNumberChannels()];
	for (int i = 0; i < _subscriber->GetNumberChannels(); i++)
	{
		string channelName;
		cout << "Name of Channel  " << i + 1 << " :";
		cin >> channelName;
		s[i] = channelName;
	}
	_subscriber->operator=(s);


	delete[]s;
}

void UI::PrintStuff()
{
	cout << "Print Subscriber :" << endl;
	cout << "Name of the subscriber:" << _subscriber->GetName() << endl;
	if (_subscriber->GetNumberChannels() != 0)
	{
		for (int i = 0; i < _subscriber->GetNumberChannels(); i++)
		{
			cout << "Name of Channel  " << i + 1 << " :" << _subscriber->GetChannelList()[i] << endl;
		}
	}
	else if (_subscriber->GetNumberChannels() == 0)
	{
		
	}
	
}

void UI::Reset()
{
	cout << "Reset Subscriber :" << endl;
	_subscriber->Reset();
}

void UI::Run()
{
	string names ;
	cout << "Enter the name of the subscriber :";
	cin >> names;
	EnterNameOfSubscriber(names);
	cout << "Enter an arbitary number of channels :";
	int numberOfChannels;
	cin >> numberOfChannels;
	EnterNumbersOfChannels(numberOfChannels);
	ShowChannels();
	PrintStuff();
	Reset();
	PrintStuff();

}
