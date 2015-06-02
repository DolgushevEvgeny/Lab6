// CTriangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	while (!cin.eof())
	{
		cout << "Enter sides of triangle : " << endl;
		double side1, side2, side3;
		if (cin >> side1 && cin >> side2 && cin >> side3)
		{
			try
			{
				CTriangle triangle(side1, side2, side3);
				cout << "Perimetr of triangle : " << triangle.GetPerimeter() << endl;
				cout << "Area of triangle : " << triangle.GetArea() << endl;
			}
			catch (const invalid_argument &exception)
			{
				cout << "Cant create triangle : " << exception.what() << endl;
			}
			catch (const domain_error &exception)
			{
				cout << "Cant build triangle : " << exception.what() << endl;
			}
		}
	}

	return 0;
}

