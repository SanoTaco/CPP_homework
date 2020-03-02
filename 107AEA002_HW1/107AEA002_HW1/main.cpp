/*107AEA002  HW1 zhangyulu èà”˝µì
Write a program to calculate the grade point average(GPA) of a student by getting
their grades for all their subjects.Grades and their grade points are
Grade S 10 points
Grade A 9 points
Grade B 8 points
Grade C 7 points
Grade D 6 points
Grade E 5 points
Grade F 0 points
The program should input the number of subjects, followed by the grade obtained
in each subject.The program should calculate the average of the grade points and
print it.
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{

	string subjectName;//store subject names
	string line;//store input data
	fstream inputStream;
	string file;
	//file = "C:/score.txt";
	cout << "Enter Your File Name :";
	cin >> file;
	cout << file << endl;
	//inputStream.open("score.txt");
	inputStream.open(file);
	if (!inputStream.is_open())
	{
		cout << "ERROR ON OPENING FILE £°" << endl;//fool proof
	}
	else
	{
		cout << "File Open Success!" << endl;//it shows that  the file is open
		int flag = -1;//record how many courses 
		int gpa = 0;//initialized gpa
		int score = 0;//total score
		while (!inputStream.eof())
		{
			getline(inputStream, line);
			flag++;
			cout << line << endl;
			string temp;// a string to store the grade this course get ,then transform to int number as score
			temp = line[line.size() - 1];
			if (temp == "S")// grade transform to score
			{
				score += 10;
			}
			else if (temp == "A" )
			{
				score += 9;
			}
			else if (temp == "B" )
			{
				score += 8;
			}
			else if (temp == "C" )
			{
				score += 7;
			}
			else if (temp == "D" )
			{
				score += 6;
			}
			else if (temp == "E")
			{
				score += 5;
			}
			else if (temp == "F")
			{
				score += 0;
			}
		}

		inputStream.close();//file closed 

		gpa = score / flag;//calculate the gpa 

		cout << "GPA is:" << gpa << endl;
	}
	system("pause");

	return 0;
}