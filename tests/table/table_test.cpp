#include "table_test.h"
#include "../../structures/table/binary_search_tree.h"
#include "../../structures/table/hash_table.h"
#include "../../structures/table/linked_table.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/table.h"
#include "../../structures/table/treap.h"
#include "../../structures/table/unsorted_sequence_table.h"

#include <iostream>
#include <fstream>

namespace tests
{
	TableTestInterface::TableTestInterface() :
		SimpleTest("Interface")
	{
	}

	void TableTestInterface::test()
	{
		int x = 0;
		structures::Table<int, int>* table = this->makeTable();
		table->equals(*table);
		table->assign(*table);
		table->insert(0, 0);
		table->find(0);
		table->remove(0);
		table->tryFind(0, x);
		table->containsKey(0);
		delete table;
		this->logPass("Compiled.");
	}

	structures::Table<int, int>* BinarySearchTreeTestInterface::makeTable()
	{
		return new structures::BinarySearchTree<int, int>();
	}

	structures::Table<int, int>* HashTableTestInterface::makeTable()
	{
		return new structures::HashTable<int, int>();
	}

	structures::Table<int, int>* LinkedTableTestInterface::makeTable()
	{
		return new structures::LinkedTable<int, int>();
	}

	structures::Table<int, int>* SortedSequenceTableTestInterface::makeTable()
	{
		return new structures::SortedSequenceTable<int, int>();
	}

	structures::Table<int, int>* TreapTestInterface::makeTable()
	{
		return new structures::Treap<int, int>();
	}

	structures::Table<int, int>* UnsortedSequenceTableTestInterface::makeTable()
	{
		return new structures::UnsortedSequenceTable<int, int>();
	}

	BinarySearchTreeTestOverall::BinarySearchTreeTestOverall() :
		ComplexTest("BinarySearchTree")
	{
		addTest(new BinarySearchTreeTestInterface());

		addTest(new BinarySearchTreeTestCopyConstructor());
		addTest(new BinarySearchTreeTestAssign());
		addTest(new BinarySearchTreeTestEquals());
		addTest(new BinarySearchTreeTestInsert());
		addTest(new BinarySearchTreeTestSize());
		addTest(new BinarySearchTreeTestFind());
		addTest(new BinarySearchTreeTestRemove());
		addTest(new BinarySearchTreeTestTryFind());
		addTest(new BinarySearchTreeTestContainsKey());
		addTest(new BinarySearchTreeTestClear());
		addTest(new BinarySearchTreeTestIsEmpty());

		addTest(new BinarySearchTreePowerTestScenarioA());
		addTest(new BinarySearchTreePowerTestScenarioB());

		addTest(new BinarySearchTreeTimeAnalysisInsert());
		addTest(new BinarySearchTreeTimeAnalysisRemove());
		addTest(new BinarySearchTreeTimeAnalysisTryFind());
	}

	HashTableTestOverall::HashTableTestOverall() :
		ComplexTest("HashTable")
	{
		addTest(new HashTableTestInterface());
	}

	LinkedTableTestOverall::LinkedTableTestOverall() :
		ComplexTest("LinkedTable")
	{
		addTest(new LinkedTableTestInterface());
	}

