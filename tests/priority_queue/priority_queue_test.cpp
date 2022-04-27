#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"
#include <fstream>
#include <iostream>

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

        //power test

        addTest(new PriorityQueueTwoListsPowerTestScenarioA());
        addTest(new PriorityQueueTwoListsPowerTestScenarioB());
        addTest(new PriorityQueueTwoListsPowerTestScenarioC());
    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());

        addTest(new HeapTestCopyConstructor());
        addTest(new HeapTestAssign());
        addTest(new HeapTestPush());
        addTest(new HeapTestPop());

        //power test

        addTest(new HeapPowerTestScenarioA());
        addTest(new HeapPowerTestScenarioB());
        addTest(new HeapPowerTestScenarioC());
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

    //power test

    PriorityQueuePowerTest::PriorityQueuePowerTest(std::string name) :
        SimpleTest(std::move(name))
    {
    }

    int PriorityQueuePowerTest::getRandomNumber(int low, int high) {
        return rand() % (high - low) + low;
    }

    void PriorityQueuePowerTest::test() {
        srand(time(NULL));
        structures::PriorityQueue<int>* newPriorityQueue = createPriorityQueue();

        Scenario* scenario;
        char currentScenario = getCurrentScenario();
        switch (currentScenario) {
            case('A'):
                scenario = new ScenarioA();
                break;
            case('B'):
                scenario = new ScenarioB();
                break;
            case('C'):
                scenario = new ScenarioC();
                break;
            default:
                throw std::logic_error("Unknown error occured, what even happened?");
        }

        std::ofstream outputFile;
        outputFile.open("analysis/power_analysis/" + getName() + "/" + currentScenario + ".csv");
        outputFile << "operation;duration;index\n";

        //main loop
        int operationPushCount = 0;
        int opreationPopCount = 0;
        int operationPeekCount = 0;

        for (int i = 0; i < iterationCount_; i++) {
            switch(getRandomNumber(1, 4)) {
                case 1: {
                    if (operationPushCount >= scenario->getPushCount()) {
                        i--;
                        continue;
                    }
                    operationPushCount++;

                    int randomValue = getRandomNumber(0, SHRT_MAX);
                    int randomPriority = getRandomNumber(0, maxPriorityCount_);

                    SimpleTest::startStopwatch();
                    newPriorityQueue->push(randomPriority, randomValue);
                    SimpleTest::stopStopwatch();

                    outputFile << "push;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";

                    break;
                }
                case 2: {
                    if (opreationPopCount >= scenario->getPopCount()) {
                        i--;
                        continue;
                    }
                    opreationPopCount++;

                    SimpleTest::startStopwatch();
                    newPriorityQueue->pop();
                    SimpleTest::stopStopwatch();

                    outputFile << "pop;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";

                    break;
                }
                case 3: {
                    if (operationPeekCount >= scenario->getPeekCount()) {
                        i--;
                        continue;
                    }
                    operationPeekCount++;

                    SimpleTest::startStopwatch();
                    newPriorityQueue->peek();
                    SimpleTest::stopStopwatch();

                    outputFile << "peek;";
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
        delete newPriorityQueue;
    }

    HeapPowerTest::HeapPowerTest(std::string name) :
        PriorityQueuePowerTest(std::move(name))
    {
    }

    structures::PriorityQueue<int>* HeapPowerTest::createPriorityQueue() {
        structures::Heap<int>* heap = new structures::Heap<int>();
        for (int i = 0; i < iterationCount_; i++) {
            heap->push(getRandomNumber(0, maxPriorityCount_), getRandomNumber(0, SHRT_MAX));
        }
        return heap;
    }

    PriorityQueueTwoListsPowerTest::PriorityQueueTwoListsPowerTest(std::string name) :
        PriorityQueuePowerTest(std::move(name))
    {
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsPowerTest::createPriorityQueue() {
        structures::PriorityQueueTwoLists<int>* priorityQueueTwoLists = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < iterationCount_; i++) {
            priorityQueueTwoLists->push(getRandomNumber(0, maxPriorityCount_), getRandomNumber(0, SHRT_MAX));
        }
        return priorityQueueTwoLists;
    }

    HeapPowerTestScenarioA::HeapPowerTestScenarioA() :
        HeapPowerTest("Heap power test scenario A")
    {
    }

    HeapPowerTestScenarioB::HeapPowerTestScenarioB() :
        HeapPowerTest("Heap power test scenario B")
    {
    }

    HeapPowerTestScenarioC::HeapPowerTestScenarioC() :
        HeapPowerTest("Heap power test scenario C")
    {
    }

    PriorityQueueTwoListsPowerTestScenarioA::PriorityQueueTwoListsPowerTestScenarioA() :
        PriorityQueueTwoListsPowerTest("PriorityQueueTwoLists power test scenario A")
    {
    }

    PriorityQueueTwoListsPowerTestScenarioB::PriorityQueueTwoListsPowerTestScenarioB() :
        PriorityQueueTwoListsPowerTest("PriorityQueueTwoLists power test scenario B")
    {
    }

    PriorityQueueTwoListsPowerTestScenarioC::PriorityQueueTwoListsPowerTestScenarioC() :
        PriorityQueueTwoListsPowerTest("PriorityQueueTwoLists power test scenario C")
    {
    }

    //time analysis

    TimeAnalysis::TimeAnalysis(std::string name) :
        SimpleTest(std::move(name))
    {
    }

    int TimeAnalysis::getRandomNumber(int low, int high) {
        return rand() % (high - low) + low;
    }

    void TimeAnalysis::test() {
        srand(time(NULL));
        std::string currentOperation = getCurrentOperation();

        std::ofstream outputFile;
        outputFile.open("analysis/time_analysis/" + getName() + "/" + currentOperation + ".csv");
        outputFile << "operation;duration;index\n";

        int randomIndex;

        //main loop
        for (int i = 10; i < iterationCount_; i += 100) {
            structures::List<int>* newList = createList(i);

            for (int y = 0; y < repeatCount_; y++) {
                randomIndex = getRandomNumber(0, newList->size());

                if (currentOperation == "insert") {
                    SimpleTest::startStopwatch();
                    newList->insert(0, randomIndex);
                    SimpleTest::stopStopwatch();

                    outputFile << "insert;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                else if (currentOperation == "removeAt") {
                    SimpleTest::startStopwatch();
                    newList->removeAt(randomIndex);
                    SimpleTest::stopStopwatch();
                    newList->add(0);

                    outputFile << "removeAt;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                else if (currentOperation == "at") {
                    SimpleTest::startStopwatch();
                    newList->at(randomIndex);
                    SimpleTest::stopStopwatch();

                    outputFile << "at;";
                    outputFile << SimpleTest::getElapsedTime().count();
                    outputFile << ";";
                }
                outputFile << std::to_string(i + 1);
                outputFile << "\n";
            }
            delete newList;
        }
        outputFile.close();
    }

    //heap time analysis

    HeapTimeAnalysis::HeapTimeAnalysis(std::string name) :
        TimeAnalysis(std::move(name))
    {
    }

    structures::PriorityQueue<int>* HeapTimeAnalysis::createPriorityQueue(int size) {
        structures::Heap<int>* heap = new structures::Heap<int>();
        for (int i = 0; i < size; i++) {
            heap->push(getRandomNumber(0, maxPriorityCount_), getRandomNumber(0, SHRT_MAX));
        }
        return heap;
    }

    HeapTimeAnalysis::HeapTimeAnalysis(std::string name) :
        TimeAnalysis(std::move(name))
    {
    }

    //priority queue two lists time analysis

    structures::List<int>* DoubleLinkedListTimeAnalysis::createList(int size) {
        structures::PriorityQueueTwoLists<int>* priorityQueue = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < size; i++) {
            priorityQueue->push(getRandomNumber(0, maxPriorityCount_), getRandomNumber(0, SHRT_MAX));
        }
        return priorityQueue;
    }

//operations

    HeapTimeAnalysisPush::HeapTimeAnalysisPush() :
            HeapTimeAnalysis("Heap time analysis push")
    {
    }

    HeapTimeAnalysisPop::HeapTimeAnalysisPop() :
            HeapTimeAnalysis("Heap time analysis pop")
    {
    }

    HeapTimeAnalysisPeek::HeapTimeAnalysisPeek() :
            HeapTimeAnalysis("Heap time analysis peek")
    {
    }

    PriorityQueueTwoListsTimeAnalysisPush::PriorityQueueTwoListsTimeAnalysisPush() :
            PriorityQueueTwoListsTimeAnalysis("PriorityQueueTwoLists time analysis push")
    {
    }

    PriorityQueueTwoListsTimeAnalysisPop::PriorityQueueTwoListsTimeAnalysisPop() :
            PriorityQueueTwoListsTimeAnalysis("PriorityQueueTwoLists time analysis pop")
    {
    }

    PriorityQueueTwoListsTimeAnalysisPeek::PriorityQueueTwoListsTimeAnalysisPeek() :
            PriorityQueueTwoListsTimeAnalysis("PriorityQueueTwoLists time analysis peek")
    {
    }
}
