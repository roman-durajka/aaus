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
}
