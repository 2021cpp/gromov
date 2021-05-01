// MergeSort.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef SORTING_MERGE_SORT_H
#define SORTING_MERGE_SORT_H

#include <iostream>
#include <vector>
#include <random>

template < class RandomIt >

void MergeSort(RandomIt a, int n) {
    if (n == 1) { return; }
    int mid = (n + 0) / 2;
    MergeSort(a, mid);
    MergeSort(a + mid, n - mid);
    int* new_stor = new int[n];
    int cur1 = 0;
    int cur2 = mid;
    for (int i = 0; i < n; ++i) {
        if (cur2 >= n || cur1 < mid && *(a + cur1) <= *(a + cur2)) {
            new_stor[i] = *(a + cur1);
            cur1 += 1;
        }
        else {
            new_stor[i] = *(a + cur2);
            cur2 += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        *(a + i) = new_stor[i];
    }
    delete[] new_stor;
}

#endif //SORTING_MERGE_SORT_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
