#include "stdafx.h"
#include "Record.h"

using namespace std;

CRecord::CRecord(const string &value)
	: m_value(value)
	, m_next(std::shared_ptr<CRecord>())
	, m_prev(std::shared_ptr<CRecord>())
{
}

shared_ptr<CRecord> CRecord::GetPrevItem() const
{
	return m_prev;
}

shared_ptr<CRecord> CRecord::GetNextItem() const
{
	return m_next;
}

string CRecord::GetItemValue() const
{
	return m_value;
}

void CRecord::SetPrev(std::shared_ptr<CRecord> &prev)
{
	m_prev = prev;
}

void CRecord::SetNext(std::shared_ptr<CRecord> &next)
{
	m_next = next;
}

CRecord::~CRecord()
{
}
