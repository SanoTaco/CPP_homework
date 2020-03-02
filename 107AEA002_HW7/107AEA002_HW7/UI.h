#ifndef UI_H
#define UI_H
#include<map>
class Rating;
class UI
{
public:

	void Load();
	void Error();
	void Output();


private:
	map<string, Rating> movieRating;

};













#endif // !UI_H
