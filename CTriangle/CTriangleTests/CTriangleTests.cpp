// CTriangleTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CTriangle/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_CASE(CanCreateTriangleWithCorrectParametrs)
{
	BOOST_CHECK_NO_THROW(CTriangle(3, 4, 5));
	BOOST_CHECK_NO_THROW(CTriangle(3, 4, 6));
	BOOST_CHECK_NO_THROW(CTriangle(2.5, 4.5, 4.5));
	BOOST_CHECK_NO_THROW(CTriangle(1, 2, 3));
}

BOOST_AUTO_TEST_CASE(CantCreateTriangleWithUncorrectParametrs)
{
	BOOST_REQUIRE_THROW(CTriangle(3.2, 4, -5.1), invalid_argument);
	BOOST_REQUIRE_THROW(CTriangle(3, 4, 0), invalid_argument);
}

BOOST_AUTO_TEST_CASE(CantCreateTriangleWithUncorrectSides)
{
	BOOST_REQUIRE_THROW(CTriangle(3.5, 4.5, 10), domain_error);
	BOOST_REQUIRE_THROW(CTriangle(1, 1, 3), domain_error);
}

BOOST_AUTO_TEST_CASE(TriangleHavePerimetr)
{
	{
		CTriangle triangle(3, 4, 5);
		BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 12);
	}
	{
		CTriangle triangle(3.5, 6.4, 5.9);
		BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 15.8);
	}
	{
		CTriangle triangle(5.75, 6.24, 10.50);
		BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 22.49);
	}
}

BOOST_AUTO_TEST_CASE(TriangleHaveArea)
{
	{
		CTriangle triangle(3, 4, 5);
		BOOST_CHECK_EQUAL(triangle.GetArea(), 6);
	}
	{
		CTriangle triangle(3.5, 6.4, 5.9);
		BOOST_CHECK_EQUAL(triangle.GetArea(), 10.2118);
	}
	{
		CTriangle triangle(5.75, 6.24, 10.50);
		BOOST_CHECK_EQUAL(triangle.GetArea(), 15.179);
	}
	{
		CTriangle triangle(3, 4, 1);
		BOOST_CHECK_EQUAL(triangle.GetArea(), 0);
	}
}