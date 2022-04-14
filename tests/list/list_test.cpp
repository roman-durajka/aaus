#include "list_test.h"

namespace tests
{
// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}

// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}

// Array list tests



// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}

// DoubleLinkedListTestInterface:

	DoubleLinkedListTestInterface::DoubleLinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* DoubleLinkedListTestInterface::makeList() const
	{
		return new structures::DoubleLinkedList<int>();
	}

// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());

		addTest(new ArrayListTestSize());
		addTest(new ArrayListTestAssign());
		addTest(new ArrayListTestEquals());
		addTest(new ArrayListTestAt());
		addTest(new ArrayListTestAdd());
		addTest(new ArrayListTestInsert());
		addTest(new ArrayListTestTryRemove());
		addTest(new ArrayListTestRemoveAt());
		addTest(new ArrayListTestClear());
		addTest(new ArrayListTestGetIndexOf());
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
	}

// DoubleLinkedListTestOverall:

	DoubleLinkedListTestOverall::DoubleLinkedListTestOverall() :
		ComplexTest("DoubleLinkedList")
	{
		addTest(new DoubleLinkedListTestInterface());

		addTest(new DoubleLinkedListTestAssign());
		addTest(new DoubleLinkedListTestSize());
		addTest(new DoubleLinkedListTestEquals());
		addTest(new DoubleLinkedListTestAt());
		addTest(new DoubleLinkedListTestAdd());
		addTest(new DoubleLinkedListTestInsert());
		addTest(new DoubleLinkedListTestTryRemove());
		addTest(new DoubleLinkedListTestRemoveAt());
		addTest(new DoubleLinkedListTestGetIndexOf());
		addTest(new DoubleLinkedListTestClear());
	}

// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		addTest(new LinkedListTestOverall());
		addTest(new DoubleLinkedListTestOverall());
	}

