#include <iostream>
#include <string>


using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string name)
{
	_name = name;
	_numberChannels = 0;
	_channelList = nullptr;
}

Subscriber::~Subscriber()
{
	delete[]_channelList;
	_channelList = nullptr;
	_numberChannels = 0;
	//cout << "_channelList has been deleted" << endl;

}
void Subscriber::SetNumberChannel(int num)
{
	_numberChannels = num;
}
void Subscriber::Reset()
{
	delete[]_channelList;
	_channelList = nullptr;
	_numberChannels = 0;
	
}

string Subscriber::GetName()
{
	return _name;
}

int Subscriber::GetNumberChannels()
{
	return _numberChannels;
}

string* Subscriber::GetChannelList()
{
	return _channelList;
}





void Subscriber::operator=(const string * s)
{
	_channelList = new string[_numberChannels];

	
	
	for (int i = 0; i < _numberChannels; i++)
	{
		
		_channelList[i] =s[i];
	}
}