	SortedSequenceTableTestOverall::SortedSequenceTableTestOverall() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SortedSequenceTableTestInterface());

		addTest(new SortedSequenceTableTestCopyConstructor());
		addTest(new SortedSequenceTableTestAssign());
		addTest(new SortedSequenceTableTestEquals());
		addTest(new SortedSequenceTableTestInsert());
		addTest(new SortedSequenceTableTestSize());
		addTest(new SortedSequenceTableTestFind());
		addTest(new SortedSequenceTableTestRemove());
		addTest(new SortedSequenceTableTestTryFind());
		addTest(new SortedSequenceTableTestContainsKey());
		addTest(new SortedSequenceTableTestClear());
		addTest(new SortedSequenceTableTestIsEmpty());

		addTest(new SortedSequenceTablePowerTestScenarioA());
		addTest(new SortedSequenceTablePowerTestScenarioB());

		addTest(new SortedSequenceTableTimeAnalysisInsert());
		addTest(new SortedSequenceTableTimeAnalysisRemove());
		addTest(new SortedSequenceTableTimeAnalysisTryFind());
	}

	TreapTestOverall::TreapTestOverall() :
		ComplexTest("Treap")
	{
		addTest(new TreapTestInterface());
	}

	UnsortedSequenceTableTestOverall::UnsortedSequenceTableTestOverall() :
		ComplexTest("UnsortedSequenceTable")
	{
		addTest(new UnsortedSequenceTableTestInterface());
	}

	TableTestOverall::TableTestOverall() :
		ComplexTest("Table")
	{
		addTest(new BinarySearchTreeTestOverall());
		addTest(new HashTableTestOverall());
		addTest(new LinkedTableTestOverall());
		addTest(new SortedSequenceTableTestOverall());
		addTest(new TreapTestOverall());
		addTest(new UnsortedSequenceTableTestOverall());
	}

	//custom tests sorted sequence table

	SortedSequenceTableTestCopyConstructor::SortedSequenceTableTestCopyConstructor() :
        SimpleTest("Sorted sequence table test copy constructor")
    {
    }

    void SortedSequenceTableTestCopyConstructor::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::SortedSequenceTable<int, int>* secondTable = new structures::SortedSequenceTable<int, int>(*firstTable);

        assertTrue(secondTable->size() == 5);
        assertTrue(secondTable->remove(0) == 0);
        assertTrue(secondTable->size() == 4);
        assertTrue(secondTable->remove(4) == 4);
        assertTrue(secondTable->size() == 3);
        assertTrue(secondTable->remove(2) == 2);
        assertTrue(secondTable->size() == 2);
        assertTrue(secondTable->remove(1) == 1);
        assertTrue(secondTable->size() == 1);

        delete firstTable;
        delete secondTable;
    }

    SortedSequenceTableTestAssign::SortedSequenceTableTestAssign() :
        SimpleTest("Sorted sequence table test assign")
    {
    }

    void SortedSequenceTableTestAssign::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::SortedSequenceTable<int, int>* secondTable = new structures::SortedSequenceTable<int, int>();
        secondTable->assign(*firstTable);

        assertTrue(secondTable->size() == 5);
        assertTrue(secondTable->remove(0) == 0);
        assertTrue(secondTable->size() == 4);
        assertTrue(secondTable->remove(4) == 4);
        assertTrue(secondTable->size() == 3);
        assertTrue(secondTable->remove(2) == 2);
        assertTrue(secondTable->size() == 2);
        assertTrue(secondTable->remove(1) == 1);
        assertTrue(secondTable->size() == 1);

        delete firstTable;
        delete secondTable;
    }

    SortedSequenceTableTestEquals::SortedSequenceTableTestEquals() :
        SimpleTest("Sorted sequence table test equals")
    {
    }

    void SortedSequenceTableTestEquals::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::SortedSequenceTable<int, int>* secondTable = new structures::SortedSequenceTable<int, int>();

        secondTable->insert(0, 0);
        secondTable->insert(1, 1);
        secondTable->insert(2, 2);
        secondTable->insert(4, 4);

        assertFalse(firstTable->equals(*secondTable));

        secondTable->insert(3, 3);

        assertTrue(firstTable->equals(*secondTable));

        firstTable->remove(2);

        assertFalse(firstTable->equals(*secondTable));

        delete firstTable;
        delete secondTable;
    }

    SortedSequenceTableTestInsert::SortedSequenceTableTestInsert() :
        SimpleTest("Sorted sequence table test insert")
    {
    }

    void SortedSequenceTableTestInsert::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        assertTrue(firstTable->size() == 0);

        firstTable->insert(100, 100);

        assertTrue(firstTable->size() == 1);
        assertTrue(firstTable->containsKey(100));

        firstTable->insert(200, 200);
        firstTable->insert(20, 20);
        firstTable->insert(30, 30);

        assertTrue(firstTable->size() == 4);
        assertTrue(firstTable->containsKey(200));
        assertTrue(firstTable->containsKey(20));
        assertTrue(firstTable->containsKey(30));

        delete firstTable;
    }

    SortedSequenceTableTestSize::SortedSequenceTableTestSize() :
        SimpleTest("Sorted sequence table test size")
    {
    }

    void SortedSequenceTableTestSize::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        assertTrue(firstTable->size() == 0);
        firstTable->insert(100, 100);
        assertTrue(firstTable->size() == 1);
        firstTable->insert(200, 200);
        assertTrue(firstTable->size() == 2);
        firstTable->insert(300, 300);
        assertTrue(firstTable->size() == 3);
        firstTable->insert(400, 400);
        assertTrue(firstTable->size() == 4);
        firstTable->insert(500, 500);

        delete firstTable;
    }

    SortedSequenceTableTestFind::SortedSequenceTableTestFind() :
        SimpleTest("Sorted sequence table test find")
    {
    }

    void SortedSequenceTableTestFind::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        assertTrue(firstTable->find(1) == 100);
        assertTrue(firstTable->find(6) == 200);
        assertTrue(firstTable->find(3) == 300);

        assertTrue(firstTable->size() == 3);

        delete firstTable;
    }

    SortedSequenceTableTestRemove::SortedSequenceTableTestRemove() :
        SimpleTest("Sorted sequence table test remove")
    {
    }

    void SortedSequenceTableTestRemove::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        assertTrue(firstTable->remove(1) == 100);
        assertTrue(firstTable->remove(6) == 200);
        assertTrue(firstTable->remove(3) == 300);

        assertTrue(firstTable->size() == 0);

        delete firstTable;
    }

    SortedSequenceTableTestTryFind::SortedSequenceTableTestTryFind() :
        SimpleTest("Sorted sequence table test try find")
    {
    }

    void SortedSequenceTableTestTryFind::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        int data;

        assertTrue(firstTable->tryFind(1, data));
        assertTrue(data == 100);
        assertTrue(firstTable->tryFind(6, data));
        assertTrue(data == 200);
        assertTrue(firstTable->tryFind(3, data));
        assertTrue(data == 300);

        assertFalse(firstTable->tryFind(4, data));

        delete firstTable;
    }

    SortedSequenceTableTestContainsKey::SortedSequenceTableTestContainsKey() :
        SimpleTest("Sorted sequence table test contains key")
    {
    }

    void SortedSequenceTableTestContainsKey::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->containsKey(1) == true);
        assertFalse(firstTable->containsKey(2) == true);
        assertTrue(firstTable->containsKey(3) == true);
        assertFalse(firstTable->containsKey(4) == true);
        assertTrue(firstTable->containsKey(6) == true);

        delete firstTable;
    }

    SortedSequenceTableTestClear::SortedSequenceTableTestClear() :
        SimpleTest("Sorted sequence table test clear")
    {
    }

    void SortedSequenceTableTestClear::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        firstTable->clear();

        assertFalse(firstTable->size() == 3);
        assertTrue(firstTable->size() == 0);

        delete firstTable;
    }

    SortedSequenceTableTestIsEmpty::SortedSequenceTableTestIsEmpty() :
        SimpleTest("Sorted sequence table test is empty")
    {
    }

    void SortedSequenceTableTestIsEmpty::test() {
        structures::SortedSequenceTable<int, int>* firstTable = new structures::SortedSequenceTable<int, int>();

        assertTrue(firstTable->isEmpty() == true);

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertFalse(firstTable->isEmpty() == true);

        firstTable->clear();

        assertTrue(firstTable->isEmpty() == true);

        delete firstTable;
    }

    //custom tests binary search tree

	BinarySearchTreeTestCopyConstructor::BinarySearchTreeTestCopyConstructor() :
        SimpleTest("Binary search tree test copy constructor")
    {
    }

    void BinarySearchTreeTestCopyConstructor::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::BinarySearchTree<int, int>* secondTable = new structures::BinarySearchTree<int, int>(*firstTable);

        assertTrue(secondTable->size() == 5);
        assertTrue(secondTable->remove(0) == 0);
        assertTrue(secondTable->size() == 4);
        assertTrue(secondTable->remove(4) == 4);
        assertTrue(secondTable->size() == 3);
        assertTrue(secondTable->remove(2) == 2);
        assertTrue(secondTable->size() == 2);
        assertTrue(secondTable->remove(1) == 1);
        assertTrue(secondTable->size() == 1);

        delete firstTable;
        delete secondTable;
    }

    BinarySearchTreeTestAssign::BinarySearchTreeTestAssign() :
        SimpleTest("Binary search tree test assign")
    {
    }

    void BinarySearchTreeTestAssign::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::BinarySearchTree<int, int>* secondTable = new structures::BinarySearchTree<int, int>();
        secondTable->assign(*firstTable);

        assertTrue(secondTable->size() == 5);
        assertTrue(secondTable->remove(0) == 0);
        assertTrue(secondTable->size() == 4);
        assertTrue(secondTable->remove(4) == 4);
        assertTrue(secondTable->size() == 3);
        assertTrue(secondTable->remove(2) == 2);
        assertTrue(secondTable->size() == 2);
        assertTrue(secondTable->remove(1) == 1);
        assertTrue(secondTable->size() == 1);

        delete firstTable;
        delete secondTable;
    }

    BinarySearchTreeTestEquals::BinarySearchTreeTestEquals() :
        SimpleTest("Binary search tree test equals")
    {
    }

    void BinarySearchTreeTestEquals::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(0, 0);
        firstTable->insert(1, 1);
        firstTable->insert(2, 2);
        firstTable->insert(3, 3);
        firstTable->insert(4, 4);

        structures::BinarySearchTree<int, int>* secondTable = new structures::BinarySearchTree<int, int>();

        secondTable->insert(0, 0);
        secondTable->insert(1, 1);
        secondTable->insert(2, 2);
        secondTable->insert(4, 4);

        assertFalse(firstTable->equals(*secondTable));

        secondTable->insert(3, 3);

        assertTrue(firstTable->equals(*secondTable));

        firstTable->remove(2);

        assertFalse(firstTable->equals(*secondTable));

        delete firstTable;
        delete secondTable;
    }

    BinarySearchTreeTestInsert::BinarySearchTreeTestInsert() :
        SimpleTest("Binary search tree test insert")
    {
    }

    void BinarySearchTreeTestInsert::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        assertTrue(firstTable->size() == 0);

        firstTable->insert(100, 100);

        assertTrue(firstTable->size() == 1);
        assertTrue(firstTable->containsKey(100));

        firstTable->insert(200, 200);
        firstTable->insert(20, 20);
        firstTable->insert(30, 30);

        assertTrue(firstTable->size() == 4);
        assertTrue(firstTable->containsKey(200));
        assertTrue(firstTable->containsKey(20));
        assertTrue(firstTable->containsKey(30));

        delete firstTable;
    }

    BinarySearchTreeTestSize::BinarySearchTreeTestSize() :
        SimpleTest("Binary search tree test size")
    {
    }

    void BinarySearchTreeTestSize::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        assertTrue(firstTable->size() == 0);
        firstTable->insert(100, 100);
        assertTrue(firstTable->size() == 1);
        firstTable->insert(200, 200);
        assertTrue(firstTable->size() == 2);
        firstTable->insert(300, 300);
        assertTrue(firstTable->size() == 3);
        firstTable->insert(400, 400);
        assertTrue(firstTable->size() == 4);
        firstTable->insert(500, 500);

        delete firstTable;
    }

    BinarySearchTreeTestFind::BinarySearchTreeTestFind() :
        SimpleTest("Binary search tree test find")
    {
    }

    void BinarySearchTreeTestFind::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        assertTrue(firstTable->find(1) == 100);
        assertTrue(firstTable->find(6) == 200);
        assertTrue(firstTable->find(3) == 300);

        assertTrue(firstTable->size() == 3);

        delete firstTable;
    }

    BinarySearchTreeTestRemove::BinarySearchTreeTestRemove() :
        SimpleTest("Binary search tree test remove")
    {
    }

    void BinarySearchTreeTestRemove::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        assertTrue(firstTable->remove(1) == 100);
        assertTrue(firstTable->remove(6) == 200);
        assertTrue(firstTable->remove(3) == 300);

        assertTrue(firstTable->size() == 0);

        delete firstTable;
    }

    BinarySearchTreeTestTryFind::BinarySearchTreeTestTryFind() :
        SimpleTest("Binary search tree test try find")
    {
    }

    void BinarySearchTreeTestTryFind::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        int data;

        assertTrue(firstTable->tryFind(1, data));
        assertTrue(data == 100);
        assertTrue(firstTable->tryFind(6, data));
        assertTrue(data == 200);
        assertTrue(firstTable->tryFind(3, data));
        assertTrue(data == 300);

        assertFalse(firstTable->tryFind(4, data));

        delete firstTable;
    }

    BinarySearchTreeTestContainsKey::BinarySearchTreeTestContainsKey() :
        SimpleTest("Binary search tree test contains key")
    {
    }

    void BinarySearchTreeTestContainsKey::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->containsKey(1) == true);
        assertFalse(firstTable->containsKey(2) == true);
        assertTrue(firstTable->containsKey(3) == true);
        assertFalse(firstTable->containsKey(4) == true);
        assertTrue(firstTable->containsKey(6) == true);

        delete firstTable;
    }

    BinarySearchTreeTestClear::BinarySearchTreeTestClear() :
        SimpleTest("Binary search tree test clear")
    {
    }

    void BinarySearchTreeTestClear::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertTrue(firstTable->size() == 3);

        firstTable->clear();

        assertFalse(firstTable->size() == 3);
        assertTrue(firstTable->size() == 0);

        delete firstTable;
    }

    BinarySearchTreeTestIsEmpty::BinarySearchTreeTestIsEmpty() :
        SimpleTest("Binary search tree test is empty")
    {
    }

    void BinarySearchTreeTestIsEmpty::test() {
        structures::BinarySearchTree<int, int>* firstTable = new structures::BinarySearchTree<int, int>();

        assertTrue(firstTable->isEmpty() == true);

        firstTable->insert(1, 100);
        firstTable->insert(6, 200);
        firstTable->insert(3, 300);

        assertFalse(firstTable->isEmpty() == true);

        firstTable->clear();

        assertTrue(firstTable->isEmpty() == true);

        delete firstTable;
    }

    //power test

    TablePowerTest::TablePowerTest(std::string name) :
        SimpleTest(std::move(name))
    {
    }

    int TablePowerTest::getRandomNumber(int low, int high) {
        return rand() % (high - low) + low;
    }

    void TablePowerTest::test() {
        srand(time(NULL));
        structures::DoubleLinkedList<int>* keys = new structures::DoubleLinkedList<int>();
        structures::Table<int, int>* newTable = createTable(*keys);

        Scenario* scenario;
        char currentScenario = getCurrentScenario();
        switch (currentScenario) {
            case('A'):
                scenario = new ScenarioA();
                break;
            case('B'):
                scenario = new ScenarioB();
                break;
            default:
                throw std::logic_error("Unknown error occured, what even happened?");
        }

        std::ofstream outputFile;
        outputFile.open("analysis/power_analysis/" + getName() + "/" + currentScenario + ".csv");
        outputFile << "operation;duration;index\n";

        //main loop
        int operationInsertCount = 0;
        int operationRemoveCount = 0;
        int operationTryFindCount = 0;

        int dummyValue;

        for (int i = 0; i < iterationCount_; i++) {
            switch(getRandomNumber(1, 4)) {
                case 1: {
                    if (operationInsertCount >= scenario->getInsertCount()) {
                        i--;
                        continue;
                    }

                    int randomKey = getRandomNumber(0, maxKeyCount_);
                    while (newTable->containsKey(randomKey)) {
                        randomKey = getRandomNumber(0, maxKeyCount_);
                    }
                    operationInsertCount++;

                    int randomValue = getRandomNumber(0, SHRT_MAX);
                    keys->add(randomKey);

                    SimpleTest::startStopwatch();
                    newTable->insert(randomKey, randomValue);
                    SimpleTest::stopStopwatch();

                    outputFile << "insert;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";

                    break;
                }
                case 2: {
                    if (operationRemoveCount >= scenario->getRemoveCount()) {
                        i--;
                        continue;
                    }
                    operationRemoveCount++;

                    SimpleTest::startStopwatch();
                    newTable->remove(keys->removeAt(0));
                    SimpleTest::stopStopwatch();

                    outputFile << "remove;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";

                    break;
                }
                case 3: {
                    if (operationTryFindCount >= scenario->getTryFindCount()) {
                        i--;
                        continue;
                    }
                    operationTryFindCount++;

                    SimpleTest::startStopwatch();
                    newTable->tryFind(keys->at(0), dummyValue);
                    SimpleTest::stopStopwatch();

                    outputFile << "tryFind;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";

                    break;
                }
            }
            outputFile << std::to_string(i + 1);
            outputFile << "\n";
        }
        outputFile.close();

        delete scenario;
        delete newTable;
        delete keys;
    }

    SortedSequenceTablePowerTest::SortedSequenceTablePowerTest(std::string name) :
        TablePowerTest(std::move(name))
    {
    }

    structures::Table<int, int>* SortedSequenceTablePowerTest::createTable(structures::DoubleLinkedList<int>& keys) {
        structures::SortedSequenceTable<int, int>* table = new structures::SortedSequenceTable<int, int>();
        int randomKey;
        for (int i = 0; i < 60000; i++) {
            randomKey = getRandomNumber(0, maxKeyCount_);
            try {
                table->insert(randomKey, getRandomNumber(0, SHRT_MAX));
            } catch (std::logic_error& e) {
                i--;
                continue;
            }
            keys.add(randomKey);
        }

        return table;
    }

    BinarySearchTreePowerTest::BinarySearchTreePowerTest(std::string name) :
        TablePowerTest(std::move(name))
    {
    }

    structures::Table<int, int>* BinarySearchTreePowerTest::createTable(structures::DoubleLinkedList<int>& keys) {
        structures::BinarySearchTree<int, int>* table = new structures::BinarySearchTree<int, int>();
        int randomKey;
        for (int i = 0; i < 60000; i++) {
            randomKey = getRandomNumber(0, maxKeyCount_);
            try {
                table->insert(randomKey, getRandomNumber(0, SHRT_MAX));
            } catch (std::logic_error& e) {
                i--;
                continue;
            }
            keys.add(randomKey);
        }

        return table;
    }

    SortedSequenceTablePowerTestScenarioA::SortedSequenceTablePowerTestScenarioA() :
        SortedSequenceTablePowerTest("SortedSequenceTable power test scenario A")
    {
    }

    SortedSequenceTablePowerTestScenarioB::SortedSequenceTablePowerTestScenarioB() :
        SortedSequenceTablePowerTest("SortedSequenceTable power test scenario B")
    {
    }

    BinarySearchTreePowerTestScenarioA::BinarySearchTreePowerTestScenarioA() :
        BinarySearchTreePowerTest("BinarySearchTree power test scenario A")
    {
    }

    BinarySearchTreePowerTestScenarioB::BinarySearchTreePowerTestScenarioB() :
        BinarySearchTreePowerTest("BinarySearchTree power test scenario B")
    {
    }

    //time analysis

    TableTimeAnalysis::TableTimeAnalysis(std::string name) :
        SimpleTest(std::move(name))
    {
    }

    int TableTimeAnalysis::getRandomNumber(int low, int high) {
        return rand() % (high - low) + low;
    }

    void TableTimeAnalysis::test() {
        srand(time(NULL));
        std::string currentOperation = getCurrentOperation();

        std::ofstream outputFile;
        outputFile.open("analysis/time_analysis/" + getName() + "/" + currentOperation + ".csv");
        outputFile << "operation;duration;index\n";

        int dummyValue;

        //main loop
        for (int i = 10; i < iterationCount_; i += 100) {
            int tableSize = i + 90;
            structures::Table<int, int>* newTable = createTable(tableSize);  //added 90 more values so that pop can be evaluated without error

            for (int y = 0; y < repeatCount_; y++) {
                if (currentOperation == "insert") {
                    int randomValue = getRandomNumber(0, SHRT_MAX);
                    SimpleTest::startStopwatch();
                    newTable->insert(y, randomValue);
                    SimpleTest::stopStopwatch();

                    outputFile << "insert;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                else if (currentOperation == "remove") {
                    SimpleTest::startStopwatch();
                    newTable->remove(tableSize + y);
                    SimpleTest::stopStopwatch();

                    outputFile << "remove;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                else if (currentOperation == "tryFind") {
                    SimpleTest::startStopwatch();
                    newTable->tryFind(tableSize + y, dummyValue);
                    SimpleTest::stopStopwatch();

                    outputFile << "tryFind;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                outputFile << std::to_string(i + 1);
                outputFile << "\n";
            }
            delete newTable;
        }
        outputFile.close();
    }

    //sorted sequence table time analysis

    SortedSequenceTableTimeAnalysis::SortedSequenceTableTimeAnalysis(std::string name) :
        TableTimeAnalysis(std::move(name))
    {
    }

    structures::Table<int, int>* SortedSequenceTableTimeAnalysis::createTable(int size) {
        structures::SortedSequenceTable<int, int>* table = new structures::SortedSequenceTable<int, int>();
        for (int i = size; i < size * 2; i++) {
            table->insert(i, getRandomNumber(0, SHRT_MAX));
        }
        return table;
    }

    //priority queue two lists time analysis

    BinarySearchTreeTimeAnalysis::BinarySearchTreeTimeAnalysis(std::string name) :
        TableTimeAnalysis(std::move(name))
    {
    }

    structures::Table<int, int>* BinarySearchTreeTimeAnalysis::createTable(int size) {
        structures::BinarySearchTree<int, int>* table = new structures::BinarySearchTree<int, int>();
        for (int i = size; i < size * 2; i++) {
            table->insert(i, getRandomNumber(0, SHRT_MAX));
        }
        return table;
    }

//operations

    SortedSequenceTableTimeAnalysisInsert::SortedSequenceTableTimeAnalysisInsert() :
            SortedSequenceTableTimeAnalysis("SortedSequenceTable time analysis insert")
    {
    }

    SortedSequenceTableTimeAnalysisRemove::SortedSequenceTableTimeAnalysisRemove() :
            SortedSequenceTableTimeAnalysis("SortedSequenceTable time analysis remove")
    {
    }

    SortedSequenceTableTimeAnalysisTryFind::SortedSequenceTableTimeAnalysisTryFind() :
            SortedSequenceTableTimeAnalysis("SortedSequenceTable time analysis tryFind")
    {
    }

    BinarySearchTreeTimeAnalysisInsert::BinarySearchTreeTimeAnalysisInsert() :
            BinarySearchTreeTimeAnalysis("BinarySearchTree time analysis insert")
    {
    }

    BinarySearchTreeTimeAnalysisRemove::BinarySearchTreeTimeAnalysisRemove() :
            BinarySearchTreeTimeAnalysis("BinarySearchTree time analysis remove")
    {
    }

    BinarySearchTreeTimeAnalysisTryFind::BinarySearchTreeTimeAnalysisTryFind() :
            BinarySearchTreeTimeAnalysis("BinarySearchTree time analysis tryFind")
    {
    }
}
