#include "Rating.h"



Rating::Rating()  // default constructor initialize private members
{
	_sumOfRatings = 0;
	_numOfViews = 0;
}
int Rating::GetViews()
{
	return _numOfViews;
}

double Rating::GetAverageRatings()
{
	return ((double)_sumOfRatings / (double)_numOfViews);
}
void Rating::InceraseRatings(int ratings) // add ratings
{
	_sumOfRatings += ratings;
}
void Rating::IncreaseViews()//count how many times a movie is rated
{
	_numOfViews++;
}
int Rating::GetSumRating()
{
	return _sumOfRatings;
}