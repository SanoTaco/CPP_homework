#ifndef RATING_H
#define RATING_H

class Rating
{
public:
	Rating();
	int GetViews();
	double GetAverageRatings();
	void InceraseRatings(int ratings);
	void IncreaseViews();
	int GetSumRating();
private:
	int _numOfViews ;
	int _sumOfRatings;




};










#endif // !RATING_H
