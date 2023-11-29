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
int powers(int y, int x);
int divideInt(int y, int x);
double divideDouble(int y, int x);
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
	for (int i = 0; i < y; i++)
	{
		Solution = Solution + x;
	}
	return Solution;

}

string divide(int y, int x)
{
	int Temp = x;
	int i = 0;
	int Quotient = 0;
	int Remainder = 0;
	string Answer = "The answer is ";
	bool Incomplete = true;
	bool Invalid = false;
	bool ValidDivisor = false;

	while (ValidDivisor == false)
	{
		if (y == 0)
		{
			cout << "Cannot divide by zero, enter a different number: ";
			cin >> y;
		}
		else
			ValidDivisor = true;
	}

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
		

	if (Remainder > 0 && Invalid == false)
	{
		Answer = Answer + to_string(i) + " with a remainder of " + to_string(Remainder);
	}
	else
		Answer = Answer + to_string(i);
	
	return Answer;


}

int powers(int y, int x)
{
	int Solution = x;

	for (int i = 1; i < y; i++)
	{
		Solution = multi(Solution, x);
	}
	return Solution;
}

int divideInt(int y, int x)
{
	bool Valid = false;
	bool Incomplete = true;
	int Quotient;
	int Temp = x;
	int i = 0;
	bool ValidDivisor = false;

	while (ValidDivisor == false)
	{
		if (y == 0)
		{
			cout << "Cannot divide by zero, enter a different number: ";
			cin >> y;
		}
		else
			ValidDivisor = true;
	}

	if (x == 0)
	{
		Quotient = 0;
		Incomplete = false;
	}

	while (Incomplete == true)
	{
		if (x == y)
		{
			Incomplete = false;
			Quotient = 1;
		}
		else if (Temp >= y && Temp - y >= 0)
		{
			Temp = Temp - y;
			i++;
		}
		else
		{
			Quotient = i;
			Incomplete = false;
		}

	}

	return Quotient;
		
}

double divideDouble(int y, int x)
{
	return 0;
}