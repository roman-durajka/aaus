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
}
