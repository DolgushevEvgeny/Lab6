#pragma once
#include <string>

class CStudent
{
public:
	CStudent(int age, std::string name, std::string surname, std::string patronymic);
	~CStudent();

	void SetAge(int age);
	int GetAge() const;

	void ReName(const std::string name, const std::string surname, const std::string patronymic);
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;

private:
	int m_age;
	std::string m_name;
	std::string m_surname;
	std::string m_patromnymic;
};

bool CheckOnSpaces(const std::string &inputString);
