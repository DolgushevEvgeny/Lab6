// CStudentTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CStudent/Student.h"

using namespace std;

struct StudentFixture
{
	CStudent student;
	
	StudentFixture()
		: student(20, "Evgene", "Dolgushev", "Dmitrievich")
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Student, StudentFixture)

BOOST_AUTO_TEST_CASE(CreateStudentWithCorrectFieldsAndCheckTheirStates)
{
	BOOST_CHECK_EQUAL(student.GetAge(), 20);
	BOOST_CHECK_EQUAL(student.GetName(), "Evgene");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Dolgushev");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Dmitrievich");
}

BOOST_AUTO_TEST_CASE(CantCreateStudentWithUncorrectFields)
{
	BOOST_REQUIRE_THROW(CStudent student(20, "Evgene", "Dolgu shev", "Dmitrievich"), invalid_argument);
	BOOST_REQUIRE_THROW(CStudent student(13, "Evgene", "Dolgu shev", "Dmitrievich"), out_of_range);
}

BOOST_AUTO_TEST_CASE(StudentAgeCanBeChangedOnlyInLargeSide)
{
	{
		BOOST_REQUIRE_NO_THROW(student.SetAge(21));
		BOOST_CHECK_EQUAL(student.GetAge(), 21);
	}
	{
		BOOST_REQUIRE_THROW(student.SetAge(20), domain_error);
	}
}

BOOST_AUTO_TEST_CASE(IsStudentAgeInRange)
{
	{
		BOOST_REQUIRE_THROW(student.SetAge(61), out_of_range);
	}
	{
		BOOST_REQUIRE_THROW(CStudent student(13, "Evgene", "Dolgushev", "Dmitrievich"), out_of_range);
	}
}

BOOST_AUTO_TEST_CASE(TestRenameStudent)
{
	BOOST_REQUIRE_NO_THROW(student.ReName("Egor", "Parshin", "Vladimirovich"));

	BOOST_REQUIRE_THROW(student.ReName("", "Parshin", ""), invalid_argument);
	BOOST_REQUIRE_THROW(student.ReName("Egor", "Par shin", ""), invalid_argument);
	BOOST_REQUIRE_THROW(student.ReName("Egor", "Parshin", "Vladimiro vich"), invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()