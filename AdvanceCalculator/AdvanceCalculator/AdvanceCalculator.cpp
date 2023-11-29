//============================================================
// Author: Isaac Shields
// Date  : 11/26/2023
// Desc  : A calculator that can do more advance math
//============================================================

#include <iostream>
#include <string>
using namespace std;


int getNum1();
int getNum2();
int multi(int x, int y);
string divide(int y, int x);

int main()
{
	string FinalSolution;
	FinalSolution = divide(getNum2(), getNum1());
	cout << FinalSolution;
}


int getNum1()
{
	int x;
	cout << "Enter the first number: ";
	cin >> x;
	return x;
}
int getNum2() 
{
	int y;
	cout << "Enter the second number: ";
	cin >> y;
	return y;
}

int multi(int y, int x)
{
	int Solution = 0;
	cout << "First num: " << x << " Second num: " << y << endl;
	for (int i = 0; i < y; i++)
	{
		Solution = Solution + x;
	}
	return Solution;

}

string divide(int y, int x)
{

	cout << "First num: " << x << " Second num: " << y << endl;
	int Temp = x;
	int i = 0;
	int Quotient = 0;
	int Remainder = 0;
	string Answer = "The answer is ";
	bool Incomplete = true;
	bool Invalid = false;
	if (x != 0)
	{
		if (Temp == y)
		{
			Quotient = 1;
			Incomplete = false;
		}

		while (Incomplete == true)
		{
			if (Temp >= y && Temp - y >= 0)
			{
				Temp = Temp - y;
				i++;
			}
			else if (Temp == y || Temp == 0)
			{
				Quotient = 1;
				Incomplete = false;
			}
			else if (Temp == 1)
			{
				Remainder = 1;
				Incomplete = false;
			}
			else if (Temp > 1 && Temp < y)
			{
				Remainder = Temp;
				Incomplete = false;
			}
		}

	}
	else
		Invalid = true;
		

	if (Remainder > 0 && Invalid == false)
	{
		Answer = Answer + to_string(i) + " with a remainder of " + to_string(Remainder);
	}
	else
		Answer = Answer + to_string(i);

	if (Invalid == true)
	{
		Answer = "Can't divide by zero.";
	}

	return Answer;
	



}