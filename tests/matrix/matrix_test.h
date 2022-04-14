#pragma once

#include "../test.h"
#include "../../structures/matrix/matrix.h"
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/_logger/logger.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania matice avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class MatrixTestInterface
		: public SimpleTest
	{
	public:
		MatrixTestInterface();
		void test() override;

	protected:
		virtual structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody koherentnej matice.
	/// </summary>
	class CoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Overenie vykonu implementacii
	/// </summary>
	class CoherentMatrixPowerTestScenarioA
		: public SimpleTest
	{
	public:
		CoherentMatrixPowerTestScenarioA();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;

	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class CoherentMatrixPowerTestScenarioB
		: public SimpleTest
	{
	public:
		CoherentMatrixPowerTestScenarioB();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class CoherentMatrixPowerTestScenarioC
		: public SimpleTest
	{
	public:
		CoherentMatrixPowerTestScenarioC();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class CoherentMatrixPowerTestScenarioD
		: public SimpleTest
	{
	public:
		CoherentMatrixPowerTestScenarioD();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	/// <summary>
	/// Overenie vykonu implementacii
	/// </summary>
	class IncoherentMatrixPowerTestScenarioA
		: public SimpleTest
	{
	public:
		IncoherentMatrixPowerTestScenarioA();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;

	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class IncoherentMatrixPowerTestScenarioB
		: public SimpleTest
	{
	public:
		IncoherentMatrixPowerTestScenarioB();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class IncoherentMatrixPowerTestScenarioC
		: public SimpleTest
	{
	public:
		IncoherentMatrixPowerTestScenarioC();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	class IncoherentMatrixPowerTestScenarioD
		: public SimpleTest
	{
	public:
		IncoherentMatrixPowerTestScenarioD();
	private:
		int firstOperation_;
		int secondOperation_;
		int thirdOperation_;
	public:
		int getRandomValue(int bottom, int top);
		int getCurrentOperation();
		void test() override;
	};

	/// <summary>
	/// Analyza casovych zlozitosti
	/// </summary>
	class MatrixTimeAnalysis
		: public SimpleTest
	{
	public:
		MatrixTimeAnalysis(std::string message);
		int getRandomValue(int bottom, int top);
	};

	/// <summary>
	/// Analyza casovych zlozitosti operacie at koherentnej matice
	/// </summary>
	class CoherentMatrixTimeAnalysisTestAt
		: public MatrixTimeAnalysis
	{
	public:
		CoherentMatrixTimeAnalysisTestAt();
		void test() override;
	};

	/// <summary>
	/// Analyza casovych zlozitosti operacie assign koherentnej matice
	/// </summary>
	class CoherentMatrixTimeAnalysisTestAssign
		: public MatrixTimeAnalysis
	{
	public:
		CoherentMatrixTimeAnalysisTestAssign();
		void test() override;
	};

	/// <summary>
	/// Analyza casovych zlozitosti operacie at nekoherentnej matice
	/// </summary>
	class IncoherentMatrixTimeAnalysisTestAt
		: public MatrixTimeAnalysis
	{
	public:
		IncoherentMatrixTimeAnalysisTestAt();
		void test() override;
	};

	/// <summary>
	/// Analyza casovych zlozitosti operacie assign nekoherentnej matice
	/// </summary>
	class IncoherentMatrixTimeAnalysisTestAssign
		: public MatrixTimeAnalysis
	{
	public:
		IncoherentMatrixTimeAnalysisTestAssign();
		void test() override;
	};

	class CoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAssign();
		void test() override;
	};

	class CoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		CoherentMatrixTestEquals();
		void test() override;
	};

	class CoherentMatrixTestSize
		: public SimpleTest
	{
	public:
		CoherentMatrixTestSize();
		void test() override;
	};

	class CoherentMatrixTestGetRowCount
		: public SimpleTest
	{
	public:
		CoherentMatrixTestGetRowCount();
		void test() override;
	};

	class CoherentMatrixTestGetColumnCount
		: public SimpleTest
	{
	public:
		CoherentMatrixTestGetColumnCount();
		void test() override;
	};

	class CoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAt();
		void test() override;
	};

	class CoherentMatrixTestCopyConstructor
		: public SimpleTest
	{
	public:
		CoherentMatrixTestCopyConstructor();
		void test() override;
	};

	class IncoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAssign();
		void test() override;
	};

	class IncoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestEquals();
		void test() override;
	};

	class IncoherentMatrixTestSize
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestSize();
		void test() override;
	};

	class IncoherentMatrixTestGetRowCount
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestGetRowCount();
		void test() override;
	};

	class IncoherentMatrixTestGetColumnCount
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestGetColumnCount();
		void test() override;
	};

	class IncoherentMatrixTestCopyConstructor
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestCopyConstructor();
		void test() override;
	};

	/// <summary>
	/// Zavola vsetky metody nekoherentnej matice.
	/// </summary>
	class IncoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	class IncoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAt();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherentMatrix.
	/// </summary>
	class CoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		CoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherrentMatrix a IncoherrentMatrix.
	/// </summary>
	class MatrixTestOverall
		: public ComplexTest
	{
	public:
		MatrixTestOverall();
	};
}