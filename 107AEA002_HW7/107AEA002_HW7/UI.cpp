#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Rating.h"
#include "UI.h"
void UI::Error()
{
	cout << "Open file error!" << endl;
}
void UI::Load()
{
	string file,line;
	file = "Data.txt";
	fstream inputStream;
	inputStream.open(file);
	if (!inputStream.is_open())
	{
		Error();
	}
	else
	{
		vector<string> vec;
		string movie;
		int rates=0;
		getline(inputStream, line);//read the first useless line
		while (!inputStream.eof())
		{
			getline(inputStream, line);//read ratings and movie names
			vec.push_back(line);
		}
		for (size_t i = 0; i < (vec.size())-1; i += 2)
		{
			movie = vec[i];
			rates = stoi(vec[i + 1]);
			map<string, Rating>::iterator it = movieRating.find(movie);
			//if the map cannot find the move so just add it in to this map
			if (it == movieRating.end())  
			{
				//just initial , actuall data will be calculated in the next step
				movieRating[movie] = Rating();
			}
			//this step is calculating exact sum of ratings and the views 
				movieRating[movie].InceraseRatings(rates);
				movieRating[movie].IncreaseViews();
		}
		
	}
}
void UI::Output()//outputs
{
	map<string, Rating>::iterator it;
	for (it = movieRating.begin(); it != movieRating.end(); it++)
	{
		cout << it->first << " : " << it->second.GetViews() << "  reviews , average of :" << it->second.GetAverageRatings()<<"/ 5" << endl;
		
	}
}