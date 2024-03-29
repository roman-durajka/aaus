#pragma once

#include "matrix.h"
#include "../vector/vector.h"
#include "../list/list.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Implementacia matice v suvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class CoherentMatrix
		: public Matrix<T>
	{
	public:
		/// <summary>
		///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
		/// Polozky su inicializovane na "nulovu" hodnotu typu T.
		/// </summary>
		/// <param name="rowCount"> Pocet riadkov. </param>
		/// <param name="columnCount"> Pocet stlpcov. </param>
		CoherentMatrix(size_t rowCount, size_t columnCount);

		/// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
		/// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
		CoherentMatrix(CoherentMatrix& other);

		/// <summary> Destruktor. </summary>
		~CoherentMatrix();

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
		/// Vektor s datami
		/// </summary>
		Vector* vector_;

		/// <summary>
		/// Pocet prvkov v matici
		/// </summary>
		size_t rowCount_;
		size_t columnCount_;
	private:
		/// <summary>
		/// Mapovacia funkcia, prevedie index v matici na index vo vektore
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		int mapFunction(int rowIndex, int columnIndex) const;
	};

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(size_t rowCount, size_t columnCount) :
		vector_(new Vector(rowCount * columnCount * sizeof(T))),
		rowCount_(rowCount),
		columnCount_(columnCount)
	{
	}

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(CoherentMatrix& other) :
		vector_(new Vector(*(other.vector_))),
		rowCount_(other.rowCount_),
		columnCount_(other.columnCount_)
	{
	}

	template<typename T>
	inline CoherentMatrix<T>::~CoherentMatrix()
	{
		delete vector_;
		vector_ = nullptr;
		rowCount_ = 0;
		columnCount_ = 0;
	}

	template<typename T>
	inline Structure& CoherentMatrix<T>::assign(Structure& other)
	{
		if (this != &other) {
			CoherentMatrix<T>& otherCoherentMatrix = dynamic_cast<CoherentMatrix<T>&>(other);
			if (rowCount_ != otherCoherentMatrix.rowCount_ || columnCount_ != otherCoherentMatrix.columnCount_) {
				throw std::invalid_argument("Matrix dimensions are not the same!");
			}
			vector_->assign(*(otherCoherentMatrix.vector_));
		}

		return *this;
	}

	template<typename T>
	inline bool CoherentMatrix<T>::equals(Structure& other)
	{
		if (this == &other) {
			return true;
		}

		CoherentMatrix<T>* otherCoherentMatrix = dynamic_cast<CoherentMatrix<T>*>(&other);
		if (otherCoherentMatrix == nullptr) {
			return false;
		}

		if (rowCount_ != otherCoherentMatrix->getRowCount() || columnCount_ != otherCoherentMatrix->getColumnCount()) {
			return false;
		}

		return vector_->equals(*otherCoherentMatrix->vector_);
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::size()
	{
		return rowCount_ * columnCount_;
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::getRowCount()
	{
		return rowCount_;
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::getColumnCount()
	{
		return columnCount_;
	}

	template<typename T>
	inline T& CoherentMatrix<T>::at(int rowIndex, int columnIndex)
	{
		int matrixIndex = mapFunction(rowIndex, columnIndex);
		byte* pointerByte = vector_->getBytePointer(matrixIndex);
		T* pointerT = reinterpret_cast<T*>(pointerByte);

		return *pointerT;
	}

	template<typename T>
	inline int CoherentMatrix<T>::mapFunction(int rowIndex, int columnIndex) const {
		Utils::rangeCheckExcept(rowIndex, rowCount_, "Invalid row index!");
		Utils::rangeCheckExcept(columnIndex, columnCount_, "Invalid column index!");
		
		return ((rowIndex * columnCount_) + columnIndex) * sizeof(T);
	}
}