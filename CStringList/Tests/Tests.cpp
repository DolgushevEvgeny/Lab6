// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CStringList/Record.h"
#include "../CStringList/MyList.h"

using namespace std;

struct RecordFixture
{
	CRecord record;

	RecordFixture()
		:record("string")
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Record, RecordFixture)

BOOST_AUTO_TEST_CASE(CanGetValue)
{
	BOOST_CHECK_EQUAL(record.GetItemValue(), "string");
}

BOOST_AUTO_TEST_CASE(CanGetPointerToNextPrevElement)
{
	BOOST_CHECK_EQUAL(record.GetNextItem(), shared_ptr<CRecord>());
	BOOST_CHECK_EQUAL(record.GetPrevItem(), shared_ptr<CRecord>());
}

BOOST_AUTO_TEST_CASE(CanSetPointerToNextPrevElement)
{
	auto it = make_shared<CRecord>("record");
	record.SetNext(it);
	record.SetPrev(it);
	BOOST_CHECK_EQUAL(record.GetNextItem(), it);
	BOOST_CHECK_EQUAL(record.GetPrevItem(), it);
}

BOOST_AUTO_TEST_SUITE_END()


struct StringListFixture
{
	CMyList list;
};

BOOST_FIXTURE_TEST_SUITE(StringList, StringListFixture)

BOOST_AUTO_TEST_CASE(CanInsertToEndByDefault)
{
	list.Insert("string", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "string");
}

BOOST_AUTO_TEST_CASE(CanInsertAfterGivenArg)
{
	list.Insert("1", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "1");
	list.Insert("2", list.GetLast());
	//BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "2");
	//list.Insert("4", list.GetLast());
	//BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "4");
	//auto it = list.GetLast()->GetPrevItem();
	//list.Insert("3", it);
	//BOOST_CHECK_EQUAL(list.GetLast()->GetPrevItem()->GetItemValue(), "3");
	//BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "4");

}

BOOST_AUTO_TEST_CASE(CanDeleteElem)
{
	list.Insert("1", list.GetLast());
	list.Insert("2", list.GetLast());
	list.Insert("4", list.GetLast());
	auto it = list.GetLast()->GetPrevItem();
	list.Insert("3", it);
	list.Delete(list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "3");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetItemValue(), "1");
	list.Delete(list.GetFirst());
	BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "3");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetItemValue(), "2");
	list.Delete(list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetItemValue(), "2");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetItemValue(), "2");
}


BOOST_AUTO_TEST_SUITE_END()