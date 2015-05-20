// Equation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct EquationRoot4
{
	int numRoots;
	double roots[4];
};

struct EquationRoot2
{
	int numRoots;
	double roots[2];
};

void CreateGornorTable(vector<vector<double>> &gornorScheme, const int &x, const int &y)
{
	for (int i = 0; i < x; ++i)
	{
		vector<double> temp;
		for (int j = 0; j < y; ++j)
		{
			temp.push_back(0);
		}
		gornorScheme.push_back(temp);
	}
}

bool CheckPossibleRoot(const double &a, const double &b, const double &c, const double &d, const double &e, const int &x)
{
	if (((a * pow(x, 4)) + (b * pow(x, 3)) + (c * pow(x, 2)) + (d * x) + e) == 0)
	{
		return true;
	}
	return false;
}

double FindOneOfRoots(const double &number, const double &a, const double &b, const double &c, const double &d, const double &e)
{
	for (int divider = 1; divider < abs(number); ++divider)
	{
		double sub = number / divider;
		if ((sub * divider) == number)
		{
			if (CheckPossibleRoot(a, b, c, d, e, divider))
			{
				return divider;
			}
		}
		sub = number / (divider * -1);
		if ((sub * (divider * -1)) == number)
		{
			if (CheckPossibleRoot(a, b, c, d, e, (divider * -1)))
			{
				return (divider * -1);
			}
		}
	}
	return number;
}

int Solve2(const double &a, const double &b, const double &c, EquationRoot2 &result)
{
	double D = pow(b,2) - 4 * a * c;
	if (D < 0)
	{
		return 0;
	}
	if (D == 0)
	{
		result.numRoots = 1;
		result.roots[0] = (-b / 2 * a);
		return 1;
	}
	if (D > 0)
	{
		result.numRoots = 2;
		result.roots[0] = ((-b + sqrt(D)) / (2 * a));
		result.roots[1] = ((-b - sqrt(D)) / (2 * a));
		return 2;
	}
}

EquationRoot4 Solve4(const double &a, const double &b, const double &c, const double &d, const double &e)
{
	vector<vector<double>> gornorTable;
	CreateGornorTable(gornorTable, 4, 5);
	
	vector<double> coefficients;
	coefficients.push_back(a); coefficients.push_back(b); coefficients.push_back(c); coefficients.push_back(d); coefficients.push_back(e);
	
	vector<double> roots;

	roots.push_back(FindOneOfRoots(e, a, b, c, d, e));
	gornorTable[0][0] = coefficients[0];
	for (unsigned int i = 1; i < coefficients.size(); ++i)
	{
		gornorTable[0][i] = roots[0] * gornorTable[0][i - 1] + coefficients[i];
	}

	roots.push_back(FindOneOfRoots(gornorTable[0][3], 0, gornorTable[0][0], gornorTable[0][1], gornorTable[0][2], gornorTable[0][3]));
	gornorTable[1][0] = gornorTable[0][0];
	for (unsigned int i = 1; i < gornorTable[0].size() - 1; ++i)
	{
		gornorTable[1][i] = roots[1] * gornorTable[1][i - 1] + gornorTable[0][i];
	}

	EquationRoot2 prom;
	int roots1 = Solve2(gornorTable[1][0], gornorTable[1][1], gornorTable[1][2], prom);

	EquationRoot4 result;
	result.numRoots = 2 + prom.numRoots;
	result.roots[0] = roots[0];
	result.roots[1] = roots[1];
	for (int i = 0; i < roots1; ++i)
	{
		result.roots[i + 2] = prom.roots[i];
	}

	return result;
}


int main(int argc, char* argv[])
{

	while (!cin.eof())
	{
		double a, b, c, d, e;
		if (cin >> a && cin >> b && cin >> c && cin >> d && cin >> e)
		{
			if (a == 0)
			{
				throw 
			}
			EquationRoot4 mainresult;
			mainresult = Solve4(a, b, c, d, e);
		}
		
	}
	
	
	return 0;
}

