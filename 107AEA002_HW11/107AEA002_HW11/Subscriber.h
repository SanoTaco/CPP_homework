#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber
{
public:
	Subscriber(string name);
	void Reset();
	string GetName();
	int GetNumberChannels();
	string* GetChannelList();
	~Subscriber();
	void SetNumberChannel(int num);
	void operator=(const string* s);

private:
	string _name;
	int _numberChannels;;
	string* _channelList;








};

















#endif // !SUBSCRIBER_H
