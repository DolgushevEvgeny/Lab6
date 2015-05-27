#include "stdafx.h"
#include "MyList.h"

using namespace std;

CMyList::CMyList()
	: m_first(shared_ptr<CRecord>())
	, m_last(shared_ptr<CRecord>())
{
}

shared_ptr<CRecord> CMyList::GetFirst() const
{
	return m_first;
}

shared_ptr<CRecord> CMyList::GetLast() const
{
	return m_last;
}

shared_ptr<CRecord> CMyList::GetNext(const std::shared_ptr<const CRecord> pointer) const
{
	return pointer->GetNextItem();
}

shared_ptr<CRecord> CMyList::GetPrev(const std::shared_ptr<const CRecord> pointer) const
{
	return pointer->GetPrevItem();
}

string CMyList::GetValue(const std::shared_ptr<const CRecord> pointer) const
{
	return pointer->GetItemValue();
}

void CMyList::Insert(const std::string &value, std::shared_ptr<CRecord> pointer)
{
	auto newElement = make_shared<CRecord>(value);

	if (!m_first)
	{
		m_first = newElement;
		m_last = newElement;

		return;
	}

	newElement->SetPrev(pointer);

	auto nextElement = pointer->GetNextItem();

	if (nextElement)
	{
		nextElement->SetPrev(newElement);
		newElement->SetNext(nextElement);

	}
	else
	{
		m_last = newElement;
	}
	pointer->SetNext(newElement);

}

void CMyList::Delete(const std::shared_ptr<CRecord> current)
{
	auto nextElement = current->GetNextItem();
	auto prevElement = current->GetPrevItem();
	if (nextElement)
	{
		nextElement->SetPrev(prevElement);
	}
	else
	{
		m_last = prevElement;
	}

	if (prevElement)
	{
		prevElement->SetNext(nextElement);
	}
	else
	{
		m_first = nextElement;
	}
	current->SetNext(nullptr);
	current->SetPrev(nullptr);
}

CMyList::~CMyList()
{
}
