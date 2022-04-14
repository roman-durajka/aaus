#pragma once

#include "../list/linked_list.h"
#include "sequence_table.h"

namespace structures
{

	/// <summary> Zretazena tabulka. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class LinkedTable : public SequenceTable<K, T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		LinkedTable();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> LinkedTable, z ktorej sa prevezmu vlastnosti. </param>
		LinkedTable(LinkedTable<K, T>& other);

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;
	};

	template<typename K, typename T>
	inline LinkedTable<K, T>::LinkedTable() :
		SequenceTable<K, T>(new LinkedList<TableItem<K, T>*>())
	{
	}

	template<typename K, typename T>
	inline LinkedTable<K, T>::LinkedTable(LinkedTable<K, T>& other) :
		LinkedTable()
	{
		assign(other);
	}
	template<typename K, typename T>
	inline bool LinkedTable<K, T>::equals(Structure& other)
	{
		return Table<K, T>::equals(dynamic_cast<LinkedTable<K, T>*>(&other));
	}
}