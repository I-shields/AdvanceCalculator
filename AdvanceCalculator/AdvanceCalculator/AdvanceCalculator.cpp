//============================================================
// Author: Isaac Shields
// Date  : 11/26/2023
// Desc  : A calculator that can do more advance math
//============================================================

// N O T E S  A N D  I N F O \\
//===========================\\
//getNum2() goes first into a 
//function, inside a function.
//Inside a function it is "x"
//first then "y" for example 
//x/y x%y


#include <iostream>
#include <string>
using namespace std;


int getNum1();
int getNum2();
double getdouble1();
double getdouble2();
int multi(int x, int y);
double multiDouble(double x, double y);
int powers(int y, int x);
int mod(int y, int x);
int divide(int y, int x);
double divideDouble(double y, double x);
int doubleToInt(double x);
int stringToInt(string x);
int runCheck();
double squareRoot(double x);


int main()
{
	double FinalSolution;
	FinalSolution = squareRoot(getdouble1());
	cout << " The Final statement " << FinalSolution << endl;
}


int getNum1()
{
	//ask user to enter a number, store number in x, and return the number in x
	int x;
	cout << "Enter the first number: ";
	cin >> x;
	return x;
}

int getNum2() 
{
	//ask user to enter a number, store number in x, and return the number in x
	int y;
	cout << "Enter the second number: ";
	cin >> y;
	return y;
}

double getdouble1()
{
	//ask user to enter a number, store number in x, and return the number in x
	double x;
	cout << "Enter the first number: ";
	cin >> x;
	return x;
}

double getdouble2()
{
	//ask user to enter a number, store number in x, and return the number in x
	double x;
	cout << "Enter the second number: ";
	cin >> x;
	return x;
}

int multi(int y, int x)
{
	int Solution = 0;
	//while i is less then y, add x to solution,
	for (int i = 0; i < y; i++)
	{
		Solution = Solution + x;
	}
	return Solution;

}

double multiDouble(double y, double x)
{
	double Answer;
	Answer = x * y;
	return Answer;
}

double divideDouble(double y, double x)
{
	double Answer;
	Answer = x / y;
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

int divide(int y, int x)
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

int mod(int y, int x)
{
	int Temp;
	int Sol;
	Temp = divide(y, x);
	if (multi(Temp, y) == x)
	{
		Sol = 0;
		return Sol;
	}
	else
		return Temp;

}

int doubleToInt(double x)
{
	string Number = to_string(x);
	string DecimalPart;
	int InitialDigits = x;
	string ConvertedString;
	int start = 0;
	int Converted;

	for (int i = 0; i < Number.length(); i++)
	{
		if (Number.at(i) == '.')
		{
			start = i;
		}
	}

	for (int n = start; n < Number.length(); n++)
	{
		DecimalPart += Number.at(n);
	}
	ConvertedString = to_string(InitialDigits) + DecimalPart;
	//cout << ConvertedString << endl;
	Converted = stringToInt(ConvertedString);
	return Converted;
}

int stringToInt(string x)
{
	//cout << x << endl;
	int NumList = 0;
	for (int i = 0; i < x.length(); i++)
	{
		if (x.at(i) >= 48 && x.at(i) <= 57)
		{
			NumList = NumList * 10;
			NumList += x.at(i) - 48;
		}
	}

	return NumList;
}

int runCheck()
{
	static int i = 0;
	i++;
	//cout << "i is " << i << endl;
	return i;
}

double squareRoot(double y)
{
	double Main = y;
	double xn1 = 1.0;
	double x = 1.0;

	for (int i = 0; i < 25; i++)
	{
		xn1 = divideDouble(x, Main);
		xn1 = xn1 + x;
		xn1 = multiDouble(xn1, 0.5);
		x = xn1;
	}

	return x;
}