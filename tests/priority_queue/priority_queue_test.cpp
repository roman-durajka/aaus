#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"

namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
        this->logPass("Compiled.");
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
    }

    PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }

    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());

        addTest(new PriorityQueueTwoListsTestCopyConstructor());
        addTest(new PriorityQueueTwoListsTestAssign());
        addTest(new PriorityQueueTwoListsTestSize());
        addTest(new PriorityQueueTwoListsTestClear());
        addTest(new PriorityQueueTwoListsTestPush());
        addTest(new PriorityQueueTwoListsTestPop());
        addTest(new PriorityQueueTwoListsTestPeek());
        addTest(new PriorityQueueTwoListsTestPeekPriority());
    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());

        addTest(new HeapTestCopyConstructor());
        addTest(new HeapTestAssign());
        addTest(new HeapTestPush());
        addTest(new HeapTestPop());
    }

    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        addTest(new PriorityQueueUnsortedArrayListTestOverall());
        addTest(new PriorityQueueSortedArrayListTestOverall());
        addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }

    //heap tests

    HeapTestCopyConstructor::HeapTestCopyConstructor() :
        SimpleTest("Heap test copy constructor")
    {
    }

    void HeapTestCopyConstructor::test() {
        structures::Heap<int>* firstHeap = new structures::Heap<int>();

        firstHeap->push(10, 10);
        firstHeap->push(20, 20);
        firstHeap->push(30, 30);

        structures::Heap<int>* secondHeap = new structures::Heap<int>(*firstHeap);

        assertTrue(secondHeap->peekPriority() == 10);
        assertTrue(secondHeap->pop() == 10);
        assertTrue(secondHeap->peekPriority() == 20);
        assertTrue(secondHeap->pop() == 20);
        assertTrue(secondHeap->peekPriority() == 30);
        assertTrue(secondHeap->pop() == 30);

        delete firstHeap;
        delete secondHeap;
    }

    HeapTestAssign::HeapTestAssign() :
        SimpleTest("Heap test assign")
    {
    }

    void HeapTestAssign::test() {
        structures::Heap<int>* firstHeap = new structures::Heap<int>();
        structures::Heap<int>* secondHeap = new structures::Heap<int>();

        firstHeap->push(10, 10);
        firstHeap->push(20, 20);
        firstHeap->push(30, 30);

        secondHeap->assign(*firstHeap);

        assertTrue(secondHeap->peekPriority() == 10);
        assertTrue(secondHeap->pop() == 10);
        assertTrue(secondHeap->peekPriority() == 20);
        assertTrue(secondHeap->pop() == 20);
        assertTrue(secondHeap->peekPriority() == 30);
        assertTrue(secondHeap->pop() == 30);

        delete firstHeap;
        delete secondHeap;
    }

    HeapTestPush::HeapTestPush() :
        SimpleTest("Heap test push")
    {
    }

    void HeapTestPush::test() {
        structures::Heap<int>* heap = new structures::Heap<int>();

        heap->push(10, 10);
        assertTrue(heap->pop() == 10);

        heap->push(20, 20);
        heap->push(10,10);

        assertTrue(heap->peekPriority() == 10);
        assertTrue(heap->pop() == 10);

        heap->push(5, 5);

        assertTrue(heap->peekPriority() == 5);
        assertTrue(heap->pop() == 5);
        assertTrue(heap->peekPriority() == 20);
        assertTrue(heap->pop() == 20);

        delete heap;
    }

    HeapTestPop::HeapTestPop() :
        SimpleTest("Heap test pop")
    {
    }

    void HeapTestPop::test() {
        structures::Heap<int>* heap = new structures::Heap<int>();

        heap->push(10, 10);
        assertTrue(heap->pop() == 10);

        heap->push(20, 20);
        heap->push(10,10);

        assertTrue(heap->peekPriority() == 10);
        assertTrue(heap->pop() == 10);

        heap->push(5, 5);

        assertTrue(heap->peekPriority() == 5);
        assertTrue(heap->pop() == 5);
        assertTrue(heap->peekPriority() == 20);
        assertTrue(heap->pop() == 20);

        delete heap;
    }

    //priority queue two lists tests

    PriorityQueueTwoListsTestCopyConstructor::PriorityQueueTwoListsTestCopyConstructor() :
        SimpleTest("Priority queue two lists test copy constructor")
    {
    }

    void PriorityQueueTwoListsTestCopyConstructor::test() {
        structures::PriorityQueueTwoLists<int>* firstQueue = new structures::PriorityQueueTwoLists<int>();

        firstQueue->push(10, 10);
        firstQueue->push(20, 20);
        firstQueue->push(30, 30);

        structures::PriorityQueueTwoLists<int>* secondQueue = new structures::PriorityQueueTwoLists<int>(*firstQueue);

        assertTrue(secondQueue->peekPriority() == 10);
        assertTrue(secondQueue->pop() == 10);
        assertTrue(secondQueue->peekPriority() == 20);
        assertTrue(secondQueue->pop() == 20);
        assertTrue(secondQueue->peekPriority() == 30);
        assertTrue(secondQueue->pop() == 30);

        delete firstQueue;
        delete secondQueue;
    }

    PriorityQueueTwoListsTestAssign::PriorityQueueTwoListsTestAssign() :
        SimpleTest("Priority queue two lists test assign")
    {
    }

    void PriorityQueueTwoListsTestAssign::test() {
        structures::PriorityQueueTwoLists<int>* firstQueue = new structures::PriorityQueueTwoLists<int>();
        structures::PriorityQueueTwoLists<int>* secondQueue = new structures::PriorityQueueTwoLists<int>();

        firstQueue->push(10, 10);
        firstQueue->push(20, 20);
        firstQueue->push(30, 30);

        secondQueue->assign(*firstQueue);

        assertTrue(secondQueue->peekPriority() == 10);
        assertTrue(secondQueue->pop() == 10);
        assertTrue(secondQueue->peekPriority() == 20);
        assertTrue(secondQueue->pop() == 20);
        assertTrue(secondQueue->peekPriority() == 30);
        assertTrue(secondQueue->pop() == 30);

        delete firstQueue;
        delete secondQueue;
    }

    PriorityQueueTwoListsTestSize::PriorityQueueTwoListsTestSize() :
        SimpleTest("Priority queue two lists test size")
    {
    }

    void PriorityQueueTwoListsTestSize::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        assertTrue(newQueue->size() == 0);
        newQueue->push(10, 10);
        assertTrue(newQueue->size() == 1);
        newQueue->push(20, 20);
        assertTrue(newQueue->size() == 2);
        newQueue->push(30, 30);
        assertTrue(newQueue->size() == 3);
        newQueue->pop();
        assertTrue(newQueue->size() == 2);

        delete newQueue;
    }

    PriorityQueueTwoListsTestClear::PriorityQueueTwoListsTestClear() :
        SimpleTest("Priority queue two lists test clear")
    {
    }

    void PriorityQueueTwoListsTestClear::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        assertTrue(newQueue->size() == 0);
        newQueue->push(10, 10);
        newQueue->push(20, 20);
        newQueue->push(30, 30);
        newQueue->push(40, 40);
        newQueue->push(50, 50);

        assertTrue(newQueue->size() == 5);

        newQueue->clear();

        assertTrue(newQueue->size() == 0);

        delete newQueue;
    }

    PriorityQueueTwoListsTestPush::PriorityQueueTwoListsTestPush() :
        SimpleTest("Priority queue two lists test push")
    {
    }

    void PriorityQueueTwoListsTestPush::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        assertTrue(newQueue->size() == 0);
        newQueue->push(10, 10);
        newQueue->push(20, 20);
        newQueue->push(30, 30);
        newQueue->push(40, 40);
        newQueue->push(50, 50);

        assertTrue(newQueue->size() == 5);
        assertTrue(newQueue->pop() == 10);
        assertTrue(newQueue->pop() == 20);
        assertTrue(newQueue->size() == 3);

        newQueue->push(100, 100);
        newQueue->push(120, 120);
        assertTrue(newQueue->size() == 5);

        delete newQueue;
    }

    PriorityQueueTwoListsTestPop::PriorityQueueTwoListsTestPop() :
        SimpleTest("Priority queue two lists test pop")
    {
    }

    void PriorityQueueTwoListsTestPop::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        assertTrue(newQueue->size() == 0);
        newQueue->push(10, 10);
        newQueue->push(20, 20);
        newQueue->push(30, 30);
        newQueue->push(40, 40);
        newQueue->push(50, 50);

        assertTrue(newQueue->size() == 5);
        assertTrue(newQueue->pop() == 10);
        assertTrue(newQueue->pop() == 20);
        assertTrue(newQueue->size() == 3);

        newQueue->push(100, 100);
        newQueue->push(120, 120);
        assertTrue(newQueue->size() == 5);

        assertTrue(newQueue->pop() == 30);
        assertTrue(newQueue->pop() == 40);
        assertTrue(newQueue->pop() == 50);
        assertTrue(newQueue->pop() == 100);
        assertTrue(newQueue->pop() == 120);
        assertTrue(newQueue->size() == 0);

        delete newQueue;
    }

    PriorityQueueTwoListsTestPeek::PriorityQueueTwoListsTestPeek() :
        SimpleTest("Priority queue two lists test peek")
    {
    }

    void PriorityQueueTwoListsTestPeek::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        newQueue->push(10, 10);
        newQueue->push(20, 20);
        newQueue->push(30, 30);
        newQueue->push(40, 40);
        newQueue->push(50, 50);

        assertTrue(newQueue->peek() == 10);
        assertTrue(newQueue->pop() == 10);
        assertTrue(newQueue->peek() == 20);

        newQueue->push(1, 1);
        assertTrue(newQueue->peek() == 1);

        delete newQueue;
    }

    PriorityQueueTwoListsTestPeekPriority::PriorityQueueTwoListsTestPeekPriority() :
        SimpleTest("Priority queue two lists test peek priority")
    {
    }

    void PriorityQueueTwoListsTestPeekPriority::test() {
        structures::PriorityQueueTwoLists<int>* newQueue = new structures::PriorityQueueTwoLists<int>();

        newQueue->push(10, 10);
        newQueue->push(20, 20);
        newQueue->push(30, 30);
        newQueue->push(40, 40);
        newQueue->push(50, 50);

        assertTrue(newQueue->peekPriority() == 10);
        assertTrue(newQueue->pop() == 10);
        assertTrue(newQueue->peekPriority() == 20);

        newQueue->push(1, 1);
        assertTrue(newQueue->peekPriority() == 1);

        delete newQueue;
    }
}
