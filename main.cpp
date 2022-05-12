
#include "tests/vector/vector_test.h"
#include "tests/array/array_test.h"
#include "tests/matrix/matrix_test.h"
#include "tests/list/list_test.h"
#include "tests/stack/stack_test.h"
#include "tests/queue/queue_test.h"
#include "tests/priority_queue/priority_queue_test.h"
#include "tests/table/table_test.h"
#include "tests/tree/tree_test.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <cstdio>
int main()
{
	ui::UiKeeper keeper;
	structures::Logger::getInstance().registerConsumer(&keeper);

	keeper.registerTest(new tests::VectorTestOverall());

	keeper.registerTest(new tests::ArrayTestOverall());

	keeper.registerTest(new tests::CoherentMatrixTestOverall());
	keeper.registerTest(new tests::IncoherentMatrixTestOverall());

	keeper.registerTest(new tests::ListTestOverall());

	// TODO 05: Stack
	//keeper.registerTest(new tests::StackTestOverall());

	// TODO 05: Queue
	//keeper.registerTest(new tests::QueueTestOverall());

	keeper.registerTest(new tests::PriorityQueueTestOverall());

	// TODO 07: Tree
	keeper.registerTest(new tests::TreeTestOverall());

	// TODO 08: Table
	keeper.registerTest(new tests::TableTestOverall());

	bool run = true;
	do
	{
		keeper.printTestMenu();
		std::vector<int> choice = keeper.readTestChoice();
		keeper.markTests(choice);
		keeper.resetTests();
		keeper.runTests();
		keeper.showTestResults();
		keeper.showLog();
		keeper.clearLog();
		run = keeper.readShouldContinue();
	}
	while (run);
}
