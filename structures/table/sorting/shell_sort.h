#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{
	/// <summary> Triedenie Shell sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class ShellSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Shell sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
    private:
        void shell(int step);
    private:
        int valueCount;
	};

	template<typename K, typename T>
	inline void ShellSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
        valueCount = table->size();
		shell()
	}

	template<typename K, typename T>
	inline void ShellSort<K, T>::shell(int step, UnsortedSequenceTable<K, T>& table)
	{
        for(int z = 0; z < step; z++) {
            for(int i = 0; z < valueCount; i += z) {
                int j := i;

                if ((j - step >= z) && (table->getItemAtIndex(j)  < table->getItemAtIndex(j - step))) {
                    table->swap(j, j - step);
                    j -= step;
                }
            }
            if (step > 1) {
                shell(step - 1);
            }
        }
	}
}
