#pragma once

#include "../test.h"
#include "../../structures/list/array_list.h"
#include "../../structures/list/linked_list.h"
#include "../../structures/list/double_linked_list.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania listu avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class ListTestInterface
		: public SimpleTest
	{
	public:
		ListTestInterface(std::string name);
		void test() override;

	protected:
		virtual structures::List<int>* makeList() const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody ArrayListu.
	/// </summary>
	class ArrayListTestInterface
		: public ListTestInterface
	{
	public:
		ArrayListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zavola vsetky metody LinkedListu.
	/// </summary>
	class LinkedListTestInterface
		: public ListTestInterface
	{
	public:
		LinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zavola vsetky metody DoubleLinkedListu.
	/// </summary>
	class DoubleLinkedListTestInterface
		: public ListTestInterface
	{
	public:
		DoubleLinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList.
	/// </summary>
	class ArrayListTestOverall
		: public ComplexTest
	{
	public:
		ArrayListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class LinkedListTestOverall
		: public ComplexTest
	{
	public:
		LinkedListTestOverall();
	};

    // <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju DoubleLinkedList.
	/// </summary>
	class DoubleLinkedListTestOverall
		: public ComplexTest
	{
	public:
		DoubleLinkedListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList a LinkedList.
	/// </summary>
	class ListTestOverall :
		public ComplexTest
	{
	public:
		ListTestOverall();
	};

	class ArrayListTestSize
        : public SimpleTest
    {
        public:
            ArrayListTestSize();
            void test() override;
    };

    class ArrayListTestAssign
        : public SimpleTest
    {
        public:
            ArrayListTestAssign();
            void test() override;
    };

    class ArrayListTestEquals
        : public SimpleTest
    {
        public:
            ArrayListTestEquals();
            void test() override;
    };

    class ArrayListTestAt
        : public SimpleTest
    {
        public:
            ArrayListTestAt();
            void test() override;
    };

    class ArrayListTestAdd
        : public SimpleTest
    {
        public:
            ArrayListTestAdd();
            void test() override;
    };

    class ArrayListTestInsert
        : public SimpleTest
    {
        public:
            ArrayListTestInsert();
            void test() override;
    };

    class ArrayListTestTryRemove
        : public SimpleTest
    {
        public:
            ArrayListTestTryRemove();
            void test() override;
    };

    class ArrayListTestRemoveAt
        : public SimpleTest
    {
        public:
            ArrayListTestRemoveAt();
            void test() override;
    };

    class ArrayListTestGetIndexOf
        : public SimpleTest
    {
        public:
            ArrayListTestGetIndexOf();
            void test() override;
    };

    class ArrayListTestClear
        : public SimpleTest
    {
        public:
            ArrayListTestClear();
            void test() override;
    };

    //double linked list

	class DoubleLinkedListTestSize
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestSize();
            void test() override;
    };

	class DoubleLinkedListTestAssign
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestAssign();
            void test() override;
    };

    class DoubleLinkedListTestEquals
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestEquals();
            void test() override;
    };

    class DoubleLinkedListTestAt
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestAt();
            void test() override;
    };

    class DoubleLinkedListTestAdd
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestAdd();
            void test() override;
    };

    class DoubleLinkedListTestInsert
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestInsert();
            void test() override;
    };

    class DoubleLinkedListTestTryRemove
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestTryRemove();
            void test() override;
    };

    class DoubleLinkedListTestRemoveAt
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestRemoveAt();
            void test() override;
    };

    class DoubleLinkedListTestGetIndexOf
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestGetIndexOf();
            void test() override;
    };

    class DoubleLinkedListTestClear
        : public SimpleTest
    {
        public:
            DoubleLinkedListTestClear();
            void test() override;
    };

