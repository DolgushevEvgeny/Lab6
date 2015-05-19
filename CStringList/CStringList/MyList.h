#pragma once
#include <string>
#include <memory>
#include "Record.h"

class CMyList
{
public:
	CMyList();
	~CMyList();
	std::shared_ptr<CRecord> GetFirst() const;
	std::shared_ptr<CRecord> GetLast() const;
	std::shared_ptr<CRecord> GetNext(const std::shared_ptr<const CRecord> pointer) const;
	std::shared_ptr<CRecord> GetPrev(const std::shared_ptr<const CRecord> pointer) const;
	std::string GetValue(const std::shared_ptr<const CRecord> pointer) const;

	void Insert(const std::string &value,  std::shared_ptr<CRecord> pointer);
	void Delete(const std::shared_ptr<CRecord> item);
private:
	std::shared_ptr<CRecord> m_first, m_last;


};

