#include "matrix_test.h"
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/matrix/incoherent_matrix.h"

#include <fstream>
#include <chrono>

namespace tests
{
	tests::MatrixTestInterface::MatrixTestInterface() :
		SimpleTest("Interface")
	{
	}

	void tests::MatrixTestInterface::test()
	{
		structures::Matrix<int>* matrix = this->makeMatrix(20, 20);
		matrix->assign(*matrix);
		matrix->equals(*matrix);
		matrix->size();
		matrix->isEmpty();
		matrix->getRowCount();
		matrix->getColumnCount();
		matrix->at(10, 10);
		delete matrix;
		SimpleTest::logPass("Compiled.");
	}

	structures::Matrix<int>* CoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::CoherentMatrix<int>(rows, cols);
	}

	/// <summary>
	/// CoherentMatrix power test scenario A
	/// </summary>
	CoherentMatrixPowerTestScenarioA::CoherentMatrixPowerTestScenarioA() :
		SimpleTest("Coherent matrix power test scenario A")
	{
	}

	int CoherentMatrixPowerTestScenarioA::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int CoherentMatrixPowerTestScenarioA::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void CoherentMatrixPowerTestScenarioA::test()
	{
		srand(time(NULL));

		firstOperation_ = 50000;
		secondOperation_ = 50000;
		thirdOperation_ = 900000;

		int rowCount = 10;
		int columnCount = 50;

		std::string path = "coherent/scenarioA";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix power test scenario B
	/// </summary>
	CoherentMatrixPowerTestScenarioB::CoherentMatrixPowerTestScenarioB() :
		SimpleTest("Coherent matrix power test scenario B")
	{
	}

	int CoherentMatrixPowerTestScenarioB::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int CoherentMatrixPowerTestScenarioB::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void CoherentMatrixPowerTestScenarioB::test()
	{
		srand(time(NULL));

		firstOperation_ = 50000;
		secondOperation_ = 50000;
		thirdOperation_ = 900000;

		int rowCount = 2000;
		int columnCount = 500;

		std::string path = "coherent/scenarioB";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix power test scenario C
	/// </summary>
	CoherentMatrixPowerTestScenarioC::CoherentMatrixPowerTestScenarioC() :
		SimpleTest("Coherent matrix power test scenario C")
	{
	}

	int CoherentMatrixPowerTestScenarioC::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int CoherentMatrixPowerTestScenarioC::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void CoherentMatrixPowerTestScenarioC::test()
	{
		srand(time(NULL));

		firstOperation_ = 100000;
		secondOperation_ = 300000;
		thirdOperation_ = 600000;

		int rowCount = 50;
		int columnCount = 10;

		std::string path = "coherent/scenarioC";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix power test scenario D
	/// </summary>
	CoherentMatrixPowerTestScenarioD::CoherentMatrixPowerTestScenarioD() :
		SimpleTest("Coherent matrix power test scenario D")
	{
	}

	int CoherentMatrixPowerTestScenarioD::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int CoherentMatrixPowerTestScenarioD::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void CoherentMatrixPowerTestScenarioD::test()
	{
		srand(time(NULL));

		firstOperation_ = 100000;
		secondOperation_ = 300000;
		thirdOperation_ = 600000;

		int rowCount = 500;
		int columnCount = 2000;

		std::string path = "coherent/scenarioD";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// Matrix time analysis
	/// </summary>
	MatrixTimeAnalysis::MatrixTimeAnalysis(std::string message) :
		SimpleTest(message)
	{
	}
	
	int MatrixTimeAnalysis::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	/// <summary>
	/// CoherentMatrix time analysis test at
	/// </summary>
	CoherentMatrixTimeAnalysisTestAt::CoherentMatrixTimeAnalysisTestAt() :
		MatrixTimeAnalysis("CoherentMatrix time analysis test at")
	{
	}

	void CoherentMatrixTimeAnalysisTestAt::test()
	{
		int lowestValue = 10;
		int highestValue = 15000;
		int xAxis;
		int yAxis;

		std::string fileName = "coherent/time_analysis_at_Mx10.csv";
		std::ofstream outputFile;
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(i, lowestValue);
			
			for (int y = 0; y < 100; y++) {
				xAxis = getRandomValue(0, i);
				yAxis = getRandomValue(0, lowestValue);

				outputFile << std::to_string(i);
				outputFile << ";";
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				SimpleTest::startStopwatch();
				matrix->at(xAxis, yAxis);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete matrix;
		}
		outputFile.close();

		fileName = "coherent/time_analysis_at_10xN.csv";
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(lowestValue, i);

			for (int y = 0; y < 100; y++) {
				xAxis = getRandomValue(0, lowestValue);
				yAxis = getRandomValue(0, i);

				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				outputFile << std::to_string(i);
				outputFile << ";";
				SimpleTest::startStopwatch();
				matrix->at(xAxis, yAxis);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete matrix;
		}
		outputFile.close();
	}

	/// <summary>
	/// CoherentMatrix time analysis test assign
	/// </summary>
	CoherentMatrixTimeAnalysisTestAssign::CoherentMatrixTimeAnalysisTestAssign() :
		MatrixTimeAnalysis("CoherentMatrix time analysis test assign")
	{
	}

	void CoherentMatrixTimeAnalysisTestAssign::test()
	{
		int lowestValue = 10;
		int highestValue = 15000;

		std::string fileName = "coherent/time_analysis_assign_Mx10.csv";
		std::ofstream outputFile;
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::CoherentMatrix<int>* firstMatrix = new structures::CoherentMatrix<int>(i, lowestValue);
			structures::CoherentMatrix<int>* secondMatrix = new structures::CoherentMatrix<int>(i, lowestValue);

			for (int y = 0; y < 100; y++) {
				outputFile << std::to_string(i);
				outputFile << ";";
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				SimpleTest::startStopwatch();
				firstMatrix->assign(*secondMatrix);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete firstMatrix;
			delete secondMatrix;
		}
		outputFile.close();

		fileName = "coherent/time_analysis_assign_10xN.csv";
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::CoherentMatrix<int>* firstMatrix = new structures::CoherentMatrix<int>(lowestValue, i);
			structures::CoherentMatrix<int>* secondMatrix = new structures::CoherentMatrix<int>(lowestValue, i);

			for (int y = 0; y < 100; y++) {
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				outputFile << std::to_string(i);
				outputFile << ";";
				SimpleTest::startStopwatch();
				firstMatrix->assign(*secondMatrix);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete firstMatrix;
			delete secondMatrix;
		}
		outputFile.close();
	}

	/// <summary>
	/// IncoherentMatrix time analysis test at
	/// </summary>
	IncoherentMatrixTimeAnalysisTestAt::IncoherentMatrixTimeAnalysisTestAt() :
		MatrixTimeAnalysis("IncoherentMatrix time analysis test at")
	{
	}

	void IncoherentMatrixTimeAnalysisTestAt::test()
	{
		int lowestValue = 10;
		int highestValue = 15000;
		int xAxis;
		int yAxis;

		std::string fileName = "incoherent/time_analysis_at_Mx10.csv";
		std::ofstream outputFile;
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(i, lowestValue);

			for (int y = 0; y < 100; y++) {
				xAxis = getRandomValue(0, i);
				yAxis = getRandomValue(0, lowestValue);

				outputFile << std::to_string(i);
				outputFile << ";";
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				SimpleTest::startStopwatch();
				matrix->at(xAxis, yAxis);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete matrix;
		}
		outputFile.close();

		fileName = "incoherent/time_analysis_at_10xN.csv";
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(lowestValue, i);

			for (int y = 0; y < 100; y++) {
				xAxis = getRandomValue(0, lowestValue);
				yAxis = getRandomValue(0, i);

				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				outputFile << std::to_string(i);
				outputFile << ";";
				SimpleTest::startStopwatch();
				matrix->at(xAxis, yAxis);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete matrix;
		}
		outputFile.close();
	}

	/// <summary>
	/// IncoherentMatrix time analysis test assign
	/// </summary>
	IncoherentMatrixTimeAnalysisTestAssign::IncoherentMatrixTimeAnalysisTestAssign() :
		MatrixTimeAnalysis("IncoherentMatrix time analysis test assign")
	{
	}

	void IncoherentMatrixTimeAnalysisTestAssign::test()
	{
		int lowestValue = 10;
		int highestValue = 15000;

		std::string fileName = "incoherent/time_analysis_assign_Mx10.csv";
		std::ofstream outputFile;
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::IncoherentMatrix<int>* firstMatrix = new structures::IncoherentMatrix<int>(i, lowestValue);
			structures::IncoherentMatrix<int>* secondMatrix = new structures::IncoherentMatrix<int>(i, lowestValue);

			for (int y = 0; y < 100; y++) {
				outputFile << std::to_string(i);
				outputFile << ";";
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				SimpleTest::startStopwatch();
				firstMatrix->assign(*secondMatrix);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete firstMatrix;
			delete secondMatrix;
		}
		outputFile.close();

		fileName = "incoherent/time_analysis_assign_10xN.csv";
		outputFile.open(fileName);
		outputFile << "xAxis;yAxis;duration\n";

		for (int i = lowestValue; i <= highestValue + lowestValue; i = i + 100) {
			structures::IncoherentMatrix<int>* firstMatrix = new structures::IncoherentMatrix<int>(lowestValue, i);
			structures::IncoherentMatrix<int>* secondMatrix = new structures::IncoherentMatrix<int>(lowestValue, i);

			for (int y = 0; y < 100; y++) {
				outputFile << std::to_string(lowestValue);
				outputFile << ";";
				outputFile << std::to_string(i);
				outputFile << ";";
				SimpleTest::startStopwatch();
				firstMatrix->assign(*secondMatrix);
				SimpleTest::stopStopwatch();
				outputFile << SimpleTest::getElapsedTime().count();
				outputFile << "\n";
			}

			delete firstMatrix;
			delete secondMatrix;
		}
		outputFile.close();
	}

	/// <summary>
	/// CoherentMatrix test assign
	/// </summary>
	CoherentMatrixTestAssign::CoherentMatrixTestAssign() :
		SimpleTest("CoherentMatrix test assign")
	{
	}

	void CoherentMatrixTestAssign::test() 
	{
		structures::CoherentMatrix<int>* firstMatrix = new structures::CoherentMatrix<int>(10, 10);
		structures::CoherentMatrix<int>* secondMatrix = new structures::CoherentMatrix<int>(10, 10);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
			}
		}
		
		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				SimpleTest::assertTrue(firstMatrix->at(i, y) == i * 10 + y, "First matrix assert (" + std::to_string(i) + "," + std::to_string(y) + ")");
			}
		}

		secondMatrix->assign(*firstMatrix);

		delete firstMatrix;

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				SimpleTest::assertTrue(secondMatrix->at(i, y) == i * 10 + y, "Second matrix assert (" + std::to_string(i) + "," + std::to_string(y) + ")");
			}
		}

		delete secondMatrix;
	}

	/// <summary>
	/// CoherentMatrix test equals
	/// </summary>
	CoherentMatrixTestEquals::CoherentMatrixTestEquals() :
		SimpleTest("CoherentMatrix test equals")
	{
	}

	void CoherentMatrixTestEquals::test()
	{
		structures::CoherentMatrix<int>* firstMatrix = new structures::CoherentMatrix<int>(10, 10);
		structures::CoherentMatrix<int>* secondMatrix = new structures::CoherentMatrix<int>(10, 10);
		structures::CoherentMatrix<int>* thirdMatrix = new structures::CoherentMatrix<int>(11, 12);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
			}
		}

		SimpleTest::assertFalse(firstMatrix->equals(*secondMatrix));
		SimpleTest::assertFalse(secondMatrix->equals(*thirdMatrix));

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				secondMatrix->at(i, y) = i * 10 + y;
			}
		}

		SimpleTest::assertTrue(firstMatrix->equals(*secondMatrix));

		delete firstMatrix;
		delete secondMatrix;
		delete thirdMatrix;
	}

	/// <summary>
	/// CoherentMatrix test size
	/// </summary>
	CoherentMatrixTestSize::CoherentMatrixTestSize() :
		SimpleTest("CoherentMatrix test size")
	{
	}

	void CoherentMatrixTestSize::test()
	{
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(10, 10);

		SimpleTest::assertTrue(matrix->size() == 100);
		SimpleTest::assertFalse(matrix->size() == 10);

		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix test get row count
	/// </summary>
	CoherentMatrixTestGetRowCount::CoherentMatrixTestGetRowCount() :
		SimpleTest("CoherentMatrix test get row count")
	{
	}

	void CoherentMatrixTestGetRowCount::test()
	{
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(10, 20);

		SimpleTest::assertTrue(matrix->getRowCount() == 10);
		SimpleTest::assertFalse(matrix->getRowCount() == 20);

		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix test get column count
	/// </summary>
	CoherentMatrixTestGetColumnCount::CoherentMatrixTestGetColumnCount() :
		SimpleTest("CoherentMatrix test get column count")
	{
	}

	void CoherentMatrixTestGetColumnCount::test()
	{
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(10, 20);

		SimpleTest::assertTrue(matrix->getColumnCount() == 20);
		SimpleTest::assertFalse(matrix->getColumnCount() == 10);

		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix test at
	/// </summary>
	CoherentMatrixTestAt::CoherentMatrixTestAt() :
		SimpleTest("CoherentMatrix test at")
	{
	}

	void CoherentMatrixTestAt::test()
	{
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(10, 10);

		SimpleTest::assertTrue(matrix->at(6, 6) == 0);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				matrix->at(i, y) = i * 10 + y;
			}
		}

		SimpleTest::assertTrue(matrix->at(6, 6) == 66);
		SimpleTest::assertFalse(matrix->at(6, 6) == 0);

		delete matrix;
	}

	/// <summary>
	/// CoherentMatrix test copy constructor
	/// </summary>
	CoherentMatrixTestCopyConstructor::CoherentMatrixTestCopyConstructor() :
		SimpleTest("CoherentMatrix test copy constructor")
	{
	}

	void CoherentMatrixTestCopyConstructor::test()
	{
		structures::CoherentMatrix<int>* firstMatrix = new structures::CoherentMatrix<int>(10, 10);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
			}
		}

		structures::CoherentMatrix<int>* secondMatrix = new structures::CoherentMatrix<int>(*firstMatrix);
		
		delete firstMatrix;

		SimpleTest::assertTrue(secondMatrix->at(6, 6) == 66);
		SimpleTest::assertTrue(secondMatrix->at(9, 9) == 99);

		delete secondMatrix;
	}

	structures::Matrix<int>* IncoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::IncoherentMatrix<int>(rows, cols);
	}

	CoherentMatrixTestOverall::CoherentMatrixTestOverall() :
		ComplexTest("CoherentMatrix")
	{
		addTest(new CoherentMatrixTestInterface());
		addTest(new CoherentMatrixTestAssign());
		addTest(new CoherentMatrixTestEquals());
		addTest(new CoherentMatrixTestSize());
		addTest(new CoherentMatrixTestGetRowCount());
		addTest(new CoherentMatrixTestGetColumnCount());
		addTest(new CoherentMatrixTestAt());
		addTest(new CoherentMatrixTestCopyConstructor());


		addTest(new CoherentMatrixPowerTestScenarioA());
		addTest(new CoherentMatrixPowerTestScenarioB());
		addTest(new CoherentMatrixPowerTestScenarioC());
		addTest(new CoherentMatrixPowerTestScenarioD());

		addTest(new CoherentMatrixTimeAnalysisTestAt());
		addTest(new CoherentMatrixTimeAnalysisTestAssign());
	}

	/// <summary>
	/// IncoherentMatrix test at
	/// </summary>
	IncoherentMatrixTestAt::IncoherentMatrixTestAt() :
		SimpleTest("IncoherentMatrix test at")
	{
	}

	void IncoherentMatrixTestAt::test()
	{
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(10, 10);

		SimpleTest::assertTrue(matrix->at(6, 6) == 0);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				matrix->at(i, y) = i * 10 + y;
			}
		}

		SimpleTest::assertTrue(matrix->at(6, 6) == 66);
		SimpleTest::assertFalse(matrix->at(6, 6) == 0);

		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix test assign
	/// </summary>
	IncoherentMatrixTestAssign::IncoherentMatrixTestAssign() :
		SimpleTest("IncoherentMatrix test assign")
	{
	}

	void IncoherentMatrixTestAssign::test()
	{
		structures::IncoherentMatrix<int>* firstMatrix = new structures::IncoherentMatrix<int>(10, 10);
		structures::IncoherentMatrix<int>* secondMatrix = new structures::IncoherentMatrix<int>(10, 10);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
			}
		}

		SimpleTest::assertTrue(firstMatrix->at(6, 6) == 66);
		SimpleTest::assertTrue(secondMatrix->at(6, 6) == 0);

		secondMatrix->assign(*firstMatrix);

		SimpleTest::assertTrue(secondMatrix->at(6, 6) == 66);
		SimpleTest::assertFalse(secondMatrix->at(6, 6) == 0);

		delete firstMatrix;

		SimpleTest::assertTrue(secondMatrix->at(6, 6) == 66);

		delete secondMatrix;
	}

	/// <summary>
	/// IncoherentMatrix test equals
	/// </summary>
	IncoherentMatrixTestEquals::IncoherentMatrixTestEquals() :
		SimpleTest("IncoherentMatrix test equals")
	{
	}

	void IncoherentMatrixTestEquals::test()
	{
		structures::IncoherentMatrix<int>* firstMatrix = new structures::IncoherentMatrix<int>(10, 10);
		structures::IncoherentMatrix<int>* secondMatrix = new structures::IncoherentMatrix<int>(10, 10);
		structures::IncoherentMatrix<int>* thirdMatrix = new structures::IncoherentMatrix<int>(10, 10);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
				secondMatrix->at(i, y) = i * 10 + y;
				thirdMatrix->at(i, y) = i * 10 + y + 1;
			}
		}

		SimpleTest::assertTrue(firstMatrix->equals(*secondMatrix));
		SimpleTest::assertFalse(firstMatrix->equals(*thirdMatrix));

		delete firstMatrix;
		delete secondMatrix;
		delete thirdMatrix;
	}

	/// <summary>
	/// IncoherentMatrix test size
	/// </summary>
	IncoherentMatrixTestSize::IncoherentMatrixTestSize() :
		SimpleTest("IncoherentMatrix test size")
	{
	}

	void IncoherentMatrixTestSize::test()
	{
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(12, 13);

		SimpleTest::assertTrue(matrix->size() == 156);

		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix test get row count
	/// </summary>
	IncoherentMatrixTestGetRowCount::IncoherentMatrixTestGetRowCount() :
		SimpleTest("IncoherentMatrix test get row count")
	{
	}

	void IncoherentMatrixTestGetRowCount::test()
	{
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(12, 13);

		SimpleTest::assertTrue(matrix->getRowCount() == 12);

		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix test get column count
	/// </summary>
	IncoherentMatrixTestGetColumnCount::IncoherentMatrixTestGetColumnCount() :
		SimpleTest("IncoherentMatrix test get column count")
	{
	}

	void IncoherentMatrixTestGetColumnCount::test()
	{
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(12, 13);

		SimpleTest::assertTrue(matrix->getColumnCount() == 13);

		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix test copy constructor
	/// </summary>
	IncoherentMatrixTestCopyConstructor::IncoherentMatrixTestCopyConstructor() :
		SimpleTest("IncoherentMatrix test copy constructor")
	{
	}

	void IncoherentMatrixTestCopyConstructor::test()
	{
		structures::IncoherentMatrix<int>* firstMatrix = new structures::IncoherentMatrix<int>(10, 10);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 10; y++) {
				firstMatrix->at(i, y) = i * 10 + y;
			}
		}

		structures::IncoherentMatrix<int>* secondMatrix = new structures::IncoherentMatrix<int>(*firstMatrix);

		delete firstMatrix;

		SimpleTest::assertTrue(secondMatrix->at(6, 6) == 66);

		delete secondMatrix;
	}

	/// <summary>
	/// IncoherentMatrix power test scenario A
	/// </summary>
	IncoherentMatrixPowerTestScenarioA::IncoherentMatrixPowerTestScenarioA() :
		SimpleTest("Coherent matrix power test scenario A")
	{
	}

	int IncoherentMatrixPowerTestScenarioA::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int IncoherentMatrixPowerTestScenarioA::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void IncoherentMatrixPowerTestScenarioA::test()
	{
		srand(time(NULL));

		firstOperation_ = 50000;
		secondOperation_ = 50000;
		thirdOperation_ = 900000;

		int rowCount = 10;
		int columnCount = 50;

		std::string path = "incoherent/scenarioA";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix power test scenario B
	/// </summary>
	IncoherentMatrixPowerTestScenarioB::IncoherentMatrixPowerTestScenarioB() :
		SimpleTest("Coherent matrix power test scenario B")
	{
	}

	int IncoherentMatrixPowerTestScenarioB::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int IncoherentMatrixPowerTestScenarioB::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void IncoherentMatrixPowerTestScenarioB::test()
	{
		srand(time(NULL));

		firstOperation_ = 50000;
		secondOperation_ = 50000;
		thirdOperation_ = 900000;

		int rowCount = 2000;
		int columnCount = 500;

		std::string path = "incoherent/scenarioB";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix power test scenario C
	/// </summary>
	IncoherentMatrixPowerTestScenarioC::IncoherentMatrixPowerTestScenarioC() :
		SimpleTest("Incoherent matrix power test scenario C")
	{
	}

	int IncoherentMatrixPowerTestScenarioC::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int IncoherentMatrixPowerTestScenarioC::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void IncoherentMatrixPowerTestScenarioC::test()
	{
		srand(time(NULL));

		firstOperation_ = 100000;
		secondOperation_ = 300000;
		thirdOperation_ = 600000;

		int rowCount = 50;
		int columnCount = 10;

		std::string path = "incoherent/scenarioC";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	/// <summary>
	/// IncoherentMatrix power test scenario D
	/// </summary>
	IncoherentMatrixPowerTestScenarioD::IncoherentMatrixPowerTestScenarioD() :
		SimpleTest("Incoherent matrix power test scenario D")
	{
	}

	int IncoherentMatrixPowerTestScenarioD::getRandomValue(int bottom, int top) {
		return rand() % (top - bottom) + bottom;
	}

	int IncoherentMatrixPowerTestScenarioD::getCurrentOperation() {
		while (true) {
			int randomValue = getRandomValue(1, 4);
			if (randomValue == 1) {
				if (firstOperation_) {
					firstOperation_--;
					return 1;
				}
			}
			else if (randomValue == 2) {
				if (secondOperation_) {
					secondOperation_--;
					return 2;
				}
			}
			else {
				if (thirdOperation_) {
					thirdOperation_--;
					return 3;
				}
			}
		}
	}

	void IncoherentMatrixPowerTestScenarioD::test()
	{
		srand(time(NULL));

		firstOperation_ = 100000;
		secondOperation_ = 300000;
		thirdOperation_ = 600000;

		int rowCount = 500;
		int columnCount = 2000;

		std::string path = "incoherent/scenarioD";
		std::string fileText = "operation;duration\n";

		std::ofstream outputFile1;
		std::ofstream outputFile2;
		std::ofstream outputFile3;
		outputFile1.open(path + "/values_operation_1.csv");
		outputFile2.open(path + "/values_operation_2.csv");
		outputFile3.open(path + "/values_operation_3.csv");
		outputFile1 << fileText;
		outputFile2 << fileText;
		outputFile3 << fileText;

		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(rowCount, columnCount);

		for (int i = 0; i < 1000000; i++) {
			int currentOperation = getCurrentOperation();
			if (currentOperation == 1) {
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();

				outputFile1 << "getRowCount;";
				outputFile1 << SimpleTest::getElapsedTime().count();
				outputFile1 << "\n";
			}
			else if (currentOperation == 2) {
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();

				outputFile2 << "getColumnCount;";
				outputFile2 << SimpleTest::getElapsedTime().count();
				outputFile2 << "\n";
			}
			else {
				int randomRowIndex = getRandomValue(0, rowCount);
				int randomColumnIndex = getRandomValue(0, columnCount);
				SimpleTest::startStopwatch();
				matrix->at(randomRowIndex, randomColumnIndex);
				SimpleTest::stopStopwatch();

				outputFile3 << "at;";
				outputFile3 << SimpleTest::getElapsedTime().count();
				outputFile3 << "\n";
			}
		}

		outputFile1.close();
		outputFile2.close();
		outputFile3.close();
		delete matrix;
	}

	IncoherentMatrixTestOverall::IncoherentMatrixTestOverall() :
		ComplexTest("IncoherentMatrix")
	{
		addTest(new IncoherentMatrixTestInterface());
		addTest(new IncoherentMatrixTestAt());
		addTest(new IncoherentMatrixTestAssign());
		addTest(new IncoherentMatrixTestEquals());
		addTest(new IncoherentMatrixTestSize());
		addTest(new IncoherentMatrixTestGetRowCount());
		addTest(new IncoherentMatrixTestGetColumnCount());
		addTest(new IncoherentMatrixTestCopyConstructor());

		addTest(new IncoherentMatrixPowerTestScenarioA());
		addTest(new IncoherentMatrixPowerTestScenarioB());
		addTest(new IncoherentMatrixPowerTestScenarioC());
		addTest(new IncoherentMatrixPowerTestScenarioD());

		addTest(new IncoherentMatrixTimeAnalysisTestAt());
		addTest(new IncoherentMatrixTimeAnalysisTestAssign());
	}

	MatrixTestOverall::MatrixTestOverall() :
		ComplexTest("Matrix")
	{
		addTest(new CoherentMatrixTestOverall());
		addTest(new IncoherentMatrixTestOverall());
	}
}
