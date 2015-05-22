#include "stdafx.h"
#include "Student.h"

using namespace std;

CStudent::CStudent(int age, std::string name, std::string surname, std::string patronymic)
{
	if (name.empty())
	{
		throw invalid_argument("Student name cannot be empty!");
	}
	if (surname.empty())
	{
		throw invalid_argument("Student surname cannot be empty!");
	}

	m_age = ((age >= 14) && (age <= 60)) ? age : throw out_of_range("Student age out of range.");
	
	m_name = CheckOnSpaces(name) ? move(name) : throw invalid_argument("Student name shouldn't contain spaces!");
	m_surname = CheckOnSpaces(surname) ? move(surname) : throw invalid_argument("Student surname shouldn't contain spaces!");
	m_patromnymic = CheckOnSpaces(patronymic) ? move(patronymic) : throw invalid_argument("Student patronymic shouldn't contain spaces!");
}

CStudent::~CStudent()
{
}

void CStudent::SetAge(int age)
{
	if (age < m_age)
	{
		throw domain_error("It is impossible to establish the age less than it actually is.");
	}
	if ((age < 14) | (age > 60))
	{
		throw out_of_range("Student age out of range.");
	}

	m_age = age;
}

int CStudent::GetAge() const
{
	return m_age;
}

std::string CStudent::GetName() const
{
	return m_name;
}

std::string CStudent::GetSurname() const
{
	return m_surname;
}

std::string CStudent::GetPatronymic() const
{
	return m_patromnymic;
}

void CStudent::ReName(const std::string name, const std::string surname, const std::string patronymic)
{
	if (name.empty())
	{
		throw invalid_argument("Student name cannot be empty!");
	}
	if (surname.empty())
	{
		throw invalid_argument("Student surname cannot be empty!");
	}

	m_name = CheckOnSpaces(name) ? move(name) : throw invalid_argument("Student name shouldn't contain spaces!");
	m_surname = CheckOnSpaces(surname) ? move(surname) : throw invalid_argument("Student surname shouldn't contain spaces!");
	m_patromnymic = CheckOnSpaces(patronymic) ? move(patronymic) : throw invalid_argument("Student patronymic shouldn't contain spaces!");
}

bool CheckOnSpaces(const std::string &inputString)
{
	for (size_t i = 0; i < inputString.size(); ++i)
	{
		if (inputString[i] == ' ')
		{
			return false;
		}
	}
	return true;
}