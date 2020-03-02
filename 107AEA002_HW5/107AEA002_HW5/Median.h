#ifndef MEDIAN_H
#define MEDIAN_H

#include <vector>

class Median
{
public:
	Median();
	void Insert();
	double ShowMedian();

private:
	double _median;
	vector <string> _input;
	vector <double> _numbers;
};





#endif // !MEDIAN_H