//power test

    class ListPowerTest
        : public SimpleTest
    {
        public:
            ListPowerTest(std::string name);
            virtual structures::List<int>* createList() = 0;
            virtual char getCurrentScenario() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 100000;

        class Scenario
        {
            private:
                int insertCount_ = iterationCount_ / 100;
                int removeAtCount_ = iterationCount_ / 100;
                int atCount_ = iterationCount_ / 100;
                int indexOfCount_ = iterationCount_ / 100;

            public:
                Scenario(int insertCount, int removeAtCount, int atCount, int indexOfCount)
                {
                    insertCount_ *= insertCount;
                    removeAtCount_ *= removeAtCount;
                    atCount_ *= atCount;
                    indexOfCount_ *= indexOfCount;
                };

                inline int getInsertCount() { return insertCount_; }
                inline int getRemoveAtCount() { return removeAtCount_ ;}
                inline int getAtCount() { return atCount_; }
                inline int getIndexOfCount() { return indexOfCount_; }
        };

        class ScenarioA : public Scenario {
            public:
                ScenarioA() : Scenario(20, 20, 50, 10) {};
        };

        class ScenarioB : public Scenario {
            public:
                ScenarioB() : Scenario(35, 35, 20, 10) {};
        };

        class ScenarioC : public Scenario {
            public:
                ScenarioC() : Scenario(45, 45, 5, 5) {};
        };
    };

    class ArrayListPowerTest
        : public ListPowerTest
    {
        public:
            ArrayListPowerTest(std::string name);
            structures::List<int>* createList() override;
            std::string getName() override { return "ArrayList"; }
    };

    class DoubleLinkedListPowerTest
        : public ListPowerTest
    {
        public:
            DoubleLinkedListPowerTest(std::string name);
            structures::List<int>* createList() override;
            std::string getName() override { return "DoubleLinkedList"; }
    };

    class ArrayListPowerTestScenarioA
        : public ArrayListPowerTest {
        private:
            char scenario = 'A';
        public:
            ArrayListPowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class ArrayListPowerTestScenarioB
        : public ArrayListPowerTest {
        private:
            char scenario = 'B';
        public:
        ArrayListPowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    class ArrayListPowerTestScenarioC
        : public ArrayListPowerTest {
        private:
            char scenario = 'C';
        public:
            ArrayListPowerTestScenarioC();
            char getCurrentScenario() override { return scenario; }
    };

    class DoubleLinkedListPowerTestScenarioA
        : public DoubleLinkedListPowerTest {
        private:
            char scenario = 'A';
        public:
            DoubleLinkedListPowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class DoubleLinkedListPowerTestScenarioB
        : public DoubleLinkedListPowerTest {
        private:
            char scenario = 'B';
        public:
            DoubleLinkedListPowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    class DoubleLinkedListPowerTestScenarioC
        : public DoubleLinkedListPowerTest {
        private:
            char scenario = 'C';
        public:
            DoubleLinkedListPowerTestScenarioC();
            char getCurrentScenario() override { return scenario; }
    };

    class TimeAnalysis
        : public SimpleTest {
        public:
            TimeAnalysis(std::string name);
            virtual structures::List<int>* createList(int size) = 0;
            virtual std::string getCurrentOperation() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 10000;
            static const int repeatCount_ = 100;
    };

    class ArrayListTimeAnalysis
        : public TimeAnalysis
    {
        public:
            ArrayListTimeAnalysis(std::string name);
            structures::List<int>* createList(int size) override;
            std::string getName() override { return "ArrayList"; }
    };

    class DoubleLinkedListTimeAnalysis
        : public TimeAnalysis
    {
        public:
            DoubleLinkedListTimeAnalysis(std::string name);
            structures::List<int>* createList(int size) override;
            std::string getName() override { return "DoubleLinkedList"; }
    };

//array list operations

    class ArrayListTimeAnalysisInsert
        : public ArrayListTimeAnalysis {
        private:
            std::string operation_ = "insert";
        public:
            ArrayListTimeAnalysisInsert();
            std::string getCurrentOperation() override { return operation_; }
    };

    class ArrayListTimeAnalysisAt
        : public ArrayListTimeAnalysis {
        private:
            std::string operation_ = "at";
        public:
            ArrayListTimeAnalysisAt();
            std::string getCurrentOperation() override { return operation_; }
    };

    class ArrayListTimeAnalysisRemoveAt
        : public ArrayListTimeAnalysis {
        private:
            std::string operation_ = "removeAt";
        public:
            ArrayListTimeAnalysisRemoveAt();
            std::string getCurrentOperation() override { return operation_; }
    };

//double linked list operations

class DoubleLinkedListTimeAnalysisInsert
        : public DoubleLinkedListTimeAnalysis {
        private:
            std::string operation_ = "insert";
        public:
            DoubleLinkedListTimeAnalysisInsert();
            std::string getCurrentOperation() override { return operation_; }
    };

    class DoubleLinkedListTimeAnalysisAt
        : public DoubleLinkedListTimeAnalysis {
        private:
            std::string operation_ = "at";
        public:
            DoubleLinkedListTimeAnalysisAt();
            std::string getCurrentOperation() override { return operation_; }
    };

    class DoubleLinkedListTimeAnalysisRemoveAt
        : public DoubleLinkedListTimeAnalysis {
        private:
            std::string operation_ = "removeAt";
        public:
            DoubleLinkedListTimeAnalysisRemoveAt();
            std::string getCurrentOperation() override { return operation_; }
    };
}
