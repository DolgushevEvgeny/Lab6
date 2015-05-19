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
		pointer->SetNext(newElement);
		m_last = newElement;
	}
	

}

void CMyList::Delete(const std::shared_ptr<CRecord> current)
{
	auto prevElement = current->GetPrevItem();

	if (prevElement)
	{
		auto nextElement = current->GetNextItem();
		if (nextElement)
		{
			nextElement->SetPrev(prevElement);
			prevElement->SetNext(nextElement);

			return;
		}
		m_last = prevElement;

		return;
	}

	auto nextElement = current->GetNextItem();
	if (nextElement)
	{
		nextElement->SetPrev(shared_ptr<CRecord>());
		m_first = nextElement;

		return;
	}
	
	m_first = current->GetNextItem();
	m_last = shared_ptr<CRecord>();
}

CMyList::~CMyList()
{
}
