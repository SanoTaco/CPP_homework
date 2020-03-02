#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;

void CreateRandomBirthday(int a[], int testPeople);
void Test(int a[], int people, int testTimes);
bool SameBirthday(int a[], int testPeople);

int main()
{
	int testedPeople = 50;//initiate tested people
	int times = 5000;// simulation 5000 times;
	int birthdays[50];//array for 50 tested people's birthday information
	Test(birthdays, testedPeople,times);//function to do the whole simulation thing
	system("pause");
	return 0;
}

void CreateRandomBirthday(int a[],int testPeople)//create random birthday 
{

	
	for (int i = 0; i <testPeople; i++)
	{
		a[i] = rand() % 365 + 1;
	}
	
}
bool SameBirthday(int a[], int testPeople)
{
	
	
	for (int i = 0; i < testPeople; i++)
	{
		for (int j = i + 1; j < testPeople; j++)
		{
			if (a[i] == a[j])
			{
				return true;
			}
				
		}
	}
	return false;
}
void Test(int a[] , int people,int testTimes)
{
	double count = 0.00;
	double probability;
	srand(time(0));
	for (int i = 2; i <= people; i++)//Run simulation to see if people have the same birthday
	{
		count = 0;//count the possibility of the same birthday
		for (int j = 0; j < testTimes; j++)
		{
			CreateRandomBirthday(a, i);//create birthdays and fill them into an array
			if (SameBirthday(a, i))//To compare whether two tested people have the same birthday
			{
				count++;
			}
		}
		probability = count / 5000.0;
		cout << "For " << i << " people," << " the probability of two birthday is about " << probability << endl;
	}
	

}

