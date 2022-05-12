#pragma once

#include "../test.h"
#include "../../structures/table/table.h"
#include "../../structures/list/double_linked_list.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania tabulky avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class TableTestInterface
		: public SimpleTest
	{
	public:
		TableTestInterface();
		void test() override;

	protected:
		virtual structures::Table<int, int>* makeTable() = 0;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class BinarySearchTreeTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class HashTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class LinkedTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class SortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class TreapTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class UnsortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class BinarySearchTreeTestOverall
		: public ComplexTest
	{
	public:
		BinarySearchTreeTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class HashTableTestOverall
		: public ComplexTest
	{
	public:
		HashTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class LinkedTableTestOverall
		: public ComplexTest
	{
	public:
		LinkedTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class SortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		SortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class TreapTestOverall
		: public ComplexTest
	{
	public:
		TreapTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class UnsortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		UnsortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju tabulku.
	/// </summary>
	class TableTestOverall
		: public ComplexTest
	{
	public:
		TableTestOverall();
	};

	//custom tests sorted sequence table
	class SortedSequenceTableTestCopyConstructor
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestCopyConstructor();
		void test() override;
	};

	class SortedSequenceTableTestAssign
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestAssign();
		void test() override;
	};

	class SortedSequenceTableTestEquals
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestEquals();
		void test() override;
	};

	class SortedSequenceTableTestInsert
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestInsert();
		void test() override;
	};

	class SortedSequenceTableTestSize
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestSize();
		void test() override;
	};

	class SortedSequenceTableTestFind
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestFind();
		void test() override;
	};

	class SortedSequenceTableTestRemove
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestRemove();
		void test() override;
	};

	class SortedSequenceTableTestTryFind
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestTryFind();
		void test() override;
	};

	class SortedSequenceTableTestContainsKey
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestContainsKey();
		void test() override;
	};

	class SortedSequenceTableTestClear
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestClear();
		void test() override;
	};

	class SortedSequenceTableTestIsEmpty
		: public SimpleTest
	{
	public:
		SortedSequenceTableTestIsEmpty();
		void test() override;
	};

	//custom tests binary search tree
	class BinarySearchTreeTestCopyConstructor
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestCopyConstructor();
		void test() override;
	};

    class BinarySearchTreeTestSize
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestSize();
		void test() override;
	};

	class BinarySearchTreeTestAssign
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestAssign();
		void test() override;
	};

	class BinarySearchTreeTestEquals
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestEquals();
		void test() override;
	};

	class BinarySearchTreeTestInsert
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestInsert();
		void test() override;
	};

	class BinarySearchTreeTestFind
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestFind();
		void test() override;
	};

	class BinarySearchTreeTestRemove
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestRemove();
		void test() override;
	};

	class BinarySearchTreeTestTryFind
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestTryFind();
		void test() override;
	};

	class BinarySearchTreeTestContainsKey
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestContainsKey();
		void test() override;
	};

	class BinarySearchTreeTestClear
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestClear();
		void test() override;
	};

	class BinarySearchTreeTestIsEmpty
		: public SimpleTest
	{
	public:
		BinarySearchTreeTestIsEmpty();
		void test() override;
	};

	//power test

    class TablePowerTest
        : public SimpleTest
    {
        public:
            TablePowerTest(std::string name);
            virtual structures::Table<int, int>* createTable(structures::DoubleLinkedList<int>& keys) = 0;
            virtual char getCurrentScenario() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 100000;
            static const int maxKeyCount_ = 100000;

        class Scenario
        {
            private:
                int insertCount_ = iterationCount_ / 100;
                int removeCount_ = iterationCount_ / 100;
                int tryFindCount_ = iterationCount_ / 100;

            public:
                Scenario(int insertCount, int removeCount, int tryFindCount)
                {
                    insertCount_ *= insertCount;
                    removeCount_ *= removeCount;
                    tryFindCount_ *= tryFindCount;
                };

                inline int getInsertCount() { return insertCount_; }
                inline int getRemoveCount() { return removeCount_ ;}
                inline int getTryFindCount() { return tryFindCount_; }
        };

        class ScenarioA : public Scenario {
            public:
                ScenarioA() : Scenario(20, 20, 60) {};
        };

        class ScenarioB : public Scenario {
            public:
                ScenarioB() : Scenario(40, 40, 20) {};
        };
    };

    class SortedSequenceTablePowerTest
        : public TablePowerTest
    {
        public:
            SortedSequenceTablePowerTest(std::string name);
            structures::Table<int, int>* createTable(structures::DoubleLinkedList<int>& keys) override;
            std::string getName() override { return "SortedSequenceTable"; }
    };

    class BinarySearchTreePowerTest
        : public TablePowerTest
    {
        public:
            BinarySearchTreePowerTest(std::string name);
            structures::Table<int, int>* createTable(structures::DoubleLinkedList<int>& keys) override;
            std::string getName() override { return "BinarySearchTree"; }
    };

    class SortedSequenceTablePowerTestScenarioA
        : public SortedSequenceTablePowerTest {
        private:
            char scenario = 'A';
        public:
            SortedSequenceTablePowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class SortedSequenceTablePowerTestScenarioB
        : public SortedSequenceTablePowerTest {
        private:
            char scenario = 'B';
        public:
        SortedSequenceTablePowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    class BinarySearchTreePowerTestScenarioA
        : public BinarySearchTreePowerTest {
        private:
            char scenario = 'A';
        public:
            BinarySearchTreePowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class BinarySearchTreePowerTestScenarioB
        : public BinarySearchTreePowerTest {
        private:
            char scenario = 'B';
        public:
            BinarySearchTreePowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    //time analysis

    class TableTimeAnalysis
        : public SimpleTest {
        public:
            TableTimeAnalysis(std::string name);
            virtual structures::Table<int, int>* createTable(int size, structures::DoubleLinkedList<int>& keys) = 0;
            virtual std::string getCurrentOperation() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 10000;
            static const int repeatCount_ = 100;
            static const int maxPriorityCount_ = 100000;
    };

    class SortedSequenceTableTimeAnalysis
        : public TableTimeAnalysis
    {
        public:
            SortedSequenceTableTimeAnalysis(std::string name);
            structures::Table<int, int>* createTable(int size, structures::DoubleLinkedList<int>& keys) override;
            std::string getName() override { return "SortedSequenceTable"; }
    };

    class BinarySearchTreeTimeAnalysis
        : public TableTimeAnalysis
    {
        public:
            BinarySearchTreeTimeAnalysis(std::string name);
            structures::Table<int, int>* createTable(int size, structures::DoubleLinkedList<int>& keys) override;
            std::string getName() override { return "BinarySearchTree"; }
    };

    //sorted sequence table operations

    class SortedSequenceTableTimeAnalysisInsert
        : public SortedSequenceTableTimeAnalysis {
        private:
            std::string operation_ = "insert";
        public:
            SortedSequenceTableTimeAnalysisInsert();
            std::string getCurrentOperation() override { return operation_; }
    };

    class SortedSequenceTableTimeAnalysisRemove
        : public SortedSequenceTableTimeAnalysis {
        private:
            std::string operation_ = "remove";
        public:
            SortedSequenceTableTimeAnalysisRemove();
            std::string getCurrentOperation() override { return operation_; }
    };

    class SortedSequenceTableTimeAnalysisTryFind
        : public SortedSequenceTableTimeAnalysis {
        private:
            std::string operation_ = "tryFind";
        public:
            SortedSequenceTableTimeAnalysisTryFind();
            std::string getCurrentOperation() override { return operation_; }
    };

//binary search tree operations

    class BinarySearchTreeTimeAnalysisInsert
        : public BinarySearchTreeTimeAnalysis {
        private:
            std::string operation_ = "insert";
        public:
            BinarySearchTreeTimeAnalysisInsert();
            std::string getCurrentOperation() override { return operation_; }
    };

    class BinarySearchTreeTimeAnalysisRemove
        : public BinarySearchTreeTimeAnalysis {
        private:
            std::string operation_ = "remove";
        public:
            BinarySearchTreeTimeAnalysisRemove();
            std::string getCurrentOperation() override { return operation_; }
    };

    class BinarySearchTreeTimeAnalysisTryFind
        : public BinarySearchTreeTimeAnalysis {
        private:
            std::string operation_ = "tryFind";
        public:
            BinarySearchTreeTimeAnalysisTryFind();
            std::string getCurrentOperation() override { return operation_; }
    };
}