//Double linked list tests

    DoubleLinkedListTestSize::DoubleLinkedListTestSize() :
        SimpleTest("DoubleLinkedList test size")
    {
    }

    void DoubleLinkedListTestSize::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->size() == 3);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestAssign::DoubleLinkedListTestAssign() :
        SimpleTest("DoubleLinkedList test assign")
    {
    }

    void DoubleLinkedListTestAssign::test() {
        structures::DoubleLinkedList<int>* firstDoubleLinkedList = new structures::DoubleLinkedList<int>();
        structures::DoubleLinkedList<int>* secondDoubleLinkedList = new structures::DoubleLinkedList<int>();

        firstDoubleLinkedList->add(10);
        firstDoubleLinkedList->add(20);
        firstDoubleLinkedList->add(30);

        secondDoubleLinkedList->assign(*firstDoubleLinkedList);

        assertTrue(secondDoubleLinkedList->at(0) == 10);
        assertTrue(secondDoubleLinkedList->at(1) == 20);
        assertTrue(secondDoubleLinkedList->at(2) == 30);

        delete firstDoubleLinkedList;
        delete secondDoubleLinkedList;
    }

    DoubleLinkedListTestEquals::DoubleLinkedListTestEquals() :
        SimpleTest("DoubleLinkedList test equals")
    {
    }

    void DoubleLinkedListTestEquals::test() {
        structures::DoubleLinkedList<int>* firstDoubleLinkedList = new structures::DoubleLinkedList<int>();
        structures::DoubleLinkedList<int>* secondDoubleLinkedList = new structures::DoubleLinkedList<int>();

        firstDoubleLinkedList->add(10);
        firstDoubleLinkedList->add(20);
        firstDoubleLinkedList->add(30);

        assertFalse(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        secondDoubleLinkedList->add(10);
        secondDoubleLinkedList->add(20);
        secondDoubleLinkedList->add(30);

        assertTrue(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        secondDoubleLinkedList->add(40);

        assertFalse(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        secondDoubleLinkedList->removeAt(3);

        assertTrue(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        delete firstDoubleLinkedList;
        delete secondDoubleLinkedList;
    }

    DoubleLinkedListTestAt::DoubleLinkedListTestAt() :
        SimpleTest("DoubleLinkedList test at")
    {
    }

    void DoubleLinkedListTestAt::test() {
        structures::DoubleLinkedList<int>* firstDoubleLinkedList = new structures::DoubleLinkedList<int>();

        firstDoubleLinkedList->add(10);
        firstDoubleLinkedList->add(20);
        firstDoubleLinkedList->add(30);

        assertTrue(firstDoubleLinkedList->at(0) == 10);
        assertTrue(firstDoubleLinkedList->at(1) == 20);
        assertTrue(firstDoubleLinkedList->at(2) == 30);

        structures::DoubleLinkedList<int>* secondDoubleLinkedList = new structures::DoubleLinkedList<int>();

        secondDoubleLinkedList->add(10);
        secondDoubleLinkedList->add(20);
        secondDoubleLinkedList->add(40);

        assertFalse(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        secondDoubleLinkedList->at(2) = 30;

        assertTrue(firstDoubleLinkedList->equals(*secondDoubleLinkedList));

        delete firstDoubleLinkedList;
        delete secondDoubleLinkedList;
    }

    DoubleLinkedListTestAdd::DoubleLinkedListTestAdd() :
        SimpleTest("DoubleLinkedList test add")
    {
    }

    void DoubleLinkedListTestAdd::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->at(0) == 10);
        assertTrue(doubleLinkedList->at(1) == 20);
        assertTrue(doubleLinkedList->at(2) == 30);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestInsert::DoubleLinkedListTestInsert() :
        SimpleTest("DoubleLinkedList test insert")
    {
    }

    void DoubleLinkedListTestInsert::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        doubleLinkedList->insert(40, 3);
        assertTrue(doubleLinkedList->at(3) == 40);

        doubleLinkedList->insert(25, 2);
        assertTrue(doubleLinkedList->at(2) == 25);

        doubleLinkedList->insert(15, 1);
        assertTrue(doubleLinkedList->at(1) == 15);

        doubleLinkedList->insert(5, 0);
        assertTrue(doubleLinkedList->at(0) == 5);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestTryRemove::DoubleLinkedListTestTryRemove() :
        SimpleTest("DoubleLinkedList test try remove")
    {
    }

    void DoubleLinkedListTestTryRemove::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->size() == 3);

        assertTrue(doubleLinkedList->tryRemove(20));
        assertFalse(doubleLinkedList->size() == 3);
        assertTrue(doubleLinkedList->size() == 2);

        assertFalse(doubleLinkedList->tryRemove(20));
        assertTrue(doubleLinkedList->size() == 2);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestRemoveAt::DoubleLinkedListTestRemoveAt() :
        SimpleTest("DoubleLinkedList test remove at")
    {
    }

    void DoubleLinkedListTestRemoveAt::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->size() == 3);

        assertTrue(doubleLinkedList->removeAt(0) == 10);
        assertFalse(doubleLinkedList->size() == 3);
        assertTrue(doubleLinkedList->size() == 2);

        assertTrue(doubleLinkedList->removeAt(1) == 30);
        assertTrue(doubleLinkedList->removeAt(0) == 20);
        assertTrue(doubleLinkedList->size() == 0);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestGetIndexOf::DoubleLinkedListTestGetIndexOf() :
        SimpleTest("DoubleLinkedList test get index of")
    {
    }

    void DoubleLinkedListTestGetIndexOf::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->getIndexOf(10) == 0);
        assertTrue(doubleLinkedList->getIndexOf(20) == 1);
        assertTrue(doubleLinkedList->getIndexOf(30) == 2);

        delete doubleLinkedList;
    }

    DoubleLinkedListTestClear::DoubleLinkedListTestClear() :
        SimpleTest("DoubleLinkedList test clear")
    {
    }

    void DoubleLinkedListTestClear::test() {
        structures::DoubleLinkedList<int>* doubleLinkedList = new structures::DoubleLinkedList<int>();

        doubleLinkedList->add(10);
        doubleLinkedList->add(20);
        doubleLinkedList->add(30);

        assertTrue(doubleLinkedList->size() == 3);

        doubleLinkedList->clear();

        assertTrue(doubleLinkedList->size() == 0);

        delete doubleLinkedList;
    }

    ArrayListTestSize::ArrayListTestSize() :
        SimpleTest("ArrayList test size")
    {
    }

    void ArrayListTestSize::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->size() == 3);

        delete arrayList;
    }

    ArrayListTestAssign::ArrayListTestAssign() :
        SimpleTest("ArrayList test assign")
    {
    }

    void ArrayListTestAssign::test() {
        structures::ArrayList<int>* firstArrayList = new structures::ArrayList<int>();
        structures::ArrayList<int>* secondArrayList = new structures::ArrayList<int>();

        firstArrayList->add(10);
        firstArrayList->add(20);
        firstArrayList->add(30);

        secondArrayList->assign(*firstArrayList);

        assertTrue(secondArrayList->at(0) == 10);
        assertTrue(secondArrayList->at(1) == 20);
        assertTrue(secondArrayList->at(2) == 30);

        delete firstArrayList;
        delete secondArrayList;
    }

    ArrayListTestEquals::ArrayListTestEquals() :
        SimpleTest("ArrayList test equals")
    {
    }

    void ArrayListTestEquals::test() {
        structures::ArrayList<int>* firstArrayList = new structures::ArrayList<int>();
        structures::ArrayList<int>* secondArrayList = new structures::ArrayList<int>();

        firstArrayList->add(10);
        firstArrayList->add(20);
        firstArrayList->add(30);

        assertFalse(firstArrayList->equals(*secondArrayList));

        secondArrayList->add(10);
        secondArrayList->add(20);
        secondArrayList->add(30);

        assertTrue(firstArrayList->equals(*secondArrayList));

        secondArrayList->add(40);

        assertFalse(firstArrayList->equals(*secondArrayList));

        secondArrayList->removeAt(3);

        assertTrue(firstArrayList->equals(*secondArrayList));

        delete firstArrayList;
        delete secondArrayList;
    }

    ArrayListTestAt::ArrayListTestAt() :
        SimpleTest("ArrayList test at")
    {
    }

    void ArrayListTestAt::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->at(0) == 10);
        assertTrue(arrayList->at(1) == 20);
        assertTrue(arrayList->at(2) == 30);

        structures::ArrayList<int>* secondArrayList = new structures::ArrayList<int>();

        secondArrayList->add(10);
        secondArrayList->add(20);
        secondArrayList->add(40);

        assertFalse(arrayList->equals(*secondArrayList));

        secondArrayList->at(2) = 30;

        assertTrue(arrayList->equals(*secondArrayList));

        delete arrayList;
        delete secondArrayList;
    }

    ArrayListTestAdd::ArrayListTestAdd() :
        SimpleTest("ArrayList test add")
    {
    }

    void ArrayListTestAdd::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->at(0) == 10);
        assertTrue(arrayList->at(1) == 20);
        assertTrue(arrayList->at(2) == 30);

        delete arrayList;
    }

    ArrayListTestInsert::ArrayListTestInsert() :
        SimpleTest("ArrayList test insert")
    {
    }

    void ArrayListTestInsert::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        arrayList->insert(40, 3);
        assertTrue(arrayList->at(3) == 40);

        arrayList->insert(25, 2);
        assertTrue(arrayList->at(2) == 25);

        arrayList->insert(15, 1);
        assertTrue(arrayList->at(1) == 15);

        arrayList->insert(5, 0);
        assertTrue(arrayList->at(0) == 5);

        delete arrayList;
    }

    //

    ArrayListTestTryRemove::ArrayListTestTryRemove() :
        SimpleTest("ArrayList test try remove")
    {
    }

    void ArrayListTestTryRemove::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->size() == 3);

        assertTrue(arrayList->tryRemove(20));
        assertFalse(arrayList->size() == 3);
        assertTrue(arrayList->size() == 2);

        assertFalse(arrayList->tryRemove(20));
        assertTrue(arrayList->size() == 2);

        delete arrayList;
    }

    ArrayListTestRemoveAt::ArrayListTestRemoveAt() :
        SimpleTest("ArrayList test remove at")
    {
    }

    void ArrayListTestRemoveAt::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->size() == 3);

        assertTrue(arrayList->removeAt(1) == 20);
        assertFalse(arrayList->size() == 3);
        assertTrue(arrayList->size() == 2);

        assertTrue(arrayList->removeAt(1) == 30);
        assertTrue(arrayList->removeAt(0) == 10);
        assertTrue(arrayList->size() == 0);

        delete arrayList;
    }

    ArrayListTestGetIndexOf::ArrayListTestGetIndexOf() :
        SimpleTest("ArrayList test get index of")
    {
    }

    void ArrayListTestGetIndexOf::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->getIndexOf(10) == 0);
        assertTrue(arrayList->getIndexOf(20) == 1);
        assertTrue(arrayList->getIndexOf(30) == 2);

        delete arrayList;
    }

    ArrayListTestClear::ArrayListTestClear() :
        SimpleTest("ArrayList test clear")
    {
    }

    void ArrayListTestClear::test() {
        structures::ArrayList<int>* arrayList = new structures::ArrayList<int>();

        arrayList->add(10);
        arrayList->add(20);
        arrayList->add(30);

        assertTrue(arrayList->size() == 3);

        arrayList->clear();

        assertTrue(arrayList->size() == 0);

        delete arrayList;
    }
}