/*
107AEA002_HW7 張育祿 二技陸生
You have collected a file of movie ratings where each movie is rated from 1 (bad)
to 5 (excellent). The first line of the file is a number that identifies how many ratings
are in the file. Each rating then consists of two lines: the name of the movie
followed by the numeric rating from 1 to 5. Here is a sample rating file with four
unique movies and seven ratings:
7
Happy Feet
4
Happy Feet
5
Pirates of the Caribbean
3
Happy Feet
4
Pirates of the Caribbean
4
Flags of Our Fathers
5
Gigli
1


Write a program that reads in a file in this format, calculates the average rating for
each movie, and outputs the average along with the number of reviews. Here is the
desired output for the sample data:
Happy Feet: 3 reviews, average of 4.3 / 5
Pirates of the Caribbean: 2 reviews, average of 3.5 / 5
Flags of Our Father: 1 review, average of 5 / 5
Gigli: 1 review, average of 1 / 5
Use a map or multiple maps to generate the output. Your map should index from a
string representing each movie’s name to integers that store the number of reviews
for the movie and the sum of the ratings for the movie.

*/


#include <iostream>

using namespace std;

#include "Rating.h"
#include "UI.h"

int main()
{

	UI ui;
	ui.Load();
	ui.Output();
	

	system("pause");
	return 0;
}