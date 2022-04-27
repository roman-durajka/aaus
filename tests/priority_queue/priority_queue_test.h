#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"

namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };

    //heap tests

    class HeapTestCopyConstructor
        : public SimpleTest
    {
        public:
            HeapTestCopyConstructor();
            void test() override;
    };

    class HeapTestAssign
        : public SimpleTest
    {
        public:
            HeapTestAssign();
            void test() override;
    };

    class HeapTestPush
        : public SimpleTest
    {
        public:
            HeapTestPush();
            void test() override;
    };

    class HeapTestPop
        : public SimpleTest
    {
        public:
            HeapTestPop();
            void test() override;
    };

    //priority queue two lists tests

    class PriorityQueueTwoListsTestCopyConstructor
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestCopyConstructor();
            void test() override;
    };

    class PriorityQueueTwoListsTestAssign
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestAssign();
            void test() override;
    };

    class PriorityQueueTwoListsTestSize
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestSize();
            void test() override;
    };

    class PriorityQueueTwoListsTestClear
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestClear();
            void test() override;
    };

    class PriorityQueueTwoListsTestPush
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestPush();
            void test() override;
    };

    class PriorityQueueTwoListsTestPop
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestPop();
            void test() override;
    };

    class PriorityQueueTwoListsTestPeek
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestPeek();
            void test() override;
    };

    class PriorityQueueTwoListsTestPeekPriority
        : public SimpleTest
    {
        public:
            PriorityQueueTwoListsTestPeekPriority();
            void test() override;
    };

    //power test

    class PriorityQueuePowerTest
        : public SimpleTest
    {
        public:
            PriorityQueuePowerTest(std::string name);
            virtual structures::PriorityQueue<int>* createPriorityQueue() = 0;
            virtual char getCurrentScenario() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 100000;
            static const int maxPriorityCount_ = 100000;

        class Scenario
        {
            private:
                int pushCount_ = iterationCount_ / 100;
                int popCount_ = iterationCount_ / 100;
                int peekCount_ = iterationCount_ / 100;

            public:
                Scenario(int pushCount, int popCount, int peekCount)
                {
                    pushCount_ *= pushCount;
                    popCount_ *= popCount;
                    peekCount_ *= peekCount;
                };

                inline int getPushCount() { return pushCount_; }
                inline int getPopCount() { return popCount_ ;}
                inline int getPeekCount() { return peekCount_; }
        };

        class ScenarioA : public Scenario {
            public:
                ScenarioA() : Scenario(35, 35, 30) {};
        };

        class ScenarioB : public Scenario {
            public:
                ScenarioB() : Scenario(50, 30, 20) {};
        };

        class ScenarioC : public Scenario {
            public:
                ScenarioC() : Scenario(70, 25, 5) {};
        };
    };

    class HeapPowerTest
        : public PriorityQueuePowerTest
    {
        public:
            HeapPowerTest(std::string name);
            structures::PriorityQueue<int>* createPriorityQueue() override;
            std::string getName() override { return "Heap"; }
    };

    class PriorityQueueTwoListsPowerTest
        : public PriorityQueuePowerTest
    {
        public:
            PriorityQueueTwoListsPowerTest(std::string name);
            structures::PriorityQueue<int>* createPriorityQueue() override;
            std::string getName() override { return "PriorityQueueTwoLists"; }
    };

    class HeapPowerTestScenarioA
        : public HeapPowerTest {
        private:
            char scenario = 'A';
        public:
            HeapPowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class HeapPowerTestScenarioB
        : public HeapPowerTest {
        private:
            char scenario = 'B';
        public:
        HeapPowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    class HeapPowerTestScenarioC
        : public HeapPowerTest {
        private:
            char scenario = 'C';
        public:
            HeapPowerTestScenarioC();
            char getCurrentScenario() override { return scenario; }
    };

    class PriorityQueueTwoListsPowerTestScenarioA
        : public PriorityQueueTwoListsPowerTest {
        private:
            char scenario = 'A';
        public:
            PriorityQueueTwoListsPowerTestScenarioA();
            char getCurrentScenario() override { return scenario; }
    };

    class PriorityQueueTwoListsPowerTestScenarioB
        : public PriorityQueueTwoListsPowerTest {
        private:
            char scenario = 'B';
        public:
            PriorityQueueTwoListsPowerTestScenarioB();
            char getCurrentScenario() override { return scenario; }
    };

    class PriorityQueueTwoListsPowerTestScenarioC
        : public PriorityQueueTwoListsPowerTest {
        private:
            char scenario = 'C';
        public:
            PriorityQueueTwoListsPowerTestScenarioC();
            char getCurrentScenario() override { return scenario; }
    };

    //time analysis

    class TimeAnalysis
        : public SimpleTest {
        public:
            TimeAnalysis(std::string name);
            virtual structures::PriorityQueue<int>* createPriorityQueue(int size) = 0;
            virtual std::string getCurrentOperation() = 0;
            virtual std::string getName() = 0;
            int getRandomNumber(int low, int high);
            void test() override;
        protected:
            static const int iterationCount_ = 10000;
            static const int repeatCount_ = 100;
            static const int maxPriorityCount_ = 100000;
    };

    class HeapTimeAnalysis
        : public TimeAnalysis
    {
        public:
            HeapTimeAnalysis(std::string name);
            structures::PriorityQueue<int>* createPriorityQueue(int size) override;
            std::string getName() override { return "Heap"; }
    };

    class PriorityQueueTwoListsTimeAnalysis
        : public TimeAnalysis
    {
        public:
            PriorityQueueTwoListsTimeAnalysis(std::string name);
            structures::PriorityQueue<int>* createPriorityQueue(int size) override;
            std::string getName() override { return "PriorityQueueTwoLists"; }
    };

    //heap operations

    class HeapTimeAnalysisPush
        : public HeapTimeAnalysis {
        private:
            std::string operation_ = "push";
        public:
            HeapTimeAnalysisPush();
            std::string getCurrentOperation() override { return operation_; }
    };

    class HeapTimeAnalysisPop
        : public HeapTimeAnalysis {
        private:
            std::string operation_ = "pop";
        public:
            HeapTimeAnalysisPop();
            std::string getCurrentOperation() override { return operation_; }
    };

    class HeapTimeAnalysisPeek
        : public HeapTimeAnalysis {
        private:
            std::string operation_ = "peek";
        public:
            HeapTimeAnalysisPeek();
            std::string getCurrentOperation() override { return operation_; }
    };

//priority queue two lists operations

class PriorityQueueTwoListsTimeAnalysisPush
        : public PriorityQueueTwoListsTimeAnalysis {
        private:
            std::string operation_ = "push";
        public:
            PriorityQueueTwoListsTimeAnalysisPush();
            std::string getCurrentOperation() override { return operation_; }
    };

    class PriorityQueueTwoListsTimeAnalysisPop
        : public PriorityQueueTwoListsTimeAnalysis {
        private:
            std::string operation_ = "pop";
        public:
            PriorityQueueTwoListsTimeAnalysisPop();
            std::string getCurrentOperation() override { return operation_; }
    };

    class PriorityQueueTwoListsTimeAnalysisPeek
        : public PriorityQueueTwoListsTimeAnalysis {
        private:
            std::string operation_ = "peek";
        public:
            PriorityQueueTwoListsTimeAnalysisPop();
            std::string getCurrentOperation() override { return operation_; }
    };
}

}
