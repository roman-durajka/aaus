#pragma once

#include "matrix.h"
#include "../array/array.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Implementacia matice v nesuvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class IncoherentMatrix
		: public Matrix<T>
	{
	public:
		/// <summary>
		///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
		/// Polozky su inicializovane na "nulovu" hodnotu typu T.
		/// </summary>
		/// <param name="rowCount"> Pocet riadkov. </param>
		/// <param name="columnCount"> Pocet stlpcov. </param>
		IncoherentMatrix(size_t rowCount, size_t columnCount);

		/// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
		/// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
		IncoherentMatrix(IncoherentMatrix& other);

		/// <summary> Destruktor. </summary>
		~IncoherentMatrix();

		/// <summary>
		/// Ak je to mozne (parametrom je matica, ktora ma rovnake rozmery ako ako aktualna matica),
		/// tak skopiruje vlastnosti z matice odovzdanej ako parameter.
		/// Ak to nie je mozne, vyhodi sa vynimka.
		/// </summary>
		/// <param name = "other"> Odkaz na strukturu, z ktorej maju prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary>
		/// Ak je parametrom matica a obsah porovnavanych matic je rovnaky,
		/// tak vrati hodnotu true. V opacnom pripade vrati hodnotu false.
		/// </summary>
		/// <param name="other"> Odkaz na strukturu, s ktorou sa ma tato matica porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Pocet vsetkych prvkov v matici. </summary>
		/// <returns> Pocet prvkov v matici. </returns>
		size_t size() override;

		/// <summary> Vrati pocet riadkov v matici. </summary>
		/// <returns> Pocet riadkov matice. </returns>
		size_t getRowCount() override;

		/// <summary> Vrati pocet stlpcov matice. </summary>
		/// <returns> Pocet stlpcov matice. </returns>
		size_t getColumnCount() override;

		/// <summary> Vrati odkaz na prvok v danom riadku a stlpci. </summary>
		/// <param name="rowIndex"> Index riadku. </param>
		/// <param name="columnIndex"> Index stlpca. </param>
		/// <returns> Odkaz na prvok na danych indexoch. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index riadku alebo stlpca nepatri do matice. </exception>
		T& at(int rowIndex, int columnIndex) override;
	private:
		/// <summary>
		/// Dvojrozmerne pole
		/// </summary>
		Array<Array<T>*>* array_;

		/// <summary>
		/// Pocet prvkov v matici
		/// </summary>
		size_t rowCount_;
		size_t columnCount_;
	};

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(size_t rowCount, size_t columnCount) :
		array_(new Array<Array<T>*>(rowCount)),
		rowCount_(rowCount),
		columnCount_(columnCount)
	{
		for (size_t i = 0; i < rowCount; i++) {
			Array<T>* newArray = new Array<T>(columnCount);
			array_->at(i) = newArray;
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(IncoherentMatrix& other) :
		array_(new Array<Array<T>*>(other.rowCount_)),
		rowCount_(other.rowCount_),
		columnCount_(other.columnCount_)
	{
		for (size_t i = 0; i < rowCount_; i++) {
			Array<T>* otherColumnArray = other.array_->at(i);
			Array<T>* newColumnArray = new Array<T>(*otherColumnArray);
			array_->at(i) = newColumnArray;
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::~IncoherentMatrix()
	{
		for (size_t i = 0; i < rowCount_; i++) {
			Array<T>* arrayToDelete = array_->at(i);
			delete arrayToDelete;
			array_->at(i) = nullptr;
		}
		delete array_;
		array_ = nullptr;

		rowCount_ = 0;
		columnCount_ = 0;
	}

	template<typename T>
	inline Structure& IncoherentMatrix<T>::assign(Structure& other)
	{
		if (this != &other) {
			IncoherentMatrix<T>& otherIncoherentMatrix = dynamic_cast<IncoherentMatrix<T>&>(other);
			if (rowCount_ != otherIncoherentMatrix.rowCount_ || columnCount_ != otherIncoherentMatrix.columnCount_) {
				throw std::invalid_argument("Matrix dimensions are not the same!");
			}

			for (size_t i = 0; i < rowCount_; i++) {
				Array<T>* otherColumnArray = otherIncoherentMatrix.array_->at(i);
				delete array_->at(i);
				Array<T>* newColumnArray = new Array<T>(*otherColumnArray);
				array_->at(i) = newColumnArray;
			}
		}

		return *this;
	}

	template<typename T>
	inline bool IncoherentMatrix<T>::equals(Structure& other)
	{
		if (this == &other) {
			return true;
		}

		IncoherentMatrix<T>* otherIncoherentMatrix = dynamic_cast<IncoherentMatrix<T>*>(&other);
		if (otherIncoherentMatrix == nullptr) {
			return false;
		}

		if (rowCount_ != otherIncoherentMatrix->getRowCount() || columnCount_ != otherIncoherentMatrix->getColumnCount()) {
			return false;
		}

		for (size_t i = 0; i < rowCount_; i++) {
			for (size_t y = 0; y < columnCount_; y++) {
				if (at(i, y) != otherIncoherentMatrix->at(i, y)) {
					return false;
				}
			}
		}

		return true;
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::size()
	{
		return rowCount_ * columnCount_;
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::getRowCount()
	{
		return rowCount_;
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::getColumnCount()
	{
		return columnCount_;
	}

	template<typename T>
	inline T& IncoherentMatrix<T>::at(int rowIndex, int columnIndex)
	{
		Utils::rangeCheckExcept(rowIndex, rowCount_, "Invalid row index!");
		Utils::rangeCheckExcept(columnIndex, columnCount_, "Invalid column index!");

		Array<T>* columnArray = array_->at(rowIndex);
		return columnArray->at(columnIndex);

	}
}