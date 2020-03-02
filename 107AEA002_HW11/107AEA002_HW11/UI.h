#ifndef UI_H
#define UI_H

class UI
{
public:
	UI(Subscriber* sub);
	void EnterNameOfSubscriber(string names);
	void EnterNumbersOfChannels(int numbers);
	void ShowChannels();
	void PrintStuff();
	void Reset();
	void Run();

private:
	Subscriber* _subscriber;









};






#endif // !UI_H
