#pragma once
#include <string>
#include <memory>

class CRecord
{
public:
	CRecord(const std::string &value);
	~CRecord();
	std::shared_ptr<CRecord> GetNextItem() const;
	std::shared_ptr<CRecord> GetPrevItem() const;
	std::string GetItemValue() const;
	void SetPrev(const std::shared_ptr<CRecord> &prev);
	void SetNext(const std::shared_ptr<CRecord> &prev);
private:
	std::string m_value;
	std::shared_ptr<CRecord> m_next, m_prev;
};

