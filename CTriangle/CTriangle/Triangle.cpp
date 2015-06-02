#include "stdafx.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

CTriangle::CTriangle(double side1, double side2, double side3)
{
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		throw invalid_argument("One or more sides of triangle must be more than zero!");
	}
	if (side1 > side2 + side3 || side2 > side1 + side3 || side3 > side1 + side2)
	{
		throw domain_error("Uncorrect sides of triangle");
	}
	m_side1 = side1;
	m_side2 = side2;
	m_side3 = side3;
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return  GetSide1() + GetSide2() + GetSide3();
}

double CTriangle::GetArea()const
{
	return sqrt((GetPerimeter() / 2) * ((GetPerimeter() / 2) - GetSide1()) * ((GetPerimeter() / 2) - GetSide2()) * ((GetPerimeter() / 2) - GetSide3()));
}

CTriangle::~CTriangle()
{
}
